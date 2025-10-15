
//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jun 16 14:39:47 2022 by ROOT version 6.14/04
// from TTree Nominal/Nominal
// found on file: qqWlvHbbJ_PwPy8MINLO-0.root
//////////////////////////////////////////////////////////

#ifndef SysAnalysis_h
#define SysAnalysis_h

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

class SysAnalysis {
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
   Float_t         MCEventWeight;
   Float_t         EventWeight;
   Float_t         BTagSF;
   Float_t         TriggerSF;
   Float_t         LumiWeight;
   Float_t         PUWeight;
   Int_t           flavB1;
   Int_t           flavB2;
   Float_t         pTV;
   Float_t         MET;
   Float_t         softMET;
   Float_t         metSig;
   Int_t           nTaus;
   Int_t           Njets_truth_pTjet30;
   Float_t         Sys__MUR05_MUF05;
   Float_t         Sys__MUR05_MUF1;
   Float_t         Sys__MUR1_MUF05;
   Float_t         Sys__MUR1_MUF2;
   Float_t         Sys__MUR2_MUF1;
   Float_t         Sys__MUR2_MUF2;
   Float_t         Sys__PDF13165;
   Float_t         Sys__PDF25200;
   Float_t         Sys__PDF260000;
   Float_t         Sys__PDF260001;
   Float_t         Sys__PDF260002;
   Float_t         Sys__PDF260003;
   Float_t         Sys__PDF260004;
   Float_t         Sys__PDF260005;
   Float_t         Sys__PDF260006;
   Float_t         Sys__PDF260007;
   Float_t         Sys__PDF260008;
   Float_t         Sys__PDF260009;
   Float_t         Sys__PDF260010;
   Float_t         Sys__PDF260011;
   Float_t         Sys__PDF260012;
   Float_t         Sys__PDF260013;
   Float_t         Sys__PDF260014;
   Float_t         Sys__PDF260015;
   Float_t         Sys__PDF260016;
   Float_t         Sys__PDF260017;
   Float_t         Sys__PDF260018;
   Float_t         Sys__PDF260019;
   Float_t         Sys__PDF260020;
   Float_t         Sys__PDF260021;
   Float_t         Sys__PDF260022;
   Float_t         Sys__PDF260023;
   Float_t         Sys__PDF260024;
   Float_t         Sys__PDF260025;
   Float_t         Sys__PDF260026;
   Float_t         Sys__PDF260027;
   Float_t         Sys__PDF260028;
   Float_t         Sys__PDF260029;
   Float_t         Sys__PDF260030;
   Float_t         Sys__PDF260031;
   Float_t         Sys__PDF260032;
   Float_t         Sys__PDF260033;
   Float_t         Sys__PDF260034;
   Float_t         Sys__PDF260035;
   Float_t         Sys__PDF260036;
   Float_t         Sys__PDF260037;
   Float_t         Sys__PDF260038;
   Float_t         Sys__PDF260039;
   Float_t         Sys__PDF260040;
   Float_t         Sys__PDF260041;
   Float_t         Sys__PDF260042;
   Float_t         Sys__PDF260043;
   Float_t         Sys__PDF260044;
   Float_t         Sys__PDF260045;
   Float_t         Sys__PDF260046;
   Float_t         Sys__PDF260047;
   Float_t         Sys__PDF260048;
   Float_t         Sys__PDF260049;
   Float_t         Sys__PDF260050;
   Float_t         Sys__PDF260051;
   Float_t         Sys__PDF260052;
   Float_t         Sys__PDF260053;
   Float_t         Sys__PDF260054;
   Float_t         Sys__PDF260055;
   Float_t         Sys__PDF260056;
   Float_t         Sys__PDF260057;
   Float_t         Sys__PDF260058;
   Float_t         Sys__PDF260059;
   Float_t         Sys__PDF260060;
   Float_t         Sys__PDF260061;
   Float_t         Sys__PDF260062;
   Float_t         Sys__PDF260063;
   Float_t         Sys__PDF260064;
   Float_t         Sys__PDF260065;
   Float_t         Sys__PDF260066;
   Float_t         Sys__PDF260067;
   Float_t         Sys__PDF260068;
   Float_t         Sys__PDF260069;
   Float_t         Sys__PDF260070;
   Float_t         Sys__PDF260071;
   Float_t         Sys__PDF260072;
   Float_t         Sys__PDF260073;
   Float_t         Sys__PDF260074;
   Float_t         Sys__PDF260075;
   Float_t         Sys__PDF260076;
   Float_t         Sys__PDF260077;
   Float_t         Sys__PDF260078;
   Float_t         Sys__PDF260079;
   Float_t         Sys__PDF260080;
   Float_t         Sys__PDF260081;
   Float_t         Sys__PDF260082;
   Float_t         Sys__PDF260083;
   Float_t         Sys__PDF260084;
   Float_t         Sys__PDF260085;
   Float_t         Sys__PDF260086;
   Float_t         Sys__PDF260087;
   Float_t         Sys__PDF260088;
   Float_t         Sys__PDF260089;
   Float_t         Sys__PDF260090;
   Float_t         Sys__PDF260091;
   Float_t         Sys__PDF260092;
   Float_t         Sys__PDF260093;
   Float_t         Sys__PDF260094;
   Float_t         Sys__PDF260095;
   Float_t         Sys__PDF260096;
   Float_t         Sys__PDF260097;
   Float_t         Sys__PDF260098;
   Float_t         Sys__PDF260099;
   Float_t         Sys__PDF260100;
   Float_t         Sys__PDF265000;
   Float_t         Sys__PDF266000;
   Float_t         Sys__kZ087kW093;
   Float_t         Sys__kZ087kW105;
   Float_t         Sys__kZ091kW113;
   Float_t         Sys__kZ093kW099;
   Float_t         Sys__kZ093kW105;
   Float_t         Sys__kZ094kW111;
   Float_t         Sys__kZ099kW093;
   Float_t         Sys__kZ099kW105;
   Float_t         Sys__kZ099kW111;
   Float_t         Sys__kZ099kW117;
   Float_t         Sys__kZ105kW099;
   Float_t         Sys__kZ105kW105;
   Float_t         Sys__kZ105kW111;
   Float_t         Sys__kZ108kW095;
   Float_t         Sys__kZ111kW105;
   Float_t         Sys__kZ111kW117;
   Int_t           TTBarDecay;
   Float_t         Sys__MUON_EFF_TrigSystUncertainty__1up;
   Float_t         Sys__MUON_EFF_TrigSystUncertainty__1down;
   Float_t         Sys__MUON_EFF_TrigStatUncertainty__1up;
   Float_t         Sys__MUON_EFF_TrigStatUncertainty__1down;
   Float_t         Sys__METTrigStat__1up;
   Float_t         Sys__METTrigStat__1down;
   Float_t         Sys__METTrigTop__1up;
   Float_t         Sys__METTrigTop__1down;
   Float_t         Sys__METTrigZ__1up;
   Float_t         Sys__METTrigZ__1down;
   Float_t         Sys__METTrigSumpt__1up;
   Float_t         Sys__METTrigSumpt__1down;
   Float_t         Sys__B_0;
   Float_t         Sys__B_10;
   Float_t         Sys__B_11;
   Float_t         Sys__B_12;
   Float_t         Sys__B_13;
   Float_t         Sys__B_14;
   Float_t         Sys__B_15;
   Float_t         Sys__B_16;
   Float_t         Sys__B_17;
   Float_t         Sys__B_18;
   Float_t         Sys__B_19;
   Float_t         Sys__B_1;
   Float_t         Sys__B_20;
   Float_t         Sys__B_21;
   Float_t         Sys__B_22;
   Float_t         Sys__B_23;
   Float_t         Sys__B_24;
   Float_t         Sys__B_25;
   Float_t         Sys__B_26;
   Float_t         Sys__B_27;
   Float_t         Sys__B_28;
   Float_t         Sys__B_29;
   Float_t         Sys__B_2;
   Float_t         Sys__B_30;
   Float_t         Sys__B_31;
   Float_t         Sys__B_32;
   Float_t         Sys__B_33;
   Float_t         Sys__B_34;
   Float_t         Sys__B_35;
   Float_t         Sys__B_36;
   Float_t         Sys__B_37;
   Float_t         Sys__B_38;
   Float_t         Sys__B_39;
   Float_t         Sys__B_3;
   Float_t         Sys__B_40;
   Float_t         Sys__B_41;
   Float_t         Sys__B_42;
   Float_t         Sys__B_43;
   Float_t         Sys__B_44;
   Float_t         Sys__B_4;
   Float_t         Sys__B_5;
   Float_t         Sys__B_6;
   Float_t         Sys__B_7;
   Float_t         Sys__B_8;
   Float_t         Sys__B_9;
   Float_t         Sys__C_0;
   Float_t         Sys__C_10;
   Float_t         Sys__C_11;
   Float_t         Sys__C_12;
   Float_t         Sys__C_13;
   Float_t         Sys__C_14;
   Float_t         Sys__C_15;
   Float_t         Sys__C_16;
   Float_t         Sys__C_17;
   Float_t         Sys__C_18;
   Float_t         Sys__C_19;
   Float_t         Sys__C_1;
   Float_t         Sys__C_2;
   Float_t         Sys__C_3;
   Float_t         Sys__C_4;
   Float_t         Sys__C_5;
   Float_t         Sys__C_6;
   Float_t         Sys__C_7;
   Float_t         Sys__C_8;
   Float_t         Sys__C_9;
   Float_t         Sys__Light_0;
   Float_t         Sys__Light_10;
   Float_t         Sys__Light_11;
   Float_t         Sys__Light_12;
   Float_t         Sys__Light_13;
   Float_t         Sys__Light_14;
   Float_t         Sys__Light_15;
   Float_t         Sys__Light_16;
   Float_t         Sys__Light_17;
   Float_t         Sys__Light_18;
   Float_t         Sys__Light_19;
   Float_t         Sys__Light_1;
   Float_t         Sys__Light_2;
   Float_t         Sys__Light_3;
   Float_t         Sys__Light_4;
   Float_t         Sys__Light_5;
   Float_t         Sys__Light_6;
   Float_t         Sys__Light_7;
   Float_t         Sys__Light_8;
   Float_t         Sys__Light_9;
   Int_t           nJets;
   Int_t           nSigJets;
   Int_t           nFwdJets;
   Int_t           nbJets;
   Float_t         JVTWeightResolved;
   Float_t         fJVTSF;
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
   Float_t         bin_bTagB1;
   Float_t         bin_bTagB2;
   vector<float>   *jet_pt;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<float>   *jet_e;
   vector<int>     *jet_truthflav;
   vector<int>     *jet_btagbin;
   Float_t         met_phi;
   Double_t        SUSYMET;
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
   Float_t         mTW;
   Float_t         vbf_j1_pt;
   Float_t         vbf_j1_eta;
   Float_t         vbf_j1_phi;
   Float_t         vbf_j1_m;
   Float_t         vbf_j2_pt;
   Float_t         vbf_j2_eta;
   Float_t         vbf_j2_phi;
   Float_t         vbf_j2_m;
   Float_t         vbf_dyjj;
   Float_t         vbf_mjj;
   Float_t         vbf_mLepTop;
   Float_t         vbf_centralityHW;
   Float_t         vbf_dphiHWjj;
   Int_t           vbf_nVeto25;
   Float_t         Sys__RadLo;
   Float_t         Sys__RadHi;
   Float_t         Sys__RadHiPrime;
   Float_t         Sys__MUR__1up;
   Float_t         Sys__MUR1_MUF1_PDF13000;
   Float_t         Sys__MURMUF__1up;
   Float_t         Sys__MUR1_MUF1_PDF269000;
   Float_t         Sys__MUR1_MUF1_PDF25300;
   Float_t         Sys__MUR__1down;
   Float_t         Sys__MUF__1up;
   Float_t         Sys__MUF__1down;
   Float_t         Sys__FSR__1up;
   Float_t         Sys__FSR__1down;
   Float_t         Sys__MUR1_MUF1_PDF270000;
   Float_t         Sys__MURMUF__1down;
   Float_t         passIsoNom;
   Float_t         Sys__MUR1_MUF1_PDF303200_EXPASSEW;
   Float_t         Sys__MUR1_MUF1_PDF303200_MULTIASSEW;
   Float_t         Sys__MUR1_MUF1_PDF303200_ASSEW;
   Float_t         Sys__Var3cUp;
   Float_t         Sys__Var3cDown;

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
   TBranch        *b_MCEventWeight;   //!
   TBranch        *b_EventWeight;   //!
   TBranch        *b_BTagSF;   //!
   TBranch        *b_TriggerSF;   //!
   TBranch        *b_LumiWeight;   //!
   TBranch        *b_PUWeight;   //!
   TBranch        *b_flavB1;   //!
   TBranch        *b_flavB2;   //!
   TBranch        *b_pTV;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_softMET;   //!
   TBranch        *b_metSig;   //!
   TBranch        *b_nTaus;   //!
   TBranch        *b_Njets_truth_pTjet30;   //!
   TBranch        *b_Sys__PDF13165;   //!
   TBranch        *b_Sys__PDF25200;   //!
   TBranch        *b_Sys__PDF260071;   //!
   TBranch        *b_Sys__PDF260069;   //!
   TBranch        *b_Sys__PDF260070;   //!
   TBranch        *b_Sys__PDF260068;   //!
   TBranch        *b_Sys__PDF260067;   //!
   TBranch        *b_Sys__PDF260082;   //!
   TBranch        *b_Sys__PDF260062;   //!
   TBranch        *b_Sys__PDF260042;   //!
   TBranch        *b_Sys__PDF260021;   //!
   TBranch        *b_Sys__PDF260061;   //!
   TBranch        *b_Sys__PDF260060;   //!
   TBranch        *b_Sys__PDF260088;   //!
   TBranch        *b_Sys__PDF260056;   //!
   TBranch        *b_Sys__PDF260083;   //!
   TBranch        *b_Sys__PDF260051;   //!
   TBranch        *b_Sys__PDF260049;   //!
   TBranch        *b_Sys__PDF260095;   //!
   TBranch        *b_Sys__PDF260099;   //!
   TBranch        *b_Sys__PDF260048;   //!
   TBranch        *b_Sys__PDF260046;   //!
   TBranch        *b_Sys__kZ093kW105;   //!
   TBranch        *b_Sys__PDF260045;   //!
   TBranch        *b_Sys__PDF260043;   //!
   TBranch        *b_Sys__PDF260039;   //!
   TBranch        *b_Sys__PDF260038;   //!
   TBranch        *b_Sys__PDF260037;   //!
   TBranch        *b_Sys__PDF260055;   //!
   TBranch        *b_Sys__PDF260007;   //!
   TBranch        *b_Sys__kZ087kW105;   //!
   TBranch        *b_Sys__PDF260035;   //!
   TBranch        *b_Sys__kZ111kW117;   //!
   TBranch        *b_Sys__PDF260033;   //!
   TBranch        *b_Sys__PDF260036;   //!
   TBranch        *b_Sys__PDF260090;   //!
   TBranch        *b_Sys__PDF260044;   //!
   TBranch        *b_Sys__PDF260032;   //!
   TBranch        *b_Sys__PDF260031;   //!
   TBranch        *b_Sys__PDF260030;   //!
   TBranch        *b_Sys__PDF260009;   //!
   TBranch        *b_Sys__PDF260073;   //!
   TBranch        *b_Sys__PDF260052;   //!
   TBranch        *b_Sys__PDF260019;   //!
   TBranch        *b_Sys__PDF260022;   //!
   TBranch        *b_Sys__PDF260029;   //!
   TBranch        *b_Sys__PDF260011;   //!
   TBranch        *b_Sys__PDF260064;   //!
   TBranch        *b_Sys__PDF260040;   //!
   TBranch        *b_Sys__PDF260020;   //!
   TBranch        *b_Sys__PDF260026;   //!
   TBranch        *b_Sys__PDF260006;   //!
   TBranch        *b_Sys__PDF260028;   //!
   TBranch        *b_Sys__PDF260079;   //!
   TBranch        *b_Sys__PDF260086;   //!
   TBranch        *b_Sys__MUR2_MUF1;   //!
   TBranch        *b_Sys__PDF260076;   //!
   TBranch        *b_Sys__PDF260017;   //!
   TBranch        *b_Sys__PDF260016;   //!
   TBranch        *b_Sys__MUR2_MUF2;   //!
   TBranch        *b_Sys__PDF260072;   //!
   TBranch        *b_Sys__PDF260092;   //!
   TBranch        *b_Sys__PDF260075;   //!
   TBranch        *b_Sys__PDF260078;   //!
   TBranch        *b_Sys__PDF260077;   //!
   TBranch        *b_Sys__PDF260087;   //!
   TBranch        *b_Sys__PDF260080;   //!
   TBranch        *b_Sys__PDF260074;   //!
   TBranch        *b_Sys__PDF260097;   //!
   TBranch        *b_Sys__PDF260081;   //!
   TBranch        *b_Sys__kZ099kW117;   //!
   TBranch        *b_Sys__kZ099kW111;   //!
   TBranch        *b_Sys__kZ108kW095;   //!
   TBranch        *b_Sys__kZ105kW099;   //!
   TBranch        *b_Sys__kZ087kW093;   //!
   TBranch        *b_Sys__kZ105kW105;   //!
   TBranch        *b_Sys__kZ105kW111;   //!
   TBranch        *b_Sys__PDF260094;   //!
   TBranch        *b_Sys__PDF260089;   //!
   TBranch        *b_Sys__PDF260091;   //!
   TBranch        *b_Sys__kZ093kW099;   //!
   TBranch        *b_Sys__PDF260066;   //!
   TBranch        *b_Sys__kZ099kW105;   //!
   TBranch        *b_Sys__kZ091kW113;   //!
   TBranch        *b_Sys__kZ111kW105;   //!
   TBranch        *b_Sys__PDF260005;   //!
   TBranch        *b_Sys__PDF260058;   //!
   TBranch        *b_Sys__PDF260096;   //!
   TBranch        *b_Sys__PDF260024;   //!
   TBranch        *b_Sys__PDF260085;   //!
   TBranch        *b_Sys__PDF260001;   //!
   TBranch        *b_Sys__PDF260047;   //!
   TBranch        *b_Sys__PDF260057;   //!
   TBranch        *b_Sys__PDF260093;   //!
   TBranch        *b_Sys__PDF266000;   //!
   TBranch        *b_Sys__PDF260025;   //!
   TBranch        *b_Sys__PDF265000;   //!
   TBranch        *b_Sys__PDF260054;   //!
   TBranch        *b_Sys__PDF260013;   //!
   TBranch        *b_Sys__PDF260012;   //!
   TBranch        *b_Sys__PDF260014;   //!
   TBranch        *b_Sys__PDF260053;   //!
   TBranch        *b_Sys__MUR1_MUF2;   //!
   TBranch        *b_Sys__PDF260004;   //!
   TBranch        *b_Sys__MUR1_MUF05;   //!
   TBranch        *b_Sys__MUR05_MUF05;   //!
   TBranch        *b_Sys__PDF260063;   //!
   TBranch        *b_Sys__PDF260098;   //!
   TBranch        *b_Sys__PDF260018;   //!
   TBranch        *b_Sys__PDF260027;   //!
   TBranch        *b_Sys__PDF260034;   //!
   TBranch        *b_Sys__MUR05_MUF1;   //!
   TBranch        *b_Sys__PDF260050;   //!
   TBranch        *b_Sys__PDF260010;   //!
   TBranch        *b_Sys__PDF260000;   //!
   TBranch        *b_Sys__PDF260008;   //!
   TBranch        *b_Sys__PDF260100;   //!
   TBranch        *b_Sys__PDF260084;   //!
   TBranch        *b_Sys__PDF260023;   //!
   TBranch        *b_Sys__PDF260002;   //!
   TBranch        *b_Sys__PDF260003;   //!
   TBranch        *b_Sys__PDF260041;   //!
   TBranch        *b_Sys__kZ094kW111;   //!
   TBranch        *b_Sys__PDF260059;   //!
   TBranch        *b_Sys__PDF260065;   //!
   TBranch        *b_Sys__kZ099kW093;   //!
   TBranch        *b_Sys__PDF260015;   //!
   TBranch        *b_TTBarDecay;   //!
   TBranch        *b_Sys__MUON_EFF_TrigSystUncertainty__1up;   //!
   TBranch        *b_Sys__MUON_EFF_TrigSystUncertainty__1down;   //!
   TBranch        *b_Sys__MUON_EFF_TrigStatUncertainty__1up;   //!
   TBranch        *b_Sys__MUON_EFF_TrigStatUncertainty__1down;   //!
   TBranch        *b_Sys__METTrigStat__1up;   //!
   TBranch        *b_Sys__METTrigStat__1down;   //!
   TBranch        *b_Sys__METTrigTop__1up;   //!
   TBranch        *b_Sys__METTrigTop__1down;   //!
   TBranch        *b_Sys__METTrigZ__1up;   //!
   TBranch        *b_Sys__METTrigZ__1down;   //!
   TBranch        *b_Sys__METTrigSumpt__1up;   //!
   TBranch        *b_Sys__METTrigSumpt__1down;   //!
   TBranch        *b_Sys__B_0;   //!
   TBranch        *b_Sys__B_10;   //!
   TBranch        *b_Sys__B_11;   //!
   TBranch        *b_Sys__B_12;   //!
   TBranch        *b_Sys__B_13;   //!
   TBranch        *b_Sys__B_14;   //!
   TBranch        *b_Sys__B_15;   //!
   TBranch        *b_Sys__B_16;   //!
   TBranch        *b_Sys__B_17;   //!
   TBranch        *b_Sys__B_18;   //!
   TBranch        *b_Sys__B_19;   //!
   TBranch        *b_Sys__B_1;   //!
   TBranch        *b_Sys__B_20;   //!
   TBranch        *b_Sys__B_21;   //!
   TBranch        *b_Sys__B_22;   //!
   TBranch        *b_Sys__B_23;   //!
   TBranch        *b_Sys__B_24;   //!
   TBranch        *b_Sys__B_25;   //!
   TBranch        *b_Sys__B_26;   //!
   TBranch        *b_Sys__B_27;   //!
   TBranch        *b_Sys__B_28;   //!
   TBranch        *b_Sys__B_29;   //!
   TBranch        *b_Sys__B_2;   //!
   TBranch        *b_Sys__B_30;   //!
   TBranch        *b_Sys__B_31;   //!
   TBranch        *b_Sys__B_32;   //!
   TBranch        *b_Sys__B_33;   //!
   TBranch        *b_Sys__B_34;   //!
   TBranch        *b_Sys__B_35;   //!
   TBranch        *b_Sys__B_36;   //!
   TBranch        *b_Sys__B_37;   //!
   TBranch        *b_Sys__B_38;   //!
   TBranch        *b_Sys__B_39;   //!
   TBranch        *b_Sys__B_3;   //!
   TBranch        *b_Sys__B_40;   //!
   TBranch        *b_Sys__B_41;   //!
   TBranch        *b_Sys__B_42;   //!
   TBranch        *b_Sys__B_43;   //!
   TBranch        *b_Sys__B_44;   //!
   TBranch        *b_Sys__B_4;   //!
   TBranch        *b_Sys__B_5;   //!
   TBranch        *b_Sys__B_6;   //!
   TBranch        *b_Sys__B_7;   //!
   TBranch        *b_Sys__B_8;   //!
   TBranch        *b_Sys__B_9;   //!
   TBranch        *b_Sys__C_0;   //!
   TBranch        *b_Sys__C_10;   //!
   TBranch        *b_Sys__C_11;   //!
   TBranch        *b_Sys__C_12;   //!
   TBranch        *b_Sys__C_13;   //!
   TBranch        *b_Sys__C_14;   //!
   TBranch        *b_Sys__C_15;   //!
   TBranch        *b_Sys__C_16;   //!
   TBranch        *b_Sys__C_17;   //!
   TBranch        *b_Sys__C_18;   //!
   TBranch        *b_Sys__C_19;   //!
   TBranch        *b_Sys__C_1;   //!
   TBranch        *b_Sys__C_2;   //!
   TBranch        *b_Sys__C_3;   //!
   TBranch        *b_Sys__C_4;   //!
   TBranch        *b_Sys__C_5;   //!
   TBranch        *b_Sys__C_6;   //!
   TBranch        *b_Sys__C_7;   //!
   TBranch        *b_Sys__C_8;   //!
   TBranch        *b_Sys__C_9;   //!
   TBranch        *b_Sys__Light_0;   //!
   TBranch        *b_Sys__Light_10;   //!
   TBranch        *b_Sys__Light_11;   //!
   TBranch        *b_Sys__Light_12;   //!
   TBranch        *b_Sys__Light_13;   //!
   TBranch        *b_Sys__Light_14;   //!
   TBranch        *b_Sys__Light_15;   //!
   TBranch        *b_Sys__Light_16;   //!
   TBranch        *b_Sys__Light_17;   //!
   TBranch        *b_Sys__Light_18;   //!
   TBranch        *b_Sys__Light_19;   //!
   TBranch        *b_Sys__Light_1;   //!
   TBranch        *b_Sys__Light_2;   //!
   TBranch        *b_Sys__Light_3;   //!
   TBranch        *b_Sys__Light_4;   //!
   TBranch        *b_Sys__Light_5;   //!
   TBranch        *b_Sys__Light_6;   //!
   TBranch        *b_Sys__Light_7;   //!
   TBranch        *b_Sys__Light_8;   //!
   TBranch        *b_Sys__Light_9;   //!
   TBranch        *b_nJets;   //!
   TBranch        *b_nSigJets;   //!
   TBranch        *b_nFwdJets;   //!
   TBranch        *b_nbJets;   //!
   TBranch        *b_JVTWeightResolved;   //!
   TBranch        *b_fJVTSF;   //!
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
   TBranch        *b_bin_bTagB1;   //!
   TBranch        *b_bin_bTagB2;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_e;   //!
   TBranch        *b_jet_truthflav;   //!
   TBranch        *b_jet_btagbin;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_SUSYMET;   //!
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
   TBranch        *b_mTW;   //!
   TBranch        *b_vbf_j1_pt;   //!
   TBranch        *b_vbf_j1_eta;   //!
   TBranch        *b_vbf_j1_phi;   //!
   TBranch        *b_vbf_j1_m;   //!
   TBranch        *b_vbf_j2_pt;   //!
   TBranch        *b_vbf_j2_eta;   //!
   TBranch        *b_vbf_j2_phi;   //!
   TBranch        *b_vbf_j2_m;   //!
   TBranch        *b_vbf_dyjj;   //!
   TBranch        *b_vbf_mjj;   //!
   TBranch        *b_vbf_mLepTop;   //!
   TBranch        *b_vbf_centralityHW;   //!
   TBranch        *b_vbf_dphiHWjj;   //!
   TBranch        *b_vbf_nVeto25;   //!
   TBranch        *b_Sys__RadLo;   //!
   TBranch        *b_Sys__RadHi;   //!
   TBranch        *b_Sys__RadHiPrime;   //!
   TBranch        *b_Sys__MUR__1up;   //!
   TBranch        *b_Sys__MUR1_MUF1_PDF13000;   //!
   TBranch        *b_Sys__MURMUF__1up;   //!
   TBranch        *b_Sys__MUR1_MUF1_PDF269000;   //!
   TBranch        *b_Sys__MUR1_MUF1_PDF25300;   //!
   TBranch        *b_Sys__MUR__1down;   //!
   TBranch        *b_Sys__MUF__1up;   //!
   TBranch        *b_Sys__MUF__1down;   //!
   TBranch        *b_Sys__FSR__1up;   //!
   TBranch        *b_Sys__FSR__1down;   //!
   TBranch        *b_Sys__MUR1_MUF1_PDF270000;   //!
   TBranch        *b_Sys__MURMUF__1down;   //!
   TBranch        *b_passIsoNom;   //!
   TBranch        *b_Sys__MUR1_MUF1_PDF303200_EXPASSEW;   //!
   TBranch        *b_Sys__MUR1_MUF1_PDF303200_MULTIASSEW;   //!
   TBranch        *b_Sys__MUR1_MUF1_PDF303200_ASSEW;   //!
   TBranch        *b_Sys__Var3cUp;   //!
   TBranch        *b_Sys__Var3cDown;   //!

