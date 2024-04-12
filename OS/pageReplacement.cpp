#include<iostream>
#include<queue>
#include <vector>
#include<unordered_set>
#include<unordered_map>
#include<bits/stdc++.h>

using namespace std;

void fifoReplacement(vector<int>& pages, int capacity){
    queue<int> fifoq;
    unordered_set<int> pageset;
    int pagefaults = 0;

    cout << "Incoming | Pages | Hit/Miss" << endl;

    for(int page: pages){
        cout << " " << page << " | ";

        queue<int> tempq = fifoq;
        while (!tempq.empty())
        {
            cout << tempq.front() << " ";
            tempq.pop();
        }

        for (int i = fifoq.size(); i < capacity; i++)
        {
            cout << " - ";
        }

        cout << " | ";


        // check if set can hold more pages
        if (pageset.size() < capacity)
        {
            // check if page is not present
            if (pageset.find(page) == pageset.end())
            {
                pageset.insert(page);
                // insert in fifo q
                fifoq.push(page);
                // increment faults
                pagefaults++;

                cout << "Miss "<< endl;
            }
            else{
                cout << "Hit " << endl;
            }
            
        }

        // if set is full then implement fifo replacement
        else{
            // check is not present
            if (pageset.find(page) == pageset.end())    
            {
                int front = fifoq.front();
                fifoq.pop();
                // remove from set
                pageset.erase(front);
                pageset.insert(page);
                fifoq.push(page);
                pagefaults++;
                cout << "Miss " << endl;
            }
            else{
                cout << "Hit " << endl;
            }
            
        }
        

        }
        cout << "Total page faults : " << pagefaults << endl;
}


void lruReplacement(vector<int>& pages, int capacity){
    unordered_set<int> s;
    unordered_map<int, int> indexes;
    int pagefaults = 0;

        cout << "Incoming | Pages | Hit/Miss" << endl;


    for (int i = 0; i < pages.size(); i++)
    {
                cout << "   " << pages[i] << "    | ";
 // Print current pages in memory
        for(auto it = s.begin(); it != s.end(); ++it){
            cout << *it << " ";
        }
        for(int j = s.size(); j < capacity; ++j){
            cout << "- ";
        }

        cout << "| ";
        // check if set can hold more pages
        if (s.size() < capacity)
        {
            // check if page is not present
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                pagefaults++;
                cout << "Miss " << endl;
            }
            else{
                cout << "Hit " << endl;
            }
            indexes[pages[i]] = i;
        }

        // set is full implement lru
        else{
            if (s.find(pages[i]) == s.end())
            {
            int lru = INT_MAX, val;
            for (auto it = s.begin(); it != s.end(); it++){
                if(indexes[*it] < lru){
                    lru = indexes[*it];
                    val = *it;
                }
            }

            s.erase(val);
            s.insert(pages[i]);
            pagefaults++;
            cout << "Miss " << endl;
            }
            else{
                cout << "Hit " << endl;
            }

            indexes[pages[i]] = i;
                }
        
    }

    cout << "Total page faults : " << pagefaults << endl;
}

void optimalPageReplacement(vector<int>& pages, int capacity) {
    vector<int> frames;
    int hit = 0;
    cout << "Optimal Algorithm:" << endl;
    cout << "Incoming | Frame | Hit/Miss" << endl;
    for (int i = 0; i < pages.size(); i++) {
        string s;
        cout << "    " << pages[i] << "     | ";
        if (find(frames.begin(), frames.end(), pages[i]) != frames.end()) {
            hit++;
            s = "Hit ";
        } else {
            if (frames.size() < capacity) {
                frames.push_back(pages[i]);
            } else {
                int farthest = -1;
                int pageToRemove = -1;
                for (int j = 0; j < frames.size(); j++) {
                    int k;
                    for (k = i + 1; k < pages.size(); k++) {
                        if (frames[j] == pages[k]) {
                            if (k > farthest) {
                                farthest = k;
                                pageToRemove = j;
                            }
                            break;
                        }
                    }
                    if (k == pages.size()) {
                        pageToRemove = j;
                        break;
                    }
                }
                frames[pageToRemove] = pages[i];
            }
            s = "Miss ";
        }

        for (int p : frames) {
            cout << p << " ";
        }
        for (int j = frames.size(); j < capacity; ++j) {
            cout << "- ";
        }
        cout << " | ";
        cout << s << endl;
    }

    cout << "Total page faults: " << pages.size() - hit << endl;
    cout << endl;
}
int main(){
    int capacity = 3;
    int numPages = 12;
    vector<int> pages{1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};

    fifoReplacement(pages, capacity);
    lruReplacement(pages, capacity);
    optimalPageReplacement(pages, capacity);

    return 0;
}
