
--------------------------------------------------
# Arrays, pointer arithmetic, and Strings
--------------------------------------------------

##Content:

--------------------------------------------------
|
|
|
|
|

### Legacy

Code never really goes away.
C++ old, looks like other languages

What makes it legacy?
  No lambdas
  No foreach
  Avoids templates
  No std::vector
  No static_cast
  No const
  new and delete pointers
  No standard library: no std::string, no algorithms.
  C being compiled as C++

|
|
|
### Pointers

 - * in a declaration means pointer
 int *

 - & before variable: Means address of that variable
 int j = 4;
 int* pj = &j;

 - * before a variable, means content of:
 e.g. `*pj` -> content of pj, that is called derreferencing

 - -> after a pointer to object is like `(*pj).Method();`

 - Pointers can be null

 - Pointers can be change to point somewhere else.

 - Incrementing a pointer makes it point somewhere else. e.g. `pj++`
    It  advances the pointer by the size of whatever it is it points to.

 - Pointers arithmetic is a great source of bugs!!
    Be careful when solving something with a lot of arithmetic. COnsider redoing it with modern constructions.

|
|
|
|

### C-style arrays.

Declared with a type, and an extent known at compile time.
e.g.
    int mArray[4];

Can be initialized when declared. In that case, no need of specifying size:
e.g.
    int mArray[] = {1,2,3,4};

Access one element with operator[].
e.g.
    mArray[2];

We can also use pointers to access to elements.
e.g.
When no derreferencing, the value would be a pointer (an address) to the first element of the array.
```
double numbers[] = {1.0, 2.0, 3.0, 4.0, 0};

for (double* p = numbers; p != 0; p++) { //p++ increments the size of the element in the array
  *p += 9.9;
}
```

*Array limitations:*
They do not know how many elements they hold.
They don't have member variables or member functions to call to find out the size
They don't have bounds-check
They cannot grow to accommodate a new element

- Dynamic arrays

That doesn't solve the problem, though. That just allows not knowing the size at compile time. But you need to know it at runtime, and it can't grow once you set that up.

How? -> Use new[]

Otherwise, just like stack based arrays.
No extra punctuation.

When you're done, make sure to use delete[]


|
|
|
|

### C-style strings

std::string not used

`char *my_sting`

Array of char
Last element is a null character \0

Large collection of functions with name that start with `str` in the header cstring. i.e. #include <cstring>

e.g strcpy()

Common error: Forget to include room for the null characte. So, people it is common to use a +-1 adjustment por that last element which is part of the array, but not of the string


For modern use, there is a constructor in std::string where you can send a char*, and then it will create the right std::string

And for the other way around, the std::string class has a member function that returns the string in a C style. Such member function is `.c_str()`

strcpy(target, source);

|
|
|
|
|

### Summary
c style array don't bound check if you try to write past the end of them
              they don't self grow
