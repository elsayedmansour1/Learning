#include <iostream>
#include <string>

#define Logger_Info(KEY,MSG) LoggerStream(KEY,MSG)

using namespace std;

typedef enum {
    CMLogger_base    = 0x00000000,
    SYSCLogger_base  = 0x01000000,
    RPMSGLogger_base = 0x02000000,
    OUTOFRANGE_base  = 0xffff0000
}Base;

class abstractLogger{
    public:
        virtual string keyToString(int key) = 0;
};

class CMLogger : public abstractLogger {
    public:
        enum LogKey {
        CMLogger_test1 = Base::CMLogger_base,
        CMLogger_test2,
        CMLogger_test3
        };

        string keyToString(int key){
            switch (key) {
                case CMLogger_test1: return "CMLogger_test1";
                case CMLogger_test2: return "CMLogger_test2";
                case CMLogger_test3: return "CMLogger_test3";
                default:    return "Unknown"; // Handle unknown enum values
            }
        }
        static CMLogger& instance(){
            static CMLogger inst;
            return inst;
        }

};

class SYSCLogger : public abstractLogger{
    public:
        enum LogKey {
        SYSCLogger_test1 = Base::SYSCLogger_base,
        SYSCLogger_test2,
        SYSCLogger_test3
        };
        
        string keyToString(int key){
            switch (key) {
                case SYSCLogger_test1: return "SYSCLogger_test1";
                case SYSCLogger_test2: return "SYSCLogger_test2";
                case SYSCLogger_test3: return "SYSCLogger_test3";
                default:    return "Unknown"; // Handle unknown enum values
            }
        }
        
        static SYSCLogger& instance(){
            static SYSCLogger inst;
            return inst;
        }

};
template <typename enumType>
struct LoggerResolved;

//specilization
template<>
struct LoggerResolved<CMLogger::LogKey>{
    static CMLogger& instance() { return CMLogger::instance();} 
};

template<>
struct LoggerResolved<SYSCLogger::LogKey>{
    static SYSCLogger& instance(){ return SYSCLogger::instance();}
};

class LoggerStream{
    public:
    template <typename enumType>
    LoggerStream(enumType key,string msg):m_Key(key),m_Msg(msg),abs(&LoggerResolved<enumType>::instance()){
        cout << abs->keyToString(key) <<": " <<  m_Msg << endl;
    }
    ~LoggerStream(){
        cout << "i'm the destructor" << endl;
    }
    private:
    int m_Key;
    string m_Msg;
    abstractLogger* abs;
};


int main(){
    Logger_Info(CMLogger::CMLogger_test2,"i'm CMLite repo");
    Logger_Info(SYSCLogger::SYSCLogger_test1 ,"i'm systemcontroller repo");
    int* x = new int();
    return 0;
}