/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

int findSingleOccurenceNumber(int *A, int len) 
{
	if (A != nullptr && len > 0)
	{
		int ones = 0, twos = 0, non_threes;
		for (int i = 0; i < len; i++)
		{
			twos = twos | (ones & A[i]);
			ones = ones ^ A[i];
			non_threes = ~(ones & twos);
			ones = ones & non_threes;
			twos = twos & non_threes;
		}
		return ones;
	}
	return -1;
}