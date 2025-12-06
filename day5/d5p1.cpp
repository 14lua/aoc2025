#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void read_file(std::vector<std::string> &ranges, std::vector<std::string> &ids) {
    std::ifstream input("input.txt");
    bool first_part = true;
    std::string line;

    while (std::getline(input, line)) {
        if (line.empty()) {
            first_part = false;
            continue;
        }

        if (first_part) {
            ranges.push_back(std::move(line));
        } else {
            ids.push_back(std::move(line));
        }
    }

    input.close();
}

int part_one() {
    std::vector<std::string> ranges;
    std::vector<std::string> ids;
    int fresh_ingredients = 0;

    read_file(ranges, ids);

    for (const std::string &id_str : ids) {
        for (const std::string &range : ranges) {
            int split_idx = range.find('-');
            long long start = std::stoll(range.substr(0, split_idx));
            long long end = std::stoll(range.substr(split_idx + 1));

            long long id = std::stoll(id_str);
            if (id >= start && id <= end) {
                fresh_ingredients++;
                break;
            }
        }
    }

    return fresh_ingredients;
}

int main() {
    std::cout << part_one() << std::endl;
    return 0;
}
