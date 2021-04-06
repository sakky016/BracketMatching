#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

//-------------------------------------------------------------------------------------
// This is a mapping of the open-close bracket pairs that are supported.
//-------------------------------------------------------------------------------------
static map<char, char> supportedBrackets = { {'{', '}'},
                                             {'[', ']'},
                                             {'(', ')'} };

//-------------------------------------------------------------------------------------
// Display usage information
//-------------------------------------------------------------------------------------
static void Usage()
{
    cout << "Usage:\n";
    cout << "BracketMatching.exe <string representing bracket sequence>\n";
    cout << "Example of a bracket sequence: {[()]}\n";
    cout << "Supported brackets are:\n";
    int index = 0;
    for (const auto supportedBracket : supportedBrackets)
    {
        cout << ++index << ". "  << supportedBracket.first << " " << supportedBracket.second << endl;
    }
}



//-------------------------------------------------------------------------------------
// Given a bracket type, finds out it's corresponding opening bracket. 
// If it is not found '\0' is returned.
//-------------------------------------------------------------------------------------
static char getMatchingOpeningBracket(char bracket)
{
    for (const auto supportedBracket : supportedBrackets)
    {
        if (supportedBracket.second == bracket)
        {
            return supportedBracket.first;
        }
    }

    return '\0';
}


//-------------------------------------------------------------------------------------
// M A I N
//-------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        Usage();
        return 0;
    }

    stack<char> sequence;
    string input = argv[1];
    for (const auto& ch : input)
    {
        if (!sequence.empty() && 
            sequence.top() == getMatchingOpeningBracket(ch))
        {
            // Found its closing bracket, remove from stack
            cout << "Pop " << ch << " from stack\n";
            sequence.pop();
        }
        else
        {
            cout << "Push " << ch << " to stack\n";
            sequence.push(ch);
        }
    }

    // This will only check if the sequence of brackets provided are correct or not. If
    // there are any other characters present in the input, it will treat it as a 
    // non-matching bracket sequence.
    sequence.empty() ? cout << input << " has valid bracket sequence\n" :
                       cout << input << " has INVALID bracket sequence\n"; 

    return 0;
}