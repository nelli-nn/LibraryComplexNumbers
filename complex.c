#include "complex.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

complex_t ComplexCreate(double re, double im)
{
	complex_t complex;
	complex.re = re;
	complex.im = im;
	return complex;
}
char* GetLine() {
	int ch;
	int size = 1, val = 0;
	char* arr = (char*)malloc(sizeof(char) * 0);
	char* str = NULL;
	if (arr == NULL) {
		free(arr);
		printf("ERROR: memory \n");
		return str;
	}
	while ((ch = fgetc(stdin)) != '\n') {
		arr = (char*)realloc(arr, sizeof(char) * (size + 1));
		if (arr == NULL) {
			free(arr);
			printf("ERROR: memory \n");
			return str;
		}
		size++;
		arr[val] = (char)ch;
		val++;
	}
	arr[val] = '\0';
	if (val != 0) {
		str = arr;
		return str;
	}
	else if (ch == '\n') {
		arr = (char*)realloc(arr, sizeof(char) * (size + 1));
		if (arr == NULL) {
			free(arr);
			printf("ERROR: memory \n");
			return str;
		}
		arr[val] = '\n';
		arr[val++] = '\0';
		str = arr;
		return str;
	}
	else {
		free(arr);
		return str;
	}
}
int CharNumber(char const * str, int num) {
	int number;
	switch (str[num]) {
	case '0':
		number = 0;
		break;
	case '1':
		number = 1;
		break;
	case '2':
		number = 2;
		break;
	case '3':
		number = 3;
		break;
	case '4':
		number = 4;
		break;
	case '5':
		number = 5;
		break;
	case '6':
		number = 6;
		break;
	case '7':
		number = 7;
		break;
	case '8':
		number = 8;
		break;
	case '9':
		number = 9;
		break;
	}
	return number;
}

double CharDouble(char const * arr, int num) {
	int i = 0, razryad = 0, index = 0, j;
	double rezult;
	double schet = 0;
	double mul;
	double d_rezult = 0;
	int point = 0;
	int * str;
	str = malloc(sizeof(int));
	if (str == NULL) {
		printf("ERROR: memory\n");
		return !0;
	}
	while (arr[num] >= '0' && arr[num] <= '9' && point == 0) {
		str[i] = CharNumber(arr, num);
		razryad++;
		i++;
		str = realloc(str, sizeof(int) * (i + 1));
		if (str == NULL) {
			printf("ERROR: memory\n");
			return !0;
		}
		num++;
	}
	if (arr[num] == '.') {
		d_rezult = NumDouble(arr, num);
	}
	for (index = 0, mul = 1, j = (i - 1); index < razryad, j >= 0; index++, j--, mul *= 10) {
		schet += str[j] * mul;
	}
	rezult = schet + d_rezult;
	free(str);
	return rezult;
}
double NumDoubleF(char const * str, int num) {
	int k = 0, j = 0, index = 0;
	int razryad_double = 0;
	double rezult = 0, schet = 0, mul = 0;
	int * double_str;
	double_str = malloc(sizeof(int));
	if (double_str == NULL) {
		printf("ERROR: memory");
		return !0;
	}
	if (str[num] == ',') {
		num++;
		while (str[num] >= '0' && str[num] <= '9') {
			double_str[k] = CharNumber(str, num);
			razryad_double++;
			k++;
			double_str = realloc(double_str, sizeof(int) * (k + 1));
			if (double_str == NULL) {
				printf("ERROR");
				return !0;
			}
			num++;
		}
	}
	for (index = 0, schet = 0, mul = 0.1, j = 0; index <= razryad_double, j != k; index++, j++, mul /= 10) {
		schet += double_str[j] * mul;
	}
	rezult += schet;
	free(double_str);
	return rezult;
}
double CharDoubleF(char const * arr, int num) {
	int i = 0, razryad = 0, index = 0, j;
	double rezult;
	double schet = 0;
	double mul;
	double d_rezult = 0;
	int point = 0;
	int * str;
	str = malloc(sizeof(int));
	if (str == NULL) {
		printf("ERROR: memory\n");
		return !0;
	}
	while (arr[num] >= '0' && arr[num] <= '9' && point == 0) {
		str[i] = CharNumber(arr, num);
		razryad++;
		i++;
		str = realloc(str, sizeof(int) * (i + 1));
		if (str == NULL) {
			printf("ERROR: memory\n");
			return !0;
		}
		num++;
	}
	if (arr[num] == ',') {
		d_rezult = NumDoubleF(arr, num);
	}
	for (index = 0, mul = 1, j = (i - 1); index < razryad, j >= 0; index++, j--, mul *= 10) {
		schet += str[j] * mul;
	}
	rezult = schet + d_rezult;
	free(str);
	return rezult;
}

