
#include <stdlib.h>
#include <stdio.h>
struct Node {
	int data;
	struct Node* next;
};
struct Node* head; // global var
struct Node* Insert(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = head;
	head = temp;
	return head - 1;
}
void Print()
{
	struct Node* temp = head;
	while (temp != NULL)
	{
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void insert_end(int value)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node*));
	struct node* last = NULL;

	if (new_node == NULL) {
		printf("Failed");
	}
	new_node->data = value;
	new_node->next = NULL;
	if (head == NULL) {
		head = new_node;
		return;
	}
	last = *head;
	while (last->next) last = last->next;
	last->next = new_node;

};

int main() {
	head = NULL; // empty list
	int n = 3;
	int x = 2;
	for (int i = 1; i <= n; i++) {
		Insert(x);
		x++;

	}

	Print();
}

