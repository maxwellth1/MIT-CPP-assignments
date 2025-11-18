#include <iostream>
#include <algorithm>
#include <math.h>
#include <tuple>
using namespace std;

//Point Class
class Point{
    private:
        int x, y;
    public:
    //Constructor
        Point(int x = 0, int y = 0) : x(x), y(y) {}

    //Functions
        int getX() const {return x;}
        int getY() const {return y;}
        void setX(const int xx){x = xx;}
        void setY(const int yy){y = yy;}
};

//PointArray class
class PointArray{
    private:
        Point *points;
        int size; int capacity;
        //resize only accessed internally by PointArray class
        void resize(int n);

    public:
    //Constructors
        PointArray();
        PointArray(const Point pts[], const int size);
        PointArray(const PointArray &ca);
        ~PointArray();

    //Functions
        void push_back(const Point &p);
        void insert(const int pos, const Point &p);
        void remove(const int pos);
        const int getSize() const;
        void clear();
        Point* get(const int pos);
        const Point* get(const int pos) const;
};

//Polygon Class
class Polygon{
    protected:
        PointArray points;
        static int numPoly;
    public:
    //Constructors
        Polygon(Point point[], const int numPoint);
        Polygon(const PointArray &p);
        virtual ~Polygon(){numPoly--;}

    //Functions
        virtual double area() const = 0;
        static int getNumPolygons(){return numPoly;}
        int getNumSides() const {return points.getSize();}
        const PointArray* getPoints() const {return &points;}
};

//Recatangle Class, inherits from Polygon class
class Rectangle : public Polygon{
    public:
    //Constructors
        Rectangle(const Point &lL, const Point &uR);
        Rectangle(const int a, const int b, const int c, const int d);

    //Function
        virtual double area() const;
};

//Triangle Class, inherits from Polygon class
class Triangle : public Polygon{
    public:
    //Constructor
        Triangle(const Point &a, const Point &b, const Point &c);

    //Function
        virtual double area() const;
};