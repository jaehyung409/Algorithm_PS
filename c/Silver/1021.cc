#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	
	int s,n;
	int k,ans{0},temp1,temp2,op{0};
	cin >> s >> n;
	vector<int> arr;
	for(int i = 1; i < s + 1; i++)
		arr.push_back(i);
	
	for(int i = 0; i < n; i++){
		cin >> k;
		auto it = find(arr.begin(),arr.end(),k);
		k = int(it - arr.begin());
		if (k > ans){
			temp1 = k - ans;
			temp2 = s - k + ans;
		}
		else if(k < ans){
			temp1 = ans - k;
			temp2 = s - ans + k;
		}
		else{
			s -= 1;
			arr.erase(arr.begin() + k);
			ans = k;
			continue;
		}

		if(temp1 > temp2)
			op += temp2;
		else
			op += temp1;
		s -= 1;
		arr.erase(arr.begin() + k);
		ans = k;

	}

	cout << op << endl;

	return 0;

}
