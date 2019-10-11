#include "bhp1110_Battery.h"

int Battery::get_cranking_amps()
{
	return cranking_amps;
}

int Battery::get_cold_cranking_amps()
{
	return cold_cranking_amps;
}

int Battery::get_voltage()
{
	return voltage;
}

int Battery::get_reserve_capacity_minutes()
{
	return reserve_capacity_minutes;
}

void Battery::set_cranking_amps(int ca)
{
	cranking_amps = ca;
}

std::string Battery::to_string()
{
	return type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + std::to_string(cranking_amps) + " " + std::to_string(cold_cranking_amps) + " " + std::to_string(voltage) + " " + std::to_string(reserve_capacity_minutes);
}

std::ostream& operator<<(std::ostream& ost, const Battery& part)
{
	ost << "Type: " << part.type << " Name: " << part.name << " Part Number: " << part.part_number << " Price: " << part.price << " Cranking Amps: " << part.cranking_amps << " Cold Cranking Amps: " << part.cold_cranking_amps << " Voltage: " << part.voltage << " Resere Capacity Minutes: " << part.reserve_capacity_minutes;
	return ost;
}
