#include <bits/stdc++.h>

using namespace std;


class Passeggero{

    public:
        const static char SEPARATOR_KEYVALUE=":";
        const static char SEPARATOR=" ";
        const static set<string> all = {
            "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

        map<string,string>;
        void readFromString(string input);
        bool checkFiled() const;
};

bool Passeggero::chechkFiled()
{

}

void Passeggero::readFromString(string input)
{
    size_t found=input.find_first_of(SEPARATOR);
    int  startFrom=0;
    while(found!=string::npos){
        size_t breakPosition=input.find_first_of(SEPARATOR_KEYVALUE,initialPosition);
        if(breakPosition<found){

        }
        find=input.find_first_of(SEPARATOR,found+1);
    }
}

int main()
{
    int sol = 0;
    string s;
    Passeggero passeggero;
    while (getline(cin, s))
    {
        if (s == "")
        {
        }
    }

    printf("%d\n", sol);
}
