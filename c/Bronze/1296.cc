#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int prob(string name, int l, int o, int v, int e){
	
	for(int i = 0; i < name.size(); i++){
		if (name[i] == 'L')
			l++;
		if (name[i] == 'O')
			o++;
		if (name[i] == 'V')
			v++;
		if (name[i] == 'E')
			e++;
	}

	return ((l+o) * (l+v) * (l+e) * (o+v) * (o+e) * (v+e))%100;
}

int main(){
	
	string name;
	int n,i,l{0},o{0},v{0},e{0};
	cin >> name >> n;
	
	for(i = 0; i < name.size(); i++){
		if (name[i] == 'L')
			l++;
		if (name[i] == 'O')
			o++;
		if (name[i] == 'V')
			v++;
		if (name[i] == 'E')
			e++;
	}

	string* team = new string[n];
	int temp{0},max{0};
	vector<string> arr;

	for(i = 0; i < n; i++)
		cin >> team[i];
	
	for(i = 0; i < n; i++){
		temp = prob(team[i],l,o,v,e);
		
		if (temp == max){
			arr.push_back(team[i]);
		}

		else if(temp > max){
			max = temp;
			arr.clear();
			arr.push_back(team[i]);
		}
	}
	
	sort(arr.begin(),arr.end());

	cout << arr[0] << endl;
	
	delete[] team;
	return 0;

}
