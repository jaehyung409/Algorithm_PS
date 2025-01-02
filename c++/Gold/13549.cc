//
// Created by jaehy on 25. 1. 2.
//
#include <iostream>
#include <queue>
#define MAX_SIZE 100001
typedef std::pair<int,int> ii;

int hide_and_seek(int start, int end, int (&dir)[3]){
    if (end <= start) return start - end;
    int time = 1, top, move, next_time;
    std::deque<ii> locate; //location, time
    int visited[MAX_SIZE]; // record time + 1
    std::fill(visited, visited+MAX_SIZE, MAX_SIZE);
    visited[start] = time;
    locate.emplace_front(start, time);
    while (!locate.empty()){
        top = locate.front().first;
        if (top == end) break;
        time = locate.front().second;
        locate.pop_front();
        for (const auto direction : dir) {
            move = direction ? top + direction : top << 1;
            next_time = direction ? time + 1 : time;
            if (move <= 0 || move >= MAX_SIZE) continue;
            if (visited[move] <= next_time) continue;
            visited[move] = next_time;
            direction ? locate.emplace_back(move, next_time) : locate.emplace_front(move, next_time);
        }
    }

    return visited[end]-1;
}

int main(){
    int dir[] = {-1, 1, 0};
    int N, K;
    std::cin >> N >> K;
    std::cout << hide_and_seek(N,K,dir) << '\n';

    return 0;
}