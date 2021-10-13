#include <bits/stdc++.h>

using namespace std;

class AttributoPasseggero{
    public:
        AttributoPasseggero(bool req,function<bool(string)> fun): required(req),check(fun) {}
        bool required;
        function<bool(string)> check;

};


class Passeggero{

    public:
        const static char SEPARATOR_KEYVALUE=':';
        const static string SEPARATOR;
        const static map<string,AttributoPasseggero> all;

        map<string,string> values;
        void readFromString(string input);
        bool checkFiled() const;
        bool checkValidFiled() const;
        void clear();
};

const map<string, AttributoPasseggero> Passeggero::all = {
    {"byr", AttributoPasseggero(1,
                                [](string input) -> bool
                                {
                                    try
                                    {
                                        int num = stoi(input);
                                        return 1920 <= num and num <= 2002;
                                    }
                                    catch (...)
                                    {
                                        return false;
                                    }
                                })},
    {"iyr", AttributoPasseggero(1,
                                [](string input) -> bool
                                {
                                    try
                                    {
                                        int num = stoi(input);
                                        return 2010 <= num and num <= 2020;
                                    }
                                    catch (...)
                                    {
                                        return false;
                                    }
                                })},
    {"eyr", AttributoPasseggero(1,
                                [](string input) -> bool
                                {
                                    try
                                    {
                                        int num = stoi(input);
                                        return 2020 <= num and num <= 2030;
                                    }
                                    catch (...)
                                    {
                                        return false;
                                    }
                                })},
    {"hgt", AttributoPasseggero(1,
                                [](string input) -> bool
                                {
                                    
                                    vector<tuple<string, int, int>> v = {make_tuple("cm", 150, 193), make_tuple("in", 59, 76)};
                                    try
                                    {
                                        for (auto i : v)
                                        {
                                            size_t pos = input.find_first_of(get<0>(i));
                                            if (pos != string::npos)
                                            {
                                                
                                                int n = stoi(input.substr(0, pos));
                                                if (get<1>(i) <= n and get<2>(i) >= n)
                                                    return true;
                                            }
                                        }
                                    }
                                    catch (...)
                                    {
                                        return false;
                                    }
                                    return false;
                                })},

    {"hcl", AttributoPasseggero(1,
                                [](string input) -> bool
                                {
                                    regex exp("\\#[a-f0-9]{6}");
                                    return regex_match(input, exp);
                                })},
    {"ecl", AttributoPasseggero(1,
                                [](string input) -> bool
                                {
                                    vector<string> s = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
                                    for (auto i : s)
                                        if (i == input)
                                            return true;
                                    return false;
                                })},
    {"pid", AttributoPasseggero(1,
                                [](string input) -> bool
                                {
                                    regex exp("(\\d)+");
                                    return regex_match(input, exp) and input.size()==9;

                                })},
    {"cid", AttributoPasseggero(0,
                                [](string input) -> bool
                                {
                                    return true;
                                })}};

const string Passeggero::SEPARATOR = " \n";

void Passeggero::clear()
{
    values.clear();
}

bool Passeggero::checkValidFiled() const
{
    if (!checkFiled())
        return false;

    bool allValid=true;
    for (map<string, AttributoPasseggero>::const_iterator i = all.begin(); i != all.end(); i++)
    {
        if (values.count(i->first) == 1)
        {
            string stringaDaCercare=values.at(i->first);

            bool valid=i->second.check(stringaDaCercare);
            allValid&=valid;
        }
    }
    return allValid;
}

bool Passeggero::checkFiled() const
{
    for (map<string, AttributoPasseggero>::const_iterator i = all.begin(); i != all.end(); i++)
    {
        if (values.count(i->first) == 0 and i->second.required == 1)
        {
            return false;
        }
    }
    return true;
}

void Passeggero::readFromString(string input)
{
    input += "\n";
    size_t found = input.find_first_of(SEPARATOR);
    int startFrom = 0;
    while (found != string::npos)
    {
        size_t breakPosition = input.find_first_of(SEPARATOR_KEYVALUE, startFrom);
        if (breakPosition < found)
        {
            string key = input.substr(startFrom, breakPosition - startFrom);
            string value = input.substr(breakPosition + 1, found - breakPosition - 1);
            if (all.count(key) > 0)
            {
                values.insert({key, value});
            }
        }
        startFrom = found + 1;
        found = input.find_first_of(SEPARATOR, found + 1);
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
            if (passeggero.checkValidFiled())
                sol++;
            passeggero.clear();
        }
        passeggero.readFromString(s);
    }

    printf("%d\n", sol);
}
