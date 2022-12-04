#include <iostream>
#include <memory>
using namespace std;

int main ()
{
    shared_ptr<int>ptr = make_shared<int>(10);
    cout<<"in main"<<endl;
    return 0;
}