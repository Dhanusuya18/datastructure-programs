#include <iostream>
#include <string>
using namespace std;

#define MAX 20

class listarray
{
public:
    string b[MAX];
    string item;
    int n, i, pos, flag;

    void create();
    void insertion();
    void deletion();
    void search();
    void display();
};

void listarray::create()
{
    cout << "Enter no of items: ";
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cout << "Enter the item: ";
        cin >> b[i];
    }
}

void listarray::insertion()
{
    cout << "Enter the position to insert: ";
    cin >> pos;

    if(pos < 1 || pos > n + 1)
    {
        cout << "Invalid location";
        return;
    }

    for(i = n; i >= pos; i--)
    {
        b[i] = b[i - 1];
    }

    cout << "Enter the item to insert: ";
    cin >> item;

    b[pos - 1] = item;
    n++;

    cout << "Item added successfully";
}

void listarray::deletion()
{
    cout << "Enter the position to delete: ";
    cin >> pos;

    if(pos < 1 || pos > n)
    {
        cout << "Invalid location";
        return;
    }

    for(i = pos - 1; i < n - 1; i++)
    {
        b[i] = b[i + 1];
    }

    n--;

    cout << "Item removed successfully";
}

void listarray::search()
{
    flag = 0;

    cout << "Enter the item to search: ";
    cin >> item;

    for(i = 0; i < n; i++)
    {
        if(b[i] == item)
        {
            flag = 1;
            cout << "Item found at position: " << i + 1;
            break;
        }
    }

    if(flag == 0)
    {
        cout << "Item not found";
    }
}

void listarray::display()
{
    cout << "\nThe items in the shopping list are:\n";

    for(i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << b[i] << endl;
    }
}

int main()
{
    listarray l;
    int ch;

    do
    {
        cout << "\n\n1. Store item in shopping list";
        cout << "\n2. Add an item";
        cout << "\n3. Remove an item";
        cout << "\n4. Search an item";
        cout << "\n5. Display an item";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                l.create();
                break;

            case 2:
                l.insertion();
                break;

            case 3:
                l.deletion();
                break;

            case 4:
                l.search();
                break;

            case 5:
                l.display();
                break;

            case 6:
                cout << "Exit";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(ch != 6);

    return 0;
}
