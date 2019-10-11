#include "bhp1110_Car.h"

Engine Car::get_engine()
{
    return engine;
}

void Car::set_engine(Engine e)
{
    engine = e;
}

std::string Car::to_string()
{
    return "~~Engine~~\n" + engine.to_string() + "\n~~Frame~~\n" + frame.to_string() + "\n~~Battery~~\n" + battery.to_string() +
    "\n~~Door~~\n" + door.to_string() + "\n~~Dashboard~~\n" + dashboard.to_string() + "\n~~Wheel-Tire-Combo~~\n" + wtc.to_string() + "\n~~Steering Wheel~~\n" + sw.to_string();
}

Frame Car::get_frame()
{
    return frame;
}

void Car::set_frame(Frame f)
{
    frame = f;
}

Door Car::get_door()
{
    return door;
}

void Car::set_door(Door d)
{
    door = d;
}

Wheel_Tire_Combo Car::get_wtc()
{
    return wtc;
}

void Car::set_wtc(Wheel_Tire_Combo wc)
{
    wtc = wc;
}

Dashboard Car::get_dashboard()
{
    return dashboard;
}

void Car::set_dashboard(Dashboard dash)
{
    dashboard = dash;
}

Seat Car::get_seat()
{
    return seat;
}

void Car::set_seat(Seat s)
{
    seat = s;
}

Steering_Wheel Car::get_steering_wheel()
{
    return sw;
}

void Car::set_steering_wheel(Steering_Wheel swh)
{
    sw = swh;
}

Battery Car::get_battery()
{
    return battery;
}

void Car::set_battery(Battery b)
{
    battery = b;
}
