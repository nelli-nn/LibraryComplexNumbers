#ifndef COMPLEX_H
#define COMPLEX_H
#pragma once
/**
 * @mainpage ����������

Complex - ��� ���������� ��� ������ � ������������ �������. ��� ��������� �������������� ������ � ����������� ����� � �������, 
� ����� ������ �� ����� � ���������� � ����, ����������� ���������� �������������� ��������.

����������� ��������� �������� ���:

@code{.c}
#include "complex.h"

int main(void)
{
	int error;        // ���������� ��� ������ ������������ ��������� ������
	// ...            // ����� �� ������ ������� ���-������...
    return 0;
}
@endcode

����� ����������� ������ ��������� �������� ���:

@code
#include "complex.h"

int main(void)
{
    int error;
	double re = 12;
	double im = 56;
	complex_t num;

	//Creates complex number of complex_t type
	num = ComplexCreate;

	//Prints to screen
    ComplexPrint(&num);
    return 0;
}
@endcode

*/
/**
 * @brief ���������� ���.
 * ��������� ������� ���������� � ��������� ����������.
 *
 */
typedef enum {
	SUCCESS, ///< �������� ���������
	TRUE,    ///< ������
	FALSE    ///< ����
}error_t;
/**
 * @defgroup create_group Create Complex Number
 *
 * ������� ������������� � �������� ������������ �����.
 *
 * @{
 */
 /**
  * ��������� ������������� ����������.
  *
  */
typedef struct {
	double re; ///< �������������� ����� ������������ �����
	double im; ///< ������ ����� ������������ �����
} complex_t;


/**
 * @brief �������� ������������ �����.
 * 
 * ����� ������� � ������� ������������� ��������� ����������
�������� ����������� �����.
 *
 * @param re �������������� ����� ������������ �����.
 * @param im ������ ����� ������������ �����.
 *
 * @return @ref complex_t ���� �������� ������ �������.
 */
complex_t ComplexCreate(double re, double im);

/**
 * @brief ������� ����������� ����� �� ������.
 *
 * @param error ���������� ��� ��������� ������.
 * @param str ��������� �� ������.
 * @return @ref complex_t ���� �������� ������ �������.
 */

complex_t ComplexParse(char* str, int* error);

/**
 * @brief ������������ ������ ���� (a, b) � ����������� �����.
 *
 * @param str ��������� �� ������.
 * @param num ������ �������� �������.
 *
 * @return �����.
 */

double NumDouble(char const * str, int num);

/**
 * @brief ������������ ����� � ������.
 *
 * @param num ��������� �� ����������� �����.
 * @param error ���������� ��� ��������� ������.
 * @return ������.
 */

char* ComplexFormat(complex_t* num, int * error);

/**
 * @brief ������ ������ �� ����� � ������� ������������ �����.
 *
 * @param filename �������� �����. 
 * @param error ���������� ��� ��������� ������.
 * @param error ���������� ��� ��������� ������.
 * @return ������.
 */

complex_t ComplexRead(char* filename, int* error);

/**
 * @brief ������ ������ � ����.
 * @param error ���������� ��� ��������� ������.
 * @param filename �������� �����.
 * @param num ��������� �� ����������� �����.
 */
/** @}*/
void ComplexWrite(char* filename, complex_t* num, int * error);
/**
 * @defgroup ariphmetic_operations Ariphmetic operations
 *
 * ������� ���������� ������������� �������� � ������������ �������.
 *
 * @{
 */
/**
 * @brief ��������� ���� ����������� �����.
 *
 * @param num_one ��������� �� ������ ����������� �����.
 * @param num_two ��������� �� ������ ����������� �����.
 * @return ��������� ��������� ���� �����.
 */

complex_t ComplexMul(complex_t* num_one, complex_t* num_two);

/**
 * @brief ������� ���� ����������� �����.
 *
 * @param error ���������� ��� ��������� ������.
 * @param num_one ��������� �� ������ ����������� �����.
 * @param num_two ��������� �� ������ ����������� �����.
 * @return ��������� �������.
 */

complex_t ComplexDiv(complex_t* num_one, complex_t* num_two, int * error);

/**
 * @brief �������� ���� ����������� �����.
 *
 * @param num_one ��������� �� ������ ����������� �����.
 * @param num_two ��������� �� ������ ����������� �����.
 * @return ��������� ���������.
 */

complex_t ComplexSub(complex_t* num_one, complex_t* num_two);

/**
 * @brief ����� ���� ����������� �����.
 *
 * @param num_one ��������� �� ������ ����������� �����.
 * @param num_two ��������� �� ������ ����������� �����.
 * @return ��������� ������������.
 */

complex_t ComplexAdd(complex_t* num_one, complex_t* num_two);

/**
 * @brief ������� ������������� ����������� �����.
 *
 * @param num ��������� �� ����������� �����.
 *
 * @return ����������� �����.
 */

complex_t ComplexNegate(complex_t* num);

/**
 * @brief ������� �������� ����������� �����.
 *
 * @param num ��������� �� ����������� �����.
 *
 * @return ����������� �����.
 */

complex_t ComplexReciprocal(complex_t* num);

/**
 * @brief �������� ���������� �������� ������������ �����.
 *
 * 
 * @param num ��������� �� ����������� �����.
 *
 * @return ������ ������������ �����.
 */

double ComplexAbs(complex_t* num);

/**
 * @brief �������� �����, ����������� ������� ������������ �����.
 *
 * @param num ��������� �� ����������� �����.
 *
 * @return ����������� ����������� �����.
 */

complex_t ComplexConjugate(complex_t* num);

/**
 * @brief �������� �������� ������������ �����.
 *
 * @param num ��������� �� ����������� �����.
 *
 * @return �������� ������������ �����.
 */

double ComplexArg(complex_t* num);
/** @}*/
#endif /*COMPLEX_H_*/