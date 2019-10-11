#include "bhp1110_View.h"

int View::get_menu()
{
	std::string menu = R"(
============================
CSE 1325 Auto Part Inventory
============================

1) View All Parts
2) Create new part
3) Add to existing Part(s)
4) Remove Part(s)
5) Load from file
6) Save to file
0) Exit

?)";

	std::string result = Dialog::input(menu, "Menu", "", "0");
	std::istringstream iss(result);
	int cmd;
	iss >> cmd;
	return cmd;
}

void View::filled_prompt()
{
    Dialog::message("Order was successfully filled.", "");
}

void View::rejected_prompt()
{
    Dialog::message("Order was rejected. Parts not in stock.", "");
}

void View::exit_prompt()
{
	Dialog::message("Thank you for your time.", "Terminating Program...");

}

void View::invalid_option()
{
	Dialog::message("ERROR", "Invalid option selected.");
}

void View::view_all_inventory()
{
    string title = "*****Auto Part Inventory*****";
    string data = invent.to_stringi();

    Dialog::message(data, title);

	//cout << invent.to_stringi();
}

void View::seat_message()
{
    Dialog::message("You will now enter the seat information.", "");
}

void View::wtc_message()
{
    Dialog::message("You will now enter the wheel-tire-combo information.", "");
}

void View::dashboard_message()
{
    Dialog::message("You will now enter the dashboard information.", "");
}

void View::battery_message()
{
    Dialog::message("You will now enter the battery information.", "");
}

void View::sw_message()
{
    Dialog::message("You will now enter the steering wheel information.", "");
}

void View::engine_message()
{
    Dialog::message("You will now enter the engine information.", "");
}

void View::frame_message()
{
    Dialog::message("You will now enter the frame information.", "");
}

void View::door_message()
{
    Dialog::message("You will now enter the door information.", "");
}

void View::view_all_cars()
{
    string title = "*****Car Inventory*****";
    string data = invent.display_cars();

    Dialog::message(data, title);
}

int View::quantity_prompt()
{
	string prompt = R"(
Please enter the quantity.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int q;
	iss >> q;
	return q;
}

int View::pn_prompt()
{
	string prompt = R"(
Please enter the part number.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int pn;
	iss >> pn;
	return pn;
}

int View::what_type_prompt()
{
    string typeMenu = R"(
What type of Auto Part
would you like to add?

============================
      Auto-Part Types
============================

1) Tire
2) Wheel
3) Wheel-Tire Combo
4) Engine
5) Frame
6) Battery
7) Windshield Wiper
8) Seat
9) Dashboard
10) Steering Wheel
11) Door

?)";

    std::string result = Dialog::input(typeMenu, "Auto-Part Selection", "", "0");
	std::istringstream iss(result);
	int cmd;
	iss >> cmd;
	return cmd;

}

string View::frame_type_prompt()
{
    string prompt = R"(
Please enter the frame-type.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string ft;
	iss >> ft;
	return ft;
}

void View::save_prompt()
{
    Dialog::message(" ", "Data will now be saved as bhp1110_save_file.txt.");

}

string View::load_prompt()
{
    string prompt = R"(
Please enter the file name including the extension.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string fn;
	iss >> fn;
	return fn;
}

string View::dm_prompt()
{
    string prompt = R"(
Please enter the dashboard model.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string dm;
	iss >> dm;
	return dm;
}

int View::ds_prompt()
{
    string prompt = R"(
Please enter the dashboard size.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int ds;
	iss >> ds;
	return ds;
}

string View::swc_prompt()
{
    string prompt = R"(
Please enter the steering wheel color.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string swc;
	iss >> swc;
	return swc;
}

int View::swd_prompt()
{
     string prompt = R"(
Please enter the steering wheel diameter.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int swd;
	iss >> swd;
	return swd;
}

string View::type_prompt()
{
    string prompt = R"(
Please enter the type.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string t;
	iss >> t;
	return t;
}

string View::name_prompt()
{
    string prompt = R"(
Please enter the name.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string n;
	iss >> n;
	return n;
}

