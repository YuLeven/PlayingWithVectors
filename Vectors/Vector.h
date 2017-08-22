#include <iostream>

class Vector3
{
public:
	float X;
	float Y;
	float Z;

	Vector3();
	//Useful for instantiating the zero vector
	Vector3(float Value);
	Vector3(float X, float Y, float Z);
	//Copy constructor
	Vector3(const Vector3& Vector);

	//Common vector operations using operator overload
	Vector3 operator+(const Vector3& Vector);
	Vector3 operator-(const Vector3& Vector);
	//Times scalar
	Vector3 operator*(float Scalar);
	//Cout printing
	friend std::ostream& operator<<(std::ostream& Stream, const Vector3& Vector);
	
	//Method based operations
	Vector3 Normalization() const;
	float Magnitude() const;
	static float DotProduct(const Vector3& VectorA, const Vector3& VectorB);
	static float ValueOfTheta(const Vector3& VectorA, const Vector3& VectorB);
	bool IsOrthogonalTo(const Vector3& Vector) const;
	bool IsParallelTo(const Vector3& Vector) const;
	bool IsZero() const;
};