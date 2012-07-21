#include<iostream>
#include<cmath>
#include<string>

using namespace std;

inline void multiply(string &number, string &output, int m)
{
  output="";
  int carry=0;
  for(int i=(int)number.length()-1;i>=0;i--){
    int k = (int) (number[i] - '0');
    int t = k*m+carry;
    output =  (char)((t % 10) + (int)'0') + output;
    carry = t / 10;
  }
  if(carry != 0)
    output = (char)(carry+(int)'0')+output;
  if(m == 0)
    output = "0";
}

inline void add(string &number, string &output, int m)
{
  output="";
  int k = (int) (number[(int)number.length()-1] - (int)'0');
  int carry=0;
  if(k+m < 10){
    output=(char)(k+m+(int)'0');
  }
  else{
    carry=1;
    output=(char)(k+m-10+(int)'0');
  }
  for(int i=(int)number.length()-2;i>=0;i--){
    int k = (int) (number[i] - (int)'0');
    if(k+carry < 10){
      output=(char)(k+carry+(int)'0')+output;
      carry=0;
    }
    else{
      output=(char)(k+carry-10+(int)'0')+output;
      carry=1;
    }
  }
}

inline void min(string& n1, string& n2, string& output)
{
  output="";
  while(n1.length() < n2.length())
    n1 = "0"+n1;
  while(n2.length() < n1.length())
    n2 = "0"+n2;
  for(int i=(int)n1.length()-1;i>=0;i--){
    int m = (int)(n1[i] - '0');
    int n = (int)(n2[i] - '0');
    int k;
    if(m >= n)
      k = m-n;
    else{
      int temp=i-1;
      while(n1[temp] == '0'){
        n1[temp] = '9';
        temp--;
      }
      n1[temp] = (char)((int)n1[temp]-1);
      k=10+m-n;
    }
    output = (char)(k + (int)'0') + output;
  }
  int pos = output.find_first_not_of('0');
  if(pos != string::npos)
    output = output.substr(pos);
}

inline bool lessequal(string &n1, string &n2)
{
  if(n1.length() < n2.length())
    return true;
  if(n1.length() > n2.length())
    return false;
  return n1<n2;
}

int main()
{
  while(true){
done:
    int n;
    cin >> n;
    if(!n)
      break;
    int t = sqrt(n);
    int k = t;
    int remainder = n - t*t;
    string rem = "";
    while(remainder>0){
      rem=(char)(remainder%10 + '0')+rem;
      remainder/=10;
    }
    if(rem == "")
      rem = "0";
    string number = "";
    t*=2;
    while(t>0){
      number=(char)(t%10 + '0')+number;
      t/=10;
    }
    string ktostr;
    int temp2 = k;
    while(temp2>0){
      ktostr=(char)(temp2%10 + '0')+ktostr;
      temp2/=10;
    }

    string sqrtn;

    int pos=0;
    int len = ktostr.length();
    for(int i=0;i+2<ktostr.length();i++){
      if(ktostr[i] == ktostr[i+1] && ktostr[i+1] == ktostr[i+2]){
        cout << n << " " << ktostr[i] << " " << pos << endl;
        goto done;
      }
      pos++;
    }
    //    cout << "pos " << pos << endl;

    sqrtn = ktostr + ".";
    //    cout << "#" << number << "#" << rem << "#" <<  endl;
    int last1 = k % 10;
    int last2 = (int) (k/10) % 10;
    int last3;
    if(last1 == k)
      pos--;
    while(true){
      rem += "00";
      int p = rem.find_first_not_of('0');
      if(p == string::npos){
        break;
      }
      for(int i=9;i>=0;i--){
        string output;
        string temp1 = number + (char) (i + '0');
        multiply(temp1,output,i);
        //      cout << output << " " << rem << " " << i << endl;
        if(lessequal(output,rem)){
          string temp;
          min(rem, output, temp);
          number = number + (char) (i + '0');
          string output2;
          add(number,output2,i);
          number=output2;
          rem = temp;
          //      cout << i << endl;
          //      cout << "#" << number << " " << rem << " " << i << endl;
          // remove all zeros
          last3 = last2;
          last2 = last1;
          last1 = i;
          sqrtn += (char)(i+(int)'0');
          break;
        }
      }
      if(last1 == last2 && last2 == last3){
        break;
      }
      pos++;
    }

    cout << n << " " << pos << " " << last1 << endl;
    //    cout << sqrtn << endl;
  }
  return 0;
}
