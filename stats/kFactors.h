class kFactors{
public:

  kFactors();
  vector<double> GetFactors(TString opt = "");
  vector<double> GetValue(TString opt = "", int ind = 0);
  vector<float> GetDetectorSysts(TString opt = "", bool print = true);
  vector<float> GetBackgroundSysts(TString opt = "", bool print = true);
  void GetDDSysts(TString opt = "");
  vector<float> GetSigSysts(TString opt = "", bool print = true);
  void GetSigKappas(TString opt = "");
  void PrintTables();
  
  float GetMu2Bin(float N1 = 1, float N2 = 1, float B1 = 1., float B2 = 1., float S1 = 1., float S2 = 1., bool verbose = false);
  vector<float>* GetPosLamMu(float Nloose, float Ntight, TString opt = "");
  float GetMuUpperLimit(float N1, float N2, float B1, float B2, float S1, float S2, float SystUp, float SystDown, bool verbose = true);
  pair<float,float> GetMuErrors(float N1, float N2, float B1, float B2, float S1, float S2, bool verbose);
  vector<TH1F*> ThrowToys(int nToys = 10);
  void GetContour();
  
  TFile* f_wj;
  TFile* f_tt;
  TFile* f_wt;
  TFile* f_wh;
  TFile* f_wz;
  TFile* f_ot;
  TFile* f_da;
  TFile* f_sp;
  TFile* f_sn;

  TFile* f_tt_amc;
  TFile* f_tt_rhi;
  TFile* f_tt_rhp;
  TFile* f_tt_her;
  TFile* f_tt_hda;
  TFile* f_tt_v05;
  TFile* f_wt_v05;
  TFile* f_wj_mg;
  TFile* f_wj_11;
  TFile* f_wj_fx;
  TFile* f_wt_ds;
  TFile* f_wt_her;
  TFile* f_wt_amc;

  TFile* f_zj;
  TFile* f_tc;
  TFile* f_tc_amc;
  TFile* f_tc_her;
  TFile* f_wzq;
  TFile* f_wze;
  TFile* f_th;
  TFile* f_zh;
  TFile* f_tv;
  
  vector<TString> BVars;
  vector<TString> CVars;
  vector<TString> LVars;
  vector<TString> FlavVars;
  
  vector<TString> JESVars;
  vector<TString> JERVars;
  vector<TString> MuonVars;
  vector<TString> ElVars;
  vector<TString> METVars;
  vector<TString> TauVars;
  vector<TString> JvtVars;
  vector<TString> DetVars;
  
};

