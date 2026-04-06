#include<bits/stdc++.h>
using namespace std;
//简单数论 质数
//试除法
bool is_prime(int n)
{
    if(n<2)
    return false;
    for(int i=2;i<=n/i;i++)//等价于i*i<=n,为了避免溢出
    {
        if(n%i==0)
        return false;
    }
    return true;
}
//埃氏筛法
const int N=10002;
bool f[N];
vector<int> a;

void init()
{
    for(int i=2;i<=N;i++)
    {
        if(f[i])
        continue;//如果被标记了就下一个
        a.push_back(i);
        for(int j=i;j<=N;j+=i)
        {
            f[j]=1;
        }
    }
    for(auto i:a)
    {
        cout<<i<<'\n';
    }
}

//欧拉筛法 线性