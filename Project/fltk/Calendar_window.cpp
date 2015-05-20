

#include "Calendar_window.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Calendar_window::Calendar_window(int m, int y) : 
    Window(Point(20,20), 895, 701,"Calendar"),


    next_button(Point(x_max()-41,10), 30, 30, ">", cb_next),
    previous_button(Point(x_max()-71,10), 30, 30, "<", cb_previous),
    appointment_button(Point(x_max()/2,10), 30, 30, "+", cb_appointment),
    app_input(Point(x_max()-560,10), 100, 30, ""),

    day(1),
    month(m),
    year(y)



{

    attach(next_button);
    attach(previous_button);
    attach(appointment_button);
    attach(app_input);

}

//------------------------------------------------------------------------------
// the call back functions for the buttons

void Calendar_window::cb_next(Address, Address pw)

{
    reference_to<Calendar_window>(pw).next_month();
}


void Calendar_window::cb_previous(Address, Address pw)

{
    reference_to<Calendar_window>(pw).previous_month();
}

void Calendar_window::cb_appointment(Address, Address pw)

{
    reference_to<Calendar_window>(pw).appointment();
}

//-------------------------------------------------------------------------------
void Calendar_window::draw_days_header() // draw the name of the days insde the firs row of the grid.

{
    Vector<string> day_name={"Sun","Mon", "Tue","Wed", "Thu", "Fri", "Sat"};

    Vector_ref<Text>day_header;

    Text * sun = new Text(Point(102,70), "Sun");
    sun->set_font_size(13);
    attach(*sun);

    Text * mon = new Text(Point(226,70), "Mon");
    mon->set_font_size(13);
    attach(*mon);

    Text * tue = new Text(Point(352,70), "Tue");
    tue->set_font_size(13);
    attach(*tue);

    Text * wed = new Text(Point(472,70), "Wed");
    wed->set_font_size(13);
    attach(*wed);

    Text * thu = new Text(Point(602,70), "Thu");
    thu->set_font_size(13);
    attach(*thu);

    Text * fri = new Text(Point(735,70), "Fri");
    fri->set_font_size(13);
    attach(*fri);

    Text * sat = new Text(Point(855,70), "Sat");
    sat->set_font_size(13);
    attach(*sat);

}


//------------------------------------------------------------------------------


void Calendar_window::draw_grid() // draw the grids which consists of squares that represents the days of the month.
{
    Vector<Rectangle*>squares;
    
        for (int i=0; i<7;i++) {
            for (int j=0; j<6; j++) {
        
                
                squares.push_back(new Rectangle(Point((i*125)+10,(j*106)+55),123,104 ));
        
                squares[squares.size()-1]->set_style(Line_style(Line_style::dash,1));
        
                attach(*squares[squares.size()-1]);
        
        
            }
        }

}
//--------------------------------------------------------------------------------


void Calendar_window::draw_month_year_lable() // draw the name of the month and the year on the top left corner.
{
    
    vector<string>month_name={"Jan, ","Feb, ","Mar, ","Apr, ","May, ","Jun, ", "Jul, ", "Aug, ","Sept, ", "Oct, ", "Nov, ", "Dec, "};
    
    string year_string;          // string which will contain the result
    
    ostringstream convert;   // stream used for the conversion
    
    convert << year;      // insert the textual representation of 'Number' in the characters in the stream
    
    year_string = convert.str();
    
    
    month_lable = new Text(Point(11,30),month_name[month-1]);
    year_lable = new Text(Point(55,30),year_string);
    
    
    month_lable->set_font_size(20);
    year_lable->set_font_size(20);
    
    
    attach(*month_lable);
    attach(*year_lable);
    redraw();

    
}

//----------------------------------------------------------------------------------


void Calendar_window::erase_numbering() // this function is called whenever the user hit the next or the previous buttons. It detachs the name of the month, and the year at the top left corner.

{
    detach(*month_lable);
    detach(*year_lable);
    for(unsigned int i = 0; i < numbering_count.size(); ++i) {detach(*numbering_count[i]);}
   
}

//--------------------------------------------------------------------------------

