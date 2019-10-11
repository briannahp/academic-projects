#include "bhp1110_Frame.h"

std::string Frame::get_frame_type()
{
	return frame_type;
}

void Frame::set_frame_type(std::string ft)
{
	frame_type = ft;
}

std::string Frame::to_string()
{
	return type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + frame_type;
}

std::ostream& operator<< (std::ostream& ost, const Frame& part)

{
	ost << "Type: " << part.type << " Name: " << part.name << " Part Number: " << part.part_number << " Price: " << part.price << " Frame Type: " << part.frame_type;
	return ost;
}
