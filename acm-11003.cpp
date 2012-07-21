#include<iostream>

using namespace std;

int max(int i,int j)
{
  if(i>j)
    return i;
  else return j;
}

int min(int i,int j)
{
  if(i>j)
    return j;
  else return i;
}


int main()
{
  int n;
  cin >> n;
  while(n != 0){
    int load[n];
    int weight[n];
    for(int i=0;i<n;i++){
      int l,w;
      cin >> w >> l;
      weight[i] = w;
      load[i] = l;
    }
    int maxnum[3001];
    int maxend=0;
    for(int i=0;i<3001;i++)
      maxnum[i]=0;
    for(int j=n-1;j>=0;j--){
      if(maxend < 1 + maxnum[load[j]])
        maxend = 1 + maxnum[load[j]];
      for(int i=3000;i>=0;i--){
        if(i >= weight[j]){
          int temp = (1 + maxnum[min(i-weight[j],load[j])]);
          if(maxnum[i] < temp){
            //      cout << j << " " << i << " Checking for " << min(i-weight[j],load[j]) << " " << temp << endl;
            maxnum[i] = temp;
          }
        }
      }
    }
    cout << maxend << endl;
    cin >> n;
  }
  return 0;
}

