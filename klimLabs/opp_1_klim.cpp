#include <iostream>

//12.Заданы два массива А(m) и В(n). В каждом из массивов найти наибольшее значение и вычесть его из всех элементов массивов.
//   На печать вывести исходные и преобразованные массивы.

using namespace std;

// поиск максимального значения в массиве при помощи указателя
int searchMax(int array[], int length) {
	int maxValue = array[0];
	for (int* ptr = array + 1; ptr < array + length; ptr++) {
		if (*ptr > maxValue) {
			maxValue = *ptr;
		}
	}

	return maxValue;
}

// вывод массива на экран c помощью указателя
void show(int array[], int length) {
	for (int* ptr = array; ptr < array + length; ptr++) {
		cout << *ptr << " ";
	}
}

// вычитание макимального элемента из всех элементов массива
void subtracting(int* array, int length, int max) {
	for (int i = 0; i < length; i++) {
		array[i] -= max;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");

	int lengthA = 0;
	cout << "Введите размер массива A: ";
	cin >> lengthA;

	int lengthB = 0;
	cout << "Введите размер массива B: ";
	cin >> lengthB;

	// создание двух динамических массивов размера lengthA и lengthB
	int* arrA = new int[lengthA];
	int* arrB = new int[lengthB];

	// заполенение массива A с помощью обращения по индексу
	cout << "Заполнение массива A:" << endl;
	for (int i = 0; i < lengthA; i++) {
		cout << "arrA[" << (i + 1) << "] = ";
		cin >> arrA[i];
	}

	// заполнение массива B с помощью указателя
	cout << "Заполнение массива B:" << endl;
	for (int i = 0; i < lengthB; i++) {
		cout << "arrB[" << (i + 1) << "] = ";
		cin >> *(arrB + i);
	}

	// нахождение максимального значения для массивов A и B
	int maxA = searchMax(arrA, lengthA);
	int maxB = searchMax(arrB, lengthB);

	//вывод на экран исходных массивов A и B
	cout << "Исходные массивы:" << endl;
	cout << "A = {";
	show(arrA, lengthA);
	cout << "}" << endl;

	cout << "B = {";
	show(arrB, lengthB);
	cout << "}" << endl;

	// вычитание максимального элемента из всех элементов массива
	subtracting(arrA, lengthA, maxA);
	subtracting(arrB, lengthB, maxB);

	// вывод на экран преобразованных массивов
	cout << "Преобразованные массивы:" << endl;
	cout << "A = {";
	show(arrA, lengthA);
	cout << "}" << endl;

	cout << "B = {";
	show(arrB, lengthB);
	cout << "}" << endl;

	// удаление массивов
	delete[] arrA, arrB;

	return 0;
}