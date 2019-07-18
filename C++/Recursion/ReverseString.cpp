#include <iostream>
using namespace std;

string reverse_string(string str){
    if(str.length() == 1){
        return str;
    }
    return str.substr(str.length() - 1).append(reverse_string(str.substr(0,str.length() - 1)));
}

string reverse_string2(string str){
    if(str.size() == 1){
        return str;
    }
    return reverse_string2(str.substr(1,str.size())).append(str.substr(0,1));
}

int main(){
    cout<<reverse_string("Zumrudu")<<endl;
    cout<<reverse_string2("Anka");
    return 0;
}