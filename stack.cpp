#include <iostream>
using namespace std;
class ST
{
    ST *next = NULL;
    int vocab;

  public:
    friend ST *add(ST *t, int num);
    friend void show(ST *q);
    friend ST *showdel(ST *q);
};
ST *add(ST *t, int num)
{
    ST *New;
    New = new ST;
    New->next = t;
    New->vocab = num;
    return New;
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
        first = add(first, i);

    show(first);
    first = showdel(first);
    first = showdel(first);
    first = showdel(first);
    first = showdel(first);
    first = showdel(first);
    for (int i = 1; i < 5; i++)
        first = add(first, i);

    show(first);
    first = showdel(first);
    first = showdel(first);
    first = showdel(first);
    first = showdel(first);
    return 0;
}