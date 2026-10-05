#include <iostream>
using namespace std;

struct Coach
{
    int data;
    Coach *next;
};

int main()
{
    Coach *head = NULL;

    // Already existing coaches
    for (int i = 1; i <= 4; i++)
    {
        Coach *newCoach = new Coach;
        newCoach->data = i;
        newCoach->next = NULL;

        if (head == NULL)
            head = newCoach;
        else
        {
            Coach *temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newCoach;
        }
    }

    int choice, value;

    do
    {
        cout << "\n\n1. Add Coach at Beginning";
        cout << "\n2. Add Coach at End";
        cout << "\n3. Delete Coach";
        cout << "\n4. Display Coaches";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter coach number: ";
            cin >> value;

            Coach *newCoach = new Coach;
            newCoach->data = value;
            newCoach->next = head;
            head = newCoach;
        }

        else if (choice == 2)
        {
            cout << "Enter coach number: ";
            cin >> value;

            Coach *newCoach = new Coach;
            newCoach->data = value;
            newCoach->next = NULL;

            Coach *temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newCoach;
        }

        else if (choice == 3)
        {
            cout << "Enter coach number to delete: ";
            cin >> value;

            Coach *temp = head;
            Coach *prev = NULL;

            while (temp != NULL && temp->data != value)
            {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL)
                cout << "Coach not found";
            else
            {
                if (prev == NULL)
                    head = head->next;
                else
                    prev->next = temp->next;

                delete temp;
                cout << "Coach deleted";
            }
        }

        else if (choice == 4)
        {
            Coach *temp = head;

            while (temp != NULL)
            {
                cout << "Coach " << temp->data << " -> ";
                temp = temp->next;
            }

            cout << "NULL";
        }

    } while (choice != 5);

    return 0;
}
