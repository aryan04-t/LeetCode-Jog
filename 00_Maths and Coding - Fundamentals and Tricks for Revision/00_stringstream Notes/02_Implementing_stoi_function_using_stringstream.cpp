#include<iostream>
#include<sstream>
using namespace std;


int stoi(string &s){

    stringstream sso;
    sso << s;

    int num;
    sso >> num;

    return num;

}

int main(){

    string s = "1000";
    int n = stoi(s);

    cout << "This is a number: " << (n + 2) << endl;

    return 0;

}