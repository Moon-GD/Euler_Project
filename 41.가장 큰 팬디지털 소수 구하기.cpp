#include<stdio.h>
#include<string.h> // sprintf
#include<math.h> // log10, sqrt

int isPandigital(int i) // �ҵ����� ����
{
	char num[10];
	sprintf_s(num, "%d", i); // �� �ڸ� �񱳸� ���� ���ڿ��� ����

	int ciper = (int)log10(i) + 1; // i�� �ڸ���

	for (int x = 0; x < ciper; x++)
	{
		for (int y = x + 1; y < ciper; y++)
		{
			if (num[y] > '0' + ciper) // 1~n �ҵ����� ���ε�, n�� �Ѿ�� ���� ������ ����
				return 0;
			if (num[y] == '0') // 0�� ���� ����
				return 0;
			if (num[x] == num[y]) // �ߺ��� �߻��ϸ� ����
				return 0;
		}
	}
	return 1;
}

int isPrime(int i) // �Ҽ� �Ǻ�
{
	for (int j = 2; j <= sqrt(i); j++)
	{
		if (i % j == 0)
			return 0;
	}
	return 1;
}

int main()
{
	// 1~8, 1~9 �ҵ����� ���� ��� 3�� ����̱� ������ ��� X
	// 1~7 �������м����� ���

	int i = 7654321;

	while (1)
	{
		if (isPandigital(i)) // �ҵ����� ����
		{
			if (isPrime(i)) // �Ҽ� ����
			{
				printf("���� %d", i);
				break;
			}
		}
		i--;
	}

	return 0;
}