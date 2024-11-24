//
// Created by jaehy on 24. 11. 24.
//
#include <iostream>
#include <vector>

std::vector<int> sudoku_candidates(int (&board)[9][9], int row, int col){
    std::vector<int> ret;
    bool arr[10];
    std::fill(arr+1, arr+10, true);
    for (int i = 0; i < 9; i++) arr[board[row][i]] = false;
    for (auto & i : board) arr[i[col]] = false;
    for (int i = (row/3) * 3; i < (row/3) * 3 + 3; i++){
        for (int j = (col/3) * 3; j < (col/3) * 3 + 3; j++)
            arr[board[i][j]] = false;
    }
    for (int i = 1; i < 10; i++) if (arr[i]) ret.push_back(i);
    return ret;
}

std::pair<int, int> find_zero(int (&board)[9][9], int row, int col){
    for (int i = col; i < 9; i++)
        if (board[row][i] == 0) return std::make_pair(row, i);
    for (int i = row + 1; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] == 0) return std::make_pair(i, j);
        }
    }
    return std::make_pair(-1, -1); // complete
}

void print_sudoku(int (&board)[9][9]){
    for (auto & i : board){
        for (int & j : i) std::cout << j;
        std::cout << '\n';
    }
}

void solve_sudoku(int (&board)[9][9], int row, int col){
    std::pair<int, int> pos = find_zero(board, row, col+1);
    std::vector<int> candidate = sudoku_candidates(board, row, col);
    if (pos.first == -1 && !candidate.empty()){
        board[row][col] = candidate.front();
        print_sudoku(board);
        exit(0);
    }
    for (auto num : candidate){
        board[row][col] = num;
        solve_sudoku(board, pos.first, pos.second);
        board[row][col] = 0;
    }
}
int main(){
    int board[9][9];
    char num;
    for (auto & i : board){
        for (int & j : i) {
            std::cin >> num;
            j = num - '0';
        }
    }
    std::pair<int, int> fir = find_zero(board, 0, 0);
    solve_sudoku(board, fir.first, fir.second);

    return 0;
}