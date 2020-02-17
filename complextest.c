#include "complex.h"
#include <locale.h>
#include <stdio.h>
#pragma warning(disable:4996)
int main(void)
{
	complex_t num;
	int error;
	int enter;
	char* arr;
	double re = 53.5698;
	double im = 12.123;
	double abs;
	double arg;
	char string[100];
	complex_t num_two = { 0, 0 };
	complex_t num_one = { 0, 0 };
	complex_t num_t = { 6, 4 };
	complex_t num_o = { 2, 3 };
	complex_t number;
	char str[100] = "(12.456, 435.7)";
	error = FALSE;
	setlocale(LC_ALL, "Russian");
	number = ComplexParse(str, &error);
	if (error == FALSE) {
		printf("�����, ���������� �� ������: ");
		printf("(%g, %g)\n", number.re, number.im);
	}
	printf("\n");
	num = ComplexCreate(re, im);
	num = ComplexAdd(&num_one, &num_two);
	printf("����� ���� �����: ");
	printf("(%g, %g)\n", num.re, num.im);
	printf("\n");
	num = ComplexSub(&num_one, &num_two);
	printf("�������� ���� �����: ");
	printf("(%g, %g)\n", num.re, num.im);
	printf("\n");
	num = ComplexMul(&num_o, &num_t);
	printf("������������ ���� �����: ");
	printf("(%g, %g)\n", num.re, num.im);
	printf("\n");
	num = ComplexSub(&num_o, &num_t);
	printf("�������� ���� �����(������): ");
	printf("(%g, %g)\n", num.re, num.im);
	printf("\n");
	num = ComplexCreate(re, im);
	if (error == FALSE) {
		printf("������ � ����: ");
		printf("(%g, %g)\n", num.re, num.im);
		ComplexWrite("complexone.txt", &num, &error);
	}
	printf("\n");
	if (error == FALSE) {
		printf("������ �� �����: ");
		num = ComplexRead("complexone.txt", &error);
	}
	if (error == FALSE) {
		printf("(%g, %g)\n", num.re, num.im);
	}
	printf("\n");
	printf("�����, �������� ������� ������������ �����: ");
	num = ComplexReciprocal(&num);
	printf("(%g, %g)\n", num.re, num.im);
	printf("\n");
	printf("�����, ��������������� ������� ������������ �����: ");
	num = ComplexNegate(&num);
	printf("(%g, %g)\n", num.re, num.im);
	printf("\n");
	printf("�����, ����������� ������� ������������ �����: ");
	num = ComplexConjugate(&num);
	printf("(%g, %g)\n", num.re, num.im);
	printf("\n");
	printf("��������� ������� ���� �����: ");
	num = ComplexDiv(&num_one, &num_two, &error);
	if (error == FALSE) {
		printf("(%lf, ", num.re);
		printf("%lf)", num.im);
	}
	printf("\n");
	printf("������� ���� ����� 6+4i � 2+3i: ");
	num = ComplexDiv(&num_o, &num_t, &error);
	if (error == FALSE) {
		printf("(%lf, ", num.re);
		printf("%lf)\n", num.im);
	}
	printf("\n");
	printf("������ ������������ �����: ");
	abs = ComplexAbs(&num_t);
	printf("%g\n", abs);
	printf("\n");
	printf("�������� ������������ �����: ");
	arg = ComplexArg(&num_o);
	printf("%g\n", arg);
  printf("\n");
	printf("���� �� ������ �������������� ������ ������(�� ����� 100 ��������), ������� 1, � ���� ������ ������� 0\n");
	scanf("%i\n", &enter);
	if (enter == 1) {
		do {
			gets(string);
			number = ComplexParse(string, &error);
			if (error == FALSE) {
				printf("�����, ���������� �� ������: ");
				printf("(%g, %g)\n", number.re, number.im);
			}
			printf("\n");
		} while (error == TRUE);
	}
	return 0;
} 