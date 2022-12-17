

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
T summer(T v)
{
    return v;
}

template<typename T, typename... Args>
T summer(T first, Args... args)
{
    return first + summer(args...);
}

int main()
{
    cout<<"summer(1,2,13,100)="<<summer(1,2,13,100)<<endl;
    return 0;
}