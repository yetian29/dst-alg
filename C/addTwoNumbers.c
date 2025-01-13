#include <stdio.h>
#include <stdlib.h>


/*struct ListNode */
/*{*/
/*	int val;*/
/*	struct ListNode *next;*/
/*}*/
/**/
/**/
/*struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)*/
/*{*/
/*	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));*/
/*	struct ListNode *current = head;*/
/*	unsigned int carry = 0;*/
/*	int sum = 0;*/
/*	while (l1 != NULL || l2 != NULL || carry != 0)*/
/*	{*/
/*        int val1 = 0, val2 = 0;*/
/*		if (l1 != NULL)*/
/*        {*/
/*            val1 = l1 -> val;*/
/*        }     */
/*		if (l2 != NULL) */
/*        {*/
/*            val2 = l2 -> val;*/
/*        }*/
/**/
/*		sum = val1 + val2 + carry;*/
/*		int val3 = sum % 10;*/
/*		struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));*/
/*		new_node -> val = val3;*/
/*		new_node -> next = NULL;*/
/*		current -> next = new_node;*/
/*        current = current -> next;*/
/*		carry = sum / 10;*/
/*        if (l1 != NULL) l1 = l1 -> next;*/
/*        else l1 = NULL;*/
/*        if (l2 != NULL) l2 = l2 -> next;*/
/*        else l2 = NULL;*/
/**/
/*	}*/
/*	struct ListNode *result = head -> next;*/
/*	free(head);*/
/*	return result;*/
/*}*/



struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *current = head;
	unsigned int carry = 0;
	while (l1 != NULL || l2 != NULL || carry != 0)
	{
		int val1 = 0, val2 = 0, sum, val3;
		if (l1 != NULL)
			val1 = l1 -> val;
		if (l2 != NULL)
			val2 = l2 -> val;
	  sum = val1 + val2 + carry;
		val3 = sum % 10;
		carry = sum / 10;
		struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
		new_node -> val = val3;
		new_node -> next = NULL;
		current -> next = new_node;
		current = current -> next;
		if (l1 != NULL)
			l1 = l1 -> next;
		else
			l1 = NULL;
		if (l2 != NULL)
			l2 = l2 -> next;
		else
			l2 = NULL;	
	}
	struct ListNode *result = head -> next;
	free(head);
	return result;
}
