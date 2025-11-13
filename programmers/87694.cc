#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int area[101][101] = {};
int edge[101][101] = {};
int visited[101][101] = {};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void draw(vector<int>& pos) {
    int x_left = pos[0] << 1, y_left = pos[1] << 1, 
        x_right = pos[2] << 1, y_right = pos[3] << 1;
    for (int x = x_left; x <= x_right; ++x) {
        for (int y = y_left; y <= y_right; ++y) {
            if (x == x_left || x == x_right || y == y_left || y == y_right) {
                if (area[x][y] == 0) {
                    edge[x][y] = 1;
                }
            } else {
                if (edge[x][y] == 1) {
                    edge[x][y] = 0;
                }
            }
            area[x][y] = 1;
        }
    }
}

int move(int x, int y, int dest_x, int dest_y, int count) {
    for (int dir = 0; dir < 4; ++dir) {
        int new_x = x + dx[dir], new_y = y + dy[dir];
        if (new_x <= 100 && new_y <= 100) {
            if (new_x == dest_x && new_y == dest_y) return count + 1;
            if (visited[new_x][new_y] == 0 && edge[new_x][new_y]) {
                visited[new_x][new_y] = 1;
                return move(new_x, new_y, dest_x, dest_y, count + 1);
            }
        } 
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for (auto& pos : rectangle) {
        draw(pos);
    }
    characterX <<= 1; characterY <<= 1; itemX <<= 1; itemY <<= 1;
    visited[characterX][characterY] = 1;
    int first = move(characterX, characterY, itemX, itemY, 0);
    int second = move(characterX, characterY, itemX, itemY, 0);
    return min(first, second) / 2;
}