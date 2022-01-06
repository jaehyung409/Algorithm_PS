#include <iostream>
#include <map>

template <int num>
class Fibonacci {
	public:
		const static int result = Fibonacci<num - 1>::result + Fibonacci<num - 2>::result;

};

template <>
class Fibonacci<0>{
	public:
		const static int result = 0;
};

template <>
class Fibonacci<1>{
	public:
		const static int result = 1;
};

int main(){
	std::map <int,int> fibonacci;
	fibonacci[1] = Fibonacci<1>::result;
	fibonacci[2] = Fibonacci<2>::result;
	fibonacci[3] = Fibonacci<3>::result;
	fibonacci[4] = Fibonacci<4>::result;
	fibonacci[5] = Fibonacci<5>::result;
	fibonacci[6] = Fibonacci<6>::result;
	fibonacci[7] = Fibonacci<7>::result;
	fibonacci[8] = Fibonacci<8>::result;
	fibonacci[9] = Fibonacci<9>::result;
	fibonacci[10] = Fibonacci<10>::result;
	fibonacci[11] = Fibonacci<11>::result;
	fibonacci[12] = Fibonacci<12>::result;
	fibonacci[13] = Fibonacci<13>::result;
	fibonacci[14] = Fibonacci<14>::result;
	fibonacci[15] = Fibonacci<15>::result;
	fibonacci[16] = Fibonacci<16>::result;
	fibonacci[17] = Fibonacci<17>::result;
	fibonacci[18] = Fibonacci<18>::result;
	fibonacci[19] = Fibonacci<19>::result;
	fibonacci[20] = Fibonacci<20>::result;

	int n;
	std::cin >> n;
	std::cout << fibonacci[n] << std::endl;

	return 0;

}
