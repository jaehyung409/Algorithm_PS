//
// Created by jaehy on 25. 7. 12..
//

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int l, c;
    std::cin >> l >> c;
    std::vector<char> alphabets(c);
    std::vector<int> index;
    for (int i = 0; i < c; i++) {
        std::cin >> alphabets[i];
        if (i < l) {
            index.push_back(0);
        } else {
            index.push_back(1);
        }
    }
    std::vector<char> vowels{'a', 'e' ,'i', 'o', 'u'};
    std::sort(alphabets.begin(), alphabets.end());
    std::sort(index.begin(), index.end());
    do {
        std::string ans;
        int vowel = 0;
        for (int i = 0; i < c; ++i) {
            if (index[i] == 0) {
                ans.push_back(alphabets[i]);
                for (auto vow : vowels) {
                    if (vow == alphabets[i]) {
                        vowel++;
                    }
                }
            }
        }
        if (vowel > 0 && vowel < l - 1)
            std::cout << ans << '\n';
    } while (std::next_permutation(index.begin(), index.end()));
}