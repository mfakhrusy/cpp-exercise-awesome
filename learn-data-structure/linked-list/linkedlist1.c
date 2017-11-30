#include <stdio.h>
#include <stdlib.h>

// Linked list implementation
struct Node {
	int x;
	struct Node *next;
};

// Program to create a simple linked list with 3 nodes
int main() {

	struct Node *head = NULL;
	struct Node *second = NULL;
	struct Node *third = NULL;

	// allocate 3 nodes in the heap
	head = (struct Node*)malloc(sizeof(struct Node));

}
