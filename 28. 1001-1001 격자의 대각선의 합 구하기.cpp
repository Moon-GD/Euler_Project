#include<stdio.h>

int main()
{
	int i, sum = 1;

	for (i = 2; i <= 501; i++)
	{
		sum += 4 * (4 * i * i - 7 * i + 4);
	}

	printf("���� �밢���� ���� %d", sum);
}