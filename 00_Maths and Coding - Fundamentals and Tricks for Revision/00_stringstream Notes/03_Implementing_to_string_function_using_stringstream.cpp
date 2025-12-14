#include<iostream> 
#include<sstream> 
using namespace std; 


string toString(int n){

    stringstream sso;
    sso << n;

    string s;
    sso >> s; 

    return s;

}


int main(){
    
    int n = 1000; 
    string output = toString(n); 

    cout << "This is a string: " << output + "2" << endl; 
    
    return 0;

}