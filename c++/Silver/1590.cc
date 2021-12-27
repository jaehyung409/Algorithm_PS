#include <iostream>
using namespace std;

int main(){
	
	int N,T,min{-1},temp;
	cin >> N >> T;

	int S,I,C;
	for(int i = 0; i < N; i++){
		cin >> S >> I >> C;
		for(int j = 0; j < C; j++){
			if(S + I * j >= T){
				temp = S + I * j - T;
				if(min == -1)
					min = temp;
				else if(min > temp)
					min = temp;
				break;
			}
		}
	}

	cout << min << endl;

	return 0;
}
