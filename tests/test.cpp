#include "regex.hpp"
#include <assert.h>

int main() {
    #ifdef CACHING
    std::cout << "Caching enabled" << std::endl;
    #endif

    const int trials = 5;
    for (int n=1; n<=10; n++) {
        std::cout << "Pattern length: " << n << std::endl;
        std::string pattern;
        for (int i=0; i<n; i++) {
            pattern += "a?";
        }
        for (int i=0; i<n; i++) {
            pattern += "a";
        }
        // pattern = infix2postfix(pattern);
        // std::cout << "Postfix: " << pattern << std::endl;
        // State *start = post2nfa(pattern);

        // Check how long it takes to match the pattern
        std::string content = "";
        for (int i=0; i<n; i++)
            content += "a";

        Regex r(pattern);
        // The average time
        // auto start_time = std::chrono::high_resolution_clock::now();
        std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();

        for (int i=0; i<trials; i++) {
            // std::cout << match(start, content) << std::endl;
            std::cout << "Attempt " << i << "... " << std::endl;
            if (!r.match(content)) {
                std::cerr << "Failed" << std::endl;
                return 1;
            }
        }

        std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();
        std::cout << "Average Time: " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / trials << "us" << std::endl;
    }

    std::cout << "Non-pathological tests begin" << std::endl;

    // Now do the same, but with overlapping patterns like (a|aa)*
    std::string pattern = "(a|b|c|d)*";
    Regex r(pattern);
    for (int n=10; n<=1000; n*=2) {
        std::cout << "Content length: " << n << std::endl;
        std::string content = "";

        for (int i=0; i<n; i++)
            content += "abcd";
        assert(content.size() % 2 == 0);

        // The average time
        // auto start_time = std::chrono::high_resolution_clock::now();
        std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();

        for (int i=0; i<trials; i++) {
            // std::cout << match(start, content) << std::endl;
            // std::cout << "Attempt " << i << "... " << std::endl;
            if (!r.match(content)) {
                std::cerr << "Failed" << std::endl;
                return 1;
            }
        }

        std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();
        std::cout << "Average Time: " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / trials << "us" << std::endl;
    }

    std::cout << "All tests passed" << std::endl;
    return 0;
}