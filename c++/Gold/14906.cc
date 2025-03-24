//
// Created by jaehy on 25. 3. 23.
//

#include <iostream>
#include <string_view>

std::pair<bool, std::string_view> is_slump(std::string_view sv, int slimpc) {
    if (sv.empty() || sv.front() != 'F') return {false, sv};
    sv = sv.substr(1);
    for (; !sv.empty() && sv.front() == 'F';) {
        sv = sv.substr(1);
    }
    if (sv.empty()) return {false, sv};
    if (sv.front() == 'D' || sv.front() == 'E') return is_slump(sv.substr(1), slimpc);
    if (sv.front() == 'G') {
        sv = sv.substr(1);
        while (slimpc) {
            if (sv.empty() || sv.front() != 'C') return {false, sv};
            sv = sv.substr(1);
            --slimpc;
        }
        return {true, sv};
    }
    return {false, sv};
}

std::pair<bool, std::string_view> is_slimp(std::string_view sv, int slimpc) {;
    if (sv.empty()) return {false, sv};
    if (sv.front() == 'H') {
        sv = sv.substr(1);
        while (slimpc) {
            if (sv.empty() || sv.front() != 'C') return {false, sv};
            sv = sv.substr(1);
            --slimpc;
        }
        return {true, sv};
    }
    if (sv.front() == 'B') {
        sv = sv.substr(1);
        if (sv.empty() || sv.front() != 'A') return {false, sv};
        return is_slimp(sv.substr(1), slimpc + 1);
    }
    if (sv.front() == 'D' || sv.front() == 'E') return is_slump(sv.substr(1), slimpc + 1);
    return {false, sv};
}

bool is_slurpys(std::string_view sv) {
    if (sv.empty() || sv.front() != 'A') return false;
    if (auto [slimp, str_v] = is_slimp(sv.substr(1), 0); slimp && !str_v.empty()) {
        if (str_v.front() == 'D' || str_v.front() == 'E') {
            if (auto [ret, _] = is_slump(str_v.substr(1), 0); ret && _.empty()) return true;
        }
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << "SLURPYS OUTPUT\n";
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        if (is_slurpys(str)) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
    std::cout << "END OF OUTPUT\n";
}