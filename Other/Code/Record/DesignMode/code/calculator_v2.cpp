#include <iostream>
#include <climits>

class Operation {
private:
    double numA_;
    double numB_;
    char oper_;

    bool IsDevideZero(double num) {
        return num == 0;
    }

public:
    Operation(double numA, double numB, char oper) : numA_{numA}, numB_{numB}, oper_{oper}{}

    double GetResult() {
        double result;
        switch (oper_) {
            case '+':
                result = numA_ + numB_;
                break;

            case '-':
                result = numA_ - numB_;
                break;

            case '*':
                result = numA_ * numB_;
                break;

            case '/':
                if (IsDevideZero(numB_)) {
                    std::cout << "devide zero" << std::endl;
                    result = INT_MIN;
                    break;
                }
                result = numA_ / numB_;
                break;
            default:
                result = INT_MIN;
        }

        if (result == INT_MIN) {
            std::cout << "ERROR" << std::endl;
        }

        return result;
    }

};


int main()
{
    double numA,numB;
    char oper;

    std::cin >> numA >> numB >> oper;

    Operation op{numA, numB, oper};
    std::cout << op.GetResult() << std::endl;

    return 0;
}
