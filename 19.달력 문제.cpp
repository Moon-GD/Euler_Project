#include<stdio.h>

int flag(int year) // ���� �Ǻ� �Լ�
{
	int index = 0;
	if (year % 4 == 0)
	{
		index = 1;
		if (year % 100 == 0)
		{
			index = 0;
			if (year % 400)
			{
				index = 1;
			}
		}
	}
	return index;
}

int main()
{
	int This_year = 1900, This_month = 1;
	int year, month;
	int day[2][12] = { { 31,28,31,30,31,30,31,31,30,31,30,31 }, { 31,29,31,30,31,30,31,31,30,31,30,31 } };
	int sum = 334; //1900�� 11�� 31�ϱ��� �� ��
	int index = 0;
	int cnt = 0;

	for (year = 1901; year <= 2000; year++)
	{
		index = flag(year);
		for (month = 0; month < 12; month++)
		{
			if (month == 0) { sum += day[flag(year - 1)][11]; }
			else { sum += day[index][month - 1]; }

			if (sum % 7 == 6) { cnt++; } // 1900�� 1�� 1���� �������̹Ƿ� sum % 7 �� 6�� �� �ش� �� 1���� �Ͽ����� �ȴ�. 
		}
	}
	printf("cnt = %d", cnt);
	return 0;
}