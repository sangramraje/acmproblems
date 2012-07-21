#include <iostream>
#include <string>
using namespace std;

int getIndex(string s){
  int i;
  for(i=1;i<s.length()-1;i++){
    if('p' <= s[i] && s[i] <= 'z' && (s[i+1] == 'N' || s[i+1] == 'C' || s[i+1] == 'D' || s[i+1] == 'E' || s[i+1] == 'I')){
      return i;
    }
  }
  return i-1;
}

bool isSentence(string s){
  if(s.length() == 1){
    if('p' <= s[0] && s[0] <= 'z'){
      return 1;
    }
    else {
      return 0;
    }
  }
  if(s[0] == 'N'){
    return isSentence(s.substr(1));
  }
  if(s[0] == 'C' || s[0] == 'D' || s[0] == 'E' || s[0] == 'I'){
    if(s.length() > 2){
      return (isSentence(s.substr(1,getIndex(s))) && isSentence(s.substr(1+getIndex(s))));
    }
  }
  return 0;
}

int main(){
  string s;
  while(cin >> s){
    if(isSentence(s)) {

      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
