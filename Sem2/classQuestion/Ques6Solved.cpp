#include <iostream>
#include <queue>
#include <string>
using namespace std;
// Task structure
struct Task
{
    string name;
    int timeRequired;
    Task(string n, int t) : name(n), timeRequired(t) {}
};

// Simulate CPU execution
void simulateCPU(queue<Task> &tasks, int timeSlice)
{
    while (!tasks.empty())
    {
        Task current = tasks.front();
        tasks.pop();
        if (current.timeRequired <= timeSlice)
        {
            cout << "Task " << current.name << " executed and completed." << endl;
        }
        else
        {
            cout << "Task " << current.name << " executed for " << timeSlice
                 << " units, " << current.timeRequired - timeSlice << " units remaining." << endl;
            current.timeRequired -= timeSlice;
            tasks.push(current); // Reinsert with remaining time
        }
    }
}
int main()
{
    int n, timeSlice;
    cout << "Enter number of tasks: ";
    cin >> n;
    queue<Task> taskQueue;
    for (int i = 0; i < n; ++i)
    {
        string name;
        int duration;
        cout << "Enter task name and duration: ";
        cin >> name >> duration;
        taskQueue.push(Task(name, duration));
    }
    cout << "Enter time slice: ";
    cin >> timeSlice;
    cout << "\n--- CPU Execution Start ---\n";
    simulateCPU(taskQueue, timeSlice);
    cout << "--- CPU Execution Complete ---\n";
    return 0;
}