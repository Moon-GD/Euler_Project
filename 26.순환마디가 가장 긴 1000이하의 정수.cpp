#include<stdio.h>
#include<math.h>
#define max 9999999999999999 // 9�� 16��
long long nine[10] = { 0 };

int divide(int i) // ���μ� �� 2�� 5�� ����� ��� ����
{
	while (i % 5 == 0)
		i /= 5;
	while (i % 2 == 0)
		i /= 2;
	return i;
}

int main()
{
	int i;
	int goal_i = 0, goal = 0;
	for (i = 1; i <= 1000; i++)
	{
		int j = 0, cnt = 1;
		nine[j] = { 0 };
		while (1)
		{
			nine[j] = nine[j] * 10 + 9;

			while (j != 0)
			{
				int temp = nine[j] % i;
				j--;
				nine[j] += temp;
			}

			if (nine[j] % divide(i) == 0)
			{
				if (goal < cnt)
				{
					goal = cnt;
					goal_i = i;
				}
				break;
			}
			else
				cnt++;
			if (nine[j] >= max)
				nine[++j] = 0;
		}
		printf("%d %d\n", i, cnt); // �� ���ں� ��ȯ���� ���� ���
	}

	printf("%d�϶� %d", goal_i, goal); // ���� ����

	return 0;
}