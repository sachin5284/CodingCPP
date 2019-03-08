#include<iostream>
#include<queue>

using namespace std;
struct Point
{
    int x;
    int y;
    Point(int x,int y)
    {
        this->x =x;
        this->y =y;
    }
    const int getX()
    {
        return x;
    }
    bool operator>(const Point& a) const
    {
        if(a.x>x)
            return true;
    }

    bool operator<(const Point& a) const
    {
        return a.x<x;
    }
};

int main()
{
    priority_queue<Point> gquiz;

    gquiz.push(Point(1,2));    
    gquiz.push(Point(2,3));
    cout<<gquiz.top().x <<" "<<gquiz.top().y<<endl;

    return 0;
}