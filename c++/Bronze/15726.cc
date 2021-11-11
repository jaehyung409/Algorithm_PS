#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long int a,b,c;
	cin >> a >> b >> c;
	
	long long int d = a * max(b,c) / min(b,c);
	cout << d << endl;

	return 0;

}
