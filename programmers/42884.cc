#include <string>
#include <vector>
#include <queue>

using namespace std;

struct compare{
  bool operator()(const pair<int, int> &a, const pair<int, int> &b){
      if (a.second == b.second) return a.first > b.first;
      return a.second > b.second;
  }  
};

int solution(vector<vector<int>> routes) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for (auto vec : routes) {
        pq.emplace(vec.front(), vec.back());
    }
    while (!pq.empty()) {
        int end = pq.top().second;
        pq.pop();
        while (!pq.empty() && pq.top().first <= end) {
            pq.pop();
        }
        answer++;
    }
    return answer;
}