#include"doublyLinkedList.h"

Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;
	NewNode->PrevNode = NULL;

	return NewNode;
}
void  DLL_DestroyNode(Node* Node) //노드 free
{
	free(Node);
}
void  DLL_AppendNode(Node** Head, Node* NewNode) 
{											
	if (*Head == NULL)
		*Head = NewNode;
	else//헤드가 이미 있다면
	{
		Node* Tail = (*Head); //tail노드를 초기화
		while (Tail->NextNode != NULL)
			Tail = Tail->NextNode; //tail노드를 마지막 노드로 만든뒤,
		
		Tail->NextNode = NewNode; //새로운 노드를 마지막에 추가
		NewNode->PrevNode = Tail;
		//(NextNode는 노드생성 함수에서 이미 NULL로 초기화 되어있기에 안해도됨.)
	}
}
void  DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL) //삽입할 위치 뒤에 노드가 있었다면
	{
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}
void  DLL_RemoveNode(Node** Head, Node* Remove) 
{
	if (*Head == Remove) //삭제할 노드가 헤드 노드라면  Head<->a<->b
	{
		*Head = Remove->NextNode; //다음 노드를 헤드 노드로 한다. a<->a<->b
		if (*Head != NULL)//다음 노드가 있다면
			(*Head)->PrevNode = NULL;// 그 노드가 가리키는 앞쪽 노드를 지운다. //a->a-<->b
		
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL; //a<->b
	}
	else
	{
		Node* temp = Remove; //삭제 해야하는 노드를 temp에 저장해놓는다.
		if (Remove->PrevNode != NULL)
			Remove->PrevNode->NextNode = temp->NextNode;
		if (Remove->NextNode != NULL)
			Remove->NextNode->PrevNode = temp->PrevNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}
Node* DLL_GetNodeAt(Node* Head, int Location) 
{
	Node* Current = Head;
	
	while (Current != NULL && (--Location) >= 0)
		Current = Current->NextNode;

	return Current;
}
int   DLL_GetNodeCount(Node* Head) 
{
	int count = 0;
	Node* Current = Head;

	while (Current!=NULL)
	{
		Current = Current->NextNode;
		count++;
	}
	return count;
}

void PrintNode(Node* _Node)
{
	if (_Node->PrevNode == NULL)
		printf("Prev:NULL");
	else
		printf("Prev: %d", _Node->PrevNode->Data);
		
	printf("Current: %d", _Node->Data);

	if (_Node->NextNode == NULL)
		printf("Next: NULL\n");
	else
		printf("Next: %d\n", _Node->NextNode->Data);
}

//void PrintReverse(Node* Head) //퀴즈 1-3
//{
//	Node* Current = Head;
//	int count = 0;
//
//	while (Current!= NULL)
//	{
//		Current = Current->NextNode;
//		count++;
//	}
//	printf("역순으로 링크드 리스트를 출력합니다.\n");
//	while (Current!= NULL&&count>=0)
//	{	
//		
//		printf("List[%d]: %d",count--,Current->Data);
//		Current = Current->PrevNode;
//	}
//}

void PrintReverse(Node* Head) {
	if (Head != NULL) {
		PrintReverse(Head->NextNode); //함수를 호출하면서 스택에 값이 계속해서 쌓이게됨.
		printf("%d " ,Head->Data); //쌓인 값들이 입력한 순서의 반대로 printf()로 돌아옴.
	}
}