//
// Created by jaehy on 25. 7. 29.
//

#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int time_to_int(string time) {
    return stoi(time.substr(0,2)) * 60 + stoi(time.substr(3));
}

int time_minus_one(int time) {
    if (time % 100 == 0) {
        return time - 41;
    }
    return time - 1;
}

string time_to_string(int time) {
    int minute = time % 60;
    int hour   = time / 60;
    string min_to_str = to_string(minute);
    if (minute < 10) min_to_str = to_string(0).append(min_to_str);
    string hour_to_str = to_string(hour);
    if (hour < 10) hour_to_str = to_string(0).append(hour_to_str);
    return hour_to_str + ':' + min_to_str;
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<pair<int, int>> bus; // bus time, people
    int standard = time_to_int("09:00");
    for (int i = 0; i < n; ++i) {
        bus.emplace_back(standard + i * t, m);
    }
    vector<int> int_timetable;
    for (auto str : timetable) {
        int_timetable.push_back(time_to_int(str));
    }
    sort(int_timetable.rbegin(), int_timetable.rend());
    for (int i = 0; i < n - 1; ++i) {
        while (bus[i].second) {
            if (int_timetable.back() <= bus[i].first) {
                bus[i].second--;
                int_timetable.pop_back();
            } else {
                break;
            }
        }
    }
    int final_crew = (int_timetable.size() < m)
                ? time_to_int("24:00")
                : *(int_timetable.rbegin() + m - 1);
    return time_to_string(min(time_minus_one(final_crew), bus[n - 1].first));
}