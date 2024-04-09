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

## Building

To build your program with the regex engine, simply add it to your include path and link against the C++ standard library.

```bash
g++ -I path/to/regex-engine main.cpp -o main
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.