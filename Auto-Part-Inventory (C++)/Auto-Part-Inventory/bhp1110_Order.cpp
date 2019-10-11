#include "bhp1110_Order.h"

string Order::get_address()
{
    return address;
}

string Order::get_billInfo()
{
    return billInfo;
}

string Order::get_customer()
{
    return customer;
}

int Order::get_orderNum()
{
    return orderNum;
}

string Order::get_orderStatus()
{
    return orderStatus;
}

void Order::insert_part(int pn, int quantity)
{
    orders.insert(std::pair<int,int>(pn, quantity));
}

void Order::set_customer(string cust)
{
    customer = cust;
}

void Order::set_address(string a)
{
    address = a;
}

void Order::set_billInfo(string bi)
{
    billInfo = bi;
}

void Order::set_orderStatus(string status)
{
    orderStatus = status;
}

void Order::set_orderNum(int on)
{
    orderNum = on;
}

map<int,int> Order::get_map()
{
    return orders;
}
