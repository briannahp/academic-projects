#ifndef BHP1110_CAR_H_INCLUDED
#define BHP1110_CAR_H_INCLUDED
#include "bhp1110_Wheel_Tire_Combo.h"
#include "bhp1110_Door.h"
#include "bhp1110_Steering_Wheel.h"
#include "bhp1110_Frame.h"
#include "bhp1110_Dashboard.h"
#include "bhp1110_Seat.h"
#include "bhp1110_Engine.h"
#include "bhp1110_Battery.h"

class Car
{
public:
    Car() {};
    Engine get_engine();
    void set_engine(Engine);
    Frame get_frame();
    void set_frame(Frame);
    Steering_Wheel get_steering_wheel();
    void set_steering_wheel(Steering_Wheel);
    Battery get_battery();
    void set_battery(Battery);
    Wheel_Tire_Combo get_wtc();
    void set_wtc(Wheel_Tire_Combo);
    Seat get_seat();
    void set_seat(Seat);
    Dashboard get_dashboard();
    void set_dashboard(Dashboard);
    Door get_door();
    void set_door(Door);
    std::string to_string();
protected:
    Engine engine;
    Frame frame;
    Steering_Wheel sw;
    Battery battery;
    Wheel_Tire_Combo wtc;
    Seat seat;
    Dashboard dashboard;
    Door door;
};



#endif // BHP1110_CAR_H_INCLUDED
