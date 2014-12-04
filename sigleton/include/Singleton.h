#ifndef _SINGLETON_H_
#define _SINGLETON_H_

class Singleton
{
public:
	static Singleton* GetInstance();
	int screenWidth = 1024;
	int screenHeight = 768;

	~Singleton();
protected:
	Singleton();

	static Singleton* instance;
};

#endif