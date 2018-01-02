#include "Vector2D.h"

Vector2D & Vector2D::add(const Vector2D & vec){
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

Vector2D & Vector2D::sub(const Vector2D & vec){
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}

Vector2D & Vector2D::mult(const Vector2D & vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
	return *this;
}

Vector2D & Vector2D::div(const Vector2D & vec)
{
	this->x /= vec.x;
	this->y /= vec.y;
	return *this;
}

Vector2D & Vector2D::operator+=(const Vector2D & vec){
	return this->add(vec);
}

Vector2D & Vector2D::operator-=(const Vector2D & vec)
{
	return this->sub(vec);
}

Vector2D & Vector2D::operator*=(const Vector2D & vec)
{
	return this->mult(vec);
}

Vector2D & Vector2D::operator/=(const Vector2D & vec)
{
	return this->div(vec);
}

Vector2D & Vector2D::operator*(const int & scalarMult){
	this->x *= scalarMult;
	this->y *= scalarMult;
	return *this;
}

Vector2D & Vector2D::operator*(const float & scalarMult){
	this->x *= scalarMult;
	this->y *= scalarMult;
	return *this;
}

Vector2D & Vector2D::zeroOut(){
	this->x = this->y = 0.0f;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Vector2D & vec)
{
	return os << "X: " << vec.x << ", Y: " << vec.y << '\n';
}

Vector2D & operator+(Vector2D & v1, const Vector2D & v2)
{
	return v1.add(v2);
}

Vector2D & operator-(Vector2D & v1, const Vector2D & v2)
{
	return v1.sub(v2);
}

Vector2D & operator*(Vector2D & v1, const Vector2D & v2)
{
	return v1.mult(v2);
}

Vector2D & operator/(Vector2D & v1, const Vector2D & v2)
{
	return v1.div(v2);
}
