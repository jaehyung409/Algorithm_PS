#include <iostream>
#include <string>
using namespace std;

int main(){
	
	int ans = 0;

	for(int i = 0; i < 8; i++){
		
		string a;
		cin >> a;
		
		if (i%2 == 0){
			for(int j = 0; j < 8; j += 2){
				if (a[j] == 'F')
					ans++;
			}
		}
		
		else{
			for(int j = 1; j < 8; j += 2){
				if (a[j] == 'F')
					ans++;
			}
		}
	}

	cout << ans << endl;

}

