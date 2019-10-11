#ifndef BHP1110_ENGINE_H_INCLUDED
#define BHP1110_ENGINE_H_INCLUDED
#include "bhp1110_Auto_Part.h"

class Engine : public Auto_Part
{
	public:
		Engine(std::string t="", std::string n="", int pn=0, double p=0.0, int nc=0, std::string ft="") : Auto_Part(t,n,pn,p), num_cylinders(nc), fuel_type(ft) {};
		int get_num_cylinders();
		std::string get_fuel_type();
		void set_num_cylinders(int);
		void set_fuel_type(std::string);
		std::string to_string();
		friend std::ostream& operator<< (std::ostream&, const Engine&);
	private:
		int num_cylinders;
		std::string fuel_type;
};

#endif