   SysAnalysis(TString process = "W");
   virtual ~SysAnalysis();
   virtual void     Init(TTree *tree);
   virtual void     Loop(TChain* chain);

   bool m_isNominalMC;
   TString m_process;
   TFile* m_outFile;
   vector<Float_t>* bsys;
   vector<Float_t>* csys;
   vector<Float_t>* lsys;
   vector<Float_t>* tsys;
   vector<Float_t>* sample_sys;

   TString intNames[60] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
			   "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
			   "20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
			   "30", "31", "32", "33", "34", "35", "36", "37", "38", "39",
			   "40", "41", "42", "43", "44", "45", "46", "47", "48", "49",
			   "50", "51", "52", "53", "54", "55", "56", "57", "58", "59"};


   enum TrigVars{ MUON_EFF_TrigSystUncertainty__1up, MUON_EFF_TrigSystUncertainty__1down, MUON_EFF_TrigStatUncertainty__1up, MUON_EFF_TrigStatUncertainty__1down, METTrigStat__1up, METTrigStat__1down, METTrigTop__1up, METTrigTop__1down, METTrigZ__1up, METTrigZ__1down, METTrigSumpt__1up, METTrigSumpt__1down, nTrig};
   TString TrigNames[nTrig] = { "MUON_EFF_TrigSystUncertainty__1up", "MUON_EFF_TrigSystUncertainty__1down", "MUON_EFF_TrigStatUncertainty__1up", "MUON_EFF_TrigStatUncertainty__1down", "METTrigStat__1up", "METTrigStat__1down", "METTrigTop__1up", "METTrigTop__1down", "METTrigZ__1up", "METTrigZ__1down", "METTrigSumpt__1up", "METTrigSumpt__1down"};

   enum SigVars{ sig_MUR05_MUF05, sig_MUR05_MUF1, sig_MUR1_MUF05, sig_MUR1_MUF2, sig_MUR2_MUF1, sig_MUR2_MUF2, sig_kZ087kW093, sig_kZ087kW105, sig_kZ091kW113, sig_kZ093kW099, sig_kZ093kW105, sig_kZ094kW111, sig_kZ099kW093, sig_kZ099kW105, sig_kZ099kW111, sig_kZ099kW117, sig_kZ105kW099, sig_kZ105kW105, sig_kZ105kW111, sig_kZ108kW095, sig_kZ111kW105, sig_kZ111kW117, sig_PDF260000, sig_PDF260001, sig_PDF260002, sig_PDF260003, sig_PDF260004, sig_PDF260005, sig_PDF260006, sig_PDF260007, sig_PDF260008, sig_PDF260009, sig_PDF260010, sig_PDF260011, sig_PDF260012, sig_PDF260013, sig_PDF260014, sig_PDF260015, sig_PDF260016, sig_PDF260017, sig_PDF260018, sig_PDF260019, sig_PDF260020, sig_PDF260021, sig_PDF260022, sig_PDF260023, sig_PDF260024, sig_PDF260025, sig_PDF260026, sig_PDF260027, sig_PDF260028, sig_PDF260029, sig_PDF260030, sig_PDF260031, sig_PDF260032, sig_PDF260033, sig_PDF260034, sig_PDF260035, sig_PDF260036, sig_PDF260037, sig_PDF260038, sig_PDF260039, sig_PDF260040, sig_PDF260041, sig_PDF260042, sig_PDF260043, sig_PDF260044, sig_PDF260045, sig_PDF260046, sig_PDF260047, sig_PDF260048, sig_PDF260049, sig_PDF260050, sig_PDF260051, sig_PDF260052, sig_PDF260053, sig_PDF260054, sig_PDF260055, sig_PDF260056, sig_PDF260057, sig_PDF260058, sig_PDF260059, sig_PDF260060, sig_PDF260061, sig_PDF260062, sig_PDF260063, sig_PDF260064, sig_PDF260065, sig_PDF260066, sig_PDF260067, sig_PDF260068, sig_PDF260069, sig_PDF260070, sig_PDF260071, sig_PDF260072, sig_PDF260073, sig_PDF260074, sig_PDF260075, sig_PDF260076, sig_PDF260077, sig_PDF260078, sig_PDF260079, sig_PDF260080, sig_PDF260081, sig_PDF260082, sig_PDF260083, sig_PDF260084, sig_PDF260085, sig_PDF260086, sig_PDF260087, sig_PDF260088, sig_PDF260089, sig_PDF260090, sig_PDF260091, sig_PDF260092, sig_PDF260093, sig_PDF260094, sig_PDF260095, sig_PDF260096, sig_PDF260097, sig_PDF260098, sig_PDF260099, sig_PDF260100, sig_PDF265000, sig_PDF266000, nSigVars};
   TString SigVarNames[nSigVars] = {"MUR05_MUF05", "MUR05_MUF1", "MUR1_MUF05", "MUR1_MUF2", "MUR2_MUF1", "MUR2_MUF2", "kZ087kW093", "kZ087kW105", "kZ091kW113", "kZ093kW099", "kZ093kW105", "kZ094kW111", "kZ099kW093", "kZ099kW105", "kZ099kW111", "kZ099kW117", "kZ105kW099", "kZ105kW105", "kZ105kW111", "kZ108kW095", "kZ111kW105", "kZ111kW117", "PDF260000", "PDF260001", "PDF260002", "PDF260003", "PDF260004", "PDF260005", "PDF260006", "PDF260007", "PDF260008", "PDF260009", "PDF260010", "PDF260011", "PDF260012", "PDF260013", "PDF260014", "PDF260015", "PDF260016", "PDF260017", "PDF260018", "PDF260019", "PDF260020", "PDF260021", "PDF260022", "PDF260023", "PDF260024", "PDF260025", "PDF260026", "PDF260027", "PDF260028", "PDF260029", "PDF260030", "PDF260031", "PDF260032", "PDF260033", "PDF260034", "PDF260035", "PDF260036", "PDF260037", "PDF260038", "PDF260039", "PDF260040", "PDF260041", "PDF260042", "PDF260043", "PDF260044", "PDF260045", "PDF260046", "PDF260047", "PDF260048", "PDF260049", "PDF260050", "PDF260051", "PDF260052", "PDF260053", "PDF260054", "PDF260055", "PDF260056", "PDF260057", "PDF260058", "PDF260059", "PDF260060", "PDF260061", "PDF260062", "PDF260063", "PDF260064", "PDF260065", "PDF260066", "PDF260067", "PDF260068", "PDF260069", "PDF260070", "PDF260071", "PDF260072", "PDF260073", "PDF260074", "PDF260075", "PDF260076", "PDF260077", "PDF260078", "PDF260079", "PDF260080", "PDF260081", "PDF260082", "PDF260083", "PDF260084", "PDF260085", "PDF260086", "PDF260087", "PDF260088", "PDF260089", "PDF260090", "PDF260091", "PDF260092", "PDF260093", "PDF260094", "PDF260095", "PDF260096", "PDF260097", "PDF260098", "PDF260099", "PDF260100", "PDF265000", "PDF266000"};


   //ttbar: uses version 01_05 
   enum ttbar05Vars{ttbar_Var3cUp, ttbar_Var3cDown, ttbar_MUR__1up, ttbar_MUR__1down, ttbar_MUF__1up, ttbar_MUF__1down, ttbar_FSR__1up, ttbar_FSR__1down, ttbar_PDF13165, ttbar_PDF25200, ttbar_PDF265000, ttbar_PDF266000, nttbarVars};
   TString ttbar05VarNames[nttbarVars] = {"ttbar_Var3cUp", "ttbar_Var3cDown", "ttbar_MUR__1up", "ttbar_MUR__1down", "ttbar_MUF__1up", "ttbar_MUF__1down", "ttbar_FSR__1up", "ttbar_FSR__1down", "PDF13165", "PDF25200", "PDF265000", "PDF266000"};

   enum WVars{ w_MUR__1up, w_MUR1_MUF1_PDF13000, w_MURMUF__1up, w_MUR1_MUF1_PDF269000, w_MUR1_MUF1_PDF25300, w_MUR__1down, w_MUF__1up, w_MUF__1down, w_MUR1_MUF1_PDF270000, w_MURMUF__1down, nWVars};
   TString WVarNames[nWVars] = {"MUR__1up", "MUR1_MUF1_PDF13000", "MURMUF__1up", "MUR1_MUF1_PDF269000", "MUR1_MUF1_PDF25300", "MUR__1down", "MUF__1up", "MUF__1down", "MUR1_MUF1_PDF270000", "MURMUF__1down"};

   enum WtVars{ wt_RadLo, wt_RadHi, nWtVars};
   TString WtVarNames[nWtVars] = {"RadLo", "RadHi"};

   enum Wt05Vars{Wt_PDF13165, Wt_PDF25200, Wt_PDF265000, Wt_PDF266000, nWt05Vars};
   TString Wt05VarNames[nWt05Vars] = {"PDF13165", "PDF25200", "PDF265000", "PDF266000"};

   enum stoptVars{ stopt_RadLo, stopt_RadHi, nstoptVars};
   TString stoptVarNames[nstoptVars] = {"RadLo", "RadHi"};

   enum ZVars{ z_MUR__1up, z_MURMUF__1up, z_MUR__1down, z_MUF__1up, z_MUF__1down, z_MURMUF__1down, nZVars};
   TString ZVarNames[nZVars] = {"MUR__1up", "MURMUF__1up", "MUR__1down", "MUF__1up", "MUF__1down", "MURMUF__1down"};

   enum WHVars{ wh_MUR__1up, wh_MURMUF__1up, wh_MUR__1down, wh_MUF__1up, wh_MUF__1down, wh_MURMUF__1down, nWHVars};
   TString WHVarNames[nWHVars] = {"MUR__1up", "MURMUF__1up", "MUR__1down", "MUF__1up", "MUF__1down", "MURMUF__1down"};

   enum WZVars{ wz_MUR__1up, wz_MURMUF__1up, wz_MUR__1down, wz_MUF__1up, wz_MUF__1down, wz_MURMUF__1down, nWZVars};
   TString WZVarNames[nWZVars] = {"MUR__1up", "MURMUF__1up", "MUR__1down", "MUF__1up", "MUF__1down", "MURMUF__1down"};

   enum WZjjVars{ wzjj_MUR05_MUF05, wzjj_MUR05_MUF1, wzjj_MUR1_MUF05, wzjj_MUR1_MUF2, wzjj_MUR2_MUF1, wzjj_MUR2_MUF2, nWZjjVars};
   TString WZjjVarNames[nWZjjVars] = {"MUR05_MUF05", "MUR05_MUF1", "MUR1_MUF05", "MUR1_MUF2", "MUR2_MUF1", "MUR2_MUF2"};


};

