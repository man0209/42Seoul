#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
	int data;
	struct listNode *next;
	struct listNode *prev;
} node;

node *createNode(int data)
{
	node *newNode = (node *)malloc(sizeof(node));
	
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}

void deleteNode(node *node)
{
	free(node);
}

node *getNodeAt(node *head, int index)
{
	node *horse = head;
	int count = 0;

	while (horse != NULL)
	{
		if (count++ == index)
		{
			return horse;
		}
		horse = horse->next;
	}
	return NULL;
}

int countNode(node *head)
{
	int count = 0;
	node *horse = head;

	while (horse != NULL)
	{
		
		horse = horse->next;
		count++;
	}
	return count;
}

void addnode(node **head, node *newNode)
{
	//no list exists
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		node *horse =*head;

		while (horse->next != NULL)
		{
			horse = horse->next;
		}
		horse->next = newNode;
		newNode->prev = horse;
	}	
}

void insertNode(node *current, node *newNode)
{
	if (current->prev == NULL && current->next == NULL)
	{
		current = newNode;
	}
	else if (current->prev != NULL && current->next == NULL)
	{
		current->next = newNode;
		newNode->prev = current;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = current->next;
		newNode->prev = current;
		current->next->prev = newNode;
		current->next = newNode;
	}
	
}

void removeNode(node **head, node *remove)
{
	if (*head == remove)
	{
		*head = remove->next;
	}
	else
	{
		
	}
	
}

int main(int ac, char **av)
{
	char a[] = "abc" ;
	printf("a : %s\n", a);
	printf("a : %p\n", a);

	char *b = a;
	printf("b : %s\n", b);

	*a = 0;

	printf("b : %s\n", b);
	printf("a : %s\n", a);
	printf("a : %p\n", a);
	printf("b : %p\n", b);
}

