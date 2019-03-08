#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> gquiz;
    gquiz.push_back(10);
    gquiz.push_back(10); 
    gquiz.push_front(20); 
    gquiz.push_back(30); 
    gquiz.push_front(15); 

    deque<int> :: iterator it;
    for(it=gquiz.begin();it!=gquiz.end();++it)
    {
        cout<<(*it)<<endl;
    }

    for(auto element:gquiz)
    {
        cout<<element<<endl;
    }


    for(int i=0;i<gquiz.size();i++)
    {
        cout<<gquiz[i]<<endl;
    }
    
    cout<<"Max size: "<<gquiz.max_size()<<endl;
    
    return 0;
}