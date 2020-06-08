# Learn how to program C++

## Streams, Locals and Flow Control.

Stream I/O

Input - output

This library is different from "record base" or "fixed" which is more useful for databases

C++ supports << and >> operators.

  `<<` sends something to the stream  -> insertion  operation
  `>>` reads something to the stream  -> extraction opertation

Often called the insertion and extraction operations


## Include

`#include <iostream>`

For this, you just need the include

For other libraries or things you write yourself, you need to tell thelinker where to find that piece of code.

Good libraries are in a *namespace*
  - Prevents name's conflict / collision

Apps don't do what you want. They do what you say. You need to learn no express yourself.


## Type safety

C++ enforces type.
Varibles have type, expressions have type.
This is a strongly typed language.

It's ok to promote: e.g put an integer into a float variable.
Warnings will be gotten for "demote": e.g. putting a float into an int vble. Data might be loss. -> Runtime errors.

Some combinations are not allowed. e.g. multiplying integer with strings or dividing floats with strings.
  => Compiler error.


## Flow of control.

for
while
if
else
else if

this keywords work with logical expressions ->  e.g. (x > 20) results are true or false.

== , != , > ; < ; >= ; <=

## Summary

Expressions also have a type. e.g. 6/7 is a int expression.
