#include<iostream>

using namespace std;

class Shape
{
    public:
        virtual void Draw()=0;
};

class DrawApi 
{
    public:
        virtual void Draw()=0;
};

class GreenCircle : public DrawApi
{
    public:
    void Draw()
    {
        cout<<"GreenCircle"<<endl;
    }
};

class RedCircle : public DrawApi
{
    public:
    void Draw()
    {
        cout<<"RedCircle"<<endl;
    }
};

class Circle : public Shape
{
    DrawApi api;
    public:
        Circle(DrawApi drawApi)
        {
            this->api = drawApi;
        }

        void Draw()
        {
            this->api.Draw();
        }
};

int main()
{
    RedCircle red;
    Circle redCircle(red);

    redCircle.Draw();
    return 0;
}
