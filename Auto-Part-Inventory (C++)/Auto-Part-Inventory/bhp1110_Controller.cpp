#include "bhp1110_Controller.h"

void Controller::cli()
{
	int cmd = 0;
	do{
		//std::cout << view.get_menu();
		std::cin >> cmd;
		execute_cmd(cmd);
	}while(cmd != 0);
}

void Controller::gui()
{
	int cmd = -1;
	do{
	cmd = view.get_menu();
	execute_cmd(cmd);
	}while(cmd > 0);
}

void Controller::execute_cmd(int cmd)
{
	switch(cmd)
	{
		case 1:
			view.view_all_inventory();
			break;
		case 2:
			add_new_part();
			break;
		case 3:
			add_parts();
			break;
		case 4:
		    remove_parts();
			break;
		case 5:
            load_file();
			break;
        case 6:
            view.save_prompt();
            inven.save_inventory();
            break;
		case 0:
			view.exit_prompt();
			break;
		default:
			view.invalid_option();
			break;
	}
}

void Controller::add_parts()
{
	int part_number;
	int quantity;
	part_number = view.pn_prompt();
	quantity = view.quantity_prompt();
	inven.add_parts(part_number, quantity);
}

void Controller::remove_parts()
{
	int part_number;
	int quantity;
	part_number = view.pn_prompt();
	quantity = view.quantity_prompt();

	inven.remove_parts(part_number, quantity);

}

void Controller::add_new_part()
{
    int option;
    option = view.what_type_prompt();

    switch (option)
    {
    case 1: add_tire();
        break;
    case 2: add_wheel();
        break;
    case 3: add_wtc();
        break;
    case 4: add_engine();
        break;
    case 5: add_frame();
        break;
    case 6: add_battery();
        break;
    case 7: add_ww();
        break;
    case 8: add_seat();
        break;
    case 9: add_dashboard();
        break;
    case 10: add_steering_wheel();
        break;
    case 11: add_door();
        break;
    default: view.invalid_option();
    }
}

void Controller::add_frame()
{
    string ft, t, n;
    int pn;
    double p;

    ft = view.frame_type_prompt();
    pn = view.pn_prompt();
    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();

    Auto_Part* frame = new Frame(t,n,pn,p,ft);

    inven.add_part(frame);
}

void Controller::add_steering_wheel()
{
    string swc, t, n;
    int pn, swd;
    double p;

    swc = view.swc_prompt();
    swd = view.swd_prompt();
    pn = view.pn_prompt();
    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();

    Auto_Part* sw = new Steering_Wheel(t,n,pn,p,swc,swd);

    inven.add_part(sw);
}

void Controller::add_engine()
{
    string ft, t, n;
    int pn, nc;
    double p;

    t = view.type_prompt();
    n = view.name_prompt();
    pn = view.pn_prompt();
    p = view.price_prompt();
    nc = view.nc_prompt();
    ft = view.fuel_type_prompt();

    Auto_Part* engine = new Engine(t,n,pn,p,nc,ft);

    inven.add_part(engine);
}

