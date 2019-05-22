/* 20190223
    이로제
*/

#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.c"

int DataPriorityComp(char *str1, char *str2)
{
    return strlen(str2)-strlen(str1);
}

int main(void)
{
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);

    PEnqueue(&pq, "Good Morning");
    PEnqueue(&pq, "Curiouser and Curiouse");
    PEnqueue(&pq, "Was it a Cat I saw?");
    PEnqueue(&pq, "Whatis reality and what is a dream?");
    PEnqueue(&pq, "All the best people are mad");

    while(!PQIsEmpty(&pq))
    {
        printf("%s \n", PDequeue(&pq));
    }

    
    return 0;
}