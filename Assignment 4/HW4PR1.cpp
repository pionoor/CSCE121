//
//  HW4PR1.cpp
//  HW4PR1
//
//  Created by Noor Thabit on 2/13/13.
//  Copyright (c) 2013 Noor Thabit. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

string UpToLow(string x){
    
    string result = x;
    transform(x.begin(), x.end(), result.begin(),::tolower);
    
    
    return result;
    
    
}
int main ()
{
    vector<string> w {"hello","world","i","a","am","the","computer","is","was","can","do","computation","fast","slow","program","c++"} ;
    
    
    string temp;
    string lower;
    cout<<"Enter a word, type 'quit' to exit the program: ";
    
    while (cin>>temp){
        
        lower= UpToLow (temp);
        if (lower=="quit") {break;}
        for (unsigned int i=0; lower != w[i]; i++){
            if (i== w.size()-1) {cerr<<"The word '"<<temp<<"' is misspelled"<<endl; break;}
            
            
        }
        
        
        
    }
    
    
    return 0;
}
