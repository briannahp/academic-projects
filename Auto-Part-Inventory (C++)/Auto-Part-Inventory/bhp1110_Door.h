#ifndef BHP1110_DOOR_H_INCLUDED
#define BHP1110_DOOR_H_INCLUDED
#include "bhp1110_Auto_Part.h"

class Door : public Auto_Part
{
public:
    Door(string t = "", string n = "", int pn = 0, double p = 0.0, string dc = "", string wt = "") : Auto_Part(t,n,pn,p), door_color(dc), window_tint(wt) {};
    string get_door_color();
    string get_window_tint();
    void set_door_color(string);
    void set_window_tint(string);
    std::string to_string();
private:
    string door_color;
    string window_tint;
};


#endif // BHP1110_DOOR_H_INCLUDED
