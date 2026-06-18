#ifndef ORDER_H
#define ORDER_H

#include <string>

enum class Side {
    BUY,
    SELL
};

class Order {
public:
    int orderId;
    Side side;
    double price;
    int quantity;

    Order(int id, Side s, double p, int q);
};

#endif