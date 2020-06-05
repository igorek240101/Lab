#include <iostream>
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
                Lab3();
                break;
            }
            case 4:
            {
                Lab4();
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

struct Value
{
    int value;
    Value* Next;
};

void Lab2()
{
    while (true)
    {
        cout << "0 - чтобы выйти, любой ввод для продолжения\n";
        int n;
        cin >> n;
        if (n == 0) return;

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

void Lab3()
{
    while (true)
    {
        cout << "0 - чтобы выйти, любой ввод для продолжения\n";
        int n;
        cin >> n;
        if (n == 0) return;
        Value* Create();
        Value* Top1 = Create();
        Value* Now1 = Top1;
        Value* Now2 = Create();
        Value* Conncetion = NULL;
        while (true)
        {
            if (Now1 == NULL && Now2 == NULL) break;
            if (Now1 == NULL)
            {
                Conncetion->Next = Now2;
                Now2 = NULL;
                break;
            }
            if (Now2 == NULL)
            {
                break;
            }
            if (Now1->value + Now2->value >= 10)
            {
                if (Now1->Next == NULL)
                {
                    Now1->Next = new Value();
                    Now1->Next->value = 0;
                }
                Now1->Next->value++;
            }
            Now1->value = (Now1->value + Now2->value) % 10;
            Conncetion = Now1;
            Now1 = Now1->Next;
            Now2 = Now2->Next;
        }
        string s = string();
        Now1 = Top1;
        while (Now1 != NULL) // заплняем строку
        {
            s.insert(0, 1, (Now1->value+'0'));
            Now1 = Now1->Next;
        }
        cout << "Сумма равна: " << s <<"\n";
    }
}

Value* Create()
{
    Value* Main = NULL;
    Value* New = NULL;
    Value* Last = NULL;
    string s;
    cout << "Введите число\n";
    cin >> s;
    int b = 0;
    for (int i = s.length() - 1; i >= 0; i--) // Обходим строку с конца
    {
        New = new Value();
        New->value = s[i]-'0';
        if (Last != NULL)
        {
            Last->Next = New;
        }
        else
        {
            Main = New;
        }
        Last = New;
    }
    return Main;
}

void Lab4()
{
    struct Double
    {
        char a;
        int value;

        Double* Top;
        Double* Count;
    };

    Double* TopT = NULL;
    Double* TopC = NULL;
    Double* Last = NULL;
    cout << "Вводите пары литера - число, признако окончания ввода пар - 0 0\n";
    while (true)
    {
        char a;
        int b;
        cin >> a >> b;
        if (a == '0' && b == 0) break;
        Double* New = new Double();
        New->a = a;
        New->value = b;
        if (Last == NULL)
        {
            TopT = New;
            TopC = New;
        }
        else
        {
            Last->Top = New;
            Double* SearchLast = NULL;
            Double* Search = TopC;
            bool flag = false;
            while (Search->value < b)
            {
                if (Search->Count == NULL)
                {
                    flag = true;
                    break;
                }
                SearchLast = Search;
                Search = Search->Count;
            }
            if (SearchLast == NULL && Search->Count!= NULL)
            {
                New->Count = TopC;
                TopC = New;
            }
            else
            {
                if (flag)
                {
                    Search->Count = New;
                }
                else
                {
                    SearchLast->Count = New;
                    New->Count = Search;
                }
            }
        }
        Last = New;
    }
    while (true)
    {
        cout << "1 - чтобы вывести литеры в порядке ввода, 2 - чтобы вывести числа в порядке возрастания, 0 - выход\n";
        int n;
        cin >> n;
        if (n == 0) break;
        if (n == 1)
        {
            Double* Now = TopT;
            while (Now != NULL)
            {
                cout << Now->a << " ";
                Now = Now->Top;
            }
        }
        if (n == 2)
        {
            Double* Now = TopC;
            while (Now != NULL)
            {
                cout << Now->value << " ";
                Now = Now->Count;
            }
        }
        cout << "\n";
    }
}

