//
//  main.cpp
//  HW4PR3
//
//  Created by Noor Thabit on 2/21/13.
//  Copyright (c) 2013 Noor Thabit. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;



    void fibonacci(int x, int y, vector<unsigned long int>& v, int n) //Fibonacci funtion calculator 
    {
        
        v.push_back(x);
        v.push_back(y);
        
        
        for (int i=2; i<n; ++i) {
            int sum = x+y;
            v.push_back(sum);
            x = y;
            y = sum;}
    }


    
    int main()
    {
        vector<unsigned long int>v;
        int x(0);
        int y(0);
        int n(0);
        cout<<"Enter two integer numbers to start a fibonacci series, and the number of the elements of the sereis: ";
        
        while (cin>>x>>y>>n && n>=3){
            
            fibonacci(x, y, v, n);

            
          
            
                cout<<"fibonacci"<<"["<<v.size()<<"] = {";
                for (unsigned int i=0; i<v.size(); i++) {
                    cout<<v[i];
                    
                    if (i<v.size()-1) { cout<<", ";}

               
                }
            cout << "}\n";
            float last=v[n-1], nlast=v[n-2]; // "last" is the last term of the series, and "nlast" is the next to the last term in the series
           
            float result = (last/nlast);
            cout<<"The last term diveded by the next-to-last = " <<result<<endl;
            
            return 0;
        }
        cout<<"The number of the elements of the series must be at least 3!";
        
        }
    
