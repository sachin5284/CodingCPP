#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class Queue
{
    stack<int> s;
    public:
        void Enqueue(int x)
        {
            s.push(x);
        }

        int Dequeue()
        {
            int x;
            if(s.empty())
            {
                cout<<"Queue is Empty"<<endl;
                exit(0);
            }

            x = s.top();
            s.pop();
            
            if(s.empty())
                return x;
            
            int temp = Dequeue();
            s.push(x);

            return temp;

        }
};

int main()
{
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);

    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
}