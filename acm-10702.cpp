#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
  while(true){
    int c,s,e,t;
    cin >> c >> s >> e >> t;
    if(!(c || s || e || t))
      break;
    int edges[c+1][c+1];
    for(int i=1;i<c+1;i++){
      for(int j=1;j<c+1;j++){
        cin >> edges[i][j];
      }
    }
    int finish[e];
    for(int i=0;i<e;i++){
      cin >> finish[i];
    }
    int *lengths=new int[c+1];
    int *lengths_temp=new int[c+1];
    for(int i=1;i<c+1;i++){
      lengths[i]=-2147483645;
      lengths_temp[i]=-2147483645;
    }
    lengths[s]=0;
    for(int i=t-1;i>=0;i--){
      for(int j=c;j>0;j--){
        for(int k=c;k>0;k--){
          if(k==j)
            continue;
          int temp = edges[j][k]+lengths[j];
          if(lengths_temp[k] < temp && lengths[j]>=0){

#ifdef DEBUG
            cout << "Iteration " << t-i << ": " << j << " to  " << k << "  as " << temp << endl;
#endif
            lengths_temp[k]=temp;
          }
        }
      }
      int *swap = lengths;
      lengths=lengths_temp;
      lengths_temp=swap;
    }
    int max=0;
    for(int i=e-1;i>=0;i--){
      if(lengths[finish[i]] > max)
        max = lengths[finish[i]];
    }
    cout << max << endl;
  }
  return 0;
}
