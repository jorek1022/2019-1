#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    srand(time(NULL));

    //int checkSum=0; //

    int a = 1;  // 1부터
    int b = 45; // 45까지
    int randTemp;

    int cycle=10000000;

    int arr[46] = {0, };
    int i=0;

    while(!(cycle <= 0))
    {
        randTemp = rand()%(b+1-a) + a;   // 1부터 45까지의 숫자 랜덤 생성;
        arr[randTemp] += 1;

        cycle--;
    }

    for(i=1; i<46; i++)
        printf("%d : %d\n", i, arr[i]);
    

    /*
    for(i=1; i<46; i++)
    {
        checkSum += arr[i];
    }

    printf("\n\nAll Sum : %d\n", checkSum);
    */


    int lotto[8]={0,};
    int comp;
    
    for(i=1; i<46; i++)
    {
        comp = arr[i];
        if()
    }

    return 0;
}