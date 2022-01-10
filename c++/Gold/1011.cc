#include <iostream>

int main(){

	int T,x,y,distance{0},ans,temp;
	std::cin >> T;
	
	for(int i = 0; i < T; i++){
		ans = 0;
		temp = 1;
		std::cin >> x >> y;
		distance = y - x;
		while(distance > 0){
			distance -= temp;
			if(ans%2 == 1)
				temp++;
			ans++;
		}	
		std::cout << ans << std::endl;
	}

	return 0;

}
