#include <cstdio>
#include <string>
#include <unordered_set>

bool check_string(const std::string *arr,int n,int a){
	std::unordered_set<std::string> check;
	for(int i = 0; i < a; i++)
		check.insert(arr[i].substr(n));
	if(check.size() == a)
		return true;
	return false;
}

int main(){
	int R,C,temp;
	scanf("%d %d",&R,&C);
	std::string arr[C];
	
	while(getchar() != '\n')
		continue;

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			arr[j] += getchar();
		}		
		while(getchar() != '\n')
			continue;
	}

	int low{0},high{R-1},mid;
	bool ans_check;

	while(high >= low){
		mid = (low + high) / 2;
		ans_check = check_string(arr,mid,C);
		if(ans_check == true)
			low = mid + 1;
		else
			high = mid - 1;
	
	}
	if(ans_check == false)
		mid--;
	printf("%d \n",mid);
	
	return 0;
}
