#include "task.h"
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

void addTask(vector<Task>& list) {
    Task t;
    cout << "Name: "; getline(cin, t.name);
    cout << "Priority (1-5): "; cin >> t.priority; cin.ignore();
    cout << "Description: "; getline(cin, t.description);
    cout << "Date (YYYY-MM-DD): "; getline(cin, t.dateTime);
    list.push_back(t);
}

void showTasks(const vector<Task>& list) {
    for (size_t i = 0; i < list.size(); ++i)
        cout << i + 1 << ". " << list[i].name << " (" << list[i].priority << ") "
        << list[i].dateTime << "\n" << list[i].description << "\n\n";
}

void deleteTask(vector<Task>& list, int index) {
    if (index >= 0 && index < (int)list.size())
        list.erase(list.begin() + index);
}

void editTask(vector<Task>& list, int index) {
    if (index < 0 || index >= (int)list.size()) return;
    cout << "New name: "; getline(cin, list[index].name);
    cout << "New priority: "; cin >> list[index].priority; cin.ignore();
    cout << "New description: "; getline(cin, list[index].description);
    cout << "New date (YYYY-MM-DD): "; getline(cin, list[index].dateTime);
}

void searchTask(const vector<Task>& list) {
    string key;
    cout << "Search by name: "; getline(cin, key);
    for (const auto& t : list)
        if (t.name.find(key) != string::npos)
            cout << t.name << " (" << t.priority << ") " << t.dateTime << endl;
}

void sortTasks(vector<Task>& list) {
    sort(list.begin(), list.end(), [](const Task& a, const Task& b) {
        return a.priority < b.priority;
        });
}

void filterTasks(const vector<Task>& list, int mode) {
    string key;
    cout << "Enter date (YYYY-MM-DD): "; getline(cin, key);

    for (const auto& t : list) {
        if (mode == 1 && t.dateTime == key) 
            cout << t.name << " (" << t.priority << ") " << t.dateTime << endl;
        else if (mode == 2 && t.dateTime.substr(0, 7) == key.substr(0, 7)) 
            cout << t.name << " (" << t.priority << ") " << t.dateTime << endl;
        else if (mode == 3 && t.dateTime.substr(0, 7) == key.substr(0, 7)) 
            cout << t.name << " (" << t.priority << ") " << t.dateTime << endl;
    }
}

void saveTasks(const vector<Task>& list, const string& filename) {
    ofstream fout(filename);
    for (const auto& t : list) {
        fout << t.name << "|" << t.priority << "|"
            << t.description << "|" << t.dateTime << "\n";
    }
}

void loadTasks(vector<Task>& list, const string& filename) {
    ifstream fin(filename);
    if (!fin) return;
    list.clear();
    Task t;
    while (getline(fin, t.name, '|')) {
        string prio;
        getline(fin, prio, '|');
        t.priority = stoi(prio);
        getline(fin, t.description, '|');
        getline(fin, t.dateTime);
        list.push_back(t);
    }
}

