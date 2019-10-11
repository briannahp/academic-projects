#ifndef AUTO_PART
#define AUTO_PART
#include <iostream>
using namespace std;

class Auto_Part
{
	public:
		Auto_Part(std::string t="", std::string n="", int pn=0, double p=0.0) : type(t), name(n), part_number(pn), price(p) {};
		std::string get_type();
		std::string get_name();
		int get_part_number();
		double get_price();
		void set_type(std::string);
		void set_name(std::string);
		void set_part_number(int);
		void set_price(double);
		virtual std::string to_string() = 0;
		bool operator<(const Auto_Part&);
		friend std::ostream& operator<<(std::ostream&, const Auto_Part&);

	protected:
		std::string type;
		std::string name;
		int part_number;
		double price;
};

#endif
