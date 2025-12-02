#include <iostream>
using namespace std;

template <typename T>
int min(T num1, T num2){
    return num1 < num2 ? num1 : num2;
}

#define min(x, y) (x < y ? x : y)

int main(){

}