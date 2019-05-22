/*
    2019 02 25 Mon
    이로제
    자료구조 복잡하지만 효율적인 정렬 중
    "힙 정렬"
*/

#include <stdio.h>
#include "UsefulHeap.c"


int PriComp(int n1, int n2)
{
    return n2-n1;   // 오름차순을 위한 문장

    //return n1-n2;
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
    Heap heap;
    int i;

    HeapInit(&heap, pc);

    // 정렬 대상을 가지고 힙을 구성한다.
    for(i=0; i<n; i++)
        HInsert(&heap, arr[i]);
    
    // 순서대로 하나씩 꺼내서 정렬을 완성한다.
    for(i=0; i<n; i++)
        arr[i] = HDelete(&heap);
}

int main(void)
{
    int arr[7] = {6, 7, 2, 4, 5, 1, 3};
    int i;

    HeapSort(arr, sizeof(arr)/sizeof(int), PriComp);

    for(i=0; i<7; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    
    return 0;
}
