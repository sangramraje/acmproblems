#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
  int n;
  string s;
  while(cin >> n >> s){
    map<string,int> strings;
    int length = s.length();
    for(int i=0;i<=length-n;i++){
      string s1 = s.substr(i,n);
      //  cout << "checking for string ##" << s1 << "##" << endl;
      map<string,int>::iterator it = strings.find(s1);
      if(it == strings.end()){
        strings[s1]=1;
      }
      else{
        strings[s1]++;
      }
    }
    map<string,int>::iterator max = strings.begin();
    map<string,int>::iterator moving = strings.begin();
    for(;moving!=strings.end();moving++){
      if(moving->second > max->second){
        max=moving;
      }
    }
    cout << max->first << endl;
  }
  return 0;
}
