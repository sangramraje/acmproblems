#include<iostream>
#include<cmath>

using namespace std;

int main()
{
  int ctr = 0;
  while(true){
    long long int n;
    cin >> n;
    if(n == 0)
      break;
    ctr++;
    //     long long int sum = n*(n-3)/2 +1 ;
    //     for(int i=2;i<n;i++)
    //       sum -= n % i;
    long long int nroot = (long long int)ceil(sqrt(n));
    long long int sum = n*(nroot - 1) - nroot*(nroot+1)/2 + 1;
    //    cout << sum << endl;
    for(int i=2;i<=nroot;i++){
      sum -= n % i;
      //      cout << sum << endl;
    }
    //    cout << " that was part 1" << endl;
    long long int l = (n/nroot);
    for(long long int i=nroot+1;i<floor(n/l);i++){
      sum += (long long int)n - (n % i) - i;
      //      cout << sum << endl;
    }
    //    cout << " that was part 2" << endl;
    for(long long int i=l;i > 2;i--){
      long long int m1 = floor((double)n/i);
      long int m2 = floor((double)n/(i-1));
      sum += ((long long int)(i-2))*((m2-m1)*(m1+m2+1)/2);
      //      cout << m1 << " " << m2 << " " << sum << endl;

    }
    cout << "Case " << ctr << ": " << sum << endl;
  }
  return 0;
}