double NumDouble(char const * str, int num) {
	int k = 0, j = 0, index = 0;
	int razryad_double = 0;
	double rezult = 0, schet = 0, mul = 0;
	int * double_str;
	double_str = malloc(sizeof(int));
	if (double_str == NULL) {
		printf("ERROR: memory");
		return !0;
	}
	if (str[num] == '.') {
		num++;
		while (str[num] >= '0' && str[num] <= '9') {
			double_str[k] = CharNumber(str, num);
			razryad_double++;
			k++;
			double_str = realloc(double_str, sizeof(int) * (k + 1));
			if (double_str == NULL) {
				printf("ERROR");
				return !0;
			}
			num++;
		}
	}
	for (index = 0, schet = 0, mul = 0.1, j = 0; index <= razryad_double, j != k; index++, j++, mul /= 10) {
		schet += double_str[j] * mul;
	}
	rezult += schet;
	free(double_str);
	return rezult;
}

char NumberChar(int symb) {
	char number;
	switch (symb) {
	case 0:
		number = '0';
		break;
	case 1:
		number = '1';
		break;
	case 2:
		number = '2';
		break;
	case 3:
		number = '3';
		break;
	case 4:
		number = '4';
		break;
	case 5:
		number = '5';
		break;
	case 6:
		number = '6';
		break;
	case 7:
		number = '7';
		break;
	case 8:
		number = '8';
		break;
	case 9:
		number = '9';
		break;
	}
	return number;
}
int ErrorString(int* error, char* str) {
	int i = 0, j = 0, one = 0;
	if (str[i] != '(') {
		*error = TRUE;
		return TRUE;
	}
	for (i = 1; str[i] != ','; i++) {
		if (((str[i] >= '0' && str[i] <= '9') || (str[i] == '.' && one == 0)))
			*error = FALSE;
		else {
			*error = TRUE;
			return TRUE;
		}
		j = i - 1;
		if (str[i] == '.') {
			one++;
			if (str[j] >= '0' && str[j] <= '9') {
				*error = FALSE;
			}
			else {
				*error = TRUE;
				return TRUE;
			}
			j = i + 1;
			if (str[j] >= '0' && str[j] <= '9') {
				*error = FALSE;
			}
			else {
				*error = TRUE;
				return TRUE;
			}
		}
	}
	i++;
	if (str[i] != ' ') {
		*error = TRUE;
		return TRUE;
	}
	i++;
	one = 0;
	for (i; str[i] != ')'; i++) {
		if (((str[i] >= '0' && str[i] <= '9') || (str[i] == '.' && one == 0)))
			*error = FALSE;
		else {
			*error = TRUE;
			return TRUE;
		}
		j = i - 1;
		if (str[i] == '.') {
			one++;
			if (str[j] >= '0' && str[j] <= '9') {
				*error = FALSE;
			}
			else {
				*error = TRUE;
				return TRUE;
			}
			j = i + 1;
			if (str[j] >= '0' && str[j] <= '9') {
				*error = FALSE;
			}
			else {
				*error = TRUE;
				return TRUE;
			}
		}
	}
	if (str[i] != ')') {
		*error = TRUE;
		return TRUE;
	}
	else {
		i++;
		if (str[i] != '\0') {
			*error = TRUE;
			return TRUE;
		}
	}
	*error = FALSE;
	return 0;
}
int ErrorStringF(int* error, char* str) {
	int i = 0, j = 0, one = 0;
	if (str[i] != '(') {
		*error = TRUE;
		return TRUE;
	}
	for (i = 1; str[i] != ' '; i++) {
		if (((str[i] >= '0' && str[i] <= '9') || (str[i] == ',' && one == 0)))
			*error = FALSE;
		else {
			if(str[i + 1] != ' '){
				*error = TRUE;
				return TRUE;
			}
		}
		j = i - 1;
		if (str[i] == ',') {
			one++;
			if (str[j] >= '0' && str[j] <= '9') {
				*error = FALSE;
			}
			else {
				*error = TRUE;
				return TRUE;
			}
			j = i + 1;
			if (str[j] >= '0' && str[j] <= '9') {
				*error = FALSE;
			}
			else if (!(str[i + 1] == ' ' && str[i] == ',')){
				*error = TRUE;
				return TRUE;
			}
		}
	}
	i--;
	if (str[i] != ',') {
		*error = TRUE;
		return TRUE;
	}
	i = i + 1;
	if (str[i] != ' ') {
		*error = TRUE;
		return TRUE;
	}
	i++;
	one = 0;
	for (i; str[i] != ')'; i++) {
		if (((str[i] >= '0' && str[i] <= '9') || (str[i] == ',' && one == 0)))
			*error = FALSE;
		else {
			*error = TRUE;
			return TRUE;
		}
		j = i - 1;
		if (str[i] == ',') {
			one++;
			if (str[j] >= '0' && str[j] <= '9') {
				*error = FALSE;
			}
			else {
				*error = TRUE;
				return TRUE;
			}
			j = i + 1;
			if (str[j] >= '0' && str[j] <= '9') {
				*error = FALSE;
			}
			else {
				*error = TRUE;
				return TRUE;
			}
		}
	}
	if (str[i] != ')') {
		*error = TRUE;
		return TRUE;
	}
	else {
		i++;
		if (str[i] != '\0') {
			*error = TRUE;
			return TRUE;
		}
	}
	*error = FALSE;
	return 0;
}
complex_t ComplexParse(char * str, int * error) {
	//char* str;
	int i = 0, var = 0;
	int re = 0;
	int mistake;
	int minus = 0;
	complex_t complex = { 0, 0 };
	//str = GetLine();
	mistake = ErrorString(error, str);
	if (*error == TRUE) {
		printf("ERROR: input\n");
		return complex;
	}
	for (i = 0; str[i] != '\0'; ) {
		if (str[i] == '(')
			i++;
		if (re == 0) {
			complex.re = CharDouble(str, i);
			re++;
			while (str[i] != ',')
				i++;
		}
		do {
			i++;
		} while (!(str[i] >= '0' && str[i] <= '9'));
		complex.im = CharDouble(str, i);
		while (str[i] != ')')
			i++;
		i++;
	}
	return complex;
}
complex_t ComplexParseF(char * str, int * error) {
	//char* str;
	int i = 0, var = 0;
	int re = 0;
	int mistake;
	int minus = 0;
	complex_t complex = { 0, 0 };
	//str = GetLine();
	mistake = ErrorStringF(error, str);
	if (*error == TRUE) {
		printf("ERROR: input\n");
		return complex;
	}
	for (i = 0; str[i] != ')'; ) {
		if (str[i] == '(')
			i++;
		if (re == 0) {
			complex.re = CharDoubleF(str, i);
			re++;
			while (str[i] != ' ')
				i++;
		}
		i--;
		do {
			i++;
		} while (!(str[i] >= '0' && str[i] <= '9'));
		complex.im = CharDoubleF(str, i);
		while (str[i] != ')')
			i++;
		break;
	}
	return complex;
}
char* ComplexFormat(complex_t* complex, int* error) {
	double mod;
	int temp;
	int number = 0;
	int chislo;
	double num = 10;
	int index = 0, i = 0;
	int value;
	int cian;
	char* str;
	char* arr;
	int variable = 8;
	int j;
	int var = 0;
	int raz = 0;
	(char*)str = (char*)malloc(sizeof(char));
	if (str == NULL) {
		printf("ERROR: memory\n");
		*error = TRUE;
	}
	str[i] = ')';
	i++;
	(char*)str = (char*)realloc(str, sizeof(char) * (i + 1));
	if (str == NULL) {
		printf("ERROR: memory\n");
		*error = TRUE;
	}
	number = (int)complex->im;
	mod = complex->im - number;
	if (mod != 0) {
		raz = 0;
		do {
			mod = mod * num;
			cian = (int)mod % 10;
			index++;
			raz++;
		} while ((cian != 0 && raz != 5));
		mod = mod / 10;
		chislo = (int)mod;
		for (chislo; chislo != 0; chislo /= 10) {
			value = chislo % 10;
			str[i] = NumberChar(value);
			i++;
			(char*)str = (char*)realloc(str, sizeof(char) * (i + 1));
			if (str == NULL) {
				printf("ERROR: memory\n");
				*error = TRUE;
			}
		}
		str[i] = '.';
		i++;
		(char*)str = (char*)realloc(str, sizeof(char) * (i + 1));
		if (str == NULL) {
			printf("ERROR: memory\n");
			*error = TRUE;
		}
	}
	chislo = (int)complex->im;
	if (chislo == 0) {
		str[i] = '0';
		i++;
		(char*)str = (char*)realloc(str, sizeof(char) * (i + 1));
		if (str == NULL) {
			printf("ERROR: memory\n");
			*error = TRUE;
		}
	}
	for (chislo; chislo != 0; chislo /= 10) {
		value = chislo % 10;
		str[i] = NumberChar(value);
		i++;
		(char*)str = (char*)realloc(str, sizeof(char) * (i + 1));
		if (str == NULL) {
			printf("ERROR: memory\n");
			*error = TRUE;
		}
	}
	(char*)arr = (char*)malloc(sizeof(char) * i);
	if (arr == NULL) {
		printf("ERROR\n");
		*error = TRUE;
	}
	value = i - 1;
	temp = i - 1;
	for (value, j = 0; value >= 0; value--, j++) {
		arr[j] = str[value];
	}
	(char*)arr = (char*)realloc(arr, sizeof(char) * i);
	if (str == NULL) {
		printf("ERROR: memory\n");
		*error = TRUE;
	}
	index = i - 1;
	temp = i - 2;
	for (index, j = temp; index >= (temp + 1); index--, j++) {
		arr[j] = str[index];
	}
	str[i] = ' ';
	(char*)str = (char*)realloc(str, sizeof(char) * (i + 2));
	if (str == NULL) {
		printf("ERROR: memory\n");
		*error = TRUE;
	}
	i++;
	str[i] = ',';
	i++;
	(char*)str = (char*)realloc(str, sizeof(char) * (i + 1));
	if (str == NULL) {
		printf("ERROR: memory\n");
		*error = TRUE;
	}
	number = (int)complex->re;
	mod = complex->re - number;
	if (mod != 0) {
		raz = 0;
		do {
			mod = mod * num;
			cian = (int)mod % 10;
			index++;
			raz++;
		} while ((cian != 0 && raz != 5));
		mod = mod / 10;
		cian = -1;
		chislo = (int)mod;
		for (chislo; chislo != 0; chislo /= 10) {
			value = chislo % 10;
			str[i] = NumberChar(value);
			i++;
			(char*)str = (char*)realloc(str, sizeof(char) * (i + 1));
			if (str == NULL) {
				printf("ERROR: memory\n");
				*error = TRUE;
			}
		}
		str[i] = '.';
		i++;
		(char*)str = (char*)realloc(str, sizeof(char) * (i + 1));
		if (str == NULL) {
			printf("ERROR: memory\n");
			*error = TRUE;
		}
	}
	chislo = (int)complex->re;
	if (chislo == 0) {
		str[i] = '0';
		i++;
		(char*)str = (char*)realloc(str, sizeof(char) * (i + 1));
		if (str == NULL) {
			printf("ERROR: memory\n");
			*error = TRUE;
		}
	}
	for (chislo; chislo != 0; chislo /= 10) {
		value = chislo % 10;
		str[i] = NumberChar(value);
		i++;
		var++;
		(char*)str = (char*)realloc(str, sizeof(char) * (i + 1));
		if (str == NULL) {
			printf("ERROR: memory\n");
			*error = TRUE;
		}
	}
	(char*)arr = (char*)realloc(arr, sizeof(char) * i);
	if (str == NULL) {
		printf("ERROR: memory\n");
		*error = TRUE;
	}
	str[i] = '(';
	i++;
	(char*)str = (char*)realloc(str, sizeof(char) * (i + 1));
	if (str == NULL) {
		printf("ERROR: memory\n");
		*error = TRUE;
	}
	str[i] = '\0';
	i = i - 1;
	for (i, j = 0; i >= 0; i--, j++) {
		arr[j] = str[i];
	}
	arr[j] = '\0';
	return arr;
}
void ComplexWrite(char* filename, complex_t* num, int * error) {
	errno_t err;
	FILE* stream;
	err = fopen_s(&stream, filename, "a");
	if (err != 0) {
		printf("ERROR\n");
		*error = TRUE;
	}
	else {
		fprintf(stream, "(%lf, %lf)\n", num->re, num->im);
	}
	fclose(stream);
}

