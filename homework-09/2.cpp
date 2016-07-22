#include <iostream>
#include <memory>
using namespace std;
char str[20];
void deviate(int k)
{
    shared_ptr<char>p(new char[20]);
    strcpy(p.get(),"Hello World!");
    string str1 = p.get() + strlen("Hello World!") - k;
    cout<<str1;
    *(p.get() + strlen("Hello World!") - k) = '\0';
    str1 = p.get();
    cout<<str1<<endl;
}
int main(int argc, const char * argv[])
{
    deviate(1);
    deviate(3);
    return 0;
}
