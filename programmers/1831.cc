//
// Created by jaehy on 25. 8. 5.
//

struct data{
public:
    int score = 0;
    int stars = 0;
    int pluses = 0;
    void push(int a, int b, int c) {
        score = a;
        stars = b;
        pluses = c;
    }
};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
// maximum remain -> 57
int solution(int n) {
    int answer = 0;
    data a[1000000];
    int idx = 0;
    int capacity = 1;
    int stars = -1;
    int nn = n;
    while (nn > 0) {
        nn /= 3;
        ++stars;
    }
    const int pluses = stars * 2;
    a[0].push(n, 0, 0);
    while (idx != capacity) {
        const int current_pluses = a[idx].pluses;
        const int next_stars = a[idx].stars + 1;
        const int current_score = a[idx].score;
        if (current_score == 1) {
            ++idx;
            ++answer;
            continue;
        }
        int plus_capacity = pluses - current_pluses;
        const int require_pluses = next_stars * 2;
        for (int i = current_score % 3; i <= plus_capacity; i += 3) {
            if (require_pluses > current_pluses + i) continue;
            a[capacity++].push((current_score - i) / 3, next_stars, current_pluses + i);
        }
        ++idx;
    }
    return answer;
}