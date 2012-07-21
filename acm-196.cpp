#include<iostream>
#include<cassert>
#include<vector>
using namespace std;

#define BLACK   101
#define WHITE   102
#define GRAY    103

int rows, columns;

int parse(string s){
    int a[3]={-1, -1, -1};
    int num = 0;
    int i;
    for (i=0; i<s.length(); i++){
        if (s[i]<'A' || s[i]>'Z'){
           num=atoi(s.substr(i).c_str())-1;
           break;
        }
        a[i]=(int) (s[i]-'A');
    }
    if(i == 1){
        return columns*num+a[0];
    }
    else if(i == 2){
        return columns*num+(26*(a[0])+26+a[1]);
    }
    else{
        return columns*num+(26*26*(a[0])+676+26*(a[1])+26+a[2]);
    }
}

void DFS(int index, vector< vector<int> >& dependencyGraph, vector< vector<short int> >& colour, vector<int>& processIndices){
    //cout << "Calling DFS for " << index << endl;
    
    int myrow, mycolumn;
    myrow = index/columns;
    mycolumn = index%columns;
    
    colour[myrow][mycolumn]=GRAY;
    
    for(int i=0; i<dependencyGraph[index].size(); i++){
            int next = dependencyGraph[index][i];
    //        cout << "Next is: " << next << endl;
            if(colour[next/columns][next%columns] == WHITE){
                 DFS(next, dependencyGraph, colour, processIndices);
            }
    }
    
    colour[myrow][mycolumn]=BLACK;
    
    processIndices.push_back(index);
}
                

int main(){
    int numberOfSheets;
    cin >> numberOfSheets;
    
    for(int z=0; z<numberOfSheets; z++){
            vector<int> tempV;
            cin >> columns >> rows;
            
            vector< vector<short int> > colour;
            vector< vector<int> > dependencyGraph(rows*columns, tempV);
            vector< vector<int> > numbers;
            vector<int> processIndices;

            for(int i=0; i<rows; i++){
                    vector<short int> tempColour(columns);
                    vector<int> tempNumbers(columns);
                    for(int j=0; j<columns; j++){
                            string temp;
                            cin >> temp;
                            if(temp[0] == '='){
           //                     cout << temp << " ";
                                       int start = 1;
                                       int end = temp.find("+", start);
                                       while(end != string::npos){
                                                 int ref = parse(temp.substr(start, end-start));
                                                 dependencyGraph[i*columns+j].push_back(ref);
      //                                           cout << ref << " ";
      //                                           cout << i << " " << j << ": " << ref << endl;
                                                 start = end+1;
                                                 end = temp.find("+", start);
                                       }
                                       int ref = parse(temp.substr(start));
                                       dependencyGraph[i*columns+j].push_back(ref);
        //                               cout << i << " " << j << ": " << ref << endl;
                                       tempNumbers[j]=0;
                                       tempColour[j]=WHITE;
        //                               cout << ref << endl;
                            }
                            else{
                                 tempColour[j]=BLACK;
                                 tempNumbers[j]=atoi(temp.c_str());
          //                       cout << i << " " << j << ": " << numbers[i][j] << endl;
                            }
                    }
                    colour.push_back(tempColour);
                    numbers.push_back(tempNumbers);
            }
            for(int i=0; i<rows*columns; i++){
                    if(colour[i/columns][i%columns]==WHITE){
                        DFS(i, dependencyGraph, colour, processIndices);
                    }
            }
            
            for(int i=0; i<processIndices.size(); i++){
                    int myrow = processIndices[i]/columns;
                    int mycolumn = processIndices[i]%columns;
		    cout << "Processing entry at " << myrow << " and " << mycolumn << endl;
                    for(int j=0; j<dependencyGraph[processIndices[i]].size(); j++){
                            int tempIndex = dependencyGraph[processIndices[i]][j];                                   
                            numbers[myrow][mycolumn]+=numbers[tempIndex/columns][tempIndex%columns];
                    }
            }
            
            for(int i=0; i<rows; i++){
                    for(int j=0; j<columns; j++){
                        if(j>0)
                            cout << " ";    
                        cout << numbers[i][j];
                    }
                    cout << endl;
            }
            
            if(z < numberOfSheets-1)
                cout << endl;
    }
    
    return 0;
}        
