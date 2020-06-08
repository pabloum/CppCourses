# Learn how to program C++

## Text becomes executable.

`^_^`

We need to transform text into executable code. -> Multi step process.

Steps:

1. *Compiling*
  A compiler takes  source code that you can read and write, and transforms that into a different format.
  We call that an object file.
  If it can't be compiled you will get error messages

2. *Linking*
  Real life projects are made of several sources. So, we compile them, and then we must link all that together.
  Linker will send errors if it can't link.

3. *Running the App*
  Interact with the application through keyboard or clicks.
  Everything that happens here, even errors, are happening are Runtime.

## Tools.

1. *Bare minimum*
  - Text editor.
  - Compiler
  - Linker

2. *Nice additions* for full-on development environment.
  - Code aware editor.
  - Debugger.
  - Code-specific tools: static analysis, diagramming tools, etc.
  - Libraries, frameworks


www.isocpp.org/



## Command Line
batch programs. You wrote the program with the whole input, then you run it and get a result. Not interactive at all.

The first unix machines

The oldest C++ applications run at the command line in DOS or Unix.

Terminal on linux

Command prompt on Windows

## Smallest C++ App

int main() {
  return 0;
}


MinGW -> Compiler

## Errors

Compiler errors, Linked errors.

*Linker error*
int man() {
  return 0;
}

*Compiler error*
int main() {
  return 0
}

Warnings -> Do not ignore warnings -> They might be telling that something can happen on Runtime


## Summary

C++ is maintained by a standard comitee
