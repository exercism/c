The C language track requires that you have the following software installed
on your system:

* A modern C compiler
* The Make build tool

Apple's Xcode IDE combines the compiler and
the native build system into a single IDE (integrated development
environment). Linux environments typically expose the compiler and native
build system as separate command-line tools.


#### Linux

Linux users will need gcc or clang for the compiler, and `make` will be needed
for the native build. Make is pre-installed on most unix systems, but is most
likely available via your package manager. On Debian and Ubuntu based
distributions everything you need can be installed with `sudo apt-get install build-essential`
if not present.


#### MacOS

MacOS users can install gcc or clang with [Homebrew](http://brew.sh/) via
`brew install gcc` or `brew install llvm`.


#### Windows

Windows 10 users are recommended to use [WSL Bash](https://msdn.microsoft.com/en-us/commandline/wsl/about), and proceed with the instruction for linux above.

If you are using an earlier version of Windows or WSL Bash is not available to you, you could use [MSYS/MinGW](http://www.mingw.org/) (32-bit only) or [mingw6-w64](http://mingw-w64.org/doku.php) (32 & 64-bit).
