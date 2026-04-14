void prime_factorize(int x)//质因数分解
{
    for(int i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            x /=i;
            a.push_back(i);
        }
    }
    if(x>1)
    a.push_back(x);//此时x剩下的值为一个质数

}