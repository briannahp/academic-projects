#ifndef BHP1110_ORDER_H_INCLUDED
#define BHP1110_ORDER_H_INCLUDED
#include <map>
#include <iostream>
using namespace std;


class Order{

public:
    Order() {};
    string get_customer();
    string get_address();
    string get_billInfo();
    int get_orderNum();
    string get_orderStatus();
    void insert_part(int, int);
    void set_customer(string);
    void set_address(string);
    void set_billInfo(string);
    void set_orderStatus(string);
    void set_orderNum(int);
    map<int,int> get_map();
protected:
    string customer;
    string address;
    string billInfo;
    int orderNum;
    string orderStatus;
    map<int, int> orders;
};

#endif // BHP1110_ORDER_H_INCLUDED
