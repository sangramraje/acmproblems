#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
  int n;
  string n1;
  getline(cin, n1);
  n=atoi(n1.c_str());
  for(int z=0;z<n;z++){
    string s;
    getline(cin,s);
    int i=0;
    int j;
    vector<int> temp;
    while((j=s.find("*",i))!=string::npos){
      stringstream t(s.substr(i,j-i));
      int x;
      int p=0;
      while(t>>x){
        p+=x;
        char c;
        t >> c;
      }
      temp.push_back(p);
      i=j+1;
    }
    stringstream t(s.substr(i));
    int x;
    int p=0;
    while(t>>x){
      p+=x;
      char c;
      t>>c;
    }
    temp.push_back(p);
    long long int answer = 1;
    for(int k=0;k<temp.size();k++)
      answer *= temp[k];
    long long int maximum = answer;

    i=0;
    vector<long long int> temp1;
    while((j=s.find("+",i))!=string::npos){
      stringstream t(s.substr(i,j-i));
      int x;
      long long int p=1;
      while(t>>x){
        p*=x;
        char c;
        t>>c;

      }
      temp1.push_back(p);
      i=j+1;
    }
    stringstream t1(s.substr(i));
    long long int p1=1;
    int x1;
    while(t1>>x1){
      p1*=x1;
      char c;
      t1 >> c;
    }
    temp1.push_back(p1);
    answer = 0;
    for(int k=0;k<temp1.size();k++){
      answer += temp1[k];
    }
    cout << "The maximum and minimum are " << maximum << " and " << answer << "." << endl;
  }
  return 0;
}
