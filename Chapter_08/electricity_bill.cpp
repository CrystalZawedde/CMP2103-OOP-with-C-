# include <iostream>
using namespace std;

class Appliance{
protected:
string name;
double wattage;
public:
Appliance(string name, double wattage)
:name(name),wattage(wattage){}
virtual double calculateMonthlyCost()=0; 
};

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

int main(){
    Appliance* bill[2]; 
    bill[0]= new BaseBill("Refridgerator", 150.0,24.0);
    bill[1]= new FinalBill("Refridgerator", 150.0,24.0,1.5);
    cout<<"Monthly Base Bill: "<<bill[0]-> calculateMonthlyCost()<<"\n";
    cout<<"Monthly Final Bill: "<<bill[1]-> calculateMonthlyCost()<<"\n";
    delete bill[0];
    delete bill[1];
    return 0;  
}