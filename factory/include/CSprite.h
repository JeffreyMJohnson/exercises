#pragma once
#include "iobject.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sprite Example. </summary>
///
/// <remarks>	Caswal, 3/08/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class CSprite :
	public IObject
{
public:
	CSprite(void);
	virtual ~CSprite(void);

	virtual void Load(FILE* file);
	virtual void Save(FILE* file);

	virtual void Update(float dt) { printf("Sprite update!\n"); }
	virtual void Draw() { printf("Drawing a Sprite: %i\n", Texture); }

	int GetTexture() const { return Texture; }
	void SetTexture(int texture) { Texture = texture; }
protected:
	int Texture;
};

MAKEFUNCTION(CSprite)