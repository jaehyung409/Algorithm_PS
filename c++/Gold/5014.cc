#include <vector>
#include <iostream>

int main(){

	int F,S,G,U,D;
	std::cin >> F >> S >> G >> U >> D;

	std::vector<bool> stairs(F+1,false);
	stairs[0] = stairs[S] = true;
	std::vector<int> temp,init;
	init.push_back(S);

	int ans = 0;
	while(1){
		for(int n : init){
			if(n == G){
				std::cout << ans << std::endl;
				exit(0);
			}
			if(n + U <= F){
				if(!stairs[n+U]){
					stairs[n+U] = true;
					temp.push_back(n+U);
				}
			}
			if(n > D ){
				if(!stairs[n-D]){
					stairs[n-D] = true;
					temp.push_back(n-D);
				}
			}
		}
		ans++;
		if(temp.size() == 0){
			std::cout << "use the stairs\n" ;
			exit(0);
		}
		init.swap(temp);
		temp.clear();
	}

	return 0;

}
