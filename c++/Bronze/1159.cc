#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int N,check{0};
	cin >> N;
	string player;	
	map<char,int> player_list;
	for (int i = 0; i < N; i++){
		cin >> player;
		player_list[player[0]]++;
	}
	for(auto iter = player_list.begin(); iter != player_list.end(); iter++){
		if ( iter->second >= 5){
			cout << iter->first;
			check++;
		}
	}

	if(!check)
		cout << "PREDAJA";
	cout << endl;

	return 0;

}
