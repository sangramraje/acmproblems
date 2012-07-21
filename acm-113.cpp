#include<iostream>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

int main()
{
  int n;
  string p;
  while(cin >> n >> p){
    if(p.length() > 9){
      unsigned int a = atoi(p.substr(0,9).c_str());
      long double loga = log10((long double)a) + p.length() - 9;
      loga /= n;
      int out = (int)pow(10,loga);
      if(atoi(p.substr(p.length()-1).c_str()) % 2 == 0){
        if(out % 2 != 0)
          out++;
      }
      else
        if(out % 2 == 0)
          out ++;
      cout << out << endl;
    }
    else{
      int a = atoi(p.substr(0,9).c_str());

      long double loga = log10((long double)a);
      loga /= n;
      int out = (int)pow(10,loga);
      if(atoi(p.substr(p.length()-1).c_str()) % 2 == 0){
        if(out % 2 != 0)
          out++;
      }
      else
        if(out % 2 == 0)
          out ++;
      cout << out << endl;
    }
  }
  return 0;
}
