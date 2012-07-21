#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
 int counter = 0;
 for(int i=3;counter<10;i+=2){
   int j = i*i;
   int k = (int) sqrt((j+1)/2);
   int l = (int) sqrt((j-1)/2);
   if(k*k == (j+1)/2){
     printf("%10d%10d\n", i*k,j);
     counter++;
     continue;
   }
   if(l*l == (j-1)/2){
     printf("%10d%10d\n", i*l, j-1);
     counter++;
   }

 }
 return 0;
}
