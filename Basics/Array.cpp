#include <iostream>
using namespace std;

int main () {
    int marks[] = {11,21,83,24,45};
    // int array[5];
    int n = sizeof(marks)/ sizeof(int);

    // cout << "Enter Nos." << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> array[i];
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << array[i] << ",";
    // }
    
    int max = marks[0];
    for (int i = 0; i < n; i++)
    {
        if (marks[i] > max)
        {
            max = marks[i];
        }
        
    }
    
    cout << max <<endl;
    
    // cout << n << endl;
}