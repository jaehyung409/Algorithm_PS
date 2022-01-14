#include <iostream>
#include <array>

template<int num>
class Factorial{
public:
	const static long long result = num * Factorial<num-1>::result;
};

template <>
class Factorial<0>{
public:
	const static long long result = 1;
};

int main(){
	std::array<long long,21> arr = {Factorial<0>::result,Factorial<1>::result,Factorial<2>::result,
								 	Factorial<3>::result,Factorial<4>::result,Factorial<5>::result,
									Factorial<6>::result,Factorial<7>::result,Factorial<8>::result,
									Factorial<9>::result,Factorial<10>::result,Factorial<11>::result,
									Factorial<12>::result,Factorial<13>::result,Factorial<14>::result,
									Factorial<15>::result,Factorial<16>::result,Factorial<17>::result,
									Factorial<18>::result,Factorial<19>::result,Factorial<20>::result};

	long long N;
	std::cin >> N;
	if(N != 0){
		for(auto it = arr.rbegin(); it != arr.rend(); ++it){
			if(*it <= N)
				N -= *it;
			if(N == 0){
				std::cout << "YES" << std::endl;
				exit(0);
			}
		}
	}
	std::cout << "NO" << std::endl;
	
	return 0;
	
}
