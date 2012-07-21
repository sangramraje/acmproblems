#include<iostream>
#include<vector>
using namespace std;

int main(){
  int numbers[1001];
  for(int i=0;i<1001;i++)
    numbers[i]=0;
  for(int i=2;i<32;i++){
    int multiplier = 2;
    while(multiplier*i <= 1000){
      numbers[multiplier*i] = -1;
      multiplier++;
    }
  }
  vector<int> primes;
  for(int i=1;i<1001;i++){
    if(numbers[i]==0)
      primes.push_back(i);
  }
  int n;
  while(cin >> n){
    int m;
    cin >> m;
    cout << n << " " << m << ":";
    int counter = 0;
    for(int i=0;i<primes.size();i++){
      if(n >= primes[i]){
        counter++;
        //      cout << primes[i] << endl;
      }
    }
    //    cout << "Counter = " << counter << endl;
    if(counter <= 2*m){
      for(int i=0;i<counter;i++)
        cout << " " << primes[i];
    }
    else{
      if(counter%2==0){
        //cout << " in if" << endl;
        for(int i=(counter-2*m)/2;i<(counter-2*m)/2+2*m;i++)
          cout << " " << primes[i];
      }
      else{
        //cout << "in else" << endl;
        for(int i=(counter-2*m+1)/2;i<(counter-2*m+1)/2+2*m-1;i++)
          cout << " " << primes[i];
      }
    }
    cout << endl << endl;
  }
  return 0;
}