kFactors::kFactors(){

  //jk add VR by hand if needed
  // f_wj = new TFile("sysFilesVR/sys_W.root"); 
  // f_tt = new TFile("sysFilesVR/sys_ttbar.root"); 
  // f_wt = new TFile("sysFilesVR/sys_Wt.root"); 
  // f_ot = new TFile("sysFilesVR/sys_other.root");
  // f_wh = new TFile("sysFilesVR/sys_WH.root"); 
  // f_wz = new TFile("sysFilesVR/sys_WZ.root");
  // f_da = new TFile("sysFilesVR/sys_data.root"); 
  // f_sp = new TFile("sysFilesVR/sys_SigPos.root");
  // f_sn = new TFile("sysFilesVR/sys_SigNeg.root");

  f_wj = new TFile("sysFiles/sys_W.root"); 
  f_tt = new TFile("sysFiles/sys_ttbar.root"); 
  f_wt = new TFile("sysFiles/sys_Wt.root"); 
  f_ot = new TFile("sysFiles/sys_other.root");
  f_wh = new TFile("sysFiles/sys_WH.root"); 
  f_wz = new TFile("sysFiles/sys_WZ.root");
  f_da = new TFile("sysFiles/sys_data.root"); 
  f_sp = new TFile("sysFiles/sys_SigPos.root");
  f_sn = new TFile("sysFiles/sys_SigNeg.root");

  f_tt_amc = new TFile("sysFiles/sys_ttbar_aMC.root");
  f_tt_rhi = new TFile("sysFiles/sys_ttbar_RadHi.root");
  f_tt_rhp = new TFile("sysFiles/sys_ttbar_RadHiPrime.root");
  f_tt_her = new TFile("sysFiles/sys_ttbar_Herwig.root");
  f_tt_v05 = new TFile("sysFiles/sys_ttbar05.root");
  f_wt_v05 = new TFile("sysFiles/sys_Wt05.root");
  f_tt_hda = new TFile("sysFiles/sys_ttbar_hdamp.root");
  f_wt_amc = new TFile("sysFiles/sys_Wt_aMC.root");
  f_wt_ds = new TFile("sysFiles/sys_Wt_DS.root");
  f_wt_her = new TFile("sysFiles/sys_Wt_Herwig.root");
  f_wj_mg = new TFile("sysFiles/sys_W_MGPy8.root");
  f_wj_11 = new TFile("sysFiles/sys_W_Sh2211.root");
  f_wj_fx = new TFile("sysFiles/sys_W_FxFx.root");

  f_zj = new TFile("sysFiles/sys_Z.root");
  f_tc = new TFile("sysFiles/sys_stopt.root");
  f_tc_amc = new TFile("sysFiles/sys_stopt_aMC.root");
  f_tc_her = new TFile("sysFiles/sys_stopt_Herwig.root");
  f_wzq = new TFile("sysFiles/sys_WZqcd.root"); 
  f_wze = new TFile("sysFiles/sys_WZewk.root");
  f_th = new TFile("sysFiles/sys_ttH.root");
  f_zh = new TFile("sysFiles/sys_ZH.root"); 
  f_tv = new TFile("sysFiles/sys_ttV.root");
  
  BVars = {"SYS_B0", "SYS_B1", "SYS_B2", "SYS_B3", "SYS_B4", "SYS_B5", "SYS_B6", "SYS_B7", "SYS_B8", "SYS_B9",
	   "SYS_B10", "SYS_B11", "SYS_B12", "SYS_B13", "SYS_B14", "SYS_B15", "SYS_B16", "SYS_B17", "SYS_B18", "SYS_B19",
	   "SYS_B20", "SYS_B21", "SYS_B22", "SYS_B23", "SYS_B24", "SYS_B25", "SYS_B26", "SYS_B27", "SYS_B28", "SYS_B29",
	   "SYS_B30", "SYS_B31", "SYS_B32", "SYS_B33", "SYS_B34", "SYS_B35", "SYS_B36", "SYS_B37", "SYS_B38", "SYS_B39",
	   "SYS_B40", "SYS_B41", "SYS_B42", "SYS_B43", "SYS_B44"};

  CVars = {"SYS_C0", "SYS_C1", "SYS_C2", "SYS_C3", "SYS_C4", "SYS_C5", "SYS_C6", "SYS_C7", "SYS_C8", "SYS_C9",
	   "SYS_C10", "SYS_C11", "SYS_C12", "SYS_C13", "SYS_C14", "SYS_C15", "SYS_C16", "SYS_C17", "SYS_C18", "SYS_C19"};

  LVars = { "SYS_L0", "SYS_L1", "SYS_L2", "SYS_L3", "SYS_L4", "SYS_L5", "SYS_L6", "SYS_L7", "SYS_L8", "SYS_L9",
	    "SYS_L10", "SYS_L11", "SYS_L12", "SYS_L13", "SYS_L14", "SYS_L15", "SYS_L16", "SYS_L17", "SYS_L18", "SYS_L19"};

  FlavVars = BVars;
  FlavVars.insert(FlavVars.end(), CVars.begin(), CVars.end());
  FlavVars.insert(FlavVars.end(), LVars.begin(), LVars.end());  
  
  JESVars = {"SYS_JET_BJES_Response", 
	     "SYS_JET_EffectiveNP_Detector1", 
	     "SYS_JET_EffectiveNP_Detector2", 
	     "SYS_JET_EffectiveNP_Mixed1", 
	     "SYS_JET_EffectiveNP_Mixed2", 
	     "SYS_JET_EffectiveNP_Mixed3", 
	     "SYS_JET_EffectiveNP_Modelling1", 
	     "SYS_JET_EffectiveNP_Modelling2", 
	     "SYS_JET_EffectiveNP_Modelling3", 
	     "SYS_JET_EffectiveNP_Modelling4", 
	     "SYS_JET_EffectiveNP_Statistical1", 
	     "SYS_JET_EffectiveNP_Statistical2", 
	     "SYS_JET_EffectiveNP_Statistical3", 
	     "SYS_JET_EffectiveNP_Statistical4", 
	     "SYS_JET_EffectiveNP_Statistical5", 
	     "SYS_JET_EffectiveNP_Statistical6", 
	     "SYS_JET_EtaIntercalibration_Modelling", 
	     "SYS_JET_EtaIntercalibration_NonClosure_2018data", 
	     "SYS_JET_EtaIntercalibration_TotalStat", 
	     "SYS_JET_Flavor_Composition", 
	     "SYS_JET_Flavor_Response", 
	     "SYS_JET_Pileup_OffsetMu", 
	     "SYS_JET_Pileup_OffsetNPV", 
	     "SYS_JET_Pileup_PtTerm", 
	     "SYS_JET_Pileup_RhoTopology"};

  METVars = {"SYS_METTrigStat", 
	     "SYS_METTrigSumpt", 
	     "SYS_METTrigTop", 
	     "SYS_METTrigZ",
	     "SYS_MET_SoftTrk_Scale",
	     "SYS_MET_SoftTrk_ResoPara",
  	     "SYS_MET_SoftTrk_ResoPerp"};

  MuonVars = {"SYS_MUON_EFF_ISO_STAT",            
	      "SYS_MUON_EFF_ISO_SYS",             
	      "SYS_MUON_EFF_RECO_STAT",           
	      "SYS_MUON_EFF_RECO_STAT_LOWPT",     
	      "SYS_MUON_EFF_RECO_SYS",            
	      "SYS_MUON_EFF_RECO_SYS_LOWPT",      
	      "SYS_MUON_EFF_TrigStatUncertainty", 
	      "SYS_MUON_EFF_TrigSystUncertainty", 
	      "SYS_MUON_EFF_TTVA_STAT",           
	      "SYS_MUON_SAGITTA_DATASTAT",        
	      "SYS_MUON_SAGITTA_RESBIAS",         
	      "SYS_MUON_SCALE",
	      "SYS_MUON_CB"};

  ElVars = {"SYS_EG_RESOLUTION_ALL",                        
	    "SYS_EG_SCALE_ALL",                             
	    "SYS_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR",        
	    "SYS_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR",       
	    "SYS_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR",      
	    "SYS_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR",   
	    "SYS_EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR"};

  TauVars = {"SYS_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT",              
	     "SYS_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST",              
	     "SYS_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL",               
	     "SYS_TAUS_TRUEHADTAU_EFF_RECO_TOTAL",                 
	     "SYS_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025", 
	     "SYS_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530", 
	     "SYS_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040", 
	     "SYS_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40", 
	     "SYS_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025", 
	     "SYS_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530", 
	     "SYS_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040", 
	     "SYS_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40", 
	     "SYS_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT",               
	     "SYS_TAUS_TRUEHADTAU_EFF_RNNID_SYST",                 
	     "SYS_TAUS_TRUEHADTAU_SME_TES_DETECTOR",               
	     "SYS_TAUS_TRUEHADTAU_SME_TES_INSITUEXP",              
	     "SYS_TAUS_TRUEHADTAU_SME_TES_INSITUFIT",              
	     "SYS_TAUS_TRUEHADTAU_SME_TES_MODEL_CLOSURE",          
	     "SYS_TAUS_TRUEHADTAU_SME_TES_PHYSICSLIST"};

  JERVars = {"JER_EffectiveNP_1",          
	     "JER_EffectiveNP_2",          
	     "JER_EffectiveNP_3",          
	     "JER_EffectiveNP_4",          
	     "JER_EffectiveNP_5",          
	     "JER_EffectiveNP_6",          
	     "JER_EffectiveNP_7",          
	     "JER_EffectiveNP_8",          
	     "JER_EffectiveNP_9",
	     "JER_EffectiveNP_10",         
	     "JER_EffectiveNP_11",
	     "JER_EffectiveNP_12restTerm",
	     "JER_DataVsMC_MC16"};

  JvtVars = {"SYS_JET_fJvtEfficiency",
	     "SYS_JET_JvtEfficiency"};
  
  DetVars = JERVars;
  DetVars.insert( DetVars.begin(), METVars.begin(), METVars.end());
  DetVars.insert( DetVars.begin(), MuonVars.begin(), MuonVars.end());
  DetVars.insert( DetVars.begin(), ElVars.begin(), ElVars.end());
  DetVars.insert( DetVars.begin(), TauVars.begin(), TauVars.end());
  DetVars.insert( DetVars.begin(), JESVars.begin(), JESVars.end());
    

}
