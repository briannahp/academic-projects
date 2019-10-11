#ifndef BHP1110_DASHBOARD_H_INCLUDED
#define BHP1110_DASHBOARD_H_INCLUDED
#include "bhp1110_Auto_Part.h"

class Dashboard : public Auto_Part
{

public:
    Dashboard(string t = "", string n = "", int pn = 0, double p = 0.0, string dm = "", int ds = 0) : Auto_Part(t,n,pn,p), dashboard_model(dm), dashboard_size(ds) {};
    string get_dashboard_model();
    int get_dashboard_size();
    void set_dashboard_model(string);
    void set_dashboard_size(int);
    std::string to_string();
private:
    string dashboard_model;
    int dashboard_size;

};

#endif // BHP1110_DASHBOARD_H_INCLUDED
