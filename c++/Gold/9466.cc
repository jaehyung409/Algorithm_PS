//
// Created by jaehyung on 24. 11. 22.
//
#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T, n, k;
    long long i, j, temp, hash;
    long long  students[100001];
    bool visited[100001];
    std::cin >> T;
    while (T--){
        std::cin >> n;
        long long ans = n;
        std::fill(visited+1, visited+n+1, false);
        for (i = 1; i < n + 1; i++) std::cin >> students[i];
        for (i = 1; i < n + 1; i++){
            if (visited[i]) continue;
            visited[i] = true;
            if (students[i] == i) {
                ans -= 1;
                continue;
            }
            k = 1;
            j = students[i];
            hash = i * 100001;
            students[i] = hash;
            while (!visited[j]){
                if (students[j] == j) break;
                visited[j] = true;
                temp = students[j];
                students[j] = hash + k++;
                j = temp;
            }
            if (students[j] >= hash && students[j] < hash + k)
                ans -= (hash + k - students[j]);
        }
        std::cout << ans << '\n';
    }

    return 0;
}