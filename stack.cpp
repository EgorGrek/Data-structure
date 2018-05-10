#include <iostream>
using namespace std;
template <class T>
class ST
{
    ST *next = nullptr;
    T vocab;

  public:
    ~ST() // clear memory
    {
        while (next != nullptr)
        {
            ST *temp = next;
            next = next->next;
            try
            {
                delete temp;
                throw true;
            }
            catch (bool t)
            {
                break;
            }
        }
    }
    void add(T num) // add one element
    {
        ST<T> *New;
        New = new ST<T>;
        New->next = next;
        New->vocab = vocab;
        vocab = num;
        next = New;
    }
    void show() // show all element
    {
        ST<T> *q = this;
        while (q->next)
        {
            cout << q << " : " << q->vocab << endl;
            q = q->next;
        }
    }
    void showdel() // show one element and delete its
    {
        if (!next)
        {
            cout << "No more elements\n";
        }
        else
        {
            ST<T> *temp = this;
            cout << this << " : " << vocab << endl;
            *this = *next;
        }
    }
};
int main()
{
    ST<int> q;
    for (int i = 0; i < 10; i++)
        q.add(i);
    q.show();
    for (int i = 0; i < 11; i++)
        q.showdel();
    return 0;
}