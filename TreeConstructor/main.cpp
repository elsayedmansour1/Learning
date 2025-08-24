#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;
string TreeConstructor(string str[], int arrLength){
    map<int,set<int>> mp;
    set<int> parents;
    int pos, child, parent;
    //to gather all parents in the string
    for(int i = 0 ; i< arrLength ; i++){
        pos = str[i].find(',');
        parent = stoi(str[i].substr(pos+1 ,str[i].size()-1)) ;
        child = stoi(str[i].substr(1 ,pos-1));
        parents.insert(parent);

    }
    //to set all childs for there parents
    for (auto N  : parents){
        set<int> vec;
        for (int i = 0 ; i< arrLength ; i++){
            pos = str[i].find(',');
            parent = stoi(str[i].substr(pos+1 ,str[i].size()-1)) ;
            child = stoi(str[i].substr(1 ,pos-1));
            if (parent == N) {
               vec.insert(child); 
            }
        }
        mp[N] = vec; 
    }
    //*this to handle if there is multiple parents for one node 
    for (int N : mp.at(*parents.begin())) {
        for (auto const& [key, s] : mp) {
            if (s.find(N) != s.end() && *parents.begin() != key) {
                return "false";
            }
        }
    }
    //*to check if the binary tree form not correct
    for (auto const& [key, value] : mp) {    
        if(value.size() >2){
            return "false";
        }
    }
    return "ture";
}
int main()
{
    // string str[] = {"(1,2)", "(3,2)", "(2,12)", "(5,2)"}; //false
    // string str[] = {"(1,2)", "(2,4)", "(5,7)", "(7,2)", "(9,5)"};//true
    // string str[] = {"(1,2)", "(2,4)", "(7,2)"};//true
    string str[] = {"(2,5)", "(2,6)"};//false
    int arrLength = sizeof(str) / sizeof(*str);
    cout << TreeConstructor(str,arrLength) << endl;

    return 0;
}