#include <iostream>
using namespace std;

void convert(int (&arr)[9],int i,int j,int k,int& a){
	if (k ==0){
		int	x = arr[3*i+j] + arr[3*i+(j+1)%3] + arr[3*i+(j+2)%3];
		int y = arr[3*i+j] + arr[3*((i+1)%3)+j] + arr[3*((i+2)%3)+j];
		if (x > a)
			a = x;
		if (y > a)
			a = y;
	}
	
	else if(arr[3*i+j] == 0){
		int b,c,bb,cc;
		b = arr[3*((i+1)%3)+j] + arr[3*((i+2)%3)+j];
		bb = arr[3*((i+1)%3)+j] && arr[3*((i+2)%3)+j];
		c = arr[3*i+(j+1)%3] + arr[3*i+(j+2)%3];
		cc = arr[3*i+(j+1)%3] && arr[3*i+(j+2)%3];
		if (bb == 0 && cc != 0)
			arr[3*i+j] = a - c;
		else if (bb != 0 && cc == 0)
			arr[3*i+j] = a - b;
		else if(bb != 0 && cc != 0){
			if ( b > c)
				arr[3*i+j] = a - b;
			else
				arr[3*i+j] = a - c;
		}
	}

}

int main(){
	
	int arr[9];
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
			cin >> arr[3*i+j];
	}

	int o = arr[0] + arr[4] + arr[8];
	int l = arr[2] + arr[4] + arr[6];
	if ( l > o ){
		int temp = o;
		o = l;
		l = temp;
	}
	int &a = o;

	if (l == 0){
		int a,b,c,all;
		if (arr[0] == 0){
			a = arr[1] + arr[2];
			b = arr[3] + arr[5];
			c = arr[6] + arr[7];
			all = (a+b+c)/2;
			arr[0] = all - a;
			arr[4] = all - b;
			arr[8] = all - c;
		}
		
		else{
			a = arr[0] + arr[1];
			b = arr[3] + arr[5];
			c = arr[7] + arr[8];
			all = (a+b+c)/2;
			arr[2] = all - a;
			arr[4] = all - b;
			arr[6] = all - c;
		}

	}
	
	else{
		for (int k = 0; k < 3; k++){
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++)
					convert(arr,i,j,k,a);
			}
		}
	}

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
			cout << arr[3*i+j]<< ' ';
		cout << endl;
	}

	return 0;

}
