#include "bhp1110_Wheel_Tire_Combo.h"

std::string Wheel_Tire_Combo::to_string()
{
	return Wheel::to_string() + " " + tire_type + " " + std::to_string(width) + " " + std::to_string(ratio) + " " + std::to_string(diameter) + " " + speed_rating + " " + load_range;
}

std::ostream& operator<<(std::ostream& ost, const Wheel_Tire_Combo& part)
{
	ost << "Type: " << part.type << " Name: " << part.name << " Part Number: " << part.part_number << " Price: " << part.price << " Category: " << part.category << " Color: " << part.color << " Wheel Diameter: " << part.wheel_diameter << " Wheel Width: " << part.wheel_width << " Bolt Pattern: " << part.bolt_pattern << " Tire Type: " << part.tire_type << " Width: " << part.width << " Ratio: " << part.ratio << " Diameter: " << part.diameter << " Speed Rating: " << part.speed_rating << " Load Range: " << part.load_range;
}
