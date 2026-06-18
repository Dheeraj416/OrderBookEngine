#ifndef MATCHINGENGINE_H
#define MATCHINGENGINE_H

#include "OrderBook.h"

class MatchingEngine
{
private:
    OrderBook& orderBook;

public:
    MatchingEngine(OrderBook& ob);

    void matchOrders();
};

#endif