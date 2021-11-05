#include <iostream>
using namespace std;

int main(){
	
	int m,k,i,j;
	cin >> m >> k;
	j = 1;

	while(k){
	
	if (m > j)
		j <<= 1;
	
	else{
		if (m != j && k != 1)
			j >>= 1;
		m -= j;
		j = 1;
		k -= 1;
		if (m == 0)
			break;
		}
	
	}

	if(k == 0)
		cout << -1 *  m  << endl;
	else
		cout << 0 << endl;
		
	return 0;

}

