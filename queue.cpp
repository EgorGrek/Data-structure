#include <iostream>
using namespace std;
class ST
{
    ST *next = NULL;
    int vocab;

  public:
    void add(int num);
    friend void show(ST *q);
    friend ST *showdel(ST *q);
};
void ST::add(int num)
{
    if (!next)
    {
        vocab = num;
        ST *New;
        New = new ST;
        New->next = NULL;
        next = New;
    }
    else
        next->add(num);
}
void show(ST *q)
{
    while (q->next)
    {
        cout << q << " : " << q->vocab << endl;
        q = q->next;
    }
}
ST *showdel(ST *q)
{
    if (!q->next)
    {
        cout << "No more elements" << endl;
        return q;
    }
    ST *temp;
    temp = q->next;
    cout << q << " : " << q->vocab << endl;
    delete q;
    return temp;
}
int main()
{
    int num;
    ST *first;
    first = new ST;
    for (int i = 1; i < 5; i++)
        first->add(i);

    show(first);
    first = showdel(first);
    first = showdel(first);
    first = showdel(first);
    first = showdel(first);
    first = showdel(first);
    return 0;
}