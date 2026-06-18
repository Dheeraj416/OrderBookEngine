#include "../include/MatchingEngine.h"

int main()
{
    OrderBook book;

    book.addOrder(Order(1, Side::BUY, 100, 50));
    book.addOrder(Order(2, Side::BUY, 99, 25));

    book.addOrder(Order(3, Side::SELL, 100, 30));
    book.addOrder(Order(4, Side::SELL, 101, 20));

    std::cout << "\nBEFORE MATCHING\n";
    book.printBook();

    MatchingEngine engine(book);

    engine.matchOrders();

    std::cout << "\nAFTER MATCHING\n";
    book.printBook();

    return 0;
}