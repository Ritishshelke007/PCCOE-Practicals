#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

void fcfs(vector<int> requests, int head) {
    int totalMovement = 0;
    int current = head;
    vector<int> seekSequence;
    for (int req : requests) {
        totalMovement += abs(current - req);
        seekSequence.push_back(req);
        current = req;
    }
    cout << "FCFS" << endl <<  "Total head movement = " << totalMovement << endl << "Seek sequence: ";
    for (int i : seekSequence) {
        cout << i << " ";
    }
    cout << endl << endl;
}

void sstf(vector<int> requests, int head) {
    int totalMovement = 0;
    int current = head;
    vector<bool> visited(requests.size(), false);
    vector<int> seekSequence;
    for (int i = 0; i < requests.size(); ++i) {
        int minDist = INT_MAX;
        int index = -1;
        for (int j = 0; j < requests.size(); ++j) {
            if (!visited[j]) {
                int dist = abs(current - requests[j]);
                if (dist < minDist) {
                    minDist = dist;
                    index = j;
                }
            }
        }
        totalMovement += minDist;
        seekSequence.push_back(requests[index]);
        current = requests[index];
        visited[index] = true;
    }
    cout << "SSTF " << endl <<  "Total head movement = " << totalMovement << endl <<  "Seek sequence: ";
    for (int i : seekSequence) {
        cout << i << " ";
    }
    cout << endl << endl;
}

void scan(vector<int> requests, int head, string direction) {
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seekSequence;

    if (direction == "left")
        left.push_back(0);
    else if (direction == "right")
        right.push_back(199); // Cylinder size is 200

    for (int i = 0; i < requests.size(); i++) {
        if (requests[i] < head)
            left.push_back(requests[i]);
        if (requests[i] > head)
            right.push_back(requests[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int run = 2;
    while (run--) {
        if (direction == "left") {
            for (int i = left.size() - 1; i >= 0; i--) {
                cur_track = left[i];
                seekSequence.push_back(cur_track);
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = "right";
        }
        else if (direction == "right") {
            for (int i = 0; i < right.size(); i++) {
                cur_track = right[i];
                seekSequence.push_back(cur_track);
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = "left";
        }
    }

    cout << "SCAN" << endl <<  "Total head movement = " << seek_count << endl << "Seek sequence: ";
    for (int i : seekSequence) {
        cout << i << " ";
    }
    cout << endl;
}

void cscan(vector<int> requests, int head) {
cout << endl;
    int disk_size = 200;
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seekSequence;

    left.push_back(0);
    right.push_back(199); // Cylinder size is 200

    for (int i = 0; i < requests.size(); i++) {
        if (requests[i] < head)
            left.push_back(requests[i]);
        if (requests[i] > head)
            right.push_back(requests[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for (int i = 0; i < right.size(); i++) {
        cur_track = right[i];
        seekSequence.push_back(cur_track);
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }

    head = 0;
    seek_count += (disk_size - 1);

    for (int i = 0; i < left.size(); i++) {
        cur_track = left[i];
        seekSequence.push_back(cur_track);
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }

    cout << "C-SCAN" << endl <<  "Total head movement = " << seek_count <<  endl << "Seek sequence: ";
    for (int i : seekSequence) {
        cout << i << " ";
    }
    cout << endl << endl;
}

int main() {
    int count;
    int head;
    cout << "Total requests : ";
    cin >> count;
    vector<int> requests(count);
    cout << "Enter requests : ";
    for (int i=0; i<count; i++){
        cin >> requests[i];
    }
    cout << "Enter Head : ";
    cin >> head;
    cout << endl;

    fcfs(requests, head);
    sstf(requests, head);
    scan(requests, head, "left"); // SCAN
    cscan(requests, head);

    return 0;
}
