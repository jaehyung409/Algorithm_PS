#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int count{2};

	while (N != 1){
		while(N % count != 0){
			count++;
		}
		while(N % count == 0){
			N /= count;
			cout << count << '\n';
		}
											}
	return 0;

}
