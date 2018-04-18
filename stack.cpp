#include <iostream>
using namespace std;
template <class T>
class ST
{
    ST *next = NULL;
    T vocab;

  public:
    ~ST() // clear memory
    {
        while (this->next)
        {
            ST *temp;
            temp = this->next;
            delete this->next;
            this = temp;
            delete temp;
        }
    }
    friend ST *add(ST *t, T num) // add one element
    {
        ST *New;
        New = new ST;
        New->next = t;
        New->vocab = num;
        return New;
    }
    friend void show(ST *q) // show all element
    {
        while (q->next)
        {
            cout << q << " : " << q->vocab << endl;
            q = q->next;
        }
    }
    friend ST *showdel(ST *q) // show one element and delete its
    {
        if (!q->next)
        {
            cout << "No more elements" << endl;
            return q;
        }
        ST<T> *temp;
        temp = q->next;
        cout << q << " : " << q->vocab << endl;
        delete q;
        return temp;
    }
};
int main()
{
    return 0;
}