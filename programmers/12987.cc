#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    const int size = A.size();
    for (int i = 0, j = 0; i < size && j < size;) {
        if (A[i] >= B[j]) ++j;
        else {
            ++answer;
            ++i; ++j;
        }
    }
    return answer;
}