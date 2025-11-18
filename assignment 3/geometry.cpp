#include "geometry.h"

//PointArray Definitions
PointArray :: PointArray(){
    size = 0;
    capacity = 0;
    points = new Point[size];
}
PointArray :: PointArray(const Point pts[], const int sz){
    size = sz;
    capacity = sz;
    points = new Point[sz];
    for(int x = 0; x < sz; x++){
        points[x] = pts[x];
    }
}
PointArray :: PointArray(const PointArray &ca){
    points = new Point[ca.size];
    size = ca.size;
    capacity = ca.size;
    for(int x = 0; x < ca.size; x++){
        points[x] = ca.points[x];
    }
}
PointArray :: ~PointArray(){
    delete[] points;
}
void PointArray :: resize(int n){
    if(n < 0) n = 0;

    if(n > capacity){
        int newCap = (capacity == 0) ? 1 : capacity;
        while(newCap < n) newCap *= 2;
        
        Point *newPts = new Point[newCap];

        for(int x = 0; x < size; x++){
            newPts[x] = points[x];
        }

        delete[] points;
        points = newPts;
        capacity = newCap;
    }
    size = n;

    if(capacity > 0 && size < capacity / 4){
        int newCap = max(size, capacity / 2);
        Point *newPts = (newCap > 0) ? new Point[newCap] : nullptr;

        for(int x = 0; x < size; x++){
            newPts[x] = points[x];
        }

        delete[] points;
        points = newPts;
        capacity = newCap;
    }
}
void PointArray :: push_back(const Point &p){
    if(size == capacity){
        int newCap = (capacity == 0) ? 1 : capacity * 2;
        Point *newPts = new Point[newCap];
        for(int x = 0; x < size; x++){
            newPts[x] = points[x];
        }
        delete[] points;
        points = newPts;
        capacity = newCap;
    }
    points[size++] = p;
}

void PointArray :: clear(){
    resize(0);
}
void PointArray :: insert(const int pos, const Point &p){
    if(pos < 0 || pos > size) return;
    resize(size + 1);
    for(int x = size - 1; x > pos; x--){
        points[x] = points[x - 1];
    }
    points[pos] = p;
}
void PointArray :: remove(const int pos){
    if(pos < 0 || pos >= size) return;
    for(int x = pos; x < size - 1; x++){
        points[x] = points[x + 1];
    }
        resize(size - 1);
}
const int PointArray :: getSize() const{
    return size;
}
Point* PointArray :: get(const int pos){
    if(pos < 0 || pos >= size)
        return nullptr;
    return &points[pos];
}
const Point* PointArray :: get(const int pos) const{
    if(pos < 0 || pos >= size)
        return nullptr;
    return &points[pos];
}

//Polygon Definitions
int Polygon :: numPoly = 0;
Polygon :: Polygon(Point pointArr[], const int numPoint) : points(pointArr, numPoint){
    numPoly++;
}
Polygon :: Polygon(const PointArray &p) : points(p){
    numPoly++;
}

//Rectangle Definitions
Point constructorPoints[4];
Point* updateConstructorPoints(const Point &p1 , 
                               const Point &p2 , 
                               const Point &p3 , 
                               const Point &p4 = Point (0 ,0)) {
    constructorPoints [0] = p1;
    constructorPoints [1] = p2;
    constructorPoints [2] = p3;
    constructorPoints [3] = p4;
    return constructorPoints ;
}
Rectangle :: Rectangle(const Point &lL, const Point &uR) : 
 Polygon(updateConstructorPoints(lL, Point(uR.getX(), lL.getY()), 
                                 uR, Point(lL.getX(), uR.getY())), 4) 
{}
Rectangle :: Rectangle(const int lLx, const int lLy, const int uRx, const int uRy) : 
 Polygon(updateConstructorPoints(Point(lLx, lLy), 
                                 Point(uRx, lLy), 
                                 Point(uRx, uRy), 
                                 Point(lLx, uRy)), 4)
{}
double Rectangle :: area() const {
    int length = points.get(1)->getY() - points.get(0)->getY();
    int width = points.get(2)->getX() - points.get(1)->getX();
    return abs((double) length * width); 
}

//Triangle Definitions
Triangle :: Triangle(const Point &a, const Point &b, const Point &c) : 
 Polygon(updateConstructorPoints(a, b, c), 3) 
{}
double Triangle :: area() const {
    const double x0 = points.get(0)->getX(), y0 = points.get(0)->getY();
    const double x1 = points.get(1)->getX(), y1 = points.get(1)->getY();
    const double x2 = points.get(2)->getX(), y2 = points.get(2)->getY();

    const double a = hypot(x1 - x0, y1 - y0);
    const double b = hypot(x2 - x1, y2 - y1);
    const double c = hypot(x0 - x2, y0 - y2);

    const double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
