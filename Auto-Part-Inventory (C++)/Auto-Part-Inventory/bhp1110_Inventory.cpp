#include "bhp1110_Inventory.h"

void Inventory::add_part(Auto_Part* part)
{
	if(inventory.count(part) == 1)
		inventory.at(part) = inventory.at(part)+1;
	else
		inventory.insert(std::pair<Auto_Part*,int>(part, 1));
}

void Inventory::add_parts(int pn, int num)
{
    for (auto x : inventory)
        if((x.first)->get_part_number() == pn)
    {
        inventory.at(x.first) += num;
    }
}

int Inventory::get_num_parts(Auto_Part* part)
{
	return inventory.at(part);
}

void Inventory::remove_parts(int pn, int num)
{
	for (auto x : inventory)
        if ((x.first)->get_part_number() == pn)
            if(inventory.at(x.first) > num+1)
                inventory.at(x.first) -= num;
            else
                inventory.erase(x.first);

}

std::ostream& operator<<(std::ostream& ost, const Inventory& inv)
{
	for (auto x : inv.inventory)
    {
       ost << ((*x.first)).to_string() << " - " << x.second << "\n--------------------------------------\n"  << endl;
    }
}

void Inventory::save_inventory()
{
    ofstream savefile;
    string filename = "bhp1110_save_file.txt";

    savefile.open(filename);

    for(auto x : inventory)
        savefile << ((*x.first)).to_string() << " " << x.second << "\n\n";

    savefile.close();
}

void Inventory::clear_inventory()
{
    inventory.clear();
}

string Inventory::to_stringi()
{
    string str;
    for (auto x : inventory)
        str += (((*x.first)).to_string() + " - " + to_string((x.second)) + "\n--------------------------------------\n");
    return str;
}

bool Inventory::process_one_order(Order order)
{
    map<int,int> myorders = order.get_map();
    bool istrue = inventory_check2(order);

    if (istrue)
    {
        for(auto x : myorders)
            remove_parts(x.first, x.second);
        return true;
    }
    else
        return false;
}

void Inventory::process_mult_order(string fileName)
{
    string address, customer, billInfo;
    bool process;
    int pn, quantity, numParts, orderNumber;
    ifstream loadFile;
    loadFile.open(fileName);
    while (loadFile.peek()!=EOF)
    {
    Order order;
    getline(loadFile,customer);
    order.set_customer(customer);
    getline(loadFile,address);
    order.set_address(address);
    getline(loadFile,billInfo);
    order.set_billInfo(billInfo);
    loadFile >> orderNumber;
    order.set_orderNum(orderNumber);
    order.set_orderStatus("Not yet filled");
    loadFile >> numParts;
    for (int i = 0; i < numParts; i++)
    {
        loadFile >> pn;
        loadFile >> quantity;
        order.insert_part(pn, quantity);
    }
    process = process_one_order(order);
    }
}

void Inventory::add_car(Car c)
{
    myCars.push_back(c);
}

string Inventory::display_cars()
{
    string str;
    for (int i = 0; i < myCars.size(); i++)
        str += (myCars[i].to_string() + "\n------------------------------------------------\n");
    return str;
}

bool Inventory::inventory_check2(Order order)
{
    map <int,int> myorders = order.get_map();
    bool istrue = true;
    for (auto x : myorders)
    {
        istrue = inventory_check(x.first, x.second);
        if (!istrue)
            return istrue;
    }
    return istrue;
}

bool Inventory::inventory_check(int pn, int num)
{
    bool partFound = false;
    for (auto x : inventory)
        if((x.first)->get_part_number() == pn)
    {
        partFound = true;
        if((x.second) < num)
            return false;
    }
    if (!partFound)
        return false;
    else
        return true;
}
