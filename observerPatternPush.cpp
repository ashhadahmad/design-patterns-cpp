#include <iostream>
#include <vector>

using namespace std;

class Observer {
    public:
    virtual void update(float temp, float humidity, float pressure) = 0;
};

class DisplayElement {
    public:
    virtual void display() = 0;
};

class Subject {
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers() = 0;
};

class WeatherData : public Subject {
    private:
    vector<Observer*> observers;
    float temperature;
    float humidity;
    float pressure;

    public:
    void registerObserver(Observer* o) {
        observers.push_back(o);
    }

    void removeObserver(Observer* o) {
        observers.erase(find(observers.begin(), observers.end(), o));
    }

    void notifyObservers() {
        for(int i=0; i<observers.size(); i++) {
            observers[i]->update(temperature, humidity, pressure);
        }
    }

    void measurementsChanged() {
        notifyObservers();
    }

    void setMeasurements(float temp, float humidity, float pressure) {
        this->temperature = temp;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
    }
};

class CurrentConditionsDisplay: public Observer, public DisplayElement {
    private:
    float temperature;
    float humidity;
    WeatherData* weatherData;

    public:
    CurrentConditionsDisplay(WeatherData* weatherData) {
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure) {
        this->temperature = temperature;
        this->humidity = humidity;
        display();
    }

    void display() {
        cout << "CurrentConditionsDisplay\n";
        cout << "Temperature :" << temperature << "\nHumidity :" << humidity << "\n" ;
    }
};

int main() {
    cout << "Hello world !";
    WeatherData* weatherData = new WeatherData();
    CurrentConditionsDisplay* currentConditionsDisplay = new CurrentConditionsDisplay(weatherData);

    weatherData->setMeasurements(80, 65, 30.4f);
    weatherData->setMeasurements(82, 70, 29.4f);
    weatherData->setMeasurements(78, 90, 29.2f);

}