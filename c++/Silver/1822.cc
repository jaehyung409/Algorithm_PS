#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void SetInsert (set<int>& S,int InsertSize){
	
	int temp;

	for(int i = 0; i < InsertSize; i ++){
		cin >> temp;
		S.insert(temp);
	}
}

int main() {
	
	set<int> A,B,diff;
	int Acount, Bcount;
	int temp;
	
	cin >>  Acount >> Bcount ;

	SetInsert(A,Acount);
	SetInsert(B,Bcount);

	set_difference(A.begin(), A.end(), B.begin(), B.end(),inserter(diff,diff.begin()));
	
	cout << diff.size() << endl;

	for_each(diff.begin(), diff.end(), [](int x){
			cout << x << ' ';
	});

	cout << endl;

	return 0;

}
