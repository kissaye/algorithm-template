#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=101001;
const int mod=1e9+7;
int n;
int fact[N],infact[N];//阶乘//阶乘逆元
//快速幂求逆元
int fast_power(int a,int b)
{
    int ans=1;
    int t=a;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*t)%mod;
        }
        t=(t*t)%mod;
        b>>=1;
    }
    return ans;
}
int main ()
{
    fact[0]=infact[0]=1;
    //1.预处理分子的阶乘
    for(int i=1;i<N;i++)
    {
        fact[i]=(ll)fact[i-1]*i%mod;
    }
    //2.逆元优化成线性，先求出最大的逆元
    infact[N-1]=fast_power(fact[N-1],mod-2);
    //3.从大到小反推分母的阶乘逆元
    for(int i=N-2;i>=1;i--)
    {
        infact[i]=(ll)infact[i+1]*(i+1)%mod;
    }
    cin>>n;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        //C(a,b)=a!*(b!)^-1*((a-b)!)^-1;
        if (b > a) 
        {
        cout << 0 << '\n';
        continue;
        }
        cout << (ll)fact[a] * infact[b] % mod * infact[a-b] % mod << '\n';

    }
    return 0;

}