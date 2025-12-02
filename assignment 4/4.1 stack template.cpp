#include <iostream>
#include <vector>
using namespace std;

template <typename T>

class Stack{
    private:
        vector<T> arr;
    public:
        bool empty(){
            return arr.size() > 0 ? false : true;
        }

        bool empty() const{
            return arr.size() > 0 ? false : true;
        }

        void push(const T &val){
            arr.push_back(val);
        }

        T& top(){
            return arr.back();
        }

        const T& top() const{
            return arr.back();
        }

        void pop(){
            arr.pop_back();
        }
        
        friend Stack<T> operator+(const Stack<T> &stack1, const Stack<T> &stack2){
            Stack<T> added = stack1;
            for(unsigned x = 0; x < stack2.arr.size(); x++){
                added.arr.push_back(stack2.arr[x]);
            }
            return added;
        }
};


