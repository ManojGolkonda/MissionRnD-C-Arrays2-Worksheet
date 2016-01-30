/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int isGreater(char *date1, char *date2)
{
	//	printf("date1 : %s date2: %s\n",date1,date2);
	int y1 = ((date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0'));
	int y2 = ((date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0'));
	//	printf("y1: %d y2: %d\n",y1,y2);
	if (y1>y2)
		return 1;
	else if (y1 < y2)
		return 0;
	else
	{
		int m1 = ((date1[3] - '0') * 10 + (date1[4] - '0'));
		int m2 = ((date2[3] - '0') * 10 + (date2[4] - '0'));
		//		printf("m1: %d m2: %d\n",m1,m2);
		if (m1>m2)
			return 1;
		else if (m1 < m2)
			return 0;
		else
		{
			int d1 = ((date1[0] - '0') * 10 + (date1[1] - '0'));
			int d2 = ((date2[0] - '0') * 10 + (date2[1] - '0'));
			//			printf("d1: %d d2: %d\n",d1,d2);
			if (d1>d2)
				return 1;
			else
				return 0;
		}
	}
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (isGreater(Arr[i].date, date))
			break;
	}
	return len - i;
}
