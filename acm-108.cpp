#include<iostream>
#include<vector>
using namespace std;

class matrix
{
  int* numbers;
  int size;
  public:
  matrix(int size)
  {
    numbers = new int[size*size];
    this->size = size;
  }

  ~matrix()
  {
    delete numbers;
  }

  int getEntry(int i, int j)
  {
    return(numbers[i*size + j]);
  }

  void makeEntry(int i, int j, int number)
  {
    numbers[i*size + j] = number;
  }
};

int sumOfRectangle(matrix &m, int x1, int y1, int x2, int y2, int previousSum)
{
  int answer = previousSum;
  for(int j=y1; j<=y2; j++)
  {
    answer += m.getEntry(x2,j);
  }
  return(answer);
}

int main()
{
  int size;
  cin >> size;
  int numEntered;
  matrix entries(size);
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<size;j++)
    {
      cin >> numEntered;
      entries.makeEntry(i, j, numEntered);
    }
  }
  int maxSum = INT_MIN;
  int cumMin;
  int cumMax;
  int cumSum;
  for(int x1=0; x1<=0; x1++)
  {
    for(int y1=0; y1<size; y1++)
    {
      for(int y2=0; y2<size; y2++)
      {
        cumSum = 0;
        cumMin = 0;
        cumMax = INT_MIN;
        for(int x2=0; x2<size; x2++)
        {
          cumSum = sumOfRectangle(entries, x1, y1, x2, y2, cumSum);
          if(cumSum > cumMax)
            cumMax = cumSum;
          if(maxSum < (cumMax - cumMin))
            maxSum = cumMax - cumMin;
          if(cumSum < cumMin)
          {
            cumMin = cumSum;
            cumMax = INT_MIN;
          }
        }
      }
    }
  }
  cout << maxSum << endl;
  return(0);
}
