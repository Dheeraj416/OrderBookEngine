#include "../include/OrderBook.h"
#include <iostream>
#include <algorithm>

void OrderBook::addOrder(const Order& order)
{
    if(order.side == Side::BUY)
        buyOrders.push_back(order);
    else
        sellOrders.push_back(order);
}

void OrderBook::cancelOrder(int orderId)
{
    buyOrders.erase(
        std::remove_if(
            buyOrders.begin(),
            buyOrders.end(),
            [orderId](const Order& o)
            {
                return o.orderId == orderId;
            }),
        buyOrders.end());

    sellOrders.erase(
        std::remove_if(
            sellOrders.begin(),
            sellOrders.end(),
            [orderId](const Order& o)
            {
                return o.orderId == orderId;
            }),
        sellOrders.end());
}

void OrderBook::printBook() const
{
    std::cout << "\nBUY ORDERS\n";

    for(const auto& order : buyOrders)
    {
        std::cout
            << order.orderId
            << " "
            << order.price
            << " "
            << order.quantity
            << "\n";
    }

    std::cout << "\nSELL ORDERS\n";

    for(const auto& order : sellOrders)
    {
        std::cout
            << order.orderId
            << " "
            << order.price
            << " "
            << order.quantity
            << "\n";
    }
}

std::vector<Order>& OrderBook::getBuyOrders()
{
    return buyOrders;
}

std::vector<Order>& OrderBook::getSellOrders()
{
    return sellOrders;
}