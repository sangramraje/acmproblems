#include<iostream>
#include<cmath>
using namespace std;

int main()
{
  int primes[250];
  int number=1;
  primes[0]=1;
  for(int i=1;i<250;i++){
    int j;
    for(j=1;j<number;j++){
      if((4*i+1) % primes[j] == 0)
        break;
    }
    if(j==number){
      primes[number]=4*i+1;
      number++;
    }
  }

  int n = 1000001;
  int mycount = 0;
  int store[25001];
  int index=0;
  for(int i=0;i<=(n-1)/4;i++){
    int sq = sqrt(4*i+1);
    for(int j=1;j<number;j++){
      if(primes[j] > sq)
        break;
      if((4*i+1) % primes[j] == 0){
        int k=(4*i+1) / primes[j];
        sq = sqrt(k);
        bool flag=0;
        for(int m=1;m<number;m++)
        {
          if(primes[m] > sq)
            break;
          if(k % primes[m] == 0){
            flag=1;
            break;
          }
        }
        if(flag == 0){
          mycount++;
          break;
        }
      }
    }
    if(i%10==0){
      store[index]=mycount;
      index++;
      //  cout << 4*i+1 << "   " << index << "   " << store[index-1] << endl;
    }
  }
  //  cout << "Done with memoization !" << endl;
  while(true){
    int n;
    cin >> n;
    if(!n)
      break;
    int startFrom = ((n-1)/4) / 10;
    //    cout << startFrom << "   " << store[startFrom] << endl;
    int mycount = store[startFrom];
    for(int i=startFrom*10+1;i<=(n-1)/4;i++){
      int sq = sqrt(4*i+1);
      for(int j=1;j<number;j++){
        if(primes[j] > sq)
          break;
        if((4*i+1) % primes[j] == 0){
          int k=(4*i+1) / primes[j];
          sq = sqrt(k);
          bool flag=0;
          for(int m=1;m<number;m++)
          {
            if(primes[m] > sq)
              break;
            if(k % primes[m] == 0){
              flag=1;
              break;
            }
          }
          if(flag == 0){
            mycount++;
            break;
          }
        }
      }
    }
    cout << n << " " << mycount << endl;
  }
  return 0;
}
