//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jun 16 14:39:47 2022 by ROOT version 6.14/04
// from TTree Nominal/Nominal
// found on file: qqWlvHbbJ_PwPy8MINLO-0.root
//////////////////////////////////////////////////////////

#ifndef ETAnalysis_h
#define ETAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TLorentzVector.h"
#include <iostream>
#include "TH1.h"
#include "TH2.h"

// Header file for the classes stored in the TTree if any.
#include "string"
#include "vector"
#include "vector"
#include "vector"

class ETAnalysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   string          *sample;
   string          *Description;
   Int_t           MCChannelNumber;
   string          *EventFlavor;
   Int_t           RunNumber;
   ULong64_t       EventNumber;
   Float_t         AverageMu;
   Float_t         ActualMu;
   Float_t         AverageMuScaled;
   Float_t         ActualMuScaled;
   Int_t           isMerged;
   Int_t           isResolved;
   Int_t           isOverlap;
   Int_t           passResoSel_noTag;
   Int_t           passBoostSel_noTag;
   Float_t         MCEventWeight;
   Float_t         EventWeight;
   Float_t         BTagSF;
   Float_t         TriggerSF;
   Float_t         LumiWeight;
   Float_t         PUWeight;
   Int_t           flavB1;
   Int_t           flavB2;
   Int_t           flavJ3;
   Float_t         pTV;
   Float_t         MET;
   Float_t         softMET;
   Float_t         metSig;
   Int_t           nTaus;
   Int_t           nTrkJets;
   Int_t           nBTrkJets;
   Float_t         pTV_truth;
   Float_t         etaV_truth;
   Float_t         phiV_truth;
   Float_t         mV_truth;
   Float_t         pTH_truth;
   Float_t         etaH_truth;
   Float_t         phiH_truth;
   Float_t         mH_truth;
   Int_t           Njets_truth_pTjet30;
   vector<float>   *jetvr_pt;
   vector<float>   *jetvr_eta;
   vector<float>   *jetvr_phi;
   vector<float>   *jetvr_e;
   vector<double>  *jetvr_DL1r_pb;
   vector<double>  *jetvr_DL1r_pc;
   vector<double>  *jetvr_DL1r_pu;
   vector<int>     *jetvr_truthflav;
   vector<float>   *jetpf_pt;
   vector<float>   *jetpf_eta;
   vector<float>   *jetpf_phi;
   vector<float>   *jetpf_e;
   vector<double>  *jetpf_DL1r_pb;
   vector<double>  *jetpf_DL1r_pc;
   vector<double>  *jetpf_DL1r_pu;
   vector<int>     *jetpf_truthflav;
   vector<int>     *index_Pflow_to_VR;
   Int_t           nJets;
   Int_t           nSigJets;
   Int_t           nFwdJets;
   Int_t           nbJets;
   Float_t         mVHResolved;
   Float_t         pTVHResolved;
   Float_t         JVTWeightResolved;
   Float_t         sumPtJets;
   Float_t         mBB;
   Float_t         pTBB;
   Float_t         etaBB;
   Float_t         phiBB;
   Float_t         dRBB;
   Float_t         dPhiBB;
   Float_t         dEtaBB;
   Float_t         pTB1;
   Float_t         etaB1;
   Float_t         phiB1;
   Float_t         mB1;
   Float_t         pTB2;
   Float_t         etaB2;
   Float_t         phiB2;
   Float_t         mB2;
   Float_t         pTJ3;
   Float_t         etaJ3;
   Float_t         phiJ3;
   Float_t         mJ3;
   Float_t         bin_bTagB1;
   Float_t         bin_bTagB2;
   Float_t         bin_bTagJ3;
   Float_t         mBBJ;
   Float_t         pTBBJ;
   Float_t         GSCMbb;
   Float_t         OneMuMbb;
   Float_t         PtRecoMbb;
   Double_t        mvaResolved;
   Double_t        mvadiboson;
   vector<float>   *jet_pt;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<float>   *jet_e;
   vector<float>   *jet_jvt;
   vector<int>     *jet_truthflav;
   vector<float>   *el_pt;
   vector<float>   *el_eta;
   vector<float>   *el_phi;
   vector<float>   *el_e;
   vector<float>   *el_charge;
   vector<float>   *mu_pt;
   vector<float>   *mu_eta;
   vector<float>   *mu_phi;
   vector<float>   *mu_e;
   vector<float>   *mu_charge;
   vector<float>   *tau_pt;
   vector<float>   *tau_eta;
   vector<float>   *tau_phi;
   vector<float>   *tau_e;
   vector<float>   *tau_charge;
   Float_t         met_met;
   Float_t         met_phi;
   Float_t         metOverSqrtSumET;
   Float_t         metOverSqrtHT;
   Float_t         LeptonSF;
   Int_t           nElectrons;
   Int_t           nMuons;
   Float_t         ptL1;
   Float_t         etaL1;
   Float_t         phiL1;
   Float_t         mL1;
   Int_t           chargeL1;
   Float_t         lmetdPhi;
   Float_t         mTW;
   Float_t         phiW;
   Float_t         dPhiVBB;
   Float_t         dPhiLBmin;

   // List of branches
   TBranch        *b_sample;   //!
   TBranch        *b_Description;   //!
   TBranch        *b_MCChannelNumber;   //!
   TBranch        *b_EventFlavor;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_AverageMu;   //!
   TBranch        *b_ActualMu;   //!
   TBranch        *b_AverageMuScaled;   //!
   TBranch        *b_ActualMuScaled;   //!
   TBranch        *b_isMerged;   //!
   TBranch        *b_isResolved;   //!
   TBranch        *b_isOverlap;   //!
   TBranch        *b_passResoSel_noTag;   //!
   TBranch        *b_passBoostSel_noTag;   //!
   TBranch        *b_MCEventWeight;   //!
   TBranch        *b_EventWeight;   //!
   TBranch        *b_BTagSF;   //!
   TBranch        *b_TriggerSF;   //!
   TBranch        *b_LumiWeight;   //!
   TBranch        *b_PUWeight;   //!
   TBranch        *b_flavB1;   //!
   TBranch        *b_flavB2;   //!
   TBranch        *b_flavJ3;   //!
   TBranch        *b_pTV;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_softMET;   //!
   TBranch        *b_metSig;   //!
   TBranch        *b_nTaus;   //!
   TBranch        *b_nTrkJets;   //!
   TBranch        *b_nBTrkJets;   //!
   TBranch        *b_pTV_truth;   //!
   TBranch        *b_etaV_truth;   //!
   TBranch        *b_phiV_truth;   //!
   TBranch        *b_mV_truth;   //!
   TBranch        *b_pTH_truth;   //!
   TBranch        *b_etaH_truth;   //!
   TBranch        *b_phiH_truth;   //!
   TBranch        *b_mH_truth;   //!
   TBranch        *b_Njets_truth_pTjet30;   //!
   TBranch        *b_jetvr_pt;   //!
   TBranch        *b_jetvr_eta;   //!
   TBranch        *b_jetvr_phi;   //!
   TBranch        *b_jetvr_e;   //!
   TBranch        *b_jetvr_DL1r_pb;   //!
   TBranch        *b_jetvr_DL1r_pc;   //!
   TBranch        *b_jetvr_DL1r_pu;   //!
   TBranch        *b_jetvr_truthflav;   //!
   TBranch        *b_jetpf_pt;   //!
   TBranch        *b_jetpf_eta;   //!
   TBranch        *b_jetpf_phi;   //!
   TBranch        *b_jetpf_e;   //!
   TBranch        *b_jetpf_DL1r_pb;   //!
   TBranch        *b_jetpf_DL1r_pc;   //!
   TBranch        *b_jetpf_DL1r_pu;   //!
   TBranch        *b_jetpf_truthflav;   //!
   TBranch        *b_index_Pflow_to_VR;   //!
   TBranch        *b_nJets;   //!
   TBranch        *b_nSigJets;   //!
   TBranch        *b_nFwdJets;   //!
   TBranch        *b_nbJets;   //!
   TBranch        *b_mVHResolved;   //!
   TBranch        *b_pTVHResolved;   //!
   TBranch        *b_JVTWeightResolved;   //!
   TBranch        *b_sumPtJets;   //!
   TBranch        *b_mBB;   //!
   TBranch        *b_pTBB;   //!
   TBranch        *b_etaBB;   //!
   TBranch        *b_phiBB;   //!
   TBranch        *b_dRBB;   //!
   TBranch        *b_dPhiBB;   //!
   TBranch        *b_dEtaBB;   //!
   TBranch        *b_pTB1;   //!
   TBranch        *b_etaB1;   //!
   TBranch        *b_phiB1;   //!
   TBranch        *b_mB1;   //!
   TBranch        *b_pTB2;   //!
   TBranch        *b_etaB2;   //!
   TBranch        *b_phiB2;   //!
   TBranch        *b_mB2;   //!
   TBranch        *b_pTJ3;   //!
   TBranch        *b_etaJ3;   //!
   TBranch        *b_phiJ3;   //!
   TBranch        *b_mJ3;   //!
   TBranch        *b_bin_bTagB1;   //!
   TBranch        *b_bin_bTagB2;   //!
   TBranch        *b_bin_bTagJ3;   //!
   TBranch        *b_mBBJ;   //!
   TBranch        *b_pTBBJ;   //!
   TBranch        *b_GSCMbb;   //!
   TBranch        *b_OneMuMbb;   //!
   TBranch        *b_PtRecoMbb;   //!
   TBranch        *b_mvaResolved;   //!
   TBranch        *b_mvadiboson;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_e;   //!
   TBranch        *b_jet_jvt;   //!
   TBranch        *b_jet_truthflav;   //!
   TBranch        *b_el_pt;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_el_e;   //!
   TBranch        *b_el_charge;   //!
   TBranch        *b_mu_pt;   //!
   TBranch        *b_mu_eta;   //!
   TBranch        *b_mu_phi;   //!
   TBranch        *b_mu_e;   //!
   TBranch        *b_mu_charge;   //!
   TBranch        *b_tau_pt;   //!
   TBranch        *b_tau_eta;   //!
   TBranch        *b_tau_phi;   //!
   TBranch        *b_tau_e;   //!
   TBranch        *b_tau_charge;   //!
   TBranch        *b_met_met;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_metOverSqrtSumET;   //!
   TBranch        *b_metOverSqrtHT;   //!
   TBranch        *b_LeptonSF;   //!
   TBranch        *b_nElectrons;   //!
   TBranch        *b_nMuons;   //!
   TBranch        *b_ptL1;   //!
   TBranch        *b_etaL1;   //!
   TBranch        *b_phiL1;   //!
   TBranch        *b_mL1;   //!
   TBranch        *b_chargeL1;   //!
   TBranch        *b_lmetdPhi;   //!
   TBranch        *b_mTW;   //!
   TBranch        *b_phiW;   //!
   TBranch        *b_dPhiVBB;   //!
   TBranch        *b_dPhiLBmin;   //!

   ETAnalysis(TString process = "W");
   virtual ~ETAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   vector<TH1F*>*   GetHistVec(TString name, int nBins, float xlow, float xhigh);
   vector<TH2F*>*   GetHistVec(TString name, int nBinsX, float xlow, float xhigh, int nBinsY, float ylow, float yhigh);
   void             FillHists(vector<bool>* rVec, vector<TH1F*>* hVec, float var, float weight);
   void             FillHists(vector<bool>* rVec, vector<TH2F*>* hVec, float varx, float vary, float weight);
     
   TString m_process;

   TLorentzVector m_b1TLV;
   TLorentzVector m_b2TLV;
   TLorentzVector m_j1TLV;
   TLorentzVector m_j2TLV;
   TLorentzVector m_lepTLV;
   TLorentzVector m_metTLV;

   vector<bool>* jet_isTagged;

};

