#include "bhp1110_Seat.h"

string Seat::get_fabric()
{
    return fabric;
}

string Seat::get_seat_type()
{
    return seat_type;
}

void Seat::set_fabric(string f)
{
    fabric = f;
}

void Seat::set_seat_type(string st)
{
    seat_type = st;
}

std::string Seat::to_string()
{
    return type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + fabric + " " + seat_type;
}

