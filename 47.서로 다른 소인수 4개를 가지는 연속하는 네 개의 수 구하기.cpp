#include <stdio.h>

#define MAX 1000000
int num[MAX] = { 0 };

int main()
{
	for (int i = 2; i <= MAX; i++) {
		if (num[i] == 0) { // i==0, ��, i�� �Ҽ��̸� i�� ����� �Ǵ� �׸�鿡 1�� �����ش�.
			//���� ��� i�� 3�̸� i = 3 , 6, 9, 12, 15, ... �� �� 1�� �����ش�.
			for (int j = i; j <= MAX; j += i) {
				num[j]++;
			}
		}
	}

	for (int i = 2; i <= MAX; i++) { // i�� �����ؼ� �� ���� ���μ��� ���� �� ����ϰ� main �Լ� ����
		if (num[i] == 4) {
			if (num[i + 1] == 4) {
				if (num[i + 2] == 4) {
					if (num[i + 3] == 4) {
						printf("%d", i);
						return 0;
					}
					else { i += 3; }
				}
				else { i += 2; }
			}
			else { i++; }
		}
	}
}