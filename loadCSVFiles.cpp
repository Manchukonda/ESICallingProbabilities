#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <unordered_map>
#include <unordered_set>

class CSVReader
{
    std::string fileName;
    std::string delimeter;

    public: CSVReader(std::string filename, std::string delm=","):
    fileName(filename), delimeter(delm)
    {}
    
    std::vector<std::vector<std::string> > getData();
};

std::vector<std::vector<std::string> > CSVReader::getData()
{
    std::ifstream file(fileName);
    std::vector<std::vector<std::string> > dataList;

    std::string line = "";

    while(getline(file, line))
    {
        std::vector<std::string> vec;
        boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
        dataList.push_back(vec);
    };

    return dataList;
}

int main()
{
    CSVReader esi1_reader("ESI_1_PatientsCallingPossibility.csv");
    CSVReader esi2_reader("ESI_2_PatientsCallingPossibility.csv");
    CSVReader esi3_reader("ESI_3_PatientsCallingPossibility.csv");
    CSVReader esi4_reader("ESI_4_PatientsCallingPossibility.csv");
    CSVReader esi5_reader("ESI_5_PatientsCallingPossibility.csv");
    std::unordered_map<std::int16_t,double> esi1;
    std::unordered_map<std::int16_t,double> esi2;
    std::unordered_map<std::int16_t,double> esi3;
    std::unordered_map<std::int16_t,double> esi4;
    std::unordered_map<std::int16_t,double> esi5;
    std::unordered_map<std::int16_t,std::unordered_map<std::int16_t, double>> All;
    std::vector<std::vector<std::string> >dataList1 = esi1_reader.getData();
    for(std::vector<std::string> vec1 : dataList1)
        esi1[stoi(vec1[1])] = stod(vec1[2]);
    std::vector<std::vector<std::string> >dataList2 = esi2_reader.getData();
    for(std::vector<std::string> vec2 : dataList2)
        esi2[stoi(vec2[1])] = stod(vec2[2]);
    std::vector<std::vector<std::string> >dataList3 = esi3_reader.getData();
    for(std::vector<std::string> vec3 : dataList3)
        esi3[stoi(vec3[1])] = stod(vec3[2]);
    std::vector<std::vector<std::string> >dataList4 = esi4_reader.getData();
    for(std::vector<std::string> vec4 : dataList4)
        esi4[stoi(vec4[1])] = stod(vec4[2]);
    std::vector<std::vector<std::string> >dataList5 = esi5_reader.getData();
    for(std::vector<std::string> vec5 : dataList5)
        esi5[stoi(vec5[1])] = stod(vec5[2]);

    All[1] = esi1;
    All[2] = esi2;
    All[3] = esi3;
    All[4] = esi4;
    All[5] = esi5;
    std::cout << "Finally!" << std::endl;
    //for (auto x : esi1) 
    //  std::cout << x.first << " " << x.second << std::endl; 
    /*std::cout << esi1.at(200) << std::endl;
    std::cout << esi2.at(200) << std::endl;
    std::cout << esi3.at(200) << std::endl;
    std::cout << esi4.at(200) << std::endl;
    std::cout << esi5.at(200) << std::endl;*/
    int i = 0;
    for(i = 0; i <= 2000000; i++)
    {
        int randESI = rand() % 5 + 1;
        int randWaitTime = rand()%300 + 1;
        int prob = All.at(randESI).at(randWaitTime);
    };

    /*std::cout << "Lets Check!" << std::endl;
    std::cout << All.at(1).at(200) << std::endl;
    std::cout << All.at(2).at(200) << std::endl;
    std::cout << All.at(3).at(200) << std::endl;
    std::cout << All.at(4).at(200) << std::endl;
    std::cout << All.at(5).at(200) << std::endl;*/
    std::cout << "Done" << std::endl;
    return 0;
}