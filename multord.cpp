#include<bits/stdc++.h>
using namespace std;

// function for GCD
int GCD ( int a , int b )
{
    if (b == 0 )
        return a;
    return GCD( b , a%b ) ;
}

// Function return smallest +ve integer that
// holds condition A^k(mod N ) = 1
int multiplicativeOrder(int  N)
{
    if (GCD(10, N ) != 1)
        return -1;

    // result store power of A that raised to
    // the power N-1
    unsigned int result = 1;

    int K = 1 ;
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

//driver program to test above function
int main()
{

    cout<<multiplicativeOrder(297/3)<<endl;
    cout<<multiplicativeOrder(891407)<<endl;
    cout<<multiplicativeOrder(65392029/9)<<endl;


    /*int temp;
    for(int i = 10001 ; i < 1000000 ; i++)
    {
        if (i%2 == 0 || i%5 == 0)
            continue;
        temp = multiplicativeOrder(i);
        if (temp==337 || temp==674 || temp==1011 || temp == 2022)
            cout<<i<<endl;
    }
    */
    return 0;
}
