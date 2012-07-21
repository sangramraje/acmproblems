#include<iostream>
using namespace std;

int main(){
  int m, n, counter=0;
  while(true){
    counter++;
    cin >> m >> n;
    if(m == 0 && n == 0)
      break;
    int field[m+2][n+2];
    for(int i=0; i<m+2; i++){
      field[i][0] = 0;
      field[i][n+1] = 0;
    }
    for(int i=0; i<n+2; i++){
      field[0][i] = 0;
      field[m+1][i] = 0;
    }
    for(int i=1; i<=m; i++){
      for(int j=1; j<=n; j++){
        char c;
        cin >> c;
        if(c == '.'){
          field[i][j] = 0;
        }
        else if(c == '*'){
          field[i][j] = 100;
        }
        else
          cout << "Problem!" << endl;
      }
    }
    if(counter>1)
      cout << endl;
    cout << "Field #" << counter << ":" << endl;
    for(int i=1; i<=m; i++){
      for(int j=1; j<=n; j++){
        if(field[i][j] == 100){
          if(field[i+1][j] != 100)
            field[i+1][j]++;
          if(field[i-1][j] != 100)
            field[i-1][j]++;
          if(field[i][j-1] != 100)
            field[i][j-1]++;
          if(field[i][j+1] != 100)
            field[i][j+1]++;
          if(field[i-1][j-1] != 100)
            field[i-1][j-1]++;
          if(field[i-1][j+1] != 100)
            field[i-1][j+1]++;
          if(field[i+1][j-1] != 100)
            field[i+1][j-1]++;
          if(field[i+1][j+1] != 100)
            field[i+1][j+1]++;

        }
      }
    }
    for(int i=1; i<=m; i++){
      for(int j=1; j<=n; j++){
        if(field[i][j]==100)
          cout << '*';
        else
          cout << field[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
