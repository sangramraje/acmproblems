#include<iostream>
#include<string>
#include<cassert>
using namespace std;

bool healthy(string s){
  if(s == "A"){
    return true;
  }
  if(s[s.length()-1] == 'B' && s[s.length()-2] == 'A'){
    return healthy(s.substr(0, s.length()-2));
  }
  if(s[0] == 'B' && s[s.length()-1] == 'A'){
    return healthy(s.substr(1, s.length()-2));
  }
  return false;
}

int main(){
  string s;
  int n;
  cin >> n;
  for(int z=0; z<n; z++){
    cin >> s;
    if(healthy(s)){
      if(s == "A"){
        cout << "SIMPLE" << endl;
      }
      else if(s[s.length()-1] == 'B' && s[s.length ()-2] == 'A'){
        cout << "FULLY-GROWN" << endl;
      }
      else if(s[0] == 'B' && s[s.length()-1] == 'A'){
        cout << "MUTAGENIC" << endl;
      }
      else assert(false);
    }
    else {
      cout << "MUTANT" << endl;
    }
  }
  return 0;
}
