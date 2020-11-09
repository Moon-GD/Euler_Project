#include<stdio.h>

double Way(int grid)
{
	int i;
	double way = 1;

	for (i = 2 * grid; 1 <= i; i--)
	{
		if (grid < i) { way *= i; }
		if (i <= grid) { way /= i; }

	}

	return way;
}

int main()
{
	int grid;

	printf("������ ũ���? :"); scanf_s("%d", &grid);
	printf("%.lf �Դϴ�.", Way(grid));

	return 0;
}
//�������� : 
// 1. ������ �̿��� ���, ���丮�� �Լ��� ���̺귯���� ������������, �װ��� ����� ��
// 2. ����� ���� �̿��� ���, �迭�� ����� ��