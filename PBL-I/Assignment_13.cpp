#include <iostream>
using namespace std;

int main(){
    int n,visited=-1;
    cout << "No of elements : ";
    cin >> n;

    int arr[n];
    int visitedArr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // frequency logic 

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                visitedArr[j] = visited;
                count++;
            }
            
        }
        if (visitedArr[i]!=visited)
        {
            visitedArr[i] = count;
        }  
    }

    // display 

    cout << "Numbers with their frequency\n";

    for (int i = 0; i < n; i++)
    {
       if (visitedArr[i]!=visited)
       {
            cout << arr[i] << " : " << visitedArr[i] << endl;
       }
       
    }

    return 0;
}
