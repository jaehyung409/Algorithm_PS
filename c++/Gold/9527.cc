//
// Created by jaehy on 24. 12. 29.
//
#include <iostream>
typedef long long ll;

ll dict_bit_number(ll num, ll (&bit_counter)[60]){
    ll counter = 0;
    ll digit = 0;
    for (int i = 59; i >= 0; i--){
        if ((num >> i) & 1){
            counter++;
            counter += bit_counter[i] + digit * ((ll)1 << i);
            digit++;
        }
    }
    return counter;
}

int main(){
    ll bit_counter[60];
    ll A, B;
    bit_counter[0] = 0;
    for (int i = 1; i < 60; i++)
        bit_counter[i] = (bit_counter[i-1] << 1) + ((ll)1 << (i-1));
    std::cin >> A >> B;
    std::cout << dict_bit_number(B, bit_counter)
               - dict_bit_number(A-1, bit_counter) << '\n';

    return 0;
}

