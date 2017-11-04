#include <iostream>
#include <assert.h>
#include "Vector.h"
#include "Math.h"

Vector3::Vector3() { }

Vector3::Vector3(float Value) : X(Value), Y(Value), Z(Value) { }

Vector3::Vector3(float nX, float nY, float nZ) : X(nX), Y(nY), Z(nZ) { }

Vector3::Vector3(const Vector3& Vector) : X(Vector.X), Y(Vector.Y), Z(Vector.Z) { }

Vector3 
Vector3::operator+(const Vector3& VectorB)
{
	return Vector3(
		X + VectorB.X,
		Y + VectorB.Y,
		Z + VectorB.Z
	);
}

Vector3 
Vector3::operator-(const Vector3& VectorB)
{
	return Vector3(
		X - VectorB.X,
		Y - VectorB.Y,
		Z - VectorB.Z
	);
}

const Vector3 Vector3::operator-(const Vector3& VectorB) const
{
	return Vector3(
		X - VectorB.X,
		Y - VectorB.Y,
		Z - VectorB.Z
	);
}

Vector3 
Vector3::operator*(float Scalar)
{
	return Vector3(
		X * Scalar,
		Y * Scalar,
		Z * Scalar
	);
}

float 
Vector3::Magnitude() const
{
	return sqrt(
		pow(X, 2) + 
		pow(Y, 2) + 
		pow(Z, 2)
	);
}

Vector3 
Vector3::Normalization() const
{
	//Zero vectors cannot be normalized
	assert(!IsZero());

	float Magnitude = this->Magnitude();
	
	return Vector3(
		X / Magnitude,
		Y / Magnitude,
		Z / Magnitude
	);
}

float
Vector3::DotProduct(const Vector3& VectorA, const Vector3& VectorB)
{
	return (
		VectorA.X * VectorB.X +
		VectorA.Y * VectorB.Y +
		VectorA.Z * VectorB.Z
	);
}

float 
Vector3::ValueOfTheta(const Vector3& VectorA, const Vector3& VectorB)
{
	return acos(
		DotProduct(
			VectorA.Normalization(), 
			VectorB.Normalization()
		)
	);
}

bool 
Vector3::IsOrthogonalTo(const Vector3& VectorB) const
{
	return Math::IsNearlyZero(
		abs(
			DotProduct(*this, VectorB)
		)
	);
}

bool 
Vector3::IsParallelTo(const Vector3& VectorB) const
{
			//This is the zero vector
	return  this->IsZero()											||
			//Or the other vector is the zero vector
			VectorB.IsZero()										||
			//Or the angle has a value of zero in radians
			Math::IsNearlyZero(ValueOfTheta(*this, VectorB))		||
			//Or the angle has a value of PI (180º) in radians
			ValueOfTheta(*this, VectorB) == Math::PI;
}

bool 
Vector3::IsZero() const
{
	//Only the zero vector has a magnitude of zero
	return  Math::IsNearlyZero(Magnitude());
}

Vector3
Vector3::ComponentParallelTo(Vector3 VectorB) const
{
	// The projection of self onto a vector B
	// equals the normal of B times 
	// the dot product of the normal of B and self
	float Weight = Vector3::DotProduct(*this, VectorB.Normalization());
	return VectorB.Normalization() * Weight;
}

Vector3
Vector3::ComponentOrthogonalTo(Vector3 VectorB) const
{
	return *this - this->ComponentParallelTo(VectorB);
}

Vector3
Vector3::CrossProduct(const Vector3& VectorA, const Vector3& VectorB)
{
	return Vector3(
		VectorA.Y * VectorB.Z - VectorB.Y * VectorA.Z,
		-(VectorA.X * VectorB.Z - VectorB.X * VectorA.Z),
		VectorA.X * VectorB.Y - VectorB.X * VectorA.Y
	);
}

float 
Vector3::AreaOfParallelogram(const Vector3& VectorA, const Vector3& VectorB)
{
	return Vector3::CrossProduct(VectorA, VectorB).Magnitude();
}

float 
Vector3::AreaOfTriangle(const Vector3& VectorA, const Vector3& VectorB)
{
	return Vector3::AreaOfParallelogram(VectorA, VectorB) / 2.f;
}

std::ostream 
&operator<<(std::ostream &Stream, const Vector3& Vector)
{
	Stream  << "X: "
			<< Vector.X
			<< " Y: "
			<< Vector.Y
			<< " Z: "
			<< Vector.Z
			<< std::endl;
	return Stream;
}