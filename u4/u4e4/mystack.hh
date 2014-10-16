/** @file mystack.h
 */
#ifndef MYSTACK_HH
#define MYSTACK_HH

#include <iostream>
#include <stdexcept>


/** my stack class. Stack is a container that can contain
 *  any assignable data type. Data type that is assignable is an element
 *  that can be copied to an other one with a mere assignment operator (=)
 *  i.e. a primitive data type or a struct/class with no pointer
 *  variables or a class with overloaded assignment operator
 */
template<class T> class MyStack
{
  static const int DEFAULT_BLOCKSIZE = 5;
public:
  
  /** A constructor.
   *  @param blockSize number of elements in a one block
   */
  MyStack(int blockSize=DEFAULT_BLOCKSIZE);

  /** A destructor. frees memory allocated by the stack
   */
  virtual ~MyStack();

  /** Pushes an element to the stack. element is assigned to the stack array.
   *  @param element element to push
   *  @return 0 success, -1 failure (if possible)
   */
  int push(const T *element);

  /** Pops an element from the stack (to one last set to the stack). 
   *  @param element pointer to memory where to popped element is copied (using
   *                 assignment
   *  @return 0 success, -1 nothing to pop
   */
  int pop(T *element);

  /** Number of elements in the stack
   *  @return number of element in the stack
   */
  int size() const;

  /** Assignment operator overloading function for the stack. With this, stacks
   *  can be copied by simple assigning a stack variable to an other one.
   *  @param stack stack to copy
   */
  MyStack<T>& operator=(const MyStack& stack);

protected:

  T *array;                   /**<-- the stack array */
  int elementCount;           /**<-- number of elements in the stack */
  int elementMemoryAllocated; /**<-- number of elements allocated */
  int blockSize;              /**<-- number of elements to allocate at a time */
};


/* ----- MyStack class template member function implementations ---- */


/* Add the implementation of MyStack funktions below this line */
template <class T>
MyStack<T>::MyStack(int blockSize) : elementCount(0), blockSize(blockSize)
{
	this->array = new T[blockSize];
	if (this->array == NULL)
		throw std::runtime_error("Muisti loppu?");
	
	this->elementMemoryAllocated = blockSize;
}

/** A destructor. frees memory allocated by the stack
*/
template <class T>
MyStack<T>::~MyStack()
{
	delete[] array;
}

/** Pushes an element to the stack. element is assigned to the stack array.
*  @param element element to push
*  @return 0 success, -1 failure (if possible)
*/
template <class T>
int MyStack<T>::push(const T *element)
{
	// Muistinhallintaa
	if (elementCount >= elementMemoryAllocated) {
		// Allokointi
		T *temp = new T[elementCount + blockSize];
		
		if(temp == NULL)
			return -1;
		// Kopiointi
		for (int i=0; i<elementCount; i++) {
			temp[i] = this->array[i];
		}
		
		delete[] this->array;
		this->array = temp;
		
		elementMemoryAllocated += blockSize;
		
		
	}
	// Sijoitus
	array[elementCount] = *element;
	elementCount++;
	return 0;
}

/** Pops an element from the stack (to one last set to the stack). 
*  @param element pointer to memory where to popped element is copied (using
*                 assignment
*  @return 0 success, -1 nothing to pop
*/
template <class T>
int MyStack<T>::pop(T *element)
{
	if (elementCount < 1)
		return -1;
	
	*element = array[elementCount-1];
	elementCount--;
	
	// Muistinhallintaa
	if (elementMemoryAllocated - elementCount >= 2*blockSize) {
		elementMemoryAllocated -= blockSize;
		// Allokointi
		T *temp = new T[elementMemoryAllocated];
		// Kopiointi
		for (int i=0; i<elementCount; i++) {
			temp[i] = this->array[i];
		}
		// Sijoitus
		delete[] this->array;
		this->array = temp;
		
	}
	
	return 0;
}

/** Number of elements in the stack
*  @return number of element in the stack
*/

template <class T>
int MyStack<T>::size() const
{
	return elementCount;
}

/** Assignment operator overloading function for the stack. With this, stacks
*  can be copied by simple assigning a stack variable to an other one.
*  @param stack stack to copy
*/
template <class T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T>& stack)
{
	delete[] this->array;
	this->array = new T[stack.size()+blockSize];
	for (int i=0; i < stack.size(); i++) {
		this->array[i] = stack.array[i];
	}
	
	this->elementCount = stack.size();
	this->elementMemoryAllocated = this->elementCount + blockSize;
	
	return *this;
}




#endif /* MYSTACK_HH */
