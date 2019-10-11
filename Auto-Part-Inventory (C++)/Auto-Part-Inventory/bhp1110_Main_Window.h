#ifndef BHP1110_MAIN_WINDOW_H_INCLUDED
#define BHP1110_MAIN_WINDOW_H_INCLUDED

#include <gtkmm.h>
#include "bhp1110_Controller.h"

class Main_Window : public Gtk::Window {
    public:
        Main_Window();
        virtual ~Main_Window();
    protected:
        void on_about_click();
        void on_car_click();
        void on_view_car_click();
        void on_quit_click();
        void on_view_click();
        void on_save_click();
        void on_load_click();
        void on_new_click();
        void on_inc_click();
        void on_remove_click();
        void on_oneorder_click();
        void on_multorder_click();
    private:
        Inventory inv;
};

#endif // BHP1110_MAIN_WINDOW_H_INCLUDED
