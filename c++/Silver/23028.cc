#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int N,A,B,X,Y;
	cin >> N >> A >> B;

	for(int i = N; i < 8; i++){
		cin >> X >> Y;
		A += X * 3;
		B += min(X+Y,6) * 3;
	} // greedy; first: major , second: total with min(maximum credit, limit credit)
	
	for(int i = 0; i < N + 2; i++)
		cin >> X >> Y;
	
	if(A >= 66 && B >= 130)
		cout << "Nice" << endl;
	else
		cout << "Nae ga wae" << endl;
	
	return 0;

}
