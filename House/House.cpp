#include <iostream>
#include "Person.h"
#include "House.h"
#include "Apartment.h"


using namespace std;

int main()
{
	House house;
	house.SetNumApartments(5);
    for (int i = 0; i < house.GetNumApartments(); ++i) {
        Apartment apartment(i, 2);
        apartment.SetPerson(0, Person("John Smith", 30));
        apartment.SetPerson(1, Person("Jane Doe", 25));
        house.SetApartment(i, apartment);
    }

    for (int i = 0; i < house.GetNumApartments(); i++) {
        Apartment apartment = house.GetApartment(i);
        cout << "Apartment " << apartment.GetNum() << ":" << endl;
        for (int j = 0; j < apartment.GetCapacity(); j++) {
            Person person = apartment.GetPerson(j);
            cout << "    Person " << j << ":" << endl;
            cout << "        Name: " << person.GetName() << endl;
            cout << "        Age: " << person.GetAge() << endl;
        }
    }
}
