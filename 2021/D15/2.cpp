#include <bits/stdc++.h>

using namespace std;

#define MN 502

int g[MN][MN];
int dist[MN][MN];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
struct Point{
    int x, y, d;
    bool operator<(const Item &other) const{
        return d > other.d;
    }
};

int main(){
    int n;
    {
        int i=1;
        string s;
        while(getline(cin,s)){
            n=s.size();
            for (int j = 1; j <= n; ++j){
                g[i][j] = s[j-1] - '0';
            }
            i++;
        }
    }
    for (int i = 1; i <= 5 * n; ++i){
        for (int j = 1; j <= 5 * n; ++j){
            g[i][j] = ((i - 1) / n) + ((j - 1) / n) + g[(i - 1) % n + 1][(j - 1) % n + 1];
            g[i][j] = (g[i][j] - 1) % 9 + 1;
            dist[i][j] = 1000000;
        }
    }
    n *= 5;
    priority_queue<Point> pq;
    dist[1][1] = g[1][1];
    pq.push({1, 1, dist[1][1]});
    while (!pq.empty()){
        auto k = pq.top();
        int x=k.x,y=k.y,d=k.d;
        pq.pop();
        for (int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<1 or ny<1)continue;
            if (d + g[nx][ny] < dist[nx][ny]){
                dist[nx][ny] = d + g[nx][ny];
                pq.push({nx, ny, dist[nx][ny]});
            }
        }
    }
    cout << dist[n][n] - g[1][1] << '\n';
}
