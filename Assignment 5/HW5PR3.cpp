//
//  HW5PR3.cpp
//  HW5PR3
//
//  Created by Noor Thabit on 3/8/13.
//  Copyright (c) 2013 Noor Thabit. All rights reserved.
//

#include <iostream>
#include "chrono/Chrono.cpp"

using namespace Chrono;

int main()

{
    
    Date x;
    cout<<"Enter a date (YYYY,MM,DD): ";
    cin>>x;
    ++x;
    cout<<"Tomorrow is: "<<x;
    
    return 0;
}