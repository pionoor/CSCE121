//
//  HW5PR1.cpp
//  HW5PR1
//
//  Created by Noor Thabit on 2/13/13.
//  Copyright (c) 2013 Noor Thabit. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

void Lower(string &x){
    
    
    for (unsigned int i=0; i<x.length(); ++i) {x[i]=tolower(x[i]);}
    
    
    
}


void clean(string &x){
    
    for (unsigned int i=0; i<x.length(); ++i) {
        switch (x[i]) {
           case ';': case '!': case '.': case '?': case ',':
                x[i]=' ';
                
            }
    }
    
    
}



int main ()
{
    vector<string> dictionary {"hello","world","i","a","am","the","computer","is","was","can","do","computation","fast","slow","program","c++","and"} ;
    
    
    string line;
    cout<<"Enter a word, type 'quit' to exit the program: ";
    
    
    while (getline(cin, line)){
       
        clean(line);    // clean the line from any punctuation chars and replace them with white spaces. 
        stringstream stream(line);
        string word;
        
        while (stream>>word) {
        
        Lower (word);
        if (word=="quit") {break;}
        for (unsigned int i=0; word != dictionary[i]; ++i){
            if (i== dictionary.size()-1) {cerr<<"The word '"<<word<<"' is misspelled"<<endl; break;}
            
        }
        }
    }
        return 0;
}

    
    

