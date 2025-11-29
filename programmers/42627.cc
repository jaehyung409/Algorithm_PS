#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(vector<int>&lhs, vector<int>& rhs) {
    return lhs.front() < rhs.front();
}

struct Compare{
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if (a[1] != b[1]) return a[1] > b[1]; // 소요시간 
        if (a[0] != b[0]) return a[0] > b[0]; // 요청시간
        return a[2] > b[2]; // 작업 번호
    }  
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    sort(jobs.begin(), jobs.end(), compare);
    for (int i = 0; i < jobs.size();) {
        if (time <= jobs[i][0] && pq.empty()) time = jobs[i][0];
        for (; i < jobs.size() && time >= jobs[i][0]; ++i) {
            jobs[i].emplace_back(i);
            pq.emplace(jobs[i]);
        }
        int s = pq.top()[0], t = pq.top()[1]; 
        pq.pop();
        time += t;
        answer += time - s;
    }
    while (!pq.empty()) {
        int s = pq.top()[0], t = pq.top()[1]; 
        pq.pop();
        time += t;
        answer += time - s;
    }
    return answer / jobs.size();
}