void Controller::add_dashboard()
{
    string dm, t, n;
    int pn, ds;
    double p;

    t = view.type_prompt();
    n = view.name_prompt();
    pn = view.pn_prompt();
    p = view.price_prompt();
    dm = view.dm_prompt();
    ds = view.ds_prompt();

    Auto_Part* dashboard = new Dashboard(t,n,pn,p,dm,ds);

    inven.add_part(dashboard);
}
void Controller::load_file()
{
    ifstream loadfile;
    string fileName, c, cat, type, name, bp, framet, fuelt,lr,sr, tt, currentline, f, st, dm, swc, wt, dc;
    int cca, ca, r, ww, wdia, w, dia, v, rcm, nc, pn, l, stock, ds, swd;
    double p;

    inven.clear_inventory();

    fileName = view.load_prompt();

    loadfile.open(fileName);

    while (getline(loadfile, currentline))
    {
        stringstream templine;
        templine << currentline;
        templine >> type;

        if (type == "tire")
        {
            templine >> name >> pn >> p >> tt >> w >> r >> dia >> sr >> lr;
            Auto_Part* tire = new Tire(type, name, pn, p, tt, w, r, dia, sr, lr);
            inven.add_part(tire);
            templine >> stock;
            inven.add_parts(pn, stock-1);
        }
        if (type == "wheel")
        {
            templine >> name >> pn >> p >> cat >> c >> wdia >> ww >> bp;
            Auto_Part* wheel = new Wheel(type, name, pn, p, cat, c, wdia, ww, bp);
            inven.add_part(wheel);
            templine >> stock;
            inven.add_parts(pn, stock-1);
        }
        if (type == "battery")
        {
            templine >> name >> pn >> p >> ca >> cca >> v >> rcm;
            Auto_Part* battery = new Battery(type, name, pn, p, ca, cca, v, rcm);
            inven.add_part(battery);
            templine >> stock;
            inven.add_parts(pn, stock-1);
        }
        if (type == "engine")
        {
            templine >> name >> pn >> p >> nc >> fuelt;
            Auto_Part* engine = new Engine(type, name, pn, p, nc, fuelt);
            inven.add_part(engine);
            templine >> stock;
            inven.add_parts(pn, stock-1);
        }
        if (type == "wtc")
        {
            templine >> name >> pn >> p >> cat >> c >> wdia >> ww >> bp >> tt >> w >> r >> dia >> sr >> lr;
            Auto_Part* wtc = new Wheel_Tire_Combo(type, name, pn, p, cat, c, wdia, ww, bp, tt, w, r, dia, sr, lr);
            inven.add_part(wtc);
            templine >> stock;
            inven.add_parts(pn, stock-1);
        }
        if (type == "ww")
        {
            templine >> name >> pn >> p >> l >> framet;
            Auto_Part* ww = new Windshield_Wiper(type, name, pn, p, l, framet);
            inven.add_part(ww);
            templine >> stock;
            inven.add_parts(pn, stock-1);
        }
        if (type == "frame")
        {
            templine >> name >> pn >> p >> framet;
            Auto_Part* frame = new Frame(type, name, pn, p, framet);
            inven.add_part(frame);
            templine >> stock;
            inven.add_parts(pn, stock-1);
        }
        if (type == "seat")
        {
            templine >> name >> pn >> p >> f >> st;
            Auto_Part* seat = new Seat(type, name, pn, p, f, st);
            inven.add_part(seat);
            templine >> stock;
            inven.add_parts(pn, stock-1);
        }
        if (type == "dashboard")
        {
            templine >> name >> pn >> p >> dm >> ds;
            Auto_Part* dashboard = new Dashboard(type, name, pn, p, dm, ds);
            inven.add_part(dashboard);
            templine >> stock;
            inven.add_parts(pn, stock-1);
        }
        if (type == "sw")
        {
            templine >> name >> pn >> p >> swc >> swd;
            Auto_Part* sw = new Steering_Wheel(type, name, pn, p, swc, swd);
            inven.add_part(sw);
            templine >> stock;
            inven.add_parts(pn, stock-1);
        }
        if (type == "door")
        {
            templine >> name >> pn >> p >> dc >> wt;
            Auto_Part* door = new Door(type, name, pn, p, dc, wt);
            inven.add_part(door);
            templine >> stock;
            inven.add_parts(pn, stock-1);
        }

    }
    loadfile.close();
}

void Controller::add_battery()
{
    string t, n;
    int pn, ca, cca, v, rcm;
    double p;

    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();
    pn = view.pn_prompt();
    ca = view.ca_prompt();
    cca = view.cca_prompt();
    v = view.v_prompt();
    rcm = view.rcm_prompt();

    Auto_Part* battery = new Battery(t,n,pn,p,ca,cca, v, rcm);

    inven.add_part(battery);
}

void Controller::add_door()
{
    string t, n, wt, dc;
    int pn;
    double p;

    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();
    pn = view.pn_prompt();
    wt = view.wt_prompt();
    dc = view.dc_prompt();

    Auto_Part* door = new Door(t,n,pn,p,dc,wt);

    inven.add_part(door);
}

void Controller::add_seat()
{
    string t, n, f, st;
    int pn;
    double p;

    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();
    pn = view.pn_prompt();
    st = view.st_prompt();
    f = view.f_prompt();

    Auto_Part* seat = new Seat(t,n,pn,p,f,st);

    inven.add_part(seat);
}

void Controller::add_tire()
{
    string t, n, tt, sr, lr;
    int pn, w, r, dia;
    double p;

    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();
    pn = view.pn_prompt();
    tt = view.tt_prompt();
    dia = view.diameter_prompt();
    w = view.width_prompt();
    r = view.ratio_prompt();
    lr = view.lr_prompt();
    sr = view.sr_prompt();

    Auto_Part* tire = new Tire(t,n,pn,p,tt,w,r,dia,sr,lr);

    inven.add_part(tire);
}

void Controller::add_wheel()
{
    string t,n,cat,c,bp;
    int pn,wdia,ww;
    double p;

    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();
    pn = view.pn_prompt();
    wdia = view.wdiameter_prompt();
    ww = view.wwidth_prompt();
    cat = view.cat_prompt();
    c = view.c_prompt();
    bp = view.bp_prompt();

    Auto_Part* wheel = new Wheel(t,n,pn,p,cat,c,wdia,ww,bp);

    inven.add_part(wheel);
}

void Controller::add_ww()
{
    string t, n, ft;
    int pn, l;
    double p;

    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();
    pn = view.pn_prompt();
    l = view.length_prompt();
    ft = view.frame_type_prompt();

    Auto_Part* ww = new Windshield_Wiper(t,n,pn,p,l,ft);

    inven.add_part(ww);
}

