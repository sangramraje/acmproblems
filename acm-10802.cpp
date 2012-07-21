#include<iostream>

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
   long long int sum = n*(n-3)/2 +1 ;
   for(int i=2;i<n;i++)
     sum -= n % i;
   cout << "Case " << ctr << ": " << sum << endl;
 }
 return 0;
}
