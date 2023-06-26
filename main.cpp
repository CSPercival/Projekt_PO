#include "geometry.h"

using namespace std;

int main(){
    Point2D<int> p0;
    Point2D<int> p1(1,2);
    Point2D<int> p2(1,2);
    Point2D<int> p3(4,2);
    Point2D<int> p4 = p3 + p2;
    Point2D<int> p5 = p3 - p1;
    Point2D<int> p6(1,1);
    Point2D<int> p7(1,1.6);

    if(p1 == p2){
        cout << "p4 : " << p4.x << " " << p4.y << endl;
        cout << "p5 : " << p5.x << " " << p5.y << endl;
        cout << "distance between p5 and p4: " << p5.distance(p4) << endl;
        cout << "distance between p4 and p5: " << p4.distance(p5) << endl;
        cout << "angle between p6 and OX: " << p6.angle() << endl;
        cout << "angle between p1 and p2: " << p1.angle(p2) << endl;
    }


    Line2D<int> l1;
    Line2D<int> l2(p1,p6);
    Line2D<int> l3(p1,p5);
    Point2D<int> p8 = l3.intersection(l2);
    Point2D<int> p9 = l2.intersection(l3);
    if(p8 == p9 && p8 == p1){
        cout << "well done" << endl;
    } else {
        cout << "XD" << endl;
    }
    cout << "p1 : " << p1.x << " " << p1.y << endl;
    cout << "p8 : " << p8.x << " " << p8.y << endl;
    cout << "p9 : " << p9.x << " " << p9.y << endl;
    
    long double res1 = l2.angle(l3);
    long double res2 = l3.angle(l2);

    cout << "l2: " << l2.A << " " << l2.B << " " << l2.C << endl;
    cout << "l3: " << l3.A << " " << l3.B << " " << l3.C << endl;
    cout << "angle between l2 and l3: " << res1 << " - " << res2 << endl;
    cout << "angle between l2 and OX: " << l2.angle() << endl;
    cout << "angle between l3 and OX: " << l3.angle() << endl;

    Point3D<int> p10;
    Point3D<int> p11(1,2,3);
    Point3D<int> p12(1,2,3);
    Point3D<int> p13(4,2,7);
    Point3D<int> p14 = p13 + p12;
    Point3D<int> p15 = p13 - p11;
    Point3D<int> p16(1,1,1);
    Point3D<int> p17(1,1.6,0.7);
    if(p11 == p12){
        cout << "Norm of p11: " << p11.norm() << endl;
    }


    PointND<double> p20({0.5, 1.5, 6.43, 23.1});
    cout << "Lenght of p20: " << p20.length() << endl;

    Segment2D<int> s1(p1,p6);
    Segment2D<int> s2(p1,p5);
    cout << "Are s2 and s1 parallel?: " << s2.parallel(s1) << endl;
    cout << "Are l2 and s1 parallel?: " << l2.parallel(s1) << endl;
    cout << "Are s2 and l2 parallel?: " << s2.parallel(l2) << endl;
    cout << "Are l2 and l3 parallel?: " << l2.parallel(l3) << endl;

    cout << "Does s1 and s2 intersect?: " << s1.intersect(s2) << endl;

    Point2D<int> p40(0,2);
    Point2D<int> p41(1,1);
    Point2D<int> p42(4,2);
    Point2D<int> p43(3,1);

    Line2D<int> l40(p40,p41);
    Line2D<int> l41(p42,p43);

    Segment2D<int> s40(p40,p41);
    Segment2D<int> s41(p42,p43);

    cout << "Does l40 and l41 intersect?: " << l40.intersect(l41) << endl;
    cout << "Does l41 and l40 intersect?: " << l41.intersect(l40) << endl;
    cout << "Does s40 and s41 intersect?: " << s40.intersect(s41) << endl;
    cout << "Does s41 and s40 intersect?: " << s41.intersect(s40) << endl;

    cout << "Does l40 and s41 intersect?: " << l40.intersect(s41) << endl;
    cout << "Does s41 and l40 intersect?: " << s41.intersect(l40) << endl;
    cout << "Does s40 and l41 intersect?: " << s40.intersect(l41) << endl;
    cout << "Does l41 and s40 intersect?: " << l41.intersect(s40) << endl;

    Point2D<int> p44(3,-1);
    Segment2D<int> s42(p40,p44);
    cout << endl;
    cout << "Does s42 and s41 intersect?: " << s42.intersect(s41) << endl;
    cout << "Does s41 and s42 intersect?: " << s41.intersect(s42) << endl;
    cout << "Does s42 and l41 intersect?: " << s42.intersect(l41) << endl;
    cout << "Does l41 and s42 intersect?: " << l41.intersect(s42) << endl;


    Point2D<double> p50(2,1);
    Point2D<double> p51(1,4);
    Point2D<double> p52(2,2);
    Point2D<double> p53(3,3);
    Point2D<double> p54(0,2);

    Set_Point2D<double> sp1({p50,p51,p52,p53,p54});
    Polygon2D<double> pg1 = sp1.convex_hull();

    cout << "sp1: " << endl;
    for(auto i : sp1.points){
        cout << i.x << " " << i.y << endl;
    }

    cout << "CONVEX HULL for sp1: " << endl;
    for(auto i : pg1.points){
        cout << i.x << " " << i.y << endl;
    }
    cout << "Area of pg1: " << pg1.area() << endl;

    Point2D<double> p55(2,2);
    Point2D<double> p56(2,3);
    Point2D<double> p57(0,3);
    Point2D<double> p58(3,1);
    cout << "Is p55 iside pg1?: " << pg1.inside(p55) << endl;
    cout << "Is p56 iside pg1?: " << pg1.inside(p56) << endl;
    cout << "Is p57 iside pg1?: " << pg1.inside(p57) << endl;
    cout << "Is p58 iside pg1?: " << pg1.inside(p58) << endl;

    return 0;
}