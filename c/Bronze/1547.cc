#include <iostream>
using namespace std;

int main(){
	
	int n;
	int ans = 1;
	cin >> n;

	for(int i = 0; i < n; i++){
		int a,b;
		cin >> a >> b;
		if(a == ans)
			ans = b;
		else if( b == ans )
			ans = a;
	}

	cout << ans << endl;

	return 0;
}
