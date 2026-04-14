int gcd(int x,int y)//最大公约数 欧几里得算法 辗转相除法
{
    return y==0?x:gcd(y,x%y);
}
//cout<<__gcd(x,y);

int lcm(int a,int b)//最小公倍数
{
    return (int)a*b/gcd(a,b);
}