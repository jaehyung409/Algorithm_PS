#include <iostream>
#include <vector>

int main(){
    int N, K, count = 0, i, tmp;
    std::vector<int> coins;

    std::cin >> N >> K;
    for(i = 0; i < N; ++i) {
        std::cin >> tmp;
        coins.push_back(tmp);
    }
    i--;
    while(K != 0){
        if(K >= coins[i]) {
            count += K/coins[i];
            K %= coins[i];
        }
        else
            i--;
    }
    std::cout << count << '\n';

    return 0;
}