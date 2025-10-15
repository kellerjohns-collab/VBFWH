# VBFWH
Miscellaneous code for the VBF WH analysis.

CxAODs are made using CxAOD Maker, and turned to Easy Trees with CxAOD Reader. These are not in this repository.

ETAnalysis and SysAnalysis run on the Easy Trees to create histograms. ETAnalysis plots a number of variables in various regions, useful for investigative studies. SysAnalysis creates the histograms including systematic uncertainties needed for the final statistical analysis.

kFactors.C and .h has the implementation of the analytical statistical framework.

PlotStack.C is for plotting data/MC comparisons.

Separately, VBF_WHplots.cc implements the cutflow on truth files using rivet.