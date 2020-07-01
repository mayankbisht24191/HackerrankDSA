#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the shortestReach function below.

int mindist(int dist[],bool visited[],int n){
    int min=INT_MAX;
    int rn=-1;
    for(int i=1;i<n+1;i++){
        if(!visited[i] && dist[i]<=min){
            rn=i;
        }
    }
    return rn;
}

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    
int g[n+1][n+1]={0};
for(long unsigned int i=0;i<edges.size();i++){
    int u=edges[i][0];
    int v=edges[i][1];
    g[u][v]=edges[i][2];
    g[v][u]=edges[i][2];
}

int dist[n+1];
bool visited[n+1];
for(int i=0;i<n+1;i++)
    dist[i]=INT_MAX,visited[i]=false;

dist[s]=0;
for(int i=1; i<n; i++){
int u=mindist(dist,visited,n);
visited[u]=true;
for(int j=1;j<n+1;j++){
    if(!visited[j]&&!g[u][j]&&g[u][j]!=INT_MAX && g[u][j]+dist[u]<dist[j] ){
        dist[j]=g[u][j]+dist[u];
    }
}
}
//ans.push_back((dist[n]==INT_MAX)?-1:dist[n]);
vector<int> ans;
for(int i=1;i<n+1;i++){
    ans.push_back((dist[i]==INT_MAX)?-1:dist[i]);
}
return ans;
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            for (int j = 0; j < 3; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = shortestReach(n, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
