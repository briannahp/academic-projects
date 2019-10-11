#ifndef BHP1110_WHEEL_TIRE_COMBO_H_INCLUDED
#define BHP1110_WHEEL_TIRE_COMBO_H_INCLUDED

#include "bhp1110_Wheel.h"
#include "bhp1110_Tire.h"

class Wheel_Tire_Combo : public Tire, public Wheel
{
	public:
		Wheel_Tire_Combo(std::string t="", std::string n="", int pn=0, double p=0.0, std::string cat="", std::string c="", int w_dia=0, int w_w=0, std::string bp="",std::string tt="", int w=0, int r=0, int dia=0, std::string sr="", std::string lr="") : Auto_Part(t, n, pn, p), Wheel(t, n, pn, p, cat, c, w_dia, w_w, bp), Tire(t, n, pn, p, tt, w, r, dia, sr, lr) {};
		std::string to_string();
		friend std::ostream& operator<<(std::ostream&, const Wheel_Tire_Combo&);

	private:
};

#endif
