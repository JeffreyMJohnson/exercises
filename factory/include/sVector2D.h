#pragma once

class sVector2D
{
public:
	sVector2D() { x = 0; y = 0; }
	sVector2D(float _x, float _y ) { x = _x; y = _y; }

	float x;
	float y;
};