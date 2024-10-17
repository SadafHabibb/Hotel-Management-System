#include "hotel.hpp"
#include <iomanip>
using namespace std;


// defining onstructor 
Hotel::Hotel(string name, string city, string stars, string price, string country, string address)
    : name(name), city(city), stars(stars), price(price), country(country), address(address) {}

// getter methods to acces private members variables

// give name of the hotel
string Hotel::getName() {
    return name;
}

// give city of the hotel
string Hotel::getCity() {
    return city;
}

// give stars rating of the hotel
string Hotel::getStars() {
    return stars;
}

// give price of the hotel
string Hotel::getPrice() {
    return price;
}

// give country of the hotel
string Hotel::getCountry() {
    return country;
}

// give address of the hotel
string Hotel::getAddress() {
    return address;
}

// give string representation of the hotel
string Hotel::toString() {
    return "Hotel name: " + name + ", City: " + city + ", Stars: " + stars +
           ", Price: " + price + ", Country: " + country + ", Address: " + address;
}

// print hotel details
void Hotel::print() {
    cout << "Hotel name: " << name << endl;
    cout << "City      : " << city << endl;
    cout << "Stars     : " << stars << endl;
    cout << "Price     : " << price << endl;
    cout << "Country   : " << country << endl;
    cout << "Address   : " << address << endl;
}

// print Hotel Details
void Hotel::print2() {
    cout << left << setw(50) << name << " " << setw(10) << city << " " << setw(5) << stars << " "
         << setw(10) << price << " " << setw(20) << country << " " << address << endl;
}

