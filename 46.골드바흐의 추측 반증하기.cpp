#include<stdio.h>
#include<math.h> // sqrt

int isPrime(int i) // �Ҽ� �Ǻ� �Լ�. �Ҽ��� 1, �ռ����� 0�� ��ȯ
{
	for (int j = 2; j <= sqrt(i); j++)
	{
		if (i % j == 0)
			return 0;
	}
	return 1;
}

int main()
{
	for (int i = 9;; i += 2)
	{
		int flag = 1;
		if (isPrime(i) == 0)
		{
			for (int j = 3; j < i; j++)
			{
				if (isPrime(j))
				{
					int temp = (i - j);
					//temp = �ռ��� - �Ҽ�
					for (int k = 1; k * k * 2 <= temp; k++) { // �ռ��� - �Ҽ��� 2 X �������� ǥ���Ǵ��� Ȯ��
						//ǥ���Ǹ� flag = 0 �����ϰ� �ݺ��� �ߴ�
						if (k * k * 2 == temp) {
							flag = 0;
							break;
						}
					}
				}
				if (flag == 0) // flag == 0, ��, �������� ������� ǥ���� �Ǹ� �ݺ��� �ߴ�
					break;
			}
			if (flag == 1) { // �������� ������ ��߳� �ռ��� i�� �������� ��� i�� ����ϰ� main �Լ� ����
				printf("������ : %d", i);
				return 0;
			}
		}
	}
}