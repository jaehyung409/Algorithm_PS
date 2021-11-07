#include <stdio.h>
#include <queue>
using namespace std;

int main(){

	int n,i,charging,ans;
	priority_queue<int,vector<int>,greater<int>> charging_arr; //ascending order queue
	
	while(1){
		
		scanf("%d" ,&n);
		
		if(n == 0)
			break;
		
		while(!charging_arr.empty()){
			charging_arr.pop();
		}//queue initialize
		
		for(i = 0;i < n;i++){
			scanf("%d",&charging);
			charging_arr.push(charging);
		}

		ans = 0;

		for(i = 0;i < n; i++){
			if (charging_arr.top() <= ans + 200)
				ans = charging_arr.top();
			else
				break;
			charging_arr.pop();
		}//continuity check
		if (ans >= 1322)
			printf("POSSIBLE\n"); //consider a round-trip
		else
			printf("IMPOSSIBLE\n");
	}

	return 0;

}
