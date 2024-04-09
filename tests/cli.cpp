#include "regex.hpp"


int main(int argc, char *argv[]) {
    std::string pattern, content;
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <pattern> [content] [-v]" << std::endl;
        return 1;
    }

    bool verbose = false;

    if (argc == 4) {
        // Find the verbose flag
        for (int i = 0; i < argc; i++) {
            if (std::string(argv[i]) == "-v") {
                verbose = true;
                break;
            }
        }

        if (!verbose) {
            std::cerr << "Usage: " << argv[0] << " <pattern> [content] [-v]" << std::endl;
            return 1;
        }
    }

    pattern = argv[1];
    content = argv[2];

    std::cout << "Pattern: " << pattern << std::endl;
    std::cout << "Compiling regex" << std::endl;
    Regex r(pattern);
    std::cout << "Compiled regex" << std::endl;
    std::cout << "NFA: " << std::endl;
    std::cout << r << std::endl;

    std::cout << "Does `" << content << "` match: " << (r.match(content)? "yes" : "no") << std::endl;

    return 0;
}