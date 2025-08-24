#include <iostream>
#include <string>
#include <set>
#include <chrono> 
#include <vector>
#include <set>
#include <iterator>
using namespace std;


int numberOfRepeatedLetter(string str,char letter){
    int num = 1;
    for (char L :str){
        if (L == letter){
            num++;

        }
    }
    return num;
}

int findTheStartingPoint(string *str){
    multiset<int> myMultiset;
    for(char L : str[1]){
      myMultiset.insert(str[0].find(L));
    }
    multiset<int>::iterator it = myMultiset.begin();
    if(it != myMultiset.end()){
      return *it;
    }else {
      return 255;
    }
}

bool searchIfExist(string * str ,string *res){
    int len = str[1].size();
    string newStr;
    while(len <= str[0].size()){
      //Starting poit is to create string from the size of str[1]
      newStr = str[0].substr(0,len);
      bool notFound = false;
      string secStr = str[1];
      for (char L : secStr){
        // secStr = aad -> a is in (aabd) true -> cut// aad -> a is in (abd) true -> cut// aad -> d is in (bd) true -> cut
        // secStr = aed -> a is in (aaab)true -> cut// ed -> e is in (aaab) false -> break
        // didn't found the L letter 
        int pos =  newStr.find(L);
        if(pos == string::npos){
            notFound = true;
            break;
        }
        //reach to last letter
        if(pos >= len){
            newStr = newStr.substr(0,pos) + newStr.substr(pos+1);
        } else {
            newStr = newStr.substr(0,pos) + newStr.substr(pos);
        }
      }
      // purpose is when we reduce the string more, till the new string is not valid 
      if (!notFound){
        //str =  jefaa -> j #num in str[1] =>1 && newStr = hffaksfaje 
        for (char L: str[1]){
            if(numberOfRepeatedLetter(str[1],L) > numberOfRepeatedLetter(newStr,L)){

              return false;
            }
        }
        *res = newStr;
        return true;
      }
      len++;
    }
    *res = str[0];
    return false;
}


string getTheReduceStr(string * str){
            // str[0].size() -----------------
            // str[1].size() -----
            // maxlen     =       <----------> 
    int maxlen = str[0].size() - str[1].size();
    int iteration = 0;
    //TO DO: you should search for starting point instead of starting from the begaining always
    int startPos = findTheStartingPoint(str);
    if(startPos == 255){
      return string();
    }
    string result = str[0].substr(startPos);
    string newstr[2] ;

    while(iteration <= maxlen){
        newstr[0] = result;
        newstr[1] = str[1];
        //TO DO: use only result for input and output instead of using newstr[0] and then make newstr string not array of strings; 
        if(!searchIfExist(newstr , &result)){
            if(iteration > 0 ){
                result = str[0].substr(iteration-1,result.size()+1);
                break;
            } else {
            }
          //because it's impossible to reduse the result string more
        } else if (result.size() == str[1].size()){
            break;
        }
        iteration ++;
        result = result.substr(1);
    }

    return result;
}

int main() {
    vector<vector<string>> testCases = {
        {"caae", "cae"},                  // Expected: caae
        {"aaabaaddae", "aed"},            // Expected: dae
        {"aabdccdbcacd", "aad"},          // Expected: aabd
        {"ahffaksfajeeubsne", "jefaa"},   // Expected: aksfaje
        {"aaffhkksemckelloe", "fhea"},    // Expected: affhkkse
        {"aaffsfsfasfasfasfasfasfacasfafe", "fafe"},   // Expected: fafe
        {"aaffsfsfasfasfasfasfasfacasfafe", "fafsf"}   // Expected: affsf
    };
    for (int i = 0; i < testCases.size(); i++) {
        string arr[2] = {testCases[i][0], testCases[i][1]};
        string result = getTheReduceStr(arr);
        cout << "Test " << i + 1 << " - Input: " << arr[0] 
             << ", Pattern: " << arr[1] 
             << " -> Found: " << result << endl;
    }

    return 0;
}


#if flase

bool hasAll(string strArr[], int min, int max) {
  // cout << "hasAllString start. min:" << min << " max:" << max << endl;
  multiset<char> rChars(begin(strArr[1]), end(strArr[1]));
  for (int i = min ; i <= max ; i++) {
    // cout << "." << flush;
    auto it = rChars.find(strArr[0][i]);
    if (it != rChars.end()) {
      // cout << "-";
      rChars.erase(it);
    }
  }
  // cout << endl << "remaining chars:" << rChars.size() << endl;
  return (rChars.size() == 0);
}

