#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define fep(i,j,n) for(int i=j;i<n;i++)
typedef array<int,2> ii;
#define MOD 1000000007
int LSB(int x){return x&-x;}

#define MN 12
#define ML 3


struct FieldVerification{
    string name;
    array<int,4> range;
    FieldVerification(string s,int i1,int i2,int i3,int i4){
        name=s;
        range[0]=i1;
        range[1]=i2;
        range[2]=i3;
        range[3]=i4;
    }
    bool verify(int val){
        return (range[0]<=val and val<=range[1]) or (range[2]<=val and val<=range[3]);
    }
};

struct Ticket{
    vector<int> field;

    Ticket(vector<int> v):field{v}{}

    int sumIncorretFiled(vector<FieldVerification> ver){
        int sum=0;
        for(auto fil:field ){
            bool extrue=false;
            for(auto c:ver){
                extrue|=c.verify(fil);
            }
            if(!extrue){
                sum+=fil;
            }
        }
        return sum;
    }

};
void readInput(vector<FieldVerification> &filed,vector<Ticket> &tikets){
    std::regex rule_pattern(R"((.+): (\d+)-(\d+) or (\d+)-(\d+))");
    std::regex ticket_patterh(R"((\d+),?)");
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "") {
            break;
        }
        std::smatch rule_match;
        std::regex_search(line, rule_match, rule_pattern);
        filed.emplace_back(
            rule_match[1],
            std::stoi(rule_match[2]),
            std::stoi(rule_match[3]),
            std::stoi(rule_match[4]),
            std::stoi(rule_match[5])
        );
    }
    while (std::getline(std::cin, line)) {
        if(line=="ff")break;
        vector<int> fields;
        auto start = std::sregex_iterator(line.begin(), line.end(), ticket_patterh);
        auto end = std::sregex_iterator();
        for (std::sregex_iterator i = start; i != end; ++i) {
            std::smatch match = *i;
            fields.push_back(stoi(match.str()));
        }
        
        if (fields.size() > 0) {
            tikets.emplace_back(fields);
        }
    }
}

int main(){
    vector<FieldVerification> filed;
    vector<Ticket> tikets;
    readInput(filed,tikets);
    int sum=0;
    fep(i,1,tikets.size()){
        sum+=tikets[i].sumIncorretFiled(filed);
    }
    cout <<sum<<endl;
}
