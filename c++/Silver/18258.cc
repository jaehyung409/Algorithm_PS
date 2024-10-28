//
// Created by jaehy on 24. 10. 29.
//

#include <cstdio>
#include <cstring>

struct Queue{
private:
    int queue[2000000] = {};
    int f_point;
    int l_point;
    int size;
public:
    Queue(): f_point(0), l_point(0), size(0) {};
    void push(int x){
        queue[l_point++] = x;
        size++;
    }
    int pop(){
        if (size == 0) return -1;
        size--;
        return queue[f_point++];
    }
    int get_size() { return size; }
    int is_empty() { return !get_size(); }
    int front() {
        if (this->is_empty()) return -1;
        return queue[f_point];
    }
    int back() {
        if (this->is_empty()) return -1;
        return queue[l_point-1];
    }
};

int main(){
    int N;
    char order[6];
    int order_num;
    Queue queue_data;
    std::scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        std::scanf("%s", order);
        if (std::strcmp(order, "push") == 0){
            std::scanf("%d", &order_num);
            queue_data.push(order_num);
        }
        else if (std::strcmp(order, "pop") == 0){
            std::printf("%d\n",queue_data.pop());
        }
        else if (std::strcmp(order, "size") == 0){
            std::printf("%d\n",queue_data.get_size());
        }
        else if (std::strcmp(order, "empty") == 0){
            std::printf("%d\n",queue_data.is_empty());
        }
        else if (std::strcmp(order, "front") == 0){
            std::printf("%d\n",queue_data.front());
        }
        else {
            std::printf("%d\n",queue_data.back());
        }
    }
    return 0;
}