#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class LRUCache
{
    public:
        list<int> cacheList;
        int cacheSize;
        unordered_map<int,list<int>:: iterator> cacheMap;

        LRUCache(int n)
        {
            this->cacheSize=n;
        }

        void refer(int x)
        {
            //x is not present in cache
            if(cacheMap.find(x)==cacheMap.end())
            {
                //if cache is full
                if(cacheList.size()==cacheSize)
                {
                    int m=cacheList.back();
                    cacheList.pop_back();
                    cacheMap.erase(m);
                }
            }
            else
            {
                cacheList.erase(cacheMap[x]);
            }

            cacheList.push_front(x);
            cacheMap[x]=cacheList.begin();
        }

        void display()
        {
            //list<int> ::iterator it;
            for(auto it:cacheList)
            {
                cout<<it<<" ";
            }
        }
};

int main()
{
    LRUCache cache(3);
    cache.refer(4);
    cache.refer(1);
    cache.refer(2);
    cache.refer(3);
    cache.refer(5);
    cache.display();
}