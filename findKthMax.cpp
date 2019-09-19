#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

int cmp ( const void *a , const void *b )
{

    //return *(int *)a - *(int *)b;  //升序排序
    return *(int *)b - *(int *)a; //降序排序
}
template<typename T>
void sort(T a[], int p, int r)
{
    for(int i = p; i <= r; i ++)
    {
        int m = i;
        for(int j = i + 1; j <= r; j ++)
        if(a[j] < a[i]) m = j;
        if(m != i)
        {
            T temp = a[i];
            a[i] = a[m];
            a[m] = temp;
        }
    }
}

template<typename T>
int partition(T a[], int p, int r, T x)
{
    int mid_index = 0;
    for(int i = p; i <= r; i ++)
    {
        if(a[i] == x)
        {
            mid_index = i;
            break;
        }
    }
    T temp1 = a[mid_index];
    a[mid_index] = a[p];
    a[p] = temp1;
    int l = p;
    int m = r + 1;
    while(true)
    {
        while(a[++l] > x && l <= r);
        while(a[--m] < x);
        if(l >= m)
        {
            break;
        }
        T temp2 = a[l];
        a[l] = a[m];
        a[m] = temp2;
    }
    a[p] = a[m];
    a[m] = x;
    return m;
}

template<typename T>
T find_kth_max(T a[], int p, int r, int k)
{
    if(r - p < 75)
    {
        qsort(a + p, r - p + 1, sizeof(T), cmp);
        return a[p + k - 1];
    }
    for(int i = 0; i <= (r - p - 4) / 5; i ++)
    {
        sort(a, p + 5 * i, p + 5 * i + 4);
        T mid_i = a[p + 5 * i + 2];
        a[p + 5 * i + 2] = a[p + i];
        a[p + i] = mid_i;
    }
    T x = find_kth_max(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10);
    int i = partition(a, p, r, x);
    int j = i - p + 1;
    if(k <= j) return find_kth_max(a, p, i, k);
    else return find_kth_max(a, i + 1, r, k - j);
}

int main()
{
    srand(int(time(0)));
    int data[1000];//下面随机生成一千个互不相等的0-9999的随机数
    for(int i = 0; i < 1000;)
    {
        data[i] = rand() % 9999;
        bool flag = false;
        for(int j = 0; j < i; j ++)
        {
            if(data[j] == data[i])
            {
                flag = true;
                break;
            }
        }
        if(flag) continue;
        i ++;
    }
    cout <<"The 25th max num is "<< find_kth_max(data, 0, 999, 25) << "!" <<endl;
    qsort(data, 1000, sizeof(int), cmp);
    cout<< "The correct num is " << data[24] <<endl;
    for(int i = 0; i <= 25; i++) cout << data[i]<<" ";
    getchar();
    return 0;
}