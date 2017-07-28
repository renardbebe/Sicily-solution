	#include <cmath>
     Double::Double() {
        data = 0;
     }

     Double::Double(double data) {
        Double::data = data;
     }

     double Double::getDouble() const {
        return data;
     }

     void Double::setDouble(double data) {
        Double::data = data;
     }

     void Double::add(const Double &other) {
        data += other.data;
     }

     void Double::sub(const Double &other) {
        data -= other.data;
     }

     void Double::mul(const Double &other) {
        data *= other.data;
     }

     bool Double::div(const Double &other) {
        if(abs(other.data) <= 0.005) return false;
        else
        {
            data /= other.data;
            return true;    
        } 
     }                           