#endif

#ifdef SysAnalysis_cxx
SysAnalysis::SysAnalysis(TString process) : fChain(0) 
{

  m_process = process;
  m_isNominalMC = (process == "SigNeg" || process == "SigPos" || process == "W" || process == "ttbar" || process == "Wt" || process == "WZ" || process == "WH" || process == "other" || process == "stops" || process == "stopt" || process == "Z" || process == "H" || process == "ttV" || process == "db" || process == "SigTest" || process == "WZewk" || process == "WZqcd");

  m_outFile = new TFile("outFiles/sys_"+process+".root","RECREATE"); 
  
  vector<TString>* TreeNames = new vector<TString>();
   TreeNames->push_back("NominalFull");
   if(m_isNominalMC){
    TreeNames->push_back("EG_RESOLUTION_ALL__1down");
    TreeNames->push_back("EG_RESOLUTION_ALL__1up");
    TreeNames->push_back("EG_SCALE_ALL__1down");
    TreeNames->push_back("EG_SCALE_ALL__1up");
    TreeNames->push_back("EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1down");
    TreeNames->push_back("EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1up");
    TreeNames->push_back("EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1down");
    TreeNames->push_back("EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1up");
    TreeNames->push_back("EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1down");
    TreeNames->push_back("EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1up");
    TreeNames->push_back("EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down");
    TreeNames->push_back("EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up");
    TreeNames->push_back("EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1down");
    TreeNames->push_back("EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1up");
    TreeNames->push_back("JET_BJES_Response__1down");
    TreeNames->push_back("JET_BJES_Response__1up");
    TreeNames->push_back("JET_EffectiveNP_Detector1__1down");
    TreeNames->push_back("JET_EffectiveNP_Detector1__1up");
    TreeNames->push_back("JET_EffectiveNP_Detector2__1down");
    TreeNames->push_back("JET_EffectiveNP_Detector2__1up");
    TreeNames->push_back("JET_EffectiveNP_Mixed1__1down");
    TreeNames->push_back("JET_EffectiveNP_Mixed1__1up");
    TreeNames->push_back("JET_EffectiveNP_Mixed2__1down");
    TreeNames->push_back("JET_EffectiveNP_Mixed2__1up");
    TreeNames->push_back("JET_EffectiveNP_Mixed3__1down");
    TreeNames->push_back("JET_EffectiveNP_Mixed3__1up");
    TreeNames->push_back("JET_EffectiveNP_Modelling1__1down");
    TreeNames->push_back("JET_EffectiveNP_Modelling1__1up");
    TreeNames->push_back("JET_EffectiveNP_Modelling2__1down");
    TreeNames->push_back("JET_EffectiveNP_Modelling2__1up");
    TreeNames->push_back("JET_EffectiveNP_Modelling3__1down");
    TreeNames->push_back("JET_EffectiveNP_Modelling3__1up");
    TreeNames->push_back("JET_EffectiveNP_Modelling4__1down");
    TreeNames->push_back("JET_EffectiveNP_Modelling4__1up");
    TreeNames->push_back("JET_EffectiveNP_Statistical1__1down");
    TreeNames->push_back("JET_EffectiveNP_Statistical1__1up");
    TreeNames->push_back("JET_EffectiveNP_Statistical2__1down");
    TreeNames->push_back("JET_EffectiveNP_Statistical2__1up");
    TreeNames->push_back("JET_EffectiveNP_Statistical3__1down");
    TreeNames->push_back("JET_EffectiveNP_Statistical3__1up");
    TreeNames->push_back("JET_EffectiveNP_Statistical4__1down");
    TreeNames->push_back("JET_EffectiveNP_Statistical4__1up");
    TreeNames->push_back("JET_EffectiveNP_Statistical5__1down");
    TreeNames->push_back("JET_EffectiveNP_Statistical5__1up");
    TreeNames->push_back("JET_EffectiveNP_Statistical6__1down");
    TreeNames->push_back("JET_EffectiveNP_Statistical6__1up");
    TreeNames->push_back("JET_EtaIntercalibration_Modelling__1down");
    TreeNames->push_back("JET_EtaIntercalibration_Modelling__1up");
    TreeNames->push_back("JET_EtaIntercalibration_NonClosure_2018data__1down");
    TreeNames->push_back("JET_EtaIntercalibration_NonClosure_2018data__1up");
    TreeNames->push_back("JET_EtaIntercalibration_TotalStat__1down");
    TreeNames->push_back("JET_EtaIntercalibration_TotalStat__1up");
    TreeNames->push_back("JET_fJvtEfficiency__1down");
    TreeNames->push_back("JET_fJvtEfficiency__1up");
    TreeNames->push_back("JET_Flavor_Composition__1down");
    TreeNames->push_back("JET_Flavor_Composition__1up");
    TreeNames->push_back("JET_Flavor_Response__1down");
    TreeNames->push_back("JET_Flavor_Response__1up");
    TreeNames->push_back("JET_JERMC_DataVsMC_MC16__1down");
    TreeNames->push_back("JET_JERMC_EffectiveNP_10__1down");
    TreeNames->push_back("JET_JERMC_EffectiveNP_10__1up");
    TreeNames->push_back("JET_JERMC_EffectiveNP_11__1down");
    TreeNames->push_back("JET_JERMC_EffectiveNP_11__1up");
    TreeNames->push_back("JET_JERMC_EffectiveNP_12restTerm__1up");
    TreeNames->push_back("JET_JERMC_EffectiveNP_1__1up");
    TreeNames->push_back("JET_JERMC_EffectiveNP_2__1down");
    TreeNames->push_back("JET_JERMC_EffectiveNP_2__1up");
    TreeNames->push_back("JET_JERMC_EffectiveNP_3__1down");
    TreeNames->push_back("JET_JERMC_EffectiveNP_3__1up");
    TreeNames->push_back("JET_JERMC_EffectiveNP_4__1down");
    TreeNames->push_back("JET_JERMC_EffectiveNP_4__1up");
    TreeNames->push_back("JET_JERMC_EffectiveNP_5__1down");
    TreeNames->push_back("JET_JERMC_EffectiveNP_5__1up");
    TreeNames->push_back("JET_JERMC_EffectiveNP_6__1down");
    TreeNames->push_back("JET_JERMC_EffectiveNP_6__1up");
    TreeNames->push_back("JET_JERMC_EffectiveNP_7__1down");
    TreeNames->push_back("JET_JERMC_EffectiveNP_7__1up");
    TreeNames->push_back("JET_JERMC_EffectiveNP_8__1down");
    TreeNames->push_back("JET_JERMC_EffectiveNP_8__1up");
    TreeNames->push_back("JET_JERMC_EffectiveNP_9__1down");
    TreeNames->push_back("JET_JERMC_EffectiveNP_9__1up");
    TreeNames->push_back("JET_JERPD_DataVsMC_MC16__1up");
    TreeNames->push_back("JET_JERPD_EffectiveNP_10__1down");
    TreeNames->push_back("JET_JERPD_EffectiveNP_10__1up");
    TreeNames->push_back("JET_JERPD_EffectiveNP_11__1down");
    TreeNames->push_back("JET_JERPD_EffectiveNP_11__1up");
    TreeNames->push_back("JET_JERPD_EffectiveNP_12restTerm__1down");
    TreeNames->push_back("JET_JERPD_EffectiveNP_1__1down");
    TreeNames->push_back("JET_JERPD_EffectiveNP_2__1down");
    TreeNames->push_back("JET_JERPD_EffectiveNP_2__1up");
    TreeNames->push_back("JET_JERPD_EffectiveNP_3__1down");
    TreeNames->push_back("JET_JERPD_EffectiveNP_3__1up");
    TreeNames->push_back("JET_JERPD_EffectiveNP_4__1down");
    TreeNames->push_back("JET_JERPD_EffectiveNP_4__1up");
    TreeNames->push_back("JET_JERPD_EffectiveNP_5__1down");
    TreeNames->push_back("JET_JERPD_EffectiveNP_5__1up");
    TreeNames->push_back("JET_JERPD_EffectiveNP_6__1down");
    TreeNames->push_back("JET_JERPD_EffectiveNP_6__1up");
    TreeNames->push_back("JET_JERPD_EffectiveNP_7__1down");
    TreeNames->push_back("JET_JERPD_EffectiveNP_7__1up");
    TreeNames->push_back("JET_JERPD_EffectiveNP_8__1down");
    TreeNames->push_back("JET_JERPD_EffectiveNP_8__1up");
    TreeNames->push_back("JET_JERPD_EffectiveNP_9__1down");
    TreeNames->push_back("JET_JERPD_EffectiveNP_9__1up");
    TreeNames->push_back("JET_JvtEfficiency__1down");
    TreeNames->push_back("JET_JvtEfficiency__1up");
    TreeNames->push_back("JET_Pileup_OffsetMu__1down");
    TreeNames->push_back("JET_Pileup_OffsetMu__1up");
    TreeNames->push_back("JET_Pileup_OffsetNPV__1down");
    TreeNames->push_back("JET_Pileup_OffsetNPV__1up");

    TreeNames->push_back("JET_Pileup_PtTerm__1down");
    TreeNames->push_back("JET_Pileup_PtTerm__1up");
    TreeNames->push_back("JET_Pileup_RhoTopology__1down");
    TreeNames->push_back("JET_Pileup_RhoTopology__1up");
    TreeNames->push_back("MET_SoftTrk_ResoPara__1up");
    TreeNames->push_back("MET_SoftTrk_ResoPerp__1up");
    TreeNames->push_back("MET_SoftTrk_Scale__1down");
    TreeNames->push_back("MET_SoftTrk_Scale__1up");
    TreeNames->push_back("MUON_CB__1down");
    TreeNames->push_back("MUON_CB__1up");
    TreeNames->push_back("MUON_EFF_ISO_STAT__1down");
    TreeNames->push_back("MUON_EFF_ISO_STAT__1up");
    TreeNames->push_back("MUON_EFF_ISO_SYS__1down");
    TreeNames->push_back("MUON_EFF_ISO_SYS__1up");
    TreeNames->push_back("MUON_EFF_RECO_STAT__1down");
    TreeNames->push_back("MUON_EFF_RECO_STAT__1up");
    TreeNames->push_back("MUON_EFF_RECO_STAT_LOWPT__1down");
    TreeNames->push_back("MUON_EFF_RECO_STAT_LOWPT__1up");
    TreeNames->push_back("MUON_EFF_RECO_SYS__1down");
    TreeNames->push_back("MUON_EFF_RECO_SYS__1up");
    TreeNames->push_back("MUON_EFF_RECO_SYS_LOWPT__1down");
    TreeNames->push_back("MUON_EFF_RECO_SYS_LOWPT__1up");
    TreeNames->push_back("MUON_EFF_TTVA_STAT__1down");
    TreeNames->push_back("MUON_EFF_TTVA_STAT__1up");
    TreeNames->push_back("MUON_SAGITTA_DATASTAT__1down");
    TreeNames->push_back("MUON_SAGITTA_DATASTAT__1up");
    TreeNames->push_back("MUON_SAGITTA_RESBIAS__1down");
    TreeNames->push_back("MUON_SAGITTA_RESBIAS__1up");
    TreeNames->push_back("MUON_SCALE__1down");
    TreeNames->push_back("MUON_SCALE__1up");
    TreeNames->push_back("PRW_DATASF__1down");
    TreeNames->push_back("PRW_DATASF__1up");
    TreeNames->push_back("TAUS_TRUEELECTRON_EFF_ELEBDT_STAT__1down");
    TreeNames->push_back("TAUS_TRUEELECTRON_EFF_ELEBDT_STAT__1up");
    TreeNames->push_back("TAUS_TRUEELECTRON_EFF_ELEBDT_SYST__1down");
    TreeNames->push_back("TAUS_TRUEELECTRON_EFF_ELEBDT_SYST__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RECO_TOTAL__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RECO_TOTAL__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_SYST__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_EFF_RNNID_SYST__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_SME_TES_DETECTOR__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_SME_TES_DETECTOR__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_SME_TES_INSITUEXP__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_SME_TES_INSITUEXP__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_SME_TES_INSITUFIT__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_SME_TES_INSITUFIT__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_SME_TES_MODEL_CLOSURE__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_SME_TES_MODEL_CLOSURE__1up");
    TreeNames->push_back("TAUS_TRUEHADTAU_SME_TES_PHYSICSLIST__1down");
    TreeNames->push_back("TAUS_TRUEHADTAU_SME_TES_PHYSICSLIST__1up");

  }  

  for(unsigned int tt = 0; tt < TreeNames->size(); tt++){

    TChain* ch = new TChain(TreeNames->at(tt));

    if(m_process == "W"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wenu*Sh221_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wmunu*Sh221_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wtaunu*Sh221_*.root");
    }
    
    if(m_process == "ttbar"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ttbar_nonallhad_PwPy8_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ttbar_dilep_PwPy8_A.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ttbar_dilep_PwPy8_D.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ttbar_dilep_PwPy8_E.root");
    }
    
    if(m_process == "WH"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/qqWlvHbbJ_PwPy8*.root");
    }
    
    if(m_process == "Wt"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stopWt_PwPy8_*.root");
    }
    
    if(m_process == "WZ"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/WlvZ*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/WZjj_lvqq_EWK*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/WqqZll*.root");
    }

    if(m_process == "WZqcd"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/WlvZ*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/WqqZll*.root");
    }
    
    if(m_process == "WZewk"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/WZjj_lvqq_EWK*.root");
    }
        
    if(m_process == "data"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/data*.root");
    }
    
    if(m_process == "SigNeg"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/VBFWHlvbbNeg_*.root");
    }
    
    if(m_process == "SigPos"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/VBFWHlvbbPos_*.root");
    }
    
    if(m_process == "other"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stopt_PwPy8_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stops_PwPy8_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/WqqWlv*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ggWqqWlv*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Z*Zll*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ggZqqZll*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Zee*Sh221_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Zmumu*Sh221_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Ztautau*Sh221_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ggHinc*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ggZllHbb*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/qqZllHbbJ*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ttHinc*.root"); 
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ttV*.root");
    }
    
    
    if(m_process == "stopt"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stopt_PwPy8_*.root");
    }
    
    if(m_process == "stops"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stops_PwPy8_*.root");
    }
    
    if(m_process == "db"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/WqqWlv*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ggWqqWlv*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Z*Zll*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ggZqqZll*.root");
    }
    
    if(m_process == "Z"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Zee*Sh221_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Zmumu*Sh221_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Ztautau*Sh221_*.root");
    }
    
    if(m_process == "H"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ggHinc*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ggZllHbb*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/qqZllHbbJ*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ttHinc*.root");
    }

    if(m_process == "ttH"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ttHinc*.root");
    }

    if(m_process == "ZH"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ggZllHbb*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/qqZllHbbJ*.root");
    }
    
    if(m_process == "ttV"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ttV*.root");
    }
    
    if(m_process == "W_MGPy8"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wenu*MGPy8_A.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wmunu*MGPy8_A.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wtaunu*MGPy8_A.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wenu*MGPy8_D.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wmunu*MGPy8_D.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wtaunu*MGPy8_D.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wenu*MGPy8_E.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wmunu*MGPy8_E.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wtaunu*MGPy8_E.root");
    }

    if(m_process == "W_Sh2211"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wenu*Sh2211_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wmunu*Sh2211_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wtaunu*Sh2211_*.root");
    }

    if(m_process == "W_FxFx"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wenu*FxFx_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wmunu*FxFx_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/Wtaunu*FxFx_*.root");
    }
        
    if(m_process == "Wt_aMC"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stopWt_aMCatNLO_A.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stopWt_aMCatNLO_D.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stopWt_aMCatNLO_E.root");
    }
    
    if(m_process == "Wt_DS"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stopWt_DS_PwPy8_*.root");
    }
    
    if(m_process == "Wt_Herwig"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stopWt_PwHwg7_A.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stopWt_PwHwg7_D.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stopWt_PwHwg7_E.root");
    }

    if(m_process == "stopt_aMC"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stopt_aMCatNLO*.root");
    }

    if(m_process == "stopt_Herwig"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/stopt_PwHwg7*.root");
    }
    
    if(m_process == "ttbar_aMC"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ttbar_*aMCatNLO*.root");
    }
    
    if(m_process == "ttbar_Herwig"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ttbar_*PwHwg7*.root");
    }
    
    if(m_process == "ttbar_RadHi"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_03/ttbar_*RadHi*.root");
    }  

    if(m_process == "ttbar05"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_05/ttbar_nonallhad_PwPy8_*.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_05/ttbar_dilep_PwPy8_A.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_05/ttbar_dilep_PwPy8_D.root");
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_05/ttbar_dilep_PwPy8_E.root");
    }

    if(m_process == "Wt05"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_05/stopWt_PwPy8_*.root");
    }


    if(m_process == "ttbar_hdamp"){
      ch->Add("/eos/user/j/jkeller/EasyTreeOutputs/Hadded_01_04/ttbar_*hdamp*.root");
    }


    Init(ch);
    Loop(ch);

  }
  
  m_outFile->Close();     

}

