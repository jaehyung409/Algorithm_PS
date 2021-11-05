#include <iostream>
using namespace std;

int main(){
	
	int people_num,check{0},temp;
	int check_arr[100] = {0,};

	cin >> people_num;
	
	
	for(int i = 0; i < people_num; i++){
	cin >> temp;
	check_arr[temp-1]++;
	}


	for(int i = 0; i < 100; i++){
	if(check_arr[i] != 0)
		check += check_arr[i]-1;
	}

	cout << check << endl;

	return 0;

}
