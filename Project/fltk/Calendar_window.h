
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef CALENDAR_WINDOW_GUARD
#define CALENDAR_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Calendar_window : Graph_lib::Window {
    Calendar_window(int m, int y);

    void draw_calendar();
    
private:
    
    int day;
    int month;
    int year;
    Vector<Text*>numbering_count;
    Text * month_lable;
    Text * year_lable;
    
    Button next_button;     // the "next" button
    Button previous_button;
    Button appointment_button;
    In_box app_input;
   
    
    int gettotalday(int year, int monh);
    int getnumberofdayinmonth(int year, int month);
    int isleapyear(int year);
    int start_day();

    void draw_month_year_lable();
    void next_month();
    void previous_month();
    void draw_days_header();
    void draw_grid();
    void draw_numbering();
    void erase_numbering();
    
    
    
    
    bool button_pushed;     // implementation detail

    static void cb_next(Address, Address); // callback for next_button
    static void cb_previous(Address, Address);
    static void cb_appointment(Address, Address);
  
    void appointment();
    

};




//------------------------------------------------------------------------------

#endif // CALENDAR_WINDOW_GUARD
