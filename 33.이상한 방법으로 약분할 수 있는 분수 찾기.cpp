#include<stdio.h>

double find(int i, int j) // �м����� ���� �и� ���� �κ��� ����� �������� ��ȯ�ϴ� �Լ�
{
	int i_10 = i / 10, i_1 = i % 10;
	int j_10 = j / 10, j_1 = j % 10;
	if (i_10 == j_10)
		return double(j_1) / double(i_1);
	else if (i_10 == j_1)
		return double(j_10) / double(i_1);
	else if (i_1 == j_10)
		return double(j_1) / double(i_10);
	else if (i_1 == j_1)
		return double(j_10) / double(i_10);
	else
		return 0;
}

int array_i[10]; // �и� ������ �迭
int array_j[10]; // ���ڸ� ������ �迭

int main()
{
	int cnt = 0;
	double temp = 0.0;
	for (int i = 10; i < 100; i++)
	{
		for (int j = 10; j < i; j++)
		{
			if (i % 10 == 0 && j % 10 == 0) { continue; } // 10/20 �� ���� �� ����

			temp = ((double)j / (double)i);
			if (find(i, j))
			{
				if (temp == find(i, j))
				{
					cnt++;
					array_i[cnt] = (int)i;
					array_j[cnt] = (int)j;
				}
			}
		}
	}

	for (int i = 1; array_i[i] != 0; i++) // �и� ���� ���
	{
		printf("%d ��° �и� = %d, ���� = %d\n\n", i, array_i[i], array_j[i]);
	}

	return 0;
}