complex_t ComplexRead(char* filename, int * error) {
	FILE* file;
	errno_t err;
	complex_t complex = { 0, 0 };
	int size = 10, delta = 10, i = 0;
	char* buf = (char*)malloc(sizeof(char) * size);
	err = fopen_s(&file, filename, "r");
	if (err == 0) {
		while (((buf[i] = fgetc(file)) != EOF && buf[i] != '\n') && buf[i - 1] != ')') {
			i++;
			if (i >= size) {
				size += delta;
				buf = (char*)realloc(buf, sizeof(char) * size);
			}
		}
		fclose(file);
		buf[i] = '\0';
		complex = ComplexParseF(buf, error);
		free(buf);
	}
	else{
		printf("ERROR: no such file in directory\n");
		*error = TRUE;
    }
	return complex;
}

complex_t ComplexAdd(complex_t* num_one, complex_t* num_two)
{
	complex_t num;
	num.re = num_one->re + num_two->re;
	num.im = num_one->im + num_two->im;
	return num;
}
complex_t ComplexSub(complex_t* num_one, complex_t* num_two)
{
	complex_t num;
	num.re = num_one->re - num_two->re;
	num.im = num_one->im - num_two->im;
	return num;
}
complex_t ComplexMul(complex_t* num_one, complex_t* num_two)
{
	complex_t num;
	num.re = num_one->re * num_two->re - num_one->im * num_two->im;
	num.im = num_one->re * num_two->im + num_two->re * num_one->im;
	return num;
}
complex_t ComplexDiv(complex_t* num_one, complex_t* num_two, int *error)
{
	complex_t num = { 0, 0 };
	if (num_one->re == 0 && num_one->im == 0 && num_two->re == 0 && num_two->im == 0) {
		printf("ERROR: division by zero\n");
		*error = TRUE;
		return num;
	}
	*error = FALSE;
	num.re = (num_one->re * num_two->re + num_one->im * num_two->im) / (num_two->re*num_two->re + num_two->im * num_two->im);
	num.im = (-num_one->re * num_two->im + num_one->im * num_two->re) / (num_two->re*num_two->re + num_two->im * num_two->im);
	return num;
}

