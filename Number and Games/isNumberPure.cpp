#include<iostream>
#include<map>

using namespace std;

// The number is pure if recursive sum of squares of digits of the number boils down to 1.

bool isNumberPure(int num){
    map<int,int> intermediate_numbers;

    int temp = 0;
    while(num != 1){
        while(num){
            int digit = num % 10;
            temp += digit * digit;
            num /= 10;
        }
        cout<<temp<<"-->";
        if(intermediate_numbers.find(temp) != intermediate_numbers.end()){
            cout<<"Loop detected!";
            return false; 
        }
        intermediate_numbers.insert(make_pair(temp,1));
        num = temp;
        temp = 0;
    }

    return true;
}
/*
int main(){
    cout<<"Is Pure?? -> "<<isNumberPure(41);
    return 1;
}
*/
