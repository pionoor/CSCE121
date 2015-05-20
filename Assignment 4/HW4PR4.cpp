//
//  main.cpp
//  HW4PR4
//
//  Created by Noor Thabit on 2/21/13.
//  Copyright (c) 2013 Noor Thabit. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//a function check if the url starts with "http://" and ends with ".pdf".

bool urlCheck(string &url)
{
    bool result=true;
   
    string low_url=url;
    transform(url.begin(), url.end(), low_url.begin(),::tolower);//converts url to lower case.
    
    unsigned long int length=low_url.length();
    
    if (length<=8)
    {
        result=false;
        cerr<<"URL is too short"<<endl;
        return result;
    }
    
    
    string http=low_url.substr(0,7);
    string pdf=low_url.substr(length-4,4);
    
    
    if (http!="http://")
    {
        result=false;
        cerr<<"'http://' is missing, or misspelled";
        return result;
    }
    
    if (pdf!=".pdf")
    {
        result=false;
        cerr<<"URL is missing .pdf extesion"<<endl;
        return result;

    
    }
    
    return result;
    

}

int main()
{

    string temp;
    
    cout<<"Enter the URL of the pdf file to grab: ";
    while (cin>>temp)
    {
   
    bool check=urlCheck(temp);
        
    if (check==true) {
        string url="wget "+temp+" -O webfile.pdf";
        system(url.c_str());
        system("xpdf webfile.pdf");
       }
    }
    
  

    return 0;
}

