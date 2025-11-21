#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int bfs(vector<vector<int>>& board, int x, int y, int dest_x, int dest_y) {
    vector<tuple<int,int,int>> q;
    q.reserve(16);
    q.emplace_back(x, y, 0);
    int visited[4][4] = {};
    int move_x, move_y;
    visited[x][y] = 1;
    int idx = 0;
    while(1) {
        auto [tx, ty, count] = q[idx++];
        if (tx == dest_x && ty == dest_y) return count;
        for (int i = 0; i < 4; ++i) {
            move_x = tx + dx[i];
            move_y = ty + dy[i];
            if (move_x < 4 && move_x >= 0 && move_y < 4 && move_y >= 0 && !visited[move_x][move_y]) {
                visited[move_x][move_y] = 1;
                q.emplace_back(move_x, move_y, count + 1);
            }
            int cx = tx, cy = ty;
            while (true) {
                int nx = cx + dx[i], ny = cy + dy[i];
                if (!(0 <= nx && nx < 4 && 0 <= ny && ny < 4)) break;
                cx = nx; cy = ny;
                if (board[nx][ny] != 0) break;
            }
            if(!visited[cx][cy]){
                visited[cx][cy] = 1;
                q.emplace_back(cx, cy, count + 1);
            }
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 1000;
    vector<int> vec;
    set<int> s;
    vector<vector<pair<int, int>>> loc(7);
    vector<vector<int>> bits;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == 0) continue;
            s.insert(board[i][j]);
            loc[board[i][j]].emplace_back(i, j);
        }
    }
    for(auto n : s) vec.emplace_back(n);
    int size = vec.size();
    for (int mask = 0; mask < (1 << size); ++mask) {
        vector<int> v(size);
        for (int i = 0; i < size; ++i) v[i] = (mask >> i) & 1;
        bits.emplace_back(v);
    }
    do {
        for (auto bit : bits) {
            int temp = 0;
            int position_x = r, position_y = c;
            vector<vector<int>> board_c = board; // can be optimized
            for (int i = 0; i < size; ++i) {
                int s_x = loc[vec[i]][bit[i]].first;
                int s_y = loc[vec[i]][bit[i]].second;
                int dest_x = loc[vec[i]][!bit[i]].first;
                int dest_y = loc[vec[i]][!bit[i]].second;
                temp += bfs(board_c, position_x, position_y, s_x, s_y);
                if (temp >= answer) break; // pruning
                temp += bfs(board_c, s_x, s_y, dest_x, dest_y);
                if (temp >= answer) break; // pruning
                board_c[s_x][s_y] = 0;
                board_c[dest_x][dest_y] = 0;
                position_x = dest_x; position_y = dest_y;
            }
            answer = min(answer, temp);
        }
    } while (next_permutation(vec.begin(), vec.end()));
    return answer + (size << 1);
}