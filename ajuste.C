#include <iostream>
#include <fstream>
#include <string>

#include "TROOT.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TF1.h"
#include "TCanvas.h"

void histogram(){
    //Se crea una funcion exponensial para ajustar los datos
    TF1 *ajuste=new TF1("ajuste","[0]*TMath::Exp(-x/[1])+[2]");
    ajuste->SetParNames("N","T","C");
    ajuste->SetParameters(10,100,10);
    //Se carga el archivo .root y se extrae el histograma con una variable h1
    TFile *muon = new TFile("suma.root");
    TH1D *h1 = new TH1D("h1","title", 2000, 0, 20000);
    h1 = (TH1D*)muon->Get("histograma");
    //Se crea un canvas para generar una grafica y guardar el ajuste
    gStyle->SetOptFit(1);
    TCanvas *ShowGraph = new TCanvas("h1", "Histograma Total", 800, 600);
    //Se utiliza la funcion Fit para generar el ajuste y se guarda la imagen
    h1->Fit(ajuste);
    ShowGraph->Update();
    ShowGraph->SaveAs("Ajuste.png" ,"png");
}