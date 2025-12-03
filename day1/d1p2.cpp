#include <fstream>
#include <iostream>

int part_two() {
    int upper = 99;
    int lower = 0;
    int zero_count = 0;
    int pointing_at = 50;
    std::ifstream input("input.txt");

    for (std::string line; std::getline(input, line);) {
        int num = std::stoi(line.substr(1));

        switch (line[0]) {
            case 'L':
                for (int i = 0; i < num; i++) {
                    pointing_at--;
                    if (pointing_at < lower) {
                        pointing_at = upper;
                    }
                    if (pointing_at == 0) {
                        zero_count++;
                    }
                }
                break;
            case 'R':
                for (int i = 0; i < num; i++) {
                    pointing_at++;
                    if (pointing_at > upper) {
                        pointing_at = lower;
                    }
                    if (pointing_at == 0) {
                        zero_count++;
                    }
                }
                break;
        }
    }

    return zero_count;
}

int main() {
    std::cout << part_two() << std::endl;
}
