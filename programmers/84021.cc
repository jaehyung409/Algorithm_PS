#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(vector<vector<int>>& table, vector<pair<int, int>>& blocks, vector<vector<bool>>& visited, int x, int y, int size, int number) {
    if (x < 0 || x >= size || y < 0 || y >= size || visited[x][y] || table[x][y] == number) return;
    blocks.emplace_back(x, y);
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        dfs(table, blocks, visited, x + dx[i], y + dy[i], size, number);
    }
}

pair<int,int> rot_x[] = { {1,0}, {0,-1}, {-1,0}, {0,1} };
pair<int,int> rot_y[] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

vector<pair<int, int>> rotate(vector<pair<int, int>>& block, int d) {
    vector<pair<int, int>> temp;
    for (auto &p : block) {
        int x = p.first * rot_x[d].first + p.second * rot_x[d].second;
        int y = p.first * rot_y[d].first + p.second * rot_y[d].second;
        temp.emplace_back(x, y);
    }
    return temp;
}

void normalize(vector<pair<int, int>>& block) {
    int min_x = 51, min_y = 51;
    for (auto &p : block) {
        min_x = min(min_x, p.first);
        min_y = min(min_y, p.second);
    }
    for (auto &p : block) {
        p.first -= min_x;
        p.second -= min_y;
    }
    sort(block.begin(), block.end());
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    const int size = table.size();
    vector<vector<bool>> g_visited(size, vector<bool>(size));
    vector<vector<bool>> t_visited(size, vector<bool>(size));
    list<vector<pair<int, int>>> g_blocks;
    list<vector<pair<int, int>>> t_blocks;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (game_board[i][j] == 0) {
                vector<pair<int, int>> temp;
                dfs(game_board, temp, g_visited, i, j, size, 1);
                g_blocks.emplace_back(temp);
            }
            if (table[i][j] == 1) {
                vector<pair<int, int>> temp;
                dfs(table, temp, t_visited, i, j, size, 0);
                t_blocks.emplace_back(temp);
            }
        }
    }
    for (auto& vec : g_blocks) {
        normalize(vec);
        bool out = false;
        auto size = vec.size();
        for (auto it = t_blocks.begin(); it != t_blocks.end(); ++it) {
            if ((*it).size() != size) continue;
            for (int i = 0; i < 4; ++i) {
                auto temp = rotate(*it, i);
                normalize(temp);
                int j = 0;
                for (; j < size; ++j) {
                    if (vec[j] != temp[j])
                        break;
                }
                if (j == size) {
                    out = true;
                    answer += size;
                    t_blocks.erase(it);
                    break;
                }
            }
            if (out) break;
        }
    }
    return answer;
}