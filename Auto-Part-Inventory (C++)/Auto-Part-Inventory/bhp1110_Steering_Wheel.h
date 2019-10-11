#ifndef BHP1110_STEERING_WHEEL_H_INCLUDED
#define BHP1110_STEERING_WHEEL_H_INCLUDED
#include "bhp1110_Auto_Part.h"
using namespace std;

class Steering_Wheel : public Auto_Part
{
public:
    Steering_Wheel(string t = "", string n = "", int pn = 0, double p = 0.0, string swc = "", int swd = 0) : Auto_Part(t,n,pn,p), sw_color(swc), sw_diameter(swd) {};
    string get_sw_color();
    int get_sw_diameter();
    void set_sw_color(string);
    void set_sw_diameter(int);
    std::string to_string();
private:
    string sw_color;
    int sw_diameter;
};

#endif
