#include<iostream>
#include<cstdio>
using namespace std;

int partition(int n,int m)
{
    if(n == 1) return 1;
    else if(m == 1) return 1;
    else if(n < m) return partition(n,n);
    else if(n == m) return (1 + partition(n,m-1));
    else return (partition(n,m-1) + partition(n-m,m));
}
int main()
{
    cout<<partition(3,3);
    getchar();
    return 0;
}