complex_t ComplexNegate(complex_t* num) {
	complex_t number;
	number.re = -num->re;
	number.im = -num->im;
	return number;
}

complex_t ComplexReciprocal(complex_t* num) {
	complex_t number;
	number.re = num->re / (num->re * num->re + num->im * num->im);
	number.im = -num->im / (num->re * num->re + num->im * num->im);
	if (num->re == 0 && num->im == 0) {
		number.re = 0;
		number.im = 0;
	}
	return number;
}

double ComplexAbs(complex_t* num) {
	double abs;
	if (num->re > num->im)
		abs = num->re * sqrt((1 + num->im * num->im / (num->re * num->re)));
	else if (num->im > num->re)
		abs = num->im * sqrt((1 + num->re * num->re / (num->im * num->im)));
	else
		abs = 0;
	return abs;
}

double ComplexArg(complex_t* num) {
	double arg = 0;
	double pi = 3.14;
	if (num->re > 0)
		arg = atan(num->im / num->re);
	else if (num->re < 0 && num->im >= 0)
		arg = atan(num->im / num->re) + pi;
	else if (num->re < 0 && num->im < 0)
		arg = atan(num->im / num->re) - pi;
	else if (num->re = 0 && num->im > 0)
		arg = pi / 2;
	else if (num->re = 0 && num->im < 0)
		arg = -pi / 2;
	else {
		arg = 0;
	}
	return arg;
}
complex_t ComplexConjugate(complex_t * num) {
	complex_t number;
	number.re = num->re;
	number.im = -num->im;
	return number;
}