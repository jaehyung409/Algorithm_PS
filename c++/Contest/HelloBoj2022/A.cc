#include <iostream>
#include <cmath>
#include <string>
#include <set>
using namespace std;

int main(){
	int N,d,special{0};
	cin >> N >> d;
	
	if(N + 1 >= pow(d,d)){
		cout << "-1" << '\n';
		exit(0);
	}
	special += pow(d,d-1);
	for(int i = 2; i < d; i++){
		special += i * (pow(d,d-i-1)); 
	}
	if(N  + 1 <= special){
		cout << special << '\n';
		exit(0);
	}
	
	string num;
	for(int i = d-1; i >= 0; i--){
		int quotient = N/pow(d,i); 
		N -= pow(d,i) * quotient;
		num += quotient + '0';
	}

	string ans;
	int a = 0;
	bool confirm = true;
	while(1){
		ans.clear();
		set<char> num_set;
		for(int i = 0; i < d; i++)
			num_set.insert(i+'0');
		int aa = d - a - 1, ii = 0;
		for(char it : num){
			if(ii < aa){ 
				ans += it;
				auto search = num_set.find(it);
				if(search != num_set.end())
					num_set.erase(search);
				else 
					break;
			}
			else if(ii == aa){
				for(auto it2 = num_set.begin(); it2 != num_set.end(); it2++){
					if(*it2 > it){
						ans += *it2;
						num_set.erase(it2);
						confirm = false;
						break;
					}
				}
				if(confirm)
					break;
			}
			else{
				ans += *num_set.begin();
				num_set.erase(num_set.begin());
			}
			ii++;
		}
		if(confirm){
			ans = "0";
		}
		if(stoi(ans) > stoi(num) || a >= 10)
			break;
		a++;
		confirm = true;
	}
	if(a >= 10){
		cout << "-1" << endl;
		exit(0);
	}
	int i = d - 1;
	special = 0;
	for(char c : ans){
		special += (c - '0') * pow(d,i);
		i--;
	}
	cout << special << endl;

	return 0;

}
