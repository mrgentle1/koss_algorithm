# 1주차 - 이분탐색
탐색기법 중 하나로 탐색 범위를 두 부분으로 분할해서 탐색하는 방식. 따라서 시간복잡도는 ```O(lgN)```가 걸린다.

- 이분탐색 정리
1. 먼저 이분탐색 하려고 하는 리스트를 정렬한다.
2. low, high값은 탐색 범위의 최소, 최대값으로 설정한다.
3. mid = (low+high)/2
4. mid 값과 구하고자 하는 값을 비교한다.
5. 비교시 mid 값보다 구하고자 하는 값이 높으면 low를 mid+1로, 낮으면 high를 mid-1로 만들어준다.
6. while(left <= right)일 때 이 과정을 반복해서 값을 구한다.

- 예제 코드
```cpp
#include <stdio.h>
int main(void){
 
    int findN;
    int result = 0;
    //처음int는 다음 정점 마지막 int 값어치
 
    int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15 };
 
    scanf("%d", &findN);
    int left = 0, right =  9;
 
 
    while (left <= right){
 
        int mid = (left + right) / 2;
        if (A[mid] > findN)
            right = mid - 1;
        else if (A[mid] < findN)
            left = mid + 1;
        else
        {
            result = mid;
            break;
        }
 
    }
 
    printf("%d\n", result);
 
    return 0;
}
```
예제코드 출처: https://wootool.tistory.com/62
