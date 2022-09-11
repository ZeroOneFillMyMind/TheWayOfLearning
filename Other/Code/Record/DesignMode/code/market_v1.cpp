#include <iostream>

class object;
class EventArgs;

double total{0.0d};

#if 0
class Market {
private:
    double txtPrice;
    int txtNum;

public:
    void btnOk_Click(object sender, EventArgs e) {
        double totalPrices = txtPrice * txtNum;

        total+=totalPrices;
    }
};

#endif

