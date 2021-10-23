#include <bits/stdc++.h>

using namespace std;

class Bag
{
public:
    Bag(string desc) : descrizione(desc) {}
    vector<int> contenutaDa;
    vector<array<int,2>> contentente;
    string descrizione;
};

map<string, int> nameToPos;
vector<Bag> bags;

int getIndex(string inp)
{
    if (nameToPos.count(inp) == 0)
    {
        bags.emplace_back(inp);
        nameToPos.insert({inp, bags.size() - 1});
    }
    return nameToPos[inp];
}

int dfs(vector<bool> &v,int n){
    if(v[n])return 0;
    v[n]=1;
    int sol=1;
    for(auto c:bags[n].contenutaDa){
        sol+=dfs(v,c);
    }
    return sol;
}

int rdfs(vector<bool> &v, vector<int> &dp, int n)
{
    if (v[n])
        return dp[n];
    
    v[n] = 1;
    int sol=0;
    for (auto c : bags[n].contentente)
        sol += (rdfs(v, dp, c[0])+1)*c[1];
    dp[n]=sol;
    return sol;
}

int main()
{
    //questa mappa stora il nome del della valigia con la posizione nel suo array
    string input;
    try
    {
        while (getline(cin, input))
        {
            //trova i primi due spazi (crea la sottostringa delle prime due parole)
            int lastPos = 0;
            size_t nextSpace = input.find_first_of(" ");
            nextSpace = input.find_first_of(" ", nextSpace + 1);
            string container = input.substr(lastPos, nextSpace);

            //salta le parole bag e arriviamo allo spazio prima di contain
            nextSpace = input.find_first_of(" ", nextSpace + 1);

            int posOfRoot = getIndex(container);

            if (input.substr(nextSpace + 1, input.size() - nextSpace - 1) != "contain no other bags.")
                while (nextSpace != string::npos)
                {
                    //schippa lo spazio del contain se è la prima volta che viene esseguito se no salta lo spazio della bag
                    nextSpace = input.find_first_of(" ", nextSpace + 1);
                    if (nextSpace == string::npos)
                        break;

                    lastPos = nextSpace + 1;
                    nextSpace = input.find_first_of(" ", nextSpace + 1);
                    int valigeContenute = stoi(input.substr(lastPos, nextSpace - lastPos));
                    lastPos = nextSpace + 1;
                    nextSpace = input.find_first_of(" ", nextSpace + 1);
                    nextSpace = input.find_first_of(" ", nextSpace + 1);
                    string contained = input.substr(lastPos, nextSpace - lastPos);

                    int arrayPos = getIndex(contained);
                    bags[arrayPos].contenutaDa.push_back(posOfRoot);
                    bags[posOfRoot].contentente.push_back({arrayPos, valigeContenute});
                }
        }
        vector<bool> visited(bags.size(), 0);
        vector<int> dp(bags.size(), 0);
        int tosearch = getIndex("shiny gold");
        int sol = rdfs(visited,dp,tosearch);
        cout << sol << endl;
    }
    catch (...)
    {
        cerr << "Error while reading the input" << endl;
    }
}