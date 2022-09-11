#include <iostream>

using namespace std;

int main()
{
    int numA;
    int numB;
    char oper;
    int result;

    cout << "Please input NUM_A:" << endl;
    cin >> numA;
    cout << "Please input NUM_B:" << endl;
    cin >> numB;
    cout << "Please input op:" << endl;
    cin >> oper;

    switch (oper) {
        case '+':
            result = numA + numB;
            break;
        
        case '-':
            result = numA - numB;
            break;

        case '*':
            result = numA * numB;
            break;

        case '/':
            result = numA / numB;
            break;

        default:
            cout << "ERROR" << endl;
    }

    cout << "result: " << result << endl;
    return 0;
}
