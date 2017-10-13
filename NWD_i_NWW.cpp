#include<iostream>
using namespace std;
int nwd(int a,int b)
{
    while(b)
    {
        a=a%b;
        swap(a,b);
    }
    return a;
}
int nww(int a,int b)
{
    return a*(b/nwd(a,b));
}
int main()
{
    int a,b;
    cin >> a >>  b;
    cout << nwd(a,b) <<"  "<<nww(a,b)<<'\n';
}
