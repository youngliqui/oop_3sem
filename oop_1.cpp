#include <iostream>
/*
* 26. Заданы два массива A(m) и B(n). Подсчитать в них количество элементов, больших значения t
*	и первым на печать вывести массив, имеющий наибольшее их кол-во. 
*/

void createArray(double* arr, int length) {
    std::cout << "\nEnter array values:\n";
    for (int i = 0; i < length; i++) {
        std::cout << "arr[ " << (i + 1) << " ] = ";
        std::cin >> arr[i];
    }
}

int amountElementsEqualKey(double arr[], int length, double key) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] == key) {
            count++;
        }
    }
    return count;
}

int amountElementsEqualKeyWithPointer(double arr[], int length, double key) {
    int count = 0;
    for (double* ptr = arr; ptr < arr + length; ptr++) {
        if (key == *ptr) {
            count++;
        }
    }
    return count;
}

void createArrayWithPointer(double* arr, int length) {
    std::cout << "\nEnter array values:\n";
    for (int i = 0; i < length; i++) {
        std::cout << "arr[ " << (i + 1) << " ] = ";
        std::cin >> *(arr + i);
    }
}

void showArray(double arr[], int length) {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void showArrayWithPointer(double arr[], int length) {
    for (double* ptr = arr; ptr < arr + length; ptr++) {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Enter array length : ";
    int length = 0;
    std::cin >> length;

    if (length >= 0) {

        double* arr1 = new double[length];
        double* arr2 = new double[length];

        std::cout << "First Array:";
        createArray(arr1, length);
        std::cout << "Second Array:" ;
        createArrayWithPointer(arr2, length);

        std::cout << "\nEnter t = ";
        double key = 0;
        std::cin >> key;

        int count1 = amountElementsEqualKey(arr1, length, key);
        int count2 = amountElementsEqualKeyWithPointer(arr2, length, key);

        if (count2 > count1) {
            std::cout << "n = " << count2 << " array2: ";
            showArrayWithPointer(arr2, length);
            std::cout << "n = " << count1 << " array1: ";
            showArray(arr1, length);
        }
        else {
            std::cout << "n = " << count1 << " array1: ";
            showArray(arr1, length);
            std::cout << "n = " << count2 << " array2: ";
            showArrayWithPointer(arr2, length);
        }

        delete[] arr1, arr2;
    }
    else {
        std::cout << "invalid length value";
    }

    return 0;
}
