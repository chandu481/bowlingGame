
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void clearCinError()
{
    cerr << "Invalid input! Please enter an integer." << endl;
    
    // Clear the error flag
    cin.clear();

    // Discard the invalid input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int printResult(vector<int>& scores, int round)
{
    int total = 0;
    int lineNo = 1;
    for(int i=0; i<scores.size(); )
    {
        if(lineNo <= 10)
        cout<<"Round "<<lineNo<<"-----> ";
        int s1 = scores[i];
        cout<<s1<<"    ";
        if(s1 == 10)
        {
            if(i+2 < scores.size())
            {
                int val1 = scores[i+1];
                int val2 = scores[i+2];
                int res = s1+val1 + val2;
                total += res;
                    cout<<"  \t "<<total;
            }
            i++;
        }
        else
        {
            if(i+1 < scores.size())
            {
                int val1 = scores[i+1];
                cout<<val1;
                if(s1 + val1 == 10)
                {
                    if(i+2 < scores.size())
                    {
                        int val2 = scores[i+2];
                        int res = s1 + val1 + val2;
                        total += res;
                            cout<<"  \t "<<total;
                    }
                }
                else
                {
                    total += s1 + val1;
                        cout<<"  \t "<<total;
                }
                
            }
            i = i+2;
        }
        if(lineNo < 10)
        {
            cout<<endl;
        }
        lineNo++;
    }
    return total;
}

int getInput(int tryNo, int range)
{
    int s = 0;
    bool tryAgain = false;
    do {
        tryAgain = false;
        cout<<"Enter try "<<tryNo<<"(0-"<<range<<"): ";
        cin>>s;
        if (cin.fail()) 
        {
            tryAgain = true;
            clearCinError();
        }   
        else if(!(s >= 0 && s <= range) )
        {
            cout<<"Invalid input!!"<<endl;
            tryAgain = true;
        }
    }while(tryAgain);

    return s;
}

int main() 
{
    vector<int> scores;
    int total = 0;
    int s1 = 0, s2 = 0;
    for(int i=1; i<=10; i++)
    {
        
        cout<<"---------- Round "<<i<<" -------------"<<endl;
        int range = 10;
        int tryNo = 1;
        s1 = getInput(tryNo, range);
        scores.push_back(s1);
        
        range = 10-s1;
        total = printResult(scores, i);
        if(s1 != 10 || i == 10)
        {
            if(i == 10)
            {
                tryNo = 2;
                range = 10;
                cout<<endl;
                s2 = getInput(tryNo, range);
            }
            else 
            {
                tryNo = 2;
                s2 = getInput(tryNo, range);
            }

            
            scores.push_back(s2);
            total = printResult(scores, i);
            
            if(i == 10)
            {
                if(s1 + s2 >= 10)
                {
                    total += s1 + s2;
                    tryNo = 3;
                    range = 10;
                    cout<<endl;
                    int extraPoint = getInput(tryNo, range);

                    total += extraPoint;
                    printResult(scores,i);
                    cout<<"\n\t\t ::"<<extraPoint;
                    cout<<"    "<<total;
                }
            }
        }
    }
    
    return 0;
}