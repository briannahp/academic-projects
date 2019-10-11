#ifndef BHP1110_WHEEL_H_INCLUDED
#define BHP1110_WHEEL_H_INCLUDED
#include "bhp1110_Auto_Part.h"

class Wheel : public virtual Auto_Part
{
	public:
		Wheel(std::string t="", std::string n="", int pn=0, double p=0.0, std::string cat="", std::string c="", int w_dia=0, int w_w=0, std::string bp="") : Auto_Part(t, n, pn, p), category(cat), color(c), wheel_diameter(w_dia), wheel_width(w_w), bolt_pattern(bp) {};
		std::string get_category();
		std::string get_color();
		int get_wheel_diameter();
		int get_wheel_width();
		std::string get_bolt_pattern();
		void set_category(std::string);
		void set_color(std::string);
		void set_wheel_diameter(int);
		void set_wheel_width(int);
		void set_bolt_pattern(std::string);
		std::string to_string();
		friend std::ostream& operator<<(std::ostream&, const Wheel&);

	protected:
		std::string category;
		std::string color;
		int wheel_diameter;
		int wheel_width;
		std::string bolt_pattern;
};

#endif
