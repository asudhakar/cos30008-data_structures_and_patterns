#include "Point2D.h"

static const Point2D gCoordinateOrigin;

double Point2D::directionTo(const Point2D& aOther) const {
	return atan2(fPosition.getY() - aOther.getY(), fPosition.getX() - aOther.getX());
}

double Point2D::magnitudeTo(const Point2D& aOther) const {
	return sqrt(pow(fPosition.getX() - aOther.getX(), 2) + pow(fPosition.getY() - aOther.getY(), 2));
}

Point2D::Point2D() : fId(""), fPosition(0, 0), fOrigin(&gCoordinateOrigin) {

}

Point2D::Point2D(const std::string& aId, double aX, double aY) : fId(aId), fPosition(aX, aY), fOrigin(&gCoordinateOrigin) {

}

Point2D::Point2D(std::istream& aIStream) : fOrigin(&gCoordinateOrigin) {
	double lX, lY;

	aIStream >> fId >> lX >> lY;

	fPosition.setX(lX);
	fPosition.setX(lY);
}

const std::string& Point2D::getId() const {
	return fId;
}

void Point2D::setX(const double& aX) {
	fPosition.setX(aX);
}

const double Point2D::getX() const {
	return fPosition.getX();
}

void Point2D::setY(const double& aY) {
	fPosition.setX(aY);
}

const double Point2D::getY() const {
	return fPosition.getY();
}

void Point2D::setOrigin(const Point2D& aPoint) {
	fOrigin = &aPoint;
}

const Point2D& Point2D::getOrigin() const {
	return *fOrigin;
}

Vector2D Point2D::operator-(const Point2D& aRHS) const {
	Vector2D lResult;
	lResult.setX(fPosition.getX() - aRHS.getX());
	lResult.setY(fPosition.getY() - aRHS.getY());
	return lResult;
}

double Point2D::direction() const {
	return directionTo(*fOrigin);
}

double Point2D::magnitude() const {
	return magnitudeTo(*fOrigin);
}

bool Point2D::isCollinear(const Point2D& aOther) const {
	double lResult;
	lResult = abs(direction() - aOther.direction());
	return	lResult <= 0.0001 && lResult >= 0 ||
			lResult <= 3.1416 && lResult >= 3.1415;
}

//bool Point2D::isClockwise(const Point2D& aP0, const Point2D& aP2) const {
//
//}
//
//bool Point2D::operator<(const Point2D& aRHS) const {
//
//}
//
//std::ostream& operator<<(std::ostream& aOStream, const Point2D& aObject) {
//
//}
//
//std::istream& operator>>(std::istream& aIStream, Point2D& aObject) {
//
//}