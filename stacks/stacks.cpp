/*
Create your own stack class using the layout given in the lecture slides. Make it templated so it can hold any type. You can use a vector or
linked list as your internal data structure. It must contain the following functions:
Empty - returns true if the stack is empty
Size - returns the number of elements
Push - adds an element to the end of the stack
Pop - removes an element at the end of the stack and returns it
Top - returns the element at the end of the stack
*/

#include "stdafx.h"
#include <stack>
#include <iostream>

template <class T>
class Stack
{
public:
	Stack();
	~Stack();
	bool Empty()
	{
		return mData.empty();
	}

	int Size()
	{
		return mData.size();
	}

	void Push(T& rValue)
	{
		mData.push(rValue);
	}

	void Pop()
	{
		mData.pop();
	}

	const T& Top()
	{
		return mData.top();
	}

private:
	std::stack<T> mData;

};


/*
Using this stack class, create a state manager for a game. The idea is that you start off at a base state,
you can then push states onto the stack, and once you pop them off the stack, the state reverts to its previous.
i.e. Main Menu > Push Options Menu on to the stack; once user finishes in the options menu, pop options off the
stack and you will go back to the main menu.
*/

class StateMachine;
class BaseState;
class Menu;
class Game;

bool quit = false;
void main_old()
{
	StateMachine sMachine{};
	sMachine.PushState(new Menu());

	while (!quit)
	{
		/*sMachine.Update(.016);
		sMachine.Draw();*/
		system("pause");
		quit = true;
	}
	sMachine.PopState();

}

class StateMachine
{
public:
	StateMachine(){}
	~StateMachine(){}
	void PushState(BaseState* a_state)
	{
		mData.Push(a_state);
		a_state->Init();
	}
	void PopState()
	{
		BaseState* state = mData.Top();
		mData.Pop();
		//state->Destroy();
		delete state;
	}

	void Switch(BaseState* a_state)
	{
		BaseState* oldState = mData.Top();
		mData.Pop();
		mData.Push(a_state);
		//oldState->Destroy();
		delete oldState;
		a_state->Init();
	}

	BaseState* Top()
	{
		return mData.Top();
	}

	//void Update(float a_delta)
	//{
	//	mData.Top()->Update(a_delta, *this);
	//}

	//void Draw()
	//{
	//	mData.Top()->Draw();
	//}

private:
	Stack<BaseState*> mData;
};

class BaseState
{
public:
	BaseState();
	~BaseState();
	virtual void Init() = 0;
	//virtual void Destroy() = 0;
	//virtual void Update(float a_delta, StateMachine& a_sMachine) = 0;
	//virtual void Draw() = 0;
};

class Menu
	: public BaseState
{
public:
	Menu()
	{
	}
	~Menu()
	{

	}
	void Init()
	{
		std::cout << "menu state initializing\n";
	}

	/*void Destroy()
	{
		std::cout << "menu state destroying now." << std::endl;
	}

	void Update(float a_delta, StateMachine& a_sMachine)
	{
		std::cout << "I am Updating\nHit 'q' to quit." << std::endl;
		std::cout << "hit 'g' to go to game state\n";
		std::cin.ignore();
		char c;
		std::cin >> c;
		if (c == 'q')
			quit = true;
		if (c == 'g')
			a_sMachine.PushState(new Game());
	}

	void Draw()
	{
		std::cout << "menu drawing\n";
	}*/

private:
};

class Game
	: public BaseState
{
public:
	Game(){}
	~Game(){}
	void Init()
	{
		std::cout << "game state init\n";
	}

	/*void Destroy()
	{
		std::cout << "game state destroy called\n";
	}

	void Update(float a_delta, StateMachine& a_sMachine)
	{
		std::cout << "hit 'm' to go back to menu\n";
		char c;
		std::cin >> c;
		if (c == 'm')
			a_sMachine.PopState();
	}
	void Draw()
	{
		std::cout << "game state drawing\n";
	}*/

private:
};