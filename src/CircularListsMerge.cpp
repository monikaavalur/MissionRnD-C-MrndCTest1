/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
void concat(struct node **list1, struct node **list2);
int lengthOfLoop(struct node **q);
int merge_circularlists(struct node **head1, struct node **head2){
	if (head1==NULL||head2==NULL)
	return -1;
	concat(head1, head2);
	int n = lengthOfLoop(head1);

	return n;

}
void concat(struct node **list1, struct node **list2)
{

	struct node *temp;

	/* if the first linked list is empty */
	if (*list1 == NULL)
		*list1 = *list2;
	else
	{
		/* if both linked lists are non-empty */
		if (*list2 != NULL)
		{
			temp = *list1;  /* points to the starting of the first list */
			/* traverse the entire first linked list */
			while (temp->next != NULL){
				temp = temp->next;
			}

			temp->next = *list2;  /* concatenate the second list after the
							  first */

		}
	}

}

int lengthOfLoop(struct node **q)
{

	int c = 0;
	struct node *temp;
	temp = *q;
	/* traverse the entire linked list */
	while (temp->next != NULL)
	{
		temp = temp->next;
		c++;
	}
	return c;
}