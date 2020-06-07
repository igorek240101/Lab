#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

void Lab1();
void Lab2();
void Lab3();
void Lab4();
void Lab5();
void Lab6();
void Course();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
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
                Lab5();
                break;
            }
            case 6:
            {
                Lab6();
                break;
            }
            case 7:
            {
                Course();
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
        if (n == 0 || m == 0)
        {
            cout << "Некоректный ввод\n";
            continue;
        }
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
            if (n == 0) 
                break;
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
            if (Top == NULL)
            {
                Top = new Value();
                Top->value = n;
                continue;
            }
            Now = Top;
            Last = NULL;
            bool flag = false;
            while (Now->value<=n) // Поиск места вставки
            {
                if (Now->value == n) // Исключить переход от возрастающей последовательности к неубывающей
                {
                    flag = true;
                    break;
                }
                Last = Now;
                Now = Now->Next;
                if (Now == NULL) break; // Обработка, если число больше любого в последовательности
            }
            if (flag) continue;
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
        while (true) // сложение
        {
            if (Now1 == NULL && Now2 == NULL) break;
            if (Now1 == NULL) // Первый список окончен, прибавим к ниму все старшие разряды второго числа
            {
                Conncetion->Next = Now2;
                Now2 = NULL;
                break;
            }
            if (Now1->value >= 10) // Обработка каскада переходов
            {
                Now1->value %= 10;
                if(Now1->Next == NULL)
                {
                    Now1->Next = new Value();
                    Now1->Next->value = 0;
                }
                Now1->Next->value++;
            }
            if (Now2 == NULL) // Второй список окончен, далее только обработка каскадов
            {
                Now1 = Now1->Next;
                continue;
            }
            if (Now1->value + Now2->value >= 10) // Обработка перехода
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
    cin >> s; // Считываем строку
    int b = 0;
    for (int i = s.length() - 1; i >= 0; i--) // Обходим строку с конца
    {
        New = new Value();
        New->value = s[i]-'0'; // Записываем цифру
        if (Last != NULL) // Проверка на первый ввод
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
            if (SearchLast == NULL && Search->Count!= NULL || TopC->Count == NULL)
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

struct Tree
{
    int value;
    Tree* Left;
    Tree* Right;
};

void Lab5()
{

    Tree* Top = NULL;
    void Add_element(int a, Tree* point);
    cout << "Введите эелементы дерева (признак окончания 0)\n";
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0) break;
        if (Top == NULL)
        {
            Top = new Tree();
            Top->value = n;
        }
        else
        {
            Add_element(n, Top);
        }
    }
    while (true)
    {
        cout << "1 - для инфиксного вывода, 2 - для префиксного вывода, 3 - для постфиксного вывода, 0 - выход\n";
        int n;
        cin >> n;
        void INF(Tree * point);
        void PRE(Tree * point);
        void POS(Tree * point);
        switch (n)
        {
        case 1:
        {
            INF(Top);
        }
        break;
        case 2:
        {
            PRE(Top);
        }
        break;
        case 3:
        {
            POS(Top);
        }
        break;
        case 0:
        {
            return;
        }
        }

    }
}

void INF(Tree* point)
{
    if(point->Left != NULL)INF(point->Left);
    cout << point->value << "\n";
    if (point->Right != NULL)INF(point->Right);
}

void PRE(Tree* point)
{
    cout << point->value << "\n";
    if (point->Left != NULL)PRE(point->Left);
    if (point->Right != NULL)PRE(point->Right);
}

void POS(Tree* point)
{
    if (point->Left != NULL)POS(point->Left);
    if (point->Right != NULL)POS(point->Right);
    cout << point->value << "\n";
}

void Add_element(int a, Tree* point)
{
    if (point->value > a)
    {
        if (point->Left != NULL)
        {
            Add_element(a, point->Left);
        }
        else
        {
            point->Left = new Tree();
            point->Left->value = a;
        }
    }
    else
    {
        if (point->value < a)
        {
            if (point->Right != NULL)
            {
                Add_element(a, point->Right);
            }
            else
            {
                point->Right = new Tree();
                point->Right->value = a;
            }
        }
    }
}

struct Point
{
    int x;
    int y;
    Point* Left;
    Point* Right;
    Point* Middle;
    Point* Parent;
};

void Lab6()
{
    int MaxSearch(Point * Top);
    Point* Search(int a, Point * Top);
    Point* Top = NULL;
    while (true)
    {
        cout << "Вводите листья дерева, 0 - для выхода\n";
        int n;
        cin >> n;
        if (n == 0) break;
        if (Top == NULL)
        {
            Top = new Point();
            Top->x = n;
        }
        else
        {
            Point* L = Search(n, Top);
            if (L != NULL)
            {
                int lists[4];
                lists[0] = L->Left->x;
                lists[1] = L->Right->x;
                bool flag = true;
                if (L->Middle != NULL)
                {
                    lists[2] = lists[1];
                    lists[1] = L->Middle->x;
                    flag = false;
                }
                for (int i = 0; i < 4; i++)
                {
                    if (i == 3)
                    {
                        lists[3] = n;
                        break;
                    }
                    if ((i == 2 && flag))
                    {
                        lists[2] = n;
                        break;
                    }
                    if (n < lists[i])
                    {
                        for (int j = 3; j > i; j--)
                        {
                            lists[j] = lists[j - 1];
                        }
                        lists[i] = n;
                        break;
                    }
                }
                if (L->Middle == NULL)
                {
                    L->Left->x = lists[0];
                    L->Middle = new Point();
                    L->Middle->x = lists[1];
                    L->Right->x = lists[2];
                    L->Middle->Parent = L;
                    L->x = MaxSearch(L->Left);
                    L->y = MaxSearch(L->Middle);
                    Point* Keys = L;
                    while (Keys != Top)
                    {
                        Keys = Keys->Parent;
                        Keys->x = MaxSearch(Keys->Left);
                        if (Keys->Middle != NULL)Keys->y = MaxSearch(Keys->Middle);
                    }
                }
                else
                {
                    Point* f = L->Left;
                    Point* s = L->Middle;
                    Point* t = L->Right;
                    Point* fo = new Point();
                    f->x = lists[0];
                    s->x = lists[1];
                    t->x = lists[2];
                    fo->x = lists[3];
                    Point* L2 = new Point();
                    do
                    {
                        L->Middle = NULL;
                        L->Left = f;
                        L->Right = s;
                        L2->Left = t;
                        t->Parent = L2;
                        L2->Right = fo;
                        fo->Parent = L2;
                        L->x = MaxSearch(L->Left);
                        L2->x = MaxSearch(L2->Left);
                        if (L == Top)
                        {
                            Top = new Point();
                            Top->Left = L;
                            Top->Right = L2;
                            L->Parent = Top;
                            L2->Parent = Top;
                            Top->x = MaxSearch(L);
                            break;
                        }
                        if (L->Parent->Middle == NULL)
                        {
                            L2->Parent = L->Parent;
                            Point* L3;
                            if (L->Parent->Left != L)
                            {
                                L3 = L->Parent->Left;
                                L->Parent->Middle = L;
                                L->Parent->Right = L2;
                            }
                            else
                            {
                                L3 = L->Parent->Right;
                                if (L3->x < L2->x)
                                {
                                    L->Parent->Middle = L3;
                                    L->Parent->Right = L2;
                                }
                                else
                                {
                                    L->Parent->Middle = L2;
                                    L->Parent->Right = L3;
                                }
                            }
                            Point* Keys = L;
                            while (Keys != Top)
                            {
                                Keys = Keys->Parent;
                                Keys->x = MaxSearch(Keys->Left);
                                if (Keys->Middle != NULL)Keys->y = MaxSearch(Keys->Middle);
                            }
                            break;
                        }
                        else
                        {
                            Point* ar[4];
                            ar[0] = L->Parent->Left;
                            ar[1] = L->Parent->Middle;
                            ar[2] = L->Parent->Right;
                            ar[3] = L2;
                            Point* min = new Point();
                            for (int i = 0; i < 3; i++)
                            {
                                int min_index = -1;
                                for (int j = i; j < 4; j++)
                                {
                                    if (j == i || ar[j]->x < min->x)
                                    {
                                        min = ar[j];
                                        min_index = j;
                                    }
                                }
                                if (ar[i] != min)
                                {
                                    Point* bufer = new Point();
                                    bufer->x = ar[i]->x;
                                    bufer->y = ar[i]->y;
                                    bufer->Left = ar[i]->Left;
                                    bufer->Middle = ar[i]->Middle;
                                    bufer->Right = ar[i]->Right;
                                    bufer->Parent = ar[i]->Parent;
                                    delete(ar[i]);
                                    ar[i] = ar[min_index];
                                    ar[min_index] = bufer;
                                }
                            }
                            f = ar[0];
                            s = ar[1];
                            t = ar[2];
                            fo = ar[3];
                            L2->Parent = L->Parent;
                            L = L->Parent;
                            L2 = new Point();
                        }

                    } while (true);
                }
            }
            else
            {
                Point* New = new Point();
                New->x = n;
                Point* Last = Top;
                Top = new Point();
                New->Parent = Top;
                Last->Parent = Top;
                if (n < Last->x)
                {
                    Top->Left = New;
                    Top->Right = Last;
                    Top->x = n;
                }
                else
                {
                    Top->Left = Last;
                    Top->Right = New;
                    Top->x = Last->x;
                }
            }
        }
    }
}

int MaxSearch(Point* Top)
{
    if (Top->Right != NULL) return MaxSearch(Top->Right);
    return Top->x;
}

Point* Search(int a, Point* Top)
{
    Point* Last = NULL;
    Point* S = Top;
    while (S->Left!= NULL)
    {
        Last = S;
        if (S->Middle == NULL)
        {
            if (S->x < a)
            {
                S = S->Right;
            }
            else
            {
                S = S->Left;
            }
        }
        else
        {
            if (S->y < a)
            {
                S = S->Right;
            }
            else
            {
                if (S->x < a)
                {
                    S = S->Middle;
                }
                else
                {
                    S = S->Left;
                }
            }
        }
    }
    return Last;
}


void Course()
{
    struct Student
    {
        string FIO;
        int group;
        int value[5];
        int money;
        Student* Next;
    };
    Student* Top = NULL;
    while (true)
    {
        cout << "1 - Консольный ввод, 2 - файловый ввод (только англоязычное ФИО), 3 - удалить группу, 4 - удалить студента, 5 - консольный вывод, 6 - файловый вывод, 7 - вывод студентов в алфавитном порядке, имеющих задолжности по сессии, 0 - для выхода\n";
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            Student* New = new Student();
            cout << "Введите ФИО студента\n";
            char f[50];
            cin.ignore();
            cin.getline(f, 50);
            New->FIO = (string)f;
            cout << "Введите № группы студента\n";
            cin >> New->group;
            for (int i = 0; i < 5; i++)
            {
                cout << "Введите оценку за предмет № " << i+1 << " студента\n";
                cin >> New->value[i];
            }
            cout << "Введите размер степендии студента\n";
            cin >> New->money;
            if (Top == NULL)Top = New;
            else
            {
                Student* Last = NULL;
                Student* Now = Top;
                while (Now != NULL)
                {
                    int i = 0;
                    if (Now->FIO == New->FIO)
                    {
                        delete(New);
                        break;
                    }
                    bool tr = false;
                    while (Now->FIO[i] == New->FIO[i])
                    {
                        i++;
                        if (Now->FIO.length() == i || New->FIO.length() == i)
                        {
                            tr = true;
                            break;
                        }
                    }
                    if (Now->FIO.length() == i)
                    {
                        Last = Now;
                        Now = Now->Next;
                        continue;
                    }
                    if (tr || Now->FIO[i] > New->FIO[i])
                    {
                        if (Now == Top)
                        {
                            New->Next = Now;
                            Top = New;
                        }
                        else
                        {
                            Last->Next = New;
                            New->Next = Now;
                        }
                        break;
                    }
                    Last = Now;
                    Now = Now->Next;
                }
                if (Now == NULL) Last->Next = New;
            }
        }
        break;
        case 2:
        {
            cout << "Введите имя входного файла (вводить с двойным \\)\n";
            char f[50];
            cin.ignore();
            cin.getline(f, 50);
            ifstream fin(f);
            locale loc("Rus");
            

#pragma region Код аналогичен консольному вводу

            Student* New = new Student();
            fin.ignore();
            fin.ignore();
            fin.ignore();
            fin.getline(f, 50);
            New->FIO = (string)f;
            fin >> New->group;
            for (int i = 0; i < 5; i++)
            {
                fin >> New->value[i];
            }
            fin >> New->money;
            if (Top == NULL)Top = New;
            else
            {
                Student* Last = NULL;
                Student* Now = Top;
                while (Now != NULL)
                {
                    int i = 0;
                    if (Now->FIO == New->FIO)
                    {
                        delete(New);
                        break;
                    }
                    bool tr = false;
                    while (Now->FIO[i] == New->FIO[i])
                    {
                        i++;
                        if (Now->FIO.length() == i || New->FIO.length() == i)
                        {
                            tr = true;
                            break;
                        }
                    }
                    if (Now->FIO.length() == i)
                    {
                        Last = Now;
                        Now = Now->Next;
                        continue;
                    }
                    if (tr || Now->FIO[i] >= New->FIO[i])
                    {
                        if (Now == Top)
                        {
                            New->Next = Now;
                            Top = New;
                        }
                        else
                        {
                            Last->Next = New;
                            New->Next = Now;
                        }
                        break;
                    }
                    Last = Now;
                    Now = Now->Next;
                }
                if (Now == NULL) Last->Next = New;
            }

#pragma endregion

            fin.close();
        }
        break;
        case 3:
        {
            cout << "Введите номер группы которую надо удалить\n";
            int n;
            cin >> n;
            Student* Last = NULL;
            Student* Now = Top;
            while (Now != NULL)
            {
                if (Now->group == n)
                {
                    if (Last == NULL)
                    {
                        Top = Top->Next;
                        delete(Now);
                        Now = Top;
                    }
                    else
                    {
                        if (Now->Next != NULL)
                        {
                            Last->Next = Now->Next;
                            delete(Now);
                            Now = Last->Next;
                        }
                        else
                        {
                            delete(Now);
                            Last->Next = NULL;
                        }
                    }
                }
                else
                {
                    Last = Now;
                    Now = Now->Next;
                }
            }
        }
        break;
        case 4:
        {
            cout << "Введите ФИО студента которого надо удалить\n";
            string n;
            char f[50];
            cin.ignore();
            cin.getline(f, 50);
            n = (string)f;
            Student* Last = NULL;
            Student* Now = Top;
            while (Now != NULL)
            {
                if (Now->FIO == n)
                {
                    if (Last == NULL)
                    {
                        Top = Top->Next;
                        delete(Now);
                        Now = Top;
                    }
                    else
                    {
                        if (Now->Next != NULL)
                        {
                            Last->Next = Now->Next;
                            delete(Now);
                            Now = Last->Next;
                        }
                        else
                        {
                            delete(Now);
                            Last->Next = NULL;
                        }
                    }
                }
                else
                {
                    Last = Now;
                    Now = Now->Next;
                }
            }
        }
        break;
        case 5:
        {
            Student* Now = Top;
            int j = 1;
            while (Now != NULL)
            {
                char f[50];
                for (int i = 0; i < Now->FIO.length(); i++)
                {
                    f[i] = Now->FIO[i];
                }
                cout << "\nЛичное дело №" << j << "\n\n" << "ФИО :";
                for (int i = 0; i < Now->FIO.length(); i++) 
                    cout << f[i];
                cout << "\nГруппа номер :"<< Now->group << "\n";
                cout << "Результаты сессии :" << Now->value[0] << ", " << Now->value[1] << ", " << Now->value[2] << ", " << Now->value[3] << ", " << Now->value[4] << "\n";
                cout << "Размер степендии :" << Now->money << "\n";
                bool r = true;
                for (int i = 0; i < 5; i++)
                {
                    if (Now->value[i] < 5)r = false;
                }
                if (r) cout << "Кандидат на красный диплом\n";
                Now = Now->Next;
                j++;
            }
        }
        break;
        case 6:
        {

            cout << "Введите имя выходного файла (вводить с двойным \\)\n";
            char f[50];
            cin.ignore();
            cin.getline(f, 50);
            ofstream fout(f);
            locale loc("Rus");

#pragma region Код аналогичен консолоьному аналогу

            Student* Now = Top;
            int j = 1;
            while (Now != NULL)
            {
                char f[50];
                for (int i = 0; i < Now->FIO.length(); i++)
                {
                    f[i] = Now->FIO[i];
                }
                for (int i = 0; i < Now->FIO.length(); i++)
                    fout << f[i];
                fout << "\n" << Now->group << "\n";
                fout << Now->value[0] << ", " << Now->value[1] << ", " << Now->value[2] << ", " << Now->value[3] << ", " << Now->value[4] << "\n";
                fout  << Now->money << "\n";
                Now = Now->Next;
                j++;
            }

#pragma endregion

            fout.close();

        }
        break;
        case 7:
        {
            Student* Now = Top;
            while (Now != NULL)
            {
                cout << "\n";
                int count = 0;
                for (int i = 0; i < 5; i++)
                {
                    if (Now->value[i] <= 2)count++;
                }
                if (count > 0)
                {
                    cout << Now->FIO;
                    if (count < 4) cout << " - Вылетел на допсу\n";
                    else if (count < 5) cout << " - Отправлен на Комиссию\n";
                    else cout << " - ОТЧИСЛЕНО\n";
                }
                Now = Now->Next;
            }
            cout << "\n";
        }
        break;
        case 0:
        {
            return;
        }
        }
    }

}
