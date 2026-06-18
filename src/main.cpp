#include "../include/OrderBook.h"

int main()
{
    OrderBook book;

    book.addOrder(Order(1, Side::BUY, 100.5, 50));
    book.addOrder(Order(2, Side::SELL, 101.0, 30));

    book.printBook();

    return 0;
}