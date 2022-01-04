#include <iostream>
using namespace std;

int main(){
	
	int T;
	long N;
	cin >> T;
	
	for(int i = 0; i < T; i++){
		cin >> N;
		if(N % 3 == 2 || N % 9 == 0)
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl; 
	}

	return 0;
	
}
