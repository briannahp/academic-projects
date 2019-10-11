#include "bhp1110_Dashboard.h"

string Dashboard::get_dashboard_model()
{
    return dashboard_model;
}

int Dashboard::get_dashboard_size()
{
    return dashboard_size;
}

void Dashboard::set_dashboard_model(string dm)
{
    dashboard_model = dm;
}

void Dashboard::set_dashboard_size(int ds)
{
    dashboard_size = ds;
}

std::string Dashboard::to_string()
{
    return type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + dashboard_model + " " + std::to_string(dashboard_size);
}
