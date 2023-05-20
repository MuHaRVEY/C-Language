#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode
{
    char* Data;
    struct tagNode* NextNode;   //연결리스트 : 다음 노드를 가르킬 포인터
} Node;

typedef struct tagLinkedListStack
{
    Node* List; //리스트 시작 주소
    Node* Top;  //최상위 노드 주소
} LinkedListStack;

void  LLS_CreateStack(LinkedListStack** Stack);
void  LLS_DestroyStack(LinkedListStack* Stack);

Node* LLS_CreateNode(char* NewData);
void  LLS_DestroyNode(Node* _Node);

void  LLS_Push(LinkedListStack* Stack, Node* NewNode);
Node* LLS_Pop(LinkedListStack* Stack);

Node* LLS_Top(LinkedListStack* Stack);
int   LLS_GetSize(LinkedListStack* Stack);
int   LLS_IsEmpty(LinkedListStack* Stack);