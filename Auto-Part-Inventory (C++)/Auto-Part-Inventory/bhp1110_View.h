#ifndef BHP1110_VIEW_H_INCLUDED
#define BHP1110_VIEW_H_INCLUDED
#include "bhp1110_Inventory.h"
#include "bhp1110_Dialog.h"
class View
{
	public:
		View(Inventory& inv) : invent(inv) {};
		int get_menu();
		void exit_prompt();
		void invalid_option();
		void view_all_inventory();
		void filled_prompt();
		void rejected_prompt();
		int pn_prompt();
		string name_prompt();
		string fuel_type_prompt();
		void view_all_cars();
		void engine_message();
		void wtc_message();
		void frame_message();
		void battery_message();
		void sw_message();
		void door_message();
		void seat_message();
		void dashboard_message();
		string dm_prompt();
		int ds_prompt();
		int nc_prompt();
		string tt_prompt();
		string f_prompt();
		string st_prompt();
		string lr_prompt();
		string sr_prompt();
		int width_prompt();
		int diameter_prompt();
		int ratio_prompt();
		double price_prompt();
		string type_prompt();
		string frame_type_prompt();
		string dc_prompt();
		string wt_prompt();
		int length_prompt();
		int quantity_prompt();
		int ca_prompt();
		int cca_prompt();
		int swd_prompt();
		string swc_prompt();
		int v_prompt();
		int rcm_prompt();
		int wdiameter_prompt();
		int wwidth_prompt();
		string cat_prompt();
		string c_prompt();
		string bp_prompt();
		int what_type_prompt();
		void save_prompt();
		string load_prompt();
		string customer_prompt();
		string address_prompt();
		int ordernum_prompt();
		int numparts_prompt();
		string billinfo_prompt();
	protected:
		Inventory& invent;
};


#endif
