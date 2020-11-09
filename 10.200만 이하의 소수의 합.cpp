#include<stdio.h>
#include<stdbool.h> // bool
#include<stdlib.h> // �迭�� ũ�� �� ���� �޸𸮸� ������ ���� //�Լ� ������ �޸� ���� �� ���� ��!
#define MAX 2000000

int main()
{
	bool* prime = (bool*)malloc(sizeof(bool) * (MAX + 1));
	double sum = 0;
	int i, j;

	for (i = 2; i < MAX; i++) // ��� prime ���� true ����
	{
		prime[i] = true;
	}

	for (i = 2; i < MAX; i++)
	{
		if (prime[i] == true) // prime[i]�� true �̸� i�� ����� �Ǵ� ��� prime���� false�� �ٲ�
		{
			for (j = i + i; j < MAX; j += i)
			{
				prime[j] = false;
			}
		}
	}

	for (i = 2; i < MAX; i++)
	{
		if (prime[i] == true) // prime�� true�̸�, ��, � ���� ����� �ƴ� ��(�Ҽ�)�� ��� ������.
		{
			sum += (double)(i);
		}
	}
	free(prime);
	printf("���� : %.lf", sum);
	return 0;
}