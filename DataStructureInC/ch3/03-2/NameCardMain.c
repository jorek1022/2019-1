#include <stdio.h>
#include <stdlib.h>
#include "NameCard.c"
#include "ArrayList.c"

int main(void)
{
    List list;
    NameCard *pcard;

    ListInit(&list);

    // 총 3명의 전화번호 정보를 리스트에 저장
    pcard = MakeNameCard("이로제", "205016");
    LInsert(&list, pcard);

    pcard = MakeNameCard("최우진","051620");
    LInsert(&list, pcard);

    pcard = MakeNameCard("사랑해", "160520");
    LInsert(&list, pcard);

    pcard = MakeNameCard("바이러스", "베베베베");
    LInsert(&list, pcard);

    printf("수정 전의 정보 수 : %d \n", LCount(&list));

    if(LFirst(&list, &pcard))
    {
        ShowNameCardInfo(pcard);

        while(LNext(&list, &pcard))
            ShowNameCardInfo(pcard);
    }

    printf("\n\n");
    
    //특정이름을 대상으로 탐색진행, 그 사람의 정보 출력
    if(LFirst(&list, &pcard))
    {
        if(!NameCompare(pcard, "이로제"))
            ShowNameCardInfo(pcard);
        
        while(LNext(&list, &pcard))
        {
            if(!NameCompare(pcard, "이로제"))
            {
                ShowNameCardInfo(pcard);
                break;
            }
        }
    }
    printf("\n\n");

    //특정이름을 대상으로 탐색하여, 그 사람의 전화번호를 변경한다
    if(LFirst(&list, &pcard))
    {
        if(!NameCompare(pcard, "최우진"))
            ChangePhoneNum(pcard, "160520");
        
        while(LNext(&list, &pcard))
        {
            if(!NameCompare(pcard, "최우진"))
            {
                ChangePhoneNum(pcard, "160520");
                break;
            }
        }
    }


    //특정이름을 대상으로 탐색하여, 그 사람의 정보를 삭제한다
    if(LFirst(&list, &pcard))
    {
        if(!NameCompare(pcard, "바이러스"))
        {
            pcard = LRemove(&list);
            free(pcard);
        }
            
        while(LNext(&list, &pcard))
        {
            if(!NameCompare(pcard, "바이러스"))
            {
                pcard = LRemove(&list);
                free(pcard);
                break;
            }
        }
    }

    //남아 있는 모든 사람의 전화번호 정보를 출력한다
    printf("수정 후 남아 있는 정보 수 : %d \n", LCount(&list));

    if(LFirst(&list, &pcard))
    {
        ShowNameCardInfo(pcard);

        while(LNext(&list, &pcard))
            ShowNameCardInfo(pcard);
    }
    

    return 0;
}