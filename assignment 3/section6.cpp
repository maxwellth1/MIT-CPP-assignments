#include <iostream>
using namespace std;

const string vowels = "aeiou";

string pigLatinify(const string s){
    if(s.size() == 0){return s;}
    if(s.find("qu") == 0){return s.substr(2, s.size() - 2) + "-" + s.substr(0, 2) + "ay";}
    else if(vowels.find(s[0]) != string::npos){return s + "way";}
    else {return s.substr(2, s.size() - 1) + "-" + s[0] + "ay";}
}

int main(){
    string word;
    cin >> word;
    pigLatinify(word);
}