string MinWindowSubstring(string strArr[], int arrLength) {
  
  vector<set<int> > charLocs(strArr[1].size());

  for (size_t i1 = 0 ; i1 < strArr[1].size() ; i1++) {
    for (size_t i2 = 0 ; i2 < strArr[0].size() ; i2++) {
      if (strArr[0][i2] == strArr[1][i1]) {
        charLocs[i1].insert(i2);
    }
    }
  }


  set<int> allLocs;
  for (const set<int>& s : charLocs) {
    copy(begin(s), end(s), inserter(allLocs, begin(allLocs)));
  }

  int minPos = *(--(allLocs.end()));
  int maxPos = *(allLocs.begin());
  
  int ansMin = minPos, ansMax = maxPos;
  size_t da = ansMax - ansMin;
  size_t sz2 = strArr[1].size();
  
  for (auto itn = begin(allLocs) ; itn != end(allLocs) ; ++itn ) {
    for (auto itx = allLocs.rbegin() ; itx != allLocs.rend() ; ++itx) {
      size_t min = *itn, max = *itx;
      if ((max - min) >= da) { continue; }
      if ((max - min) < sz2-1) { break; }
      if (hasAll(strArr, min, max)) {
        ansMin = min;
        ansMax = max;
        da = max - min;
      }
    }

  }
  return strArr[0].substr(ansMin, ansMax-ansMin+1); // strArr[0];
}

int main(void) { 
   
  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. */
     string A[] = {"aaffsfsfasfasfasfasfasfacasfafe", "fafsf"};
  auto start = std::chrono::high_resolution_clock::now();
  int arrLength = sizeof(A) / sizeof(*A);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duration = end - start;
  
  cout << MinWindowSubstring(A, arrLength);
  std::cout << "Execution time: " << duration.count() << " ms\n";
  return 0;
  
}
#endif
#if false
int searchforStr(string provStr, string targStr,string *res){
  //the number of found letter
  int ret = 0;
  //search in targstr if all letter of it are exist on  provstr
  for(char L : targStr){
    int pos = provStr.find(L);
    if(pos == string::npos){
      return ret;
    } else { 
      ret++;
    }
    //reach to last letter
    if(pos == provStr.size()){
        provStr = provStr.substr(0,pos) + provStr.substr(pos+1);
    } else {
        provStr = provStr.substr(0,pos) + provStr.substr(pos);
    }
  }
  *res = provStr;
  return ret;
}

bool checkIfweCanReduceTheStr(string provStr, string targStr,string *res){
  int iteration = 0;
  while(iteration <= provStr.size()-targStr.size()){
    iteration++;
    int num = searchforStr(provStr.substr(iteration),targStr,res);
    cout << "The found str: " << *res << " and the number of match letter: " << num << endl;
    if(num < targStr.size()){
      break;
    }
  }
  return false;
}
string MinWindowSubstring(string *arr){
  //step 1: cut the arr[0] to two strings from the center
  int centerPos = arr[0].size()/2;
  string str1 = arr[0].substr(0,centerPos);
  string str2 = arr[0].substr(centerPos);
  string res = arr[0];
  while ((str1.size()> arr[1].size() || str2.size()> arr[1].size())){
    //check if each string size is equal or bigger than the length of arr[1]
    if( centerPos >= arr[1].size()){
      //create two string and send them to search function
      int num = searchforStr(str1,arr[1],&res);
      checkIfweCanReduceTheStr(res,arr[1],&res);
      if(num != arr[1].size()){
        num = searchforStr(str2,arr[1],&res);
        cout << "the found str: " << res << " and the number of match letter: " << num << endl;
      } else {
        cout << "the found str: " << res << " and the number of match letter: " << num << endl;
      }
    }
    centerPos = res.size()/2;
    str1 = res.substr(0,centerPos);
    str2 = res.substr(centerPos);
    cout << "im still in the while loop: " << res << " " << str1 << " " << str2 <<endl;
  }
  cout << "//Check If we Can reduce the string\n";
  checkIfweCanReduceTheStr(res,arr[1],&res);
  cout << "the found str: " << res << endl;
  
  return string();
}
int main(){
    // string arr[] = {"caae", "cae"};
    // string arr[] = {"aaabaaddae", "aed"};
    string arr[] = {"aabdccdbcacd", "aad"};
    //
    auto start = std::chrono::high_resolution_clock::now();
    string result = MinWindowSubstring(arr);
    // End time
    auto end = std::chrono::high_resolution_clock::now();
    
    // Calculate duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    
    std::cout << "Execution time: " << duration.count() << " ms\n";
    cout << "the input str: " << arr[1] << " the found str: "  << result << endl;
    return 0;
}
#endif