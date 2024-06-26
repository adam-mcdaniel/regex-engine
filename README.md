# regex-engine

![Header Image](assets/header.png)

This repository implements a regex engine in C++ using Thompson's NFA algorithm. This algorithm prevents pathological backtracking, a common problem with most widely used regex implementations.

This implementation is also a header-only library.

## Usage

To use the library, first include it in your C++ file.

```c++
// Optionally, you can define `CACHING` to allow
// the regex engine to cache transition states.
// This can improve performance in many cases.
#define CACHING

// Include the regex header file
#include "regex.hpp"
```

To use the regex engine, first create a regex object with the desired regex pattern. You can use `std::cout` to print out the compiled regex NFA. Use the `match` method to use the regex on a given content string.

```c++
int main() {
    // Compile a regex pattern
    Regex r("((ab)*|c)+");

    // Print out the compiled NFA
    std::cout << r << std::endl;

    // The content to match
    std::string content = "abc";

    // Check if the content matches the regex
    if (r.match(content)) {
        std::cout << "Matched!" << std::endl;
    } else {
        std::cout << "Not matched!" << std::endl;
    }

    return 0;
}
```

## Regex Syntax

The regex engine supports the following syntax:

| Syntax | Description |
|--------|-------------|
| `*` | Zero or more of the preceding expression |
| `+` | One or more of the preceding expression |
| `?` | Zero or one of the preceding expression |
| `\|` | Alternation |
| `()` | Grouping |
| `a`, `b`, `c`, ... | Any single character |

<!-- - `*` - Zero or more of the preceding expression
- `+` - One or more of the preceding expression
- `?` - Zero or one of the preceding expression
- `|` - Alternation
- `()` - Grouping
- `a`, `b`, `c`, ... - Any character -->

## Building

To build your program with the regex engine, simply add it to your include path and link against the C++ standard library.

```bash
g++ -I path/to/regex-engine main.cpp -o main
```

### CMake

To build with CMake, you can use a `CMakeLists.txt` file like the following:

```cmake
cmake_minimum_required(VERSION 3.0)

# Create a new project
project(HelloWorld)

# Add an executable
add_executable(HelloWorld main.cpp)

include_directories(path/to/regex-engine)
```

Alternatively, you can use `FetchContent` to download the regex engine repository and include it in your project.

```cmake
# Import the library from the git repo
include(FetchContent)

FetchContent_Declare(
  regex-engine
  GIT_REPOSITORY https://github.com/adam-mcdaniel/regex-engine
  GIT_TAG        main
)

FetchContent_MakeAvailable(regex-engine)

# Include the header only library
include_directories(${regex-engine_SOURCE_DIR})
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.