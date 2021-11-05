#include <iostream>
using namespace std;

int main(){
	
	int n,k,temp,min,max;
	cin >> n;
	
	int* arr = new int[n];

	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	cin >> k;

	min = -1000;
	max = 1000;
	
	for(int i = 0; i < n; i++){
		temp = arr[i] - k;
		if (temp == 0)
			break;
		else if (temp > 0 && temp < max)
			max = temp;
		else if(temp < 0 && temp > min)
			min = temp;
	}

	if (min == -1000 && temp != 0)
		cout << max * k - 1 << endl;
	else if (temp != 0)
		cout << -1 * min * max -1 << endl;
	else
		cout << 0 << endl;
			
	return 0;

}
