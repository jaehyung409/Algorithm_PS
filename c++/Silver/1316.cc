#include <iostream>
#include <string>
#include <set>
using namespace std;

bool wordChecker(string& word){
	set<char> check;
	char temp = word[0];
	check.insert(temp);
	for(int i = 0; i < word.size(); i++){
		if(temp == word[i])
			continue;
		auto search = check.find(word[i]);
		if(search != check.end())
			return false;
		else{
			check.insert(word[i]); 
			temp = word[i];
		}
	}
	return true;
}

int main(){
	
	int Case,ans{0};
	string word;
	cin >> Case;

	for(int i = 0; i < Case; i++){
		cin >> word;
		if(wordChecker(word))
			ans++;
	}

	cout << ans << endl;

	return 0;
}
