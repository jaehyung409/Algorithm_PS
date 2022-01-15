#include <cstdio>
#include <queue>

int main(){

	std::priority_queue<int, std::vector<int>, std::greater<int>> weights;
	int N,weight,measurable{0};
	scanf("%d",&N);

	for(int i = 0; i < N; i++){
		scanf("%d",&weight);
		weights.push(weight);
	}

	for(int i = 0; i < N; i++){
		if(measurable + 1 >= weights.top()){
			measurable += weights.top();
			weights.pop();
		}
		else
			break;
	}
	printf("%d\n",measurable+1);

	return 0;

}
