#include<stdio.h>

int main()
{
	int i=2, j, prime, cnt = 0; // 3���� �Ҽ��� ã�� �����ϴ� 2�� ���ܵȴ�. ��, 10,000��° �Ҽ��� ã���� �Ǵ� ���̴�.
	while (1)
	{
		i++, j = 2;
		while (i > j)
		{
			if (i % j == 0)
			{
				break;
			}
			if (j == i - 1)
			{
				prime = i;
				cnt++;
				if (cnt == 10000) // 
				{
					goto exit;
				}
			}
			j++;
		}
	}
exit:
	printf("%d��° �Ҽ��� %d�Դϴ�.", cnt+1, prime);
	return 0;
}