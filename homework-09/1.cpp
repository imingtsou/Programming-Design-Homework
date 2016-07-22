#include <iostream>
using namespace std;
char str[110];
auto func = [] (char ch)
{
    int num = 0;
    int len = strlen(str);
    for (int i = 0;i < len;i++) if (str[i] == ch) num++;
    cout<<num<<endl;
};
int main(int argc, const char * argv[])
{
    strcpy(str,"Hello World!");
    func('e');
    func('l');
    return 0;
}
