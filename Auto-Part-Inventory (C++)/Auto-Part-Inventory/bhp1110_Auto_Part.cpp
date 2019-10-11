#include "bhp1110_Auto_Part.h"

std::string Auto_Part::get_type()
{
	return type;
}

std::string Auto_Part::get_name()
{
	return name;
}

int Auto_Part::get_part_number()
{
	return part_number;
}

double Auto_Part::get_price()
{
	return price;
}

void Auto_Part::set_type(std::string t)
{
	type = t;
}

void Auto_Part::set_name(std::string n)
{
	name = n;
}

void Auto_Part::set_part_number(int pn)
{
	part_number = pn;
}

void Auto_Part::set_price(double p)
{
	price = p;
}

/*std::string Auto_Part::to_string()
{
	return type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price);
} */

bool Auto_Part::operator<(const Auto_Part& rhs)
{
	return this->part_number < rhs.part_number;
}

std::ostream& operator<<(std::ostream& ost, const Auto_Part& part)
{
	ost << "Type: " << part.type << " Name: " << part.name << " Part Number: " << part.part_number << " Price: " << part.price;
	return ost;
}
