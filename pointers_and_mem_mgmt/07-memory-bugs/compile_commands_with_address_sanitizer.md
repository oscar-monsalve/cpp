```bash
clang++ -g -O1 -fsanitize=address -fno-omit-frame-pointer 07-memory-bugs.cpp -o 07-memory-bugs-asan
```

Then

```bash
ASAN_OPTIONS=detect_leaks=1 ./07-memory-bugs-asan
```
