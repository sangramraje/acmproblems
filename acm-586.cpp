#include<iostream>
#include<string>

using namespace std;

int main()
{
  int k;
  cin >> k;
  int time[11];
  int multiplierstack[10];
  int pos;
  for(int i=0;i<k;i++){
    pos = 0;
    string cmd;
    for(int j=0;j<11;j++)
      time[j] = 0;
    int multiplier=1;
    int addpower=0;
    while(cin >> cmd){
      if(cmd == "BEGIN")
        continue;
      else if(cmd == "LOOP"){
        string count;
        cin >> count;
        if(count == "n"){
          addpower++;
          multiplierstack[pos++] = -1;
        }
        else{
          multiplierstack[pos++] = multiplier;
          multiplier *= atoi(count.c_str());
        }
      }
      else if(cmd == "END"){
        if(pos == 0)
          break;
        int count = multiplierstack[--pos];
        if(count == -1){
          addpower--;
        }
        else{
          multiplier = count;
        }
      }
      else if(cmd == "OP"){
        int n;
        cin >> n;
        time[addpower] += multiplier*n;
      }
    }
    cout << "Program #" << (i+1) << endl;
    cout << "Runtime = ";
    string res;
    bool first = true;
    for(int i=10;i>=0;i--){
      if(i == 0){
        //      res += (string)(itoa(time[0]));
        if(!first){
          if(time[0] != 0)

            cout << "+" << time[0];
        }
        if(first){
          cout << time[0];
        }
      }
      else{
        if(time[i] != 0){
          if(!first){
            if(time[i] != 1){
              if(i == 1)
                cout << "+" << time[i] << "*n";
              else
                cout << "+" <<  time[i] << "*n^" << i;
            }
            else{
              if(i != 1)
                cout << "+n^" << i;
              else
                cout << "+n";
            }
          }
          else{
            if(time[i] != 1){
              if(i == 1)
                cout << time[i] << "*n";
              else
                cout <<  time[i] << "*n^" << i;
            }
            else{
              if(i != 1)
                cout << "n^" << i;
              else
                cout << "n";
            }
            first = false;
          }
        }
      }
    }
    cout << endl << endl;
  }
  return 0;
}