void Controller::add_wtc()
{
    string t, n, cat, c, sr, lr, bp, tt;
    int pn, wdia, ww, w, r, dia;
    double p;

    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();
    pn = view.pn_prompt();
    wdia = view.wdiameter_prompt();
    ww = view.wwidth_prompt();
    cat = view.cat_prompt();
    c = view.c_prompt();
    bp = view.bp_prompt();
    w = view.width_prompt();
    r = view.ratio_prompt();
    dia = view.diameter_prompt();
    tt = view.tt_prompt();
    sr = view.sr_prompt();
    lr = view.lr_prompt();

    Auto_Part* wtc = new Wheel_Tire_Combo(t,n,pn,p,cat,c,wdia,ww,bp,tt,w,r,dia,sr,lr);

    inven.add_part(wtc);
}

void Controller::view_parts()
{
    view.view_all_inventory();
}

void Controller::save_inven()
{
    view.save_prompt();
    inven.save_inventory();
}

void Controller::new_car()
{
    Car car;
    string  c, cat, t, n, bp, framet, fuelt,lr,sr, tt, f, st, dm, swc, wt, dc;
    int cca, ca, r, ww, wdia, w, dia, v, rcm, nc, pn, stock, ds, swd;
    double p;

    view.engine_message();

    t = view.type_prompt();
    n = view.name_prompt();
    pn = view.pn_prompt();
    p = view.price_prompt();
    nc = view.nc_prompt();
    fuelt = view.fuel_type_prompt();

    Engine e(t,n,pn,p,nc,fuelt);
    car.set_engine(e);

    view.wtc_message();

    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();
    pn = view.pn_prompt();
    wdia = view.wdiameter_prompt();
    ww = view.wwidth_prompt();
    cat = view.cat_prompt();
    c = view.c_prompt();
    bp = view.bp_prompt();
    w = view.width_prompt();
    r = view.ratio_prompt();
    dia = view.diameter_prompt();
    tt = view.tt_prompt();
    sr = view.sr_prompt();
    lr = view.lr_prompt();

    Wheel_Tire_Combo wtc(t,n,pn,p,cat,c,wdia,ww,bp,tt,w,r,dia,sr,lr);
    car.set_wtc(wtc);

    view.seat_message();

    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();
    pn = view.pn_prompt();
    st = view.st_prompt();
    f = view.f_prompt();

    Seat seat(t,n,pn,p,f,st);
    car.set_seat(seat);

    view.door_message();

    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();
    pn = view.pn_prompt();
    wt = view.wt_prompt();
    dc = view.dc_prompt();

    Door door(t,n,pn,p,dc,wt);
    car.set_door(door);

    view.dashboard_message();

    t = view.type_prompt();
    n = view.name_prompt();
    pn = view.pn_prompt();
    p = view.price_prompt();
    dm = view.dm_prompt();
    ds = view.ds_prompt();

    Dashboard dash(t,n,pn,p,dm,ds);
    car.set_dashboard(dash);

    view.battery_message();

    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();
    pn = view.pn_prompt();
    ca = view.ca_prompt();
    cca = view.cca_prompt();
    v = view.v_prompt();
    rcm = view.rcm_prompt();

    Battery batt(t,n,pn,p,ca,cca,v,rcm);
    car.set_battery(batt);

    view.sw_message();

    swc = view.swc_prompt();
    swd = view.swd_prompt();
    pn = view.pn_prompt();
    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();

    Steering_Wheel strw(t,n,pn,p,swc,swd);
    car.set_steering_wheel(strw);

    view.frame_message();

    framet = view.frame_type_prompt();
    pn = view.pn_prompt();
    t = view.type_prompt();
    n = view.name_prompt();
    p = view.price_prompt();

    Frame frame(t,n,pn,p,framet);
    car.set_frame(frame);

    inven.add_car(car);
}

void Controller::one_order()
{
    int pn, quantity, ordernum, numparts;
    bool status;
    string address, billinfo, customer, orderstatus;
    //Order order;

    address = view.address_prompt();
    myorder.set_address(address);
    billinfo = view.billinfo_prompt();
    myorder.set_billInfo(billinfo);
    orderstatus = "not_yet_processed";
    myorder.set_orderStatus(orderstatus);
    customer = view.customer_prompt();
    myorder.set_customer(customer);
    numparts = view.numparts_prompt();

    for (int i = 0; i < numparts; i++)
    {
    pn = view.pn_prompt();
    quantity = view.quantity_prompt();
    myorder.insert_part(pn, quantity);
    }
   status = inven.process_one_order(myorder);
   if (status)
   {
       myorder.set_orderStatus("filled");
       view.filled_prompt();
   }
   if (!status)
   {
       myorder.set_orderStatus("rejected");
       view.rejected_prompt();
   }
}

void Controller::mult_order()
{
    string fileName;
    fileName = view.load_prompt();
    inven.process_mult_order(fileName);
}
