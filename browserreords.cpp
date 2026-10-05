#include <iostream>
using namespace std;

int main()
{
    string history[10];
    int top = -1;

    // Push visited pages
    history[++top] = "google.com";
    history[++top] = "youtube.com";
    history[++top] = "abcse.com";
    history[++top] = "facebook.com";

    // First Back
    top--;

    // Second Back
    top--;

    // Display current top page
    cout << "Current top page: " << history[top] << endl;

    return 0;
}
