#!/bin/bash

# sudo update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-6.0 0

clang -E -C -P ../src/lua-ev.c -I../deps/libev > lua-ev.c
clang-format -i lua-ev.c
