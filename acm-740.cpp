#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int eval(char code[])
{
  return (16*((int) code[0]-(int) '0') +
      8*((int) code[1]-(int) '0') +
      4*((int) code[2]-(int) '0') +
      2*((int) code[3]-(int) '0') +
      ((int) code[4]-(int) '0'));
}

int main()
{
  int lower[32], upper[32];
  string s;
  getline(cin, s);
  for(int i=0; i<32; i++)
  {
    lower[i] = s[i];
  }
  s = "";
  getline(cin, s);
  for(int i=0; i<32; i++)
  {
    upper[i]=s[i];
  }
  s = "";
  while(getline(cin, s))
  {
    bool upperCase = false;
    stringstream input(s);
    char code[5];
    while(input >> code[0] >> code[1] >> code[2] >> code[3] >> code[4])
    {
      int ans = eval(code);
      if(ans == 27)
      {
        upperCase = false;
        continue;
      }
      if(ans == 31)
      {
        upperCase = true;
        continue;
      }
      if(upperCase)
        cout << (char) upper[ans];
      else
        cout << (char) lower[ans];
    }
    cout << endl;
  }
  return 0;
}
