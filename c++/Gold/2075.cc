#include <cstdio>
#include <queue>

int main(){
	int N,temp;
	scanf("%d", &N);
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &temp);
			if(j == 0){
				q.push(temp);
				continue;
			}
			if(q.top() < temp){
				q.pop();
				q.push(temp);
			}
		}
	}
	printf("%d\n",q.top());

	return 0;

}
