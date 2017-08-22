#include "Math.h"

//Runtime computed constants
const float Math::PI = 3.14159265f;
const float Math::TOLERANCE = 1e-6f;

float 
Math::RadiansToDegrees(float radians)
{
	return radians * (180.f / PI);
}

bool 
Math::IsNearlyZero(float value)
{
	return value < TOLERANCE;
}

bool 
Math::IsNearlyZero(float value, float tolerance = TOLERANCE)
{
	return value < tolerance;
}