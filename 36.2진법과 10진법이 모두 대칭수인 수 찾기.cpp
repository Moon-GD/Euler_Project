#define _CRT_SECURE_NO_WARNINGS // sprintf ��� ����
#include<stdio.h> //sprintf
#include<string.h> // strrev, strcpy
#define MAX 1000000

int main()
{
	int i;
	int sum = 0;

	for (i = 1; i < MAX; i++)
	{
		char array[10];
		char temp[10] = {};
		sprintf(array, "%d", i); // ���� i�� array�� ���ڿ��� ����
		strcpy(temp, array); // temp�� array ����

		if (strcmp(_strrev(array), temp) != 0) // ��Ī���� �ƴϸ� continue
		{
			continue;
		}

		char Two[30], Temp[30] = {}; // 2������ ��Ÿ�� �迭�� �ӽ� �迭
		int x = i;
		int k = 0; // Two�� Index

		while (x > 0) // 2�������� ��Ÿ���� ���ڿ��� ����
		{
			Two[k++] = '0' + x % 2;
			x /= 2;
		}

		Two[k] = NULL; // �����Ⱚ ������ ���� �ι��� ����
		strcpy(Temp, Two); //Temp�� Two ����

		if (strcmp(Two, _strrev(Temp)) == 0) // 2������ ��Ī���̸� �ջ�
		{
			sum += i;
		}
	}
	printf("���� : %d", sum);

	return 0;
}