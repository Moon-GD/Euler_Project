#include<stdio.h>
#include<math.h>

int main()
{
	double i, sum = 0, sum2 = 0;

	for (i = 1; i <= 100; i++)
	{
		sum += pow(i,2);
		sum2 += i;
	}
	printf("������ ���� : %.lf, ���� ������ %.lf\n", sum, pow(sum2,2));
	printf("���� ���̴� %.lf �Դϴ�.", pow(sum2,2) - sum);

	return 0;
}