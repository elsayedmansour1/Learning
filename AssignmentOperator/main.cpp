#include <iostream>

using namespace std;
class buffer{
private:
    char *data;
    int m_size;
public:
    buffer(int size){
        m_size = size;
        data = new char[size];
    }
    void addData(const char *str){
        for (int i=0 ;i < m_size; i++){
            data[i] = str[i];
        }
    }
    void printData(){
        cout << "data: ";
        for (int i=0 ;i < m_size; i++){
            cout << data[i];
        }
        cout <<endl;
    }
    buffer& operator=(const buffer& other){
        //step 1 ignore self assignment
        if(this == &other)
            return *this;
        //step 2 free old memory
        delete[] data;
        //step 3 allocate new memory
        m_size = other.m_size;
        data = new char[m_size];
        //step 4 copy the containt
        for(int i =0; i<other.m_size;i++){
            data[i] = other.data[i];
        }

        return *this;
    }
    // Destructor
    ~buffer(){
        cout << "destructor called" << endl;
        delete[] data;
    }

};

int main()
{
    buffer containerA(8);
    containerA.addData("elsayed");
    containerA.printData();

    buffer containerB(4);
    // ❗ Copy assignment → uses default shallow copy
    containerB = containerA;      
    containerB.printData();

    // Change the content of containerA
    containerA.addData("huda");
    cout << "After changing containerA:" << endl;
    containerA.printData();
    containerB.printData();   // <-- this ALSO changed (bad!)

    return 0;
}