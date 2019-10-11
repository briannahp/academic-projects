#include "bhp1110_Auto_Part.h"

class Tire : public virtual Auto_Part
{
	public:
		Tire(std::string t="", std::string n="", int pn=0, double p=0.0, std::string tt="", int w=0, int r=0, int dia=0, std::string sr="", std::string lr="") : Auto_Part(t, n, pn, p), tire_type(tt), width(w), ratio(r), diameter(dia), speed_rating(sr), load_range(lr) {};
		std::string get_tire_type();
		int get_width();
		int get_ratio();
		int get_diameter();
		std::string get_speed_rating();
		std::string get_load_range();
		void set_tire_type(std::string);
		void set_width(int);
		void set_ratio(int);
		void set_diameter(int);
		void set_speed_rating(std::string);
		void set_load_range(std::string);
		std::string to_string();
		friend std::ostream& operator<<(std::ostream&, const Tire&);
	protected:
		std::string tire_type;
		int width;
		int ratio;
		int diameter;
		std::string speed_rating;
		std::string load_range;
};
