#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define SIGN(A) (A > 0 ? 1 : -1)
int divide_and_conquer(int X, int Y, int n) // n必须为2的指数幂
{
    int sign = SIGN(X) * SIGN(Y);
    int x = abs(X);
    int y = abs(Y);
    if(x == 0||y == 0) return 0;
    else if(n == 1) return (x * y * sign);
    else
    {
        int a = (int) x / pow(2, n / 2);
        int b = x - a * pow(2, n / 2);
        int c = (int) y / pow(2, n / 2);
        int d = y - c * pow(2, n / 2);
        int ac = divide_and_conquer(a, c, n / 2);
        int bd = divide_and_conquer(b, d, n / 2);
        int ad_plus_bc = divide_and_conquer(a - b, d - c, n / 2) + ac + bd;
        return (ac * pow(2, n) + ad_plus_bc * pow(2, n / 2) + bd) * sign;
    }
    


}
int main()
{
    //cout<<SIGN(-1155)<<endl;
    cout << "1155 * 1999 true value is " << 1155 * 1999 << endl << "and divide_and_conquer method result is " << divide_and_conquer(1155, 1999, 8) << endl;//样例1
    cout << "28888 * 56789 true value is " << 28888 * 56789 << endl << "and divide_and_conquer method result is " << divide_and_conquer(28888, 56789, 16) << endl;//样例2
    getchar();
    return 0;
}