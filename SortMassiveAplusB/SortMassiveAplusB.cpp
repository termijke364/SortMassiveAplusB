#include <iostream>
#include <algorithm>

using namespace std;

unsigned int tm = time(NULL);

void CreateMassive(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        *(arr + i) = rand() % 20 + 1;
}

void PrintMassive(int* arr, int size)
{
    srand(++tm);
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << ' ';

    cout << endl;
}

void JoinMassive(int* arr1, int size1, int* arr2, int size2, int* arr3, int size3)
{
    int i = 0, j = 0, k = 0;;
    for (; i < size1 && j < size2; k++)
    {
        if (*(arr1 + i) < *(arr2 + j))
        {
            *(arr3 + k) = *(arr1 + i);
            ++i;
        }
        else
        {
            *(arr3 + k) = *(arr2 + j);
            ++j;
        }
    }

    for (; i < size1; ++i, ++k)
    {
        *(arr3 + k) = *(arr1 + i);
    }

    for (; j < size2; ++j, ++k)
    {
        *(arr3 + k) = *(arr2 + j);
    }
}
int main()
{
    setlocale(0, "");
    srand(time(NULL));

    int size;
    cout << "Введите длину первого массива: ";
    cin >> size;

    int size1;
    cout << "Введите длину второго массива: ";
    cin >> size1;


    int* arr1 = new int[size];
    int* arr2 = new int[size1];
    int* arr3 = new int[size + size1];

    cout << "Массив 1: " << endl;
    CreateMassive(arr1, size);
    sort(arr1, arr1 + size);
    PrintMassive(arr1, size);

    cout << "Массив 2: " << endl;
    CreateMassive(arr2, size1);
    sort(arr2, arr2 + size1);
    PrintMassive(arr2, size1);

    cout << endl;

    JoinMassive(arr1, size, arr2, size1, arr3, size + size1);
    cout << "Общий массив: " << endl;
    PrintMassive(arr3, size + size1);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}