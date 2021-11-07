#include <stdio.h>
#include <queue>
using namespace std;

int main(){

	int honor_people,i,honor;
	scanf("%d", &honor_people);
	priority_queue<int,vector<int>,greater<int>> honor_arr; //ascending order queue
	
	for(i = 0; i < honor_people; i++){
		scanf("%d",&honor);
		honor_arr.push(honor);
	}

	int Defile_check{1};
	long int Defile_count{0}; // ans cna be bigger than 65536

	for(i = 0; i < honor_people; i++){
		if (honor_arr.top() >= Defile_check){
			Defile_count += honor_arr.top() - Defile_check;
			Defile_check++;
		}
		honor_arr.pop();
	}// if (honor >= Defile_check) then we need hacker for defile

	printf("%ld \n", Defile_count);

	return 0;

}
