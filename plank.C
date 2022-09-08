#include <iostream>
#include <fstream>
#include <string>

#include "TROOT.h"
#include "TCanvas.h"
#include "TProfile.h"
#include "TF1.h"

void GraficaS(const char* FileName)
{
    std::ifstream CVSFile(FileName);

    std::string line;

    size_t pos = 0;
    bool NumericValue;

    double time, in1, in2;

    TProfile *Time_Voltage_profile = new TProfile("tvp","Time - Voltage profile",200,-2.5,2.5);
    TProfile *Time_Current_profile = new TProfile("tcp","Time - Current profile",200,-2.5,2.5);
    

    int lineNumber = 0;

    while( std::getline( CVSFile, line ) )
    {
        NumericValue = true;
        lineNumber++;

        if((pos = line.find(",")) != std::string::npos) {
            try
            {
                time = std::stod( line.substr(0, pos) );
                if( (lineNumber > 309) && (lineNumber < 719) )
                    time *= 0.001;
            }
            catch(const std::exception& e)
            {
                NumericValue = false;
                std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
                continue;
            }
            
            line.erase(0, pos + 1);
        }
        if((pos = line.find(",")) != std::string::npos) {
            try
            {
                in1 = std::stod( line.substr(0, pos) );
            }
            catch(const std::exception& e)
            {
                NumericValue = false;
                std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
                continue;
            }
            
            line.erase(0, pos + 1);
        }
        try
        {
            in2 = std::stod( line );
        }
        catch(const std::exception& e)
        {
            NumericValue = false;
            std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
            continue;
        }
        
        if(NumericValue) Time_Voltage_profile->Fill(time,in1);
        if(NumericValue) Time_Current_profile->Fill(time,in2);
        
    }

    TCanvas *aCanvas = new TCanvas("ac","Uncorrected data",1600,600);
    aCanvas->Divide(2);

    aCanvas->cd(1);
    Time_Voltage_profile->Draw();
    aCanvas->cd(2);
    Time_Current_profile->Draw();
}


void Grafica(const char* FileName)
{
    std::ifstream CVSFile(FileName);

    std::string line;

    size_t pos = 0;
    bool NumericValue;

    double time, in1, in2;

    TProfile *Voltage_Current_profile = new TProfile("vcp","Anaranjado",200,-1.5,0.5,"s");
    

    int lineNumber = 0;

    while( std::getline( CVSFile, line ) )
    {
        NumericValue = true;
        lineNumber++;

        if((pos = line.find(",")) != std::string::npos) {
            try
            {
                time = std::stod( line.substr(0, pos) );
                if( (lineNumber > 309) && (lineNumber < 719) )
                    time *= 0.001;
            }
            catch(const std::exception& e)
            {
                NumericValue = false;
                std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
                continue;
            }
            
            line.erase(0, pos + 1);
        }
        if((pos = line.find(",")) != std::string::npos) {
            try
            {
                in1 = std::stod( line.substr(0, pos) );
            }
            catch(const std::exception& e)
            {
                NumericValue = false;
                std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
                continue;
            }
            
            line.erase(0, pos + 1);
        }
        try
        {
            in2 = std::stod( line );
        }
        catch(const std::exception& e)
        {
            NumericValue = false;
            std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
            continue;
        }
        
        if(NumericValue) Voltage_Current_profile->Fill(in1,in2);
        
    }

    TCanvas *aCanvas = new TCanvas("ac","Uncorrected data",800,600);

    Voltage_Current_profile->Draw();
}

void Fit(const char* FileName, unsigned bins, double Range_min, double Range_max)
{
    std::ifstream CVSFile(FileName);

    std::string line;

    size_t pos = 0;
    bool NumericValue;

    double time, in1, in2;


    TProfile *Voltage_Current_profile = new TProfile("vcp","Fit Anaranjado 'down'",bins,-1.5,0.5,"s");
    

    int lineNumber = 0;

    while( std::getline( CVSFile, line ) )
    {
        NumericValue = true;
        lineNumber++;

        if((pos = line.find(",")) != std::string::npos) {
            try
            {
                time = std::stod( line.substr(0, pos) );
                if( (lineNumber > 309) && (lineNumber < 719) )
                    time *= 0.001;
            }
            catch(const std::exception& e)
            {
                NumericValue = false;
                std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
                continue;
            }
            
            line.erase(0, pos + 1);
        }
        if((pos = line.find(",")) != std::string::npos) {
            try
            {
                in1 = std::stod( line.substr(0, pos) );
            }
            catch(const std::exception& e)
            {
                NumericValue = false;
                std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
                continue;
            }
            
            line.erase(0, pos + 1);
        }
        try
        {
            in2 = std::stod( line );
        }
        catch(const std::exception& e)
        {
            NumericValue = false;
            std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
            continue;
        }

        if(NumericValue) Voltage_Current_profile->Fill(in1,in2);
        
    }

    TCanvas *aCanvas = new TCanvas("ac","Fit UV",800,600);
    
    gStyle->SetOptFit(1);

    TF1 *lFunc = new TF1("line","[0]+[1]*x",Range_min,Range_max);
    lFunc->SetParNames("b","m");

    Voltage_Current_profile->Fit(lFunc,"R");
}