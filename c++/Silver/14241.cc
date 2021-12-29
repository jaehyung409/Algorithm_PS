#include <iostream>
#include <queue>
using namespace std;

int main(){

	priority_queue<int> slimes;
	int slime,N,ans{0};
	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> slime;
		slimes.push(slime);
	}	
	
	int temp = slimes.top();
	slimes.pop();
	for(int i = 1; i < N; i++){
		ans += temp * slimes.top();
		temp += slimes.top();
		slimes.pop();
	}

	cout << ans << endl;

	return 0;

}
