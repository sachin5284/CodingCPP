#include<iostream>
using namespace std;

class Graphic
{
    public:
        virtual void Move(int x, int y) = 0;
        virtual void Draw() = 0;
};

class Dot : public Graphic
{
    int x,y;
    public:
        Dot(int x,int y)
        {
            this->x = x;
            this->y = y;
        }
        void Move(int x,int y)
        {        
            this->x += x;
            this->y += y;
        }    

        void Draw()
        {
            cout<<"Dot at "<<x<<" and "<<y<<"...!"<<endl;
        }
};

int main()
{
    Dot d(1,2);
    d.Move(2,3);
    d.Draw();
    cout<<"Hello World..!!"<<endl;
}