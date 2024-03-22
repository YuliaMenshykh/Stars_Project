#pragma once
#include "MathLib/HeaderMath.h"


struct  ParticleProps
{
	Vector2 Position;
	Vector2 Velocity, VelocityVariation;
	Vector4 ColorBegin, ColorEnd;
	float SizeBegin, SizeEnd, SizeVariation;
	float LifeTime = 1.0f;
};

class ParticleSystem
{
	ParticleSystem() {};
	~ParticleSystem() {};

};