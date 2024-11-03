//
// Created by jaehy on 24. 11. 3.
//
#include <iostream>
#include <queue>

struct Node {
    int heuristic;
    int x_pos;
    int y_pos;
    int pre_walking;
    int abs_route;

    Node(int h, int x, int y, int p, int r) : heuristic(h), x_pos(x), y_pos(y), pre_walking(p), abs_route(r){}
};
struct CompareNode {
    bool operator()(Node const& n1, Node const& n2) {
        return n1.heuristic > n2.heuristic;
    }
};

int main(){
    int N, M, maze[100][100];
    bool visited[100][100] = {false};
    bool later_visit[100][100] = {false};
    std::priority_queue<Node, std::vector<Node>, CompareNode> candidates;
    int move[4][2] = {{1, 0 }, {-1, 0}, {0, 1}, {0, -1}};
    std::cin >> N >> M;
    int size = N + M - 2;
    char inp;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            std::cin >> inp;
            maze[i][j] = inp -'0';
        }
    }
    candidates.emplace(size,0,0,1,size);
    while (!visited[N-1][M-1]){
        Node present = candidates.top();
        if (present.x_pos == M-1 && present.y_pos == N-1) std::cout << present.pre_walking <<'\n';
        candidates.pop();
        visited[present.y_pos][present.x_pos] = true;
        for (const auto pos : move){
            int new_x = present.x_pos + pos[0];
            int new_y = present.y_pos + pos[1];
            int preWalking = present.pre_walking + 1;
            if (new_x < 0 || new_x >= M || new_y < 0 || new_y >= N || maze[new_y][new_x] == 0 || visited[new_y][new_x])
                continue;
            candidates.emplace(preWalking + size - new_x - new_y,new_x, new_y, preWalking, size - new_y - new_x);
        }
    }
    return 0;
}