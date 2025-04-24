# Lab work 4: my_vector and my_array
Authors (team):[Ivan](https://github.com/vvaranytsa)<br>
## Prerequisites

- GCC or any C++20-compatible compiler
- CMake ≥ 3.15
- GoogleTest (installed automatically via FetchContent)
### Compilation

```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### Usage
Tests:
```shell
ctest --output-on-failure
```
Example:
```shell
./my_array_tests
```



