#include<stdio.h>
#include<math.h> // log10, pow
#define MAX 1000000000 // 10�ڸ� ��
int isPandigital(long long sum) // 1~9 �ҵ����� ����
{
	int ciper = (int)log10((double)sum) + 1;

	if (ciper != 9)
		return 0;

	int array[9] = { 0 }; // �ʱ�ȭ
	for (int i = 0; i < 9; i++) // �迭�� ����
	{
		array[i] = sum % 10;
		sum = (long long)(sum / 10);
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (array[i] == array[j])
				return 0;
			if (array[i] == 0)
				return 0;
		}
	}

	return 1;
}

int main()
{
	long long max = 0;

	for (int i = 1; i <= 9999; i++) // i�� �ټ� �ڸ� �̻��� ��쿡, ���ؼ� �̾���̸� 1~9�ҵ������� �� ���� ����.
	{
		long long sum = 0;
		for (int j = 1; sum < MAX && j <= 9; j++)
		{
			if (isPandigital(sum))
			{
				break;
			}
			int temp = i * j;
			int sum_ciper = (int)log10(temp) + 1;
			sum = sum * (int)pow(10, (double)sum_ciper) + temp; // ���ؼ� �̾���̱�
		}
		if (isPandigital(sum)) // �� ������ ���� ��,
		{
			if (sum > max) // ������ �ִ񰪺��� ũ�ٸ� �ִ� ����
			{
				max = sum;
			}
		}
	}
	printf("���� : %lld", max);

	return 0;
}