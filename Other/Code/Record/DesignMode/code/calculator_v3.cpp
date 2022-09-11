#include <iostream>

class Operation {
private:
    double numA_{};
    double numB_{};
    char oper_{};

public:
    Operation(double A, double B, char C) : numA_(A), numB_(B), oper_(C) {}
    Operation() = default;

    double GetNumA() const {
        return numA_;
    }

    void SetNumA(double num) {
        numA_ = num;
    }

    double GetNumB() const {
        return numB_;
    }

    void SetNumB(double num) {
        numB_ = num;
    }

    virtual double GetResult() {
        return 0;
    }

};

class OperationAdd : public Operation {
public:
    OperationAdd(double A, double B) : Operation(A, B, '+') {}
    OperationAdd() = default;

    double GetResult() override {
        return GetNumA() + GetNumB();
    }
};

class OperationSub : public Operation {
public:
    OperationSub(double A, double B) : Operation(A, B, '-') {}
    OperationSub() = default;

    double GetResult() override {
        return GetNumA() - GetNumB();
    }
};

class OperationFactory {
public:
    static Operation* createOp(char op) {
        Operation *oper = nullptr;
        switch (op) {
            case '+':
                oper = new OperationAdd();
                break;
            case '-':
                oper = new OperationSub();
                break;
            default:
                break;
        }

        return oper;
    }
};
int main()
{
    OperationAdd add(1, 2);
    std::cout << add.GetResult() << std::endl;

    Operation *op = OperationFactory::createOp('+');
    op->SetNumA(1.2);
    op->SetNumB(2.4);
    std::cout << op->GetResult() << std::endl;
    return 0;
}