#include <iostream>
using namespace std;

int div_0 = 0;
const int divide(const int x, const int y){
    if(y == 0){
        throw div_0;
    }
    return x / y;
}

int main(){
    try{
        int x, y;
        cin >> x; cin >> y;
        int *arrPtr = new int[divide(x,y)];
        cout << *arrPtr;
    }
    catch(int error){
        cerr << "Error, cannot divide by 0";
    }
    return 0;
}