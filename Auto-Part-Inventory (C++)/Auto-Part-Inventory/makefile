CXXFLAGS = -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: bhp1110_Main_Window

debug: CXXFLAGS += -g
debug: bhp1110_Main_Window


bhp1110_Main_Window: bhp1110_main.o bhp1110_Auto_Part.o bhp1110_Tire.o bhp1110_Wheel.o bhp1110_Wheel_Tire_Combo.o bhp1110_Battery.o bhp1110_Windshield_Wiper.o bhp1110_Frame.o bhp1110_Engine.o bhp1110_Inventory.o bhp1110_View.o bhp1110_Controller.o bhp1110_Dialog.o bhp1110_Main_Window.o bhp1110_Order.o bhp1110_Seat.o bhp1110_Door.o bhp1110_Steering_Wheel.o bhp1110_Dashboard.o bhp1110_Car.o
	$(CXX) $(CXXFLAGS) bhp1110_main.o bhp1110_Auto_Part.o bhp1110_Tire.o bhp1110_Wheel.o bhp1110_Wheel_Tire_Combo.o bhp1110_Battery.o bhp1110_Windshield_Wiper.o bhp1110_Frame.o bhp1110_Engine.o bhp1110_Inventory.o bhp1110_View.o bhp1110_Controller.o bhp1110_Dialog.o bhp1110_Main_Window.o bhp1110_Order.o bhp1110_Seat.o bhp1110_Door.o bhp1110_Steering_Wheel.o bhp1110_Dashboard.o bhp1110_Car.o $(GTKFLAGS)
	./a.out
bhp1110_main.o: bhp1110_Auto_Part.h bhp1110_Tire.h bhp1110_Wheel.h bhp1110_Wheel_Tire_Combo.h bhp1110_Battery.h bhp1110_Frame.h bhp1110_Engine.h bhp1110_Windshield_Wiper.h bhp1110_Inventory.h bhp1110_main.cpp bhp1110_View.h bhp1110_Controller.h bhp1110_Dialog.h bhp1110_Main_Window.h bhp1110_Order.h bhp1110_Seat.h bhp1110_Steering_Wheel.h bhp1110_Door.h bhp1110_Dashboard.h bhp1110_Car.h
	$(CXX) $(CXXFLAGS) -c bhp1110_main.cpp $(GTKFLAGS)
bhp1110_Inventory.o: bhp1110_Auto_Part.h bhp1110_Tire.h bhp1110_Wheel.h bhp1110_Wheel_Tire_Combo.h bhp1110_Battery.h bhp1110_Frame.h bhp1110_Engine.h bhp1110_Windshield_Wiper.h bhp1110_Inventory.h bhp1110_Inventory.cpp bhp1110_Dialog.h bhp1110_Order.h bhp1110_Seat.h bhp1110_Door.h bhp1110_Steering_Wheel.h bhp1110_Dashboard.h bhp1110_Car.h
	$(CXX) $(CXXFLAGS) -c bhp1110_Inventory.cpp $(GTKFLAGS)
bhp1110_Frame.o: bhp1110_Auto_Part.h bhp1110_Frame.h bhp1110_Frame.cpp
	$(CXX) $(CXXFLAGS) -c bhp1110_Frame.cpp $(GTKFLAGS)
bhp1110_Engine.o: bhp1110_Auto_Part.h bhp1110_Engine.h bhp1110_Engine.cpp
	$(CXX) $(CXXFLAGS) -c bhp1110_Engine.cpp $(GTKFLAGS)
bhp1110_Windshield_Wiper.o: bhp1110_Auto_Part.h bhp1110_Windshield_Wiper.h bhp1110_Windshield_Wiper.cpp
	$(CXX) $(CXXFLAGS) -c bhp1110_Windshield_Wiper.cpp $(GTKFLAGS)
bhp1110_Battery.o: bhp1110_Auto_Part.h bhp1110_Battery.h bhp1110_Battery.cpp
	$(CXX) $(CXXFLAGS) -c bhp1110_Battery.cpp $(GTKFLAGS)
bhp1110_Wheel_Tire_Combo.o: bhp1110_Auto_Part.h bhp1110_Wheel.h bhp1110_Tire.h bhp1110_Wheel_Tire_Combo.h bhp1110_Wheel_Tire_Combo.cpp
	$(CXX) $(CXXFLAGS) -c bhp1110_Wheel_Tire_Combo.cpp $(GTKFLAGS)
