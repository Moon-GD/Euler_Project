#include<stdio.h>

int Prime(int i)									// �Ҽ� �Ǻ� �Լ�
{
	int j;
	for (j = 2; j < i; j++)
	{
		if (i % j == 0)
			return 0;								// �Ҽ��� �ƴϸ� 0�� ��ȯ
	}
	return 1;										// �Ҽ��̸� 1�� ��ȯ
}

int main()
{
	long long n = 600851475143, i;

	for (i = 2; i <= n; i++)
	{
		if (n % i == 0)								 // i�� �־��� ���� ����϶�
		{
			if (Prime(i) == 1)						 // 1�� ��ȯ�޴´ٸ� ���
				printf("%lld\n", i);
			n = n / i;								// n�� ������ �־� ��� �뷮�� �ٿ���.
		}
	}

	return 0;
}
// 71 839 1471 6857 �� ��µǹǷ� ���� ū ���μ��� 6857