#endif

#ifdef ETAnalysis_cxx
ETAnalysis::ETAnalysis(TString process) : fChain(0) 
{

  m_process = process;

  if(m_process != "W" && m_process != "ttbar" && m_process != "WH" && m_process != "stop" && m_process != "WZ" && m_process != "data" && m_process != "db" && m_process != "H" && m_process != "Z" && m_process != "stopt" && m_process != "stops" && m_process != "stopWt" && m_process != "other" && m_process != "SigNeg" && m_process != "SigPos" && m_process != "WZjjEWK"){
    cout<<"Available processes are ttbar, stop, W, WZ, data, db, H, Z, other, stopt, stopWt, SigNeg, SigPos, WZjjEWK"<<endl;
    return;
  }

  TChain* ch = new TChain("Nominal");

  if(m_process == "W"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/June2022_nTuples/EasyTree-W*nu*");
  }

  if(m_process == "ttbar"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/June2022_nTuples/EasyTree-ttbar*");
  }

  if(m_process == "WH"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/June2022_nTuples/EasyTree-qqWlvHbbJ*");
  }

  if(m_process == "stop"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/June2022_nTuples/EasyTree-stop*");
  }

  if(m_process == "stopt"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/June2022_nTuples/EasyTree-stopt*");
  }

  if(m_process == "stops"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/June2022_nTuples/EasyTree-stops*");
  }

  if(m_process == "stopWt"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/June2022_nTuples/EasyTree-stopWt*");
  }

  if(m_process == "WZ"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/June2022_nTuples/EasyTree-WlvZbb*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-WlvZcc*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-WlvZqq*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-WqqZll*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/August2022_nTuples_WZjjEWK/EasyTree-WZjjEWK*");
  }

  if(m_process == "data"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/June2022_nTuples/EasyTree-data*");
  }

  if(m_process == "other"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-WqqWlv*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-Z*Z*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-Zee*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-Zmumu*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-Ztautau*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-*ZllHbb*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-ttH*");
  }

  if(m_process == "db"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-WqqWlv*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-Z*Z*");
  }

  if(m_process == "Z"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-Zee*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-Zmumu*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-Ztautau*");
  }

  if(m_process == "H"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-*ZllHbb*");
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/July2022_nTuples/EasyTree-ttH*");
  }

  if(m_process == "SigNeg"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/August2022_nTuples_SIGNAL/EasyTree-VBFWHlvbbNeg*");
  }

  if(m_process == "SigPos"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/August2022_nTuples_SIGNAL/EasyTree-VBFWHlvbbPos*");
  }

  if(m_process == "WZjjEWK"){
    ch->Add("/eos/user/e/estaats/Analysis/Rare_Higgs/nTuples_hadded/August2022_nTuples_WZjjEWK/EasyTree-WZjjEWK*");
  }


  Init(ch);
  Loop();

}

