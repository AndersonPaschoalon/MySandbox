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
void test_linkedList_create();
void test_linkedList_merge();
void test_linkedList_pickMinNode();

// FUNCTIONS
void linkedList_append(node** head, int val);
void linkedList_delete(node** head);
void linkedList_print(node* head);
void linkedList_create(int vet[], int nvals, node** head);
node* linkedList_pickMinNode(node** n1, node** n2);                              
void linkedList_merge(node** head, node** r1, node** r2);
void linkedList_printNode(node* n);

///////////////////////////////////////////////////////////////////////////////
// MAIN
///////////////////////////////////////////////////////////////////////////////
int main()
{
	int test01 = 0;
	int test02 = 0;
	int test03 = 1;
	int test04 = 0;
	int test05 = 0;
	int test06 = 0;
	int test07 = 0;
	int test08 = 0;
	int test09 = 0;
	int test10 = 0;
	int test11 = 0;


	if(test01 == 1) test_linkedList();
	if(test02 == 1) test_linkedList_create();
	if(test03 == 1) test_linkedList_merge(); 
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
	printf("# test_linkedList\n");
	node* head = NULL;
	linkedList_append(&head, 1);
	linkedList_append(&head, 2);
	linkedList_append(&head, 3);
	linkedList_append(&head, 4);
	linkedList_append(&head, 5);
	linkedList_append(&head, 10);
	linkedList_append(&head, 20);
	linkedList_append(&head, 30);
	linkedList_append(&head, 40);
	linkedList_append(&head, 50);
	linkedList_print(head);
	printf("\n");
	linkedList_delete(&head);

	linkedList_append(&head, 2);
	linkedList_append(&head, 4);
	linkedList_append(&head, 6);
	linkedList_append(&head, 8);
	linkedList_append(&head, 10);
	linkedList_append(&head, 12);
	linkedList_append(&head, 14);
	linkedList_append(&head, 16);
	linkedList_append(&head, 18);
	linkedList_append(&head, 20);
	linkedList_print(head);
	printf("\n");
	linkedList_delete(&head);

}

void test_linkedList_create()
{
	node* head = NULL;
	int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	linkedList_create(vet, 10, &head);
	linkedList_append(&head, 12);
	linkedList_print(head);
	printf("\n");
	linkedList_delete(&head);
}

void test_linkedList_merge()
{
	printf("* test merge");
	node* r1 = NULL;
	node* r2 = NULL;
	node* head = NULL;
	int vet[] = {1, 3, 5, 7, 9, 11, 13};	
	int vet2[] = {0, 2, 4, 6, 8, 10, 12};

	linkedList_create(vet, 7, &r1);
	linkedList_print(r1);
	printf("\n");
	linkedList_create(vet2, 7, &r2);
	linkedList_print(r2);
	printf("\n");
	linkedList_merge(&head, &r1, &r2);
	printf("-- merged list head:");
	linkedList_print(head);
	printf("\n");
	linkedList_delete(&head);
}

void test_linkedList_pickMinNode()
{
	printf("* test merge");
	node* head1 = NULL;
	int vet[] = {1, 3, 5, 7, 9, 11, 13};
	linkedList_create(vet, 7, &head1);
	linkedList_print(head1);
	printf("\n");

	node* head2 = NULL;
	int vet2[] = {0, 2, 4, 6, 8, 10, 12};
	linkedList_create(vet2, 7, &head2);
	linkedList_print(head2);
	printf("\n");
	
	node* min = linkedList_pickMinNode(&head1, &head2);
	printf("-- min->next:%p\n", min->next);
	printf("-- min->data:%d\n", min->data);
	
	printf("-- head1->data:%d\n", head1->data);
	printf("-- head2->data:%d\n", head2->data);
	
	linkedList_delete(&head1);
	linkedList_delete(&head2);

	return;
}



///////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
///////////////////////////////////////////////////////////////////////////////


void linkedList_append(node** head, int val)
{
	node* last = *head;
	node* newNode = (node*)malloc(sizeof(node));
	printf("-- append val:%d, *head:%p\n", val, *head);

	newNode->data = val;
	newNode->next = NULL;

	if(*head == NULL)
	{
		printf("-- append first node\n");
		(*head) = newNode;
		return;
	}
	while(last->next != NULL)
	{
		last = last->next;
	}
	last->next = newNode;
	return;
}

void linkedList_delete(node** head)
{
	node* last = *head;
	node* temp;
	while(last != NULL)
	{
		temp = last;
		free(temp);
		temp = NULL;
		last = last->next;
	}
	*head = NULL;

}

void linkedList_print(node* head)
{
	node* temp = head;
	printf("[");
	while(temp != NULL)
	{
		printf("%d", temp->data);
		if(temp->next != NULL)
		{
			printf(", "); 
		}
		temp = temp->next;
	}
	printf("]");
}


void linkedList_create(int vet[], int nvals, node** head)
{
	int i = 0;
	for(i = 0; i< nvals; i++)
	{
		linkedList_append(head, vet[i]);
	}
}


node* linkedList_pickMinNode(node** n1, node** n2)
{
	node* temp = NULL;

	if(*n1 == NULL && *n2 == NULL)
	{
		return NULL;
	}
	else if(*n1 == NULL)
	{
		temp = *n2;
		*n2 = (*n2)->next;
		return temp;	
	}
	else if(*n2 == NULL)
	{
		temp = *n1;
		*n1 = (*n1)->next;
		return temp;	
	}
	else if((*n1)->data < (*n2)->data)
	{
		temp = *n1;
		*n1 = (*n1)->next;
		return temp;
	}
	else // (*n1)->key >= (*n2)->key
	{
		temp = *n2;
		*n2 = (*n2)->next;
		return temp;
	}

}

void linkedList_merge(node** head, node** r1, node** r2)
{
	printf("-- linkedList_merge r1:\t");
	linkedList_print(*r1);
	printf("\n-- linkedList_merge r2:\t");
	linkedList_print(*r2);
	printf("\n");

	if(*head == NULL)
	{
		*head = linkedList_pickMinNode(r1, r2);
	}
	(*head)->next = linkedList_pickMinNode(r1, r2);
	if( (*head)->next != NULL)
	{
		printf("-- linkedList_merge:(*head)->data:%d\n", (*head)->data);
		linkedList_merge(&((*head)->next), r1, r2);
	}
}


void linkedList_printNode(node* n)
{
	printf("<node->data:%d, node->next:%p>", n->data, n->next);
}
