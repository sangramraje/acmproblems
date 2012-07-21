#include<iostream>
#include<vector>
using namespace std;

#ifdef DEBUG
void pprint(vector<char> result)
{
  cout << "The number is: " << endl;
  for(int k=result.size()-1;k>=0;k--)
    cout << result[k];
  cout << endl;
}
#endif

vector<char> multiply(vector<char> n, int i)
{
  vector<char> result;
  int carry=0;
  for(int j=0;j<n.size();j++)
  {
    int product = ((int) (n[j]-'0'))*i+carry;
    result.push_back(((char) (product%10)) + '0');
    carry = product/10;
  }
  while(carry!=0)
  {
    result.push_back(((char) (carry%10)) + '0');
    carry/=10;
  }
  return(result);
}

int main()
{
  int n;
  while(true)
  {
    cin >> n;
    if(n==0)
      break;
    vector<char> number1;
    number1.push_back(1+'0');
    for(int i=2;i<=n;i++)
    {
      number1 = multiply(number1, i);
    }
    vector<int> count(10,0);
#ifdef DEBUG
    pprint(number1);
#endif
    for(int i=0;i<number1.size();i++)
    {
      count[(int) (number1[i]-'0')]++;
    }
    cout << n << "! --" << endl;
    for(int i=0;i<count.size();i++)
    {
#ifdef DEBUG
      cout << "\t(" << i << ")\t" << count[i];
#else
      cout << "   (" << i << ")   " << count[i];
#endif

      if(i==4 || i==9)
        cout << endl;
    }
  }
  return(0);
}
