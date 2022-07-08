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
    if (b == 0 )
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

int main()
{
int grid = 9;
long long temp = 0;
long long result = 1;
long long mord = 0;
long long a = 1;
for (long long i = 1 ; i < grid+1 ; i++)
    {for (long long j = 1 ; j < grid+1 ; j++)
        {   a=1;
            if (i==j)
                continue;
            if (GCD(i,j)!=1)
                continue;

            long long i3=i*i*i;
            long long j3=j*j*j;

            temp = 10*j*j*j-i*i*i;

            if (temp < 0 )
                continue;

            if(temp%10==0)
                continue;

            if(temp%2==0 && temp%3!=0)

                {
                    if(3*i*i*i>10*j*j*j)
                        {
        //                    cout<<" check failed 2 "<<i<<" "<<j<<endl;
                            continue;
                        }
                    a=2;
                    goto calc;
                }

            if(temp%5==0)

                {
                    if(3*i*i*i>5*j*j*j)
                        {
        //                    cout<<" check failed 5 "<<i<<" "<<j<<endl;
                            continue;
                        }
                    {
       //                 cout<<" check 5 "<<i<<" "<<j<<endl;
                        a=5;
                        goto calc;
                    }

                }

            if(temp%6==0)
                {
                if(multiplicativeOrder(temp/6) < multiplicativeOrder(temp/2) && 7*i*i*i<10*j*j*j)
                    {
        //                cout<<" check 6! "<<i<<" "<<j<<endl;
                        a=6;
                        goto calc;
                    }
                else if ( 3*i*i*i<10*j*j*j )
                    {
        //                cout<<" check 6 to 2 "<<i<<" "<<j<<endl;
                        a=2;
                        goto calc;
                    }
                else {
        //                cout<<" check failed 6 "<<i<<" "<<j<<endl;
                        continue;
                     }
                }



            if( temp%9==0 )
                {

                    if( multiplicativeOrder(temp/9) < multiplicativeOrder(temp) && i<j )
                         {
       //                     cout<<" check 9! "<<i<<" "<<j<<endl;
                            a=9;
                            goto calc;
                        }
                    else if (multiplicativeOrder(temp/3) < multiplicativeOrder(temp) && 2*i*i*i<5*j*j*j)
                         {
       //                     cout<<" check 9 to 3 "<<i<<" "<<j<<endl;
                            a=3;
                            goto calc;
                        }
                    else if (i*i*i<5*j*j*j)
                        {
        //                    cout<<"check 9 to 1 "<<i<<" "<<j<<endl;
                            a=1;
                            goto calc;
                        }
                    else
                        {
                            //cout<<"failed 9 "<<i<<" "<<j<<endl;
                            continue;
                        }

                }
                    if(i*i*i>5*j*j*j)
                    {
                        //cout<<"failed 1 "<<i<<" "<<j<<endl;
                        continue;
                    }

            calc:
            mord = multiplicativeOrder(temp/a);
            if (mord < 1)
                continue;
            cout<<i<<" "<<j<<" "<<temp<<"*m="<<a<<"*10^"<< mord<<"  res="<<j3*((modexp(10,mord)-1)*getFractionModulo(temp/a)%m) % m<<endl;


            result += j*j*j*( ((modexp(10,mord)-1)*getFractionModulo(temp/a)) %m) ;
            //result += ((j*(modexp(10,mord)-1)%m)*j%m)*(j*(getFractionModulo(temp/a)%m) % m)%m;
            result %= m;
        }
        cout<<i<<endl;
    }
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
//293389654 n20 mult 39 fixed
//896721945  n200 mult 39 fixed
//666946917 n20 inequations fixed
//924052361 n20 fixed ord2 in 6 case
//160554577 n20 fix2 ord 2 6
//435053746 n20 fix 1 3 9
//736821789 n20 fix 9-3 iiijjj736821789
//501982226 n200 ?fix inex a=1
