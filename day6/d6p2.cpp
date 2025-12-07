#include <fstream>
#include <iostream>
#include <vector>

std::vector<std::string> read_file() {
    std::ifstream input("input.txt");
    std::vector<std::string> lines;
    std::string line;

    while(std::getline(input, line))
        lines.push_back(std::move(line));

    return lines;
}

std::vector<std::vector<char>> transpose(std::vector<std::string> &worksheet) {
    int n = worksheet.size();
    int m = worksheet[0].size();
    std::vector<std::vector<char>> ans(m, std::vector<char>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans[j][i] = worksheet[i][j];

    return ans;
}

long long part_two() {
    std::vector<std::string> lines = read_file();
    std::vector<std::vector<char>> transposed = transpose(lines);

    std::vector<std::string> nums;
    for (int row = transposed.size() - 1; row >= 0; row--) {
        std::string num = "";
        for (int col = 0; col < transposed[0].size(); col++) {
            char curr = transposed[row][col];
            if (curr != ' ')
                num += curr;
        }
        nums.push_back(num);
    }


    std::vector<std::vector<std::string>> problems = {{}};
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == "") {
            problems.push_back({});
            continue;
        }
        problems.back().push_back(nums[i]);
    }

    long long sum = 0;
    for (const auto &problem : problems) {
        long long res = std::stoll(problem[0]);
        if (problem.back().back() == '*') {
            for (int i = 1; i < problem.size(); i++) {
                std::string curr = problem[i];
                if (i == problem.size() - 1)
                    curr = curr.substr(0, curr.length());
                res *= std::stoll(curr);
            }
        } else if (problem.back().back() == '+') {
            for (int i = 1; i < problem.size(); i++) {
                std::string curr = problem[i];
                if (i == problem.size() - 1)
                    curr = curr.substr(0, curr.length());
                res += std::stoll(curr);
            }
        }
        sum += res;
    }

    return sum;
}

int main() {
    std::cout << part_two() << std::endl;
    return 0;
}
