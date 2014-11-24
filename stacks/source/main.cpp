/*
Create your own stack class using the layout given in the lecture slides. Make it templated so it can hold any type. You can use a vector or
linked list as your internal data structure. It must contain the following functions:
Empty - returns true if the stack is empty
Size - returns the number of elements
Push - adds an element to the end of the stack
Pop - removes an element at the end of the stack and returns it
Top - returns the element at the end of the stack


Using this stack class, create a state manager for a game. The idea is that you start off at a base state, you can then push states onto the stack, 
and once you pop them off the stack, the state reverts to its previous. i.e. Main Menu > Push Options Menu on to the stack; once user finishes in 
the options menu, pop options off the stack and you will go back to the main menu.
*/

#include <stack>
#include <iostream>

namespace j
{
	template <class T>
	class Stack
	{
	public:
		Stack(){};
		~Stack(){};
		std::stack<T> mData;
	};

	class BaseState
	{
	public:
		BaseState(){}
		~BaseState(){}

		virtual void Update() = 0;
	};

	class MenuState
		: public BaseState
	{
	public:
		MenuState(){}
		~MenuState(){}
		
		void Update()
		{
			std::cout << "menu state update firing\n";
		}
	};

	class GameState
		: public BaseState
	{
	public:
		GameState(){}
		~GameState(){}

		void Update()
		{
			std::cout << "game state update firing.\n";
		}
	};

	class StateManager
	{
	public:
		StateManager(){}
		~StateManager()
		{
			while (!mStateList.mData.empty())
			{
				BaseState* state = mStateList.mData.top();
				mStateList.mData.pop();
				std::cout << "deleting state:" << state << std::endl;
				delete state;
			}
		}

		void PushState(BaseState* a_state)
		{
			mStateList.mData.push(a_state);
		}

		void PopState()
		{
			BaseState* state = mStateList.mData.top();
			mStateList.mData.pop();
			std::cout << "deleting state: " << state << std::endl;
			delete state;
		}

		void Update()
		{
			mStateList.mData.top()->Update();
		}

	private:
		Stack<BaseState*> mStateList;
	};
}

void main()
{
	j::StateManager sManager;
	std::cout << "push new menu state to stack\n";
	system("pause");
	sManager.PushState(new j::MenuState());

	std::cout << "update the top state\n";
	system("pause");
	sManager.Update();

	std::cout << "push new state on stack\n";
	system("pause");
	sManager.PushState(new j::GameState());

	std::cout << "update the top state\n";
	system("pause");
	sManager.Update();

	std::cout << "push new menu state to stack\n";
	system("pause");
	sManager.PushState(new j::MenuState());

	std::cout << "update the top state\n";
	system("pause");
	sManager.Update();

	std::cout << "pop current state\n";
	system("pause");
	sManager.PopState();

	std::cout << "update the top state\n";
	system("pause");
	sManager.Update();

	std::cout << "end of main, destructors called\n";
	system("pause");
}