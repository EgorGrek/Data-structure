#include <iostream>
using namespace std;
class Per
{
  public:
    Per *next;
    Per *previous;
    int koef;
    int exp;
    Per()
    {
        next = nullptr;
        previous = nullptr;
        this->koef = NULL;
        this->exp = NULL;
    }
    Per(int koef, int exp)
    {
        next = this;
        previous = this;
        this->koef = koef;
        this->exp = exp;
    }
    void add(int koef, int exp)
    {
        if (next == nullptr)
        {
            next = this;
            previous = this;
            this->koef = koef;
            this->exp = exp;
        }
        else
        {
            Per *New = new Per;
            New->next = next;
            next->previous = New;
            next = New;
            New->koef = koef;
            New->exp = exp;
            New->previous = this;
        }
    }
    void add(Per &var)
    {
        if (next == nullptr)
        {
            next = this;
            previous = this;
            this->koef = var.koef;
            this->exp = var.exp;
        }
        else
        {
            Per *New = new Per;
            New->next = next;
            next->previous = New;
            next = New;
            New->koef = var.koef;
            New->exp = var.exp;
            New->previous = this;
        }
    }
    bool operator!=(Per &a)
    {
        if (koef != a.koef || exp != a.exp)
            return true;
        else
            return false;
    }
    bool operator==(Per &a)
    {
        if (koef == a.koef && exp == a.exp)
            return true;
        else
            return false;
    }
};
class Ring
{
  private:
    Per *it;
    int size;

