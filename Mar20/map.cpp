#include <iostream>
#include <vector>
#include <map>

struct CityRecord
{
    std::string cityName;
    int population;
};

int main()
{
    std::vector<CityRecord> cities;
    cities.push_back(CityRecord{"jaipur", 1000});
    cities.push_back(CityRecord{"ajmer", 1000});
    cities.push_back(CityRecord{"delhi", 1000});
    cities.push_back(CityRecord{"noida", 9000});
    cities.push_back(CityRecord{"mumbai", 1000});

    for (auto city : cities)
    {
        if (city.cityName == "noida")
        {
            std::cout << city.population<<std::endl;
            break;
        }
    }

    std::map<std::string, CityRecord> cityMap;
    cityMap["jaipur"] = CityRecord{"jaipur", 1000};
    cityMap["ajmer"] = CityRecord{"ajmer", 1000};
    cityMap["noida"] = CityRecord{"noida", 9000};
    cityMap["delhi"] = CityRecord{"delhi", 1000};
    cityMap["mumbai"] = CityRecord{"mumbai", 1000};

    CityRecord& data=cityMap["noida"];
    std::cout<<data.population<<std::endl;
}