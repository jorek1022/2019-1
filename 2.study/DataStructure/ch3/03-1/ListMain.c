#include <stdio.h>
#include "ArrayList.c"

int main(void)
{

    //리스트 생성 및 초기화
    List list;
    int i;
    int data;
    int sum=0;
    ListInit(&list);

    //정수 1부터 9까지 리스트에 저장
    for(i=0; i<10; i++)
    {
        LInsert(&list, i);
    }
        
    //리스트에 저장된 값을 순차적으로 참조하여 그 합을 계산
    if(LFirst(&list, &data))
    {
        sum += data;

        while(LNext(&list, &data))
        {
            sum += data;
        }
    }
    
    //출력
    printf("sum : %d \n\n", sum);

    //2의 배수와 3의 배수 삭제하기
    if(LFirst(&list, &data))
    {
        if(data%2 == 0 || data%3 ==0)
            LRemove(&list);
        
        while(LNext(&list, &data))
        {
            if(data%2 ==0 || data%3 == 0)
                LRemove(&list);
        }
    }

    //마지막으로 리스트에 저장된 데이터를 순서대로 출력한다.
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
    }


    return 0;
}