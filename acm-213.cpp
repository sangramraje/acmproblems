#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int bintodec(int numberOfChars)
{
    int answer=0;
    for(int i=0;i<numberOfChars;i++)
    {
        char c;
        cin >> c;
        answer=2*answer+(int) (c-'0');
    }
    return(answer);
}

int main()
{
    string header;
    int breakCodes[] = {0, 1, 3, 7, 15, 31, 63, 127};
    int offsets[] = {0, 0, 1, 4, 11, 26, 57, 120};
    while(getline(cin,header))
    {
        while(true){
            int lengthOfCode = bintodec(3);
            if(lengthOfCode == 0)
                break;
            while(true){
                int code = bintodec(lengthOfCode);
                if(code == breakCodes[lengthOfCode])
                    break;
                cout << header[offsets[lengthOfCode] + code];
            }
        }
        cout << endl;
        getline(cin, header);        
    }
    return(0);
}