double View::price_prompt()
{
    string prompt = R"(
Please enter the price.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	double p;
	iss >> p;
	return p;
}

int View::length_prompt()
{
    string prompt = R"(
Please enter the length.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int l;
	iss >> l;
	return l;
}

int View::nc_prompt()
{
    string prompt = R"(
Please enter the number of cylinders.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int nc;
	iss >> nc;
	return nc;
}

string View::fuel_type_prompt()
{
    string prompt = R"(
Please enter the fuel type.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string ft;
	iss >> ft;
	return ft;
}

string View::lr_prompt()
{
    string prompt = R"(
Please enter the load range.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string lr;
	iss >> lr;
	return lr;
}

string View::sr_prompt()
{
    string prompt = R"(
Please enter the speed rating.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string sr;
	iss >> sr;
	return sr;
}

string View::tt_prompt()
{
    string prompt = R"(
Please enter the tire type.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string tt;
	iss >> tt;
	return tt;
}

int View::diameter_prompt()
{
    string prompt = R"(
Please enter the tire diameter.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int d;
	iss >> d;
	return d;
}

int View::width_prompt()
{
    string prompt = R"(
Please enter the tire width.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int w;
	iss >> w;
	return w;
}

int View::ratio_prompt()
{
    string prompt = R"(
Please enter the ratio.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int r;
	iss >> r;
	return r;
}

int View::rcm_prompt()
{
    string prompt = R"(
Please enter the reserve capacity minutes.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int rcm;
	iss >> rcm;
	return rcm;
}

int View::v_prompt()
{
    string prompt = R"(
Please enter the voltage.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int v;
	iss >> v;
	return v;
}

int View::ca_prompt()
{
    string prompt = R"(
Please enter the cranking amps.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int ca;
	iss >> ca;
	return ca;
}

int View::cca_prompt()
{
    string prompt = R"(
Please enter the cold cranking amps.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int cca;
	iss >> cca;
	return cca;
}

string View::cat_prompt()
{
  string prompt = R"(
Please enter the category.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string cat;
	iss >> cat;
	return cat;
}

string View::c_prompt()
{
  string prompt = R"(
Please enter the color.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string c;
	iss >> c;
	return c;
}

string View::wt_prompt()
{
    string prompt = R"(
Please enter the window tint.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string wt;
	iss >> wt;
	return wt;
}

string View::dc_prompt()
{
    string prompt = R"(
Please enter the door color.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string dc;
	iss >> dc;
	return dc;
}

string View::f_prompt()
{
    string prompt = R"(
Please enter the fabric.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string f;
	iss >> f;
	return f;
}

string View::st_prompt()
{
    string prompt = R"(
Please enter the seat type.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string st;
	iss >> st;
	return st;
}

string View::bp_prompt()
{
  string prompt = R"(
Please enter the bolt pattern.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string bp;
	iss >> bp;
	return bp;
}

int View::wdiameter_prompt()
{
    string prompt = R"(
Please enter the wheel diameter.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int d;
	iss >> d;
	return d;
}

int View::wwidth_prompt()
{
    string prompt = R"(
Please enter the wheel width.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int w;
	iss >> w;
	return w;
}

int View::ordernum_prompt()
{
  string prompt = R"(
Please enter the order number.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int on;
	iss >> on;
	return on;
}

string View::customer_prompt()
{
  string prompt = R"(
Please enter the name of the customer (Use underscores for spaces e.g. Jane_Doe).)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string customer;
	iss >> customer;
	return customer;
}

string View::address_prompt()
{
  string prompt = R"(
Please enter the customer's address (Use underscores for spaces).)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string address;
	iss >> address;
	return address;
}

string View::billinfo_prompt()
{
  string prompt = R"(
Please enter the billing information (Use underscores for spaces).)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	string bi;
	iss >> bi;
	return bi;
}

int View::numparts_prompt()
{
  string prompt = R"(
Please enter the number of different auto-parts you'd like to order.)";

    std::string result = Dialog::input(prompt, " ", "", "0");
	std::istringstream iss(result);
	int parts;
	iss >> parts;
	return parts;
}
