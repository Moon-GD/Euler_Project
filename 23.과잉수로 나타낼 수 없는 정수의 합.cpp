#include<stdio.h>
#include<stdlib.h> // malloc
#include<stdbool.h> // bool
#define max 28123
bool num[max + 1];

int abudant(int n) // ������ �Ǻ� �Լ�
{
	int i, sum = 0;

	for (i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			sum += i;
		}
	}
	if (sum > n)
		return n;
	else
		return 0;
}

int main()
{
	int size = 0, i, j, sum = 0;

	for (i = 1; i <= max; i++)  // 1~28123 ������ ���� true ����, ���������� true�� ���� �����ֱ�.
		num[i] = true;

	for (i = 12; i < max; i++)
	{
		if (abudant(i) != 0)
			size++;
	}

	int* array = (int*)malloc(sizeof(int) * size + 1); // ������ ���� ���� �迭 ���� �Ҵ�
	int n = 0;

	for (i = 12; i < max; i++) // array�� ������ ����
	{
		if (abudant(i) != 0)
			array[n++] = abudant(i);
	}

	for (i = 0; i < size; i++)
	{
		for (j = i; array[i] + array[j] <= max; j++)
		{
			num[array[i] + array[j]] = false; // �������� ������ ǥ���Ǵ� ���� false �� ǥ��
		}
	}

	sum = 0;

	for (i = 1; i <= max; i++)
	{
		if (num[i] == true) // true�� ǥ���Ǵ� ���� ��� ����
			sum += i;
	}

	printf("sum = %d", sum);
	free(array); // �޸� ����
	return 0;
}