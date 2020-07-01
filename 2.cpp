#include <bits/stdc++.h>

using namespace std;
int main()
{
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int n;
        cin>>n;
        int M[n][n];
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
            cin>>M[j][k];
        }
        }

        vector<int> sum_col(n, 0), sum_row(n, 0);
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            sum_col[i] += M[i][j];
          }
        }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            sum_row[i] += M[j][i];
          }
        }
        sort(sum_col.begin(), sum_col.end());
        sort(sum_row.begin(), sum_row.end());

        if (sum_col == sum_row)
          cout << "Possible" << endl;
        else
          cout << "Impossible" << endl;
    }
    return 0;
}
