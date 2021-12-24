#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	int n,m,sum{0};
	cin >> n >> m;
	
	for(int i = ceil(sqrt(n)); i <= floor(sqrt(m)); i++)
		sum += pow(i,2);

	if(sum == 0)
		cout << "-1" << endl;
	else
		cout << sum << '\n' << pow(ceil(sqrt(n)),2) << endl;

	return 0;

}
