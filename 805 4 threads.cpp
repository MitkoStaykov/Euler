#include<bits/stdc++.h>
using namespace std;
#define m 1000000007

// Recursive function to return (x ^ n) % m
long long modexp(long long x, long long n)
{
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 0) {
        return modexp((x * x) % m, n / 2);
    }
    else {
        return (x * modexp((x * x) % m, (n - 1) / 2) % m);
    }
}

// Function to return the fraction modulo mod
long long getFractionModulo(long long b)
{


    // (b ^ m-2) % m
    long long d = modexp(b, m - 2);

    // Final answer
    return d % m;

}

long long GCD ( long long a , long long b )
{
    if (b == 0)
        return a;
    return GCD( b , a%b ) ;
}

// Function return smallest +ve integer that
// holds condition A^k(mod N ) = 1
long long multiplicativeOrder(long long  N)
{
    if (GCD(10, N ) != 1)
        return -1;

    // result store power of A that raised to
    // the power N-1
    long long result = 1;

    long long K = 1 ;
    while (K < N)
    {
        // modular arithmetic
        result = (result * 10) % N ;

        // return smallest +ve integer
        if (result  == 1)
            return K;

        // increment power
        K++;
    }

    return -1 ;
}


//int grid = 20;
long long result = 0;

void func(long long starti, long long endi,long long startj, long long endj)
{

long long temp = 0;
long long mord = 0;
long long a = 1;
for (long long i = starti ; i < endi+1 ; i++)
    {for (long long j = startj ; j < endj+1 ; j++)
        {   a=1;
            if (i==j)
                continue;
            if (GCD(i,j)!=1)
                continue;

            long long i3=i*i*i;
            long long j3=j*j*j;

            //if (i3>5*j3)
            //    continue;

            temp = 10*j3-i3;

            if (temp < 0)
                continue;

            if(temp%10==0)
                continue;

            if(temp%2==0 && temp%3!=0)
                {
                    if(3*i3>10*j3)
                        continue;
                    a=2;
                    goto calc;
                }
            if(temp%5==0)
                {
                    if(3*i3>5*j3)
                        continue;
                    a=5;
                    goto calc;
                }
            if(temp%6==0)
                {

                if(multiplicativeOrder(temp/6) < multiplicativeOrder(temp/2) && 7*i3<10*j3  )
                    {
                        a=6;
                        goto calc;
                    }
                else if ( 3*i3<10*j3 )
                    {
                        a=2;
                        goto calc;
                    }
                else continue;

                }


            if(temp%9==0)
                {
                    if( multiplicativeOrder(temp/9) < multiplicativeOrder(temp) && i<j )
                    {
                        a=9;
                        goto calc;
                    }
                    else if (multiplicativeOrder(temp/3) < multiplicativeOrder(temp) && 2*i3<5*j3)
                        {
                            a=3;
                            goto calc;
                        }
                    else if (i3<5*j3)
                        {
                            a=1;
                            goto calc;
                        }
                    else continue;
                }
            if(i3>5*j3)
                    {
                        //cout<<"failed 1 "<<i<<" "<<j<<endl;
                        continue;
                    }




            calc:
            mord = multiplicativeOrder(temp/a);
            if (mord < 1)
                continue;
            //cout<<i<<" "<<j<<" "<<temp<<"*m="<<a<<"*10^"<< mord<<"  res="<<j*j*j*((modexp(10,mord)-1)*getFractionModulo(temp/a)%m) % m<<endl;

            result += j3*((modexp(10,mord)-1)*getFractionModulo(temp/a)%m) % m;
            result %= m;
        }
        cout<<i<<endl;
    }
cout<<"thread"<<starti<<"to "<<endi<<" finished"<<endl;
}



int main()
{
//int grid = 200;
    result++;
    std::thread first (func,1,46,1,200);
    std::thread second (func,47,95,1,200);
    std::thread third (func,96,144,1,200);
    std::thread fourth (func,145,200,1,200);

 /*   std::thread first (func,1,5,1,20);
    std::thread second (func,6,10,1,20);
    std::thread third (func,11,15,1,20);
    std::thread fourth (func,16,20,1,20);
*/
    first.join();
    second.join();
    third.join();
    fourth.join();
    cout<<result;
    return 0;
}
//124294245 2
//563255889
//221438808 - n=20 bez 369
//654313409 - n20 sys 2369
//724050044 - n20 fixed
//683413573 n200 not fixed 9
//675405573 n200 fixed 10 100
//193551722 n20 mult 369 fixed
//648442494  n200 mult 369 fixed
//293389654 n20 mult 39 fixed LAST STABLE
//896721945  n200 mult 39 fixed LAST STABLE
//742915011 n20 fix if (i*i*i>=5*j*j*j) check WRONG
//834197076 n200 fix if (i*i*i>=5*j*j*j) check WRONG
//896721945  291 s
//834197076  585 s WRONG
//230811060  292 s fix ij inequation
//121405329  327 s fix2 and 6 mord
//525687971  295 s fix3 2 and 6
//957245454  307 s fix 139
//667377928  323 s fix 9->3
//501982226  268 s fix ineq <2
