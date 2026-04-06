const int mod=1e9+7;
long long ksm(int a,int b)
{
    long long t=a;//存储a的幂
    long long ans=1;//存储需要的值
    while(b)
    {
        if((b&1)==1)//若最后一位为一，则该地方有值，需要乘进ans
        {
            ans=ans*t%mod;
        }
        t=t*t%mod;//升位
        b>>=1;
    }
    return ans;
}