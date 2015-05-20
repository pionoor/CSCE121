//
//  main.cpp
//  HW2PR3
//
//  Created by Noor Thabit on 2/7/13.
//  Copyright (c) 2013 Noor Thabit. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
using std::vector;

int main()
{

    vector<string>agg;          //creat a vector name agg, string type.
    string temp;
    cout<<"Enter some words, write 'stop' at the end to get the result: ";
    while (cin>>temp)
    {
        if (temp=="stop")  {break;}  //Whenever the user types '.' at the end of the last word, it will exit the loop.
        
        else if  (temp=="Aggie"||temp=="Aggies") {agg.push_back(temp);}  //it will only reads the words "Aggies" or "Aggie" into the vector agg.
              
    
        }
    
           cout<<"The number of times the words Aggie or Aggies occur in the keyboard input = "<<agg.size()<<endl;  //displays numbers of typed " Aggies" and "Aggie" words.
    
        
    
            
      
    return 0;
}