bhp1110_Wheel.o: bhp1110_Auto_Part.h bhp1110_Wheel.h bhp1110_Wheel.cpp
	$(CXX) $(CXXFLAGS) -c bhp1110_Wheel.cpp $(GTKFLAGS)
bhp1110_Tire.o: bhp1110_Auto_Part.h bhp1110_Tire.h bhp1110_Tire.cpp
	$(CXX) $(CXXFLAGS) -c bhp1110_Tire.cpp $(GTKFLAGS)
bhp1110_Auto_Part.o: bhp1110_Auto_Part.h bhp1110_Auto_Part.cpp
	$(CXX) $(CXXFLAGS) -c bhp1110_Auto_Part.cpp $(GTKFLAGS)
bhp1110_View.o: bhp1110_View.h bhp1110_View.cpp bhp1110_Auto_Part.h bhp1110_Inventory.h bhp1110_Engine.h bhp1110_Battery.h bhp1110_Wheel.h bhp1110_Tire.h bhp1110_Frame.h bhp1110_Windshield_Wiper.h bhp1110_Wheel_Tire_Combo.h bhp1110_Dialog.h bhp1110_Order.h bhp1110_Seat.h bhp1110_Dashboard.h bhp1110_Steering_Wheel.h bhp1110_Door.h bhp1110_Car.h
	$(CXX) $(CXXFLAGS) -c bhp1110_View.cpp $(GTKFLAGS)
bhp1110_Controller.o: bhp1110_Controller.cpp bhp1110_Controller.h bhp1110_View.h bhp1110_Auto_Part.h bhp1110_Inventory.h bhp1110_Engine.h bhp1110_Battery.h bhp1110_Wheel.h bhp1110_Tire.h bhp1110_Frame.h bhp1110_Windshield_Wiper.h bhp1110_Wheel_Tire_Combo.h bhp1110_Dialog.h bhp1110_Order.h bhp1110_Seat.h bhp1110_Door.h bhp1110_Steering_Wheel.h bhp1110_Dashboard.h bhp1110_Car.h
	$(CXX) $(CXXFLAGS) -c bhp1110_Controller.cpp $(GTKFLAGS)
bhp1110_Dialog.o: bhp1110_Dialog.h bhp1110_Dialog.cpp
	$(CXX) $(CXXFLAGS) -c bhp1110_Dialog.cpp $(GTKFLAGS)
bhp1110_Main_Window.o: bhp1110_Main_Window.h bhp1110_Main_Window.cpp bhp1110_View.h bhp1110_Controller.h bhp1110_Auto_Part.h bhp1110_Inventory.h bhp1110_Frame.h bhp1110_Engine.h bhp1110_Wheel_Tire_Combo.h bhp1110_Tire.h bhp1110_Wheel.h bhp1110_Windshield_Wiper.h bhp1110_Battery.h bhp1110_Order.h bhp1110_Seat.h bhp1110_Door.h bhp1110_Steering_Wheel.h bhp1110_Dashboard.h bhp1110_Car.h
	$(CXX) $(CXXFLAGS) -c bhp1110_Main_Window.cpp $(GTKFLAGS)
bhp1110_Order.o: bhp1110_Order.cpp bhp1110_Order.h
	$(CXX) $(CXXFLAGS) -c bhp1110_Order.cpp $(GTKFLAGS)
bhp1110_Seat.o: bhp1110_Seat.cpp bhp1110_Seat.h bhp1110_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c bhp1110_Seat.cpp $(GTKFLAGS)
bhp1110_Door.o: bhp1110_Door.h bhp1110_Door.cpp bhp1110_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c bhp1110_Door.cpp $(GTKFLAGS)
bhp1110_Steering_Wheel.o: bhp1110_Steering_Wheel.h bhp1110_Steering_Wheel.cpp bhp1110_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c bhp1110_Steering_Wheel.cpp $(GTKFLAGS)
bhp1110_Dashboard.o: bhp1110_Dashboard.h bhp1110_Dashboard.cpp bhp1110_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c bhp1110_Dashboard.cpp $(GTKFLAGS)
bhp1110_Car.o: bhp1110_Car.h bhp1110_Car.cpp bhp1110_Auto_Part.h bhp1110_Steering_Wheel.h bhp1110_Door.h bhp1110_Seat.h bhp1110_Dashboard.h bhp1110_Tire.h bhp1110_Wheel_Tire_Combo.h bhp1110_Engine.h bhp1110_Battery.h bhp1110_Frame.h
	$(CXX) $(CXXFLAGS) -c bhp1110_Car.cpp $(GTKFLAGS)

