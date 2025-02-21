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

* GCC 15 HEAD https://www.equation.com gcc-15-2024-1215-64.exe
* CMake 3.31.3
* Ninja 1.12.1

Limitations (at the time of writing, 2025-02-21):

* CMake supports C++ modules for Ninja generator only
* CMake tells Ninja nothing about module std. Hack: extra library `module_std` in `CMakeList.txt`.

Some lines in source file gnu/std.cc (copied from MinGW/include/c++/15.0.0/bits/std.cc)
had to be commented out:

```cpp
// using std::aligned_alloc;
// using std::timespec;
// using std::timespec_get;
// using std::mbrtoc8;
// using std::c8rtomb;
```

Sadly, newer weekly build compiler https://www.equation.com/ftpdir/gcc-15-20250202-64.exe resulted in compilation error: `exposes TU-local entity`. :-(
