/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdlib.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int isLessOrEqual(char *date1, char *date2)
{
	//	printf("date1 : %s date2: %s\n",date1,date2);
	int y1 = ((date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0'));
	int y2 = ((date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0'));
	//	printf("y1: %d y2: %d\n",y1,y2);
	if (y1 < y2)
		return 1;
	else if (y1 > y2)
		return 0;
	else
	{
		int m1 = ((date1[3] - '0') * 10 + (date1[4] - '0'));
		int m2 = ((date2[3] - '0') * 10 + (date2[4] - '0'));
		//		printf("m1: %d m2: %d\n",m1,m2);
		if (m1 < m2)
			return 1;
		else if (m1 > m2)
			return 0;
		else
		{
			int d1 = ((date1[0] - '0') * 10 + (date1[1] - '0'));
			int d2 = ((date2[0] - '0') * 10 + (date2[1] - '0'));
			//			printf("d1: %d d2: %d\n",d1,d2);
			if (d1 < d2)
				return 1;
			else if (d1 = d2)
				return 2;
			else
				return 0;
		}
	}
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	if (A != NULL && B != NULL)
	{
		struct transaction *result = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
		int i = 0, j = 0, k = 0;
		while (i < ALen && j < BLen)
		{
//			int flag = isLessOrEqual(A[i].date, B[j].date);
			if (isLessOrEqual(A[i].date, B[j].date))
			{
				result[k] = A[i];
				i++;
				k++;
			}
			else
			{
				result[k] = B[j];
				j++;
				k++;
			}
		}
		while (i<ALen)
		{
			result[k] = A[i];
			i++;
			k++;
		}
		while (j<BLen)
		{
			result[k] = B[j];
			j++;
			k++;
		}
		return result;
	}
	return NULL;
}