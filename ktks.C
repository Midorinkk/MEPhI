#include <TLorentzVector.h>

void ktks()
{
TFile* f1 = new TFile("/home/midorinkk/Downloads/user.dponomar.19428203._000001.SM_WLepton.root", "READ");
TFile* f2 = new TFile("/home/midorinkk/Downloads/user.dponomar.19428278._000009.SM_WLepton.root", "READ");

TTree* ee = (TTree*)f1->Get("NOMINAL");
TTree* mumu = (TTree*)f2->Get("NOMINAL");

TH1F *ee11 = new TH1F("Pt", "e; P_{T} [GeV]; Entries", 150, 0, 400);
TH1F *ee12 = new TH1F("Eta", "e; Eta; Entries", 150, -3, 3);
TH1F *ee13 = new TH1F("Phi", "e; Phi; Entries", 150, -4, 4);
TH1F *ee14 = new TH1F("E", "e; E; Entries", 150, 0, 1000);
TH1F *ee21 = new TH1F("Pt", "e; P_{T} [GeV]; Entries", 150, 0, 200);
TH1F *ee23 = new TH1F("Phi", "e; Phi; Entries", 150, -4, 4);
TH1F *ee24 = new TH1F("E", "e; E; Entries", 150, 0, 200);

TH1F *mumu11 = new TH1F("Pt", "mu; P_{T} [GeV]; Entries", 150, 0, 400);
TH1F *mumu12 = new TH1F("Pt", "mu; P_{T} [GeV]; Entries", 150, -3, 3);
TH1F *mumu13 = new TH1F("Phi", "mu; Phi; Entries", 150, -4, 4);
TH1F *mumu14 = new TH1F("E", "mu; E; Entries", 150, 0, 600);
TH1F *mumu21 = new TH1F("Pt", "mu; P_{T} [GeV]; Entries", 150, 0, 150);
TH1F *mumu23 = new TH1F("Phi", "mu; Phi; Entries", 150, -4, 4);
TH1F *mumu24 = new TH1F("E", "mu; E; Entries", 150, 0, 150);

TCanvas* c = new TCanvas("c", "", 2000, 2000);
c->Divide(3,2);

ee11->SetDirectory(gROOT);
ee12->SetDirectory(gROOT);
ee13->SetDirectory(gROOT);
ee14->SetDirectory(gROOT);
ee21->SetDirectory(gROOT);
ee23->SetDirectory(gROOT);
ee24->SetDirectory(gROOT);

mumu11->SetDirectory(gROOT);
mumu12->SetDirectory(gROOT);
mumu13->SetDirectory(gROOT);
mumu14->SetDirectory(gROOT);
mumu21->SetDirectory(gROOT);
mumu23->SetDirectory(gROOT);
mumu24->SetDirectory(gROOT);

TLorentzVector* lep_e = 0;
TLorentzVector* met_e = 0;
TLorentzVector* lep_mu = 0;
TLorentzVector* met_mu = 0;

ee->SetBranchAddress("lep_0_p4", &lep_e);
ee->SetBranchAddress("met_reco_p4", &met_e);
mumu->SetBranchAddress("lep_0_p4", &lep_mu);
mumu->SetBranchAddress("met_reco_p4", &met_mu);

Long64_t N=ee->GetEntries();
std::cout<<"N events: "<< N << std::endl;

for (Long64_t i=0; i<N; i++)
{
ee->GetEntry(i);
ee11->Fill(lep_e->Pt());
ee12->Fill(lep_e->Eta());
ee13->Fill(lep_e->Phi());
ee14->Fill(lep_e->E());
ee21->Fill(met_e->Pt());
ee23->Fill(met_e->Phi());
ee24->Fill(met_e->E());
}

Long64_t M=mumu->GetEntries();
std::cout<<"M events: "<< M << std::endl;

for (Long64_t i=0; i<M; i++)
{
mumu->GetEntry(i);
mumu11->Fill(lep_mu->Pt());
mumu12->Fill(lep_mu->Eta());
mumu13->Fill(lep_mu->Phi());
mumu14->Fill(lep_mu->E());
mumu21->Fill(met_mu->Pt());
mumu23->Fill(met_mu->Phi());
mumu24->Fill(met_mu->E());
}

f1->Close();
f2->Close();

c->cd(1);
Double_t norm=1;
ee11->Scale(norm/ee11->Integral(), "width");
mumu11->Scale(norm/mumu11->Integral(), "width");
ee11->SetLineColor(kGreen);
ee11->Draw("hist");
mumu11->Draw("hist same");
gPad->BuildLegend(0.9,0.1,0.8,0.3);

c->cd(2);
ee12->Scale(norm/ee12->Integral(), "width");
mumu12->Scale(norm/mumu12->Integral(), "width");
ee12->SetLineColor(kGreen);
ee12->Draw("hist");
mumu12->Draw("hist same");
gPad->BuildLegend(0.9,0.1,0.8,0.3);

c->cd(3);
ee13->Scale(norm/ee13->Integral(), "width");
mumu13->Scale(norm/mumu13->Integral(), "width");
ee13->SetLineColor(kGreen);
ee13->Draw("hist");
mumu13->Draw("hist same");
gPad->BuildLegend(0.9,0.1,0.8,0.3);

c->cd(4);
ee21->Scale(norm/ee21->Integral(), "width");
mumu21->Scale(norm/mumu21->Integral(), "width");
mumu21->Draw("hist");
ee21->SetLineColor(kGreen);
ee21->Draw("hist same");
gPad->BuildLegend(0.9,0.1,0.8,0.3);

c->cd(5);
ee23->Scale(norm/ee23->Integral(), "width");
mumu23->Scale(norm/mumu23->Integral(), "width");
mumu23->Draw("hist");
ee23->SetLineColor(kGreen);
ee23->Draw("hist same");
gPad->BuildLegend(0.9,0.1,0.8,0.3);

c->cd(6);
ee24->Scale(norm/ee24->Integral(), "width");
mumu24->Scale(norm/mumu24->Integral(), "width");
mumu24->Draw("hist");
ee24->SetLineColor(kGreen);
ee24->Draw("hist same");
gPad->BuildLegend(0.9,0.1,0.8,0.3);

}
