#include "bhp1110_Auto_Part.h"

class Windshield_Wiper : public Auto_Part
{
	public:
		Windshield_Wiper(std::string t="", std::string n="", int pn=0, double p=0.0, int l=0, std::string ft="") : Auto_Part(t, n, pn, p), length(l), frame_type(ft) {};
		int get_length();
		std::string get_frame_type();
		void set_length(int);
		void set_frame_type(std::string);
		std::string to_string();
		friend std::ostream& operator<<(std::ostream&, const Windshield_Wiper&);
	private:
		int length;
		std::string frame_type;
};
