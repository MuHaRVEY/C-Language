#include"doublyLinkedList.h"

int main()
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	for (i = 0; i < 5; i++)
	{
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	printf("\n\"Inserting 3000 after[2]...\"\n");
	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(3000);
	DLL_InsertAfter(Current, NewNode);

	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	/*printf("\nDestroying List...\n");
	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		if (Current != NULL)
		{
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}*/


	//ДыБо 1-3
	
	PrintReverse(List);
	return 0;
}