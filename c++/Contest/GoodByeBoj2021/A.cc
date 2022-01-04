#include <iostream>
#include <cmath>
using namespace std;

int main(){

	int prime[500] = {};
	for(int i = 0; i < 500; i++)
		prime[i] = i;
	for(int i = 2; i <= sqrt(500); i++){
		for(int j = 2 * i; j < 500; j += i)
			prime[j] = 0;
	}
	
	int N, temp{2};
	cin >> N;
	for(int i = 3; i <500; i++){
		if(prime[i] != 0){
			if(temp * i > N){
				cout << temp * i << endl;
				break;
			}
			temp = i;
		}

	}
	
	return 0;

}
