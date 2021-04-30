#include "Point2DSet.h"
#include <fstream>
#include <algorithm>

using namespace std;
using Iterator = std::vector<Point2D>::const_iterator;

void Point2DSet::add(const Point2D& aPoint) {
	fPoints.push_back(aPoint);
}

void Point2DSet::add(Point2D&& aPoint) {
	fPoints.push_back(move(aPoint));
}

void Point2DSet::removeLast() {
	fPoints.pop_back();
}

bool Point2DSet::doesNotTurnLeft(const Point2D& aPoint) const {
	return aPoint.isClockwise(fPoints[0], fPoints[1]);
}

void Point2DSet::populate(const std::string& aFileName) {
	int lPointCount;
	Point2D lPoint2D;

	ifstream aInStream(aFileName, ifstream::in);
	aInStream >> lPointCount;
	for (int i = 0; i < lPointCount; i++)
	{
		aInStream >> lPoint2D;
		add(lPoint2D);
	}
}

void Point2DSet::sort(Comparator aComparator) {
	stable_sort(fPoints.begin(), fPoints.end(), aComparator);
}

void Point2DSet::buildConvexHull(Point2DSet& aConvexHull) {

}

size_t Point2DSet::size() const {
	return fPoints.size();
}

void Point2DSet::clear() {
	fPoints.clear();
}

const Point2D& Point2DSet::operator[](size_t aIndex) const {
	return fPoints[aIndex];
}

Iterator Point2DSet::begin() const {
	return fPoints.begin();
}

Iterator Point2DSet::end() const {
	return fPoints.end();
}
