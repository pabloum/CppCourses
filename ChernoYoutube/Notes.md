
wandbox.org -> online compiler


### Lvalues && Rvalues

Lvalues => have a location in memory
Rvalues => temporary value. Does not have a location in memory // memory address.

`int x = 5;`
"left" value = "right" value -> Just an analogy. Might not always be true.

`int x = 6;`
`int y = x;` -> In this case, both sides are left values.

Other example:
```
int& GetRef() {
  static int value = 10;
  return value;
}

GetRef() = 25;  // this might be valid
```

1. Lvalue reference
`void foo (int& x);`   -> Just admits lvalue references
`foo(x);`

2. Rvalue reference
`void foo (int&& x);`  -> Just admits rvalue references
`foo(10);`

3. Admit both references
`void foo (const int& x);`  -> Admits rvalue AND lvalue references
`foo(x);`
`foo(10);`

### Function argument evaluation order

UNDEFINED BEHAVIOR

```
void foo(int x, int y) {
  std::cout << x << y << '\n';
}
int main() {

  int a = 0;
  foo(a++, ++a);  // Undefined behavior. Everuthing could happen
  return 0;
}
```
There is no
