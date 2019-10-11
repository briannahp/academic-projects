#ifndef BHP1110_CONTROLLER_H_INCLUDED
#define BHP1110_CONTROLLER_H_INCLUDED

#include "bhp1110_View.h"
#include <fstream>
#include <sstream>

class Controller
{
	public:
		Controller(Inventory& inv, View& v) : inven(inv), view(v) {};
		void cli();
		void gui();
		void execute_cmd(int);
		void add_parts();
		void remove_parts();
		void add_new_part();
		void add_frame();
		void add_tire();
		void add_wheel();
		void new_car();
		void add_wtc();
		void add_battery();
		void add_steering_wheel();
		void add_door();
		void add_engine();
		void add_seat();
		void add_dashboard();
		void add_ww();
        void load_file();
        void view_parts();
        void save_inven();
        void one_order();
        void mult_order();
	protected:
		Inventory& inven;
		View& view;
		Order myorder;
};

#endif
