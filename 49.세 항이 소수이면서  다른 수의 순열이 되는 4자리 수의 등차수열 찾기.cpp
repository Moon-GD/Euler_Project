#include<stdio.h>
#include<math.h> // sqrt
int array[11] = { 0,1,2,3,4,5,6,7,8,9 };

int target[600] = { 0 }; // Permutation(10,4)���� �Ҽ� �迭
int i = 0; // Permutation(10,4)���� �Ҽ� �迭�� ��ǥ

int divide(int a, int b, int c) {
	int A[5] = { 0 }, B[5] = { 0 }, C[5] = { 0 };
	int j = 0;
	for (int i = 1; i <= 4; i++) {
		A[j] = a % 10, a /= 10;
		B[j] = b % 10, b /= 10;
		C[j] = c % 10, c /= 10;
		j++;
	}

}

int isPrime(int i) { // �Ҽ� �Ǻ�
	for (int j = 2; j <= sqrt(i); j++) {
		if (i % j == 0) {
			return 0;
		}
	}
	return 1;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b, *b = temp;
	return;
}

void Permutation(int n, int r, int depth)
{
	int sum = array[0] * 1000 + array[1] * 100 + array[2] * 10 + array[3];
	if (r == depth) {
		if (isPrime(sum)) {
			if (sum < 1000)
				return;

			target[i++] = sum;
		}
		return;
	}


	for (int i = depth; i < n; i++) {
		swap(&array[i], &array[depth]);
		Permutation(n, r, depth + 1);
		swap(&array[i], &array[depth]);
	}
}

int main()
{
	Permutation(10, 4, 0);
	
	/* ����ϱ�
	for (int i = 0; i<510; i++) {
		printf("%d %d��\n", target[i], i+1);
	}
	*/

	for (int a = 0; a <= 507; a++) {
		for (int c = a + 2; c <= 509; c++) {
			for (int b = a + 1; b < c; b++) {
				if (target[a] + target[b] + target[c] == 3 * target[a] || 
					target[a] + target[b] + target[c] == 3 * target[b] ||
					target[a] + target[b] + target[c] == 3 * target[c]) {
					int p_array[10];
					printf("%d ��° %d %d %d\n", a+1 , target[a], target[b], target[c]);
				}
			}
		}
	}

	return 0;
}