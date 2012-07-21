#include<iostream>
#include<string>
#include<vector>
using namespace std;

class myPair
{
  public:
    int indexNumber;
    int lengthOfPath;
};

class Node
{
  public:
    char nodeName;
    vector<myPair> listOfConnections;
    int keyValue;
};


int main()
{
  vector<Node> listOfNodes;
  string input;
outOfLoop:
  while(cin >> input)
  {
    if(input == "deadend")
    {
      vector<int> listForDijkstra;
      int nodesOfOddDegree = 0;
      int startingNode = -1;
      int endingNode = -1;
      for(int i=0;i<listOfNodes.size();i++)
      {
        listForDijkstra.push_back(i);
        if(listOfNodes[i].listOfConnections.size() % 2 == 1)
        {
          nodesOfOddDegree ++;
          if(nodesOfOddDegree == 1)
          {
            startingNode = i;
            listOfNodes[i].keyValue = 0;
          }
          else
          {
            endingNode = i;
          }
        }
      }
      int lengthOfPath=0;
      for(int i=0;i<listOfNodes.size();i++)
      {
        for(int j=0; j<listOfNodes[i].listOfConnections.size(); j++)
        {
          lengthOfPath += listOfNodes[i].listOfConnections[j].lengthOfPath;
        }
      }
      lengthOfPath /= 2;
      if(startingNode == -1)
      {
        listOfNodes.clear();
        cout << lengthOfPath << endl;
      }
      else
      {
        do
        {
          int smallestKey = INT_MAX;
          int smallestKeyIndex = -1;
          for(int i=0; i<listForDijkstra.size(); i++)
          {
            if(listOfNodes[ listForDijkstra[i] ].keyValue <= smallestKey)
            {
              smallestKeyIndex = i;
              smallestKey = listOfNodes[ listForDijkstra[i] ].keyValue;
            }
          }
          int selectedNode = listForDijkstra[smallestKeyIndex];
          if(selectedNode == endingNode)
          {
            cout << lengthOfPath + listOfNodes[selectedNode].keyValue << endl;
            listOfNodes.clear();
            break;
          }
          listForDijkstra.erase(listForDijkstra.begin() + smallestKeyIndex);
          for(int i=0;i<listOfNodes[selectedNode].listOfConnections.size();i++)
          {
            for(int j=0;j<listForDijkstra.size();j++)
            {
              if(listForDijkstra[j] ==
                  listOfNodes[selectedNode].listOfConnections[i].indexNumber)
              {
                if(listOfNodes[ listOfNodes[selectedNode].listOfConnections[i].indexNumber ].keyValue > listOfNodes[selectedNode].listOfConnections[i].lengthOfPath + listOfNodes[selectedNode].keyValue)
                {
                  listOfNodes[ listOfNodes[selectedNode].listOfConnections[i].indexNumber ].keyValue = listOfNodes[selectedNode].listOfConnections[i].lengthOfPath +
                    listOfNodes[selectedNode].keyValue;
                }
                break;
              }
            }
          }
        }while(listForDijkstra.size() > 0);
      }
    }
    else
    {
      char name1 = input[0];
      int i,j;
      for(i=0; i< listOfNodes.size(); i++)
      {
        if(listOfNodes[i].nodeName == name1)
        {
          char name2 = input[input.length()-1];
          //  cout << name2 << endl;
          for(j=0; j < listOfNodes.size(); j++)
          {
            if(listOfNodes[j].nodeName == name2)
            {
              myPair temp;
              temp.indexNumber = i;
              temp.lengthOfPath = input.length();
              listOfNodes[j].listOfConnections.push_back(temp);
              temp.indexNumber = j;
              listOfNodes[i].listOfConnections.push_back(temp);
              goto outOfLoop;
            }
          }
          if(j == listOfNodes.size())
          {
            myPair temp;
            temp.indexNumber = i;
            temp.lengthOfPath = input.length();
            Node tempNode;
            tempNode.nodeName = name2;
            tempNode.listOfConnections.push_back(temp);
            tempNode.keyValue = INT_MAX;
            listOfNodes.push_back(tempNode);
            temp.indexNumber = j;
            listOfNodes[i].listOfConnections.push_back(temp);
            goto outOfLoop;
          }
        }
      }
      if(i == listOfNodes.size())
      {
        char name2 = input[input.length()-1];
        for(j=0; j < listOfNodes.size(); j++)
        {
          if(listOfNodes[j].nodeName == name2)
          {
            myPair temp;
            temp.indexNumber = j;
            temp.lengthOfPath = input.length();
            Node tempNode;
            tempNode.nodeName = name1;
            tempNode.listOfConnections.push_back(temp);
            tempNode.keyValue = INT_MAX;
            listOfNodes.push_back(tempNode);
            temp.indexNumber = i;
            listOfNodes[j].listOfConnections.push_back(temp);
            goto outOfLoop;
          }
        }
        if(j == listOfNodes.size())
        {
          Node tempNode;
          tempNode.nodeName = name2;
          tempNode.keyValue = INT_MAX;
          listOfNodes.push_back(tempNode);
          tempNode.nodeName = name1;
          listOfNodes.push_back(tempNode);
          myPair temp;
          temp.indexNumber = j+1;
          temp.lengthOfPath = input.length();
          listOfNodes[j].listOfConnections.push_back(temp);
          temp.indexNumber = j;
          listOfNodes[j+1].listOfConnections.push_back(temp);
          goto outOfLoop;
        }
      }
    }
  }

  return (0);
}
