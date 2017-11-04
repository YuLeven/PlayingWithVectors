// Vectors.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include "Vector.h"
#include "Math.h"

using namespace std;

void PrintLine()
{
	cout << "----------------------------" << endl;
}

void PrintSectionName(string SecionName)
{
	cout << "=========" << SecionName.c_str() << "=========" << endl;
}

void FreeCalculations()
{
	PrintSectionName("FreeCalculations");

	auto FirstVector = Vector3(1.6f, 1.8f, 36.f);
	auto SecondVector = Vector3(1.4f, 1.2f, 2.f);
	auto ThirdVector = FirstVector + SecondVector;
	auto FourthVector = ThirdVector - FirstVector;
	auto FifthVector = FourthVector * 2.58f;

	cout << FirstVector << endl;
	cout << SecondVector << endl;
	cout << ThirdVector << endl;
	cout << FourthVector << endl;
	cout << FifthVector << endl;
	cout << FifthVector.Magnitude() << endl;
	cout << FifthVector.Normalization() << endl;
	cout << Vector3::DotProduct(FifthVector, SecondVector) << endl;
	cout << FifthVector.Normalization().Magnitude() << endl;
	cout << endl;
}

void LessonTwo() 
{
	PrintSectionName("LessonTwo");

	//Plus
	auto FirstPlusVector = Vector3(8.218f, -9.341f, 0.f);
	auto SecondPlusVector = Vector3(-1.129f, 2.111f, 0.f);
	cout << "Sum:" << endl;
	cout << FirstPlusVector + SecondPlusVector << endl;

	//Minus
	auto FirstMinusVector = Vector3(7.119f, 8.215f, 0.f);
	auto SecondMinusVector = Vector3(-8.223f, 0.878f, 0.f);
	cout << "Subtraction:" << endl;
	cout << FirstMinusVector - SecondMinusVector << endl;

	//Scalar
	auto FirstScalarVector = Vector3(1.671f, -1.012f, -0.318f);
	cout << "Scalar:" << endl;
	cout << FirstScalarVector * 7.41f << endl;
	cout << endl;
}

void LessonThree()
{
	PrintSectionName("LessonThree");

	//Manitude
	auto FirstMagnitudeVector = Vector3(-0.221f, 7.437f, 0.f);
	auto SecondMagnitudeVector = Vector3(-8.813f, 1.331f, -6.247f);
	cout << "Magnitudes:" << endl;
	cout << FirstMagnitudeVector.Magnitude() << endl;
	cout << SecondMagnitudeVector.Magnitude() << endl;
	cout << endl;

	//Normalization
	auto FirstNormalizedVector = Vector3(5.581f, -2.136f, 0.f);
	auto SecondNormalizedVector = Vector3(1.996f, 3.108f, -4.554f);
	cout << "Normalizations:" << endl;
	cout << FirstNormalizedVector.Normalization() << endl;
	cout << SecondNormalizedVector.Normalization() << endl;
	cout << endl;
}

void LessonFour()
{
	PrintSectionName("LessonFour");

	//Dot Products
	auto FirstDotProductVector = Vector3(7.887f, 4.138f, 0.f);
	auto SecondDotProductVector = Vector3(-8.802f, 6.776f, 0.f);
	auto ThirdDotProductVector = Vector3(-5.955f, -4.904f, -1.874f);
	auto FourthdDotProductVector = Vector3(-4.496f, -8.755f, 7.103f);

	cout << "Dot products:" << endl;
	cout << Vector3::DotProduct(FirstDotProductVector, SecondDotProductVector) << endl;
	cout << Vector3::DotProduct(ThirdDotProductVector, FourthdDotProductVector) << endl;
	cout << endl;

	//Angles (Value of Theta)
	auto FirstAngleVector = Vector3(3.183f, -7.627f, 0.f);
	auto SecondAngleVector = Vector3(-2.668f, 5.319f, 0.f);
	auto ThirdAngleVector = Vector3(7.35f, 0.221f, 5.188f);
	auto FourthAngleVector = Vector3(2.751f, 8.259f, 3.985f);

	cout << "Angle values:" << endl;
	cout <<  Vector3::ValueOfTheta(FirstAngleVector, SecondAngleVector) << endl;
	cout << Math::RadiansToDegrees(
		Vector3::ValueOfTheta(
			ThirdAngleVector, 
			FourthAngleVector
		)
	) << endl;
	cout << endl;
}

void LessonFive()
{
	PrintSectionName("LessonFive");

	auto FirstVector = Vector3(-7.579f, -7.88f, 0.f);
	auto SecondVector = Vector3(22.737f, 23.64f, 0.f);

	cout << FirstVector << "\n" << SecondVector << endl;
	cout << "Are parallel: " << FirstVector.IsParallelTo(SecondVector) << endl;
	cout << "Are orthogonal: " << FirstVector.IsOrthogonalTo(SecondVector) << endl;
	PrintLine();

	auto ThirdVector = Vector3(-2.029f, 9.97f, 4.172f);
	auto FourthVector = Vector3(-9.231f, -6.639f, -7.245f);

	cout << ThirdVector << "\n" << FourthVector << endl;
	cout << "Are parallel: " << ThirdVector.IsParallelTo(FourthVector) << endl;
	cout << "Are orthogonal: " << ThirdVector.IsOrthogonalTo(FourthVector) << endl;
	PrintLine();

	auto FifthVector = Vector3(-2.328f, -7.284f, -1.214f);
	auto SixthVector = Vector3(-1.821f, 1.072f, -2.94f);

	cout << FifthVector << "\n" << SixthVector << endl;
	cout << "Are parallel: " << FifthVector.IsParallelTo(SixthVector) << endl;
	cout << "Are orthogonal: " << FifthVector.IsOrthogonalTo(SixthVector) << endl;
	PrintLine();

	auto SeventhVector = Vector3(2.118f, 4.827f, 0.f);
	auto EighthVector = Vector3(0.f);

	cout << SeventhVector << "\n" << EighthVector << endl;
	cout << "Are parallel: " << SeventhVector.IsParallelTo(EighthVector) << endl;
	cout << "Are orthogonal: " << SeventhVector.IsOrthogonalTo(EighthVector) << endl;
	cout << endl;
}

int main()
{
	FreeCalculations();
	LessonTwo();
	LessonThree();
	LessonFour();
	LessonFive();

	return 0;
}

