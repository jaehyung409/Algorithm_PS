#include <iostream>
using namespace std;

int main(){

	int n;
	int i = 1;
	cin >> n;

	while( n > 0 ){
		n -= i;
		i++;
	}

	i -= 1;
	n += i;

	if (i % 2 == 0)
		cout << n << '/' << i - n + 1 << endl;
	else
		cout << i - n + 1 << '/' << n << endl;
	
	return 0;

}



