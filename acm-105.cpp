#include<iostream>
using namespace std;


int main()
{
  int left, height, right;
  int skyLine[10000];
  for(int i=0;i<10000;i++)
    skyLine[i]=0;
  int endEntry = 0;
  int startEntry = 10000;
  while(cin >> left >> height >> right)
  {
    for(int i=left;i<right;i++)
    {
      if(height > skyLine[i])
      {
        skyLine[i] = height;
      }
    }
    if(right>endEntry)
      endEntry = right;
    if(left<startEntry)
      startEntry = left;
  }
  int currHeight = 0;
  for(int i=startEntry;i<=endEntry;i++)
  {
    if(skyLine[i] != currHeight)
    {
      cout << i << " " << skyLine[i] << " ";
      currHeight = skyLine[i];
      continue;
    }
  }
  cout << endl;
  return(0);
}
