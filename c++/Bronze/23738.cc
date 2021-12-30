#include <iostream>
#include <string>
#include <unordered_map>

int main(){
	std::unordered_map<char,std::string> translate;
	translate['A'] = 'a';
	translate['K'] = 'k';
	translate['M'] = 'm';
	translate['O'] = 'o';
	translate['T'] = 't';
	translate['B'] = 'v';
	translate['E'] = "ye";
	translate['H'] = 'n';
	translate['P'] = 'r';
	translate['C'] = 's';
	translate['Y'] = 'u';
	translate['X'] = 'h';
	
	std::string word,ans;
	std::cin >> word;

	for(char i : word){
		ans += translate[i];
	}
	
	std::cout << ans << std::endl;

	return 0;

}
