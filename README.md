# Modules with g++15 HEAD, CMake and Ninja under Windows 10

A small demo project.

How to build and execute:
```bat
cd build
cmake -G Ninja
ninja
demo
```

Prerequisites:

* GCC 15.1 (just released!) or GCC 16 HEAD https://www.equation.com gcc-15-2025-0420-64.exe
* CMake 3.31.3
* Ninja 1.12.1

Limitations (at the time of writing, 2025-04-25):

* CMake supports C++ modules for Ninja generator only
* CMake tells Ninja nothing about module std. Hack: extra library `module_std` in `CMakeList.txt`.
