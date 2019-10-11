#ifndef BHP1110_FRAME_H_INCLUDED
#define BHP1110_FRAME_H_INCLUDED
#include "bhp1110_Auto_Part.h"

class Frame : public Auto_Part
{
	public:
		Frame(std::string t="", std::string n="", int pn=0, double p=0.0, std::string ft="") : Auto_Part(t,n,pn,p), frame_type(ft) {};
		std::string get_frame_type();
		void set_frame_type(std::string);
		std::string to_string();
		friend std::ostream& operator<< (std::ostream&, const Frame&);
	private:
		std::string frame_type;
};

#endif
