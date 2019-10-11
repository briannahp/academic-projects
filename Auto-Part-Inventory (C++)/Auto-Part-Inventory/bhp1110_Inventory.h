#include "bhp1110_Wheel_Tire_Combo.h"
#include "bhp1110_Battery.h"
#include "bhp1110_Windshield_Wiper.h"
#include "bhp1110_Frame.h"
#include "bhp1110_Engine.h"
#include "bhp1110_Dialog.h"
#include "bhp1110_Seat.h"
#include "bhp1110_Dashboard.h"
#include "bhp1110_Car.h"
#include <map>
#include <fstream>
#include "bhp1110_Order.h"
#include "bhp1110_Steering_Wheel.h"
#include "bhp1110_Door.h"

class Inventory : public Order
{
	public:
		Inventory() {};
		void add_part(Auto_Part*);
		void add_parts(int, int);
		int get_num_parts(Auto_Part*);
		void remove_parts(int, int);
		void save_inventory();
		void clear_inventory();
		bool process_one_order(Order);
		void add_car(Car);
		string display_cars();
		void process_mult_order(string);
		bool inventory_check(int, int);
		bool inventory_check2(Order);
		string to_stringi();
		friend std::ostream& operator<< (std::ostream&, const Inventory&);
	private:
		std::map<Auto_Part*, int> inventory;
		vector<Car> myCars;
};
