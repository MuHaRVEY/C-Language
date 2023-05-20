#include"LinkedListStack.h"

int main()
{
	int Count = 0;
	Node* Popped;
	
	LinkedListStack* Stack;
	LLS_CreateStack(&Stack);

	LLS_Push(Stack, LLS_CreateNode("abc"));
	LLS_Push(Stack, LLS_CreateNode("def"));
	LLS_Push(Stack, LLS_CreateNode("ghi"));
	LLS_Push(Stack, LLS_CreateNode("jkl"));

	Count = LLS_GetSize(Stack);
	printf("Size : %d, Top : %s\n\n",
		Count, LLS_Top(Stack)->Data);

	for (int i = 0; i < Count; i++)
	{
		if (LLS_IsEmpty(Stack))
			break;
		Popped = LLS_Pop(Stack);

	}
	return 0;
}