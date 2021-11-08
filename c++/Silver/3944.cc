#include <iostream>
#include <string>
using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);	// for reduce cin/cout time

	int T,base_num,remainder;
	string num_array;

	cin >> T;

	for(int i = 0; i < T; i++){
		remainder = 0;

		cin >> base_num >> num_array;
	
		for(int j = 0; j < num_array.size(); j++)
			remainder += num_array[j] - '0';	// divide by positional number
		
		remainder %= base_num - 1;
		cout << remainder << "\n";
	}

	return 0;

}
