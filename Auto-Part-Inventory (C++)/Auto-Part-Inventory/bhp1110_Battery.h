#ifndef BHP1110_BATTERY_H_INCLUDED
#define BHP1110_BATTERY_H_INCLUDED
#include "bhp1110_Auto_Part.h"

class Battery : public Auto_Part
{
	public:
		Battery(std::string t="", std::string n="", int pn=0, double p=0.0, int ca=0, int cca=0, int v=0, int rcm=0) : Auto_Part(t, n, pn, p), cranking_amps(ca), cold_cranking_amps(cca), voltage(v), reserve_capacity_minutes(rcm) {};
		int get_cranking_amps();
		int get_cold_cranking_amps();
		int get_voltage();
		int get_reserve_capacity_minutes();
		void set_cranking_amps(int);
		void set_cold_cranking_amps(int);
		void set_voltage(int);
		void set_reserve_capacity_minutes(int);
		std::string to_string();
		friend std::ostream& operator<<(std::ostream&, const Battery&);
	private:
		int cranking_amps;
		int cold_cranking_amps;
		int voltage;
		int reserve_capacity_minutes;
};

#endif
