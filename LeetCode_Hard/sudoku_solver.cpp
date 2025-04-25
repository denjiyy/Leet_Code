#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using std::string;
using std::vector;

class Solution {
    public:
        void solveSudoku(vector<vector<char>>& board) {
            solve(board);
        }
        bool solve(vector<vector<char>>& board) {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] == '.') {
                        for (char c = '1'; c <= '9'; ++c) {
                            if (isValid(board, i, j, c)) {
                                board[i][j] = c;
                                if (solve(board)) {
                                    return true;
                                }
                                board[i][j] = '.';
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
        bool isValid(vector<vector<char>>& board, int row, int col, char c) {
            for (int i = 0; i < 9; ++i) {
                if (board[row][i] == c || board[i][col] == c || 
                    board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                    return false;
                }
            }
            return true;
        }
        void printBoard(const vector<vector<char>>& board) {
            for (const auto& row : board) {
                for (char c : row) {
                    std::cout << c << " ";
                }
                std::cout << std::endl;
            }
        }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '6', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '2', '1', '9', '.', '.', '.'},
        {'.', '6', '.', '.', '.', '5', '9', '8', '.'},
        {'.', '5', '9', '7', '4', '2', '.', '.', '.'},
        {'.', '4', '1', '8', '3', '6', '.', '.', '.'}
    };
    
    solution.solveSudoku(board);
    solution.printBoard(board);
    
    return 0;
}
