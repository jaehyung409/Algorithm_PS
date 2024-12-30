//
// Created by jaehy on 24. 12. 30.
//
#include <iostream>
#include <queue>
#include <string>

std::deque<int> input(std::string input_string){
    std::deque<int> ret;
    if (input_string.size() == 2) return ret;
    std::string::size_type Fpos = input_string.find_first_not_of(',',1);
    std::string::size_type Lpos = input_string.find_first_of(',',Fpos);
    while (std::string::npos != Fpos || std::string::npos != Lpos){
        ret.push_back(std::stoi(input_string.substr(Fpos, Lpos - Fpos)));
        Fpos = input_string.find_first_not_of(',', Lpos);
        Lpos = input_string.find_first_of(',', Fpos);
    }
    return ret;
}

int AC_calculator(std::deque<int> &int_arr, std::string &orders, int size){
    int flip_counter = 0;
    bool error = false;
    for (const auto &order : orders){
        if (order == 'R') flip_counter++;
        if (order == 'D'){
            if (size == 0){ // int_arr.empty()
                error = true;
                break;
            }
            if (flip_counter % 2 == 0) int_arr.pop_front();
            else int_arr.pop_back();
            size--;
        }
    }
    if (error) return -2;
    else if (size == 0) return -1;
    else return flip_counter;
}

void output_AC(int status, std::deque<int> &out){
    if (status == -2) std::cout << "error\n";   //error
    else if (status == -1) std::cout << "[]\n"; //size == 0
    else {
        std::cout << '[';
        if (status % 2 == 0) {
            while (out.size() != 1){
                std::cout << out.front() << ',';
                out.pop_front();
            }
            std::cout << out.front();
            out.pop_front();
        }
        else {
            while (out.size() != 1){
                std::cout << out.back() << ',';
                out.pop_back();
            }
            std::cout << out.back();
            out.pop_back();
        }
        std::cout << "]\n";
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_case;
    std::string input_str, orders;
    std::deque<int> int_arr;
    int size;

    std::cin >> test_case;
    for (int i = 0; i < test_case; i++){
        std::cin >> orders >> size >> input_str;
        int_arr = input(input_str);
        output_AC(AC_calculator(int_arr, orders, size), int_arr);
        int_arr.clear();
    }

    return 0;
}