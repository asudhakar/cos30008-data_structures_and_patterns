#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D(double aX, double aY) : fX(aX), fY(aY) {

}

void Vector2D::setX(double aX) {
	fX = aX;
}
double Vector2D::getX() const {
	return fX;
}
void Vector2D::setY(double aY) {
	fY = aY;
}
double Vector2D::getY() const {
	return fY;
}

Vector2D Vector2D::operator+(const Vector2D& aRHS) const {
	return Vector2D(fX + aRHS.getX(), fY + aRHS.getY());;
}

Vector2D Vector2D::operator-(const Vector2D& aRHS) const {
	return Vector2D(fX - aRHS.getX(), fY - aRHS.getY());
}

double Vector2D::magnitude() const {
	return sqrt(pow(fX, 2) + pow(fY, 2));
}

double Vector2D::direction() const {
	return atan2(fY, fX);
}

double Vector2D::dot(const Vector2D& aRHS) const {
	return fX * aRHS.getX() + fY * aRHS.getY();
}

double Vector2D::cross(const Vector2D& aRHS) const {
	return fX * aRHS.getY() - aRHS.getX() * fY;
}

double Vector2D::angleBetween(const Vector2D& aRHS) const {
	if (magnitude() == 0 && aRHS.magnitude() == 0)
		return 0;

	return acos(dot(aRHS) / magnitude() * aRHS.magnitude());
}

std::ostream& operator<<(std::ostream& aOutStream, const Vector2D& aObject) {
	aOutStream << "[" << aObject.fX << ", " << aObject.fY << "]";
	return aOutStream;
}

std::istream& operator>>(std::istream& aInStream, Vector2D& aObject) {
	double lX, lY;
	aInStream >> lX >> lY;
	aObject = Vector2D(lX, lY);
	return aInStream;
}