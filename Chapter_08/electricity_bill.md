# Home Energy Bill Calculator 
The Home Energy Bill Calculator is designed to calculate monthly electricity costs for home appliances in Ugandan Shillings (UGX). It works by first calculating a flat rate for an appliance and then calculating the final bill using a peak hour multiplier. 
To build this, a 3-level chained inheritance structure wasused starting with our base class Appliance, moving down to our derived class BaseBill, and finally to our deeply derived class FinalBill.
## The Base Class (Appliance) 
The Base Class (Appliance) acts as the foundation of our program. Every appliance has a name and a wattage. 

class Appliance{
protected:
string name;
double wattage;
public:
Appliance(string name, double wattage)
:name(name),wattage(wattage){}
virtual double calculateMonthlyCost()=0; 
};

In this class, the protected keyword was used as an access specifier instead of private because protected allows variables to be used in the class itself alongside any classes that inherit from it, unlike private, which limits variables strictly to that specific class. We also need the classes to be connected since variables like wattage and name are shared with the child classes.

Inside this base class,a pure virtual function was also declared, ie virtual double calculateMonthlyCost() = 0;. A virtual function is a way of bringing about polymorphism in code. A regular virtual function can have a default implementation at the base class if there are no other instances created for child classes, but if instances are created for child classes, the alternative implementations of the original virtual function will be taken on. However, for this particular case, a pure virtual function (set to zero) was used because we do not have any default value or implementation that we expect at the Appliance level. 

Because of this pure virtual function, Appliance becomes an abstract class. An abstract class sets a precedence and acts as a template for other classes, but it cannot have instances of its own. C++ prevents you from creating an object directly from an abstract class because it has no body for that function yet.

# The Derived Class (BaseBill)
The BaseBill class inherits from Appliance. This class introduces hoursPerDay to calculate a monthly flat rate based on kilowatt-hours (kWh).

class BaseBill: public Appliance{
protected:
double hoursPerDay;
public: 
BaseBill(string name, double wattage, double hoursPerDay)
: Appliance(name, wattage), hoursPerDay(hoursPerDay){}
double calculateMonthlyCost()override{
    double kwhPerDay = (wattage/1000)*hoursPerDay;
    return kwhPerDay*30*500; //In Ugx
} 
};

The algorithm here takes the wattage, divides it by 1000 to get kilowatts, and multiplies it by the hours per day to get the daily energy use. We then multiply that by 30 days and by 500 UGX to find the monthly flat rate. This class overrides the pure virtual function from the base class to provide its own concrete formula.

## The Deeply Derived Class (FinalBill)
The FinalBill class inherits from BaseBill. This introduces a peak hour multiplier to handle advanced pricing.

class FinalBill: public BaseBill{
protected:
double peakHourMultiplier;
public: 
FinalBill(string name, double wattage, double hourPerDay,double peakHourMultiplier)
: BaseBill(name, wattage,hourPerDay), peakHourMultiplier(peakHourMultiplier){}
double calculateMonthlyCost()override{
    return BaseBill::calculateMonthlyCost()*peakHourMultiplier;
} 
};

Instead of rewriting the whole formula from scratch, this class reuses the calculation from BaseBill by calling BaseBill::calculateMonthlyCost() and multiplying the result by the peakHourMultiplier (like 1.5).

# The Main Function

In the main function, we bring everything together using polymorphism and dynamic memory allocation:

int main(){
    Appliance* bill[2]; 
    bill[0] = new BaseBill("Refridgerator", 150.0,24.0);
    bill[1] = new FinalBill("Refridgerator", 150.0,24.0,1.5);
    cout<<"Monthly Base Bill: "<<bill[0]->calculateMonthlyCost()<<"\n";
    cout<<"Monthly Final Bill: "<<bill[1]->calculateMonthlyCost()<<"\n";
    delete bill[0];
    delete bill[1];
    return 0;  
}

We use base class pointers (like Appliance* bill[2]) to handle different types of bills because it allows us to store different related objects in a single unified array. Even though the array pointers look like Appliance*, polymorphism allows C++ to figure out at runtime which specific object it is pointing to and run the correct overridden version of calculateMonthlyCost().

Finally, we use dynamic memory operators like new and delete. Normal variables live on the stack and are destroyed automatically when a function ends, but using new creates objects dynamically on the heap while the program runs. Because heap memory does not clean itself up automatically, we use delete at the end of the program to free up that memory and prevent memory leaks.