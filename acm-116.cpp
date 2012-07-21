#include<iostream>
using namespace std;

class mypair
{
  public:
    int weight;
    int parentRow;
};

int myMin(int i1, int i2, int i3)
{
  if(i1<=i2 && i1<=i3)
    return(1);
  else if(i2<=i1 && i2<=i3)
    return(2);
  else if(i3<=i1 && i3<=i2)
    return(3);
}

int main()
{
  int rows;
  int columns;
  while(cin >> rows)
  {
    cin >> columns;
    int numbers[rows][columns];
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<columns;j++)
      {
        cin >> numbers[i][j];
      }
    }
    mypair weightEntries[rows][columns];
    for(int i=columns-1;i>=0;i--)
    {
      for(int j=0;j<rows;j++)
      {
        if(i==columns-1)
        {
          weightEntries[j][i].weight = numbers[j][i];
          weightEntries[j][i].parentRow = j;
        }
        else if(j==0)
        {
          int nextRow = 1;
          if(rows == 1)
            nextRow = 0;
          int minIndex = myMin(weightEntries[0][i+1].weight,
              weightEntries[nextRow][i+1].weight,
              weightEntries[rows-1][i+1].weight);
          if(minIndex == 1)
          {
            weightEntries[j][i].weight = weightEntries[0][i+1].weight + numbers[j][i];
            weightEntries[j][i].parentRow = 0;
          }
          else if(minIndex == 2)
          {
            weightEntries[j][i].weight = weightEntries[nextRow][i+1].weight + numbers[j][i];
            weightEntries[j][i].parentRow = nextRow;
          }
          else
          {
            weightEntries[j][i].weight = weightEntries[rows-1][i+1].weight + numbers[j][i];
            weightEntries[j][i].parentRow = rows-1;
          }
        }
        else if(j==rows-1)
        {
          int minIndex = myMin(weightEntries[0][i+1].weight,
              weightEntries[rows-2][i+1].weight,
              weightEntries[rows-1][i+1].weight);
          if(minIndex == 1)
          {
            weightEntries[j][i].weight = weightEntries[0][i+1].weight + numbers[j][i];
            weightEntries[j][i].parentRow = 0;
          }
          else if(minIndex == 2)
          {
            weightEntries[j][i].weight = weightEntries[rows-2][i+1].weight + numbers[j][i];
            weightEntries[j][i].parentRow = rows-2;
          }
          else
          {
            weightEntries[j][i].weight = weightEntries[rows-1][i+1].weight + numbers[j][i];
            weightEntries[j][i].parentRow = rows-1;
          }
        }
        else
        {
          int minIndex = myMin(weightEntries[j-1][i+1].weight,
              weightEntries[j][i+1].weight,
              weightEntries[j+1][i+1].weight);
          if(minIndex == 1)
          {
            weightEntries[j][i].weight = weightEntries[j-1][i+1].weight + numbers[j][i];
            weightEntries[j][i].parentRow = j-1;
          }
          else if(minIndex == 2)
          {
            weightEntries[j][i].weight = weightEntries[j][i+1].weight + numbers[j][i];
            weightEntries[j][i].parentRow = j;
          }
          else
          {
            weightEntries[j][i].weight = weightEntries[j+1][i+1].weight + numbers[j][i];
            weightEntries[j][i].parentRow = j+1;
          }
        }
      }
    }

    int minEntry = weightEntries[0][0].weight;
    int minEntryIndex = 0;
    for(int i=0; i<rows; i++)
    {
      if(weightEntries[i][0].weight < minEntry)
      {
        minEntry = weightEntries[i][0].weight;
        minEntryIndex = i;
      }
    }
    int path[columns];
    path[0] = minEntryIndex;
    cout << path[0] + 1;
    for(int i=1;i<columns;i++)
    {
      path[i] = weightEntries[ path[i-1] ][i-1].parentRow;
      cout << "  " << path[i] + 1;
    }
    cout << endl << minEntry << endl;
  }
  return(0);
}
