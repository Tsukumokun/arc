#!/bin/sh

# Setup color output if possible
if [ -t 1 ]; then

    ncolors=$(tput colors)

    if test -n "$ncolors" && test $ncolors -ge 8; then
        BOLD="$(tput bold)"
        UNDERLINE="$(tput smul)"
        STANDOUT="$(tput smso)"
        NORMAL="$(tput sgr0)"
        BLACK="$(tput setaf 0)"
        RED="$(tput setaf 1)"
        GREEN="$(tput setaf 2)"
        YELLOW="$(tput setaf 3)"
        BLUE="$(tput setaf 4)"
        MAGENTA="$(tput setaf 5)"
        CYAN="$(tput setaf 6)"
        WHITE="$(tput setaf 7)"
    fi
fi

echo_color()
{
    if [ "$#" -lt 1 ]; then
        echo -n
    elif [ "$#" -lt 2 ]; then
        echo $1
    else
        echo "${1}${2}${NORMAL}"
    fi
}

for file in $(find . -name '*.cxx');do
    obj=${file/.cxx/.o}
    echo_color $BLUE "Making $obj ..."
    clang++ -std=c++0x -ggdb -pg -Wall -L../build -larc -o $obj $file
done
