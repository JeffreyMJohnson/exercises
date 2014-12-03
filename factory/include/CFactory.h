#pragma once
#include "IObject.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Factory Class.
///				Used to create objects from a type name
/// </summary>
///
/// <remarks>	Caswal, 3/08/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class CFactory
{
public:
	static CFactory* GetInstance();
	static CFactory* instance;
	~CFactory(void);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Creates an object. </summary>
	///
	/// <remarks>	Caswal, 3/08/2010. </remarks>
	///
	/// <param name="name">	The type name of object to be made. </param>
	///
	/// <returns>	null if it fails, else returns a new object of correct type. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	IObject* CreateObject(const char* name);

	typedef IObject* (*TMakeFunction)();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a make function to 'func'. </summary>
	///
	/// <remarks>	Caswal, 3/08/2010. </remarks>
	///
	/// <param name="name">	The type name. </param>
	/// <param name="func">	The create function of the given type. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void AddMakeFunction(const char* name, TMakeFunction func);
private:
	CFactory(void);
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Structure to pair type names, and make functions.</summary>
	///
	/// <remarks>	Caswal, 3/08/2010. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	struct SPair
	{
		char name[256];
		TMakeFunction MakeFunction;
	};

	/// <summary> Array of Make Functions.  </summary>

	SPair makeFunctions[256];
};


/// <summary> Global factory variable, could use a singleton instead.  </summary>

//extern CFactory g_Factory;