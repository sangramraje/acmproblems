#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int input1,input2,output,i,n,j,max,currentno;
  vector<int> alloutputs,stepstaken,inputs;
  while(cin >> input1)
  {
    cin >> input2;
    inputs.push_back(input1);
    inputs.push_back(input2);

    if(input2<input1)
    {
      input1+=input2;
      input2=input1-input2;
      input1=input1-input2;
    }
    for(i=input1;i<=input2;i++)
    {
      currentno=i;
      for(j=1;;j++)
      {
        if(currentno==1)
        {
          stepstaken.push_back(j);
          break;
        }
        if(currentno%2==1) currentno=3*currentno+1;
        else currentno=currentno/2;
      }
    }
    max=stepstaken[0];
    for(i=0;i<stepstaken.size();i++)
    {
      if(stepstaken[i]>max) max=stepstaken[i];
    }
    alloutputs.push_back(max);
    stepstaken.clear();
  }
  for(i=0;i<alloutputs.size();i++)
  {
    cout << inputs[2*i] << " " << inputs[2*i+1] << " " << alloutputs[i] << endl;
  }
  return(0);
}

