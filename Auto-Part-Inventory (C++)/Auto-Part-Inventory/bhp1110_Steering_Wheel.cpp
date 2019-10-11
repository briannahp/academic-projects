#include "bhp1110_Steering_Wheel.h"

string Steering_Wheel::get_sw_color()
{
    return sw_color;
}

int Steering_Wheel::get_sw_diameter()
{
    return sw_diameter;
}

void Steering_Wheel::set_sw_color(string swc)
{
    sw_color = swc;
}

void Steering_Wheel::set_sw_diameter(int swd)
{
    sw_diameter = swd;
}

std::string Steering_Wheel::to_string()
{
    return type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + sw_color + " " + std::to_string(sw_diameter);
}
