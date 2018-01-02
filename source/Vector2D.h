#pragma once
#include <ostream>

class Vector2D {
public:
	float x;
	float y;
	Vector2D()
		: x{ 0.0f },
		y{ 0.0f }
	{};
	Vector2D(float x, float y)
		: x{ x },
		y{ y }
	{};
	friend std::ostream& operator<<(std::ostream &os, const Vector2D& vec);
	Vector2D& add(const Vector2D& vec);
	Vector2D& sub(const Vector2D& vec);
	Vector2D& mult(const Vector2D& vec);
	Vector2D& div(const Vector2D& vec);
	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);
	Vector2D& operator+=(const Vector2D& vec);
	Vector2D& operator-=(const Vector2D& vec);
	Vector2D& operator*=(const Vector2D& vec);
	Vector2D& operator/=(const Vector2D& vec);
	Vector2D& operator*(const int& scalarMult);
	Vector2D& operator*(const float& scalarMult);
	Vector2D& zeroOut();
	
};