
--------------------------------------------------
#Macros, old keywords, More pointers, and Printf
--------------------------------------------------

##Content:
  Macros, Typedef, Function pointers
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
  `(myInstance.*action)();`   -> It is important to dereference.

But we are probably never going to need to use this syntax. But we may run into it in old legacy code.



|
|
|
|
_________________
### Casting
****************


.