ETAnalysis::~ETAnalysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ETAnalysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ETAnalysis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void ETAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   sample = 0;
   Description = 0;
   EventFlavor = 0;
   jetvr_pt = 0;
   jetvr_eta = 0;
   jetvr_phi = 0;
   jetvr_e = 0;
   jetvr_DL1r_pb = 0;
   jetvr_DL1r_pc = 0;
   jetvr_DL1r_pu = 0;
   jetvr_truthflav = 0;
   jetpf_pt = 0;
   jetpf_eta = 0;
   jetpf_phi = 0;
   jetpf_e = 0;
   jetpf_DL1r_pb = 0;
   jetpf_DL1r_pc = 0;
   jetpf_DL1r_pu = 0;
   jetpf_truthflav = 0;
   index_Pflow_to_VR = 0;
   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_e = 0;
   jet_jvt = 0;
   jet_truthflav = 0;
   el_pt = 0;
   el_eta = 0;
   el_phi = 0;
   el_e = 0;
   el_charge = 0;
   mu_pt = 0;
   mu_eta = 0;
   mu_phi = 0;
   mu_e = 0;
   mu_charge = 0;
   tau_pt = 0;
   tau_eta = 0;
   tau_phi = 0;
   tau_e = 0;
   tau_charge = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("sample", &sample, &b_sample);
   fChain->SetBranchAddress("Description", &Description, &b_Description);
   fChain->SetBranchAddress("MCChannelNumber", &MCChannelNumber, &b_MCChannelNumber);
   fChain->SetBranchAddress("EventFlavor", &EventFlavor, &b_EventFlavor);
   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("AverageMu", &AverageMu, &b_AverageMu);
   fChain->SetBranchAddress("ActualMu", &ActualMu, &b_ActualMu);
   fChain->SetBranchAddress("AverageMuScaled", &AverageMuScaled, &b_AverageMuScaled);
   fChain->SetBranchAddress("ActualMuScaled", &ActualMuScaled, &b_ActualMuScaled);
   fChain->SetBranchAddress("isMerged", &isMerged, &b_isMerged);
   fChain->SetBranchAddress("isResolved", &isResolved, &b_isResolved);
   fChain->SetBranchAddress("isOverlap", &isOverlap, &b_isOverlap);
   fChain->SetBranchAddress("passResoSel_noTag", &passResoSel_noTag, &b_passResoSel_noTag);
   fChain->SetBranchAddress("passBoostSel_noTag", &passBoostSel_noTag, &b_passBoostSel_noTag);
   fChain->SetBranchAddress("MCEventWeight", &MCEventWeight, &b_MCEventWeight);
   fChain->SetBranchAddress("EventWeight", &EventWeight, &b_EventWeight);
   fChain->SetBranchAddress("BTagSF", &BTagSF, &b_BTagSF);
   fChain->SetBranchAddress("TriggerSF", &TriggerSF, &b_TriggerSF);
   fChain->SetBranchAddress("LumiWeight", &LumiWeight, &b_LumiWeight);
   fChain->SetBranchAddress("PUWeight", &PUWeight, &b_PUWeight);
   fChain->SetBranchAddress("flavB1", &flavB1, &b_flavB1);
   fChain->SetBranchAddress("flavB2", &flavB2, &b_flavB2);
   fChain->SetBranchAddress("flavJ3", &flavJ3, &b_flavJ3);
   fChain->SetBranchAddress("pTV", &pTV, &b_pTV);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("softMET", &softMET, &b_softMET);
   fChain->SetBranchAddress("metSig", &metSig, &b_metSig);
   fChain->SetBranchAddress("nTaus", &nTaus, &b_nTaus);
   fChain->SetBranchAddress("nTrkJets", &nTrkJets, &b_nTrkJets);
   fChain->SetBranchAddress("nBTrkJets", &nBTrkJets, &b_nBTrkJets);
   fChain->SetBranchAddress("pTV_truth", &pTV_truth, &b_pTV_truth);
   fChain->SetBranchAddress("etaV_truth", &etaV_truth, &b_etaV_truth);
   fChain->SetBranchAddress("phiV_truth", &phiV_truth, &b_phiV_truth);
   fChain->SetBranchAddress("mV_truth", &mV_truth, &b_mV_truth);
   fChain->SetBranchAddress("pTH_truth", &pTH_truth, &b_pTH_truth);
   fChain->SetBranchAddress("etaH_truth", &etaH_truth, &b_etaH_truth);
   fChain->SetBranchAddress("phiH_truth", &phiH_truth, &b_phiH_truth);
   fChain->SetBranchAddress("mH_truth", &mH_truth, &b_mH_truth);
   fChain->SetBranchAddress("Njets_truth_pTjet30", &Njets_truth_pTjet30, &b_Njets_truth_pTjet30);
   fChain->SetBranchAddress("jetvr_pt", &jetvr_pt, &b_jetvr_pt);
   fChain->SetBranchAddress("jetvr_eta", &jetvr_eta, &b_jetvr_eta);
   fChain->SetBranchAddress("jetvr_phi", &jetvr_phi, &b_jetvr_phi);
   fChain->SetBranchAddress("jetvr_e", &jetvr_e, &b_jetvr_e);
   fChain->SetBranchAddress("jetvr_DL1r_pb", &jetvr_DL1r_pb, &b_jetvr_DL1r_pb);
   fChain->SetBranchAddress("jetvr_DL1r_pc", &jetvr_DL1r_pc, &b_jetvr_DL1r_pc);
   fChain->SetBranchAddress("jetvr_DL1r_pu", &jetvr_DL1r_pu, &b_jetvr_DL1r_pu);
   fChain->SetBranchAddress("jetvr_truthflav", &jetvr_truthflav, &b_jetvr_truthflav);
   fChain->SetBranchAddress("jetpf_pt", &jetpf_pt, &b_jetpf_pt);
   fChain->SetBranchAddress("jetpf_eta", &jetpf_eta, &b_jetpf_eta);
   fChain->SetBranchAddress("jetpf_phi", &jetpf_phi, &b_jetpf_phi);
   fChain->SetBranchAddress("jetpf_e", &jetpf_e, &b_jetpf_e);
   fChain->SetBranchAddress("jetpf_DL1r_pb", &jetpf_DL1r_pb, &b_jetpf_DL1r_pb);
   fChain->SetBranchAddress("jetpf_DL1r_pc", &jetpf_DL1r_pc, &b_jetpf_DL1r_pc);
   fChain->SetBranchAddress("jetpf_DL1r_pu", &jetpf_DL1r_pu, &b_jetpf_DL1r_pu);
   fChain->SetBranchAddress("jetpf_truthflav", &jetpf_truthflav, &b_jetpf_truthflav);
   fChain->SetBranchAddress("index_Pflow_to_VR", &index_Pflow_to_VR, &b_index_Pflow_to_VR);
   fChain->SetBranchAddress("nJets", &nJets, &b_nJets);
   fChain->SetBranchAddress("nSigJets", &nSigJets, &b_nSigJets);
   fChain->SetBranchAddress("nFwdJets", &nFwdJets, &b_nFwdJets);
   fChain->SetBranchAddress("nbJets", &nbJets, &b_nbJets);
   fChain->SetBranchAddress("mVHResolved", &mVHResolved, &b_mVHResolved);
   fChain->SetBranchAddress("pTVHResolved", &pTVHResolved, &b_pTVHResolved);
   fChain->SetBranchAddress("JVTWeightResolved", &JVTWeightResolved, &b_JVTWeightResolved);
   fChain->SetBranchAddress("sumPtJets", &sumPtJets, &b_sumPtJets);
   fChain->SetBranchAddress("mBB", &mBB, &b_mBB);
   fChain->SetBranchAddress("pTBB", &pTBB, &b_pTBB);
   fChain->SetBranchAddress("etaBB", &etaBB, &b_etaBB);
   fChain->SetBranchAddress("phiBB", &phiBB, &b_phiBB);
   fChain->SetBranchAddress("dRBB", &dRBB, &b_dRBB);
   fChain->SetBranchAddress("dPhiBB", &dPhiBB, &b_dPhiBB);
   fChain->SetBranchAddress("dEtaBB", &dEtaBB, &b_dEtaBB);
   fChain->SetBranchAddress("pTB1", &pTB1, &b_pTB1);
   fChain->SetBranchAddress("etaB1", &etaB1, &b_etaB1);
   fChain->SetBranchAddress("phiB1", &phiB1, &b_phiB1);
   fChain->SetBranchAddress("mB1", &mB1, &b_mB1);
   fChain->SetBranchAddress("pTB2", &pTB2, &b_pTB2);
   fChain->SetBranchAddress("etaB2", &etaB2, &b_etaB2);
   fChain->SetBranchAddress("phiB2", &phiB2, &b_phiB2);
   fChain->SetBranchAddress("mB2", &mB2, &b_mB2);
   fChain->SetBranchAddress("pTJ3", &pTJ3, &b_pTJ3);
   fChain->SetBranchAddress("etaJ3", &etaJ3, &b_etaJ3);
   fChain->SetBranchAddress("phiJ3", &phiJ3, &b_phiJ3);
   fChain->SetBranchAddress("mJ3", &mJ3, &b_mJ3);
   fChain->SetBranchAddress("bin_bTagB1", &bin_bTagB1, &b_bin_bTagB1);
   fChain->SetBranchAddress("bin_bTagB2", &bin_bTagB2, &b_bin_bTagB2);
   fChain->SetBranchAddress("bin_bTagJ3", &bin_bTagJ3, &b_bin_bTagJ3);
   fChain->SetBranchAddress("mBBJ", &mBBJ, &b_mBBJ);
   fChain->SetBranchAddress("pTBBJ", &pTBBJ, &b_pTBBJ);
   fChain->SetBranchAddress("GSCMbb", &GSCMbb, &b_GSCMbb);
   fChain->SetBranchAddress("OneMuMbb", &OneMuMbb, &b_OneMuMbb);
   fChain->SetBranchAddress("PtRecoMbb", &PtRecoMbb, &b_PtRecoMbb);
   fChain->SetBranchAddress("mvaResolved", &mvaResolved, &b_mvaResolved);
   fChain->SetBranchAddress("mvadiboson", &mvadiboson, &b_mvadiboson);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_e", &jet_e, &b_jet_e);
   fChain->SetBranchAddress("jet_jvt", &jet_jvt, &b_jet_jvt);
   fChain->SetBranchAddress("jet_truthflav", &jet_truthflav, &b_jet_truthflav);
   fChain->SetBranchAddress("el_pt", &el_pt, &b_el_pt);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("el_e", &el_e, &b_el_e);
   fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
   fChain->SetBranchAddress("mu_pt", &mu_pt, &b_mu_pt);
   fChain->SetBranchAddress("mu_eta", &mu_eta, &b_mu_eta);
   fChain->SetBranchAddress("mu_phi", &mu_phi, &b_mu_phi);
   fChain->SetBranchAddress("mu_e", &mu_e, &b_mu_e);
   fChain->SetBranchAddress("mu_charge", &mu_charge, &b_mu_charge);
   fChain->SetBranchAddress("tau_pt", &tau_pt, &b_tau_pt);
   fChain->SetBranchAddress("tau_eta", &tau_eta, &b_tau_eta);
   fChain->SetBranchAddress("tau_phi", &tau_phi, &b_tau_phi);
   fChain->SetBranchAddress("tau_e", &tau_e, &b_tau_e);
   fChain->SetBranchAddress("tau_charge", &tau_charge, &b_tau_charge);
   fChain->SetBranchAddress("met_met", &met_met, &b_met_met);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("metOverSqrtSumET", &metOverSqrtSumET, &b_metOverSqrtSumET);
   fChain->SetBranchAddress("metOverSqrtHT", &metOverSqrtHT, &b_metOverSqrtHT);
   fChain->SetBranchAddress("LeptonSF", &LeptonSF, &b_LeptonSF);
   fChain->SetBranchAddress("nElectrons", &nElectrons, &b_nElectrons);
   fChain->SetBranchAddress("nMuons", &nMuons, &b_nMuons);
   fChain->SetBranchAddress("ptL1", &ptL1, &b_ptL1);
   fChain->SetBranchAddress("etaL1", &etaL1, &b_etaL1);
   fChain->SetBranchAddress("phiL1", &phiL1, &b_phiL1);
   fChain->SetBranchAddress("mL1", &mL1, &b_mL1);
   fChain->SetBranchAddress("chargeL1", &chargeL1, &b_chargeL1);
   fChain->SetBranchAddress("lmetdPhi", &lmetdPhi, &b_lmetdPhi);
   fChain->SetBranchAddress("mTW", &mTW, &b_mTW);
   fChain->SetBranchAddress("phiW", &phiW, &b_phiW);
   fChain->SetBranchAddress("dPhiVBB", &dPhiVBB, &b_dPhiVBB);
   fChain->SetBranchAddress("dPhiLBmin", &dPhiLBmin, &b_dPhiLBmin);
   Notify();
}

Bool_t ETAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void ETAnalysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t ETAnalysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef ETAnalysis_cxx
