#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int getPageFaults(int pages[], int n, int frames)
{


    unordered_set <int> set;  
    queue <int> indexes;
    
    
    int countPageFaults = 0;
    
    cout << "Incoming\tPages\n";

    for (int i=0; i < n; i++)
    {
        
        if (set.size() < frames)
        {
            
            if (set.find(pages[i])==set.end())
            {
                set.insert(pages[i]);
                // increment the conter for page fault
                countPageFaults++;
            
                // Push the current page into the queue
                indexes.push(pages[i]);
            }
        }


        else
        {
           
            if (set.find(pages[i]) == set.end())
            {
                // Remove the first page from the queue
                int val = indexes.front();
                indexes.pop();
                
                // Pop the index page
                set.erase(val);
                
                // Push the current page in the queue
                set.insert(pages[i]);
                indexes.push(pages[i]);
                
                // Increment page faults
                countPageFaults++;
            }
        }
        cout << pages[i] << "\t\t";
        queue<int> Q = indexes;
        while(!Q.empty()){
		cout<<" "<< Q.front();
		Q.pop();
	}

	cout<<endl;
    }
    
    

    return countPageFaults;
}

// Driver code
int main()
{
    int pages[] = {7, 0, 1, 2, 0,3,0,4,2,3,0,3,2,1};
    int n = sizeof(pages)/sizeof(pages[0]);
    int frames = 3;

    int pageFaults = getPageFaults(pages, n, frames);
    cout << "Page Faults : " << pageFaults << endl;

    return 0;
}
