#include <iostream>

using namespace std;

int my_product(int x,int y){
    if(x == 1){
        return y;
    }
    return y + my_product(x-1, y);
}

int my_pow(int x, int y){
    if(y == 1){
        return x;
    }
    return my_product(x,my_pow(x, y - 1));
}

int main(){
    cout<<my_pow(5,2);

    return 0;
}