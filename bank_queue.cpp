#include <iostream>
#include <queue>
#include <string>
#include <limits>

using namespace std;

int main() {
    queue<string> customers;
    int choice = 0;
    string name;

    do {
        cout << "\n===== BANK CUSTOMER QUEUE SYSTEM =====\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Waiting Customers\n";
        cout << "4. Display Number of Waiting Customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                getline(cin, name);

                if (name.empty()) {
                    cout << "Customer name cannot be empty.\n";
                } else {
                    customers.push(name);
                    cout << name << " has joined the queue.\n";
                }
                break;

            case 2:
                if (customers.empty()) {
                    cout << "No customers are waiting.\n";
                } else {
                    cout << "Now serving: " << customers.front() << '\n';
                    customers.pop();
                    cout << "Customer served successfully.\n";
                }
                break;

            case 3:
                if (customers.empty()) {
                    cout << "The queue is empty.\n";
                } else {
                    queue<string> temp = customers;
                    cout << "\nCustomers waiting:\n";
                    int position = 1;

                    while (!temp.empty()) {
                        cout << position << ". " << temp.front() << '\n';
                        temp.pop();
                        ++position;
                    }
                }
                break;

            case 4:
                cout << "Number of waiting customers: "
                     << customers.size() << '\n';
                break;

            case 5:
                cout << "Exiting the system. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
