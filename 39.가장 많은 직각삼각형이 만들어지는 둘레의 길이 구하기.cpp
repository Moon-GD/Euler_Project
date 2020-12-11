#include<stdio.h>
int rightAngle[1000 + 1] = { 0 };

int main()
{
	int a, b, c; // �ﰢ���� �� ��
	for (a = 1; a <= 998; a++)
	{
		for (b = a; b <= 998; b++)
		{
			for (c = b; c <= 998; c++)
			{
				if (a + b + c > 1000) // �ѷ��� 1000 �̻��� ���� ����
					continue;
				if (c * c == a * a + b * b) // ��Ÿ����� ������ ������Ű�� �ش� �ѷ��� �迭�� +1 ���ش�
				{
					rightAngle[a + b + c]++;
				}
			}
		}
	}
	int max = 0, max_circumference = 0;
	// max = �����ﰢ���� �ִ� ����, max_circumference = �����ﰢ���� ������ �ִ�� ������ �ѷ��� ����

	for (int i = 1; i < 1000; i++)
	{
		if (rightAngle[i] > max)
		{
			max = rightAngle[i];
			max_circumference = i;
		}
	}

	printf("���� : %d", max_circumference);

	return 0;
}