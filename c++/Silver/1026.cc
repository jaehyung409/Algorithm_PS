#include <iostream>
#include <queue>

int main(){

	int S,num,ans{0};
	std::cin >> S;
	std::priority_queue<int> A;
	std::priority_queue<int, std::vector<int>, std::greater<int>> B;
	
	for(int i = 0; i < S; i++){
		std::cin >> num;
		A.push(num);
	}
	for(int i = 0; i < S; i++){
		std::cin >> num;
		B.push(num);
	}

	for(int i = 0; i < S; i++){
		ans += A.top() * B.top();
		A.pop();
		B.pop();
	}

	std::cout << ans << std::endl;
	return 0;

}
