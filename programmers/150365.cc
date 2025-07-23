//
// Created by jaehy on 25. 7. 22.
//

#include <string>
#include <map>

using namespace std;
// order : dlru
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'d', 'l', 'r', 'u'};
string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int distance = abs(x - r) + abs(y - c);
    int remain = k - distance;
    if (remain < 0 || remain % 2 != 0) {
        return "impossible";
    }
    map<char, int> command;
    command['d'] = max(r - x, 0);
    command['l'] = max(y - c, 0);
    command['r'] = max(c - y, 0);
    command['u'] = max(x - r, 0);
    int new_x, new_y;
    while (k) {
        for (int i = 0; i < 4; ++i) {
            new_x = x + dx[i];
            new_y = y + dy[i];
            if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m) {
                if (command[dir[i]] == 0 && remain == 0)
                    continue;
                x = new_x; y = new_y;
                if (command[dir[i]] > 0) {
                    command[dir[i]]--;
                } else {
                    remain -= 2;
                    command[dir[3 - i]]++;
                }
                answer.push_back(dir[i]);
                k--;
                break;
            }
        }
    }

    return answer;
}