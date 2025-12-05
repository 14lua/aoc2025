#include <fstream>
#include <iostream>
#include <string>
#include <vector>

long part_two() {
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
            std::string double_id = id + id;

            int idx = 1;
            while (idx < id.length()) {
                std::string shifted_id = double_id.substr(idx, id.length());

                if (shifted_id == id) {
                    invalid_ids.push_back(id);
                    break;
                }

                idx++;
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
    std::cout << part_two() << std::endl;
}
