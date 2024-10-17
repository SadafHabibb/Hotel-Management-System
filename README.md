# Hotel-Management-System

## Overview
The Hotel Management System is a C++ application designed to manage information about hotels, including details like name, city, star rating, price, country, and address. It allows users to view and manipulate hotel data using various methods, offering formatted output for ease of use.

## Features
- **Hotel Data Management:** Store and access hotel information such as name, city, star rating, price, country, and address.
- **Formatted Display:** Output hotel details in different formats using `print` and `print2` methods for a user-friendly display.
- **String Representation:** Generate a string representation of the hotel's information for quick overview or logging.
- **Object-Oriented Design:** Uses a class-based structure with encapsulation for managing hotel data.

## Installation
1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/hotel-management-system.git
   ```
2. **Compile the project:**
   Make sure you have a C++ compiler (such as `g++`) installed. Use the following command to compile:
   ```bash
   g++ -o hotel_management main.cpp hotel.cpp -std=c++17
   ```
3. **Run the executable:**
   ```bash
   ./hotel_management
   ```

## Usage
The `Hotel` class provides methods to manage and display hotel information:
- **Constructor:** Create a new hotel with specified details.
- **Getters:** Access individual properties of a hotel (name, city, stars, price, country, and address).
- **String Representation (`toString`):** Generate a single-line string representation of the hotel's details.
- **Formatted Print (`print`):** Display the hotel's details with each attribute on a new line.
- **Tabular Print (`print2`):** Display the hotel's details in a tabular format using `iomanip` for formatted output.

## Example Code
Here's how to use the `Hotel` class:

```cpp
#include "hotel.hpp"
#include <iostream>

int main() {
    // Create a hotel object
    Hotel hotel("The Grand Hotel", "New York", "5", "$350", "USA", "123 Broadway");

    // Print hotel details using different formats
    hotel.print();
    cout << endl;
    hotel.print2();

    // Display string representation
    cout << endl << hotel.toString() << endl;

    return 0;
}
```

## Sample Output
```plaintext
Hotel name: The Grand Hotel
City      : New York
Stars     : 5
Price     : $350
Country   : USA
Address   : 123 Broadway

The Grand Hotel                                  New York    5     $350       USA                  123 Broadway

Hotel name: The Grand Hotel, City: New York, Stars: 5, Price: $350, Country: USA, Address: 123 Broadway
```

## Implementation Details
The `Hotel` class is implemented in `hotel.cpp` and declared in `hotel.hpp`. It includes:
- **Private Member Variables:** `name`, `city`, `stars`, `price`, `country`, and `address` for encapsulating hotel information.
- **Constructor:** Initializes a hotel object with the provided details.
- **Getter Methods:** Retrieve individual details about the hotel.
- **Formatted Output Methods:** `print` displays each attribute on a separate line, while `print2` provides a tabular output with proper alignment using `iomanip`.
- **String Representation:** `toString` returns a formatted string combining all hotel details.

## Future Improvements
- Add functionalities for managing multiple hotels (e.g., storing in a list or database).
- Implement search and filtering based on attributes like city or star rating.
- Add file input/output to save and load hotel data from a file.
- Extend the system to support more detailed hotel attributes (e.g., amenities, room types, reviews).

## License
This project is open-source and available under the MIT License.
