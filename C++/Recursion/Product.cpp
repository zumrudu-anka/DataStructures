#include <iostream>

using namespace std;

int my_product(int x, int y){
    if(x == 1){
        return y;
    }
    return y + my_product(x-1,y);
}

int my_product2(int x, int y){
    if(y == 1){
        return x;
    }
    return x + my_product(x, y-1);
}

int main(){
    cout<<my_product(2,3)<<endl<<my_product2(3,2);

    return 0;
}