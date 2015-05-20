//
//  main.cpp
//  hw1pr2
//
//  Created by Noor Thabit on 1/28/13.
//  Copyright (c) 2013 Noor Thabit. All rights reserved.
//

#include <iostream>
using namespace std; 
int main()

{
    int val1 = 0;
    int val2 = 0;
    
    cout<<"Please enter two integer numbers separated by a space: ";
   
    while (cin>>val1>>val2)
    {
    cout<<"\nEnterd values: "<<val1<<','<<val2<<endl;
    
    if (val1 > val2) cout<<val2<<" = The smallest value.";
        else cout<<val1<<" = The smallest value."<<endl;
    if (val1 > val2) cout<<val1<<" = The largest value."<<endl;
        else cout<<val2<<" = The largest value."<<endl;
    
    cout<<"Sum = "<<val1+val2
        <<"\nDiffrence = "<<val1-val2
        <<"\nProduct = "<<val1*val2;
    if (val2==0)
        cout<<"\nCannout divide by Zero!";
    else cout<<"\nRation = "<<val1<<'/'<<val2
        <<endl;
         return (0);
    }
    cout<<"Sorry, you have to enter numbers only";
    
    
}

