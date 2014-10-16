#ifndef TREE_HH
#define TREE_HH

#include <iterator>
#include <iostream>


namespace tree
{
  template <typename T>
  class Tree;
	  
  template <typename T>
  class TreeIterator;
  
  	template <class T>
	bool operator==(TreeIterator<T> const &iter1, TreeIterator<T> const &iter2)
	{
		if (iter1.position == iter2.position)
			return true;
		else
			return false;
	}
	
	template <class T>
	std::ostream &operator<<(std::ostream &os, Tree<T> const &tree)
	{
		os << tree.value;
		return os;
	}


	
  template <typename T>
  class TreeIterator : public std::iterator<std::forward_iterator_tag, T, std::ptrdiff_t, T*, T&>
  {
	public:
	
	TreeIterator();
	TreeIterator(Tree<T> *position, Tree<T> *next);
	
	void setDel();
	Tree<T> *getPosition();
	
	TreeIterator &operator++();
	TreeIterator &operator++(int i);
	T &operator*();
	
	bool operator!=(TreeIterator<T> const &iter);
	
	
	friend bool operator==<T>(TreeIterator const &iter1, TreeIterator const &iter2);
	// friend bool operator!=<T>(TreeIterator &iter1, TreeIterator &iter2);
	friend class Tree<T>;
	
	private:
	
	Tree<T> *position;
	Tree<T> *next;
	bool del;
  };
  // This template class is a tree container capable of holding
  // values of template type T.

  // You can iterate the elements of this tree in in-order using
  // iterators.
  template <typename T>
  class Tree
  {
    
  public:

	friend class TreeIterator<T>;
    // This function creates a new tree. The tree holds
    // a certain value. You can access it with iterators.
    Tree(T const &val);
	~Tree();

    // The functions which add members to the tree do NOT
    // invalidate any iterators.

    // This function adds a new subtree as the left child.
    // The new subtree has initially no children, and it holds the value
    // given to it as the parameter of this function.
    void addLeft(T const &val);
    

    // This function adds a new subtree as the right child.
    // The new subtree has initially no children, and it holds the value
    // given to it as the parameter of this function.
    void addRight(T const &val);
    

    // This function returns the left subtree.
    Tree &getLeft();

    // This function returns the right subtree.
    Tree &getRight();
	
	// Asettaa vanhemmuussuhteen
	void setSuper(Tree *supertree);
	Tree *getSuper();


    // Create one new type alias, iterator.
    // The iterators must fulfill the requirements for
    // forward iterator (ISO/IEC 14882:2003 24.1.3)
	typedef tree::TreeIterator<T> iterator;
    // You don't need to implement const_iterators in this exercise.

    // This function returns the iterator pointing to the first
    // element of this tree. The traversal order is in-order.
    iterator begin(); 
    

    // This function returns past-the-end iterator of this tree.
    // The traversal order is in-order.
    iterator end();
	
	friend std::ostream &operator<< <T>(std::ostream &os, Tree<T> const &tree);
    
