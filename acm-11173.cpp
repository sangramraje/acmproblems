#include<iostream>
using namespace std;

int main(){
  int powers[31];
  powers[0]=1;
  for(int i=1;i<=30;i++){
    powers[i]=powers[i-1]*2;
  }
  int upperIndex, lowerIndex;
  int numberOfCases;
  cin >> numberOfCases;
  for(int z=0;z<numberOfCases;z++){
    int n;
    cin >> n;
    int counter = n;
    int k;
    cin >> k;
    int ans = 0;
    lowerIndex = powers[0]-1;
    upperIndex = powers[n]-1;
    bool normal=true;
    while(lowerIndex!=upperIndex){
      if(normal){
        if(k<=(lowerIndex+upperIndex)/2){
          upperIndex=(lowerIndex+upperIndex)/2;
        }
        else{
          normal=false;
          lowerIndex=(lowerIndex+upperIndex)/2+1;
          ans+=powers[counter-1];
        }
      }
      else{
        if(k<=(lowerIndex+upperIndex)/2){
          upperIndex=(lowerIndex+upperIndex)/2;
          normal=true;
          ans+=powers[counter-1];
        }
        else{
          lowerIndex=(lowerIndex+upperIndex)/2+1;
        }
      }
      counter--;
    }
    cout << ans << endl;
  }
  return 0;
}
