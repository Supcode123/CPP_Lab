#include "food.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iostream>


 
Food::Food(int bestellnummer, std::string bezeichnung, float preis) : bestellnr(bestellnummer), bezeichnung(bezeichnung), preis(preis) {}

std::string Food::getBezeichnung() const {
    return bezeichnung;
}

float Food::getPreis() const {
    return preis;
}

int Food::getBestellnummer() const {
    return bestellnr;
}

//2.1a
void speichern(const std::string& dateiname, const std::vector<Food>& speisen)  
{
/* std::ifstream in_file(dateiname);
    if (!in_file)
        {
        std::cout << "open file failed"<<std::endl;
        }
    std::string line;
    //std::vector<std::vector<std::string>> strArray;
    //std::string str;
    //std::vector<std::string> linearry;
    int num = 0;
       while (getline(in_file,line))
        {
      //std::cout<<line<<std::endl;
      num++;
     
      std::stringstream ss(line);
         while(getline(ss,str,';'))
        {
            //std::cout<<str<<std::endl;
            linearry.push_back(str);
            
        }
        //std::cout<<linearry.size()<<std::endl;
        strArray.push_back(linearry);
        //std::cout<<strArray.size()<<std::endl;
        }
 std::cout<<num<<std::endl;
        in_file.close();*/
        
      
        //******const_iterator******//
     std::ofstream o_file(dateiname,std::ofstream::app);//ofstream additon
     
     if(!o_file){
          std::cout << "open file failed"<<std::endl;
         }
       std::vector<Food>::const_iterator it;
        for(it=speisen.begin(); it !=speisen.end();it++)
            {
            //std::string Be_Nr =std::to_string(it->getBestellnummer()) ;
            int Be_Nr =it->getBestellnummer();
            std::ostringstream s1; // int to string && aviod the redundant 0 
            s1<< Be_Nr;
            std::string Bez = it->getBezeichnung();
            float Preis = it->getPreis();
            std::ostringstream s2;
            s2<< Preis;
            std::string new_line[]= {s1.str()+";" + Bez + ";" +s2.str()};
                 o_file<<new_line[0]<<std::endl;  
                 
            
    }
       o_file.close();
        
}

//2.1b
void laden(const std::string& dateiname, std::vector<Food>& speisen) {
  speichern(dateiname, speisen) ;
  std::ifstream in_file(dateiname);
  std::string line;
  if(! in_file)
      {
      throw std::runtime_error ("fail to read");
      }
      while(getline(in_file,line))
      {
       std::cout<< line <<std::endl;
      }
in_file.close();
}