int Calendar_window::start_day() // calculate and return an integer which is used to determine each month's first day. 
{
    int start_day = (((day + int(((month+1)*26))/10)+ year + int(year/4) + int(6*(year/100)) + int(year/400))%7);

    switch (start_day) {
    case 0: return 0;
            
    case 1: return 6;
        
    case 2: return 5;

    case 3: return 4;

    case 4: return 3;

    case 5: return 2;

    case 6: return 1;

    }
}

//--------------------------------------------------------------------------------

void Calendar_window::draw_numbering() // this function draw the numbering of the month.

{
    Vector<string> days_counts_31={"  ", "  ", "  ", "  ", "  ", "  ", "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", " ", " ", " ", " ", " ", " ",};
    
    Vector<string> days_counts_30={"  ", "  ", "  ", "  ", "  ", "  ", "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "11",   "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", " ", " ", " ", " ", " ", " "};
  
    Vector<string> days_counts_28={"  ", "  ", "  ", "  ", "  ", "  ", "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10"," 11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", " ", " ", " ", " ", " ", " "};
        
    Vector<string> days_counts_29={"  ", "  ", "  ", "  ", "  ", "  ", "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10"," 11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", " ", " ", " ", " ", " ", " "};
    
    
    
    int d = start_day();
    
    int columns=5;
    
    if (start_day()==0) {columns=6;}
    
    
    for (int i=0 ; i<columns;i++) {
        for (int j=0; j<7; j++) {
            
            switch (month) {
                    
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    numbering_count.push_back(new Text(Point((j*125)+15,(i*106)+70),days_counts_31[d]));
                    break;
                  
                case 2:
                    
                    if(isleapyear(year)==0){
                        numbering_count.push_back(new Text(Point((j*125)+15,(i*106)+70),days_counts_29[d]));
                    }
                    else numbering_count.push_back(new Text(Point((j*125)+15,(i*106)+70),days_counts_28[d]));
                    break;
                    

                case 4: case 6: case 9: case 11:
                    numbering_count.push_back(new Text(Point((j*125)+15,(i*106)+70),days_counts_30[d]));
                    break;
               
            }
            

            numbering_count[numbering_count.size()-1]->set_font_size(14);

            numbering_count[numbering_count.size()-1]->set_color(0x8B008B00);

            attach(*numbering_count[numbering_count.size()-1]);
            
            
            if (d==days_counts_31.size()-1){break;}
            
            ++d;
            
        }
    }
    redraw();

    gui_main();
    
    }


//----------------------------------------------------------------------------------



int Calendar_window::gettotalday(int year, int month) 
{
    int totalday=6;
    int delta;
    for(delta=2000;delta<year;delta++)
    {
        if(isleapyear(delta)==0)
            totalday+=2;
        else
            totalday+=1;
    }
    int delt=1;
    for(;delt<month;delt++)
        totalday+=getnumberofdayinmonth(year,delt);
    return totalday%7;  
}

//----------------------------------------------------------------------------------


int Calendar_window::getnumberofdayinmonth(int year, int month) // calculate returnes the numbers of days each month that passed to it
{
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        return 31;
    else if(month==4||month==6||month==9||month==11)
        return 30;
    else if(month==2) {
        if(isleapyear(year)==0)
            return 29;
        else if(isleapyear(year)==1)
            return 28;
    }  
    
}



//----------------------------------------------------------------------------------


int Calendar_window::isleapyear(int year)
{
    if(year%400==0||(year%4==0&&year%100!=0))
        return 0;
    else return 1;
}



//----------------------------------------------------------------------------------






void Calendar_window::appointment()
{
    
}

//------------------------------------------------------------------------------

void Calendar_window::draw_calendar() // this function draw the whole calendar by calling the functions that the grid, days names, and the month numbering.
{
    draw_month_year_lable();
    draw_days_header();
    draw_grid();
    draw_numbering();
}

//------------------------------------------------------------------------------

void Calendar_window::next_month() //this function called when the next button pushed.
 
 {
     erase_numbering();

     if (month==12){month=1; ++year;}
     else ++month;
     draw_month_year_lable();

     draw_numbering();

     

 
 }

//-----------------------------------------------------------------------------

void Calendar_window::previous_month() //this function called when the previous button pushed.
 {
     erase_numbering();

     if (month==1){month=12; --year;}
     else --month;
     draw_month_year_lable();
     draw_numbering();


 }

 
 



