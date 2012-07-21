#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
 vector<char> sequence;
 int n;
 cin >> n;
 for(int i=1;i<=n;i++)
   {
     int length;
     int h;
     cin >> length >> h;
     sequence.assign(length - h, '0');
     vector<char> helper;
     helper.assign(h, '1');
     sequence.insert(sequence.end(),helper.begin(),helper.end());
     do
       {
         for(int j=0;j<sequence.size();j++)
           {
             if(sequence[j] == '0')
               cout << '0';
             else
               cout << '1';
           }
         cout << endl;
       }
     while(next_permutation(sequence.begin(),sequence.end()));
     if(i!=n)
       cout << endl;
   }
 return(0);
}
