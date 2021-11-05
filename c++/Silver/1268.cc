#include <iostream>
using namespace std;

int main(){
	
	int n,i,j;
	cin >> n;
	int* arr = new int[5*n];
	int* ans = new int[n];

	for (i = 0; i < n; i++){
		for(j = 0; j <5; j++)
			cin >> arr[i*5+j];
	}

	int max = 0;
	int temp = 1;

	for (i = 0; i < n; i++){
		int k = 0;
		for (int m = i + 1; m < n; m++){
			for(j = 0; j < 5; j++){
				if ( arr[i*5+j] == arr[m*5+j]){
						ans[i]++;
						ans[m]++;
						break;
				}
			}
		}
	}

	for (i = 0; i < n; i++){
		if (ans[i] > max){
			max = ans[i];
			temp = i+1;
		}
	}

	cout << temp << endl;
	
	delete[] arr;
	delete[] ans;
	
	return 0;

}
