#include <stdio.h>	//fast input,output
#include <algorithm>
#include <vector>
#include <utility>	//use pair
using namespace std;

int main(){
	
	int assignment_n,i,time_temp,deadline;
	vector<pair<int,int>> time_arr;

	scanf("%d",& assignment_n);

	for(i = 0; i < assignment_n; i++){
		scanf("%d %d",&time_temp,&deadline);
		time_arr.push_back(pair<int,int>(deadline,time_temp));
	 }	//input with vector<deadline ,time_temp> (for sorting)

	sort(time_arr.rbegin(),time_arr.rend());

	vector<pair<int,int>>::iterator iter = time_arr.begin();
	int rest_time = iter->first - iter->second;
	iter++;

	for(; iter != time_arr.end(); iter++){
		if(rest_time > iter->first)
			rest_time = iter->first - iter->second;
		else
			rest_time -= iter->second;
	}	//greedy algorithm; (rest_time vs deadline) with '- time_temp' 

	printf("%d \n", rest_time);
	
	return 0;

}
