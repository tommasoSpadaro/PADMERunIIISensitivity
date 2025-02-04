#!/usr/bin/perl -w

$maxjobs = $ARGV[0]; # max number of jobs simultaneously running together
$username = $ARGV[1]; # needed to retrieve number of jobs running
$seedStem = $ARGV[2]; # starting seed value

$nSteps = 199; #number of pseudo-events
$iStep = -1;

$loopCond = 1;

while ($loopCond == 1){
    
    $numberOfRunningJobs = "ps -fu $username | grep runStatisticalTreatment | wc -l";
    open (JOBSNOW, "$numberOfRunningJobs \|");
    $njobs = 0;
    while(<JOBSNOW>) {
	chomp;
	$njobs = $_;
	$njobs--;
    }

    if ($njobs < $maxjobs && $iStep < $nSteps) { #when jobs are < maxjobs start a new submission
	$iStep++;
	$seed = $seedStem+$iStep;

	open (CONFIG, "input/config_generic.txt") or die "cannot open config file input/config_generic.txt\n";
	$configOut = "input/config_generic_seed_${seed}.txt";
	open (CONFIGOUT, ">$configOut") or die "cannot open config file $configOut.txt\n";
	while (<CONFIG>){
	    chomp;
	    if (/^Seed/) {print CONFIGOUT "Seed $seed\n";}
#	    elsif (/^Verbosity/) {print CONFIGOUT "Verbosity 2\n";}
# mass window
	    elsif (/^MassStep/){print CONFIGOUT "MassStep 0.06\n";} # instead of 0.02
	    elsif (/^MassMin/){print CONFIGOUT "MassMin 16.22\n";} # instead of 16.22
	    elsif (/^MassMax/){print CONFIGOUT "MassMax 17.74\n";} # instead of 17.62
# gve bins
	    elsif (/^NgveBins/){print CONFIGOUT "NgveBins 40\n";} # instead of 20
	    elsif (/^ToyOfToyMode/) {print CONFIGOUT "ToyOfToyMode 0\n";} #read NObs from file

	    # INPUT FILE for POT, EFF, PERIODS, BKG
#	    elsif (/InputFileName /) {print CONFIGOUT "InputFileName ~/PADME/PADME_sensitivity/input/MCVersion2_POTErrorScanLevel_BKG0.006_EFF0.004.root\n";}
	    elsif (/InputFileName /) {print CONFIGOUT "InputFileName ~/PADME/PADME_sensitivity/input/MCVersion2_POTErrorScanLevel_BKG0.006_EFF0.004_POTnominalRunIII.root\n";}
	    
	    # INPUT FILENAME for PSEUDOEVENTS
	    # elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMC_seed1000_useNuis1_useEffiOverBkgCurve1.root\n";}
# elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_seed2100_useNuis1_useEffiOverBkgCurve0.root\n";}
# elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion1_seed1200_useNuis1_useEffiOverBkgCurve1.root\n";}
# elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_POTErrorScanLevel_seed4100_useNuis1_useEffiOverBkgCurve1.root\n";}
# elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_POTErrorScanLevel_seed5100_useNuis1_useEffiOverBkgCurve1.root\n";}
#	    elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_POTErrorScanLevel_seed7100_useNuis1_useEffiOverBkgCurve1.root\n";} # bkg only
#	    elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_POTErrorScanLevel_seed8100_useNuis1_useEffiOverBkgCurve1.root\n";} # bkg+signal 0.06-MeV spaced mass points, 40 points linear scale in gve in the range 1,8 x 10^-4 
#	    elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_POTErrorScanLevel_seed9200_useNuis1_useEffiOverBkgCurve1.root\n";} # bkg only, 1000 pseudoevents, POT=1E10
	    elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_POTErrorScanLevel_seed9200_useNuis1_useEffiOverBkgCurve1.root\n";} # bkg only, 1000 pseudoevents, POT=1E10, error on the background down by x10
	    elsif (/^ErrorImprove/) {print CONFIGOUT "ErrorImprove 10.\n";}
	    # BKG-ONLY PSEUDOEVENTS
	    elsif (/^BkgOnlyNObsFromFile/) {print CONFIGOUT "BkgOnlyNObsFromFile 1\n";} # read bkg-only input
#	    elsif (/^NumberOfGenerations /) {print CONFIGOUT "NumberOfGenerations 800\n";} # read bkg-only input

	    # SIG+BKG PSEUDOEVENTS
#	    elsif (/^BkgOnlyNObsFromFile/) {print CONFIGOUT "BkgOnlyNObsFromFile 0\n";} # read sig+bkg input
#	    elsif (/^WantedMassNObsFromFile/) {print CONFIGOUT "WantedMassNObsFromFile 16.92\n";} # use sig+bkg input
#	    elsif (/^WantedGveNObsFromFile/) {print CONFIGOUT "WantedGveNObsFromFile 0.0006\n";}  # use sig+bkg input

#	    elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersionRunIV_seed1400_useNuis1_useEffiOverBkgCurve1.root\n";}
	    elsif (/^FirstEventNObsFromFile/){print CONFIGOUT "FirstEventNObsFromFile $iStep\n";}
	    elsif (/^ManipulateInput/){print CONFIGOUT "ManipulateInput 0\n";} # to decrease the yield
	    elsif (/^AssumeEffiOverBkgCurve/){print CONFIGOUT "AssumeEffiOverBkgCurve 2\n";}
	    elsif (/^StraightFitMode/){print CONFIGOUT "StraightFitMode 1\n";}
#	    elsif (/^StraightFitMode/){print CONFIGOUT "StraightFitMode 2\n";}
	    # TO PUT FREQ ONLY EVALUATION:
#	    elsif (/^EvaluateExpLimit/){print CONFIGOUT "EvaluateExpLimit 0\n";} # ONLY FREQUENTIST

	    # TO TEST ABSENCE OF ELECTRON MOTION
#	    elsif (/^SignalLorentzianWidth /){print CONFIGOUT "SignalLorentzianWidth 0.6\n";}        #to test absence of electron motion: instead of 1.72
#	    elsif (/^SignalLorentzianWidthErr/){print CONFIGOUT "SignalLorentzianWidthErr 0.014\n";} #to test absence of electron motion: instead of 0.039
	    else         {print CONFIGOUT "$_\n";}
	}
	close CONFIGOUT;
	$command = "./bin/runStatisticalTreatment $configOut > logs/runEvent_useEffiCurve2_${iStep}_seed${seed}.log &";
	print "execute $command\n";
	system($command);
    }
    elsif ($iStep < $nSteps) {
	print "Presently $njobs jobs are running, wait 15 s \n";
	system("sleep 15");
    }
    else {
	$loopCond = 0;
    }
}
# For MCVersion0 (no magnetic field, old analysis):
# -EffiOverBkgObsP0_0 20752
# -EffiOverBkgObsP1_0 1042.69
# -EffiOverBkgErrP0_0 51.2548
# -EffiOverBkgErrP1_0 165.793
# -EffiOverBkgErrP0P1Corr_0 0.00185491
# -EffiOverBkgObsP0_1 20950.9
# -EffiOverBkgObsP1_1 615.989
# -EffiOverBkgErrP0_1 56.598
# -EffiOverBkgErrP1_1 159.678
# -EffiOverBkgErrP0P1Corr_1 -0.530699
# -EffiOverBkgObsP0_2 20830
# -EffiOverBkgObsP1_2 895.463
# -EffiOverBkgErrP0_2 36.7071
# -EffiOverBkgErrP1_2 109.881
# -EffiOverBkgErrP0P1Corr_2 -0.29936
#
# For MCVersion1 (magnetic field for the signal, no magnetic field for the bkg, new analysis with tighter phi rcut and looser cut on r (no cut on cluster 2 radius):
#
# +EffiOverBkgObsP0_0 27443.6
# +EffiOverBkgObsP1_0 2759.3
# +EffiOverBkgErrP0_0 63.9133
# +EffiOverBkgErrP1_0 204.712
# +EffiOverBkgErrP0P1Corr_0 0.0773278
# +EffiOverBkgObsP0_1 27186.8
# +EffiOverBkgObsP1_1 2663.12
# +EffiOverBkgErrP0_1 68.4073
# +EffiOverBkgErrP1_1 198.233
# +EffiOverBkgErrP0P1Corr_1 -0.476311
# +EffiOverBkgObsP0_2 27312.2
# +EffiOverBkgObsP1_2 2589.87
# +EffiOverBkgErrP0_2 44.9336
# +EffiOverBkgErrP1_2 136.161
# +EffiOverBkgErrP0P1Corr_2 -0.228923
#
# For MCVersion2 (magnetic field for the signal and bkg, POT corrected,  no magnetic field for the bkg, new analysis with tighter phi rcut and looser cut on r (no cut on cluster 2 radius):
#
#EffiOverBkgObsP0_0 23667.7
#EffiOverBkgObsP1_0 2503.84
#EffiOverBkgErrP0_0 40.4747
#EffiOverBkgErrP1_0 129.26
#EffiOverBkgErrP0P1Corr_0 0.103481
#EffiOverBkgObsP0_1 23712.5
#EffiOverBkgObsP1_1 2702.23
#EffiOverBkgErrP0_1 44.0717
#EffiOverBkgErrP1_1 129.828
#EffiOverBkgErrP0P1Corr_1 -0.426455
#EffiOverBkgObsP0_2 23697.9
#EffiOverBkgObsP1_2 2626.57
#EffiOverBkgErrP0_2 28.768
#EffiOverBkgErrP1_2 88.0593
#EffiOverBkgErrP0P1Corr_2 -0.174639
#
