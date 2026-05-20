#pragma once
#include <string>
#include <vector>
using namespace std;

struct Task {
    string name;
    int priority;
    string description;
    string dateTime;
};

void addTask(vector<Task>& list);
void showTasks(const vector<Task>& list);
void deleteTask(vector<Task>& list, int index);
void editTask(vector<Task>& list, int index);
void searchTask(const vector<Task>& list);
void sortTasks(vector<Task>& list);
void filterTasks(const vector<Task>& list, int mode);

void saveTasks(const vector<Task>& list, const string& filename);
void loadTasks(vector<Task>& list, const string& filename);
