#pragma once
#include <iostream>
using namespace std;


//repetitions are not allowed
class SearchTree{
	struct Node{
		int 	key_;
		Node* 	llink_;
		Node* 	rlink_;
		Node* 	parent_;
		Node	(int key=0, Node* llink=0, Node* rlink=0, Node* parent=0):
				key_(key), llink_(llink), rlink_(rlink), parent_(parent){}
	};
	
	//AUXILIARY FUNCTIONS
	static  void	clear(const Node* tree);
	static	void	print(const Node* tree, int indent=0);
			Node*	search(int key) const; 
			static	void   do_insert(Node* current, int key);

public:
					SearchTree():tree_(0)	{}							//constructor
					~SearchTree()			{clear(tree_);}				//destructor
	
	/*1*/	bool	find(int key) const		{ return	search(key)!=0;} 
	/*2*/	void	insert(int key);		//insertion is not done, if key occurs in the tree	
	/*3*/	void	remove(int key);		
			
	/*4*/	void	print()const		{	cout<<"- - - - - - - - - -"<<endl; 
											print(tree_);
											cout<<"- - - - - - - - - -"<<endl;}
	

private:
	Node*	tree_;
};