SysAnalysis::~SysAnalysis()
{
}

void SysAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF

   // Set object pointer
   sample = 0;
   Description = 0;
   EventFlavor = 0;
   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_e = 0;
   jet_truthflav = 0;
   jet_btagbin = 0;

   bsys = new vector<Float_t>();
   bsys->assign(45,0.0);
   csys = new vector<Float_t>();
   csys->assign(20,0.0);
   lsys = new vector<Float_t>();
   lsys->assign(20,0.0);
   tsys = new vector<Float_t>();
   tsys->assign(nTrig,0.0);

   sample_sys = new vector<Float_t>();
   if(m_process.Contains("Sig")) sample_sys->assign(nSigVars,0.0);
   if(m_process == "ttbar05") sample_sys->assign(nttbarVars,0.0);
   if(m_process == "W") sample_sys->assign(nWVars,0.0);
   if(m_process == "Wt") sample_sys->assign(nWtVars,0.0);
   if(m_process == "Wt05") sample_sys->assign(nWt05Vars,0.0);
   if(m_process == "Z") sample_sys->assign(nZVars,0.0);
   if(m_process == "WH") sample_sys->assign(nWHVars,0.0);
   if(m_process == "WZqcd") sample_sys->assign(nWZVars,0.0);
   if(m_process == "WZewk") sample_sys->assign(nWZjjVars,0.0);
   if(m_process == "stopt") sample_sys->assign(nstoptVars,0.0);

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   tree->SetBranchAddress("MCEventWeight", &MCEventWeight, &b_MCEventWeight);
   tree->SetBranchAddress("EventWeight", &EventWeight, &b_EventWeight);
   tree->SetBranchAddress("BTagSF", &BTagSF, &b_BTagSF);
   tree->SetBranchAddress("TriggerSF", &TriggerSF, &b_TriggerSF);
   tree->SetBranchAddress("LumiWeight", &LumiWeight, &b_LumiWeight);
   tree->SetBranchAddress("PUWeight", &PUWeight, &b_PUWeight);
   tree->SetBranchAddress("pTV", &pTV, &b_pTV);
   /* tree->SetBranchAddress("MET", &MET, &b_MET); */
   /* tree->SetBranchAddress("nJets", &nJets, &b_nJets); */
   /* tree->SetBranchAddress("nSigJets", &nSigJets, &b_nSigJets); */
   /* tree->SetBranchAddress("nFwdJets", &nFwdJets, &b_nFwdJets); */
   /* tree->SetBranchAddress("nbJets", &nbJets, &b_nbJets); */
   tree->SetBranchAddress("JVTWeightResolved", &JVTWeightResolved, &b_JVTWeightResolved);
   tree->SetBranchAddress("fJVTSF", &fJVTSF, &b_fJVTSF);
   tree->SetBranchAddress("LeptonSF", &LeptonSF, &b_LeptonSF);
   /* tree->SetBranchAddress("sumPtJets", &sumPtJets, &b_sumPtJets); */
   tree->SetBranchAddress("mBB", &mBB, &b_mBB);
   tree->SetBranchAddress("pTBB", &pTBB, &b_pTBB);
   /* tree->SetBranchAddress("etaBB", &etaBB, &b_etaBB); */
   /* tree->SetBranchAddress("phiBB", &phiBB, &b_phiBB); */
   /* tree->SetBranchAddress("dRBB", &dRBB, &b_dRBB); */
   /* tree->SetBranchAddress("dPhiBB", &dPhiBB, &b_dPhiBB); */
   /* tree->SetBranchAddress("dEtaBB", &dEtaBB, &b_dEtaBB); */
   tree->SetBranchAddress("pTB1", &pTB1, &b_pTB1);
   tree->SetBranchAddress("etaB1", &etaB1, &b_etaB1);
   tree->SetBranchAddress("phiB1", &phiB1, &b_phiB1);
   tree->SetBranchAddress("mB1", &mB1, &b_mB1);
   tree->SetBranchAddress("pTB2", &pTB2, &b_pTB2);
   tree->SetBranchAddress("etaB2", &etaB2, &b_etaB2);
   tree->SetBranchAddress("phiB2", &phiB2, &b_phiB2);
   tree->SetBranchAddress("mB2", &mB2, &b_mB2);
   /* tree->SetBranchAddress("bin_bTagB1", &bin_bTagB1, &b_bin_bTagB1); */
   /* tree->SetBranchAddress("bin_bTagB2", &bin_bTagB2, &b_bin_bTagB2); */
   tree->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   tree->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   tree->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   tree->SetBranchAddress("jet_e", &jet_e, &b_jet_e);
   /* tree->SetBranchAddress("jet_truthflav", &jet_truthflav, &b_jet_truthflav); */
   tree->SetBranchAddress("jet_btagbin", &jet_btagbin, &b_jet_btagbin);
   /* tree->SetBranchAddress("met_phi", &met_phi, &b_met_phi); */
   /* tree->SetBranchAddress("nElectrons", &nElectrons, &b_nElectrons); */
   /* tree->SetBranchAddress("nMuons", &nMuons, &b_nMuons); */
   /* tree->SetBranchAddress("ptL1", &ptL1, &b_ptL1); */
   /* tree->SetBranchAddress("etaL1", &etaL1, &b_etaL1); */
   /* tree->SetBranchAddress("phiL1", &phiL1, &b_phiL1); */
   /* tree->SetBranchAddress("mL1", &mL1, &b_mL1); */
   /* tree->SetBranchAddress("chargeL1", &chargeL1, &b_chargeL1); */
   tree->SetBranchAddress("mTW", &mTW, &b_mTW);
   tree->SetBranchAddress("vbf_j1_pt", &vbf_j1_pt, &b_vbf_j1_pt);
   tree->SetBranchAddress("vbf_j1_eta", &vbf_j1_eta, &b_vbf_j1_eta);
   tree->SetBranchAddress("vbf_j1_phi", &vbf_j1_phi, &b_vbf_j1_phi);
   tree->SetBranchAddress("vbf_j1_m", &vbf_j1_m, &b_vbf_j1_m);
   tree->SetBranchAddress("vbf_j2_pt", &vbf_j2_pt, &b_vbf_j2_pt);
   tree->SetBranchAddress("vbf_j2_eta", &vbf_j2_eta, &b_vbf_j2_eta);
   tree->SetBranchAddress("vbf_j2_phi", &vbf_j2_phi, &b_vbf_j2_phi);
   tree->SetBranchAddress("vbf_j2_m", &vbf_j2_m, &b_vbf_j2_m);
   tree->SetBranchAddress("vbf_dyjj", &vbf_dyjj, &b_vbf_dyjj);
   tree->SetBranchAddress("vbf_mjj", &vbf_mjj, &b_vbf_mjj);
   tree->SetBranchAddress("vbf_mLepTop", &vbf_mLepTop, &b_vbf_mLepTop);
   tree->SetBranchAddress("vbf_centralityHW", &vbf_centralityHW, &b_vbf_centralityHW);
   tree->SetBranchAddress("vbf_dphiHWjj", &vbf_dphiHWjj, &b_vbf_dphiHWjj);
   /* tree->SetBranchAddress("vbf_nVeto25", &vbf_nVeto25, &b_vbf_nVeto25); */

   if(m_process == "W_Sh2211"){
     tree->SetBranchAddress("Sys__MUR1_MUF1_PDF303200_EXPASSEW", &Sys__MUR1_MUF1_PDF303200_EXPASSEW, &b_Sys__MUR1_MUF1_PDF303200_EXPASSEW);
     tree->SetBranchAddress("Sys__MUR1_MUF1_PDF303200_MULTIASSEW", &Sys__MUR1_MUF1_PDF303200_MULTIASSEW, &b_Sys__MUR1_MUF1_PDF303200_MULTIASSEW);
     tree->SetBranchAddress("Sys__MUR1_MUF1_PDF303200_ASSEW", &Sys__MUR1_MUF1_PDF303200_ASSEW, &b_Sys__MUR1_MUF1_PDF303200_ASSEW);
   }

   if(m_process == "ttbar05"){
     tree->SetBranchAddress("Sys__Var3cUp", &sample_sys->at(ttbar_Var3cUp), &b_Sys__Var3cUp);
     tree->SetBranchAddress("Sys__Var3cDown", &sample_sys->at(ttbar_Var3cDown), &b_Sys__Var3cDown);
     tree->SetBranchAddress("Sys__MUR__1up", &sample_sys->at(ttbar_MUR__1up), &b_Sys__MUR__1up);
     tree->SetBranchAddress("Sys__MUR__1down", &sample_sys->at(ttbar_MUR__1down), &b_Sys__MUR__1down);
     tree->SetBranchAddress("Sys__MUF__1up", &sample_sys->at(ttbar_MUF__1up), &b_Sys__MUF__1up);
     tree->SetBranchAddress("Sys__MUF__1down", &sample_sys->at(ttbar_MUF__1down), &b_Sys__MUF__1down);
     tree->SetBranchAddress("Sys__FSR__1up", &sample_sys->at(ttbar_FSR__1up), &b_Sys__FSR__1up);
     tree->SetBranchAddress("Sys__FSR__1down", &sample_sys->at(ttbar_FSR__1down), &b_Sys__FSR__1down);
     tree->SetBranchAddress("Sys__PDF13165", &sample_sys->at(ttbar_PDF13165), &b_Sys__PDF13165);
     tree->SetBranchAddress("Sys__PDF25200", &sample_sys->at(ttbar_PDF25200), &b_Sys__PDF25200);
     tree->SetBranchAddress("Sys__PDF265000", &sample_sys->at(ttbar_PDF265000), &b_Sys__PDF265000);
     tree->SetBranchAddress("Sys__PDF266000", &sample_sys->at(ttbar_PDF266000), &b_Sys__PDF266000);
   }

   if(m_process == "Wt05"){
     tree->SetBranchAddress("Sys__PDF13165", &sample_sys->at(Wt_PDF13165), &b_Sys__PDF13165);
     tree->SetBranchAddress("Sys__PDF25200", &sample_sys->at(Wt_PDF25200), &b_Sys__PDF25200);
     tree->SetBranchAddress("Sys__PDF265000", &sample_sys->at(Wt_PDF265000), &b_Sys__PDF265000);
     tree->SetBranchAddress("Sys__PDF266000", &sample_sys->at(Wt_PDF266000), &b_Sys__PDF266000);
   }


   if(((TString)tree->GetName()).Contains("Nominal")) tree->SetBranchAddress("passIsoNom", &passIsoNom, &b_passIsoNom);
   else passIsoNom = true;

   if(((TString)tree->GetName()).Contains("Nominal") && m_isNominalMC){

     /* tree->SetBranchAddress("sample", &sample, &b_sample); */
     /* tree->SetBranchAddress("Description", &Description, &b_Description); */
     /* tree->SetBranchAddress("MCChannelNumber", &MCChannelNumber, &b_MCChannelNumber); */
     /* tree->SetBranchAddress("EventFlavor", &EventFlavor, &b_EventFlavor); */
     /* tree->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber); */
     /* tree->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber); */
     /* tree->SetBranchAddress("AverageMu", &AverageMu, &b_AverageMu); */
     /* tree->SetBranchAddress("ActualMu", &ActualMu, &b_ActualMu); */
     /* tree->SetBranchAddress("AverageMuScaled", &AverageMuScaled, &b_AverageMuScaled); */
     /* tree->SetBranchAddress("ActualMuScaled", &ActualMuScaled, &b_ActualMuScaled); */
     /* tree->SetBranchAddress("flavB1", &flavB1, &b_flavB1); */
     /* tree->SetBranchAddress("flavB2", &flavB2, &b_flavB2); */
     /* tree->SetBranchAddress("softMET", &softMET, &b_softMET); */
     /* tree->SetBranchAddress("metSig", &metSig, &b_metSig); */
     /* tree->SetBranchAddress("nTaus", &nTaus, &b_nTaus); */
     /* tree->SetBranchAddress("Njets_truth_pTjet30", &Njets_truth_pTjet30, &b_Njets_truth_pTjet30); */
     /* tree->SetBranchAddress("TTBarDecay", &TTBarDecay, &b_TTBarDecay); */
     /* tree->SetBranchAddress("SUSYMET", &SUSYMET, &b_SUSYMET); */
     /* tree->SetBranchAddress("metOverSqrtSumET", &metOverSqrtSumET, &b_metOverSqrtSumET); */
     /* tree->SetBranchAddress("metOverSqrtHT", &metOverSqrtHT, &b_metOverSqrtHT); */
        
     if(m_process.Contains("Sig")){
       tree->SetBranchAddress("Sys__MUR05_MUF05", &sample_sys->at(sig_MUR05_MUF05), &b_Sys__MUR05_MUF05);
       tree->SetBranchAddress("Sys__MUR05_MUF1", &sample_sys->at(sig_MUR05_MUF1), &b_Sys__MUR05_MUF1);
       tree->SetBranchAddress("Sys__MUR1_MUF05", &sample_sys->at(sig_MUR1_MUF05), &b_Sys__MUR1_MUF05);
       tree->SetBranchAddress("Sys__MUR1_MUF2", &sample_sys->at(sig_MUR1_MUF2), &b_Sys__MUR1_MUF2);
       tree->SetBranchAddress("Sys__MUR2_MUF1", &sample_sys->at(sig_MUR2_MUF1), &b_Sys__MUR2_MUF1);
       tree->SetBranchAddress("Sys__MUR2_MUF2", &sample_sys->at(sig_MUR2_MUF2), &b_Sys__MUR2_MUF2);
       
       tree->SetBranchAddress("Sys__kZ087kW093", &sample_sys->at(sig_kZ087kW093), &b_Sys__kZ087kW093);
       tree->SetBranchAddress("Sys__kZ087kW105", &sample_sys->at(sig_kZ087kW105), &b_Sys__kZ087kW105);
       tree->SetBranchAddress("Sys__kZ091kW113", &sample_sys->at(sig_kZ091kW113), &b_Sys__kZ091kW113);
       tree->SetBranchAddress("Sys__kZ093kW099", &sample_sys->at(sig_kZ093kW099), &b_Sys__kZ093kW099);
       tree->SetBranchAddress("Sys__kZ093kW105", &sample_sys->at(sig_kZ093kW105), &b_Sys__kZ093kW105);
       tree->SetBranchAddress("Sys__kZ094kW111", &sample_sys->at(sig_kZ094kW111), &b_Sys__kZ094kW111);
       tree->SetBranchAddress("Sys__kZ099kW093", &sample_sys->at(sig_kZ099kW093), &b_Sys__kZ099kW093);
       tree->SetBranchAddress("Sys__kZ099kW105", &sample_sys->at(sig_kZ099kW105), &b_Sys__kZ099kW105);
       tree->SetBranchAddress("Sys__kZ099kW111", &sample_sys->at(sig_kZ099kW111), &b_Sys__kZ099kW111);
       tree->SetBranchAddress("Sys__kZ099kW117", &sample_sys->at(sig_kZ099kW117), &b_Sys__kZ099kW117);
       tree->SetBranchAddress("Sys__kZ105kW099", &sample_sys->at(sig_kZ105kW099), &b_Sys__kZ105kW099);
       tree->SetBranchAddress("Sys__kZ105kW105", &sample_sys->at(sig_kZ105kW105), &b_Sys__kZ105kW105);
       tree->SetBranchAddress("Sys__kZ105kW111", &sample_sys->at(sig_kZ105kW111), &b_Sys__kZ105kW111);
       tree->SetBranchAddress("Sys__kZ108kW095", &sample_sys->at(sig_kZ108kW095), &b_Sys__kZ108kW095);
       tree->SetBranchAddress("Sys__kZ111kW105", &sample_sys->at(sig_kZ111kW105), &b_Sys__kZ111kW105);
       tree->SetBranchAddress("Sys__kZ111kW117", &sample_sys->at(sig_kZ111kW117), &b_Sys__kZ111kW117);
       
       tree->SetBranchAddress("Sys__PDF260001", &sample_sys->at(sig_PDF260001), &b_Sys__PDF260001);
       tree->SetBranchAddress("Sys__PDF260002", &sample_sys->at(sig_PDF260002), &b_Sys__PDF260002);
       tree->SetBranchAddress("Sys__PDF260003", &sample_sys->at(sig_PDF260003), &b_Sys__PDF260003);
       tree->SetBranchAddress("Sys__PDF260004", &sample_sys->at(sig_PDF260004), &b_Sys__PDF260004);
       tree->SetBranchAddress("Sys__PDF260005", &sample_sys->at(sig_PDF260005), &b_Sys__PDF260005);
       tree->SetBranchAddress("Sys__PDF260006", &sample_sys->at(sig_PDF260006), &b_Sys__PDF260006);
       tree->SetBranchAddress("Sys__PDF260007", &sample_sys->at(sig_PDF260007), &b_Sys__PDF260007);
       tree->SetBranchAddress("Sys__PDF260008", &sample_sys->at(sig_PDF260008), &b_Sys__PDF260008);
       tree->SetBranchAddress("Sys__PDF260009", &sample_sys->at(sig_PDF260009), &b_Sys__PDF260009);
       tree->SetBranchAddress("Sys__PDF260010", &sample_sys->at(sig_PDF260010), &b_Sys__PDF260010);
       tree->SetBranchAddress("Sys__PDF260011", &sample_sys->at(sig_PDF260011), &b_Sys__PDF260011);
       tree->SetBranchAddress("Sys__PDF260012", &sample_sys->at(sig_PDF260012), &b_Sys__PDF260012);
       tree->SetBranchAddress("Sys__PDF260013", &sample_sys->at(sig_PDF260013), &b_Sys__PDF260013);
       tree->SetBranchAddress("Sys__PDF260014", &sample_sys->at(sig_PDF260014), &b_Sys__PDF260014);
       tree->SetBranchAddress("Sys__PDF260015", &sample_sys->at(sig_PDF260015), &b_Sys__PDF260015);
       tree->SetBranchAddress("Sys__PDF260016", &sample_sys->at(sig_PDF260016), &b_Sys__PDF260016);
       tree->SetBranchAddress("Sys__PDF260017", &sample_sys->at(sig_PDF260017), &b_Sys__PDF260017);
       tree->SetBranchAddress("Sys__PDF260018", &sample_sys->at(sig_PDF260018), &b_Sys__PDF260018);
       tree->SetBranchAddress("Sys__PDF260019", &sample_sys->at(sig_PDF260019), &b_Sys__PDF260019);
       tree->SetBranchAddress("Sys__PDF260020", &sample_sys->at(sig_PDF260020), &b_Sys__PDF260020);
       tree->SetBranchAddress("Sys__PDF260021", &sample_sys->at(sig_PDF260021), &b_Sys__PDF260021);
       tree->SetBranchAddress("Sys__PDF260022", &sample_sys->at(sig_PDF260022), &b_Sys__PDF260022);
       tree->SetBranchAddress("Sys__PDF260023", &sample_sys->at(sig_PDF260023), &b_Sys__PDF260023);
       tree->SetBranchAddress("Sys__PDF260024", &sample_sys->at(sig_PDF260024), &b_Sys__PDF260024);
       tree->SetBranchAddress("Sys__PDF260025", &sample_sys->at(sig_PDF260025), &b_Sys__PDF260025);
       tree->SetBranchAddress("Sys__PDF260026", &sample_sys->at(sig_PDF260026), &b_Sys__PDF260026);
       tree->SetBranchAddress("Sys__PDF260027", &sample_sys->at(sig_PDF260027), &b_Sys__PDF260027);
       tree->SetBranchAddress("Sys__PDF260028", &sample_sys->at(sig_PDF260028), &b_Sys__PDF260028);
       tree->SetBranchAddress("Sys__PDF260029", &sample_sys->at(sig_PDF260029), &b_Sys__PDF260029);
       tree->SetBranchAddress("Sys__PDF260030", &sample_sys->at(sig_PDF260030), &b_Sys__PDF260030);
       tree->SetBranchAddress("Sys__PDF260031", &sample_sys->at(sig_PDF260031), &b_Sys__PDF260031);
       tree->SetBranchAddress("Sys__PDF260032", &sample_sys->at(sig_PDF260032), &b_Sys__PDF260032);
       tree->SetBranchAddress("Sys__PDF260033", &sample_sys->at(sig_PDF260033), &b_Sys__PDF260033);
       tree->SetBranchAddress("Sys__PDF260034", &sample_sys->at(sig_PDF260034), &b_Sys__PDF260034);
       tree->SetBranchAddress("Sys__PDF260035", &sample_sys->at(sig_PDF260035), &b_Sys__PDF260035);
       tree->SetBranchAddress("Sys__PDF260036", &sample_sys->at(sig_PDF260036), &b_Sys__PDF260036);
       tree->SetBranchAddress("Sys__PDF260037", &sample_sys->at(sig_PDF260037), &b_Sys__PDF260037);
       tree->SetBranchAddress("Sys__PDF260038", &sample_sys->at(sig_PDF260038), &b_Sys__PDF260038);
       tree->SetBranchAddress("Sys__PDF260039", &sample_sys->at(sig_PDF260039), &b_Sys__PDF260039);
       tree->SetBranchAddress("Sys__PDF260040", &sample_sys->at(sig_PDF260040), &b_Sys__PDF260040);
       tree->SetBranchAddress("Sys__PDF260041", &sample_sys->at(sig_PDF260041), &b_Sys__PDF260041);
       tree->SetBranchAddress("Sys__PDF260042", &sample_sys->at(sig_PDF260042), &b_Sys__PDF260042);
       tree->SetBranchAddress("Sys__PDF260043", &sample_sys->at(sig_PDF260043), &b_Sys__PDF260043);
       tree->SetBranchAddress("Sys__PDF260044", &sample_sys->at(sig_PDF260044), &b_Sys__PDF260044);
       tree->SetBranchAddress("Sys__PDF260045", &sample_sys->at(sig_PDF260045), &b_Sys__PDF260045);
       tree->SetBranchAddress("Sys__PDF260046", &sample_sys->at(sig_PDF260046), &b_Sys__PDF260046);
       tree->SetBranchAddress("Sys__PDF260047", &sample_sys->at(sig_PDF260047), &b_Sys__PDF260047);
       tree->SetBranchAddress("Sys__PDF260048", &sample_sys->at(sig_PDF260048), &b_Sys__PDF260048);
       tree->SetBranchAddress("Sys__PDF260049", &sample_sys->at(sig_PDF260049), &b_Sys__PDF260049);
       tree->SetBranchAddress("Sys__PDF260050", &sample_sys->at(sig_PDF260050), &b_Sys__PDF260050);
       tree->SetBranchAddress("Sys__PDF260051", &sample_sys->at(sig_PDF260051), &b_Sys__PDF260051);
       tree->SetBranchAddress("Sys__PDF260052", &sample_sys->at(sig_PDF260052), &b_Sys__PDF260052);
       tree->SetBranchAddress("Sys__PDF260053", &sample_sys->at(sig_PDF260053), &b_Sys__PDF260053);
       tree->SetBranchAddress("Sys__PDF260054", &sample_sys->at(sig_PDF260054), &b_Sys__PDF260054);
       tree->SetBranchAddress("Sys__PDF260055", &sample_sys->at(sig_PDF260055), &b_Sys__PDF260055);
       tree->SetBranchAddress("Sys__PDF260056", &sample_sys->at(sig_PDF260056), &b_Sys__PDF260056);
       tree->SetBranchAddress("Sys__PDF260057", &sample_sys->at(sig_PDF260057), &b_Sys__PDF260057);
       tree->SetBranchAddress("Sys__PDF260058", &sample_sys->at(sig_PDF260058), &b_Sys__PDF260058);
       tree->SetBranchAddress("Sys__PDF260059", &sample_sys->at(sig_PDF260059), &b_Sys__PDF260059);
       tree->SetBranchAddress("Sys__PDF260060", &sample_sys->at(sig_PDF260060), &b_Sys__PDF260060);
       tree->SetBranchAddress("Sys__PDF260061", &sample_sys->at(sig_PDF260061), &b_Sys__PDF260061);
       tree->SetBranchAddress("Sys__PDF260062", &sample_sys->at(sig_PDF260062), &b_Sys__PDF260062);
       tree->SetBranchAddress("Sys__PDF260063", &sample_sys->at(sig_PDF260063), &b_Sys__PDF260063);
       tree->SetBranchAddress("Sys__PDF260064", &sample_sys->at(sig_PDF260064), &b_Sys__PDF260064);
       tree->SetBranchAddress("Sys__PDF260065", &sample_sys->at(sig_PDF260065), &b_Sys__PDF260065);
       tree->SetBranchAddress("Sys__PDF260066", &sample_sys->at(sig_PDF260066), &b_Sys__PDF260066);
       tree->SetBranchAddress("Sys__PDF260067", &sample_sys->at(sig_PDF260067), &b_Sys__PDF260067);
       tree->SetBranchAddress("Sys__PDF260068", &sample_sys->at(sig_PDF260068), &b_Sys__PDF260068);
       tree->SetBranchAddress("Sys__PDF260069", &sample_sys->at(sig_PDF260069), &b_Sys__PDF260069);
       tree->SetBranchAddress("Sys__PDF260070", &sample_sys->at(sig_PDF260070), &b_Sys__PDF260070);
       tree->SetBranchAddress("Sys__PDF260071", &sample_sys->at(sig_PDF260071), &b_Sys__PDF260071);
       tree->SetBranchAddress("Sys__PDF260072", &sample_sys->at(sig_PDF260072), &b_Sys__PDF260072);
       tree->SetBranchAddress("Sys__PDF260073", &sample_sys->at(sig_PDF260073), &b_Sys__PDF260073);
       tree->SetBranchAddress("Sys__PDF260074", &sample_sys->at(sig_PDF260074), &b_Sys__PDF260074);
       tree->SetBranchAddress("Sys__PDF260075", &sample_sys->at(sig_PDF260075), &b_Sys__PDF260075);
       tree->SetBranchAddress("Sys__PDF260076", &sample_sys->at(sig_PDF260076), &b_Sys__PDF260076);
       tree->SetBranchAddress("Sys__PDF260077", &sample_sys->at(sig_PDF260077), &b_Sys__PDF260077);
       tree->SetBranchAddress("Sys__PDF260078", &sample_sys->at(sig_PDF260078), &b_Sys__PDF260078);
       tree->SetBranchAddress("Sys__PDF260079", &sample_sys->at(sig_PDF260079), &b_Sys__PDF260079);
       tree->SetBranchAddress("Sys__PDF260080", &sample_sys->at(sig_PDF260080), &b_Sys__PDF260080);
       tree->SetBranchAddress("Sys__PDF260081", &sample_sys->at(sig_PDF260081), &b_Sys__PDF260081);
       tree->SetBranchAddress("Sys__PDF260082", &sample_sys->at(sig_PDF260082), &b_Sys__PDF260082);
       tree->SetBranchAddress("Sys__PDF260083", &sample_sys->at(sig_PDF260083), &b_Sys__PDF260083);
       tree->SetBranchAddress("Sys__PDF260084", &sample_sys->at(sig_PDF260084), &b_Sys__PDF260084);
       tree->SetBranchAddress("Sys__PDF260085", &sample_sys->at(sig_PDF260085), &b_Sys__PDF260085);
       tree->SetBranchAddress("Sys__PDF260086", &sample_sys->at(sig_PDF260086), &b_Sys__PDF260086);
       tree->SetBranchAddress("Sys__PDF260087", &sample_sys->at(sig_PDF260087), &b_Sys__PDF260087);
       tree->SetBranchAddress("Sys__PDF260088", &sample_sys->at(sig_PDF260088), &b_Sys__PDF260088);
       tree->SetBranchAddress("Sys__PDF260089", &sample_sys->at(sig_PDF260089), &b_Sys__PDF260089);
       tree->SetBranchAddress("Sys__PDF260090", &sample_sys->at(sig_PDF260090), &b_Sys__PDF260090);
       tree->SetBranchAddress("Sys__PDF260091", &sample_sys->at(sig_PDF260091), &b_Sys__PDF260091);
       tree->SetBranchAddress("Sys__PDF260092", &sample_sys->at(sig_PDF260092), &b_Sys__PDF260092);
       tree->SetBranchAddress("Sys__PDF260093", &sample_sys->at(sig_PDF260093), &b_Sys__PDF260093);
       tree->SetBranchAddress("Sys__PDF260094", &sample_sys->at(sig_PDF260094), &b_Sys__PDF260094);
       tree->SetBranchAddress("Sys__PDF260095", &sample_sys->at(sig_PDF260095), &b_Sys__PDF260095);
       tree->SetBranchAddress("Sys__PDF260096", &sample_sys->at(sig_PDF260096), &b_Sys__PDF260096);
       tree->SetBranchAddress("Sys__PDF260097", &sample_sys->at(sig_PDF260097), &b_Sys__PDF260097);
       tree->SetBranchAddress("Sys__PDF260098", &sample_sys->at(sig_PDF260098), &b_Sys__PDF260098);
       tree->SetBranchAddress("Sys__PDF260099", &sample_sys->at(sig_PDF260099), &b_Sys__PDF260099);
       tree->SetBranchAddress("Sys__PDF260100", &sample_sys->at(sig_PDF260100), &b_Sys__PDF260100);
       tree->SetBranchAddress("Sys__PDF265000", &sample_sys->at(sig_PDF265000), &b_Sys__PDF265000);
       tree->SetBranchAddress("Sys__PDF266000", &sample_sys->at(sig_PDF266000), &b_Sys__PDF266000);
     }

     if(m_process == "W"){
       tree->SetBranchAddress("Sys__MUR__1up", &sample_sys->at(w_MUR__1up), &b_Sys__MUR__1up);
       tree->SetBranchAddress("Sys__MUR1_MUF1_PDF13000", &sample_sys->at(w_MUR1_MUF1_PDF13000), &b_Sys__MUR1_MUF1_PDF13000);
       tree->SetBranchAddress("Sys__MURMUF__1up", &sample_sys->at(w_MURMUF__1up), &b_Sys__MURMUF__1up);
       tree->SetBranchAddress("Sys__MUR1_MUF1_PDF269000", &sample_sys->at(w_MUR1_MUF1_PDF269000), &b_Sys__MUR1_MUF1_PDF269000);
       tree->SetBranchAddress("Sys__MUR1_MUF1_PDF25300", &sample_sys->at(w_MUR1_MUF1_PDF25300), &b_Sys__MUR1_MUF1_PDF25300);
       tree->SetBranchAddress("Sys__MUR__1down", &sample_sys->at(w_MUR__1down), &b_Sys__MUR__1down);
       tree->SetBranchAddress("Sys__MUF__1up", &sample_sys->at(w_MUF__1up), &b_Sys__MUF__1up);
       tree->SetBranchAddress("Sys__MUF__1down", &sample_sys->at(w_MUF__1down), &b_Sys__MUF__1down);
       tree->SetBranchAddress("Sys__MUR1_MUF1_PDF270000", &sample_sys->at(w_MUR1_MUF1_PDF270000), &b_Sys__MUR1_MUF1_PDF270000);
       tree->SetBranchAddress("Sys__MURMUF__1down", &sample_sys->at(w_MURMUF__1down), &b_Sys__MURMUF__1down);
     }

     if(m_process == "Wt"){
       tree->SetBranchAddress("Sys__RadLo", &sample_sys->at(wt_RadLo), &b_Sys__RadLo);
       tree->SetBranchAddress("Sys__RadHi", &sample_sys->at(wt_RadHi), &b_Sys__RadHi);
     }

     if(m_process == "Z"){
       tree->SetBranchAddress("Sys__MUR__1up", &sample_sys->at(z_MUR__1up), &b_Sys__MUR__1up);
       tree->SetBranchAddress("Sys__MURMUF__1up", &sample_sys->at(z_MURMUF__1up), &b_Sys__MURMUF__1up);
       tree->SetBranchAddress("Sys__MUR__1down", &sample_sys->at(z_MUR__1down), &b_Sys__MUR__1down);
       tree->SetBranchAddress("Sys__MUF__1up", &sample_sys->at(z_MUF__1up), &b_Sys__MUF__1up);
       tree->SetBranchAddress("Sys__MUF__1down", &sample_sys->at(z_MUF__1down), &b_Sys__MUF__1down);
       tree->SetBranchAddress("Sys__MURMUF__1down", &sample_sys->at(z_MURMUF__1down), &b_Sys__MURMUF__1down);
     }

     if(m_process == "WH"){
       tree->SetBranchAddress("Sys__MUR__1up", &sample_sys->at(wh_MUR__1up), &b_Sys__MUR__1up);
       tree->SetBranchAddress("Sys__MURMUF__1up", &sample_sys->at(wh_MURMUF__1up), &b_Sys__MURMUF__1up);
       tree->SetBranchAddress("Sys__MUR__1down", &sample_sys->at(wh_MUR__1down), &b_Sys__MUR__1down);
       tree->SetBranchAddress("Sys__MUF__1up", &sample_sys->at(wh_MUF__1up), &b_Sys__MUF__1up);
       tree->SetBranchAddress("Sys__MUF__1down", &sample_sys->at(wh_MUF__1down), &b_Sys__MUF__1down);
       tree->SetBranchAddress("Sys__MURMUF__1down", &sample_sys->at(wh_MURMUF__1down), &b_Sys__MURMUF__1down);
     }

     if(m_process == "stopt"){
       tree->SetBranchAddress("Sys__RadLo", &sample_sys->at(stopt_RadLo), &b_Sys__RadLo);
       tree->SetBranchAddress("Sys__RadHi", &sample_sys->at(stopt_RadHi), &b_Sys__RadHi);
     }

     if(m_process == "WZqcd"){
       tree->SetBranchAddress("Sys__MUR__1up", &sample_sys->at(wz_MUR__1up), &b_Sys__MUR__1up);
       tree->SetBranchAddress("Sys__MURMUF__1up", &sample_sys->at(wz_MURMUF__1up), &b_Sys__MURMUF__1up);
       tree->SetBranchAddress("Sys__MUR__1down", &sample_sys->at(wz_MUR__1down), &b_Sys__MUR__1down);
       tree->SetBranchAddress("Sys__MUF__1up", &sample_sys->at(wz_MUF__1up), &b_Sys__MUF__1up);
       tree->SetBranchAddress("Sys__MUF__1down", &sample_sys->at(wz_MUF__1down), &b_Sys__MUF__1down);
       tree->SetBranchAddress("Sys__MURMUF__1down", &sample_sys->at(wz_MURMUF__1down), &b_Sys__MURMUF__1down);
     }

     if(m_process == "WZewk"){
       tree->SetBranchAddress("Sys__MUR2_MUF1", &sample_sys->at(wzjj_MUR2_MUF1), &b_Sys__MUR2_MUF1);
       tree->SetBranchAddress("Sys__MUR2_MUF2", &sample_sys->at(wzjj_MUR2_MUF2), &b_Sys__MUR2_MUF2);
       tree->SetBranchAddress("Sys__MUR05_MUF1", &sample_sys->at(wzjj_MUR05_MUF1), &b_Sys__MUR05_MUF1);
       tree->SetBranchAddress("Sys__MUR1_MUF2", &sample_sys->at(wzjj_MUR1_MUF2), &b_Sys__MUR1_MUF2);
       tree->SetBranchAddress("Sys__MUR1_MUF05", &sample_sys->at(wzjj_MUR1_MUF05), &b_Sys__MUR1_MUF05);
       tree->SetBranchAddress("Sys__MUR05_MUF05", &sample_sys->at(wzjj_MUR05_MUF05), &b_Sys__MUR05_MUF05);
     }

   
     tree->SetBranchAddress("Sys__MUON_EFF_TrigSystUncertainty__1up", &tsys->at(MUON_EFF_TrigSystUncertainty__1up), &b_Sys__MUON_EFF_TrigSystUncertainty__1up);
     tree->SetBranchAddress("Sys__MUON_EFF_TrigSystUncertainty__1down", &tsys->at(MUON_EFF_TrigSystUncertainty__1down), &b_Sys__MUON_EFF_TrigSystUncertainty__1down);
     tree->SetBranchAddress("Sys__MUON_EFF_TrigStatUncertainty__1up", &tsys->at(MUON_EFF_TrigStatUncertainty__1up), &b_Sys__MUON_EFF_TrigStatUncertainty__1up);
     tree->SetBranchAddress("Sys__MUON_EFF_TrigStatUncertainty__1down", &tsys->at(MUON_EFF_TrigStatUncertainty__1down), &b_Sys__MUON_EFF_TrigStatUncertainty__1down);
     tree->SetBranchAddress("Sys__METTrigStat__1up", &tsys->at(METTrigStat__1up), &b_Sys__METTrigStat__1up);
     tree->SetBranchAddress("Sys__METTrigStat__1down", &tsys->at(METTrigStat__1down), &b_Sys__METTrigStat__1down);
     tree->SetBranchAddress("Sys__METTrigTop__1up", &tsys->at(METTrigTop__1up), &b_Sys__METTrigTop__1up);
     tree->SetBranchAddress("Sys__METTrigTop__1down", &tsys->at(METTrigTop__1down), &b_Sys__METTrigTop__1down);
     tree->SetBranchAddress("Sys__METTrigZ__1up", &tsys->at(METTrigZ__1up), &b_Sys__METTrigZ__1up);
     tree->SetBranchAddress("Sys__METTrigZ__1down", &tsys->at(METTrigZ__1down), &b_Sys__METTrigZ__1down);
     tree->SetBranchAddress("Sys__METTrigSumpt__1up", &tsys->at(METTrigSumpt__1up), &b_Sys__METTrigSumpt__1up);
     tree->SetBranchAddress("Sys__METTrigSumpt__1down", &tsys->at(METTrigSumpt__1down), &b_Sys__METTrigSumpt__1down);

     tree->SetBranchAddress("Sys__C_0", &csys->at(0), &b_Sys__C_0);
     tree->SetBranchAddress("Sys__C_10", &csys->at(10), &b_Sys__C_10);
     tree->SetBranchAddress("Sys__C_11", &csys->at(11), &b_Sys__C_11);
     tree->SetBranchAddress("Sys__C_12", &csys->at(12), &b_Sys__C_12);
     tree->SetBranchAddress("Sys__C_13", &csys->at(13), &b_Sys__C_13);
     tree->SetBranchAddress("Sys__C_14", &csys->at(14), &b_Sys__C_14);
     tree->SetBranchAddress("Sys__C_15", &csys->at(15), &b_Sys__C_15);
     tree->SetBranchAddress("Sys__C_16", &csys->at(16), &b_Sys__C_16);
     tree->SetBranchAddress("Sys__C_17", &csys->at(17), &b_Sys__C_17);
     tree->SetBranchAddress("Sys__C_18", &csys->at(18), &b_Sys__C_18);
     tree->SetBranchAddress("Sys__C_19", &csys->at(19), &b_Sys__C_19);
     tree->SetBranchAddress("Sys__C_1", &csys->at(1), &b_Sys__C_1);
     tree->SetBranchAddress("Sys__C_2", &csys->at(2), &b_Sys__C_2);
     tree->SetBranchAddress("Sys__C_3", &csys->at(3), &b_Sys__C_3);
     tree->SetBranchAddress("Sys__C_4", &csys->at(4), &b_Sys__C_4);
     tree->SetBranchAddress("Sys__C_5", &csys->at(5), &b_Sys__C_5);
     tree->SetBranchAddress("Sys__C_6", &csys->at(6), &b_Sys__C_6);
     tree->SetBranchAddress("Sys__C_7", &csys->at(7), &b_Sys__C_7);
     tree->SetBranchAddress("Sys__C_8", &csys->at(8), &b_Sys__C_8);
     tree->SetBranchAddress("Sys__C_9", &csys->at(9), &b_Sys__C_9);
     tree->SetBranchAddress("Sys__Light_0", &lsys->at(0), &b_Sys__Light_0);
     tree->SetBranchAddress("Sys__Light_10", &lsys->at(10), &b_Sys__Light_10);
     tree->SetBranchAddress("Sys__Light_11", &lsys->at(11), &b_Sys__Light_11);
     tree->SetBranchAddress("Sys__Light_12", &lsys->at(12), &b_Sys__Light_12);
     tree->SetBranchAddress("Sys__Light_13", &lsys->at(13), &b_Sys__Light_13);
     tree->SetBranchAddress("Sys__Light_14", &lsys->at(14), &b_Sys__Light_14);
     tree->SetBranchAddress("Sys__Light_15", &lsys->at(15), &b_Sys__Light_15);
     tree->SetBranchAddress("Sys__Light_16", &lsys->at(16), &b_Sys__Light_16);
     tree->SetBranchAddress("Sys__Light_17", &lsys->at(17), &b_Sys__Light_17);
     tree->SetBranchAddress("Sys__Light_18", &lsys->at(18), &b_Sys__Light_18);
     tree->SetBranchAddress("Sys__Light_19", &lsys->at(19), &b_Sys__Light_19);
     tree->SetBranchAddress("Sys__Light_1", &lsys->at(1), &b_Sys__Light_1);
     tree->SetBranchAddress("Sys__Light_2", &lsys->at(2), &b_Sys__Light_2);
     tree->SetBranchAddress("Sys__Light_3", &lsys->at(3), &b_Sys__Light_3);
     tree->SetBranchAddress("Sys__Light_4", &lsys->at(4), &b_Sys__Light_4);
     tree->SetBranchAddress("Sys__Light_5", &lsys->at(5), &b_Sys__Light_5);
     tree->SetBranchAddress("Sys__Light_6", &lsys->at(6), &b_Sys__Light_6);
     tree->SetBranchAddress("Sys__Light_7", &lsys->at(7), &b_Sys__Light_7);
     tree->SetBranchAddress("Sys__Light_8", &lsys->at(8), &b_Sys__Light_8);
     tree->SetBranchAddress("Sys__Light_9", &lsys->at(9), &b_Sys__Light_9);
     tree->SetBranchAddress("Sys__B_0", &bsys->at(0), &b_Sys__B_0);
     tree->SetBranchAddress("Sys__B_10", &bsys->at(10), &b_Sys__B_10);
     tree->SetBranchAddress("Sys__B_11", &bsys->at(11), &b_Sys__B_11);
     tree->SetBranchAddress("Sys__B_12", &bsys->at(12), &b_Sys__B_12);
     tree->SetBranchAddress("Sys__B_13", &bsys->at(13), &b_Sys__B_13);
     tree->SetBranchAddress("Sys__B_14", &bsys->at(14), &b_Sys__B_14);
     tree->SetBranchAddress("Sys__B_15", &bsys->at(15), &b_Sys__B_15);
     tree->SetBranchAddress("Sys__B_16", &bsys->at(16), &b_Sys__B_16);
     tree->SetBranchAddress("Sys__B_17", &bsys->at(17), &b_Sys__B_17);
     tree->SetBranchAddress("Sys__B_18", &bsys->at(18), &b_Sys__B_18);
     tree->SetBranchAddress("Sys__B_19", &bsys->at(19), &b_Sys__B_19);
     tree->SetBranchAddress("Sys__B_1", &bsys->at(1), &b_Sys__B_1);
     tree->SetBranchAddress("Sys__B_20", &bsys->at(20), &b_Sys__B_20);
     tree->SetBranchAddress("Sys__B_21", &bsys->at(21), &b_Sys__B_21);
     tree->SetBranchAddress("Sys__B_22", &bsys->at(22), &b_Sys__B_22);
     tree->SetBranchAddress("Sys__B_23", &bsys->at(23), &b_Sys__B_23);
     tree->SetBranchAddress("Sys__B_24", &bsys->at(24), &b_Sys__B_24);
     tree->SetBranchAddress("Sys__B_25", &bsys->at(25), &b_Sys__B_25);
     tree->SetBranchAddress("Sys__B_26", &bsys->at(26), &b_Sys__B_26);
     tree->SetBranchAddress("Sys__B_27", &bsys->at(27), &b_Sys__B_27);
     tree->SetBranchAddress("Sys__B_28", &bsys->at(28), &b_Sys__B_28);
     tree->SetBranchAddress("Sys__B_29", &bsys->at(29), &b_Sys__B_29);
     tree->SetBranchAddress("Sys__B_2", &bsys->at(2), &b_Sys__B_2);
     tree->SetBranchAddress("Sys__B_30", &bsys->at(30), &b_Sys__B_30);
     tree->SetBranchAddress("Sys__B_31", &bsys->at(31), &b_Sys__B_31);
     tree->SetBranchAddress("Sys__B_32", &bsys->at(32), &b_Sys__B_32);
     tree->SetBranchAddress("Sys__B_33", &bsys->at(33), &b_Sys__B_33);
     tree->SetBranchAddress("Sys__B_34", &bsys->at(34), &b_Sys__B_34);
     tree->SetBranchAddress("Sys__B_35", &bsys->at(35), &b_Sys__B_35);
     tree->SetBranchAddress("Sys__B_36", &bsys->at(36), &b_Sys__B_36);
     tree->SetBranchAddress("Sys__B_37", &bsys->at(37), &b_Sys__B_37);
     tree->SetBranchAddress("Sys__B_38", &bsys->at(38), &b_Sys__B_38);
     tree->SetBranchAddress("Sys__B_39", &bsys->at(39), &b_Sys__B_39);
     tree->SetBranchAddress("Sys__B_3", &bsys->at(3), &b_Sys__B_3);
     tree->SetBranchAddress("Sys__B_40", &bsys->at(40), &b_Sys__B_40);
     tree->SetBranchAddress("Sys__B_41", &bsys->at(41), &b_Sys__B_41);
     tree->SetBranchAddress("Sys__B_42", &bsys->at(42), &b_Sys__B_42);
     tree->SetBranchAddress("Sys__B_43", &bsys->at(43), &b_Sys__B_43);
     tree->SetBranchAddress("Sys__B_44", &bsys->at(44), &b_Sys__B_44);
     tree->SetBranchAddress("Sys__B_4", &bsys->at(4), &b_Sys__B_4);
     tree->SetBranchAddress("Sys__B_5", &bsys->at(5), &b_Sys__B_5);
     tree->SetBranchAddress("Sys__B_6", &bsys->at(6), &b_Sys__B_6);
     tree->SetBranchAddress("Sys__B_7", &bsys->at(7), &b_Sys__B_7);
     tree->SetBranchAddress("Sys__B_8", &bsys->at(8), &b_Sys__B_8);
     tree->SetBranchAddress("Sys__B_9", &bsys->at(9), &b_Sys__B_9);

   }

}

#endif // #ifdef SysAnalysis_cxx
