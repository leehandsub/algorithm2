#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char s[10] = { 'e','a','b','e','c','a','e','g','w','a' };

int partition(int low, int high, int pivotpoint)
{
	int i, j;
	char pivotitem;
	char temp;
	pivotitem = s[low];
	j = low;
	for (i = low + 1; i <= high; i++)
	{
		if (s[i] < pivotitem)
		{
			j++;
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}
	}
	temp = s[low];
	s[low] = s[j];
	s[j] = temp;
	return j;
}
int rand_partition(int low, int high)
{
	int i = rand() % (high + 1 - low) + low;
	char temp;
	temp = s[low];
	s[low] = s[i];
	s[i] = temp;
	return partition(low, high, i);
}
void quicksort(int low, int high)
{
	int pivotpoint = 0;

	srand(time(NULL));

	if (high > low)
	{
		pivotpoint = rand_partition(low, high);
		quicksort(low, pivotpoint - 1);
		quicksort(pivotpoint + 1, high);
	}
}
void perm(int k, int n)
{
	char temp;
	int m;
	if (k >= n)
	{
		printf("%s\n", s);
		return;
	}
	quicksort(k, n);
	perm(k + 1, n);
	quicksort(k + 1, n);
	for (m = k + 1; m <= n; m++)
	{
		if (s[m] > s[k])
		{
			temp = s[k];
			s[k] = s[m];
			s[m] = temp;
			perm(k + 1, n);
			quicksort(k + 1, n);
		}
	}
}
int main(void)
{
	int len;
	scanf("%d", &len);
	scanf("%s", s);
	perm(0, len - 1);
}