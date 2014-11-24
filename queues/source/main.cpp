/*
Create your own queue class using the layout given in the lecture slides. Make it templated so it can hold any type. You can use a vector or linked list as your internal data structure.
It must contain the following functions:
Push/Enqueue - pushes an element onto the end of the queue
Pop/Dequeue - removes and returns the element at the front of the queue
Top - gets the element at the front of the queue
Empty - returns true if the queue is empty
GetSize - returns the number of elements in the queue
*/

#include <iostream>
#include <algorithm>
#include <list>

namespace j
{
	template <class T>
	class Queue
	{
	public:
		Queue(){}
		Queue(Queue& rhs)
		{
			for (std::list<T>::iterator it = mData.begin(); it != mData.end(); it++)
			{
				rhs.Push(*it);
			}
		}
		~Queue(){}

		/*
		Adds given element to end of queue
		*/
		void Push(T& data)
		{
			mData.push_back(data);
			mSize++;
		}

		/*
		removes and returns the first element of the queue
		calling this function on an empty Queue  causes undefined behavior
		*/
		T& Pop()
		{
			T r = mData.front();
			mData.pop_front();
			mSize--;
			return r;
		}

		/*
		Returns a reference to the first element in queue
		Calling this function on empty queue causes undefined behavior
		*/
		T& Top()
		{
			return mData.front();
		}

		/*
		Returns true if queue has no elements otherwise returns false.
		*/
		bool Empty()
		{
			return (mSize == 0);
		}

		/*
		Returns number of elements in queue
		*/
		int GetSize()
		{
			return mSize;
		}

	private:
		std::list<T> mData;
		unsigned int mSize;
	};
}

void main()
{
	j::Queue<int> myQ;
	int x = 10;
	int y = 5;
	myQ.Push(x);
	myQ.Push(x);

	y = myQ.Pop();

	system("pause");


}