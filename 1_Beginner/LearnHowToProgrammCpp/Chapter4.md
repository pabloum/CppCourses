# C++

## Strings and collections

### Intro

C++ hybrid language, because you may have free-functions AND member functions. Both of them.

### String

`#include <string>`
std::string
 can compare, manipulate, search for substrings, make replacements
almost feels like a built-in type.

For Unicode strings -> use `wstring` W for wide. That will support Unicode characters.

Almost everything that works with string, will work with `wstring`

```
std::string name;
cin >> name;

std::string greeting = "Hello, " + name;

std::cout << greeting;

if (name == "Pablo")
  std::cout << "OMG"

greeting += ". You are fantastic.";
```

*Manupulation*

comnine + ; +=
test 2 strings:  == < > !=

cout << and cin >> work perfectly with strings


Member functions:

length();
substr();
find();

and more.

```
int sizeOfGreeting = greeting.length();

```

find(" "); gives back a pointer essentially to a place within the string where there is a space.
           // apparently returns an iterator. Actually returns a very long type.

substr(); if you give it just ONE parameter, it will go from it to the end.
          receives an iterator.


cin >> vble; This just picks the first word of the stream. 
### Vector

*More on vector*


### Behind more curtains.

### Summary
