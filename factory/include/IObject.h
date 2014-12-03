#pragma once
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "sVector2D.h"


//Macro for the make function for object types
//Usage: 
//MAKEFUNCTION(Player)

//Where Player is a derived class from IObject
//Produces the function:
//IObject* MakePlayer() { return new Player() }
#define MAKEFUNCTION(Type) inline IObject* Make##Type() { return new Type(); }

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Base Object Class. Is Abstract </summary>
///
/// <remarks>	Caswal, 3/08/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class IObject
{
public:
	IObject(void);
	virtual ~IObject(void);


	//Load save functions for this type
	virtual void Load(FILE* file);
	virtual void Save(FILE* file);

	//Pure Virtual functions for derived
	//Classes to implement
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;

	//The trusty getters and setters
	void SetSize(const sVector2D& size) { Size = size; }
	void SetPosition(const sVector2D& position) { Position = position; }
	void SetRotation(float rotation) { Rotation = rotation; }

	void SetID(int id) { ID = id; }

	sVector2D GetSize() const { return Size; }
	sVector2D GetPosition() const { return Position; }
	float GetRotation() const { return Rotation; }

	int GetID() const { return ID; }

	const char* GetTypeName() const { return TypeName; }
	void SetTypeName(const char* typeName) { strcpy(TypeName, typeName); }

protected:
	sVector2D Size;
	sVector2D Position;
	float Rotation;

private:
	char TypeName[256];
	int ID;
};
