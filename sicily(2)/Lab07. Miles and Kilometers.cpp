class Kilometers
{
private:
    double kilometers;
public:
    Kilometers(double kilometers): kilometers(kilometers) {}
    void display()
    {
        cout << kilometers << " kilometeres";
    }
    double getValue()
    {
        return kilometers;
    }
};

class Miles
{
private:
    double miles;
public:
    Miles(double miles) : miles(miles) {}
    Miles(Kilometers k) { 
        miles = k.getValue() * 1.609;
    }
    void display()
    {
        cout << miles << " miles";
    }
    operator Kilometers(){
        return (double)(miles / 1.609);
    }
};
