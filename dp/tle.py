from pathlib import Path
import shutil
import subprocess
import sys
import time

BASE_DIR = Path(__file__).resolve().parent
INCLUDE_DIR = BASE_DIR.parent / ".vscode" / "include"
ARTIFACT_DIR = BASE_DIR / ".tmp"


def find_compiler() -> str:
    for candidate in ("g++-15", "g++-14", "g++-13", "g++-12", "g++-11", "g++-10", "g++", "clang++", "c++"):
        if shutil.which(candidate):
            return candidate
    raise FileNotFoundError("No C++ compiler found")


def parse_generator_mode() -> str:
    generator_mode = "cpp"
    time_limit_ms = None
    for arg in sys.argv[1:]:
        mode = arg.lower()
        if mode in {"cpp", "py", "python"}:
            generator_mode = "py" if mode in {"py", "python"} else "cpp"
            continue
        try:
            value = float(arg)
        except ValueError as exc:
            raise SystemExit(f"Usage: {sys.argv[0]} [cpp|py] [time_limit_ms]") from exc
        if value < 0:
            raise SystemExit(f"Usage: {sys.argv[0]} [cpp|py] [time_limit_ms]")
        time_limit_ms = value
    return generator_mode, time_limit_ms


def main() -> int:
    generator_mode, time_limit_ms = parse_generator_mode()
    compiler = find_compiler()
    ARTIFACT_DIR.mkdir(exist_ok=True)
    subprocess.run(
        [compiler, "-std=c++23", "-O2", "-I", str(INCLUDE_DIR), "solve.cpp", "-o", str(ARTIFACT_DIR / "solve")],
        cwd=BASE_DIR,
        check=True,
    )
    data_in = ARTIFACT_DIR / "data.in"
    solve_out = ARTIFACT_DIR / "solve.out"
    with data_in.open("w", encoding="utf-8") as data_in_file:
        if generator_mode == "cpp":
            subprocess.run(
                [compiler, "-std=c++23", "-O2", "-I", str(INCLUDE_DIR), "data.cpp", "-o", str(ARTIFACT_DIR / "data")],
                cwd=BASE_DIR,
                check=True,
            )
            subprocess.run([str(ARTIFACT_DIR / "data")], cwd=BASE_DIR, stdout=data_in_file, check=True)
        else:
            subprocess.run([sys.executable, "data.py"], cwd=BASE_DIR, stdout=data_in_file, check=True)
    with data_in.open("r", encoding="utf-8") as data_in_file, solve_out.open("w", encoding="utf-8") as solve_out_file:
        start = time.perf_counter()
        subprocess.run([str(ARTIFACT_DIR / "solve")], cwd=BASE_DIR, stdin=data_in_file, stdout=solve_out_file, check=True)
        elapsed_ms = (time.perf_counter() - start) * 1000
    print(f"Elapsed: {elapsed_ms:.3f} ms")
    if time_limit_ms is not None and elapsed_ms > time_limit_ms:
        print("Potential TLE")
        return 3
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
