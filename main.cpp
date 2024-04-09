#include "regex.hpp"


int main(int argc, char *argv[]) {
    std::string pattern = "ab.*c|+";
    if (argc > 1) {
        pattern = argv[1];
        std::cout << "Pattern: " << pattern << std::endl;
        // pattern = infix2postfix(pattern);
        // std::cout << "Postfix: " << pattern << std::endl;
    }

    // State *start = post2nfa(pattern);
    std::cout << "Compiling regex" << std::endl;
    Regex r(pattern);
    std::cout << "Compiled regex" << std::endl;
    std::cout << "NFA: " << std::endl;
    std::cout << r << std::endl;

    std::string content = "ccababc";
    if (argc > 2) {
        content = argv[2];
    }
    std::cout << "Does `" << content << "` match: " << (r.match(content)? "yes" : "no") << std::endl;

    return 0;
}