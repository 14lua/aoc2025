#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

long part_one() {
    std::ifstream input("input.txt");
    std::string line;
    std::vector<std::string> ranges = {};
    std::vector<std::string> invalid_ids = {};

    std::string t;
    while(std::getline(input, t, ',')) {
        ranges.push_back(t);
    }


    for (const std::string &range : ranges) {
        long start = std::stol(range.substr(0, range.find('-')));
        long end = std::stol(range.substr(range.find('-') + 1));

        for (long i = start; i <= end; i++) {
            std::string id = std::to_string(i);

            int window_size = std::ceil((id.length() / 2));

            while (window_size > 0) {
                if (id.length() % window_size != 0) {
                    window_size--;
                    continue;
                }

                std::vector<std::string> chunks = {};
                int idx_start = 0;
                int idx_end = window_size;
                while (idx_end != id.length() - 1) {
                    chunks.push_back(id.substr(idx_start, idx_end));
                    idx_start += window_size;
                    idx_end += window_size;
                }
            }

            std::string id_halve_1 = id.substr(0, id.length() / 2);
            std::string id_halve_2 = id.substr(id.length() / 2);

            if (id_halve_1 == id_halve_2) {
                invalid_ids.push_back(id);
            }
        }
    }

    long sum = 0;
    for (const std::string &id : invalid_ids) {
        sum += std::stoll(id);
    }

    return sum;
}

int main() {
    std::cout << part_one() << std::endl;
}
