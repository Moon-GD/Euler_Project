#include<stdio.h>
int main()
{
	int goal = 1, cnt = 3;
	double x = 1, y = 1, z = 2; // ������ �� ��
	while (1)
	{
		x = y;
		y = z;
		z = x + y;
		cnt++;
		if (z >= 10) //���� ū ���� 10���� ū ��� 10���� �������ְ� goal ++
		{
			x /= 10;
			y /= 10;
			z /= 10;
			goal++;
		}
		if (goal == 1000)
			break;
	}
	printf("%d", cnt);

	return 0;
}