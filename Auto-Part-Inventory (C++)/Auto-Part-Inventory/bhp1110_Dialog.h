#ifndef BHP1110_DIALOG_H_INCLUDED
#define BHP1110_DIALOG_H_INCLUDED
#include <vector>
#include <iostream>
#include <gtkmm.h>

class Dialog
{
public:
    static void message(std::string msg, std::string title);
    static std::string input(std::string msg, std::string title, std::string default_text = "",std::string cancel_text = "CANCEL");
private:
};


#endif // BHP1110_DIALOG_H_INCLUDED
