#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
  int n;
  while(cin >> n){
    int temp = (int) (sqrt((double)2*n+0.25)-0.5);
    int noofpoints = (temp+3)*(temp)/2 - n;
    n = temp - noofpoints;
    if(noofpoints <= 0)
      while(true){
      }
    int x[noofpoints];
    int y[noofpoints];
    for(int i=0;i<noofpoints;i++){
      temp = (int) (sqrt((double)2*n+0.25)-0.5);
      int p = (temp+3)*(temp)/2 - n;
      n = temp - p;
      temp = (int) (sqrt((double)2*p+0.25)-0.5);
      int x1 = (temp+3)*(temp)/2 - p;
      x[i] = x1;
      y[i] = temp - x1;
    }
    double area = 0;
    if(noofpoints > 0){
      for(int i=0;i<noofpoints-1;i++){
        area += x[i]*y[i+1] - x[i+1]*y[i];
      }
      area += x[noofpoints-1]*y[0] - x[0]*y[noofpoints-1];
    }
    cout.setf(ios::fixed);
    cout << setprecision(1) << 0.5*(double)abs(area) << endl;
  }
  return 0;

}

