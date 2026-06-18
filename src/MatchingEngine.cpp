#include "../include/MatchingEngine.h"
#include <iostream>

MatchingEngine::MatchingEngine(OrderBook& ob)
    : orderBook(ob)
{
}

void MatchingEngine::matchOrders()
{
    auto& buys = orderBook.getBuyOrders();
    auto& sells = orderBook.getSellOrders();

    for(auto buyIt = buys.begin(); buyIt != buys.end();)
    {
        bool matched = false;

        for(auto sellIt = sells.begin(); sellIt != sells.end();)
        {
            if(buyIt->price >= sellIt->price)
            {
                int tradedQty =
                    std::min(
                        buyIt->quantity,
                        sellIt->quantity);

                std::cout
                    << "TRADE EXECUTED | "
                    << tradedQty
                    << " @ "
                    << sellIt->price
                    << std::endl;

                buyIt->quantity -= tradedQty;
                sellIt->quantity -= tradedQty;

                if(sellIt->quantity == 0)
                    sellIt = sells.erase(sellIt);
                else
                    ++sellIt;

                if(buyIt->quantity == 0)
                {
                    buyIt = buys.erase(buyIt);
                    matched = true;
                    break;
                }

                matched = true;
            }
            else
            {
                ++sellIt;
            }
        }

        if(!matched)
            ++buyIt;
    }
}