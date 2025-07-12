
#include <iostream>
#include <vector>
using namespace std;

int sum_of_multiples(int numberOne, int numberTwo, int numberBelow)
{
    int sum = 0;
    for (int i = 0; i < numberBelow; i++)
    {
        if( i % numberOne == 0 || i % numberTwo == 0)
        {
            cout << i << " ";
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int numberOne, numberTwo, numberBelow;
    cout << "Enter two numbers and a limit: ";
    cin >> numberOne >> numberTwo >> numberBelow;
    int result = sum_of_multiples(numberOne, numberTwo, numberBelow);
    cout << "\nSum of multiples: " << result << endl;

    return 0;
}