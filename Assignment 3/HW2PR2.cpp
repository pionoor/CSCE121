//
//  main.cpp
//  HW2PR1
//
//  Created by Noor Thabit on 2/7/13.
//  Copyright (c) 2013 Noor Thabit. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
double my_sqrt_1(double n) //creat a function accept double and return adouble
{
    double x=n-1;
    double result = 1 + (1/2)*pow(x,1.0) - (1/8)*pow(x,2.0) + (1/16)*pow(x,3.0) - (5/128)*pow(x,4.0);
    return result;
    
}

int main()
{
    double n;
    double relative_error_per_cent;
    
    for(auto k: {-100,-10,-1,0,1,10,100})
    {
       
         n = 3.14159 * pow(10.0,k);
       
        relative_error_per_cent = 100 * ((my_sqrt_1(n) - sqrt(n))/sqrt(n)); //the relative error as a per cent
        

        cout<<n<<'\t'<<sqrt(n)<<'\t'<<my_sqrt_1(n)<<'\t'<<relative_error_per_cent<<endl ; //prints n, sqrt(n), and my_sqrt_1(n) for n
    }
    
    
    return 0;
}
