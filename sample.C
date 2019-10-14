#include <TLorentzVector.h>

void sample()
{
TFile* f = new TFile("/home/midorinkk/Downloads/sample.root","READ");
TTree* tree = (TTree*)f->Get("NOMINAL");

TH1F *h11 = new TH1F("Pt", "lep_0_p4_fast; P_{T} [GeV]; Entries", 100, 0, 750);
TH1F *h12 = new TH1F("Eta", "lep_0_p4_fast; Eta; Entries", 100, -3, 3);
TH1F *h13 = new TH1F("Phi", "lep_0_p4_fast; Phi; Entries", 100, -4, 4);
TH1F *h14 = new TH1F("E", "lep_0_p4_fast; E [GeV]; Entries", 100, 0, 2500);

TH1F *h21 = new TH1F("Pt", "dilep_p4_fast; P_{T} [GeV]; Entries", 100, 0, 1000);
TH1F *h22 = new TH1F("Eta", "dilep_p4_fast; Eta; Entries", 100, -11, 11);
TH1F *h23 = new TH1F("Phi", "dilep_p4_fast; Phi; Entries", 100, -4, 4);
TH1F *h24 = new TH1F("E", "dilep_p4_fast; E [GeV]; Entries", 100, 0, 2900);

TH1F *h31 = new TH1F("Pt", "met_reco_p4_fast; P_{T} [GeV]; Entries", 100, 0, 170);
TH1F *h32 = new TH1F("Eta", "met_reco_p4_fast; Eta; Entries", 100, -1.5, 1.5);
TH1F *h33 = new TH1F("Phi", "met_reco_p4_fast; Phi; Entries", 100, -4, 4);
TH1F *h34 = new TH1F("E", "met_reco_p4_fast; E [GeV]; Entries", 100, 0, 170);

TCanvas *c= new TCanvas("c","", 2000, 2000);
c->Divide(4,3);

h11->SetDirectory(gROOT);
h12->SetDirectory(gROOT);
h13->SetDirectory(gROOT);
h14->SetDirectory(gROOT);
h21->SetDirectory(gROOT);
h22->SetDirectory(gROOT);
h23->SetDirectory(gROOT);
h24->SetDirectory(gROOT);
h31->SetDirectory(gROOT);
h32->SetDirectory(gROOT);
h33->SetDirectory(gROOT);
h34->SetDirectory(gROOT);

TLorentzVector* lep_0 = 0;
TLorentzVector* dilep = 0;
TLorentzVector* met_reco = 0;
tree->SetBranchAddress("lep_0_p4", &lep_0);
tree->SetBranchAddress("dilep_p4", &dilep);
tree->SetBranchAddress("met_reco_p4", &met_reco);

Long64_t nEvents = tree->GetEntries();
std::cout<<"N events: "<<nEvents << std::endl;

for (Long64_t i=0; i< nEvents; i++)
{
	tree->GetEntry(i);
	h11->Fill(lep_0->Pt());
	h12->Fill(lep_0->Eta());
	h13->Fill(lep_0->Phi());
	h14->Fill(lep_0->E());
	h21->Fill(dilep->Pt());
	h22->Fill(dilep->Eta());
	h23->Fill(dilep->Phi());
	h24->Fill(dilep->E());
	h31->Fill(met_reco->Pt());
	h32->Fill(met_reco->Eta());
	h33->Fill(met_reco->Phi());
	h34->Fill(met_reco->E());
}

f->Close();

c->cd(1);
h11->Draw();
c->cd(2);
h12->Draw();
c->cd(3);
h13->Draw();
c->cd(4);
h14->Draw();
c->cd(5);
h21->Draw();
c->cd(6);
h22->Draw();
c->cd(7);
h23->Draw();
c->cd(8);
h24->Draw();
c->cd(9);
h31->Draw();
c->cd(10);
h32->Draw();
c->cd(11);
h33->Draw();
c->cd(12);
h34->Draw();

}
