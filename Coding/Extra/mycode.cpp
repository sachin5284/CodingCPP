// CPP program to express N as sum of at-most
// three prime numbers.
#include <bits/stdc++.h>
using namespace std;
 
// Function to check if a number is prime or not.
bool isPrime(int x)
{
    if (x == 0 || x == 1)
        return false;
    for (int i = 2; i * i <= x; ++i) 
        if (x % i == 0)
            return false;    
    return true;
}
 
// Prints at most three prime numbers whose
// sum is n.
void findPrimes(int n)
{
    if (isPrime(n - 2)) // CASE-II    
        cout << 2 << " " << n - 2 << endl;
 
    else // CASE-III
    {
        cout << 3 << " ";
        n = n - 3;
        for (int i = 4; i < n; i++) {
            if (isPrime(i) && isPrime(n - i)) {
                cout << i << " " << (n - i);
                break;
            }
        }
    }
}
 
// Driver code
int main()
{
    int n;
    //findPrimes(n); 
    cin>>n;
    return 0;
}