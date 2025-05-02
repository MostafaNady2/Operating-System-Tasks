#include <bits/stdc++.h>
using namespace std;
class Scheduler
{
private:
    int queueSize;
    int initialHead;
    int numOfTracks;
    double totalHeadMovements;
    vector<int> requests;

public:
    Scheduler(int queueSize, int initialHead, int numOfTracks)
    {
        this->queueSize = queueSize;
        this->initialHead = initialHead;
        this->numOfTracks = numOfTracks;
        totalHeadMovements = 0;
    }
    void fillRequests()
    {
        cout << "Enter the requests: ";
        for (int i = 0; i < queueSize; i++)
        {
            int request;
            cin >> request;
            requests.push_back(request);
        }
    }
    double totalSeekTime()
    {
        return totalHeadMovements;
    }
    void FCFS()
    {
        int head = initialHead;
        totalHeadMovements = 0;
        for (int i = 0; i < queueSize; i++)
        {
            int request = requests[i];
            totalHeadMovements += abs(head - request);
            head = request;
        }
        cout << "-----------------------------------------------------" << endl;
        cout << "FCFS Algorithm" << endl;
        cout << "Total head movement: " << totalHeadMovements << " Cylinders" << endl;
        cout<< "supposed each track take 0.1 ms , Seek Time : "<<totalHeadMovements*0.1<<" ms"<<endl;
        cout << "The Order of requests: ";
        for (int i = 0; i < queueSize; i++)
        {
            cout << requests[i];
            if (i != queueSize - 1)
            {
                cout << " -> ";
            }
        }
        cout << '\n';
    }
    void SCAN()
    {
        int head = initialHead;
        totalHeadMovements = 0;
        vector<int> temp = requests;
        vector<int> p;
        sort(temp.begin(), temp.end());
        int idx = lower_bound(temp.begin(), temp.end(), head) - temp.begin();
        for (int i = idx; i < temp.size(); i++)
        {
            int request = temp[i];
            totalHeadMovements += abs(request - head);
            head = request;
            p.push_back(request);
        }
        totalHeadMovements += abs((numOfTracks - 1) - head);
        head = numOfTracks - 1;
        p.push_back(numOfTracks - 1);
        for (int i = idx - 1; i >= 0; i--)
        {
            int request = temp[i];
            totalHeadMovements += abs(head - request);
            head = request;
            p.push_back(request);
        }
        cout << "-----------------------------------------------------" << endl;
        cout << "SCAN Algorithm" << endl;
        cout << "Total head movement: " << totalHeadMovements << " Cylinders" << endl;
        cout<< "supposed each track take 0.1 ms , Seek Time : "<<totalHeadMovements*0.1<<" ms"<<endl;
        cout << "The Order of requests: ";
        for (int i = 0; i < p.size(); i++)
        {
            cout << p[i];
            if (i != p.size() - 1)
                cout << " -> ";
        }
        cout << '\n';
    }
    void CSCAN()
    {
        int head = initialHead;
        totalHeadMovements = 0;
        vector<int> temp = requests;
        vector<int> p;
        sort(temp.begin(), temp.end());
        int idx = lower_bound(temp.begin(), temp.end(), head) - temp.begin();
        for (int i = idx; i < temp.size(); i++)
        {
            int request = temp[i];
            totalHeadMovements += abs(request - head);
            head = request;
            p.push_back(request);
        }
        totalHeadMovements += abs((numOfTracks - 1) - head);
        head = numOfTracks - 1;
        p.push_back(numOfTracks - 1);
        totalHeadMovements += abs(0 - head);
        head = 0;
        p.push_back(0);
        for (int i = 0; i < idx; i++)
        {
            int request = temp[i];
            totalHeadMovements += abs(head - request);
            head = request;
            p.push_back(request);
        }
        cout << "-----------------------------------------------------" << endl;
        cout << "CSCAN Algorithm" << endl;
        cout << "Total head movement: " << totalHeadMovements << " Cylinders" << endl;
        cout<< "supposed each track take 0.1 ms , Seek Time : "<<totalHeadMovements*0.1<<" ms"<<endl;
        cout << "The Order of requests: ";
        for (int i = 0; i < p.size(); i++)
        {
            cout << p[i];
            if (i != p.size() - 1)
                cout << " -> ";
        }
        cout << '\n';
    }
    ~Scheduler()
    {
        requests.clear();
        totalHeadMovements = 0;
        queueSize = 0;
        initialHead = 0;
        numOfTracks = 0;
    }
};
int main()
{
    int head, queueSize, initialHead, numOfTracks;
    cout << "Enter the number of trcks : ";
    cin >> numOfTracks;
    cout << "Enter the queue size : ";
    cin >> queueSize;
    cout << "Enter the initial head : ";
    cin >> initialHead;
    Scheduler s(queueSize, initialHead, numOfTracks);
    s.fillRequests();
    s.FCFS();
    s.SCAN();
    s.CSCAN();

    return 0;
}