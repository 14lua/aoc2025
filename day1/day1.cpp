#include <fstream>
#include <iostream>
#include <string>

int WRAP_UPPER = 99;
int WRAP_LOWER = 0;

int wrap_within_bounds(int x, int const lowerBound, int const upperBound) {
    int range_size = upperBound - lowerBound + 1;

    if (x < lowerBound) {
        x += range_size * ((lowerBound - x) / range_size + 1);
    }

    return lowerBound + (x - lowerBound) % range_size;
}

int part_one() {
    int zero_counts = 0;
    int pointing_at = 50;
    std::ifstream input("input.txt");

    for (std::string line; std::getline(input, line);) {
        int num = std::stoi(line.substr(1));
        int direction;

        switch (line[0]) {
            case 'L':
                direction = -1;
                break;
            case 'R':
                direction = 1;
                break;
        }

        pointing_at =
            wrap_within_bounds(pointing_at + (num * direction), 0, WRAP_UPPER);

        if (pointing_at == 0) {
            zero_counts++;
        }
    }

    return zero_counts;
}

int main() {
    std::cout << "Part 1: " << part_one() << std::endl;
    return 0;
}
