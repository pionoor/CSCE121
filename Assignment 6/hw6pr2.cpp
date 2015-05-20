
#include "fltk/Graph.h"
#include "fltk/Simple_window.h"




struct Parallelogram : Polygon {
    
    Parallelogram(Point tl, Point tr, Point bl)
    
    {
        Point br((bl.x+(tr.x-tl.x)),bl.y+(tr.y-tl.y)); //forth point.

        
        add(tl);
        add(tr);
        add(br);
        add(bl);
        
    }
     
    

};

 

int main()

{
    using namespace Graph_lib;
    
    Simple_window win(Point(0,0),600,400,"Parallelogram");
    
    Parallelogram p1(Point(20,20),Point(120,20),Point(30,70)); //first Parallelogram.
    p1.set_fill_color(Color::white);                           //fill with white color
    p1.set_color(Color::invisible);                            //make the it invisiable 

    Parallelogram p2(Point(30,80),Point(130,80),Point(20,130)); 
    p2.set_fill_color(Color::yellow);
    p2.set_color(Color::invisible);

    
    Parallelogram p3(Point(130,20),Point(230,20),Point(140,70));
    p3.set_fill_color(Color::red);
    p3.set_color(Color::invisible);

    Parallelogram p4(Point(140,80),Point(240,80),Point(130,130));
    p4.set_fill_color(Color::green);
    p4.set_color(Color::invisible);


    
    
    win.attach(p1);
    win.attach(p2);
    win.attach(p3);
    win.attach(p4);

    win.wait_for_button();
    return 0;

                    }