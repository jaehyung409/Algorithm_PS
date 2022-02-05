#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

bool compare(std::pair<char,int> a, std::pair <char,int> b){
	return a.second > b.second;
}

int main(){
	
	int N,ans{0};
	std::string temp;
	std::cin >> N;
	std::map <char,int> word_count;

	for(int i = 0; i < N; i++){
		int position = 1;
		std::cin >> temp;
		for(auto it = temp.rbegin(); it != temp.rend(); it++){
			word_count[*it] += position;
			position *= 10;
		}
	}

	std::vector<std::pair<char,int>> tmp;
	for(auto it = word_count.begin(); it != word_count.end(); it++)
		tmp.push_back(*it);
	std::sort(tmp.begin(),tmp.end(),compare);

	for(int i = 0; i < tmp.size(); i++)
		ans += tmp[i].second * (9 - i);

	std::cout << ans << std::endl;

	return 0;

}
