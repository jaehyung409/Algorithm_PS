//
// Created by jaehy on 25. 7. 27.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    unordered_map<int, int> work_map;
    for (auto a : works) {
        work_map[a]++;
    }
    for (int i = 50000; i > 0; i--) {
        if (work_map[i] <= n) {
            work_map[i-1] += work_map[i];
            n -= work_map[i];
            work_map [i] = 0;
        } else {
            work_map[i-1] += n;
            work_map[i] -= n;
            break;
        }
    }
    for (int i = 50000; i > 0; i--) {
        answer += pow(i,2) * work_map[i];
    }
    return answer;
}