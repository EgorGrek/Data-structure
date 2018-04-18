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
    void add(T num) // add one element
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
    friend void show(ST *q) // show all elements
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
        ST *temp;
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