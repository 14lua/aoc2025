#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> read_file() {
    std::ifstream input("input.txt");
    std::vector<std::string> lines;
    std::string line;

    while(std::getline(input, line))
        lines.push_back(std::move(line));

    return lines;
}

std::vector<std::string> tokenize(const std::string &s) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string t;

    while (ss >> t)
        tokens.push_back(t);

    return tokens;
}

long long part_one() {
    std::vector<std::string> lines = read_file();

    std::vector<std::vector<std::string>> worksheet;
    for (const std::string &line : lines)
        worksheet.push_back(tokenize(line));

    std::vector<std::vector<std::string>> groups;
    for (int col = 0; col < worksheet[0].size(); col++) {
        std::vector<std::string> group;
        for (int row = 0; row < worksheet.size(); row++)
            group.push_back(worksheet[row][col]);
        groups.push_back(group);
    }

    long long sum = 0;
    for (const auto &group : groups) {
        long long res = std::stoll(group[0]);
        if (group.back() == "*")
            for (int i = 1; i < group.size() - 1; i++)
                res *= std::stoll(group[i]);
        else if (group.back() == "+")
            for (int i = 1; i < group.size() - 1; i++)
                res += std::stoll(group[i]);
        sum += res;
    }
    
    return sum;
}

int main() {
    std::cout << part_one() << std::endl;
    return 0;
}
