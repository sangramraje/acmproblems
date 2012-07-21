#include<iostream>
using namespace std;

int main(){
  bool remember[3001];
  int n;
  while(cin >> n){
    int count = n-1;
    for(int i=1; i<n; i++){
      remember[i] = false;
    }
    bool flag = true;
    int previous;
    cin >> previous;
    for(int i=1; i<n; i++){
      int diff;
      int current;
      cin >> current;
      if(!flag)
        continue;
      diff = current - previous;
      if(diff < 0)
        diff*=-1;
      if(diff >= n || diff == 0 || remember[diff]){
        flag = false;
        continue;
      }
      count--;
      remember[diff] = true;
      previous = current;

    }
    if(flag)
      cout << "Jolly" << endl;
    else
      cout << "Not jolly" << endl;
  }
  return 0;
}
