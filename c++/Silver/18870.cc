#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){
	int N,num;
	priority_queue<int, vector<int>, greater<int>> points;
	vector<int> points_array;
	unordered_map<int,int> new_points;
	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> num;
		points_array.push_back(num);
		points.push(num);
	}
	int i = 0;	
	int temp = 1000000001;
	while(!points.empty()){
		if(temp != points.top()){
			new_points[points.top()] = i;
			i++;
			temp = points.top();
		}
		points.pop();
	}
	for(int n : points_array)
		cout << new_points[n] << ' ';
	cout << endl;
	
	return 0;
}
