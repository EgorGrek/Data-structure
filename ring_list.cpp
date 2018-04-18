#include <iostream>
using namespace std;
template <class T>
class ST
{
    ST *next = this;
    ST *previous;
    T value;

  public:
    ST()
    {
        next = this;
    }
    ~ST() // clear memory
    {
        while (this->next)
        {
            ST *temp;
            temp = this->next;
            delete this->previous;
            delete this->next;
            this = temp;
            delete temp;
        }
    }
    void add(T num, ST *fir) // add element
    {
        if (next == fir)
        {
            value = num;
            ST *New;
            New = new ST;
            New->next = fir;
            New->value = NULL;
            New->previous = this;
            next = New;
            fir->previous = New;
        }
        else
            next->add(num, fir);
    }
    friend void show_ell(ST *q, int num) // show num elements
    {
        int i = 0;
        ST *fir;
        fir = q;
        do
        {
            i++;
            cout << q << " : " << q->value << endl;
            q = q->next;
            if (q->value == NULL)
                q = q->next;
        } while (i != num);
    }
    friend void fr_end_show_ell(ST *q, int num) // show num elements in the opposite direction
    {
        int i = 0;
        do
        {
            q = q->previous;
            if (q->value == NULL)
                q = q->previous;
            i++;
            cout << q << " : " << q->value << endl;
        } while (i != num);
    }
    friend ST *left(ST *q) // move the pointer to the left
    {

        q = q->previous;
        if (q->value == NULL)
            q = q->previous;

        return q;
    }
    friend ST *right(ST *q) // move the pointer to the right
    {
        q = q->next;
        if (q->value == NULL)
            q = q->next;
        return q;
    }
    friend ST *delthis(ST *q) // delete one element
    {
        q->previous->next = q->next;
        q->next->previous = q->previous;
        return q->previous;
    }
};
int main()
{
    return 0;
}