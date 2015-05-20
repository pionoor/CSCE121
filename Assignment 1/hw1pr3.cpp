//
//  main.cpp
//  hwpr3
//
//  Created by Noor Thabit on 1/28/13.
//  Copyright (c) 2013 Noor Thabit. All rights reserved.
//

#include <iostream>

using namespace std;
int main ()


{
    string operation;
    double n1=0;
    double n2=0;
    cout<<"Please enter one of listed operations [+, -, *, /, plus, minus, mul, div] followed by two numbers, saparated by a space:";
    
    while (cin>>operation>>n1>>n2)
    {
        double result = 0;
		if (operation=="+" || operation=="plus") result = n1+n2;
		else if (operation=="-"|| operation=="minus") result = n1-n2;
		else if (operation=="*" || operation=="mul") result = n1*n2;
		else if (operation=="/" || operation=="div") {
			if (n1==0) cout<<"cannot devide by Zero!";
               else result = n1/n2;}
        cout<<n1<<' '+operation+' '<<n2<<" == "<<result<<endl;
        
    }
    
    cout<<"Bad input! Make sure they are in order";
    
    return 0;
    
}

