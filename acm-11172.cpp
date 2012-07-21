#include<iostream>
using namespace std;

int main(){
  int t;
  cin >> t;
  for(int z=0;z<t;z++){
    long long int t1;
    long long int t2;
    cin >> t1 >> t2;
    if(t1<t2)
      cout << "<" << endl;
    else if (t1>t2)
      cout << ">" << endl;
    else
      cout << "=" << endl;
  }
  return 0;
}
