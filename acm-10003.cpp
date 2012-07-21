#include<iostream>
#include<vector>

using namespace std;

int main()
{
  int l;
  cin >> l;
  while(l != 0){
    int n;
    cin >> n;
    int sticks[n+2];
    int len;
    sticks[0] = 0;
    for(int i=0;i<n;i++){
      cin >> len;
      sticks[i+1] = len;
    }
    sticks[n+1] = l;
    int mincost[n+2][n+2];
    for(int i=0;i<n+2;i++)
      mincost[i][i+1] = 0;
    for(int i=n;i>=0;i--){
      for(int j=i+1;j<n+2;j++){
        if(i==(j-1))
          mincost[i][j] = 0;
        else{
          int mintemp=mincost[i][i+1] + mincost[i+1][j] + (sticks[j] - sticks[i]);
          for(int k=i+1;k<j;k++){
            int tempcost=mincost[i][k] + mincost[k][j] + sticks[j] - sticks[i];
            if(mintemp > tempcost)
              mintemp = tempcost;
          }
          mincost[i][j] = mintemp;

        }
      }
    }
    cout << "The minimum cutting is " << mincost[0][n+1] << "." << endl;

    cin >> l;

  }

  return 0;

}
