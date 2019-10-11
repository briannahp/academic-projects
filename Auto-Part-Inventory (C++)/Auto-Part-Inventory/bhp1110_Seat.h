#ifndef BHP1110_SEAT_H_INCLUDED
#define BHP1110_SEAT_H_INCLUDED

#include "bhp1110_Auto_Part.h"
using namespace std;

class Seat : public Auto_Part
{
public:
    Seat(string t = "", string n = "", int pn = 0, double p = 0.0, string f = "", string st = "") : Auto_Part(t,n,pn,p), fabric(f), seat_type(st) {};
    string get_fabric();
    string get_seat_type();
    void set_fabric(string);
    void set_seat_type(string);
    std::string to_string();
private:
    string fabric;
    string seat_type;
};


#endif // BHP1110_SEAT_H_INCLUDED
