#include "task.h"
#include <iostream>
using namespace std;

int main() {
    vector<Task> tasks;
    loadTasks(tasks, "tasks.txt"); 

    int choice;
    do {
        cout << "\n1. Add\n2. Show\n3. Delete\n4. Edit\n5. Search\n6. Sort\n7. Filter\n8. Save\n0. Exit\n> ";
        cin >> choice; cin.ignore();

        switch (choice) {
        case 1: addTask(tasks); break;
        case 2: showTasks(tasks); break;
        case 3: { int i; cout << "Number: "; cin >> i; cin.ignore(); deleteTask(tasks, i - 1); } break;
        case 4: { int i; cout << "Number: "; cin >> i; cin.ignore(); editTask(tasks, i - 1); } break;
        case 5: searchTask(tasks); break;
        case 6: sortTasks(tasks); break;
        case 7: { int m; cout << "1=day,2=week,3=month: "; cin >> m; cin.ignore(); filterTasks(tasks, m); } break;
        case 8: saveTasks(tasks, "tasks.txt"); break;
        }
    } while (choice != 0);

    saveTasks(tasks, "tasks.txt"); 
}
