#include<iostream>
#include<string>

using namespace std;

int main()
{
  string s1,s2;
  int counter = 0;
  while(cin >> s1 >> s2){
    counter++;
    if(counter != 1)
      cout << endl;

    int count[102];
    for(int i=0;i<102;i++)
      count[i]=0;
    for(int i=s1.length()-1;i>=0;i--){
      if(s1[i] == '1')
        count[s1.length()-1-i]++;
    }
    for(int i=s2.length()-1;i>=0;i--){
      if(s2[i] == '1')
        count[s2.length()-1-i]++;
    }
    string res,oldres;
    res = "";
    for(int i=102;i>=0;i--){
      if(count[i] == 0)
        if(res != "")
          res = res + '0';
      if(count[i] == 1)
        res += '1';
      if(count[i] == 2)
        res += '2';
      if(count[i] == 3)
        res += '3';
    }
    oldres=res;
    while(true){
      int i=0;
      for(i=0;i<102;i++){
        if(count[i] > 0 && count[i+1] > 0){
          count[i+1]--;
          count[i]--;
          count[i+2]++;
        }
      }
      for(i=0;i<102;i++){
        if(count[i] == 2){
          if(i == 0){
            count[1]++;
            count[0] = 0;
          }
          else if(i == 1){
            count[0] = 1;
            count[1] = 0;
            count[2] = 1;
          }
          else{
            count[i+1]++;
            count[i] = 0;
            count[i-2]++;
            i = i-3;
          }
        }
      }
      res = "";
      for(int i=102;i>=0;i--){
        if(count[i] == 0)
          if(res != "")
            res = res + '0';
        if(count[i] == 1)
          res += '1';
        if(count[i] == 2)
          res += '2';
        if(count[i] == 3)
          res += '3';
      }
      if(oldres == res){
        if(res != "") cout << res << endl;
        else cout << "0" << endl;
        break;
      }
      oldres = res;
    }
  }
}