  public:
    ~Ring()
    {
        if (it->next != nullptr)
        {
            it->previous->next = nullptr;
            while (it->next != nullptr)
            {
                Per *cash = it;
                it = it->next;
                delete cash;
            }
        }
        delete it;
    }
    Ring()
    {
        it = new Per;
        size = 0;
    }
    Ring(int koef, int exp)
    {
        it = new Per(koef, exp);
        size = 1;
    }
    Ring(Per &a)
    {
        it = new Per(a);
        size = 1;
    }
    Ring(int **mas, int arsize)
    {
        it = new Per;
        size = 0;
        for (int i = 0; i < arsize; i++)
        {
            size++;
            it->add(mas[i][0], mas[i][1]);
        }
    }
    void add(int koef, int exp)
    {
        size++;
        it->add(koef, exp);
    }
    void add(Per &var)
    {
        size++;
        it->add(var);
    }
    operator bool()
    {
        if (it->koef || it->exp)
            return true;
        else
            return false;
    }
    operator int **()
    {
        int **mas = new int *[size];
        for (int i = 0; i < size; i++)
        {
            mas[i] = new int[2];
            mas[i][0] = it->koef;
            mas[i][1] = it->exp;
            it = it->next;
        }
        return mas;
    }
    operator Per *()
    {
        Per *mas = new Per[size];
        for (int i = 0; i < size; i++)
        {
            mas[i].koef = it->koef;
            mas[i].exp = it->exp;
            it = it->next;
        }
        return mas;
    }
    friend istream &operator>>(istream &in, Ring &q) // add
    {
        int koef, exp;
        cin >> koef >> exp;
        q.add(koef, exp);
        return in;
    }
    friend Per &operator>>(Per &in, Ring &q) // add
    {
        q.add(in.koef, in.exp);
        return in;
    }
    friend istream &operator>(istream &in, Ring &q) // exchange
    {
        int koef, exp;
        cin >> koef >> exp;
        q.it->koef = koef;
        q.it->exp = exp;
        return in;
    }
    friend Per &operator>(Per &in, Ring &q) // exchange
    {
        q.it->koef = in.koef;
        q.it->exp = in.exp;
        return in;
    }
    friend ostream &operator<(ostream &ou, Ring &q) // cout
    {
        if (q.it->next == nullptr)
        {
            cout << "\n!!! 0 elements !!!\n";
            return ou;
        }
        cout << q.it->koef << "x^" << q.it->exp;
        return ou;
    }
    friend Per &operator<(Per &ou, Ring &q) // out
    {
        if (q.it->next == nullptr)
        {
            cout << "\n!!! 0 elements !!!\n";
            return ou;
        }
        ou.exp = q.it->exp;
        ou.koef = q.it->koef;
        return ou;
    }
    friend ostream &operator<<(ostream &ou, Ring &q) // cout and delete
    {
        if (q.it->next == nullptr)
        {
            cout << "\n!!! 0 elements !!!\n";
            return ou;
        }
        else if (q.it->next == q.it)
        {
            q.size--;
            cout << q.it->koef << "x^" << q.it->exp;
            q.it->next = nullptr;
            q.it->previous = nullptr;
            return ou;
        }
        else
        {
            q.size--;
            cout << q.it->koef << "x^" << q.it->exp;
            q.it->previous->next = q.it->next;
            Per *cash = q.it;
            q.it->next->previous = q.it->previous;
            q.it = q.it->next;
            delete cash;
            return ou;
        }
    }
    friend Per &operator<<(Per &ou, Ring &q) // out and delete
    {
        if (q.it->next == nullptr)
        {
            cout << "\n!!! 0 elements !!!\n";
            return ou;
        }
        else if (q.it->next == q.it)
        {
            q.size--;
            ou.exp = q.it->exp;
            ou.koef = q.it->koef;
            q.it->next = nullptr;
            q.it->previous = nullptr;
            return ou;
        }
        else
        {
            q.size--;
            ou.exp = q.it->exp;
            ou.koef = q.it->koef;
            q.it->previous->next = q.it->next;
            Per *cash = q.it;
            q.it->next->previous = q.it->previous;
            q.it = q.it->next;
            delete cash;
            return ou;
        }
    }
    void operator++(int) // move the pointer to the right
    {
        if (it->next == nullptr || it->next == it)
            return;
        it = it->next;
    }
    void operator--(int) // move the pointer to the right
    {
        if (it->next == nullptr || it->next == it)
            return;
        it = it->previous;
    }
    void insertsort()
    {
        int j, i, max, temp, temp2, temp3;
        for (i = 1; i < size; i++)
        {
            max = it->exp;
            temp3 = it->koef;
            j = i;
            (*this)--;
            temp = it->exp;
            temp2 = it->koef;
            while (j >= 1 && temp < max)
            {
                (*this)++;
                it->exp = temp;
                it->koef = temp2;
                (*this)--;
                (*this)--;
                temp = it->exp;
                temp2 = it->koef;
                j--;
            }
            (*this)++;
            it->exp = max;
            it->koef = temp3;
            while (j < i)
            {
                j++;
                (*this)++;
            }
            (*this)++;
        }
    }
    void operator=(Ring &a)
    {
        if (a.size == 0)
        {
            this->~Ring();
            Per *cash = new Per;
            cash->next = nullptr;
            cash->previous = nullptr;
            it = cash;
        }
        else
        {
            this->~Ring();
            Per *cash = new Per;
            for (int i = 0; i < a.size; i++)
            {
                cash->add(a.it->koef, a.it->exp);
                a++;
            }
            it = cash;
            size = a.size;
        }
    }
    bool operator==(Ring &a)
    {
        bool t = true;
        if (size != a.size)
            return false;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (*it == *a.it)
                {
                    t = false;
                    break;
                }
                a++;
            }
            if (t)
                return false;
            (*this)++;
            t = true;
        }
        return true;
    }
    bool find(Per &a)
    {
        for (int j = 0; j < size; j++)
        {
            if (*it == a)
            {
                return true;
            }
            (*this)++;
        }
        return false;
    }
    bool find(int koef, int exp)
    {
        for (int j = 0; j < size; j++)
        {
            if (it->exp == exp && it->koef == koef)
            {
                return true;
            }
            (*this)++;
        }
        return false;
    }
    bool operator!=(Ring &a)
    {
        bool t = true;
        if (size != a.size)
            return true;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (*it == *a.it)
                {
                    t = false;
                    break;
                }
                a++;
            }

            if (t)
                return true;
            (*this)++;
            t = true;
        }
        return false;
    }
    int getSize()
    {
        return size;
    }
};
int main()
{
    Ring a, b;
    int t;
    for (int i = 9; i >= 0; i--)
    {
        t = rand() % 10;
        a.add(t, t * t);
    }
    int **mas = (int **)a;
    for (int i = 0; i < a.getSize(); i++)
        cout << mas[i][0] << ' ' << mas[i][1] << '\n';
    cout << '\n';
    Per *testic = (Per *)a;
    for (int i = 0; i < a.getSize(); i++)
        cout << testic[i].koef << ' ' << testic[i].exp << '\n';
    cout << '\n';
    a.insertsort();
    for (int i = 0; i < a.getSize(); i++)
    {
        cout < a;
        cout << ' ';
        a++;
    }
    cout << '\n';
    for (int i = 0; i < a.getSize(); i++)
    {
        cout << a;
        cout << ' ';
        a++;
    }
    b = a;
    cout << '\n';
    for (int i = 0; i < b.getSize(); i++)
    {
        cout << b;
        cout << ' ';
    }
    bool chek = (a == b);
    cout << '\n'
         << chek;
    chek = (a != b);
    cout << '\n'
         << chek;
    Per test;
    test << a;
    cout << '\n'
         << test.koef << "x^" << test.exp << '\n';
    test >> a;
    a++;
    test >> a;
    for (int i = 0; i < 5; i++)
    {
        cout < a;
        cout << ' ';
        a++;
    }
    cout << '\n'
         << a.find(test);
    cout << '\n'
         << a.find(1, 2);
    return 0;
}