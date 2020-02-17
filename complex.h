#ifndef COMPLEX_H
#define COMPLEX_H
#pragma once
/**
 * @mainpage Вступление

Complex - это библиотека для работы с комплексными числами. Она позволяет конвертировать строку в комплексное число и обратно, 
а также читать из файла и записывать в него, производить простейшие арифметические операции.

Минимальная программа выглядит так:

@code{.c}
#include "complex.h"

int main(void)
{
	int error;        // Переменная для оценки корректности введенных данных
	// ...            // Здесь вы можете сделать что-нибудь...
    return 0;
}
@endcode

Более осмысленная версия программы выглядит так:

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
 * @brief Логический тип.
 * Параметры условий истинности и успешного выполнения.
 *
 */
typedef enum {
	SUCCESS, ///< успешное окончание
	TRUE,    ///< истина
	FALSE    ///< ложь
}error_t;
/**
 * @defgroup create_group Create Complex Number
 *
 * Функции инициализации и создании комплексного числа.
 *
 * @{
 */
 /**
  * Параметры инициализации библиотеки.
  *
  */
typedef struct {
	double re; ///< действительная часть комплексного числа
	double im; ///< мнимая часть комплексного числа
} complex_t;


/**
 * @brief Создание комплексного числа.
 * 
 * Перед работой с другими библиотечными функциями необходимо
 создать комплексное число.
 *
 * @param re действительная часть комплексного числа.
 * @param im мнимая часть комплексного числа.
 *
 * @return @ref complex_t если создание прошло успешно.
 */
complex_t ComplexCreate(double re, double im);

/**
 * @brief Создает комплексное число из строки.
 *
 * @param error переменная для обработки ошибок.
 * @param str указатель на строку.
 * @return @ref complex_t если создание прошло успешно.
 */

complex_t ComplexParse(char* str, int* error);

/**
 * @brief Конвертирует строку вида (a, b) в комплексное число.
 *
 * @param str указатель на строку.
 * @param num индекс элемента массива.
 *
 * @return число.
 */

double NumDouble(char const * str, int num);

/**
 * @brief Конвертирует число в строку.
 *
 * @param num указатель на комплексное число.
 * @param error переменная для обработки ошибок.
 * @return строку.
 */

char* ComplexFormat(complex_t* num, int * error);

/**
 * @brief Чтение данных из файла и возврат комплексного числа.
 *
 * @param filename название файла. 
 * @param error переменная для обработки ошибок.
 * @param error переменная для обработки ошибок.
 * @return строку.
 */

complex_t ComplexRead(char* filename, int* error);

/**
 * @brief Запись данных в файл.
 * @param error переменная для обработки ошибок.
 * @param filename название файла.
 * @param num указатель на комплексное число.
 */
/** @}*/
void ComplexWrite(char* filename, complex_t* num, int * error);
/**
 * @defgroup ariphmetic_operations Ariphmetic operations
 *
 * Функции простейших арифметичеких операций с комплексными числами.
 *
 * @{
 */
/**
 * @brief Умножение двух комплексных чисел.
 *
 * @param num_one указатель на первое комплексное число.
 * @param num_two указатель на второе комплексное число.
 * @return результат умножения двух чисел.
 */

complex_t ComplexMul(complex_t* num_one, complex_t* num_two);

/**
 * @brief Деление двух комплексных чисел.
 *
 * @param error переменная для обработки ошибок.
 * @param num_one указатель на первое комплексное число.
 * @param num_two указатель на второе комплексное число.
 * @return результат деления.
 */

complex_t ComplexDiv(complex_t* num_one, complex_t* num_two, int * error);

/**
 * @brief Разность двух комплексных чисел.
 *
 * @param num_one указатель на первое комплексное число.
 * @param num_two указатель на второе комплексное число.
 * @return результат вычитания.
 */

complex_t ComplexSub(complex_t* num_one, complex_t* num_two);

/**
 * @brief Сумма двух комплексных чисел.
 *
 * @param num_one указатель на первое комплексное число.
 * @param num_two указатель на второе комплексное число.
 * @return результат суммирования.
 */

complex_t ComplexAdd(complex_t* num_one, complex_t* num_two);

/**
 * @brief Создаем противоложное комплексное число.
 *
 * @param num указатель на комплексное число.
 *
 * @return комплексное число.
 */

complex_t ComplexNegate(complex_t* num);

/**
 * @brief Создает обратное комлпексное число.
 *
 * @param num указатель на комплексное число.
 *
 * @return комплексное число.
 */

complex_t ComplexReciprocal(complex_t* num);

/**
 * @brief Получает абсолютное значение комплексного числа.
 *
 * 
 * @param num указатель на комплексное число.
 *
 * @return модуль комплексного числа.
 */

double ComplexAbs(complex_t* num);

/**
 * @brief Получает число, сопряженное данному комплексному числу.
 *
 * @param num указатель на комплексное число.
 *
 * @return сопряженное комплексное число.
 */

complex_t ComplexConjugate(complex_t* num);

/**
 * @brief Получает аргумент комплексного числа.
 *
 * @param num указатель на комплексное число.
 *
 * @return аргумент комплексного числа.
 */

double ComplexArg(complex_t* num);
/** @}*/
#endif /*COMPLEX_H_*/