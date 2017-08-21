The C language track requires that you have the following software installed
on your system:

* A modern C compiler
* The Make build tool

Microsoft's Visual Studio IDE and Apple's Xcode IDEs combine the compiler and
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

Windows users can get [Visual Studio Community][vs], a free download
that will give you the Visual Studio 2017 IDE and the latest version of the
Microsoft Visual C compiler.

[vs]: http://visualstudio.com
