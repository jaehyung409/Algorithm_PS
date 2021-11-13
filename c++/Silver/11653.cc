#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int count{2};

	for(;count * count <= N; count++){
		while(N % count == 0){
			N /= count;
			cout << count << '\n';
		}
	}
	cout << N << '\n';
	
	return 0;

}
