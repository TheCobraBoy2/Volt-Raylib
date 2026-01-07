#!/bin/bash

RUN=false
RUNCMAKE=false

for arg in "$@"; do
    if [[ "$arg" == --* ]]; then
        # Long flags
        case "$arg" in
            --run) RUN=true ;;
            --run_cmake) RUNCMAKE=true ;;
            *) echo "Unknown argument: $arg" ;;
        esac
    elif [[ "$arg" == -* ]]; then
        # Short flags
        short_flags="${arg:1}"
        for ((i=0; i<${#short_flags}; i++)); do
            ch="${short_flags:i:1}"
            case "$ch" in
                r) RUN=true ;;
                c) RUNCMAKE=true ;;
                *) echo "Unknown short flag: -$ch" ;;
            esac
        done
    else
        echo "Unknown argument: $arg"
    fi
done

sloc="$(pwd)"

script_dir="$(dirname "$(readlink -f "$0")")"
cd "$script_dir" || exit 1

cd ../build || exit 1

if $RUNCMAKE; then
echo "Running cmake .."
cmake .. || { echo "cmake failed"; exit 1; }
fi

echo "Running make"
make || { echo "make failed"; exit 1; }

if $RUN; then
echo "Running VoltRaylib_Test.exe"
./VoltRaylib_Test.exe || { echo "Executable failed"; exit 1; }
fi

cd "$sloc" || exit 1
