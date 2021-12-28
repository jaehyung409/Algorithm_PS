#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int convertToMin(const string time){
	int minute{0};
	minute = (time[0] - '0')*600 + (time[1] - '0')*60 + (time[3] - '0')*10 + time[4] - '0';
	return minute;
}

string convertToTime(const int minute){
	string time;
	if(minute/60 < 10)
		time += '0';
	time += to_string(minute/60);
	time += ':';
	if(minute%60 < 10)
		time += '0';
	time += to_string(minute%60);	
	return time;
}

int winning(unordered_map<int,int> &team_score){
	if(team_score[1] > team_score[2])
		return 1;
	else if(team_score[1] < team_score[2])
		return 2;
	else
		return 0;
}

int main(){
	
	int N,team,temp{-1};
	cin >> N;

	unordered_map<int,int>team_score;
	team_score[1] = team_score[2] = 0;
	
	unordered_map<int,int>team_wintime;
	team_wintime[1] = team_wintime[2] = 0;
	string time;
	
	for(int i = 0; i < N; i++){
		cin >> team >> time;
		if(temp == -1)
			temp = convertToMin(time);
		else{
			team_wintime[winning(team_score)] += convertToMin(time) - temp;
			temp = convertToMin(time);
		}
		team_score[team]++;
	}
	team_wintime[winning(team_score)] += 48 * 60 - temp;

	cout << convertToTime(team_wintime[1]) << '\n';
	cout << convertToTime(team_wintime[2]) << endl;

	return 0;
}
