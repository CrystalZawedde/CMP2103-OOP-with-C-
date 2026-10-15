# include <iostream>
using namespace std;
 class rectangle
 {
 private:
   double width;
   double length;
   double getLength()const{
    return length;
   }
   double getWidth()const{
    return width;
   }

 public:
 rectangle(
    double width = 4.0,
    double length = 5.0

 )
 :width(width),length(length)
 {}
 void setWidth(const double &width){
    this->width = width;
 }
 void setLength(const double &length){
    this->length = length;
 }
 double getPerimeter(){
    length = getLength();
    width = getWidth();
    return (2*length)+(2*width);
 }
 double getArea(){
    length = getLength();
    width = getWidth();
    return length*width;
 }
   
 };
 int main(){
    rectangle r1;
    cout<<"First perimeter: "<<r1.getPerimeter() <<'\n';
    cout<<"First area: "<<r1.getArea() <<'\n';

    r1.setLength(6.1);
    r1.setWidth(5.0);
    cout<<"New perimeter: "<<r1.getPerimeter() <<'\n';
    cout<<"New Area: "<<r1.getArea() <<'\n';


    return 0;
 }
