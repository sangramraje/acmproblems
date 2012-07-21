#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

vector<int> edges[16];
bool selected[16];
int parents[16];
int visits = 0;
int n;

void output(int m)
{
  int j=parents[m]-1;
  int path[n];
  path[0]=m+1;
  int index=1;
  while(j!=-2){
    path[index] = j+1;
    index++;
    j=parents[j]-1;
  }
  // cout << path[index-1];
  printf("%d", path[index-1]);
  for(int i=index-2;i>=0;i--){
    //cout << " " << path[i];
    printf(" %d", path[i]);
  }
  //cout << endl;
  printf("\n");
}

void dfs(int k)
{
  for(int i=0;i<edges[k].size();i++){
    if(edges[k][i] == 1){
      if(visits!=n)
        continue;
      output(k);
    }
    if(visits < n && edges[k][i] <= n && !(selected[edges[k][i]-1])){
      selected[edges[k][i]-1]=true;
      visits++;
      parents[edges[k][i]-1]=k+1;
      dfs(edges[k][i]-1);
      selected[edges[k][i]-1]=false;
    }
  }
  selected[k]=false;
  parents[k]=-1;
  visits--;
}

int main()
{
  int primes[]={
    3,5,7,11,13,17,19,23,29,31
  };
  for(int i=0;i<16;i++){
    selected[i]=false;
    parents[i]=-1;
    for(int j=1;j<=16;j++){
      if(i==j-1)
        continue;
      for(int k=0;k<10;k++){
        if(i+j+1 == primes[k])
          edges[i].push_back(j);
      }
    }
  }
  int casenumber=1;
  while(cin >> n){
    visits++;
    selected[0]=true;
    parents[0]=-1;
    //    cout << "Case " << casenumber << ":" << endl;
    printf("Case %d:\n", casenumber);
    dfs(0);
    casenumber++;
    //cout << endl;
    printf("\n");
  }
  return 0;
}
