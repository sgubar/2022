#include <iostream>
#include <string.h>

using namespace std;

class Sensor {
private:
    int *storage, size, gainTime;

public:
    /* constructor (auto) */
    Sensor() {
        cout << "Sensor is created" << endl;
    }

    /* destructor (auto) */
    ~Sensor() {
        cout << "Sensor is deleted" << endl;
    }

    void setSize(int amount) {
        size = amount;
    }    

    void setValues(int values[]) {
        storage = values;
    }

    void setValuesManual() {
        cout << "Enter " << size <<  " values: " << endl;
        for (int i = 0; i < size; i++) {
            cin >> storage[i];
        }
    }

    void setGainTime(int time) {
        gainTime = time;
    }

    int getValueAtIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "value doesn't exist" << endl;
            return 0;         
        }
        return storage[index];             
    }   

    void printValues() {
            cout << "Values:\n";
            for (int i = 0; i < size; i++) {
                cout << "[" << i << "]: " << storage[i] << endl;
            }
            cout << "Amount of elements in array: " << size << "\nGain time: " << gainTime << endl;
        }

};

int main() {
    Sensor mySensor1, mySensor2;    
    int values[] = {557, 23, 657, -23, -6, 4512};

    mySensor1.setSize(sizeof(values) / sizeof(values[0]));
    mySensor1.setValues(values);
    mySensor1.setGainTime(200);

    mySensor2.setSize(5);
    mySensor2.setValuesManual();    
    mySensor2.setGainTime(100);

    cout << "Sensor1: " << endl;
    mySensor1.printValues();  
    cout << "Value at index [" << 4 << "]: " << mySensor1.getValueAtIndex(4) << endl;
    cout << "Value at index [" << 7 << "]: " << mySensor1.getValueAtIndex(7) << endl;
    
    cout << "Sensor2: " << endl;
    mySensor2.printValues();

    return 1;
}