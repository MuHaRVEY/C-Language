#include"LinkedListStack.h"

void  LLS_CreateStack(LinkedListStack** Stack)
{
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));//자유저장소에 스택 생성
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
	if (Stack->List == NULL)//스택의 첫 주소가 가리키는 것이 없다면
		Stack->List = NewNode;
	else
		Stack->Top->NextNode = NewNode; //현재 최상위 노드가 NewNode를 가리키게함

	Stack->Top = NewNode; //NewNode의 주소가 최상위 노드의 주소이게 함.
}
Node* LLS_Pop(LinkedListStack* Stack)
{
	Node* TopNode = Stack->Top;		//1. 최상위 노드의 주소 복사

	if (Stack->List == Stack->Top) //노드가 1개뿐일 경우
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{								//2. 최상위 노드 바로 이전 노드를 찾는다.
		Node* CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
		{//CurrentTop이 최상위 노드 이전 노드를 가리킬때까지
			CurrentTop = CurrentTop->NextNode;
		}
									//3. 새로운 최상위 노드의 주소를 등록한다.
		Stack->Top = CurrentTop;	//주의!! 이전 노드를 가리키는 주소를 최상위노드를 가리키는 '주소'로 지정
		Stack->Top->NextNode = NULL;
	}
	return TopNode;					//4. 1단계에서 복사해놓은 최상위 노드였던 노드의 주소를 return
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