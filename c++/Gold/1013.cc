#include <iostream>
#include <string>

bool check(const std::string& str){
	bool first_check{true},second_check{false},
		 check_10{false},check_0{false},
		 loop_0{false},loop_1{false},check_01{false};
	int check_one = 0;
	for(char n : str){
		if(first_check){
			if(n == '1')
				check_10 = true;
			else
				check_01 = true;
			first_check = false;
			continue;
		}
		if(check_10){
			if(n == '0')
				check_0 = true;
			else
				return false;
			check_10 = false;
			continue;
		}
		if(check_0){
			if(n != '0')
				return false;
			check_0 = false;
			loop_0 = true;
			continue;
		}
		if(loop_0){
			if(n == '0')
				continue;
			loop_1 = true;
			loop_0 = false;
			continue;
		}
		if(loop_1){
			if(n == '1'){
				check_one++;
				continue;
			}
			loop_1 = false;
			second_check = true;
			continue;
		}
		if(second_check){
			if(n == '1')
				first_check = true;
			else{
				if(check_one > 0){	
					loop_0 = true;
				}
				else
					return false;
			}
			check_one = 0;
			second_check = false;
			continue;
		}
		if(check_01){
			if(n == '1')
				first_check = true;
			else
				return false;
			check_01 = false;
			continue;
		}
	}
	if(second_check || check_10 || check_0 || loop_0 || check_01)
		return false;
	return true;
}

int main(){

	int T;
	std::cin >> T;
	std::string radio_wave;

	for(int i = 0; i < T; i++){
		std::cin >> radio_wave;
		if(check(radio_wave))
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
	
	return 0;

}