  protected:
	Tree *left;
	Tree *right;
  	Tree *super;
  	T value;

  };

	
  
template <class T>  
Tree<T>::Tree(T const &val) : left(NULL), right(NULL), super(NULL), value(val) {}
	
template <class T>
Tree<T>::~Tree()
{
	/*if (left != NULL) {
		left->~Tree();
		if (left->left == NULL && left->right == NULL) {
			delete left;
		}
		left = NULL;
	}
	
	if (right != NULL) {
		right->~Tree();
		if (right->left == NULL && right->right == NULL) {
			delete right;
		}
		right = NULL;
	}*/
	
	if (left == NULL && right == NULL)
		return;
	
	
	typename Tree<T>::iterator iter = this->begin();
	iter.setDel();
	typename Tree<T>::iterator loppu(this->super, NULL);
	
	for (; iter != loppu; iter++) {
		if (iter.position->left != NULL 
			&& iter.position->left->left == NULL 
			&& iter.position->left->right == NULL) {
			delete iter.position->left;
			iter.position->left = NULL;
		}
		if (iter.position->right != NULL
			&& iter.position->right->left == NULL 
			&& iter.position->right->right == NULL) {
			delete iter.position->right;
			iter.position->right = NULL;
		}
		
	}
	
}
	
	

template <class T>
void Tree<T>::addLeft(T const &val)
{
	if (left == NULL)
		left = new Tree<T>(val);
		left->setSuper(this);
	
}

template <class T>
void Tree<T>::addRight(T const &val)
{
	if (right == NULL)
		right = new Tree<T>(val);
		right->setSuper(this);
	
}

template <class T>
Tree<T> &Tree<T>::getLeft()
{
	if (left == NULL)
		return *this;
	else 
		return *(this->left);
}

template <class T>
Tree<T> &Tree<T>::getRight()
{
	if (right == NULL)
		return *this;
	else 
		return *(this->right);
}

/* iteraattorifunktiot */

template <class T>
typename Tree<T>::iterator Tree<T>::begin()
{
	if (left != NULL)
		return (*left).begin();
	else if (right != NULL)
		return (*right).begin();
	else {
		typename Tree<T>::iterator it(this, super);
		return it;
	}
}

template <class T>
typename Tree<T>::iterator Tree<T>::end()
{
	typename Tree<T>::iterator end(NULL, NULL);
	return end;
}

template <class T>
void Tree<T>::setSuper(Tree<T> *supertree) 
{
	this->super = supertree;
}

template <class T>
Tree<T> *Tree<T>::getSuper()
{
	return this->super;
}


/* TreeIterator-classmetodit */
template <class T>
TreeIterator<T>::TreeIterator(Tree<T> *position, Tree<T> *next) : 
			position(position), next(next), del(false) {}

template <class T>
TreeIterator<T>::TreeIterator() : position(NULL), next(NULL), del(false) {}

template <class T>
void TreeIterator<T>::setDel()
{
	this->del = true;
}

template <class T>
Tree<T> *TreeIterator<T>::getPosition()
{
	return this->position;
}

template <class T>
TreeIterator<T> &TreeIterator<T>::operator++()
{
	Tree<T> *temppos = position;
	Tree<T> *tempnext = next;
	
	if (del == false) {
		
		if (next != NULL) {
			if (tempnext->left == NULL && tempnext->right != NULL && tempnext->right == temppos) {
				temppos = tempnext;
				tempnext = tempnext->super;
			}
			
			else if (next->right != NULL)
				tempnext = next->right->begin().position;
			
			else {
				if (tempnext != NULL && (tempnext->right == NULL || tempnext->right == temppos)) {
				temppos = tempnext;
				tempnext = tempnext->super;
				}
				
				while (tempnext != NULL && temppos != tempnext->left
						&& (tempnext->right == NULL || tempnext->right == temppos) ) {
					
					temppos = tempnext;
					tempnext = tempnext->super;
				}
				
			}
			position = next;
			next = tempnext;
		}
		else
			position = NULL;
	}
	
	// Jos ei ole ihan tavallinen keissi, vaan destruktoriin liittyvä korotus, niin tehdään eri tavalla
	else {
		
		if (next != NULL) {
			
			tempnext = next->super;
			while (tempnext != NULL) {
				/*if (tempnext->left != NULL && next != tempnext->left)
					tempnext = tempnext->left;
				else*/
				if (tempnext->right != NULL && next != tempnext->right)
					tempnext = tempnext->right;
				else
					break;
			}
			
			position = next;
			next = tempnext;
			
		}
		else
			position = NULL;
			
		
	}
	
	return *this;
}

template <class T>
TreeIterator<T> &TreeIterator<T>::operator++(int i)
{
	++(*this);
	
	return *this;
}

template <class T>
T &TreeIterator<T>::operator*()
{
	return position->value;
}

template <class T>
bool TreeIterator<T>::operator!=(TreeIterator<T> const &iter)
{
	return !(*this == iter);
}


}




#endif
