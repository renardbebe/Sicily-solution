Date::Date(int newYear, int newMonth, int newDay) {
    year = newYear;
    month = newMonth;
    day = newDay;
}

int Date::getYear() {
    return year;
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

void Date::setYear(int newYear) {
    year = newYear;
}

void Date::setMonth(int newMonth) {
    month = newMonth;
}

void Date::setDay(int newDay) {
    day = newDay;
}

Person::Person(int id, int year, int month, int day) {
    Person::id = id;
    birthDate = new Date (year,month,day);
    ++numberOfObjects;
}

Person::~Person() {
    delete birthDate;
    --numberOfObjects;
}

int Person::getId() {
    return id;
}

Date* Person::getBirthDate() {
    return birthDate;
}

int Person::getNumberOfObjects() {
    return numberOfObjects;
}                                 
