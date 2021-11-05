#include <iostream>
#include <string>
using namespace std;

int main(){
	
	int n,m,i,j;
	cin >> n >> m;
	
	int* arr = new int[n+m];
	string* check = new string[n];

	for (i = 0; i < n; i++)
		cin >> check[i];

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			if (check[i][j] == 'X'){
				arr[i]++;
				arr[n+j]++;
			}
		}
	}

	int ans1 = 0;
	int ans2 = 0;

	for (i = 0; i < n; i++){
		if ( arr[i] == 0)
			ans1++;
	}

	for (i = n; i < n + m; i++){
		if (arr[i] == 0)
			ans2++;
	}

	if (ans1 > ans2)
		cout << ans1 << endl;
	else
		cout << ans2 << endl;

	delete[] arr;
	delete[] check;

	return 0;

}
