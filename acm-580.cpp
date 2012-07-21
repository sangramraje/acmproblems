#include<iostream>
using namespace std;

int main()
{
  int answers[30];
  answers[0]=2;
  answers[1]=4;
  answers[2]=7;
  for(int i=3;i<30;i++){
    answers[i]=answers[i-1]+answers[i-2]+answers[i-3];
  }
  int powers[30];
  powers[0]=2;
  for(int j=1;j<30;j++){
    powers[j]=2*powers[j-1];
  }
  while(true){
    int n;
    cin >> n;
    if(n==0){
      break;
    }
    cout << powers[n-1]-answers[n-1] << endl;
  }
  return 0;
}
