#include <bits/stdc++.h>
using namespace std;
// 32 bit system
// 4 kbyte page size
// 2 power 20 blocks
// int is 4 bytes
class MemoryAllocator
{
private:
    long long total_memory;
    int process_id;
    vector<int> memory;
    unordered_map<int, string> process_map;

public:
    MemoryAllocator(long long total_memory)
    {
        this->total_memory = total_memory;
        memory.resize(total_memory / 4); // 4 bytes per int
        fill(memory.begin(), memory.end(), 0);
        process_id = 0;
    }
    void allocate(int size, string process_name, char option)
    {
        process_id++;
        process_map[process_id] = process_name;
        switch (toupper(option))
        {
        case 'F':
            firstFit(size);
            break;
        case 'B':
            bestFit(size);
            break;
        case 'W':
            worstFit(size);
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
    void firstFit(int size)
    {
        int numOfEntries = (size + 3) / 4; // due to integer division
        bool allocated = false;
        for (int i = 0; i < memory.size(); i++)
        {
            if (memory[i] == 0)
            {
                int start = i;
                int end = start + numOfEntries - 1;
                if (end >= memory.size() || memory[end] > 0)
                {
                    i = end;
                    continue;
                }
                else
                {
                    for (int j = start; j <= end; j++)
                    {
                        memory[j] = process_id;
                    }
                    allocated = true;
                    break;
                }
            }
        }
        if (!allocated)
        {
            cout << "Not enough memory" << endl;
        }
    }
    void bestFit(int size)
    {
        int numOfEntries = (size + 3) / 4;
        bool allocated = false;
        int bestFitIndex = -1;
        int bestFitSize = INT_MAX;
        for (int i = 0; i < memory.size(); i++)
        {
            if (memory[i] == 0)
            {
                int start = i;
                int end = start + numOfEntries - 1;
                if (end >= memory.size() || memory[end] > 0)
                {
                    i = end;
                    continue;
                }
                else
                {
                    if (end - start + 1 < bestFitSize)
                    {
                        bestFitSize = end - start + 1;
                        bestFitIndex = start;
                    }
                }
            }
        }
        if (bestFitIndex != -1)
        {
            for (int j = bestFitIndex; j <= bestFitIndex + numOfEntries - 1; j++)
            {
                memory[j] = process_id;
            }
            allocated = true;
        }
        if (!allocated)
        {
            cout << "Not enough memory" << endl;
        }
    }
    void worstFit(int size)
    {
        int numOfEntries = (size + 3) / 4;
        bool allocated = false;
        int worstFitIndex = -1;
        int worstFitSize = INT_MIN;
        for (int i = 0; i < memory.size(); i++)
        {
            if (memory[i] == 0)
            {
                int start = i;
                int end = start + numOfEntries - 1;
                if (end >= memory.size() || memory[end] > 0)
                {
                    i = end;
                    continue;
                }
                else
                {
                    if (end - start + 1 > worstFitSize)
                    {
                        worstFitSize = end - start + 1;
                        worstFitIndex = start;
                    }
                }
            }
        }
        if (worstFitIndex != -1)
        {
            for (int j = worstFitIndex; j <= worstFitIndex + numOfEntries - 1; j++)
            {
                memory[j] = process_id;
            }
            allocated = true;
        }
        if (!allocated)
        {
            cout << "Not enough memory" << endl;
        }
    }
    void deallocate(string process_name)
    {
        int process_id = 0;
        for (auto it = process_map.begin(); it != process_map.end(); it++)
        {
            if (it->second == process_name)
            {
                process_id = it->first;
                break;
            }
        }
        if (process_id == 0)
        {
            cout << "Process not found" << endl;
            return;
        }
        for (int i = 0; i < memory.size(); i++)
        {
            if (memory[i] == process_id)
            {
                while (i < memory.size() && memory[i] == process_id)
                {
                    memory[i] = 0;
                    i++;
                }
                break;
            }
        }
        process_map.erase(process_id);
    }
    void compact()
    {
        int lastPointer = -1;
        for (int i = 0; i < memory.size(); i++)
        {
            if (memory[i] == 0)
            {
                lastPointer = i;
                while (i < memory.size() && memory[i] == 0)
                {
                    i++;
                }
                while (i < memory.size())
                {
                    memory[lastPointer] = memory[i];
                    memory[i] = 0;
                    lastPointer++;
                    i++;
                }
            }
        }
    }
    void status()
    {
        int first = 0;
        for (int i = 0; i < memory.size(); i++)
        {
            while (i < memory.size() && memory[i] == memory[first])
            {
                i++;
            }
            if (memory[first] == 0)
            {
                cout << "[" << first * 4 << " : " << ((i - 1) * 4) + 3 << "]" << " Unused " << endl;
            }
            else
            {
                cout << "[" << first * 4 << " : " << ((i - 1) * 4) + 3 << "]" << " Process " << process_map[memory[first]] << endl;
            }
            first = i;
        }
    }
    ~MemoryAllocator()
    {
        memory.clear();
        process_map.clear();
        total_memory = 0;
        process_id = 0;
    }
};
void startShell(MemoryAllocator &allocator)
{
    string command;
    cout << "allocator> ";
    while (cin >> command)
    {
        if (command == "RQ")
        {
            string name;
            int size;
            char option;
            cin >> name >> size >> option;
            allocator.allocate(size, name, option);
        }
        else if (command == "RL")
        {
            string name;
            cin >> name;
            allocator.deallocate(name);
        }
        else if (command == "C")
        {
            allocator.compact();
        }
        else if (command == "STAT")
        {
            allocator.status();
        }
        else if (command == "X")
        {
            break;
        }
        else
        {
            cout << "Invalid command" << endl;
        }
        cout << "allocator> ";
    }
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    long long total_memory = stoll(argv[1]);
    MemoryAllocator allocator(total_memory);
    startShell(allocator);

    return 0;
}