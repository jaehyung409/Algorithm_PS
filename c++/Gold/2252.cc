//
// Created by jaehy on 24. 11. 22.
//
#include <iostream>
#include <vector>
#include <queue>

int main(){
    int N, M, i, student_a, student_b;
    std::cin >> N >> M;
    int in_degree[32001] = {0}, ans[32000];
    std::vector<int> order[N+1];
    for (i = 0; i < M; i++){
        std::cin >> student_a >> student_b;
        order[student_a].push_back(student_b);
        in_degree[student_b]++;
    }

    std::queue<int> students;
    for (i = 1; i < N + 1; i++) if (in_degree[i] == 0) students.push(i);
    i = 0;

    while(!students.empty()){
        int current = students.front();
        ans[i++] = current;
        students.pop();
        for (auto node : order[current])
            if (--in_degree[node] == 0) students.push(node);
    }

    for (i = 0; i < N; i++) std::cout << ans[i] << ' ';
    std::cout << '\n';

    return 0;
}