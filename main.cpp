// SearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SearchTree.h"
#include <iostream>
using namespace std;



int main()
{
	SearchTree s;
		
	cout<<endl<<"*****   THE 4, 2, 3, 7, 6, 1, 5, 8 KEYS ARE INSERTED:  *****"<<endl<<endl;
	s.insert(4); s.insert(2); s.insert(3); s.insert(7);	
	s.insert(6); s.insert(1); s.insert(5); s.insert(8);
	s.print();
	cout<<endl<<"***** 7 IS DELETED: *****"<<endl<<endl;
	s.remove(7);
	s.print();		
	
	cout<<endl<<"***** 4 IS DELETED: *****" <<endl<<endl;
	s.remove(4);
	s.print();
	
	cout<<endl<<"***** 2 IS DELETED: *****" <<endl<<endl;
	s.remove(2);
	s.print();

	return 0;
}
