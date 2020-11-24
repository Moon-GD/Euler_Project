#include<stdio.h>
#include<math.h> //factorial
#define MAX 100000

int factorial(int i) // ���丮�� �Լ�
{
	if (i == 0)
		return 1;
	if (i < 0)
		return 0;
	return  i * factorial(i - 1);
}

int find(int i) // �� �ڸ��� ���丮���� ���� �ڱ� �ڽ��� �Ǹ� 1��, �ƴϸ� 0�� ��ȯ�ϴ� �Լ�
{
	int sum = 0;
	int x = i;

	while (x != 0)
	{
		sum += factorial(x % 10);
		x = x / 10;
	}

	if (i == sum)
		return 1;
	else
		return 0;
}


int main()
{
	int sum = 0;
	for (int i = 10; i <= MAX; i++)
	{
		if (find(i))
			sum += i;
	}

	printf("���� %d", sum);

	return 0;
}