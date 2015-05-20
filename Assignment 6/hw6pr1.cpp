
#include "fltk/Graph.h"
#include "fltk/Simple_window.h"



int main()

{
    using namespace Graph_lib;
    
    ;

    Simple_window win(Point (100,100),400,400,"Checker Board");
    
    Vector_ref<Rectangle> r1,r2;        
    


    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            
            //drawing two series of rectangles:
            
            r1.push_back(new Rectangle(Point(i*100,j*50),50,50));
            r2.push_back(new Rectangle(Point((i*100)+50,j*50),50,50));
            
            
            
            r1[r1.size()-1].set_fill_color(0xFEECA600); //fill color with yellow.
            r2[r2.size()-1].set_fill_color(0x48790000);  //fill color with green.

        //to alternate the colors, starts with green instead of yellow:
          
            if (j%2!=0) {
               
                
                r1[r1.size()-1].set_fill_color(0x48790000);//fill color with green.
                r2[r2.size()-1].set_fill_color(0xFEECA600);//fill color with yellow.

                
            }
   //to make the rectangle color invisible:
            r1[r1.size()-1].set_color(Color::invisible);
            r2[r2.size()-1].set_color(Color::invisible);

            win.attach(r1[r2.size()-1]);
            win.attach(r2[r2.size()-1]);

            
        }
    }


    
////////////////////////////////////////////////////////////////////////////////////
   
    
    //checkers section:
    
    Vector_ref<Ellipse> red;  // red checkers.
    Vector_ref<Ellipse> red_shadow; //shadows for the red checkers.
    
    Vector_ref<Ellipse> white; // white checkers. 
    Vector_ref<Ellipse> white_shadow;  //shadows for the white checkers.

    
    //draw checkers loop:
    
    for (int i=0; i<4; ++i) {
        
        for (int j=0; j<3; ++j) {
           
            //drawing red checkers, starting with the second rectangle. First and third rows:
            
            red.push_back(new Ellipse(Point(((i*100)+75),(j*50)+25),20,18));
            red_shadow.push_back(new Ellipse(Point(((i*100)+77),(j*50)+26),20,18));
           
            
            //drawing white checkers, starting with the second rectangle. First and third rows:
   
            white.push_back(new Ellipse(Point(((i*100)+75),(j*50)+275),20,18));
            white_shadow.push_back(new Ellipse(Point(((i*100)+77),(j*50)+276),20,18));
            
            //to draw checkers, starting with the first rectangle. Second row:
            
            if (j%2!=0) {
                red.push_back(new Ellipse(Point(((i*100)+25),(j*50)+25),20,18));
                red_shadow.push_back(new Ellipse(Point(((i*100)+27),(j*50)+26),20,18));
                
            }
            
            if (j%2==0){
                white.push_back(new Ellipse(Point(((i*100)+25),(j*50)+275),20,18));
                white_shadow.push_back(new Ellipse(Point(((i*100)+27),(j*50)+276),20,18));
            }
            
            
            
        
            red[red.size()-1].set_fill_color(0xB0000000); //set to red color.
            red[red.size()-1].set_color(Color::invisible);
            
            red_shadow[red_shadow.size()-1].set_fill_color(Color::black);
            red_shadow[red_shadow.size()-1].set_color(Color::invisible);

            
            white_shadow[white_shadow.size()-1].set_fill_color(Color::black);
            white_shadow[white_shadow.size()-1].set_color(Color::invisible);
            
            white[white.size()-1].set_fill_color(0xFEF8F900);  //set to white color.
            white[white.size()-1].set_color(Color::invisible);
            
            
            
            win.attach(red_shadow[red_shadow.size()-1]);
            win.attach(white_shadow[white_shadow.size()-1]);
            win.attach(red[red.size()-1]);
            win.attach(white[white.size()-1]);

        }
    }
    
    
   
    
        
    win.wait_for_button();
    return 0;
    
    
}
