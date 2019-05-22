/* 2019 02 25 Mon
    이로제
    자료구조 단순정렬 중 "선택 정렬"
*/

#include <stdio.h>

void SelectionSort(int arr[], int n)
{
    int i, j;
    int maxIdx;
    int temp;

    for(i=0; i<n-1; i++)
    {
        maxIdx = i;

        //// 최솟값을 탐색 /////////
        for(j=i+1; j<n; j++)
        {
            if(arr[j] < arr[maxIdx])
                maxIdx = j;
        }
        //// 값 교환    ///////////
        temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

int main(void)
{
    int arr[4] = {3, 4, 2, 1};
    int i;

    SelectionSort(arr, sizeof(arr)/sizeof(int));

    for(i=0; i<4; i++)
        printf("%d ", arr[i]);

    return 0;
}