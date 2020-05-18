
--------------------------------------------------
#Macros, old keywords, More pointers, and Printf
--------------------------------------------------

##Content:
  Macros, Typedef, Function pointers, Casting, void pointer, printf()
--------------------------------------------------
|
|
|
|
|
_________________
### MACROS
****************
- An old C construct

    `#define PI 3.14`

- Allows you to give a name to something
- Very literal substituion
- Doesnt have a type
- Today it would be better to do as follows:
    - const int or const float inside a namespace or class -> This helps preventing name collision
- There's no type safety. There's just TEXT SUBSTITUTION

`#define SQR(x) (x*x)`
Here, theres no type. However, this would be a type a function. Jsut TEXT SUBSTITUTION

Bad example:  `SQR(1+1) -> (1+1*1+1)`
            This equals 3, and not the desired 4.

This doesnt evaluate the input parameter. Just replaces text.

We would do that today with a function, or a function template, if we need more than just one type

|
|
|
|
_________________
### Typedef
****************

Gives name to something BUT ONLY FOR TYPES

Sets up a synonim that you could think as a type, but it is just a new name for an existing one.


example:
    typedef int BOOL; -> Before a type bool existed.


Why?
  * Make code more portable
  * For expressivity. Have more meaning in type names
  * Reduce typing or <> fear
    - typedef std::vector<int> VectorOfInt


|
|
|
|
_________________
### Function pointers
****************
Almost never in modern C++
  We don't use that much today thanks to polymorphism
  From C++11 we have lambda. Before lambdas, we used funtion pointers as as parameter to other call

But when should we use it?
  -> decide at runtime which function to execute
      e.g. Implement work dispatching systems; menuing systems or all kinds of things
      The old way to do that was Function pointers, C style.

1. Declaration:

  `typedef int     (*CHANGER) (int i, int j);`
        return       name       list parameters

  regular pointers are type safe. These are too. You can't change the type you're pointing to.

2. Declarare instance of that:

  `CHANGER Method;`
  i.e. Method can be used to point to any function that receives 2 int and return 1 int

3. Assign to a function name
  `Method = NameOfFunction;`  -> WITHOUT parenthesis

4. Call the function:
  `Method(3,4);`   -> Just use the normal calling method with ()


  Pointers to member functions are a little more difficult. The previous was just how to point  to regular functions.


  `typedef int (MyClass::*funcptr) (int a, int b);`   -> A function pointer to a member function
  `funcptr action;`
  `action = &MyClass::myMethod;`   -> Be careful. The & is required
  `(myInstance.*action)(a,b);`   -> It is important to dereference.

But we are probably never going to need to use this syntax. But we may run into it in old legacy code.



|
|
|
|
_________________
### Casting
****************

`int i = (int) 4.9;`  // C-style cast
`int i = static_cast<int>(4.9);`  // modern C++ cast. Explicit and clear what you're doing

C-tyle casting was the same for a lot of situations. Base class, or subclass, or derived class. Migth not always be safe, and it was not completly explicit and clear.

Up cast are always safe.
Down casts are only safe if you know that the pointer is geniuly pointing to an instance of the derived class

`p = (Employee*) t;`
`p = (Transaction) t;`

It's very hard to know what kind of cast it is. You might lose data or information with casting. Please don't copy and paste this sort of casting.

Try to use templated cast in new code.

static_cast
const_cast
reinterpret_cast



|
|
|
|
_________________
### Void pointer
****************

void *
- It is NOT a nullptr. It is a pointer to something without a type, to anything.
- We can take any kind of pointer and cast it into a void pointer
- We may pass it to a function, and then cast it into what we know it is, e.g. within a switch.
  * In modern C++ we wouldn't do this. We would use polymorphism.
- It can never be used as it is. You MUST cast it to what you know it is, in order to perform operations with it. That is good, that makes C++ type safe :D

|
|
|
|
_________________
### printf()
****************

 C way of writing to the screen, files or other places

 Meaning: Print with Format.

 It was used a lot for debugging. It might appear commented.

 - This function takes N number of parameters but the first one is always the format string.
    * Foramat string: mix of text and placeholders (which will be substituted with the value of a variable)
  e.g. `printf("This is my value %d \n", value);`

* %s -> string
* %d -> digit (int). %i could also work
* %f -> float
* %x -> hex

  - There could be decorators, such as how many decimals do I want to use and or how many hex deigts I want to print.

  Documentation is available online.


_________________
### Summary
*****************
We should read old code and understand it. But don't use it as template. We don't write code like that anymore!!

Use vectors, lambdas, polymorphism, but try to avoid this old stuff. It is important for you to understand it anyway. 
.
