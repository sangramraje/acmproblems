#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
  void moveonto(int,int,vector< stack<int> > &,vector<int> &);
  void moveover(int,int,vector< stack<int> > &,vector<int> &);
  void pileonto(int,int,vector< stack<int> > &,vector<int> &);
  void pileover(int,int,vector< stack<int> > &,vector<int> &);
  int numberofblocks;
  cin >> numberofblocks;
  vector< stack<int> > stacks;
  vector<int> position;
  for(int i=0;i<numberofblocks;i++)
  {
    position.push_back(i);
    stack<int> temp;
    temp.push(i);
    stacks.push_back(temp);
  }
  while(true)
  {
    // cin >> flush();
    string general;
    cin >> general;
    // cout << "general: " << general << "::" << endl;
    string input;
    getline(cin,input);
    //cout << "input: " << input << "::" << endl;
    input=general+input;
    //cout << "input now: " << input << "::" << endl;
    istringstream inp(input);
    string instruct1,instruct2;
    int number1,number2;
    inp >> instruct1;
    if(instruct1=="quit")
      break;
    else
    {
      inp >> number1 >> instruct2 >> number2;
      //    cout << "instruct1: " << instruct1 << endl;
      //cout << "instruct2: " << instruct2 << endl;
      //cout << number1 << " " << number2 << endl;
      if(number1==number2 || position[number1]==position[number2])
      {
        continue;
      }
      if(instruct1=="move")
      {
        if(instruct2=="onto")
        {
          moveonto(number1,number2,stacks,position);
        }
        else
        {
          moveover(number1,number2,stacks,position);
        }
      }
      else
      {
        if(instruct2=="onto")
        {
          pileonto(number1,number2,stacks,position);
        }
        else
        {
          pileover(number1,number2,stacks,position);
        }
      }
    }
  }
  stack<int> temp;
  for(int i=0;i<stacks.size();i++)
  {
    cout << i << ":";
    while(!stacks[i].empty())
    {
      temp.push(stacks[i].top());
      stacks[i].pop();
    }
    while(!temp.empty())
    {
      cout << " " << temp.top();
      temp.pop();
    }
    //   cout << " position: " << position[i];
    cout << endl;
  }
  return(0);
}

void redistribute(int number,vector< stack<int> > &stacks,vector<int> &position)
{
  while(stacks[position[number]].top()!=number)
  {
    int temp=stacks[position[number]].top();
    stacks[temp].push(temp);
    stacks[position[number]].pop();
    position[temp]=temp;
  }
}

void moveonto(int num1,int num2,vector< stack<int> > &stacks,vector<int> &position)
{
  //  cout << "In Move Onto" << endl;
  redistribute(num1,stacks,position);
  redistribute(num2,stacks,position);
  stacks[position[num1]].pop();
  position[num1]=position[num2];
  stacks[position[num2]].push(num1);
}

void moveover(int num1,int num2,vector< stack<int> > &stacks,vector<int> &position)
{
  //cout << "In Move Over" << endl;
  //cout << position[num1] << " " << position[num2] << endl;
  redistribute(num1,stacks,position);
  //cout << "resdistribution done" << endl;
  stacks[position[num1]].pop();
  //cout << "popping done" << endl;
  position[num1]=position[num2];
  //cout << "position changed" << endl;
  stacks[position[num2]].push(num1);
  //cout << "Done!" << endl;
}

void pileonto(int num1,int num2,vector< stack<int> > &stacks,vector<int> &position)
{
  //cout << "In Pile Onto" << endl;
  stack<int> temp;
  redistribute(num2,stacks,position);
  while(stacks[position[num1]].top()!=num1)
  {
    temp.push(stacks[position[num1]].top());
    stacks[position[num1]].pop();
  }
  stacks[position[num1]].pop();
  stacks[position[num2]].push(num1);
  position[num1]=position[num2];
  while(!temp.empty())
  {
    stacks[position[num2]].push(temp.top());
    position[temp.top()]=position[num2];
    temp.pop();
  }
}

void pileover(int num1,int num2,vector< stack<int> > &stacks,vector<int> &position)
{
  //cout << "In Pile Over" << endl;

  stack<int> temp;
  while(stacks[position[num1]].top()!=num1)
  {
    temp.push(stacks[position[num1]].top());
    stacks[position[num1]].pop();
  }
  stacks[position[num1]].pop();
  stacks[position[num2]].push(num1);
  position[num1]=position[num2];
  while(!temp.empty())
  {
    stacks[position[num2]].push(temp.top());
    position[temp.top()]=position[num2];
    temp.pop();
  }
}
