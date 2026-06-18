#include "../include/Order.h"

Order::Order(int id, Side s, double p, int q)
{
    orderId = id;
    side = s;
    price = p;
    quantity = q;
}