#include<iostream>

using namespace std;

int main()
{
    string expression ="abc9abc";
    string regex="^abc.abc$";
    char temp;
    int esize=expression.length();
    int rsize = regex.length();

    int i=0,j=0;

    int flag= true;
    while(i<rsize && flag)
    {
        switch (regex[i])
        {
            case '^':
                i++;
                break;
            
            case '$':
                i++;
                break;
            
            case '*':
                temp = regex[i-1];
                if(temp=='.'){
                    temp=expression[j-1];
                }
                while(temp==expression[j]){
                    j++;
                }
                i++;
                break;
            
            case '.':
                if(expression[j]-'a'< 26 && expression[j]-'a'>= 0){//Check this
                    i++;
                    j++;
                }
                else{
                    flag = false;
                }
        
            default:
                if(regex[i]==expression[j])
                {
                    i++;
                    j++;
                }
                else{
                    flag=false;
                }
                break;
        }

    }
    
        if(!flag)
        {
            cout<<"false"<<endl;
            return 0;
        }
        else if(i!=rsize || j!=esize)
        {
            cout<<"false"<<endl;
            return 0;
        }
        else 
            cout<<"true";
}