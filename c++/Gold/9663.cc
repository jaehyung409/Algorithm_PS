//
// Created by jaehy on 24. 11. 10.
//
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#define MAX_SIZE 15

std::vector<std::pair<int,int>> set_queen(int x_pos, int y_pos, int size, bool (&board)[MAX_SIZE][MAX_SIZE]){
    std::vector<std::pair<int,int>> restore_positions;
    for (int i = 1; i < size - y_pos; i++){
        if (board[y_pos+i][x_pos]) {
            board[y_pos+i][x_pos] = false;
            restore_positions.emplace_back(y_pos + i, x_pos);
        }
        if (x_pos+i < size && board[y_pos+i][x_pos+i]){
            board[y_pos+i][x_pos+i] = false;
            restore_positions.emplace_back(y_pos + i, x_pos + i);
        }
        if (x_pos-i >= 0 && board[y_pos+i][x_pos-i]){
            board[y_pos+i][x_pos-i] = false;
            restore_positions.emplace_back(y_pos + i, x_pos - i);
        }
    }
     return restore_positions;
}

void pop_position(const std::vector<std::pair<int,int>>& restore_position, bool (&board)[MAX_SIZE][MAX_SIZE]){
    for (const auto pos : restore_position) {
        board[pos.first][pos.second] = true;
    }
}

int n_queen(int size, int line, bool (&board)[MAX_SIZE][MAX_SIZE], std::stack<std::vector<std::pair<int,int>>> &restore){
    int ans = 0;
    for (int i = 0; i < size; i++){
        if (!board[line][i]) continue;
        if (line == size-1) return 1;
        restore.push(set_queen(i, line, size, board));
        ans += n_queen(size, line + 1, board, restore);
        pop_position(restore.top(), board);
        restore.pop();
    }
    return ans;
}

int main(){
    int N;
    bool board[MAX_SIZE][MAX_SIZE];
    std::stack<std::pair<int,int>> queens;
    std::stack<std::vector<std::pair<int,int>>> restore;
    std::fill(&board[0][0], &board[0][0] + MAX_SIZE * MAX_SIZE, true);
    std::cin >> N;

    std::cout << n_queen(N, 0, board, restore) << '\n';

    return 0;
}