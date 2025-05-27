#include <iostream>
using namespace std;

int sumArray(int* ptr,int count) {
    int res = 0;
    for (int i = 0; i < count; i++) {
        res += ptr[i];
    }
    return res;
}

double avgArray(int* ptr, int count) {
    double res = 0.0;
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += ptr[i];
    }
    res = (double)sum / count;
    return res;
}

int main()
{
    int n = 5; // 입력 받은 숫자 개수
    int num[5];

    cout << "숫자 5개를 입력해주세요" << endl;
    for (int i = 0; i < n; i++) {
        cout << i+1 << "번째 숫자: ";
        cin >> num[i];
    }

    int sum = 0;
    double avg = 0.0;

    for (int i = 0; i < n; i++) {
        sum += num[i];
    }
    avg = (double)sum / n;

    cout << "5개 숫자의 합계는 " << sum << " 평균은 " << avg << "입니다." << endl;

    int fsum = sumArray(num, n);
    double favg = avgArray(num, n);

    cout << "함수로 구한 5개 숫자의 합계는 " << fsum << " 평균은 "<< favg << "입니다." << endl;

    return 0;
}

