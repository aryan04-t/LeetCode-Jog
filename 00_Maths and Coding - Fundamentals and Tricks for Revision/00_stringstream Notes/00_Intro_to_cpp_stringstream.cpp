/*


# stringstream in C++: 

--> To use stringstream, include <sstream> header file 

--> Then create a object of stringstream class, and using this object you can just convert a "number" to "string" or a "string" to "number", or you can also just exctract all the words from a string which has leading, and/or trailing, and/or inconsistent spacing in between the words 

--> Internally, std::stringstream uses std::stringbuf, which is a buffer for std::string objects, and it's implemented using iostream, and that's why you can use insertion operator (<<) or extraction operator (>>) with "stringstream objects" 


*/



// Extracting words from a string which has any type of whitespace character formatting (leading spaces, trailing spaces, inconsistent spaces between words, or all of the above) it doesn't matter 


#include<iostream> 
#include<sstream> 
using namespace std; 


int main(){

    string a;
    cout << "Enter string stream: ";
    getline(cin, a);

    stringstream sso;
    sso << a;
    
    string temp;
    cout << "Output is: ";
    while(sso >> temp){
        cout << "|" << temp << "| ";
    }

    return 0;

}



/*


# Tokenization in stringstream: 


@ Here we will be understanding how does stringstream works under the hood, such that it is able to extract all the words: 

--> When you pass a string to the "stringstream object", all the characters get copied as it is to the "stringstream", but when you try to extract some data from the "stringstream", the extraction operator (>>) does tokenization, and this tokenization is done based on the default delimiters, and the default delimiters for stringstream are "whitespace characters". [These are the escape sequences of few of the whitespace characters: '\n', '\0', '\t', etc.] 

--> stringstream provides the data, and the extraction operator does the "tokenization".

--> Here tokenization basically means that you're ignoring "whitespace characters" because they're the default delimitersm, and by doing this you're able to extract individual words, and these words are also referred as tokens. 



@ Example: 

- This is the input string for our stringstream:
"     Hey!! I   am    Aryan Tomar  "

- Now, this above string is stored as it is in the string buffer, means all the spaces are also stored in the string buffer 

- So string stream behaves as queue, and the string is processed left to right, that's why now when you try to extract some data from the stringstream for the first time, you get the 1st word which is present in the stringstream as an output, and as you keep extracting things from the stringstream again and again repetitively, you just keep getting the next word which is present inside the stringstream, until the stringstream is empty 


*/




/*


# References Cited:  


* ChatGPT: 
https://chat.openai.com/ 


* CPlusPlus (std::stringstream::stringstream): 
https://cplusplus.com/reference/sstream/stringstream/stringstream/ 


*/