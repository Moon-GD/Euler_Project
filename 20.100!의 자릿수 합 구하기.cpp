#include<stdio.h>
#include<string.h>
char num[300] = "1";
int temp[300] = { 1 };

int main()
{
	int i, j, flag = 0; // flag �� ���� �ڸ� ���� ���� �ڸ� ���� ������ �ִ� ��� �ش� ��ȭ����ŭ ���� �ڸ� ���� ���� �ش�.
	int sum = 0; // �� �ڸ� ���� ���� ������ ����

	for (i = 2; i <= 100; i++) // ���丮�� ���
	{
		for (j = 0; j < 300; j++)
		{
			if ('0' <= num[j] && num[j] <= '9')
			{
				temp[j] = (num[j] - '0') * i + flag;
			}
			else { break; }

			num[j] = (temp[j] % 10) % 10 + '0';
			flag = 0;

			if (temp[j] >= 10)
			{
				if ('9' < num[j + 1] || num[j + 1] < '0')
				{
					num[j + 1] = '0';
				}
				flag = temp[j] / 10;
			}
		}
	}
	for (i = 0; i < 300; i++) // ������ ���� �� �ڸ� �� ���ϱ�
	{
		if ('0' <= num[i] && num[i] <= '9')
		{
			sum += num[i] - '0';
		}
		else { break; }
	}
	printf("sum = %d\n", sum);

	return 0;
}
/* 100!�� ���� �ʹ� ũ�ٺ��� �޸� �ʰ��� �����ϸ� ������ �迭�� ������ �ذ��Ͽ���.
������, ������ �迭�ε� "�����ֱ⸸ ���Ѵٸ�" Ǯ���� �� ������ �˰� �Ǿ���.
#include <stdio.h>
#include <math.h>

int main()
{
	int x[40] = { 1,0 }, check = pow(10, 5), sum = 0;
	int factorial = 100;

	for (int i = 1; i <= factorial; i++)
		for (int j = 38; j >= 0; j--)
		{
			x[j] *= i;
			if (x[j] > check)
			{
				x[j + 1] += (int)(x[j] / check);
				x[j] %= check;
			}
		}

	for (int i = 0; i < 40; i++)
		while (1)
		{
			sum += x[i] % 10;
			x[i] = (int)(x[i] / 10);
			if (x[i] == 0)
				break;
		}

	printf("%d", sum);

	return 0;
}
*/