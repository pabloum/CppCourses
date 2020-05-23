I don't think the error message is entirely correct. But just this small piece of code will show you that your code is not correct:

```
interval_map<uint8_t, std::string> moo("A");
moo.assign(1, 15, "B");
std::cout << moo[255];
```

Expected value is A, returned value is B.
