// Task09_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

void output01(int* arr, int n, int m)
{
    for (int i = 0; i < n * m; i++) {
        printf_s("%d ", arr[i]);
    }
    printf_s("\n");
}

void output02(int** arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf_s("%d ", arr[i][j]);
        }
        printf_s("\n");
    }
   
}


void viseversa(int* arr, int** arr1, int n, int m, int tudaobratno)
{
    if (tudaobratno == 0) {
        for (int i = 0; i < n * m; i++)
        {
            arr1[i / m][i % m] = arr[i];
        }
    }

    else if (tudaobratno > 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr[i*m + j] = arr1[i][j];
            }

        }
    }
}


int main()
{
    int n = 0, m, vd, l;

    setlocale(LC_ALL, "Russian");



    l = 5;
    while (l!=0)
    {
        printf_s("Выберите действие:\n");
        printf_s(" 1 - преобразование двумерного массива в одномерный,2 - пребразование одномерного массива в двумерный, 0 - завершение\n");
        scanf_s("%d", &vd);

        if (vd == 1)
        {
            printf_s("Введите количество строк и столбцов \n");
            scanf_s("%d%d", &n, &m);

            int* arr = (int*)malloc((n * m) * sizeof(int));
            int** arr1 = (int**)malloc(n * sizeof(int**));
            for (int j = 0; j < n; j++)
            {
                arr1[j] = (int*)malloc(m * sizeof(int*));
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    printf("arr[%i][%i] = ", i, j);
                    scanf_s("%d", &arr1[i][j]);
                }

            }

            viseversa(arr, arr1, n, m, 1);
            output01(arr, n, m);

        }
        else if (vd == 2)
        {
            printf_s("Введите количество строк и столбцов \n");
            scanf_s("%d%d", &n, &m);

            int* arr = (int*)malloc((n * m) * sizeof(int));
            int** arr1 = (int**)malloc(n * sizeof(int**));
            for (int j = 0; j < n; j++)
            {
                arr1[j] = (int*)malloc(m * sizeof(int*));
            }

            for (int i = 0; i < n * m; i++)
            {
                printf("arr[%i] = ", i);
                scanf_s("%d", &arr[i]);
            }
            viseversa(arr, arr1, n, m, 0);
            output02(arr1, n, m);
        }
        else l = vd;
        

    }

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
