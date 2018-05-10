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
        if (!next)
        {
            vocab = num;
            ST *New;
            New = new ST;
            New->next = nullptr;
            next = New;
        }
        else
            next->add(num);
    }
    void show() // show all elements
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
        ST<T> *q = this;
        if (!q->next)
        {
            cout << "No more elements\n";
        }
        else
        {
            temp = q;
            cout << q << " : " << q->vocab << endl;
            *this = *q->next;
            delete temp;
        }
    }
};
int main()
{
    ST<int> q;
    for (int i = 0; i < 10; i++)
        q.add(i);
    return 0;
}