#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a;
	int arr[10000]; {};
	double sum = 0;
	int N = 100; //����������
	double l = 2; //����� �������
	double u = 5; // ������ �������
	int i = 0;
	int j = 0;


	double* mas2 = 0; // ��������� �� double 

	printf("N= \t");
	scanf_s("%d", &N);

	if (N <= 0)
	{
		printf("ERROR N<=0 \n");
		return 0;
	}


	printf("min = \t");
	scanf_s("%lf", &l);

	printf("max = \t");
	scanf_s("%lf", &u);

	if (u < l)
	{
		printf("ERROR max<min \n");
		return 0;
	}

	mas2 = (double*)malloc(N * sizeof(double)); //������������ ������ ������� N

	if (mas2 == 0)
	{
		printf("ERROR mas2 = 0\n");
		return 0;
	}


	for (int i = 0; i < N; i++)
	{
		mas2[i] = (((double)rand() / RAND_MAX) * (u - l) + l);
	}


	for (i = 0; i < N; i++) {
		sum = sum + mas2[i];
	}
	printf("summa vsex = %.3lf\n", sum);
	for (i = 0; i < N; i++) {
		a = ((mas2[i] - (int)(mas2[i]))*1000);
		arr[i] = a;
		while (arr[i] % 10 == 0)
			arr[i] = arr[i] / 10;
		for (int j = 0; j < N; j++)
			if (i == arr[j]) {
				sum = sum - fabs(mas2[i]);
			}

	}

	printf("sum = %.3lf\n", sum);

	free(mas2);

	return 0;
}