//
// Created by jaehy on 24. 12. 28.
//
#include <iostream>
#define MAX_SIZE 100000

int docking(int (&gates)[MAX_SIZE + 1], int gate, int prev){
    if (gates[gate] == 0) return -1;
    else if (gates[gate] == -1) {
        if (gates[prev] == -1 ) return gates[gate] = prev-1;
        gates[gate] = prev;
        return gates[prev]-1;
    }
    int temp = docking(gates, gates[gate], gate);
    gates[gate] = prev;
    return gates[prev] = temp;
}

int main(){
    int G, P, gi, airplane;
    int gates[MAX_SIZE+1];
    std::cin >> G >> P;
    std::fill(gates, gates+G+1, -1);
    for (airplane = 0; airplane < P; airplane++){
        std::cin >> gi;
        if (docking(gates, gi, gi) == -1) break;
    }
    for (int i = airplane + 1; i < P; i++) std::cin >> gi;
    std::cout << airplane;
}