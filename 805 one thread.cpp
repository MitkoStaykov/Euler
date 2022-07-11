#include<bits/stdc++.h>
//#include <fstream>
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
//ofstream fd;
//fd.open("res.txt");

int grid = 3;
long long temp = 0;
long long result = 1;
long long mord = 0;
long long a = 1;
for (long long i = 1 ; i < grid+1 ; i++)
    {for (long long j = 1 ; j < grid+1 ; j++)
        {
	    a=1;
            if (i==j)
                continue;
            if (GCD(i,j)!=1)
                continue;
            if(i%10==0)
                continue;

            long long i3=i*i*i;
            long long j3=j*j*j;

            if(i3>5*j3)
                continue;

            temp = 10*j3-i3;

                ///////////5
            if(i%5==0 && 3*i3<5*j3)
                {
                    a=5;
                    goto calc;
                }
            if(i%5==0)
                continue;


                //////////////2
            if(i%2==0 && i%3!=0 && 3*i3<10*j3)
                {
                    a=2;
                    goto calc;
                }

            if(temp%6==0 && multiplicativeOrder(temp/6)<multiplicativeOrder(temp/2) && 7*i3<10*j3)
                {
                    a=6;
                    goto calc;
                }
            if(i%2==0 && 3*i3<10*j3)
                {
                    a=2;
                    goto calc;
                }

                ////////////9
            if(temp%3==0 && i<j && multiplicativeOrder(temp/9) < multiplicativeOrder(temp/3))
                {
                    a=9;
                    goto calc;
                }
            if (temp%3==0 && 2*i3<5*j3 && multiplicativeOrder(temp/3) < multiplicativeOrder(temp))
                {
                    a=3;
                    goto calc;
                }

            calc:
            mord = multiplicativeOrder(temp/a);
            /*if (mord < 1)
                {
                    cout <<"UNKN"<<i<<" "<<j<<" "<<mord<<" "<<temp<<" "<<a<<" "<<endl;
                    continue;
                }*/
            cout<<i<<" "<<j<<" "<<temp<<"*m="<<a<<"*10^"<< mord<<"  res="<<j3*((modexp(10,mord)-1)*getFractionModulo(temp/a)%m) % m<<endl;


            result += j3*( ((modexp(10,mord)-1)*getFractionModulo(temp/a)) %m) ;
            //result += ((j*(modexp(10,mord)-1)%m)*j%m)*(j*(getFractionModulo(temp/a)%m) % m)%m;
            result %= m;
        }
        //fd <<"\n";
        cout<<i<<endl;
    }
cout<<result;
    return 0;
}

