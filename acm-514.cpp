#include<iostream>
#include<stack>
using namespace std;

int main()
{
  int length;
  cin >> length;
  while(length != 0)
  {
    while(true)
    {
      int input[length];
      cin >> input[0];
      int current = 1;
      stack<int> store;
      if(input[0] != 0)
      {
        for(int i=1;i<length;i++)
          cin >> input[i];
        bool flag = true;
        for(int i=0;i<length;i++)
        {
          if(input[i] == current)
            current++;
          else if(input[i] < current)
          {
            if(store.empty() || input[i] != store.top())
            {
              flag = false;
              break;
            }
            else
            {
              store.pop();
            }
          }
          else if(input[i] > current)
          {
            while(input[i] > current)
            {
              store.push(current);
              current++;
            }
            current++;
          }
        }
        if(!flag)
          cout << "No" << endl;
        else
          cout << "Yes" << endl;
      }
      else
      {
        cin >> length;
        cout << endl;
        break;
      }
    }
  }
  return 0;
}
