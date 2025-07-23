//
// Created by jaehy on 25. 7. 20.
//

#include <string>
#include <vector>

using namespace std;

string dec_to_bin(long long number) {
    string binary;
    for (;number != 0; number /= 2) {
        binary.push_back(number % 2 + '0');
    }
    int size = binary.size();
    for (int i = 1; size > 0; i *= 2) {
        size -= i;
    }
    string padding(-1 * size, '0');
    return binary.append(padding);
}

bool judge(string& binary, vector<bool> &visited, int idx, int len, char root, const int size) {
    if (visited[idx] || idx < 0 || idx >= size)
        return true;
    visited[idx] = true;
    if (binary[idx] == '1' && root == '0')
        return false;
    return judge(binary, visited, idx - len, len / 2, binary[idx], size) &&
           judge(binary, visited, idx + len, len / 2, binary[idx], size);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (auto num : numbers) {
        string binary = dec_to_bin(num);
        int size = binary.size();
        vector<bool> visited(size, false);
        if (judge(binary, visited, size / 2, (size + 1) / 4, '1', size)) {
            answer.push_back(1);
        } else {
            answer.push_back(0);
        }
    }
    return answer;
}