//
//  main.cpp
//  Project
//
//  Created by Noor Thabit and Karl on 4/11/13.
//  Copyright (c) 2013 Noor Thabit. All rights reserved.
//

#include "fltk/Graph.h"
#include "fltk/Calendar_window.h"
#include "fltk/std_lib_facilities_3.h"
	




using namespace std;
using namespace Graph_lib;


 string printmonthname(int m);



int main()

{

    
    Calendar_window win(4,2013);

    
    win.draw_calendar();
    
    
    return 0;
}








