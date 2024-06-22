# cmake config files for C++ Primer, Fifth Edition

This repository contains the source code from C++ Primer, 5th edition, with the addition of cmake configuration files which allow to create a Visual Studio solution for many of the chapters.

For all information about the original distribution, see [Visual Studio 2012 README.pdf](https://github.com/greg7mdp/primer/blob/main/Visual%20Studio%202012%20README.pdf)

## Instruction for using this repo to create a Visual Studio solution

- install Visual Studio 2022 or above (community edition is fine)
- install [git](https://git-scm.com/download/win).  Probably the `64-bit Git for Windows Setup` is best.
- install [cmake](https://cmake.org/download/). Probably the `Windows x64 installer` is best.
- start a `x64 Native Tool Command Prompt` (this is a program in Visual Studio).
- change to a directory or your choice.
- clone the `primer` repo and create the solution file with the following commands: 
```
git clone https://github.com/greg7mdp/primer.git
cd primer
mkdir build
cd build
cmake ..
```
- at this point the solution was created in the `build` subdirectory, you can open it in Visual Studio and build it.