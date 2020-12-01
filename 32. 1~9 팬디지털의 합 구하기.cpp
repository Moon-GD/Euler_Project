#include<stdio.h>
#include<math.h> // pow, log10
int C[30] = {}; // a * b = c ���� c���� ������ �迭����
int cnt = 0; // C�迭�� �ε���

int Overrap(int N) // �ҵ�����(pandigital) �Ǻ� �Լ�
{
	int ciper = (int) log10(N) + 1;
	int num[10] = {};
	int i = 0;
	while (N > 0)
	{
		num[i++] = N % 10;
		N /= 10;
	}

	for (int i = 0; i < ciper; i++) //�� ���ڰ� �ϳ��� �������� �Ǻ�
	{
		if (num[i] == 0) // 0�� ���ԵǸ� ����
			return 0;
		for (int j = i + 1; j < ciper; j++)
		{
			if (num[i] == num[j]) // �ߺ��Ǵ� ���� ������ ����
				return 0;
		}
	}

	return 1;
}

int Double(int c) // �ߺ� �Ǻ� �Լ�
{
	for (int k = 0; k < cnt; k++)
	{
		if (C[k] == c)
		{
			C[k] = 0;
			cnt--;
			return 0; // ������ c�� ���� �ߺ��Ǹ� 0�� ��ȯ
		}
	}
	return 1;
}

int main()
{
	int a, b, c, sum = 0;
	int max_b, min_b;
	for (a = 1; a <= 99; a++)
	{
		if (a < 10)
		{
			min_b = 1000;
			max_b = 9999;
		}
		else
		{
			min_b = 100;
			max_b = 999;
		}
		for (b = min_b; b <= max_b; b++)
		{
			c = a * b;
			if (c > 10000) // 1~9 �ҵ����п��� c�� �ټ��ڸ��� ���� �Ǵ� ���� �Ұ���
				continue;
			int N = 0; // N = a|b|c�� �ǹ�. ��, a=1 b=23 c=456 �� ��, N = 123456
			if (a < 10)
				N = a * (int) pow(10, 8) + b * (int) pow(10, 4) + c;
			else
				N = a * (int) pow(10, 7) + b * (int) pow(10, 4) + c;

			if (Overrap(N))
			{
				cnt++;
				C[cnt] = c;
				if (Double(c))
				{
					//��� ����� �ñ��Ͻø� �Ʒ� �ּ��� �����ϼ���.
					// printf("%4d * %4d= %4d, N = %10d\n", a, b, c, N);
					sum += c;
				}
			}

		}
	}

	printf("������ %d", sum);

	return 0;
}