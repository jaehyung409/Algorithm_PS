#include <iostream>
#include <stack>

int priority(const char&);
int main(){

    std::stack<char> op;
    std::string str;

    std::cin >> str;
    for(const auto& s : str){
        if(65 <= s && s <= 90)
            std::cout << s;
        else{
            if(priority(s) == 4){
                while(op.top() != 40 && !op.empty()){
                    std::cout << op.top();
                    op.pop();
                }
                if(op.top() == 40)
                    op.pop();
            }
            else if(op.empty() || op.top() == 40)
                op.push(s);
            else if(priority(s) == 3)
                op.push(s);
            else if(priority(op.top()) < priority(s))
                op.push(s);
            else if(priority(op.top()) >= priority(s)){
                while(!op.empty() && op.top() != 40 && priority(op.top()) >= priority(s)){
                    std::cout << op.top();
                    op.pop();
                }
                op.push(s);
            }
        }
    }
    while(!op.empty()){
        std::cout << op.top();
        op.pop();
    }
    std::cout << std::endl;
}

int priority(const char& s){
    if(s == 43 || s == 45)
        return 1;
    if(s == 42 || s == 47)
        return 2;
    if(s == 40)
        return 3;
    if(s == 41)
        return 4;
    return 0;
}