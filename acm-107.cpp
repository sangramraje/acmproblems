#include<iostream>
#include<cmath>
using namespace std;

int main(){
  long long int a,b;
  while(true){
    cin >> a >> b;
    if((a == 0) && (b == 0))
      break;
    if(a == 1 && b == 1){
      cout << 0 << " " << 1 << endl;
      continue;
    }
    if(b == 0){
      cout << 1 << " " << a << endl;
      continue;
    }
    if(b == 1){
      cout << (int) ((log10(a) / log10(2)) + 0.5) << " " << 2*a-b << endl;
      continue;
    }
    int i=2;
    while(true){
      if(! (a % (i+1) == 0 && b % i == 0 /*&&
                                           (((int) (log10(a) / log10(i+1) + 0.5)) == ((int) (log10(b) / log10(i) + 0.5)))*/
           )){
        i++;
        continue;
      }
      int power = pow((double)i, 1.0);
      int flag = false;
      for(int j=1;power<=b;j++){
        if(power == b && pow((double)(i+1),(double) j) == a)
        {
          cout << ((b-1) / (i-1)) << " " << (i+1)*(a-b) + b << endl;
          flag=true;
          break;
        }
        power = pow((double)i,(double)(j+1));
      }
      if(flag){
        break;
      }
      i++;
    }
  }
  return 0;
}
