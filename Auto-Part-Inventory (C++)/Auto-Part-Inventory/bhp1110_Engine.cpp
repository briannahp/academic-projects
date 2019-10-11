#include "bhp1110_Engine.h"

int Engine::get_num_cylinders()
{
	return num_cylinders;
}

std::string Engine::get_fuel_type()
{
	return fuel_type;
}

void Engine::set_num_cylinders(int nc)
{
	num_cylinders = nc;
}

void Engine::set_fuel_type(std::string ft)
{
	fuel_type = ft;
}

std::string Engine::to_string()
{
	return type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + std::to_string(num_cylinders) + " " + fuel_type;
}

std::ostream& operator<<(std::ostream& ost, const Engine& part)
{
	ost << "Type: " << part.type << " Name: " << part.name << " Part Number: " << part.part_number << " Price: " << part.price << " Number of Cylinders: " << part.num_cylinders << " Fuel Type: " << part.fuel_type;
	return ost;
}
