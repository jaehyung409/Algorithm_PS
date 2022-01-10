#include <iostream>
#include <vector>
#include <string>
#include <iterator>

bool palindrome(int n){
	std::string str = std::to_string(n);
	std::string cp;
	std::copy(str.crbegin(),str.crend(),std::back_inserter(cp));
	if(str == cp)
		return true;
	return false;
}

int main(){

	int n;
	std::cin >> n;
	std::vector<bool> prime(1003002,true);
	prime[1] = false;
	for(int i = 2; i * i <= 1003002; i++){
		if(prime[i] == true){
			for(int j = i * i; j <= 1003002; j += i)
				prime[j] = false;
		}
	}
	for(;; n++){
		if(prime[n]){
			if(palindrome(n)){
				std::cout << n << std::endl;
				break;
			}
		}
	}

	return 0;

}
