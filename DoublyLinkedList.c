#include"doublyLinkedList.h"

Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;
	NewNode->PrevNode = NULL;

	return NewNode;
}
void  DLL_DestroyNode(Node* Node) //��� free
{
	free(Node);
}
void  DLL_AppendNode(Node** Head, Node* NewNode) 
{											
	if (*Head == NULL)
		*Head = NewNode;
	else//��尡 �̹� �ִٸ�
	{
		Node* Tail = (*Head); //tail��带 �ʱ�ȭ
		while (Tail->NextNode != NULL)
			Tail = Tail->NextNode; //tail��带 ������ ���� �����,
		
		Tail->NextNode = NewNode; //���ο� ��带 �������� �߰�
		NewNode->PrevNode = Tail;
		//(NextNode�� ������ �Լ����� �̹� NULL�� �ʱ�ȭ �Ǿ��ֱ⿡ ���ص���.)
	}
}
void  DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL) //������ ��ġ �ڿ� ��尡 �־��ٸ�
	{
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}
void  DLL_RemoveNode(Node** Head, Node* Remove) 
{
	if (*Head == Remove) //������ ��尡 ��� �����  Head<->a<->b
	{
		*Head = Remove->NextNode; //���� ��带 ��� ���� �Ѵ�. a<->a<->b
		if (*Head != NULL)//���� ��尡 �ִٸ�
			(*Head)->PrevNode = NULL;// �� ��尡 ����Ű�� ���� ��带 �����. //a->a-<->b
		
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL; //a<->b
	}
	else
	{
		Node* temp = Remove; //���� �ؾ��ϴ� ��带 temp�� �����س��´�.
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

//void PrintReverse(Node* Head) //���� 1-3
//{
//	Node* Current = Head;
//	int count = 0;
//
//	while (Current!= NULL)
//	{
//		Current = Current->NextNode;
//		count++;
//	}
//	printf("�������� ��ũ�� ����Ʈ�� ����մϴ�.\n");
//	while (Current!= NULL&&count>=0)
//	{	
//		
//		printf("List[%d]: %d",count--,Current->Data);
//		Current = Current->PrevNode;
//	}
//}

void PrintReverse(Node* Head) {
	if (Head != NULL) {
		PrintReverse(Head->NextNode); //�Լ��� ȣ���ϸ鼭 ���ÿ� ���� ����ؼ� ���̰Ե�.
		printf("%d " ,Head->Data); //���� ������ �Է��� ������ �ݴ�� printf()�� ���ƿ�.
	}
}