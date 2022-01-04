#include <cstdio>
#include <set>

int main(){

	int A,B,temp,intersection{0};
	scanf("%d %d", &A, &B);

	std::set<int> A_set;
	for(int i = 0; i < A; i++){
		scanf("%d", &temp);
		A_set.insert(temp);
	}
	for(int i = 0; i < B; i++){
		scanf("%d", &temp);
		auto search = A_set.find(temp);
		if(search != A_set.end())
			intersection++;
	}

	printf("%d \n",A + B - 2 * intersection);
	
	return 0;

}
