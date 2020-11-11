#include<stdio.h>

int isPrime(int i)
{
	for (int j = 2; j < i; j++)
	{
		if (i % j == 0)
			return 0;
	}

	return 1;
}

int main()
{
	int prime[25 + 1] = { 0 }; //�Ҽ� 25 ��
	int num[100][25 + 1] = { 0 };
	int i, j = 0;
	for (i = 2; i < 100; i++) //�Ҽ� ã��
	{
		if (isPrime(i) == 1)
		{
			prime[j++] = i;
		}
	}

	for (i = 2; i < 100; i++) // 2~100������ ����(a) �μ��� ������ ǥ��
	{
		int x = i;
		for (j = 0; j < 25; j++)
		{
			while (x % prime[j] == 0)
			{
				num[i][j] ++;
				x /= prime[j];
			}
		}
	}

	int array[100][100][25 + 1]; // array[a][b][�μ��� ������ ǥ��]
	int*** parray = array;

	for (i = 2; i <= 100; i++)
	{
		for (j = 2; j <= 100; j++)
		{
			array[i][j] = j * num[i][j];
		}
	}



	return 0;
}