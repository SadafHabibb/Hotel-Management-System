#include "hashtable.hpp"

// Constructor
HashTable::HashTable(int capacity) : size(0), capacity(capacity), collisions(0) {
    buckets = new list<Entry>[capacity];
}

// hash function to calculate the index for a given key
unsigned long HashTable::hashCode(string key) {
    unsigned long hash = 5381;  // Initial value

    for (char ch : key) {
        hash = ((hash << 5) + hash) + ch;  // I]t improved hash algorithm
    }

    return hash % capacity;
}


// find a hotel with a given key in the hashtable
Hotel* HashTable::find(string key, bool printstatement) {
    unsigned long index = hashCode(key);
    int comparisons = 0;

    // iterate through the linked list at the index given
    for (auto& entry : buckets[index]) {
        comparisons++;
        if (entry.key == key) {
            // if the Hotel found, give the comparisons
            if (printstatement == true) {
                cout << "Record found after " << comparisons << " comparison(s)" << endl;
            }
            return entry.value;
        }
    }

    // Hotel not found (this will be printed only if the loop completes without finding the hotel)
    cout << "Record not found." << endl;
    return nullptr;
}

// find the hotel in th especific city with the stars (if given)
void HashTable::findAll(string city, string stars) {
    // search for the city in the BST
    Node<string, Hotel*>* result = cityRecords.find(cityRecords.getRoot(), city, stars);
    if (result != nullptr) {
    } else {
        cout << "No record found!" << endl;
    }
}

// insert a hotel with a given key and value into the hashtable
void HashTable::insert(string key, Hotel* value) {
    unsigned long index = hashCode(key);
    bool isFound = false;

    // iterate through the linked list at the index found 
    for (auto& entry : buckets[index]) {
        if (entry.key == key) {
            // if entry with key is found 
            entry.value = value;
            isFound = true;
            cout << "Existing record has been updated" << endl;
            break;
        }
    }

    // check for collisions and update the collision count
    if (!buckets[index].empty()) {
        collisions++;
    }

    // if entry with given key is not found, create a new entry and add it to the linked list
    if (!isFound) {
        Entry newEntry(key, value);
        buckets[index].push_back(newEntry);

        // get the city name from the key and insert the hotel into the BST
        size_t commaPos = key.find(",");
        if (commaPos != string::npos) {
            string cityname = key.substr(commaPos + 1);
            cityRecords.insert(cityRecords.getRoot(), cityname, value);
        }

        //increase the size of the hashtable
        size++;
    }
}

// erase hotel with a given key from the hashtable
void HashTable::erase(string key) {
    unsigned long index = hashCode(key);

    // iterate through the linked list at the index found
    auto it = buckets[index].begin();
    while (it != buckets[index].end()) {
        //check if current key entry is same as target key
        if (it->key == key) {
            // find the hotel in that key
            Hotel* tobeDeleted = find(key, false);
            //check if it not empty
            if (tobeDeleted != nullptr){
                //separate the cityname from hotel name
                size_t commaPos = key.find(",");
                if (commaPos != string::npos) {
                    string cityname = key.substr(commaPos + 1);
                    // remove from the associated BST
                    cityRecords.remove(cityRecords.getRoot(), cityname, tobeDeleted);
                }
                cout << "Hotel \"" << key << "\" deleted successfully." << endl;
            }

            else{
                cout << "Hotel not found." << endl;
            }

            auto value = it->value;
            // remove it from the hashtable
            it = buckets[index].erase(it);
            //decrease size of hashtable
            size--;
            return;
        } else {
            //else movd to next key
            ++it;
        }
    }
    // when key not found
    cerr << "Warning: Hotel with key \"" << key << "\" not found." << endl;
}

// to get the current size of the hashtable
unsigned int HashTable::getSize() {
    return size;
}

// for total number of collisions
unsigned int HashTable::getCollisions() {
    return collisions;
}

// Dump the hashtable entries to a text file
void HashTable::dump(string path) {
    // open the output file to write in it
    ofstream outfile(path);
    if (outfile.is_open()) {
        // iterate through each bucket and each entry that we are putting in file
        for (unsigned int i = 0; i < capacity; ++i) {
            for (const Entry& entry : buckets[i]) {
                outfile << entry.key << " " << entry.value->toString() << endl;
            }
        }
        // close output file
        outfile.close();
    } else {
        //error if the file cannot be opened
        cerr << "Unable to open file for dumping." << endl;
    }
}

// destructor
HashTable::~HashTable() {
    // each linked list in the array of buckets is cleared 
    for (unsigned int i = 0; i < capacity; ++i) {
        buckets[i].clear();
    }
    // delete buckets array 
    delete[] buckets;
}


