#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main(){
	
	int N,M,package_price,piece_price,ans{0};
	std::cin >> N >> M;
	std::priority_queue<int, std::vector<int>, std::greater<int>> package,piece;

	for(int i = 0; i < M; i++){
		std::cin >> package_price >> piece_price;
		package.push(package_price);
		piece.push(piece_price);
	}

	if(piece.top() * 6 < package.top())
		ans = N * piece.top();
	else{
		int temp = (N/6 + 1)*package.top();
		ans = (N/6) * package.top() + (N%6) * piece.top();
		if(ans > temp)
			ans = temp;
	}
	std::cout << ans << std::endl;

	return 0;

}
