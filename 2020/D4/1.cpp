#include <bits/stdc++.h>

using namespace std;


class Passeggero{

    public:
        const static char SEPARATOR_KEYVALUE=':';
        const static string SEPARATOR;
        const static map<string,int> all;

        map<string,string> values;
        void readFromString(string input);
        bool checkFiled() const;
        void clear();
};

const map<string,int> Passeggero::all = {{"byr",1}, {"iyr",1}, {"eyr",1}, {"hgt",1}, {"hcl",1}, {"ecl",1}, {"pid",1},{"cid",0}};
const string Passeggero::SEPARATOR=" \n";

void Passeggero::clear(){
    values.clear();
}
bool Passeggero::checkFiled() const
{
    for(map<string,int>::const_iterator i=all.begin();i!=all.end();i++){
        if(values.count(i->first)==0 and i->second==1){
            return false;
        }
    }
    return true;

}

void Passeggero::readFromString(string input)
{
    input+="\n";
    size_t found=input.find_first_of(SEPARATOR);
    int  startFrom=0;
    while(found!=string::npos){
        size_t breakPosition=input.find_first_of(SEPARATOR_KEYVALUE,startFrom);
        if(breakPosition<found){
            string key=input.substr(startFrom,breakPosition-startFrom);
            string value=input.substr(breakPosition+1,found-breakPosition-1);
            if(all.count(key)>0){
                values.insert({key,value});
            }
        }
        startFrom=found+1;
        found=input.find_first_of(SEPARATOR,found+1);
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
            if(passeggero.checkFiled())sol++;
            passeggero.clear();
        }
        passeggero.readFromString(s);
    }

    printf("%d\n", sol);
}
