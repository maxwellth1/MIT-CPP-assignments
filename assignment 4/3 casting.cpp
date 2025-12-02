#include <iostream>
#include "geometry.h"
using namespace std;

void cast(Rectangle* rect){
    Triangle *tri1 = static_cast<Triangle *>(rect);
    Triangle *tri2 = dynamic_cast<Triangle *>(rect);
}