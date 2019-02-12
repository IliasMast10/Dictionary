#include "Dictionary.h"
#include<cstdlib>
#include<fstream>
using namespace std;

Dictionary::Dictionary(){
 list<string> temp ;
 myList = temp;
} 

Dictionary::Dictionary(const string& fileName){
    
	ifstream file(fileName.c_str());
	string word;
	
	if(!file){
		cout<<"\nError opening file\n\n";
	} else {
      while( file>>word )
        this->myList.push_back(word); 
    }
}




bool operator== (const Dictionary& d1, const Dictionary& d2){
	
	if(d1.myList.size() != d2.myList.size())
        return false;
		
			
	list<string> ::const_iterator iter1 =d1.myList.begin();
    list<string> ::const_iterator iter2 =d2.myList.begin();	
	
	int found;
	
	while(iter1 != d1.myList.end()){
		 found = 0;
		 
		 while(iter2 != d2.myList.end()){
		 
		    /* if the words are not the same, move to the next word of the 
		       second Dictionary, loop and check again. Else if the words are the same,
		       then breake the interior loop with the found indicator showing that
			   there exists the same word in both Dictionaries. 
		    */
		  	 if(*iter1 != *iter2){
		 		iter2++;		
			 } 
			 else if( *iter1 == *iter2){
				found = 1;
				break;	
             }  	 	
		 }
	
	    /* If the word exists in both Dictionaries, move to the next
	       word of the exterior Dictionary and reset the iterator of the
	       second Dictionary so you can check all the words from the beginning.
	       If the word doesn't exist in both Dictionaries, there is no need for further
	       checking, so we return false.
	    */
		if(found == 1){
		   iter1++;
		   while(iter2 != d2.myList.begin()){
		   	 iter2--;
		   }
		}else {
		   return false; 
	   }
	}
	/* If the function reaches this point, then the Dictionaries
	   are equal, so we return true.
	*/
	  return true;
}
	

 ostream& operator <<(ostream& os, const Dictionary& d){
   list<string>:: const_iterator it = d.myList.begin();
 
   while( it != d.myList.end()){
 	 os<<*it<<"\n";
 	 it++;
    } 
  return os;	 
}

