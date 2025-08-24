#include <iostream>
#include <string>


using namespace std;

class user
{
private:
    /* data */
    string userName;
    string telephoneNum;
public:
    //defualt constructor
    user(/* args */):userName("dumy"),telephoneNum("11111"){
        cout << "defualt constructor" << endl;
    }
    //copy constructor
    user(user& cpUser){
        cout << "copy constructor" << endl;
        userName = cpUser.userName;
        telephoneNum = cpUser.telephoneNum;
    }
    void changeUserName(string str){
        userName = str;
    }
    void changeTelephoneNum(string num){
        telephoneNum = num;
    }
    void printInfo(){
        cout << "the user name is: " << userName << endl;
        cout << "the user telephone number is: " << telephoneNum << endl;
    }
    ~user(){};
};

int main(){
    cout << "welcome elsayed (:" << endl;

    user user1;
    user1.changeUserName("Huda");
    user1.changeTelephoneNum("01004981057");
    user1.printInfo();
    user user2;
    user2 = user1;
    user2.printInfo();
    user1.changeUserName("Elsayed");
    user1.changeTelephoneNum("01019701628");
    user1.printInfo();
    user2.printInfo();



}