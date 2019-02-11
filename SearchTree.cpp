#include "StdAfx.h"
#include "SearchTree.h"
#include <string>


void	
SearchTree::clear(const Node* tree)
{
	if(tree)
	{
		clear(tree->llink_);
		clear(tree->rlink_);
		delete tree;
	}
}

void  
SearchTree::print(const Node* tree, int indent)
{
	if(tree==0) return;
	
		print(tree->rlink_, indent+5);
	cout<<string(indent, ' ')<<tree->key_<<endl;	
		print(tree->llink_, indent+5);
}


SearchTree::Node*	
SearchTree::search(int key) const
{
	Node* current=tree_;
	while(current)
	{
		if(current->key_==key)
			return current;
		if(key<current->key_)
			current=current->llink_;
		else
			current=current->rlink_;
	}
	return 0;
}

void SearchTree::do_insert(SearchTree::Node* current, int key){
	if (key == current->key_) {
		return;
	}

	if (key > current->key_) {
		if (current->rlink_ == nullptr) {
			current->rlink_ = new SearchTree::Node(key, nullptr, nullptr, current);
		}
		else {
			do_insert(current->rlink_, key);
		}
	}
	else {
		if (current->llink_ == nullptr) {
			current->llink_ = new SearchTree::Node(key, nullptr, nullptr, current);
		}
		else {
			do_insert(current->llink_, key);
		}
	}
}

void	
SearchTree::insert(int key)
{
	if (tree_ == nullptr) {
		tree_ = new SearchTree::Node(key);
	}
	do_insert(tree_, key);
}

void	
SearchTree::remove(int key)
{
	SearchTree::Node* m = search(key);
	if (m == nullptr) {
		return;
	}
	SearchTree::Node* pos = m;
	SearchTree::Node* par = pos->parent_;
	if (m->llink_ != nullptr) {
		m = m->llink_;
		while (m->rlink_ != nullptr) {
			m = m->rlink_;
		}
		SearchTree::Node* ml = m->llink_;
		SearchTree::Node* mPar = m->parent_;
		if (par != nullptr) {
			if (par->llink_ == pos) {
				par->llink_ = m;

			}
			else {
				pos->parent_->rlink_ = m;

			}
		}
		m->parent_ = par;
		if (pos->llink_ != m) {
			pos->llink_->parent_ = m;
			m->llink_ = pos->llink_;
		}
		if (pos->rlink_ != nullptr) {
			pos->rlink_->parent_ = m;
			m->rlink_ = pos->rlink_;
		}
		if (m != pos->llink_) {
			mPar->rlink_ = ml;
			if (ml != nullptr) {
				ml->parent_ = mPar;
			}
		}
		if (tree_ == pos) {
			tree_ = m;
		}
		delete pos;
	}
	else {
		if (m->rlink_ != nullptr) {
			if (m->parent_->llink_ == m) {
				m->parent_->llink_ = m->rlink_;
			}
			else {
				m->parent_->rlink_ = m->rlink_;

			}
			m->rlink_->parent_ = m->parent_;
			if (m == tree_) {
				tree_ = m;
			}
			delete m;
		}
		else {
			if (m->parent_->llink_ == m)
				m->parent_->llink_ = nullptr;
			else
				m->parent_->rlink_ = nullptr;
			if (m == tree_) {
				tree_ = m;
			}
			delete m;
		}
	}
} 

