// 42.txt ���� �� ������ YOUTH �ڿ� " " ���� �� ĭ �ԷµǾ� ������ ����� ��

#define _CRT_SECURE_NO_WARNINGS //fopen ��� ����
#include<stdio.h>
#include<string.h> // strcmp
char buffer[1000000]; // ������ �о�� �迭
char word[2000][20]; // �ܾ ������ �迭
int num_value[2000]; // �ܾ�� ������ �迭
int main()
{
	FILE* fp = fopen("42.txt", "r");// ���� �б� ���
	fgets(buffer, sizeof(buffer), fp); // ���� ���� buffer �迭�� ����
	char* p = buffer; // p : buffer ���� ������ ������

	int spell = 0, cnt = 0;
	// spell, cnt = word �迭�� ��ǥ

	int temp = 0, goal = 0;
	// temp = �ܾ ������ ���� ����, goal = ��

	while (strcmp(word[cnt], "YOUTH") != 0)
	{
		cnt++;
		temp = 0, spell = 0;
		while (1)
		{
			if (*p == ' ') // ���� ������ cnt ��ǥ 1 ����, ��, ���� �ܾ� �Է� ���� �غ�
			{
				p++;
				break;
			}
			temp += (*p - 'A' + 1);
			word[cnt][spell++] = *p++; // word �迭�� ���� ����
		}
		num_value[cnt] = temp; // num_value �迭�� �ܾ ���� ex) A = 1, ABILITY = 78 ...

		int n = 1, sum = 0;
		// n = �ﰢ�� ��ǥ, sum = n��° �ﰢ���� ��

		while (num_value[cnt] >= sum) // �ﰢ�� ��ġ ����
		{
			if (num_value[cnt] == sum)
			{
				goal++;
				break;
			}
			sum += n++;
		}

		//�� �ܾ��� ���� ���� �ʹٸ�, �Ʒ��� �ּ��� ����
		//printf("%s = %d\n", word[cnt], num_value[cnt]);
	}
	printf("���� : %d", goal);

	fclose(fp); // ���� �ݱ�

	return 0;
}