#include <iostream>
#include<time.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
long double power_iterative(long double n,int p)
{

    long double result=1;
    for(int i=1;i<=p;i++)
    {
        result *= n;
    }

    return result;
}
void print_iterative(long double n,int p)
{
      long double z = power_iterative(n,p);
     cout <<"The result using Iterative function power is : "<<z<<" , And takes time complexity : "<<" O(N) "<<endl;

}
long double power_recursive(long double n,int p)
{
    if(p==1)
    {
        return n;
    }
    else
    {
        return power_recursive(n,p-1)*n;
    }
}
void print_recursive(long double n,int p)
{

     long double z =power_recursive(n,p);
     cout <<"The result using Recursive function power is : "<<z<<" , And takes time complexity : "<<" O(N)"<<endl;

}
long double optimize_power_iterative(long double n,int p)
{
    int x = p/2.0;
    long double result=1;
    for(int i=1;i<=x;i++)
    {
        result *=n;
    }
    if(p%2==0)
        return result * result;
    else
        return result * result * n;
}
void print_optimize_iterative(long double n,int p)
{

     long double z =optimize_power_iterative(n,p);
     cout <<"The result using Iterative optimize function power is : "<<z<<" , And takes time complexity : "<<" O(LOG(N))"<<endl;

}
long double optimize_power_recursive(long double n,int p)
{
    long double result;
    if(p==1)
        return n;
    else
    {
         result = optimize_power_recursive(n,p/2.0);
    }
    if(p%2==0)
        return result * result;
    else
        return result * result * n;
}
void print_optimize_recursive(long double n,int p)
{
     long double z =optimize_power_recursive(n,p);
     cout <<"The result using Recursive optimize function power is : "<<z<<" , And takes time complexity : "<<" O(LOG(N))"<<endl;

}

int main()
{
    time_t total_start,total_end;
     total_start = clock();
     auto s= high_resolution_clock::now();
    long double number;
    int power;
    cout <<"Please , Enter a number : "<<endl;
    cin >>number;
    cout <<"Please , Enter a power number : "<<endl;
    cin >>power;
    while(power<0)
    {
       cout <<"Please , Enter a positive number for power again : "<<endl;
        cin >>power;
    }
    print_iterative(number,power);
    print_recursive(number,power);
    print_optimize_iterative(number,power);
    print_optimize_recursive(number,power);
    total_end = clock();
    auto e = high_resolution_clock::now();
    auto timesx=duration_cast<microseconds>(e-s);
    cout << "The time complexity of this program is : "<<timesx.count()<<" Micro Seconds . ";

    return 0;
}
