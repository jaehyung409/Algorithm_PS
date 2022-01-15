#include <iostream>
#include <string>
#include <vector>
// similar 1038

long long makeNum(int obj){
	
	int check{-1};
	std::vector<long long> temp1,temp2;
	auto li = {0,1,2,3,4,5,6,7,8,9};
	for(int n : li){
		temp1.push_back(n);
		check++;
		if(check == obj)
			return n;
	}
	for(int i = 0; i < 9; i++){
		for(long long n : temp1){
			for(int j = 0; j < std::to_string(n)[i] - '0'; j++){
				long long ans = 10*n + j;
				temp2.push_back(ans);
				check++;
				if(check == obj)
					return ans;
			}
		}
		temp1.swap(temp2);
		temp2.clear();
	}
	return -1;
}

int main(){

	int N;
	std::cin >> N;
	long long ans = makeNum(N-1);	
	std::cout << ans << std::endl;

	return 0;

}
