/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int count_leap(int date, int month, int year);
int convert_sll_2digit_to_int(struct node *head, int len1);
int between_days(struct node *date1head, struct node *date2head)
{
	if (date1head == NULL || date1head == NULL)
		return -1;
	int monthDays[12] = { 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31 };
	int date1 = convert_sll_2digit_to_int(date1head, 2);
	int date2 = convert_sll_2digit_to_int(date2head, 2);
	int count = 0;
	while (count != 2)
	{
		date1head = date1head->next;
		date2head = date2head->next;
		count++;
	}
	int month1 = convert_sll_2digit_to_int(date1head, 2);
	int month2 = convert_sll_2digit_to_int(date2head, 2);
	count = 0;
	while (count != 2)
	{
		date1head = date1head->next;
		date2head = date2head->next;
		count++;
	}
	int year1 = convert_sll_2digit_to_int(date1head, 4);
	int year2 = convert_sll_2digit_to_int(date2head, 4);
	printf("%d", year1);
	printf("%d", year2);
	long int n1 = year1 * 365 + date1;
	for (int index = 0; index<month1 - 1; index++)
		n1 += monthDays[index];
	n1 += count_leap(date1, month1, year1);
	long int n2 = year2 * 365 + date2;
	for (int i = 0; i < month2 - 1; i++)
		n2 += monthDays[i];
	n2 += count_leap(date2, month2, year2);
	return (n2 - n1 - 1);
	
}
int count_leap(int date, int month, int year)
{
	if (month <= 2)
		year--;
	return year / 4 - year / 100 + year / 400;
}

int convert_sll_2digit_to_int(struct node *head,int len1)
{
	struct node *ptr;
	ptr = head;
	int Arr[100], count = 0, index = 0, c = 0;
	if (ptr == NULL)
		return NULL;
	ptr = head;
	while (c != len1){
		Arr[index] = ptr->data;
		index++;
		ptr = ptr->next;
		c++;
	}
	int len = index;
	Arr[len] = '\0';
	long int num = 0, product;
	for (index = 0; index<2; index++)
	{
		product = 10;
		while (Arr[index] >= product)
			product *= 10;
		num *= product;
		num += Arr[index];
	}
	return num;
}