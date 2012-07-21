#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a,int b){
  /*if(b%a==0){
    return a;
    }
    else{
    return gcd(b%a, a);
    }*/
  int c;
  while((c = b%a) != 0){
    b = a;
    a = c;
  }
  return a;

}

int main(){
  int n;
  int counter;
  while(cin >> n){
    counter=0;
    int possibilities[n+1];
    for(int i=0;i<n+1;i++){
      possibilities[i]=-1;
    }
    for(int i=1;i<=sqrt(n);i++){
      for(int j=i+1;j<=sqrt(n);j++){
        int c = i*i+j*j;
        if(c <= n){
          int a = j*j-i*i;
          int b = 2*i*j;
          if(gcd(a, b) == 1){
            counter++;
            int multiplier=1;
            while(multiplier*c <=n){
              //              cout << multiplier << "   " << c << "    " << c*multiplier << "    " << n << endl;
              possibilities[c*multiplier] = 1;
              possibilities[a*multiplier] = 1;
              possibilities[b*multiplier] = 1;
              multiplier++;
            }
          }
        }
        else
          break;
      }
    }
    int counter2=0;
    for(int i=1;i<=n;i++){
      if(possibilities[i] != 1){
        counter2++;
      }
    }
    cout << counter << " " << counter2 << endl;
  }
  return 0;
}
