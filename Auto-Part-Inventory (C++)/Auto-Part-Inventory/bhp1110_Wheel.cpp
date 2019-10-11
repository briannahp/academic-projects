#include "bhp1110_Wheel.h"

std::string Wheel::get_category()
{
	return category;
}

std::string Wheel::get_color()
{
	return color;
}

int Wheel::get_wheel_diameter()
{
	return wheel_diameter;
}

int Wheel::get_wheel_width()
{
	return wheel_width;
}

std::string Wheel::get_bolt_pattern()
{
	return bolt_pattern;
}

void Wheel::set_category(std::string cat)
{
	category = cat;
}

void Wheel::set_color(std::string c)
{
	color = c;
}

void Wheel::set_wheel_diameter(int w_dia)
{
	wheel_diameter = w_dia;
}

void Wheel::set_wheel_width(int w_w)
{
	wheel_width = w_w;
}

void Wheel::set_bolt_pattern(std::string bp)
{
	bolt_pattern = bp;
}

std::string Wheel::to_string()
{
	return type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + category + " " + color + " " + std::to_string(wheel_diameter) + " " + std::to_string(wheel_width) + " " + bolt_pattern;
}

std::ostream& operator<<(std::ostream& ost, const Wheel& part)
{
	ost << "Type: " << part.type << " Name: " << part.name << " Part Number: " << part.part_number << " Price: " << part.price << " Category: " << part.category << " Color: " << part.color << " Wheel Diameter: " << part.wheel_diameter << " Wheel Width: " << part.wheel_width << " Bolt Pattern: " << part.bolt_pattern;
	return ost;
}
