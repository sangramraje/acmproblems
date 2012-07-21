#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
  int input[3][3],i,j,sumall,sum[6],maxoccurs,max,firstentry;
  vector<int> count;
  vector<string> word;
  while(cin >> firstentry)
  {
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
        if(i==0 && j==0)
        {
          input[i][j]=firstentry;
          continue;
        }
        cin >> input[i][j];
      }
    }
    sumall=0;
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
        sumall+=input[i][j];
      }
    }
    sum[1]=input[0][0]+input[1][1]+input[2][2]; //1 2 3
    sum[0]=input[0][0]+input[1][2]+input[2][1]; //1 3 2
    sum[4]=input[0][1]+input[1][0]+input[2][2]; //2 1 3
    sum[5]=input[0][1]+input[1][2]+input[2][0]; //2 3 1
    sum[2]=input[0][2]+input[1][0]+input[2][1]; //3 1 2
    sum[3]=input[0][2]+input[1][1]+input[2][0]; //3 2 1
    max=sum[0];
    maxoccurs=0;
    for(i=0;i<6;i++)
    {
      if(sum[i]>max)
      {
        max=sum[i];
        maxoccurs=i;
      }
    }
    if(maxoccurs==0) { word.push_back("BCG ");count.push_back(sumall-max);}
    if(maxoccurs==1) { word.push_back("BGC ");count.push_back(sumall-max);}
    if(maxoccurs==2) { word.push_back("CBG ");count.push_back(sumall-max);}
    if(maxoccurs==3) { word.push_back("CGB ");count.push_back(sumall-max);}
    if(maxoccurs==4) { word.push_back("GBC ");count.push_back(sumall-max);}
    if(maxoccurs==5) { word.push_back("GCB ");count.push_back(sumall-max);}
  }
  for(i=0;i<count.size();i++)
    cout << word[i] << count[i] << endl;
  return(0);
}
