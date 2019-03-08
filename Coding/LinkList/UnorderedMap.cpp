#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main()
{
    unordered_map<int,int> m ={{1,2},{44,3},{2,7},{33,5}};
    vector<vector<int> > v(3,{0,1,0});
    int **b = new int*[3];
    for(int i=0;i<3;i++)
    {
        b[i]=new int[3];
    }

    cout<<v[1][1]<<endl;

    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    for(auto it=m.begin();it!=m.end();++it)
    {
        cout<<(*it).first<< " "<<(*it).second<<endl;
    }

    std::unordered_multimap<int,int> mymap;

    std::cout << "max_size = " << mymap.max_size() << std::endl;
    std::cout << "max_bucket_count = " << mymap.max_bucket_count() << std::endl;
    std::cout << "max_load_factor = " << mymap.max_load_factor() << std::endl;

}
