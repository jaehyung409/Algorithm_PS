#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(){

	int even_check{0},ans{0},prime_factor{0};
	string N;  // for even_check
	cin >> N;
	
	int number = stoi(N);
	int temp{number},count{2};
	
	while(temp != 1){
		while(temp % count != 0){
			count++;
		}
		while(temp % count == 0){
			temp /= count;
		}
		prime_factor++;
	}//	check kind of prime_factor 

	for(int i= 0; i < N.size(); i++)
		even_check += N[i] - '0';
	
	if (number > 5 && even_check %2 == 1)
		ans++;
	if (prime_factor != 0 && prime_factor %2 == 0 || number == 2 || number == 4)
		ans += 2;
	if (ans == 3)//	both
		ans++;
	if (ans == 0)//	neither
		ans = 3;

	cout << ans << endl;
	
	return 0;

}
