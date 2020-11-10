#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define PI 3.1415
using namespace std;

class shape {
    private: 
        float x,y;
    public:
    
        shape(){ x=0.0; y=0.0; }
};

class triangle : shape { 
    private:
        float a,b,c;
        static int equ,iso,sca,rig,acu,obt,trii;
        bool valid;
    public:
        static int  getequ() { return equ; }
        static int  getiso() { return iso; }
        static int  getsca() { return sca; }
        static int  getrig() { return rig; }
        static int  getacu() { return acu; }
        static int  getobt() { return obt; }
        static int  gettrii() { return trii; }
        triangle(float numa = 0.0 , float numb = 0.0 , float numc = 0.0 ) : a(numa) , b(numb) , c(numc) {}
        
        float getArea() { 
            float s =(a+b+c)/2.0; 
            float ss = sqrt(s*(s-a)*(s-b)*(s-c));
            float sss = std::floor((ss * 100) +.5 ) / 100;
            if (valid) {
            return sss ;
            }
            else {
                return 0;
            }
        }
        float getPerimeter() { 
            if (valid) {
                return a+b+c;
            }
            else {
                return 0;
            }
             }
        
        bool isValidTriangle() {           
            if (a + b <= c) {
                valid = 0;               
            }          
            else{
                valid = 1;
                trii++;
            }
            return valid;
        }
        string getTypeBySide() {
            
            if (valid) {
                if (a == b and b == c) {
                    equ = equ + 1;
                    return("Equilateral");
                }
                else if ((a == b & b != c) || (a == c & c != b) || (b == c & c != a)) {
                    iso = iso + 1;
                    return("Isosceles");              
                }
                else {
                    sca = sca + 1;
                    return("Scalene");
                }
            }
            else {
                return ("X");
            }
        } 
        string getTypeByAngle() {
            if (valid) {
                if ((a*a) + (b*b) == (c*c)) {
                    rig = rig + 1;
                    return("Right");
                }
                else if ((a*a) + (b*b) > (c*c)) {
                    acu = acu + 1;
                    return("Acute");
                }
                else if ((a*a) + (b*b) < (c*c)) {
                    obt = obt + 1;
                    return("Obtuse");
                }
            }
            else {
                return ("X");    
            }
        }
};

class rectangle : shape { 
    protected:
        float w,h;
    public:
        rectangle(float numw = 0.0 , float numh = 0.0 ) : w(numw) , h(numh) {}
        float getArea() {return w*h;}
        float getPerimeter() { return 2*(w+h); }
};

class square : public rectangle {
    private:
        float w,h;
    public:
        square(float num = 0.0) { rectangle::w = num; rectangle::h = num;}
};

class circle : shape { 
    private:
        float r;
    public:
        circle(float numr = 0.0) : r(numr) {}
        float getArea() { return PI*r*r;}
        float getPerimeter() { return 2*PI*r; }
};
int triangle::equ;
int triangle::iso;
int triangle::sca;
int triangle::rig;
int triangle::acu;
int triangle::obt;
int triangle::trii;

int main () {
    srand(time(0));
    rectangle rec(10,5);
    circle cir(5);
    square squ(5);
    cout << "rectangle : area = " << rec.getArea() <<  ", getPerimeter = " << rec.getPerimeter() << endl;
    cout << "square : area = " << squ.getArea() <<  ", getPerimeter = " << squ.getPerimeter() << endl;
    cout << "circle : area = " << cir.getArea() <<  ", getPerimeter = " << cir.getPerimeter() << endl;
    cout << endl;
    int i;
    int k = 0;
    cout << setw(8) << " No" << setw(8) << "a" << setw(6) << "b" << setw(6) << "c" << setw(15) << "Type by Side" << setw(15) << "Type by Angle" << setw(12) << "Perimeter" << setw(10) << "Area"<< endl;
    cout <<"-----------------------------------------------------------------------------------" << endl;
    for (i=0; i < 1000; i++) {
        k++;
        float x = (rand() % 99) + 1;
        float y = (rand() % 99) + 1;
        float z = (rand() % 99) + 1;
        if (x > y) swap(x, y);
        if (y > z) swap(y, z);
        if (x > y) swap(x, y);
        
        triangle tri(x,y,z);
        tri.isValidTriangle();
        cout << setw(6) << k << " :" << setw(8) << x << setw(6) << y << setw(6) << z << setw(15)  << tri.getTypeBySide() << setw(15) << tri.getTypeByAngle() << setw(12) << tri.getPerimeter()  << setw(10)  << tri.getArea()  <<endl;

    }
    cout << endl;
    cout << "Total Data : " << k << endl;
    cout << "Total Triangle : " << triangle::gettrii() << endl;
    cout << "Total Equilateral Triangle : " << triangle::getequ() << endl;
    cout << "Total Scalene Triangle : " << triangle::getiso() << endl;
    cout << "Total Isosceles Triangle : " << triangle::getsca() << endl;
    cout << "Total Right Triangle : " << triangle::getrig() << endl;
    cout << "Total Acute Triangle : " << triangle::getacu() << endl;
    cout << "Total Obtuse Triangle : " << triangle::getobt() << endl; 
    
    
    
}