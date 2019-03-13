#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _lotto
{
    int idx;
    double data;
} Lotto;

void LottoInit(Lotto *parr)
{
    for(int i=0; i<46; i++)
    {
        parr[i].idx = i;
        parr[i].data = 0;
    }
}

int main(void)
{
    srand(time(NULL));

    int randTemp;
    int a = 1;
    int b = 45;
    int cycle = 100000000;
    int i,j=0;

    Lotto temp;
    Lotto arr[46]={0,};
    LottoInit(arr);

    // 랜덤으로 숫자 뽑기
    while(!cycle <= 0)
    {
        randTemp = rand()%(b+1-a) + a;
        arr[randTemp].data += 1;
        cycle--;
    }

    // 비교하기
    for(i=1; i<46; i++)
    {
        for(j=1; j<45; j++)
        {
            if(arr[j].data < arr[j+1].data)
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // 출력하기
    /*
    for(i=1; i<46; i++)
        printf("%d : %d\n",arr[i].idx, arr[i].data);
    */

   for(i=1; i<=6; i++)
   {
       //printf("%d : %0.7lf\n", arr[i].idx, arr[i].data/1000000);
       printf("%d ",arr[i].idx);
   }




    return 0;
}