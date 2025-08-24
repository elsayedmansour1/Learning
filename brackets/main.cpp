#include <iostream>
#include <map>
#include <cstring> // For memcpy
using namespace std;

char* GenerateBrackets(int n){
    int indx = n*2;
    char* arr = new char[indx];
    for(int i =0 ;i < indx ; i++){
        if((i%2) == 0){
            arr[i] = '(';
        } else {
            arr[i] = ')';  
        } 
    }
    return arr;
}

map<int, char*> movingBrackets(char *arr , int len,int step){
    char arr2[len];
    int end = len-1;
    map<int, char*> mp; 
    int counter =0;
    //step 1: updating arr2
    for (int i = 0 ; i < len ; i++){
            // cout << i;
        arr2[i] = arr[i];
    }
    char* snapshot = new char[len];
    memcpy(snapshot, arr2, len);
    mp[counter] = snapshot;
    for (int i1 = 1 ; i1 <= 3 ; i1 ++){
        for (int i2=1 ; i2 < len ; i2++){
            char save;
            if (i2 == end - step*i1){  //the moment for changing the pattern
                // cout << "i'm in1 " << end -step*i1 << endl;
                save = arr2[i2];
                arr2[i2] = arr2[i2+1];
            } else if (i2 >= end - step*i1  && i2 != end){ // continue with new pattern till the end step
                // cout << "i'm in2 "<< end -step*i1 << endl;
                arr2[i2] = arr2[i2+1];
            } else if (i2 == end){ //end
                // cout << "i'm in3" << endl;
                arr2[i2] = save;
            } else { //start
                // cout << "i'm in4"<< endl;
                arr2[i2] = arr2[i2];
            }
        } 
    
        counter++;
        char* snapshot = new char[len];
        memcpy(snapshot, arr2, len);
        mp[counter] = snapshot;
        // cout << endl;
    }
    for (int i = 0 ; i < mp.size() ; i++) {
        cout << "value: " << mp.at(i) << endl;
    }
    return mp;
}

int main(){
    int num = 5;
    // char* arr = GenerateBrackets(num);
    // cout << endl;
    // movingBrackets(arr , (num *2),2);
    // movingBrackets(arr , (num *2),4);
    int newnum =((num -1)*(num -1)) +1;
    cout << "new num is: " << newnum << endl;
    return 0;
}