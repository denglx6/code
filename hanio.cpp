#include<iostream>
#include<cstdio>
using namespace std;

void hanio(int n, int a, int b, int c)
{
    if(n > 0)
    {
        hanio(n-1, a, c, b);
        cout<<n<<","<<a<<","<<b<<endl;
        hanio(n-1, c, b, a);
    }
}
int main()
{
    hanio(6, 1, 2, 3);
    getchar();
    return 0;
}