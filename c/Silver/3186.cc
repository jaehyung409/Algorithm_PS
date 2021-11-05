#include <iostream>
#include <string>
using namespace std;

int main(){

	int k,l,n;
	cin >> k >> l >> n;
	cin.ignore();
	string list;
	getline(cin,list);
	int count{0},rest{0},check{0};

	for (int i = 0; i < n; i++){
		if (list[i] == '1'){
			rest = 0;
			count++;
		}
		else{
			if (count >= k){
				rest++;
				if (rest >= l){
					count = 0;
					check++;
					cout << i+1 << endl;
				}
			}
			else
				count = 0;
		}
	}
	if(count >= k){
		cout << n + l << endl;
		check++;
	}
	if (check == 0)
		cout << "NIKAD" << endl;
	
	return 0;
}
