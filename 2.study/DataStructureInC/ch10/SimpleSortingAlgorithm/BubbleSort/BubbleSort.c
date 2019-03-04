/* 2019 02 25 Mon
    이로제 
    자료구조 정렬 중 
    단순 덩렬방법의 하나인 "버블정렬"
*/

#include <stdio.h>

void BubbleSort(int arr[], int n)
{
    int i, j;
    int temp;

    for(i=0; i<n; i++)
    {
        for(j=0; j<(n-1); j++)
        {
            ////// 자리 바꾸기 ///////
            if(arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main(void)
{
    int arr[4] = {3, 2, 4, 1};
    int i;

    BubbleSort(arr, sizeof(arr)/sizeof(int));

    for(i=0; i<4; i++)
        printf("%d ", arr[i]);

    return 0;
}