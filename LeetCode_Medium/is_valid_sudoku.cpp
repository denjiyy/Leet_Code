#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using std::string;
using std::vector;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            for (int i = 0; i < 9; ++i) {
                std::unordered_map<char, int> row_map;
                std::unordered_map<char, int> col_map;
                std::unordered_map<char, int> box_map;
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] != '.') {
                        if (row_map[board[i][j]]++ > 0) return false;
                    }
                    if (board[j][i] != '.') {
                        if (col_map[board[j][i]]++ > 0) return false;
                    }
                    int box_row = 3 * (i / 3);
                    int box_col = 3 * (i % 3);
                    if (board[box_row + j / 3][box_col + j % 3] != '.') {
                        if (box_map[board[box_row + j / 3][box_col + j % 3]]++ > 0) return false;
                    }
                }
            }
            return true;
        }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '6', '8', '5', '3', '.', '.', '1'},
        {'7', '.', '.', '2', '4', '9', '.', '8', '.'},
        {'.', '6', '.', '.', '.', '2', '8', '4', '.'},
        {'.', '.', '2', '3', '1', '4', '.', '5', '.'},
        {'.', '8', '7', '.', '2', '5', '.', '9', '.'}
    };
    std::cout << solution.isValidSudoku(board) << std::endl;
    return 0;
}
