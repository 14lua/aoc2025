#include <fstream>
#include <iostream>
#include <vector>

long find_largest(const std::string &bank) {
    std::string joltage = "";
    size_t drop = 11;
    size_t start = 0;

    while (joltage.length() != 12) {
        char largest = '\0';
        for (size_t i = start; i < bank.length() - drop; i++) {
            if (bank[i] > largest) {
                largest = bank[i];
                start = i + 1;
            }
        }
        joltage += largest;
        drop--;
    }

    return std::stol(joltage);
}

long part_one() {
    std::ifstream input("input.txt");
    std::vector<std::string> banks = {};
    long total_joltage = 0;

    std::string line;
    while (std::getline(input, line)) {
        banks.push_back(std::move(line));
    }

    for (const std::string &bank : banks) {
        total_joltage += find_largest(bank);
    }

    return total_joltage;
}

int main() {
    std::cout << part_one() << std::endl;
    return 0;
}
