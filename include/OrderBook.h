#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "Order.h"
#include <vector>

class OrderBook {
private:
    std::vector<Order> buyOrders;
    std::vector<Order> sellOrders;

public:
    void addOrder(const Order& order);
    void cancelOrder(int orderId);
    void printBook() const;

    std::vector<Order>& getBuyOrders();
    std::vector<Order>& getSellOrders();
};

#endif