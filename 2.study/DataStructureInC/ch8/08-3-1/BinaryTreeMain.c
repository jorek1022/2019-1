#include <stdio.h>
#include "BinaryTree.h"

void InorderTraversal(BTreeNode *bt)        // 중위 순회 함수
{
    if(bt == NULL)                          // 비어있다면 탈출!!   
        return;

    InorderTraversal(bt->left);
    printf("%d \n", bt->data);
    InorderTraversal(bt->right);
}

void PreorderTraversal(BTreeNode *bt)       // 전위 순회 함수
{
    if(bt == NULL)
        return;
    
    printf("%d \n", bt->data);
    PreorderTraversal(bt->left);
    PreorderTraversal(bt->right);
}


void PostorderTraveral(BTreeNode *bt)       // 후위 순회 함수
{
    if(bt == NULL)
        return;
    PostorderTraveral(bt->left);
    PostorderTraveral(bt->right);
    printf("%d \n", bt->data);
}

int main(void)
{
    BTreeNode *bt1 = MakeBTreeNode();       // 노드 bt1 생성
    BTreeNode *bt2 = MakeBTreeNode();       // 노드 bt2 생성
    BTreeNode *bt3 = MakeBTreeNode();       // 노드 bt3 생성
    BTreeNode *bt4 = MakeBTreeNode();       // 노드 bt4 생성

    SetData(bt1, 1);        // bt1애 1 저장
    SetData(bt2, 2);        // bt2애 2 저장
    SetData(bt3, 3);        // bt3애 3 저장
    SetData(bt4, 4);        // bt4애 4 저장

    MakeLeftSubTree(bt1, bt2);          // bt2를 bt1의 왼쪽 자식 노드로
    MakeRightSubTree(bt1, bt3);         // bt3를 bt1의 오른쪽 자식 노드로
    MakeLeftSubTree(bt2, bt4);          // bt4를 bt2의 왼쪽 자식 노드로


    // bt1의 왼쪽 자식 노드의 데이터 출력
  //  printf("%d \n", GetData(GetLeftSubTree(bt1)));

    // bt1의 왼쪽 자식 노드의 왼쪽 자식 노드의 데이터 출력
  //  printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

    InorderTraversal(bt1);
    return 0;
}