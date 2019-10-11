#include "bhp1110_Door.h"

string Door::get_door_color()
{
    return door_color;
}

string Door::get_window_tint()
{
    return window_tint;
}

void Door::set_door_color(string dc)
{
    door_color = dc;
}

void Door::set_window_tint(string wt)
{
    window_tint = wt;
}

std::string Door::to_string()
{
    return type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + door_color + " " + window_tint;
}
