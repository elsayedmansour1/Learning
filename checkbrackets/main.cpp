#include <iostream>
#include <string>


using namespace std;

bool checkTheBrackets(string str){
    string newstr;
    string openbrackets ="({[";
    string closebrackets = ")}]";
    char prev;
    for (char L : str){
        
        if(openbrackets.find(L)!= string::npos){
            newstr = newstr + L;
            
        } else if(closebrackets.find(L)!= string::npos){
            if(newstr.size() >= 1){
                prev = newstr[newstr.size()-1];
            } else {
                prev = newstr[newstr.size()];
            }
            if(prev == '(' && static_cast<int>(prev) == static_cast<int>(L)-1){
                // to remove the last characher
                if(newstr.size() > 1){
                    newstr = newstr.substr(0,newstr.size()-1);
                }else {
                    //we didn't use the previous equal because the newstr now has only one characher.
                    newstr = newstr.substr(newstr.size());
                }
                
            } else if( static_cast<int>(prev) > 50 && static_cast<int>(prev)== static_cast<int>(L)-2){
                
                if(newstr.size() > 1){
                    newstr = newstr.substr(0,newstr.size()-1);
                }else {
                    //we didn't use the previous equal because the newstr now has only one characher.
                    newstr = newstr.substr(newstr.size());
                }            
            } else {
                return false;
            }
        }
    }
    cout << "the newstr is: " << newstr << endl;
    if(!newstr.empty()){
       return false; 
    }
    return true;
}
int main(){
    //step1 :test case
    string str;
    str = "[({)";
    str = "(){}[]";
    str = "({})[]";
    str = "{({[]})}{(])}";
    str = "]()";
    str = "(coder)(byte))";
    str = "(c(oder)) b(yte)";
    bool res = checkTheBrackets(str);
    cout << "the validation is: " << (res? "true":"false") << endl;
    return 0;
}