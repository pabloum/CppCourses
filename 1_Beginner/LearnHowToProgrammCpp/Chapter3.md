# Learn how to program with C++

## Function and Headers

Functions [...]

### Type safety
Functions respect type safety rules. The arguments you supply may be converted to the parameters that the function takes.

Return value may be converted as well, if not used properly.

double add(double x, double y);
// ...
int r = add(3.4 , 6.67);  // converted to int and thus data will be lost.

### Overloading

different parameters can distinguish overloads

return type can never distinguish overloads.

taking same number of parameters, but with different type is risky.
  -> Not recommended

### Multiple files.

g++ main.cpp Functions.cpp
a

In VS just create the cpp files in the same project and it will build everything

### Header files

Anything that starts with # is an instruction to the preprocessor - a step that runs before the compiler.

Ideally, we just put declarations there. Then, in a cpp, we create the actual implementation.

As a result, the code is neater and easier to understand and maintain.

.h is not technically mandatory. It is just  a convention. At the end of the day, #incluse"Funcitions.h" just copies the content of Functions.h and pastes it into the file which is being invoked.

### Errors and Mistakes

2 places to make mistakes.

  - Compiler problems
      In VS: C291823  - C +  bunch of numbers. For example, when you forget a declaration.
      In GCC:  complains about .cpp files

  - Linker problems
      In VS: LNK238102 -> LNK + bunch of numbers.  For example, when you forget the implementation. (called broken promises)

      In GCC: .o problems. References messages. (.o is for objects that were built already)

### Summary

  Don't repeat yourself
  Let your code be expressive. Create functions even if you're not using them repetitively, just for making your code more expressive, more readable.
