# Memory Manager

## About this
The purpose of this project is to build memory manager that controls memory operations such as new, delete in C++ and malloc, calloc, free in C etc. These memory operation affects performace of an application.

## Directory structure
FixedSizeMemortMngr - consist of source code <br>
libs - consist of library can be used in any application <br>
interface - header file include in application <br>
samples - small code to show how to use library. see Makefile <br>

## Usage
Change POOLSIZE and BUFFSIZE values in interface file (IFixedSizeMemoryManager.h)<br>
Makefile is present in 'FixedSizeMemortMngr' directory. Run 'make' in 'FixedSizeMemortMngr' directory.<br>Library 'libMemMngr.a' is created in 'libs' directory. Add this library in compilation of application.<br>Also include header file in application.<br> For more, to understand how to use library, go through samples.
