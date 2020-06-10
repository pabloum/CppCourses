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

|
|
|
|
|
|

### Vector

Common need. Bunch of things.
`#include <vector>`

This is a collection

*More on vector*

```
std::vector<int> vi;

for (int i = 0; i<10; i++) {
  vi.push_back(i);
}

for (auto element : vi) {
  std::cout << element << " ";
}

std::vector<std::string> vs;
std::cout << "Enter 3 numbers: \n"

for (int i = 0; i<3; i++) {
  std:string coso;
  std::cin >> coso;
  vs.push_back(coso);
}

vs.push_back("Another test");

vi.size(); // how many elements there already
vi[5] = 5; // 0based indexing. operator[] let's you access and/or modify a particular position.
```

How to iterate over a vector?

We have 3 possible ways:

First: With for-each loop.
```
for (auto element : vi) {
  std::cout << element << " ";
}
```

Second: With traditional indexing.
```
for (unsigned int i = 0; i < vi.size(); i++) {
  std::cout << vi[i] << " ";
}
```

Third. With iterators
```
// for (auto i = vi.begin(); i != vs.end(); i++) { // My way. I do not know if this compiles.
for (auto i = begin(vi); i != end(vi); i++) { // Kate's way. She prefers to use this way instead of the member functions "for advanced reasons."
  std::cout << *i << " ";
}
```

`#include <algorithm>`
- Sort is not a member function of vector, it is a free function:
`sort(begin(vs), end(vs));` Sorts from begining to the end. You could sort just half of the vector.

- Count. Free function as well
`int threes = count(begin(vi), end(vi),3);`
`int tees = count(begin(vs[0]), end(vs[0]), 't');`

std::cout << "Vi  has " << threes << " number 3. \n";
std::cout << "The first element of Vs  has " << tees << " letter T. \n";


=> Summary
.push_back(item)
.insert(); // try to use it just we needed
type safety <type>

string is a collection of characters
|
|
|
|
|
|
|

### Behind more curtains.

In C++, operators are just functions.

Operator overloading

Templates are a powerful way of creating a library.
  They work on any type without giving up type safety

Try making use of overloading


### Summary

Templates reduce bugs, and code.
It makes your code readable
Use vector, dont create a new one. Use what already exists.
