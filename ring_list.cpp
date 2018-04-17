#include <iostream>
using namespace std;
class ST
{
    ST *next = this;
    ST *previous;
    int vocab;

  public:
    ST(int num)
    {
        vocab = num;
    }
    ST()
    {
        next = this;
    }
    ~ST()
    {
        while (this->next)
        {
            ST *temp;
            temp = new ST;
            temp->next = this->next;
            delete this->previous;
            delete this->next;
            *this = *temp;
        }
    }
    void add(int num, ST *fir);
    friend void show_ell(ST *q, int num);
    friend void prev_el(ST *q);
    friend void fr_end_show_ell(ST *q, int num);
    friend ST *left(ST *q);
    friend ST *right(ST *q);
    friend ST *dellthis(ST *q);
};
void ST::add(int num, ST *fir)
{
    if (next == fir)
    {
        vocab = num;
        ST *New;
        New = new ST;
        New->next = fir;
        New->vocab = NULL;
        New->previous = this;
        next = New;
        fir->previous = New;
    }
    else
        next->add(num, fir);
}
ST *left(ST *q)
{

    q = q->previous;
    if (q->vocab == NULL)
        q = q->previous;

    return q;
}
ST *right(ST *q)
{
    q = q->next;
    if (q->vocab == NULL)
        q = q->next;
    return q;
}
void show_ell(ST *q, int num)
{
    int i = 0;
    ST *fir;
    fir = q;
    do
    {
        i++;
        cout << q << " : " << q->vocab << endl;
        q = q->next;
        if (q->vocab == NULL)
            q = q->next;
    } while (i != num);
}
void fr_end_show_ell(ST *q, int num)
{
    int i = 0;
    do
    {
        q = q->previous;
        if (q->vocab == NULL)
            q = q->previous;
        i++;
        cout << q << " : " << q->vocab << endl;
    } while (i != num);
}
ST *dellthis(ST *q)
{
    q->previous->next = q->next;
    q->next->previous = q->previous;
    return q->previous;
}   
int main()
{
    int num;
    ST *first;
    first = new ST;
    for (int i = 1; i < 100; i++)
        first->add(i, first);

    show_ell(first, 1);
    cout << "We delete 50 elements now !!" << endl;
    for(int i = 0; i < 50; i++)
        first = dellthis(first);
    
    show_ell(first, 80);
    return 0;
}