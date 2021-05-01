/*

   Convex Hull, COS30008, 2021

*/

//#define Main
//#define Point2DTest
#define Point2DSetTest
#define AutoFill

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

#ifdef Point2DTest
#include "Point2D.h"

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int main() {
    Point2D p1;
    stringstream ss;

#ifdef AutoFill
    ss << "P1" << " " << -2 << " " << -1;
    ss >> p1;
#else
    cin >> p1;
#endif // AutoFill
    cout << p1 << endl;

    Point2D p2("P2", -1, -1);
    cout << p2 << endl;
    cout << "P1 direction to origin: " << p1.direction() * 180 / 3.141592 << " degrees" << endl;
    cout << "P2 direction to origin: " << p2.direction() * 180 / 3.141592 << " degrees" << endl;
    cout << "P1 magnitude from origin: " << p1.magnitude() << endl;
    cout << "P2 magnitude from origin: " << p2.magnitude() << endl;
    cout << "Is P0, P1 and P2 collinear: " << p2.isCollinear(p1) << endl;
    cout << "P1 < P2: " << (p1 < p2) << endl;
    cout << "P1 - P2: " << (p1 - p2) << endl;

}
#endif Test

#ifdef Point2DSetTest
#include "Point2DSet.h"

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    Point2DSet lSet;

    lSet.populate("points.txt");

    cout << "Points:" << endl;

    for (const Point2D& p : lSet)
    {
        cout << p << endl;
    }

    Point2DSet lConvexHull;

    lSet.buildConvexHull(lConvexHull);

    cout << endl << "Convex hull:";

    size_t lSize = lConvexHull.size();

    for (size_t i = 0; i < lSize; i++)
    {
        cout << endl
            << lConvexHull[i].getId()
            << " - "
            << lConvexHull[(i + 1) % lSize].getId();
    }
    cout << endl;
}
#endif Point2DSetTest
