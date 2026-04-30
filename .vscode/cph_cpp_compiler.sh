#!/usr/bin/env bash
set -euo pipefail

script_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
workspace=$(cd -- "$script_dir/.." && pwd)
include_dir="$workspace/.vscode/include"

find_compiler() {
    local candidate
    for candidate in g++-15 g++-14 g++-13 g++-12 g++-11 g++-10 g++ clang++; do
        if command -v "$candidate" >/dev/null 2>&1; then
            command -v "$candidate"
            return 0
        fi
    done
    return 1
}

compiler=$(find_compiler) || {
    echo "No C++ compiler found. Install Xcode Command Line Tools or GNU GCC." >&2
    exit 127
}

version=$("$compiler" --version 2>/dev/null | head -n 1 || true)
is_clang=0
if [[ "$version" == *"clang"* || "$version" == *"Apple clang"* ]]; then
    is_clang=1
fi

src=""
for arg in "$@"; do
    case "$arg" in
        *.c|*.cc|*.cpp|*.cxx)
            src=$arg
            break
            ;;
    esac
done

if [[ -n "$src" && -f "$src" ]] && (( is_clang )) && grep -Eq '#[[:space:]]*include[[:space:]]*<((bits/extc\+\+\.h)|(ext/pb_ds/))' "$src"; then
    cat >&2 <<EOF
This file uses GNU libstdc++ extensions such as PBDS, but the selected compiler is:
  $compiler
  $version

Install Homebrew GCC for PBDS files, for example:
  brew install gcc
EOF
    exit 1
fi

exec "$compiler" -I "$include_dir" "$@"
