from pathlib import Path
import shutil
import subprocess
import sys

BASE_DIR = Path(__file__).resolve().parent
INCLUDE_DIR = BASE_DIR.parent / ".vscode" / "include"
ARTIFACT_DIR = BASE_DIR / ".tmp"


def find_compiler() -> str:
    for candidate in ("g++-15", "g++-14", "g++-13", "g++-12", "g++-11", "g++-10", "g++", "clang++", "c++"):
        if shutil.which(candidate):
            return candidate
    raise FileNotFoundError("No C++ compiler found")


def parse_generator_mode() -> str:
    if len(sys.argv) <= 1:
        return "cpp"
    mode = sys.argv[1].lower()
    if mode in {"cpp", "py", "python"}:
        return "py" if mode in {"py", "python"} else "cpp"
    raise SystemExit(f"Usage: {sys.argv[0]} [cpp|py]")


def build(generator_mode: str) -> None:
    compiler = find_compiler()
    ARTIFACT_DIR.mkdir(exist_ok=True)
    subprocess.run(
        [compiler, "-std=c++23", "-O2", "-I", str(INCLUDE_DIR), "std.cpp", "-o", str(ARTIFACT_DIR / "std")],
        cwd=BASE_DIR,
        check=True,
    )
    subprocess.run(
        [compiler, "-std=c++23", "-O2", "-I", str(INCLUDE_DIR), "solve.cpp", "-o", str(ARTIFACT_DIR / "solve")],
        cwd=BASE_DIR,
        check=True,
    )
    if generator_mode == "cpp":
        subprocess.run(
            [compiler, "-std=c++23", "-O2", "-I", str(INCLUDE_DIR), "data.cpp", "-o", str(ARTIFACT_DIR / "data")],
            cwd=BASE_DIR,
            check=True,
        )


def main() -> int:
    generator_mode = parse_generator_mode()
    build(generator_mode)
    tc = 0
    data_in = ARTIFACT_DIR / "data.in"
    std_out = ARTIFACT_DIR / "std.out"
    solve_out = ARTIFACT_DIR / "solve.out"
    diff_log = ARTIFACT_DIR / "diff.log"
    while True:
        with data_in.open("w", encoding="utf-8") as data_in_file:
            if generator_mode == "cpp":
                subprocess.run([str(ARTIFACT_DIR / "data")], cwd=BASE_DIR, stdout=data_in_file, check=True)
            else:
                subprocess.run([sys.executable, "data.py"], cwd=BASE_DIR, stdout=data_in_file, check=True)
        with data_in.open("r", encoding="utf-8") as data_in_file, std_out.open("w", encoding="utf-8") as std_out_file:
            subprocess.run([str(ARTIFACT_DIR / "std")], cwd=BASE_DIR, stdin=data_in_file, stdout=std_out_file, check=True)
        with data_in.open("r", encoding="utf-8") as data_in_file, solve_out.open("w", encoding="utf-8") as solve_out_file:
            subprocess.run([str(ARTIFACT_DIR / "solve")], cwd=BASE_DIR, stdin=data_in_file, stdout=solve_out_file, check=True)
        with diff_log.open("w", encoding="utf-8") as diff_log_file:
            diff = subprocess.run(
                ["diff", "-u", str(std_out), str(solve_out)],
                cwd=BASE_DIR,
                stdout=diff_log_file,
            )
        if diff.returncode != 0:
            print("WA")
            return 1
        tc += 1
        print(f"AC #{tc}")


if __name__ == "__main__":
    raise SystemExit(main())
