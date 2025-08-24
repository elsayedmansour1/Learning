#include <iostream>
#include <string>

using namespace std;

int timeToMin(string str){
    int hour;
    int min;
    int postion = str.find(':');
    int endmin = str.find('')
    int totalMin;
    hour = std::stoi(str.substr(0 , postion));
    cout << "the min value: " <<str.substr(postion +1 ) <<endl;
    min = std::stoi(str.substr(postion +1 ));
    // int period = str.find
    totalMin = hour *60 + min; 
    return totalMin;
}

int main(){
    cout << "welcome elsayed" << endl;
    string str = "12:30pm-1:50pm";
    int postion = str.find('-');

    string s_firstDate = str.substr(0, postion);
    string s_endDate = str.substr(postion+1);
    int i_firstdate = timeToMin(s_firstDate);
    int i_enddate = timeToMin(s_endDate);
    cout << "the first date is: " << i_firstdate << " and the second date is: " << i_enddate << endl;
    cout << "the differntation between the two dates is: " << (i_firstdate - i_enddate)  << endl;

    return 0;
}