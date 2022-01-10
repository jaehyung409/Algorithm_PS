#include <algorithm>
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

	int a,b;
	std::cin >> a >> b;
	std::vector<bool> prime(b,true);
	for(int i = 2; i * i <= b; i++){
		if(prime[i] == true){
			for(int j = i * i; j <= b; j += i)
				prime[j] = false;
		}
	}
	for(;a <= b; a++){
		if(prime[a]){
			if(palindrome(a))
				std::cout << a << '\n';
		}
	}
	std::cout << "-1" << std::endl;

	return 0;

}
