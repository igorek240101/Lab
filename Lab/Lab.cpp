﻿#include <iostream>
using namespace std;

void Lab1();
void Lab2();
void Lab3();
void Lab4();
void Lab5();
void Lab6();

int main()
{
    setlocale(LC_ALL, "rus");
    while (true)
    {
        std::cout << "1-6 для выбора лабороторной, 7 для выбора курсовой работы, 0 для выхода\n";
        int num;
        cin >> num;
        switch (num)
        {
            case 1:
            {
                Lab1();
                break;
            }
            case 2:
            {
                Lab2();
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                break;
            }
            case 0:
            {
                return 0;
            }
        }
    }
}


void Lab1()
{
    while (true)
    {
        cout << "0 - чтобы выйти, любой ввод для продолжения\n";
        int n, m;
        cin >> n;
        if (n == 0) return;

        struct x
        {
            x* Right;
            x* Down;
            int a;
        };


        cout << "Введите размерность таблицы (два натуральных числа через пробел)\n";
        cin >> n >> m;
        x* Top = NULL;
        x* Now = NULL;
        x* Left = NULL;
        x* Up = NULL;
        for (int i = 0; i < n; i++) // Обход строк
        {
            int max = 0;
            for (int j = 0; j < m; j++) // Обход столбцов
            {
                cout << "x[" << i << ", " << j << "] = ";
                int a; cin >> a;
                Now = new x(); // Создание элемента таблицы
                if (j == 0 || max < a) max = a;
                if (j == 0 && i == 0) Top = Now; 
                Now->a = a;
                if (Left != NULL) Left->Right = Now; // Запись в предыдущий элемент текущий элемент
                if (Up != NULL)
                {
                    Up->Down = Now; // Запись в верхний элемент текущий элемент и смещение верхнего элемента вправо
                    Up = Up->Right;
                }
                Left = Now;

            }
            cout << "В строке " << i+1 << " наибольшее значенеие " << max << "\n";
            Now = Top;
            while (Now->Down != NULL) //Поиск самой нижней строки
            {
                Now = Now->Down;
            }
            Up = Now;
        }
        Up = Top;
        for (int i = 0; i < m; i++) //Обход столбцов
        {
            int max = 0;
            Now = Up;
            for (int j = 0; j < n; j++) // Обход строк
            {
                if (j == 0 || Now->a > max) max = Now->a;
                Now = Now->Down;
            }
            cout << "В столбце " << i + 1 << " наибольшее значенеие " << max << "\n";
            Up = Up->Right;
        }
    }
}

void Lab2()
{
    while (true)
    {
        cout << "0 - чтобы выйти, любой ввод для продолжения\n";
        int n;
        cin >> n;
        if (n == 0) return;

        struct Value
        {
            int value;
            Value* Next;
        };

        Value* Top = NULL;
        Value* Now = NULL;
        Value* Last = NULL;

        cout << "Введите последовательность (признак окончания 0)\n";

        while (true) // Ввод последовательнотси
        {
            cin >> n;
            if (n == 0) break;
            Now = new Value();
            if (Top == NULL) Top = Now; // Заполняем Top
            if (Last != NULL) Last->Next = Now; // Заполянем предыдущий элемент
            Now->value = n;
            Last = Now;
        }

        cout << "Вводите числа, признак окончания 0\n";
        while (true) // Ввод чисел
        {
            cin >> n;
            if (n == 0) break;
            Now = Top;
            Last = NULL;
            while (Now->value<n) // Поиск места вставки
            {
                Last = Now;
                Now = Now->Next;
                if (Now == NULL) break; // Обработка, если число больше любого в последовательности
            }
            Value* New = new Value();
            New->value = n;
            if (Last != NULL) Last->Next = New;
            else Top = New; // Если введено число меньшее любого в последовательности
            New->Next = Now;
        }
    }
}

