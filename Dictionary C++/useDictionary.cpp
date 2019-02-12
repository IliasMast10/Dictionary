#include"Dictionary.h"
#include"Dictionary.cpp"
#include<iostream>


using namespace std;

int main(){

	Dictionary d1("wordsScrambled1.txt");
    Dictionary d2("wordsScrambled2.txt");
	
	if(d1==d2)
	 cout<<"The dictionaries are equal.\n\n";
		
	Dictionary d3;
	
	d3.addWord("basic");
	d3.addWord("volume");
    d3.addWord("engage");
	d3.addWord("ancient");    
	d3.addWord("language");
	d3.addWord("ancor");
	d3.addWord("land");

	cout<<"The Dictionary d3 contains the words\n"<<d3<<"\n\n";
	//-----------------------------------
	
	list<string> l1= d3.endWith("age");

	list<string>:: const_iterator it1 = l1.begin();	
	cout<<"The words that end with \"age\" in the Dictionary d3 are";
	while(it1 != l1.end()){
		cout<<"\n"<<*it1;
		it1++;
	}
    cout<<"\n\n";
  //-----------------------------------------------
	
	d3.addWord("basic");
	d3.updateWord("engage", "patient");
		cout<<"The Dictionary d3 contains the words\n"<<d3<<"\n\n";
 //--------------------------------------
	
	list<string> l2= d3.startWith("an");
	
	list<string>:: const_iterator it2 = l2.begin();	
	cout<<"\nThe words that start with \"an\" in the Dictionary d3 are";
	while(it2 != l2.end()){
		cout<<"\n"<<*it2;
		it2++;
	}
   cout<<"\n\n";

  //------------------------
  
  	list<string> l3= d3.startWith('l');
	
	list<string>:: const_iterator it3 = l3.begin();	
	cout<<"\nThe words that start with \'l\' in the Dictionary d3 are";
	while(it3 != l3.end()){
		cout<<"\n"<<*it3;
		it3++;
	}
	cout<<"\n\n";
	
	//-------------------------------
	list<string> l4 = d1.endWith('o');
	
	list<string>:: const_iterator it4 = l4.begin();	
	cout<<"\nThe words that end with \'o\' in the Dictionary d1 are";
	while(it4 != l4.end()){
		cout<<"\n"<<*it4;
		it4++;
	}
	cout<<"\n\n";
	
		
system("pause");	
return 0;	
}
