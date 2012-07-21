#include<iostream>
#include<vector>
using namespace std;

int main(){
  int count = 0;
  while(true){
    count++;
    int n;
    cin >> n;
    if(n == 0)
      break;
    int lengths[n+1];
    lengths[0]=-10;
    for(int i=0;i<n+1;i++)
      lengths[i]=-(n+1);
    int s;
    cin >> s;
    lengths[s]=0;
    vector<int> source;
    vector<int> destination;
    int a,b;
    while(true){
      cin >> a >> b;
      if(a == 0 && b == 0)
        break;
      source.push_back(a);
      destination.push_back(b);
    }
    bool change = false;
    for(int i=0;i<n;i++){
      for(int j=0;j<source.size();j++){
        if(lengths[source[j]] + 1 > lengths[destination[j]]){
          change = true;
          lengths[destination[j]] = lengths[source[j]]+1;
        }
      }
      if(!change)
        break;
    }
    int maximum = 0;
    int index = s;
    for(int i=1;i<n+1;i++){
      if(lengths[i] > maximum){
        maximum = lengths[i];
        index = i;
      }
    }
    cout << "Case " << count << ": The longest path from " << s << " has length " << maximum << ", finishing at " << index << "." << endl << endl;
  }
  return 0;
}
