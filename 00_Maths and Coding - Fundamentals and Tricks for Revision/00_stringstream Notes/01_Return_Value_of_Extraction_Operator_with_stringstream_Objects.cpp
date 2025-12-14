/*



# Return Value of Extraction Operator (>>) with respect to stringstream Objects: 


--> The return value of the >> operator when used with std::stringstream objects is the std::stringstream object itself. This allows for chaining of extraction operations. 


--> In the while loop condition when using std::stringstream, it typically works by evaluating the state of the stream after extraction. The extraction operation will return the stream itself, which can be evaluated in a boolean context to check if it's in a good state (true) or not (false). 


--> In this loop, (sso >> num) will return ss, and then sso is evaluated in the boolean context of the while condition. If there's more input to extract, the condition will evaluate to true, and the loop will continue. When there's no more input or if there's a failure in extraction, the condition will evaluate to false, and the loop will terminate. 



*/




/*


# References Cited:  


* ChatGPT: 
https://chat.openai.com/ 


*/