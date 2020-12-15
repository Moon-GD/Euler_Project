// �ڸ����� ������ Ǫ�� ����� ������ �� ����
// ex) 5~10�ڸ� ���� ���� ������ �����Ǵ� �� ���� 1~4�ڸ��� ���� �����غ��� ����

#include<stdio.h>
#include<math.h> // pow

int array[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
long long sum = 0;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void find(int* array)
{
    if (array[0] == 0) return; // ù �ڸ� 0 �Ұ�
    if (array[3] % 2 != 0) return; // 2���
    if (array[5] % 5 != 0) return; // 5���
    if ((array[2] + array[3] + array[4]) % 3 != 0) return; //3���
    if ((array[4] * 100 + array[5] * 10 + array[6]) % 7 != 0) return; // 7���
    if ((array[5] * 100 + array[6] * 10 + array[7]) % 11 != 0) return; // 11���
    if ((array[6] * 100 + array[7] * 10 + array[8]) % 13 != 0) return; // 13���
    if ((array[7] * 100 + array[8] * 10 + array[9]) % 17 != 0) return; // 17���
    
    long long temp = 0;

    for (int j = 0; j < 10; j++)
        temp += array[j] * pow(10, 9 - j);

    sum += temp;
}

void Permutation(int n, int r, int depth) // ����
{
    if (r == depth)
    {
        find(array);
        return;
    }

    for (int i = depth; i < n; i++)
    {
        swap(&array[i], &array[depth]);
        Permutation(n, r, depth + 1);
        swap(&array[i], &array[depth]);
    }
}



int main()
{
    Permutation(10, 10, 0);
    printf("%lld", sum);
    return 0;
}