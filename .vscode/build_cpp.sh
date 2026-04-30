#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 ]]; then
    echo "Usage: build_cpp.sh <source.cpp> [workspace]" >&2
    exit 2
fi

src=$1
workspace=${2:-$(pwd)}
build_dir="$workspace/.vscode/build"
include_dir="$workspace/.vscode/include"
std=${CPP_STD:-c++23}

if [[ ! -f "$src" ]]; then
    echo "Source file not found: $src" >&2
    exit 2
fi

mkdir -p "$build_dir"

base=$(basename "$src")
name=${base%.*}
out="$build_dir/$name"

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

if (( is_clang )) && grep -Eq '#[[:space:]]*include[[:space:]]*<((bits/extc\+\+\.h)|(ext/pb_ds/))' "$src"; then
    cat >&2 <<EOF
This file uses GNU libstdc++ extensions such as PBDS, but the selected compiler is:
  $compiler
  $version

Install Homebrew GCC for PBDS files, for example:
  brew install gcc

This repository's VS Code task will automatically prefer g++-15/g++-14/... after it exists on PATH.
EOF
    exit 1
fi

echo "CXX: $compiler" >&2
[[ -n "$version" ]] && echo "Version: $version" >&2

"$compiler" \
    "-std=$std" \
    -O2 \
    -pipe \
    -Wall \
    -Wextra \
    -DLOCAL \
    -I "$include_dir" \
    "$src" \
    -o "$out"

echo "$out"
