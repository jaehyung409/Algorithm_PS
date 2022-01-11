#include <functional>
#include <iostream>
#include <cmath>
#include <vector>

bool isPrime(int n){
	for(int i = 2; i <= std::sqrt(n); i++){
		if(n%i == 0)
			return false;
	}
	return true;
}

void makePrime(int n){
	const auto data = {2,3,5,7};
	std::vector<int> temp1,temp2;
	for(int d : data)
		temp1.push_back(d);

	while(n != 1){
		for(int t : temp1){
			for(int i = 0; i <= 9; i++){
				if(isPrime(t*10 + i))
					temp2.push_back(t*10+i);
			}

		}
		temp1.swap(temp2);
		temp2.clear();
		n--;
	}

	for(int t : temp1)
		std::cout << t << '\n';

}

int main(){
	
	int N;
	std::cin >> N;
	makePrime(N);

	return 0;
	
}
