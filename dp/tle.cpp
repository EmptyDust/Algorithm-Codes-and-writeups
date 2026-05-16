#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <optional>
#include <string>

namespace fs = std::filesystem;

enum class GeneratorMode {
	Cpp,
	Python,
};

struct Options {
	GeneratorMode generator_mode = GeneratorMode::Cpp;
	std::optional<double> time_limit_ms;
};

std::string quote(const std::string& value) {
	return "\"" + value + "\"";
}

bool has_required_files(const fs::path& dir) {
	return fs::exists(dir / "solve.cpp") && (fs::exists(dir / "data.cpp") || fs::exists(dir / "data.py"));
}

std::optional<fs::path> locate_base_dir(const fs::path& start) {
	fs::path current = start;
	for (int depth = 0; depth < 6; ++depth) {
		if (has_required_files(current)) {
			return current;
		}
		if (has_required_files(current / "dp")) {
			return current / "dp";
		}
		if (!current.has_parent_path()) {
			break;
		}
		fs::path parent = current.parent_path();
		if (parent == current) {
			break;
		}
		current = parent;
	}
	return std::nullopt;
}

int run(const std::string& command) {
	return std::system(command.c_str());
}

std::string find_compiler() {
	for (const std::string& candidate : {"g++-15", "g++-14", "g++-13", "g++-12", "g++-11", "g++-10", "g++", "clang++", "c++"}) {
		if (run("command -v " + candidate + " >/dev/null 2>&1") == 0) {
			return candidate;
		}
	}
	return "";
}

std::optional<Options> parse_options(int argc, char* argv[]) {
	Options options;
	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
		if (arg == "cpp") {
			options.generator_mode = GeneratorMode::Cpp;
			continue;
		}
		if (arg == "py" || arg == "python") {
			options.generator_mode = GeneratorMode::Python;
			continue;
		}
		try {
			size_t pos = 0;
			double value = std::stod(arg, &pos);
			if (pos != arg.size() || value < 0) {
				return std::nullopt;
			}
			options.time_limit_ms = value;
		} catch (...) {
			return std::nullopt;
		}
	}
	return options;
}

int main(int argc, char* argv[]) {
	fs::path exe_dir = fs::absolute(argv[0]).parent_path();
	std::optional<fs::path> base_dir = locate_base_dir(fs::current_path());
	if (!base_dir) {
		base_dir = locate_base_dir(exe_dir);
	}
	if (!base_dir) {
		std::cerr << "Failed to locate dp directory.\n";
		return 1;
	}
	fs::path include_dir = base_dir->parent_path() / ".vscode" / "include";
	fs::path artifact_dir = *base_dir / ".tmp";
	std::error_code ec;
	fs::current_path(*base_dir, ec);
	if (ec) {
		std::cerr << "Failed to enter dp directory: " << ec.message() << '\n';
		return 1;
	}

	std::optional<Options> options = parse_options(argc, argv);
	if (!options) {
		std::cerr << "Usage: " << argv[0] << " [cpp|py] [time_limit_ms]\n";
		return 2;
	}

	std::string compiler = find_compiler();
	if (compiler.empty()) {
		std::cerr << "No C++ compiler found.\n";
		return 1;
	}
	fs::create_directories(artifact_dir);

	std::string compile_flags = " -std=c++23 -O2 -I " + quote(include_dir.string());
	fs::path solve_bin = artifact_dir / "solve";
	fs::path data_bin = artifact_dir / "data";
	fs::path data_in = artifact_dir / "data.in";
	fs::path solve_out = artifact_dir / "solve.out";
	if (run(compiler + compile_flags + " solve.cpp -o " + quote(solve_bin.string()))) return 1;
	if (options->generator_mode == GeneratorMode::Cpp && run(compiler + compile_flags + " data.cpp -o " + quote(data_bin.string()))) return 1;

	if (options->generator_mode == GeneratorMode::Cpp) {
		if (run(quote(data_bin.string()) + " > " + quote(data_in.string()))) return 1;
	} else {
		if (run("python3 data.py > " + quote(data_in.string()))) return 1;
	}

	auto start = std::chrono::steady_clock::now();
	int code = run(quote(solve_bin.string()) + " < " + quote(data_in.string()) + " > " + quote(solve_out.string()));
	auto finish = std::chrono::steady_clock::now();
	double elapsed_ms = std::chrono::duration<double, std::milli>(finish - start).count();

	std::cout << "Elapsed: " << elapsed_ms << " ms\n";
	if (code != 0) {
		std::cerr << "solve exited with code " << code << '\n';
		return 1;
	}
	if (options->time_limit_ms && elapsed_ms > *options->time_limit_ms) {
		std::cout << "Potential TLE\n";
		return 3;
	}
	return 0;
}
