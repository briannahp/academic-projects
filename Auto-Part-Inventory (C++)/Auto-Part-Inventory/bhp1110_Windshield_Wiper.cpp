#include "bhp1110_Windshield_Wiper.h"

int Windshield_Wiper::get_length()
{
	return length;
}

std::string Windshield_Wiper::get_frame_type()
{
	return frame_type;
}

void Windshield_Wiper::set_length(int l)
{
	length = l;
}

void Windshield_Wiper::set_frame_type(std::string ft)
{
	frame_type = ft;
}

std::string Windshield_Wiper::to_string()
{
	return type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + std::to_string(length) + " " + frame_type;
}

std::ostream& operator<<(std::ostream& ost, const Windshield_Wiper& part)
{
	ost << "Type: " << part.type << " Name: " << part.name << " Part Number: " << part.part_number << " Price: " << part.price << " Length: " << part.length << " Frame Type: " << part.frame_type;
}
