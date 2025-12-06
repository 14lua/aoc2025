#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::vector<std::string> read_file() {
    std::ifstream input("input.txt");
    bool first_part = true;
    std::string line;
    std::vector<std::string> ranges;

    while (std::getline(input, line)) {
        if (line.empty())
            break;

        ranges.push_back(std::move(line));
    }

    input.close();
    return ranges;
}

std::vector<std::pair<long long, long long>> merge_ranges(const std::vector<std::string> &ranges) {
    std::vector<std::pair<long long, long long>> intervals;
    std::vector<std::pair<long long, long long>> merged;

    for (const std::string &range : ranges) {
        int split_idx = range.find('-');
        long long start = std::stoll(range.substr(0, split_idx));
        long long end = std::stoll(range.substr(split_idx + 1));

        intervals.push_back({start, end});
    }

    std::sort(intervals.begin(), intervals.end());

    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        std::pair<long long, long long> &last = merged.back();
        std::pair<long long, long long> &curr = intervals[i];

        if (curr.first <= last.second)
            last.second = std::max(last.second, curr.second);
        else
            merged.push_back(curr);
    }

    return merged;
}

long part_two() {
    std::vector<std::string> ranges = read_file();
    long fresh_ingredients = 0;

    std::vector<std::pair<long long, long long>> merged = merge_ranges(ranges);

    for (const auto &pair : merged) {
        fresh_ingredients += pair.second - pair.first + 1;
    }

    return fresh_ingredients;
}

int main() {
    std::cout << part_two() << std::endl;
    return 0;
}
