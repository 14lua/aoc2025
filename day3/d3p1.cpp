#include <fstream>
#include <iostream>
#include <vector>

int find_largest(const std::string &bank) {
    int largest_number = std::stoi(std::string() + bank[0] + bank[1]);
    size_t length = bank.length();
    for (size_t fi = 0; fi < length - 1; fi++) {
        for (size_t si = fi + 1; si < length; si++) {
            int number = std::stoi(std::string() + bank[fi] + bank[si]);
            if (number > largest_number)
                largest_number = number;
        }
    }
    return largest_number;
}

int part_one() {
    std::ifstream input("input.txt");
    std::vector<std::string> banks = {};
    int total_joltage = 0;

    std::string line;
    while(std::getline(input, line)) {
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
