#include "bhp1110_Main_Window.h"

Main_Window::Main_Window() {

    set_default_size(400, 200);

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Orders", true));
    menubar->append(*menuitem_order);
    Gtk::Menu *ordermenu = Gtk::manage(new Gtk::Menu());
    menuitem_order->set_submenu(*ordermenu);

     Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_quit_click));
    filemenu->append(*menuitem_quit);

    Gtk::MenuItem *menuitem_oneorder = Gtk::manage(new Gtk::MenuItem("_Individual Order", true));
    menuitem_oneorder->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_oneorder_click));
    ordermenu->append(*menuitem_oneorder);

    Gtk::MenuItem *menuitem_multorder = Gtk::manage(new Gtk::MenuItem("_Multiple Orders", true));
    menuitem_multorder->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_multorder_click));
    ordermenu->append(*menuitem_multorder);

     Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this,
        &Main_Window::on_about_click));
    helpmenu->append(*menuitem_about);

    Gtk::MenuItem *menuitem_parts = Gtk::manage(new Gtk::MenuItem("_Parts", true));
    menubar->append(*menuitem_parts);
    Gtk::Menu *partsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_parts->set_submenu(*partsmenu);

    Gtk::MenuItem *menuitem_cars = Gtk::manage(new Gtk::MenuItem("_Cars", true));
    menubar->append(*menuitem_cars);
    Gtk::Menu *carsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_cars->set_submenu(*carsmenu);

    Gtk::MenuItem *menuitem_viewCars = Gtk::manage(new Gtk::MenuItem("_View Cars", true));
    menuitem_viewCars->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_view_car_click));
    carsmenu->append(*menuitem_viewCars);

    Gtk::MenuItem *menuitem_addCars = Gtk::manage(new Gtk::MenuItem("_Add Car", true));
    menuitem_addCars->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_car_click));
    carsmenu->append(*menuitem_addCars);

    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View Parts", true));
    menuitem_view->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_view_click));
    partsmenu->append(*menuitem_view);

    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_Create Part", true));
    menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_new_click));
    partsmenu->append(*menuitem_new);

    Gtk::MenuItem *menuitem_inc = Gtk::manage(new Gtk::MenuItem("_Increment Part", true));
    menuitem_inc->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_inc_click));
    partsmenu->append(*menuitem_inc);

    Gtk::MenuItem *menuitem_remove = Gtk::manage(new Gtk::MenuItem("_Remove Part(s)", true));
    menuitem_remove->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_remove_click));
    partsmenu->append(*menuitem_remove);

    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save Inventory", true));
    menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_save_click));
    filemenu->append(*menuitem_save);

    Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load Inventory", true));
    menuitem_load->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_load_click));
    filemenu->append(*menuitem_load);

    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    vbox->show_all();
}

Main_Window::~Main_Window()
{
}

void Main_Window::on_about_click()
{
    Glib::ustring s = "<span size='24000' weight='bold'>Auto-Part Inventory System</span>\n<span size='large'>By Brianna Peterson.</span>\n<span size='small'>Project Created for CSE 1325.</span>";
    Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dlg.run();
}

void Main_Window::on_quit_click()
{
    hide();
}

void Main_Window::on_view_click()
{
    View view(inv);
    Controller controller(inv,view);
    controller.view_parts();
}

void Main_Window::on_new_click()
{
    View view(inv);
    Controller controller(inv,view);
    controller.add_new_part();
}

void Main_Window::on_inc_click()
{
    View view(inv);
    Controller controller(inv,view);
    controller.add_parts();
}

void Main_Window::on_remove_click()
{
    View view(inv);
    Controller controller(inv,view);
    controller.remove_parts();
}

void Main_Window::on_save_click()
{
    View view(inv);
    Controller controller(inv,view);
    controller.save_inven();
}

void Main_Window::on_load_click()
{
    inv.clear_inventory();
    View view(inv);
    Controller controller(inv, view);
    controller.load_file();
}

void Main_Window::on_multorder_click()
{
    View view(inv);
    Controller controller(inv, view);
    controller.mult_order();
}

void Main_Window::on_oneorder_click()
{
    View view(inv);
    Controller controller(inv, view);
    controller.one_order();
}

void Main_Window::on_car_click()
{
    View view(inv);
    Controller controller(inv, view);
    controller.new_car();
}

void Main_Window::on_view_car_click()
{
    View view(inv);
    Controller controller(inv, view);
    view.view_all_cars();
}
