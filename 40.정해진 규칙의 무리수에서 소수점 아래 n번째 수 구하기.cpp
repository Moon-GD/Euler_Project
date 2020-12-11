#include<stdio.h>
#include<math.h> // log10
#include<string.h> // sprintf

int find(int i, int gap) // Ÿ�� ������ �Ѿ�� �� Ÿ�꿡���� ���� �������� �����ִ� �Լ�
{
	char N[10] = { 0 }; // ���� ���� i�� ���ڿ��� ��ȯ�Ͽ� ������ �迭
	int length = (int)log10(i); // i�� �迭�� �������� ���� ����
	sprintf_s(N, "%d", i); // ���ڿ��� ��ȯ
	return N[length - gap] - '0';
}

int main()
{
	int target[7] = { 1,10,100,1000,10000,100000,1000000 };

	int goal = 1, cnt = 0;
	// goal = ��, cnt = �Ҽ����� ����
	int i = 1, j = 0;
	// i = ���� ����, j = target �迭�� ��ǥ
	while (j < 7)
	{
		int ciper = (int)log10(i) + 1; // ���� i�� �ڸ���
		cnt += ciper; // �Ҽ��� ���� �߰�
		if (cnt >= target[j])
		{
			goal *= find(i, cnt - target[j++]); // j++�� target ���� (1->10->100-> ...->1,000,000)
		}
		i++;
	}

	printf("���� %d", goal);

	return 0;
}