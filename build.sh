#!/usr/bin/env bash

readonly bin="./app/bin"
readonly src="./app/src"

function main()
{
    files="$(getFiles "$src" "*.c")"

    compileSources
    generateExecutable "Colossus"
}

function getFiles()
{
    cd $1
    local files=$(ls $2)
    cd ../..
    echo "$files"
}

function compileSources()
{
    for file in $files do
        local name="${file%.c}"

        gcc -c "$src/$file" -o "$bin/$name.o"
    done

    gcc -c ./Main.c -o "$bin/Main.o"
}

function generateExecutable()
{
    gcc "$bin"/*.o -o "$bin/$1.exe"
}

main