#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

std::unordered_map<char,int> makeMap(const std::string& str){
	std::unordered_map<char,int> dict;
	for(int i = 0; i < str.size(); i++)
		dict[str[i]]++; 

	return dict;
}

bool checkSimilar(std::unordered_set<char> chars,
				  std::unordered_map<char,int> origin, std::unordered_map<char, int> check){

	int minus{0},plus{0};
	for(const auto& a : check)
		chars.insert(a.first);
	for(const auto& a : chars){
		if(origin[a] == check[a])
			continue;
		if(origin[a] > check[a])
			minus += origin[a] - check[a];
		if(origin[a] < check[a])
			plus += check[a] - origin[a];
	}
	
	if(minus <= 1 && plus <= 1)
		return true;
	
	return false;	
}

int main(){

	int N,ans{0};
	std::string origin,check;
	
	std::cin >> N;
	std::cin >> origin;
	std::unordered_map<char,int> origin_map = makeMap(origin);
	std::unordered_set<char> chars;
	for(const char& c : origin)
		chars.insert(c);

	for(int i = 1; i < N; i++){
		std::cin >> check;
		if(checkSimilar(chars,origin_map,makeMap(check)))
			ans++;
	}

	std::cout << ans << std::endl;

	return 0;
}
