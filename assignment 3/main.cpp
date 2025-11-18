#include "geometry.h"

void printAttributes(Polygon *p){
    cout << "Area: " << p->area() << "\n";
    cout << "p's points are:\n";
    const PointArray *pa = p->getPoints();
    for(int x = 0; x < pa->getSize(); x++){
     cout << "(" << pa->get(x)->getX() << ", " << pa->get(x)->getY() << "\n";
    }
}

int main(int argc, char *argv[]){
    tuple<int, int> lL, uR; int x, y;
    cout << "Enter lL coords of rectangle lL - x y: ";
    cin >> x >> y; lL = make_tuple(x, y);
    cout << "Enter uR coords of rectangle uR - x y: ";
    cin >> x >> y; lL = make_tuple(x, y);
    Rectangle(get<0>(lL), get<1>(lL), get<0>(uR), get<1>(uR));
    
    return 0;
}