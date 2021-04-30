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

}

void Point2DSet::populate(const std::string& aFileName) {
	ifstream aInStream(aFileName, ifstream::in);
}

void Point2DSet::sort(Comparator aComparator) {

}

void Point2DSet::buildConvexHull(Point2DSet& aConvexHull) {

}

size_t Point2DSet::size() const {

}

void Point2DSet::clear() {

}

const Point2D& Point2DSet::operator[](size_t aIndex) const {

}

Iterator Point2DSet::begin() const {

}

Iterator Point2DSet::end() const {

}
