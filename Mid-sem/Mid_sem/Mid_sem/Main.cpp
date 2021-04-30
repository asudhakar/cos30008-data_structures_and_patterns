/*

   Convex Hull, COS30008, 2021

*/

//#define Main
#define Test

#ifdef Main
#include "Point2DSet.h"

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    Point2DSet lSet;

    lSet.populate( "points.txt" );

    cout << "Points:" << endl;

    for ( const Point2D& p : lSet )
    {
        cout << p << endl;
    }

    Point2DSet lConvexHull;

    lSet.buildConvexHull( lConvexHull );

    cout << "Convex hull:" << endl;

    size_t lSize = lConvexHull.size();

    for ( size_t i = 0; i < lSize; i++ )
    {
        cout
            << lConvexHull[i].getId()
            << " - "
            << lConvexHull[(i + 1) % lSize].getId() << endl;
    }
    
    return 0;
}
#endif Main

#ifdef Test
#include "Point2D.h"

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    Point2D p1;
    cin >> p1;
    cout << p1;

    Point2D p2("1", -1, -1);
    cout << "P1 direction to origin: " << p1.direction() * 180 / 3.141592 << " degrees" << endl;
    cout << "P2 direction to origin: " << p2.direction() * 180 / 3.141592 << " degrees" << endl;
    cout << "P1 magnitude from origin: " << p1.magnitude() << endl;
    cout << "P2 magnitude from origin: " << p2.magnitude() << endl;
    cout << "Is P0, P1 and P2 collinear: " << p2.isCollinear(p1) << endl;
}
#endif Test
