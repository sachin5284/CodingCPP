#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    unordered_map<int,int> m ={{1,2},{44,3},{2,7},{33,5}};

    for(auto it=m.begin();it!=m.end();++it)
    {
        cout<<(*it).first<< " "<<(*it).second<<endl;
    }

    std::unordered_multimap<int,int> mymap;

    std::cout << "max_size = " << mymap.max_size() << std::endl;
    std::cout << "max_bucket_count = " << mymap.max_bucket_count() << std::endl;
    std::cout << "max_load_factor = " << mymap.max_load_factor() << std::endl;

}
