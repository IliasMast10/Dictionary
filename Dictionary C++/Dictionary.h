#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include<list>
#include<string>

using namespace std;

class Dictionary{
	
 public:
    Dictionary();
    
	Dictionary(const string& fileName);
	
    bool containsWord(const string& word){
      resetIterator();
      
	    while(iter != myList.end() ) {
            
			if( *iter == word){
     		 return true;
		    }
		  iter++;
	    }
	 return false;    
   }
   
   
    list<string> startWith(char ch){
    	
    	list<string> newList;
    	string temp;
    	resetIterator();
      
	    while(iter != myList.end() ) {
         
		  temp = *iter;	
		
			if( temp.at(0)  == ch){
				newList.push_back(temp);
		    }
		  iter++;
	    }
	  return newList;     	
	}
	
	
    list<string> startWith( const string& prefix){
    	
		list<string> newList;
    	string temp;
    	resetIterator();
        
	   while(iter != myList.end() ) {
		  int i=0; 
		  bool flag;
		  temp = *iter;	
            
			// As long as the size of the temp word is bigger than the prefix size
			// then do the comparison. Otherwise move to the next word.		   
		   if(temp.size() >= prefix.size()) {
		     flag = true;
		     
		     // keep comparing letters until i exceeds the prefix size.
		     
			 while(i != prefix.size() ){
		        // The comparison of each letter starts.
		 	    if(temp.at(i) == prefix.at(i)){
			      i++;
		        } else {	
		          flag = false;
		          i = prefix.size();
		        } 
		     }
	       }
		 iter++; 
	     if (flag){
		    newList.push_back(temp);
	     }
        }
      return newList;
	}
	
   
    list<string> endWith(char ch){
    	
    	list<string> newList;
    	string temp;
    	resetIterator();
    
		while(iter != myList.end() ) {
		  temp = *iter;	
		     // check the last character of each word in the Dictionary.
			if( temp.at( temp.size()-1 ) == ch){
				newList.push_back(temp);
		    }
		  iter++;
	    }
	  return newList;  
	}


    list<string> endWith( const string& prefix){
    	
		list<string> newList;
    	string temp;
    	resetIterator();
        
       if( prefix == "")
          return newList;
          
	   while(iter != myList.end() ) {
		  int i=0; 
		  bool flag;
		  temp = *iter;	
		   
		   if(temp.size() >= prefix.size()) {
		     flag = true;
		     
			 while(i != prefix.size() ){
		   
		 	    if(temp.at( temp.size() -i -1 ) == prefix.at( prefix.size() -i -1)){
			      i++;
		        } else {
		          flag = false;
		          i = prefix.size();
		        } 
		     }
	       }
		 iter++; 
	     if (flag){
		    newList.push_back(temp);
	     }
        }
      return newList;
	}
	

    void addWord( const string& str){
    	resetIterator();
    	bool flag = false;
    	
    	while( iter != myList.end()){
    	
		   if(*iter == str){
		  	   flag = true;
		  	   cout<<"\nThe word "<<str<<" is already in the list.\n\n";
		 	   break;
		   } else {
		 	   iter++;	
		   }	
        }    
      if(!flag){
	     myList.push_back(str); 
      }
	}
	
	void updateWord( const string& target, const string& replacement){
	  resetIterator();
	
	  while(iter != myList.end()){
	  	
	  	if( *iter == target){
		  *iter = replacement;
		  cout<<"\nThe word "<<target<<" was updated with the word "<<replacement<<"\n\n";
		  break;	
	    }
	    iter++;
	  }	
		
	}
			 
	friend bool operator== (const Dictionary& d1, const Dictionary& d2);
	
	friend ostream& operator <<(ostream& os, const Dictionary& d);
	
  private:
	 list<string> myList;
	 list<string> :: iterator iter = myList.begin();	
	 
	 // I reset the iterator to make sure it points 
	 // at the beginning of the list.
	 void resetIterator(){
	 	while(iter != myList.begin()){
		    iter --;
	    }
	 } 
};
#endif




