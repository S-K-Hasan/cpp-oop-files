#include <iostream>
#include <string>

using namespace std;

class WeatherStation {
private:
    string stationName;
    float temperatures[30];
    float humidities[30];

public:

    WeatherStation(string name, float temperature[],float humidity[])
    {
        stationName=name;
        for (int i=0;i<30;i++)
        {
            temperatures[i]=temperature[i];
            humidities[i]=humidity[i];
        }
    }

    float calculateAverageTemperature() const{
        float totalTemp = 0.0;
        for (int i=0; i<30;i++) {
            totalTemp+=temperatures[i];
        }
        return totalTemp / 30;
    }

    float calculateAverageHumidity() const{
        float totalHum=0.0;
        for (int i=0;i<30;i++) {
            totalHum=totalHum+humidities[i];
        }
        return totalHum / 30;
    }

 static int determineHottestDay(const WeatherStation stations[],int size) {
    float maxTemperature=0;
    int hottestDay=1;

    for (int i = 0; i < size; i++)
    {
        for (int j=0;j<30;j++)
        {
            if (stations[i].temperatures[j]>maxTemperature)
            {
                maxTemperature = stations[i].temperatures[j];
                hottestDay=j+1;
            }
        }
    }
    return hottestDay;
}
    void displayStationDetails() const {
        cout << "Station Name: " << stationName <<endl;
        cout << "Average Temperature: " << calculateAverageTemperature()<<"  C"<<endl;
        cout << "Average Humidity: " << calculateAverageHumidity()<<endl;
    }
};

int main() {

    float temperature1[30]={28.5, 30.2, 29.8, 31.1, 27.4, 25.6, 26.3, 30.0, 29.7, 28.4, 32.5, 33.1, 29.9, 31.3, 28.6, 27.5, 26.8, 25.2, 29.1, 28.7, 30.3, 31.5, 30.9, 29.8, 28.4, 26.7, 27.3, 30.1, 29.6, 28.2};
    float humidity1[30]={60.5, 62.1, 58.7, 65.3, 55.6, 50.2, 52.8, 64.5, 63.9, 60.4, 67.2, 68.5, 58.9, 64.3, 62.7, 57.1, 55.4, 53.6, 60.9, 61.8, 65.5, 66.7, 64.9, 63.4, 62.1, 59.3, 58.8, 64.2, 63.7, 60.6};

    float temperature2[30]={27.8, 29.5, 28.3, 30.0, 26.9, 24.8, 25.4, 29.2, 28.5, 27.1, 31.6, 32.0, 28.7, 30.2, 27.9, 26.3, 25.7, 24.5, 28.4, 27.6, 29.8, 30.6, 29.4, 28.7, 27.5, 25.9, 26.2, 29.0, 28.2, 27.3};
    float humidity2[30]={59.3, 61.2, 57.6, 64.1, 54.8, 49.5, 51.7, 63.2, 62.8, 59.0, 66.1, 67.4, 57.8, 63.5, 61.3, 56.2, 54.7, 52.1, 59.7, 60.5, 64.3, 65.6, 63.8, 62.3, 61.0, 58.7, 57.5, 63.4, 62.5, 59.8};

    WeatherStation station1("Station A",temperature1,humidity1);
    WeatherStation station2("Station B",temperature2,humidity2);

    station1.displayStationDetails();
    station2.displayStationDetails();

    WeatherStation stations[]={station1, station2};
    int hottestDay=WeatherStation::determineHottestDay(stations,2);

    cout<<"The hottest day of the month across all stations was day "<<hottestDay<<endl;

    return 0;
}

