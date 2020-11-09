#include<stdio.h>

int factorial(int n) //���丮��
{
	int product = 1;
	while (n)
		product *= n--;

	return product;
}

void change_position(char* num, int q)
{
	int i;
	char temp = '0';

	for (i = q; i + 1 < 10; i++)
	{
		temp = num[i];
		num[i] = num[i + 1];
		num[i + 1] = temp;
	}
}

int main()
{
	char num[10 + 1] = "0123456789";
	int target = 1000000 - 1; // ��ȯ �� ����� �迭 ��ü�� ù��° �����̹Ƿ� ���Ϸ��� �������� 1�� ���ش�.
	int size = 9; // �ڸ���
	int q; // quotient(��)
	while (size)
	{
		q = target / factorial(size);
		target %= factorial(size);
		if (q == 0)
			change_position(num, 0);
		else
			change_position(num, q);
		size--;
		if (size == 0)
			change_position(num, 0);
	}
	for (int i = 0; i < 10; i++)
		printf("%c", num[i]);
	return 0;
}