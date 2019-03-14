// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
using namespace std;
void foo() 
{
  // do stuff...
}

void bar(int x)
{
  // do stuff...
}

int main() 
{
  thread first (foo);     // spawn new thread that calls foo()
  thread second (bar,0);  // spawn new thread that calls bar(0)

  cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  cout << "foo and bar completed.\n";

  return 0;
}