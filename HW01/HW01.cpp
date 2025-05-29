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

void ascOrder(int* ptr,int count) { //삽입 정렬

    for (int i = 1; i < count; i++) {
        int j = i;
        while (j > 0 && ptr[j] < ptr[j - 1]) { //현재 위치의 값보다 왼쪽에 있는 값이 더 클 시 수행
            int temp = ptr[j]; //교체
            ptr[j] = ptr[j - 1];
            ptr[j - 1] = temp; 
            j--; //현재 위치 값을 왼쪽으로 한 칸 이동
        }
    }
    cout << "오름차순의 결과: ";
    for (int i = 0; i < count; i++) {
        cout << ptr[i] << " ";
    }
}

void quickSort(int* ptr, int start, int end) {  //퀵 정렬
    if (start >= end) {   //start가 end와 같다는 것은 배열 원소가 1개라는 의미로 바로 반환
        return; 
    }

    int pivot = start;  //기준 값
    int i = start + 1;
    int j = end;
    int temp;
    
    while (i <= j) { // 엇갈리기 전까지 반복
        while (ptr[pivot] <= ptr[i] && i<=end) {   //기준값보다 작은 값이 나올때까지 왼 -> 오 
            i++;
        }
        while (ptr[pivot] >= ptr[j] && j>start) {  //기준값보다 큰 값이 나올때까지 오 -> 왼
            j--;
        }
        if (i > j) {  //엇갈릴 시 기준값과 큰값 교체 
            temp = ptr[pivot];
            ptr[pivot] = ptr[j];
            ptr[j] = temp;
        }
        else {      //아닐 시 작은 값 큰 값 서로 교체 
            temp = ptr[i];
            ptr[i] = ptr[j];
            ptr[j] = temp;
        }
    }
    //기준값의 위치가 정해진 후 다시 다른 값을 기준값으로 정하는 과정
    quickSort(ptr, start, j - 1);  //기존의 기준값보다 왼쪽에 있는 값들(큰 값) 정렬
    quickSort(ptr, j + 1, end); //기존의 기준값보다 오른쪽에 있는 값들(작은 값) 정렬
}

void descOrder(int* ptr, int count) {
    quickSort(ptr, 0, count - 1);

    cout << "내림차순의 결과: ";
    for (int i = 0; i < count; i++) {
        cout << ptr[i] << " ";
    }
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
    
    int choiceSort = 0;
    cout << "정렬 방식을 선택해주세요. 1. 오름차순 2. 내림차순" << endl;
    cin >> choiceSort;

    if (choiceSort == 1) {
        ascOrder(num, n);
    }
    else if (choiceSort == 2) {
        descOrder(num, n);
    }
    else {
        cout << "잘못 입력하셨습니다. 다시 시도해주세요." << endl;
    }

    return 0;
}

