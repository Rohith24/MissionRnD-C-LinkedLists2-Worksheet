/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	int even = 0;
	struct node *result = head;
	while (head->next != NULL)
	{
		even = 1;
		head = head->next;
		if (head->next != NULL)
		{
			head = head->next;
			result = result->next;
			even = 0;
		}
	}
	if (even == 1)
		return (result->num + result->next->num) / 2;
	else
		return result->num;
}
