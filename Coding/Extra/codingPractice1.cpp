#include<iostream>

using namespace std;

class Person
{
    private:
        int Id;
        string Name;
    public:
        Person(int id,string name)
        {
            this->Id=id;
            this->Name=name;
        }

        void PrintPerson()
        {
            cout<<"Person Name is "+ this->Name<<endl;
        }

};

int main()
{
    Person person(1,"Mrinal");
    person.PrintPerson();
    cout<<"Hello World"<<endl;
    return 0;
}