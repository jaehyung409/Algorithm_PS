#include <iostream>
using namespace std;

int main(){

	char A[10001];
	char B[10001];

	cin >> A >> B;

	long long int sum{0};
	
	for(int i = 0; char a = A[i]; ++i){
		for(int j = 0; char b = B[j]; ++j)
			sum += (a - '0') * (b - '0');
	}
	
	cout << sum << '\n';

	return 0;

}
