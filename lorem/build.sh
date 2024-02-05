#! /bin/sh
rm lorem 2>/dev/null;
if $(gcc --version >/dev/null 2>&1); then
    gcc lorem.c -std=c99 -O2 -o lorem;
elif $(clang --version >/dev/null 2>&1); then
    clang lorem.c -std=c99 -O2 -o lorem;
else
    >&2 echo "Source code can't be compiling! You must install gcc or clang!";
fi