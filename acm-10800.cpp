#include<iostream>
#include<string>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for(int z=0;z<n;z++){
    cout << "Case #" << z+1 << ":" << endl;
    string s;
    cin >> s;
    int length_y_axis=0;
    int maxdepth=0;
    int maxheight=0;
    int height=0;
    for(int i=0;i<s.length();i++){
      if(s[i]=='R' && (i==0 || (i>0 && s[i-1]!='C'))){
        height++;
        if(maxheight<height){
          maxheight++;
        }
      }
      if(s[i]=='C' && (i==0 || (i>0 && s[i-1]!='C'))){
        height++;
        if(maxheight<height){
          maxheight++;
        }
      }
      if(s[i]=='F'){
        height--;
        if(i>0 && s[i-1]=='C')
          height--;
        if(maxdepth<-height){
          maxdepth++;
        }
      }
    }
    length_y_axis = maxdepth+maxheight;
    int prints[length_y_axis][s.length()];
    for(int i=0;i<length_y_axis;i++){
      for(int j=0;j<s.length();j++){
        prints[i][j]=0;
      }
    }
    int depth=length_y_axis-maxdepth-1;
    int xcor=0;
    for(int i=0;i<s.length();i++){
      if(s[i]=='R'){
        prints[depth][xcor]=1;
        depth--;
      }
      if(s[i]=='F'){
        depth++;
        prints[depth][xcor]=2;
      }
      if(s[i]=='C'){
        prints[depth][xcor]=3;
      }
      xcor++;
    }
    int lastpos[length_y_axis];
    for(int i=0;i<length_y_axis;i++){
      for(int j=s.length()-1;j>=0;j--){
        if(prints[i][j]!=0){
          lastpos[i]=j;
          break;
        }
      }
    }
    for(int i=0;i<length_y_axis;i++){
      cout << "|";
      for(int j=0;j<=lastpos[i];j++){

        if(j==0)
          cout << " ";
        if(prints[i][j]==0)
          cout << " ";
        if(prints[i][j]==1)
          cout << "/";
        if(prints[i][j]==2)
          cout << "\\";
        if(prints[i][j]==3)
          cout << "_";
      }
      cout << endl;
    }
    cout << "+";
    for(int i=0;i<s.length()+2;i++)
      cout << "-";
    cout << endl << endl;
  }
  return 0;
}

