#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

int is_valid_pos(int i, int j, int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m)
        return 0;
    return 1;
}

int check_rolls(std::vector<std::string> &rows) {
    int roll_count = 0;
    std::vector<std::pair<int, int>> to_remove = {};
    for (size_t row = 0; row < rows.size(); row++) {
        for (size_t col = 0; col < rows[row].length(); col++) {
            if (rows[row][col] == '@') {
                int adj_count = 0;
                int row_count = rows.size();
                int col_count = rows[row].length();

                if (is_valid_pos(row - 1, col - 1, row_count, col_count))
                    if (rows[row - 1][col - 1] == '@')
                        adj_count++;
                if (is_valid_pos(row - 1, col, row_count, col_count))
                    if (rows[row - 1][col] == '@')
                        adj_count++;
                if (is_valid_pos(row - 1, col + 1, row_count, col_count))
                    if (rows[row - 1][col + 1] == '@')
                        adj_count++;
                if (is_valid_pos(row, col - 1, row_count, col_count))
                    if (rows[row][col - 1] == '@')
                        adj_count++;
                if (is_valid_pos(row, col + 1, row_count, col_count))
                    if (rows[row][col + 1] == '@')
                        adj_count++;
                if (is_valid_pos(row + 1, col - 1, row_count, col_count))
                    if (rows[row + 1][col - 1] == '@')
                        adj_count++;
                if (is_valid_pos(row + 1, col, row_count, col_count))
                    if (rows[row + 1][col] == '@')
                        adj_count++;
                if (is_valid_pos(row + 1, col + 1, row_count, col_count))
                    if (rows[row + 1][col + 1] == '@')
                        adj_count++;

                if (adj_count < 4) {
                    to_remove.push_back({row, col});
                    roll_count++;
                }
            }
        }
    }

    for (const std::pair<int, int> &pair : to_remove) {
        rows[pair.first][pair.second] = '.';
    }

    return roll_count;
}

void part_one() {
    std::ifstream input("input.txt");
    std::vector<std::string> rows = {};

    std::string line;
    while(std::getline(input, line)) {
        rows.push_back(std::move(line));
    }

    int rolls = 0;
    while(1) {
        int new_rolls = check_rolls(rows);
        if (new_rolls == 0) {
            break;
        }
        rolls += new_rolls;
    }

    std::cout << rolls << std::endl;
}

int main() {
    part_one();
    return 0;
}
