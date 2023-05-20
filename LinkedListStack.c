#include"LinkedListStack.h"

void  LLS_CreateStack(LinkedListStack** Stack)
{
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));//��������ҿ� ���� ����
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}
void  LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack))
	{
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}
	free(Stack);
}

Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->Data, NewData);
}
void  LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void  LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)//������ ù �ּҰ� ����Ű�� ���� ���ٸ�
		Stack->List = NewNode;
	else
		Stack->Top->NextNode = NewNode; //���� �ֻ��� ��尡 NewNode�� ����Ű����

	Stack->Top = NewNode; //NewNode�� �ּҰ� �ֻ��� ����� �ּ��̰� ��.
}
Node* LLS_Pop(LinkedListStack* Stack)
{
	Node* TopNode = Stack->Top;		//1. �ֻ��� ����� �ּ� ����

	if (Stack->List == Stack->Top) //��尡 1������ ���
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{								//2. �ֻ��� ��� �ٷ� ���� ��带 ã�´�.
		Node* CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
		{//CurrentTop�� �ֻ��� ��� ���� ��带 ����ų������
			CurrentTop = CurrentTop->NextNode;
		}
									//3. ���ο� �ֻ��� ����� �ּҸ� ����Ѵ�.
		Stack->Top = CurrentTop;	//����!! ���� ��带 ����Ű�� �ּҸ� �ֻ�����带 ����Ű�� '�ּ�'�� ����
		Stack->Top->NextNode = NULL;
	}
	return TopNode;					//4. 1�ܰ迡�� �����س��� �ֻ��� ��忴�� ����� �ּҸ� return
}

Node* LLS_Top(LinkedListStack* Stack)
{
	return Stack->Top;
}
int   LLS_GetSize(LinkedListStack* Stack)
{
	int Count = 0;
	Node* Current = Stack->List;

	while (Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}
int   LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}