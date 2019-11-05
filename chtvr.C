#include <TLorentzVector.h>
#include <TMath.h>

void chtvr()
{
TFile* f1 = new TFile("/home/midorinkk/Downloads/user.dponomar.19428203._000001.SM_WLepton.root", "READ");
TFile* f2 = new TFile("/home/midorinkk/Downloads/user.dponomar.19428278._000009.SM_WLepton.root", "READ");

TTree* ee = (TTree*)f1->Get("NOMINAL");
TTree* mumu = (TTree*)f2->Get("NOMINAL");

TH1F *ee1 = new TH1F("Pt", "lep_{e}; P_{T} [GeV]; Entries", 200, -10, 80);
TH1F *ee2 = new TH1F("Pt", "lep_1_{e}; P_{T} [GeV]; Entries", 200, -10, 80);
TH1F *ee3 = new TH1F("M", "dilep_{e} fitted with a Gaussian; M_{e} [GeV/c^{2}]; Entries", 200, 60, 120);

TH1F *mumu1 = new TH1F("Pt", "lep_{#mu}; P_{T} [GeV]; Entries", 200, -10, 80);
TH1F *mumu2 = new TH1F("Pt", "lep_1_{#mu}; P_{T} [GeV]; Entries", 200, -10, 80);
TH1F *mumu3 = new TH1F("M", "dilep_{#mu} fitted with a Gaussian; M_{#mu} [GeV/c^{2}]; Entries", 200, 60, 120);

TF1 *gausfit = new TF1("gausfit", "gaus", 60, 120);

TCanvas* c = new TCanvas("c", "", 2000, 2000);
c->Divide(2,2);

gStyle->SetOptFit(0111);

ee1->SetDirectory(gROOT);
ee2->SetDirectory(gROOT);
ee3->SetDirectory(gROOT);
mumu1->SetDirectory(gROOT);
mumu2->SetDirectory(gROOT);
mumu3->SetDirectory(gROOT);

TLorentzVector* lep_e = 0;
TLorentzVector* dilep_e = 0;
TLorentzVector* lep_mu = 0;
TLorentzVector* dilep_mu = 0;

ee->SetBranchAddress("lep_0_p4", &lep_e);
ee->SetBranchAddress("dilep_p4", &dilep_e);
mumu->SetBranchAddress("lep_0_p4", &lep_mu);
mumu->SetBranchAddress("dilep_p4", &dilep_mu);

Long64_t N=ee->GetEntries();
std::cout<<"N events: "<< N << std::endl;

for (Long64_t i=0; i<N; i++)
{
ee->GetEntry(i);
ee1->Fill(lep_e->Pt());
ee2->Fill(dilep_e->Pt());
ee3->Fill(dilep_e->M());
}

Long64_t M=mumu->GetEntries();
std::cout<<"M events: "<< M << std::endl;

for (Long64_t i=0; i<M; i++)
{
mumu->GetEntry(i);
mumu1->Fill(lep_mu->Pt());
mumu2->Fill(dilep_mu->Pt());
mumu3->Fill(dilep_mu->M());
}

f1->Close();
f2->Close();

c->cd(1);
ee2->Add(ee1,-1);
ee2->Draw("hist");
mumu2->Add(mumu1,-1);
mumu2->SetLineColor(kRed);
mumu2->Draw("hist same");
gPad->BuildLegend(0.9,0.1,0.75,0.3);

c->cd(2);
ee3->Draw("hist");
gausfit->SetLineColor(kRed);
gausfit->Draw();
ee3->Fit("gausfit");

c->cd(4);
mumu3->Draw("hist");
gausfit->SetLineColor(kRed);
gausfit->Draw();
mumu3->Fit("gausfit");
}
