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
        cout << "1 - для инфиксного вывода, 2 - для префиксного вывода, 3 - для постфиксного вывода, - выход\n";
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
        cout << "Вводите листья дерева\n";
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
