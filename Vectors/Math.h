class Math
{
public:

	static const float PI;

	static float RadiansToDegrees(float radians);
	static bool IsNearlyZero(float value);
	static bool IsNearlyZero(float value, float tolerance);

private:

	static const float TOLERANCE;
};