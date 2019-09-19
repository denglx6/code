#include <iostream>
#include <cstdio>
using namespace std;
//a为存放待组合的元素，b为用于暂存的数组
//n，m代表从n中取出m个数的组合 
// M=m M用于输出 
void comb(char a[],char b[],int n, int m,const int M)
{
	if (m>0)
	{
		for (int i = n; i >= m; i--)
		{
			b[m - 1]=a[i - 1];
			comb(a, b, i - 1, m - 1, M);
		}
	}
	else 
	{
		for(int i = 0 ; i < M; i++)
			cout<<b[i]<<" ";
		cout<<endl; 
	}
 
}
 
int main ()
{
	//char arr[] = "1abd5";
	char arr[] = "1234567";
	//char b[2];
	char b[4];
	//comb(arr, b, 5, 2, 2);
	comb(arr, b, 7, 4, 4); 
    getchar();
	return 0;
} 
