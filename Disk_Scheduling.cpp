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
        cout << "supposed each track take 0.1 ms , Seek Time : " << totalHeadMovements * 0.1 << " ms" << endl;
        cout << "The Order of requests: ";
        for (int i = 0; i < queueSize; i++)
        {
            cout << requests[i];
            if (i != queueSize - 1)
            {
                cout << " -> ";
            }
        }
        cout << "\n-----------------------------------------------------" << endl;
    }
    void SCAN(int direction)
    {
        int head = initialHead;
        totalHeadMovements = 0;
        vector<int> temp = requests;
        vector<int> p;
        sort(temp.begin(), temp.end());
        int idx = lower_bound(temp.begin(), temp.end(), head) - temp.begin();
        if (direction == 1) 
        {
            for (int i = idx; i < temp.size(); i++)
            {
                totalHeadMovements += abs(temp[i] - head);
                head = temp[i];
                p.push_back(head);
            }
            totalHeadMovements += abs((numOfTracks - 1) - head);
            head = numOfTracks - 1;
            for (int i = idx - 1; i >= 0; i--)
            {
                totalHeadMovements += abs(temp[i] - head);
                head = temp[i];
                p.push_back(head);
            }
        }
        else 
        {
            for (int i = idx - 1; i >= 0; i--)
            {
                totalHeadMovements += abs(temp[i] - head);
                head = temp[i];
                p.push_back(head);
            }
            totalHeadMovements += head;
            head = 0;
            for (int i = idx; i < temp.size(); i++)
            {
                totalHeadMovements += abs(temp[i] - head);
                head = temp[i];
                p.push_back(head);
            }
        }
        cout << "-----------------------------------------------------" << endl;
        cout << "SCAN Algorithm" << endl;
        cout << "Total head movement: " << totalHeadMovements << " Cylinders" << endl;
        cout << "Suppose each track takes 0.1 ms, Seek Time: " << totalHeadMovements * 0.1 << " ms" << endl;
        cout << "The Order of requests: ";
        for (int i = 0; i < p.size(); i++)
        {
            cout << p[i];
            if (i != p.size() - 1)
            {
                cout << " -> ";
            }
        }
        cout << "\n-----------------------------------------------------" << endl;
    }
    void CSCAN(int direction)
    {
        int head = initialHead;
        totalHeadMovements = 0;
        vector<int> temp = requests;
        vector<int> p;
        sort(temp.begin(), temp.end());
        int idx = lower_bound(temp.begin(), temp.end(), head) - temp.begin();
        if (direction == 1)
        {
            for (int i = idx; i < temp.size(); i++)
            {
                totalHeadMovements += abs(temp[i] - head);
                head = temp[i];
                p.push_back(head);
            }
            totalHeadMovements += abs((numOfTracks - 1) - head);
            head = 0;
            totalHeadMovements += head;
            for (int i = 0; i < idx; i++)
            {
                totalHeadMovements += abs(temp[i] - head);
                head = temp[i];
                p.push_back(head);
            }
        }
        else
        {
            for (int i = idx - 1; i >= 0; i--)
            {
                totalHeadMovements += abs(temp[i] - head);
                head = temp[i];
                p.push_back(head);
            }

            totalHeadMovements += head;
            head = numOfTracks - 1;
            totalHeadMovements += head;

            for (int i = temp.size() - 1; i >= idx; i--)
            {
                totalHeadMovements += abs(temp[i] - head);
                head = temp[i];
                p.push_back(head);
            }
        }

        cout << "-----------------------------------------------------" << endl;
        cout << "CSCAN Algorithm" << endl;
        cout << "Total head movement: " << totalHeadMovements << " Cylinders" << endl;
        cout << "Suppose each track takes 0.1 ms, Seek Time: " << totalHeadMovements * 0.1 << " ms" << endl;
        cout << "The Order of requests: ";
        for (int i = 0; i < p.size(); i++)
        {
            cout << p[i];
            if (i != p.size() - 1)
            {
                cout << " -> ";
            }
        }
        cout << "\n-----------------------------------------------------" << endl;
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
    while (true)
    {
        cout << "Choose the scheduling algorithm : \n";
        cout << "1 : FCFS \n2 : SCAN \n3 : CSCAN\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.FCFS();
            break;
        case 2:
            cout << "Enter the direction : \n1 : Clockwise\n2 : Anticlockwise\n";
            int direction;
            cin >> direction;
            if (direction != 1 && direction != 2)
            {
                cout << "Invalid direction" << endl;
                break;
            }
            s.SCAN(direction);
            break;
        case 3:
            cout << "Enter the direction : \n1 : Clockwise\n2 : Anticlockwise\n";
            cin >> direction;
            if (direction != 1 && direction != 2)
            {
                cout << "Invalid direction" << endl;
                break;
            }
            s.CSCAN(direction);
            break;
        default:
            break;
        }
        cout << "Do you want to continue? (y/n) : ";
        char ch;
        cin >> ch;
        if (ch == 'n' || ch == 'N')
        {
            break;
        }
    }

    return 0;
}