#include <stdio.h>
#include <stdlib.h>


///////////////////////////////////////////////////////////////////////////////
// TYPES
///////////////////////////////////////////////////////////////////////////////
typedef struct node_ll
{
	int data;
	struct node_ll* next;
} node;



///////////////////////////////////////////////////////////////////////////////
// HEADERS
///////////////////////////////////////////////////////////////////////////////

// TESTS
void test_linkedList();
void test_createLinkedList();

// FUNCTIONS
void linkedListAdd(node** head, int val);
void deleteLinkedList(node** head);
void printLinkedList(node* head);
void createLinkedList(int vet[], int nvals, node** head);

///////////////////////////////////////////////////////////////////////////////
// MAIN
///////////////////////////////////////////////////////////////////////////////
int main()
{
	int test01 = 1;
	int test02 = 1;
	int test03 = 0;
	int test04 = 0;
	int test05 = 0;
	int test06 = 0;
	int test07 = 0;
	int test08 = 0;
	int test09 = 0;
	int test10 = 0;
	int test11 = 0;


	if(test01 == 1) test_linkedList();
	if(test02 == 1)  test_linkedList();
	//if(test01 == 1) 
	//if(test01 == 1) 
	//if(test01 == 1) 
	//if(test01 == 1) 
	//if(test01 == 1) 
	//if(test01 == 1) 
	//if(test01 == 1) 
	//if(test01 == 1) 
	//if(test01 == 1) 



	return 0;
}

void test_linkedList()
{
	
	node** head1 = (node**) malloc(sizeof(node*));
	linkedListAdd(head1, 1);
	linkedListAdd(head1, 2);
	linkedListAdd(head1, 3);
	linkedListAdd(head1, 4);
	linkedListAdd(head1, 5);
	linkedListAdd(head1, 10);
	linkedListAdd(head1, 20);
	linkedListAdd(head1, 30);
	linkedListAdd(head1, 40);
	linkedListAdd(head1, 50);
	printLinkedList(*head1);
	deleteLinkedList(head1);

}

void test_createLinkedList()
{

	node** head2 = (node**) malloc(sizeof(node*));
	int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	createLinkedList(vet, 10, head2);
	printLinkedList(*head2);
	deleteLinkedList(head2);

}



///////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
///////////////////////////////////////////////////////////////////////////////


void linkedListAdd(node** head, int val)
{
	node* newNode = NULL;
	node* nextNode = NULL;

	if(head ==  NULL)
	{
		printf("-- Error, head is NULL\n");
	}

	printf("-- linkedListAdd val:%d, head:%p\n", val, head);;
	newNode = (node*) malloc(sizeof(node));
	newNode->next = NULL;
	newNode->data = val;

	if(*head == NULL)
	{
		*head = newNode;
		return;
	}
	else
	{
		nextNode = *head;
		while(nextNode->next != NULL)
		{
			printf("nextNode:%p\n", nextNode);
			printf("nextNode->next:%p\n", nextNode->next);
			printf("nextNode->data:%d\n", nextNode->data);
			nextNode = nextNode->next;
		}
		printf(">nextNode->next:%p\n", nextNode->next);
		printf(">nextNode->data:%d\n", nextNode->data);
		newNode->next = NULL;
		newNode->data = val;
		nextNode->next = newNode;
		return;
	}
}



void deleteLinkedList(node** head)
{
	node* temp = NULL;
	node* next = NULL;
	if( (head == NULL) || (*head == NULL) )
	{
		return;
	}
	else if(*head == NULL)
	{
		return;
	}
	else
	{
		temp = (*head);
		while(temp != NULL)
		{
			next = temp->next;
			free(temp);
			temp = NULL;
			temp = next;
		}
		free(head);
		head = NULL;
	}
}

void printLinkedList(node* head)
{
	node* temp = head;
	printf("\n[");
	while(temp != NULL)
	{
		printf("%d", temp->data);
		if(temp->next != NULL)
		{
			printf(", "); 
		}
		temp = temp->next;
	}
	printf("]\n");
}


void createLinkedList(int vet[], int nvals, node** head)
{
	int i = 0;
	for(i = 0; i< nvals; i++)
	{
		linkedListAdd(head, vet[i]);
	}
}

