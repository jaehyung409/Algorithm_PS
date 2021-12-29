#include <iostream>
#include <queue>
using namespace std;

int main(){
	int N,M,price,ans{0},temp,ans_price;
	priority_queue<int> prices;
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> price;
		prices.push(price);
	}	
	for(int i = 1; i <= N; i++){
		if(i > M)
			break;
		temp = prices.top() * i;
		if (temp > ans){
			ans = temp;		
			ans_price = prices.top();
		}
		prices.pop();
	}
	cout << ans_price << ' ' << ans << endl;

	return 0;

}
