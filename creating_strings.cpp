#include <iostream>
#include <string>
#include <set>
#include <algorithm>

void generateStrings(std::string prefix, std::string remainingChars, std::set<std::string>& generatedStrings) {
    if (prefix.length() == remainingChars.length()) {
        generatedStrings.insert(prefix);
    } else {
        for (size_t i = 0; i < remainingChars.length(); ++i) {
            std::string newPrefix = prefix + remainingChars[i];
            std::string newRemaining = remainingChars.substr(0, i) + remainingChars.substr(i + 1);
            generateStrings(newPrefix, newRemaining, generatedStrings);
        }
    }
}

int main() {
    std::string inputString;
    std::cin >> inputString;

    std::set<std::string> generatedStrings;
    generateStrings("", inputString, generatedStrings);

    std::cout << generatedStrings.size() << std::endl;
    for (const std::string& s : generatedStrings) {
        std::cout << s << std::endl;
    }

    return 0;
}
