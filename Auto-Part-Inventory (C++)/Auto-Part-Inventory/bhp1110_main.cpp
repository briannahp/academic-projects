#include "bhp1110_Main_Window.h"


int main(int argc, char* argv[])
{
    Gtk::Main kit(argc, argv);
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.nim");

    Main_Window win;

    win.set_title("Auto-Part Inventory Menu");

	//controller.cli();

	//controller.gui();

	return app->run(win);
}
