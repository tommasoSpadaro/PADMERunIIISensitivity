#!/usr/bin/perl -w

$maxjobs = $ARGV[0]; # max number of jobs simultaneously running together
$username = $ARGV[1]; # needed to retrieve number of jobs running
$seedStem = $ARGV[2]; # starting seed value

$nSteps = 1;#315;#200;#1 #200;#9;#199; #number of pseudo-events
$iStep = 0;

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
	    
	    elsif (/^MassStep/){print CONFIGOUT "MassStep 0.02\n";} # instead of 0.06
	    elsif (/^MassMin/){print CONFIGOUT "MassMin 16.22\n";} # instead of 16.22
	    elsif (/^MassMax/){print CONFIGOUT "MassMax 17.74\n";} # instead of 17.62

#	    elsif (/^MassStep/){print CONFIGOUT "MassStep 0.04\n";} # instead of 0.06
#	    elsif (/^MassMin/){print CONFIGOUT "MassMin 16.32\n";} # instead of 16.32
#	    elsif (/^MassMax/){print CONFIGOUT "MassMax 17.60\n";} # instead of 17.62

# gve bins

	    elsif (/^NgveBins/){print CONFIGOUT "NgveBins 40\n";} # instead of 20
	    elsif (/^gveMin/){print CONFIGOUT "gveMin 0.0001\n";}
	    elsif (/^gveMax/){print CONFIGOUT "gveMax 0.001\n";} 
#
#	    elsif (/^NgveBins/){print CONFIGOUT "NgveBins 80\n";} # instead of 20
#	    elsif (/^gveMin/){print CONFIGOUT "gveMin 0.0001\n";}
#	    elsif (/^gveMax/){print CONFIGOUT "gveMax 0.002\n";} 

	    # INPUT FILE for POT, EFF, PERIODS, BKG
#	    elsif (/InputFileName /) {print CONFIGOUT "InputFileName ~/PADME/PADME_sensitivity/input/MCVersion2_POTErrorScanLevel_BKG0.006_EFF0.004.root\n";}
#	    elsif (/InputFileName /) {print CONFIGOUT "InputFileName ~/PADME/PADME_sensitivity/input/MCVersion2_POTErrorScanLevel_BKG0.006_EFF0.004_POTnominalRunIII.root\n";}
#	    elsif (/InputFileName /) {print CONFIGOUT "InputFileName ~/PADME/PADME_sensitivity/input/MCVersion2_POTError0.01_BKG0.006_EFF0.004_POTnominalRunIII.root\n";}
#	    elsif (/InputFileName /) {print CONFIGOUT "InputFileName ~/PADME/PADME_sensitivity/input/MCVersion2_POTError0.02_BKG0.006_EFF0.004_POTnominalRunIII.root\n";}
#	    elsif (/InputFileName /) {print CONFIGOUT "InputFileName ~/PADME/PADME_sensitivity/input/MCVersion2_POTErrorFinal_BKG0.004_EFF0.004_bugfix.root\n";}
#	    elsif (/InputFileName /) {print CONFIGOUT "InputFileName ~/PADME/PADME_sensitivity/input/prova.root\n";}
	    elsif (/InputFileName /) {print CONFIGOUT "InputFileName ~/PADME/PADME_sensitivity/input/completedRunIII_0.3pctOnB_0.3pctOnPoT.root\n";}

	    # VALUTAZIONE LIMITE OSSERVATO
	    elsif (/ObsLimitMode /) {print CONFIGOUT "ObsLimitMode 1\n";} # OBSLIMIT!!!

#limite atteso
#	    elsif (/^ToyOfToyMode/) {print CONFIGOUT "ToyOfToyMode 1\n";} #generate toy-pseudoevents in memory


	    # INPUT FILENAME for PSEUDOEVENTS
	    # elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMC_seed1000_useNuis1_useEffiOverBkgCurve1.root\n";}
# elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_seed2100_useNuis1_useEffiOverBkgCurve0.root\n";}
# elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion1_seed1200_useNuis1_useEffiOverBkgCurve1.root\n";}
# elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_POTErrorScanLevel_seed4100_useNuis1_useEffiOverBkgCurve1.root\n";}
# elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_POTErrorScanLevel_seed5100_useNuis1_useEffiOverBkgCurve1.root\n";}
#	    elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_POTErrorScanLevel_seed7100_useNuis1_useEffiOverBkgCurve1.root\n";} # bkg only
#	    elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_POTErrorScanLevel_seed8100_useNuis1_useEffiOverBkgCurve1.root\n";} # bkg+signal 0.06-MeV spaced mass points, 40 points linear scale in gve in the range 1,8 x 10^-4 
#	    elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_POTErrorScanLevel_seed9200_useNuis1_useEffiOverBkgCurve1.root\n";} # bkg only, 1000 pseudoevents, POT=1E10
#	    elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_POTErrorScanLevel_seed9200_useNuis1_useEffiOverBkgCurve1.root\n";} # bkg only, 1000 pseudoevents, POT=1E10, error on the background down by x10
#	    elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersion2_POTErrorScanLevel_seed9300_useNuis1_useEffiOverBkgCurve1.root\n";} # bkg only, 1000 pseudoevents, POT=1E10, error on the background from the b/pot curve
#	    elsif (/^ErrorImprove/) {print CONFIGOUT "ErrorImprove 10.\n";}

	    # BKG-ONLY PSEUDOEVENTS
	    elsif (/^NumberOfGenerations /) {print CONFIGOUT "NumberOfGenerations 200\n";} 

	    # SIG+BKG PSEUDOEVENTS
#	    elsif (/^BkgOnlyPseudoEvents/) {print CONFIGOUT "BkgOnlyPseudoEvents 0\n";} # read sig+bkg input
#	    elsif (/^WantedMassPseudoEvents/) {print CONFIGOUT "WantedMassPseudoEvents 16.92\n";} # use sig+bkg input
#	    elsif (/^WantedGvePseudoEvents/) {print CONFIGOUT "WantedGvePseudoEvents 0.0007\n";}  # use sig+bkg input

#	    elsif (/^InputFileNameNObsFromFile/) {print CONFIGOUT "InputFileNameNObsFromFile /Users/Tommaso1/PADME/PADME_sensitivity/output/geneToyMCVersionRunIV_seed1400_useNuis1_useEffiOverBkgCurve1.root\n";}
#	    elsif (/^FirstEventNObsFromFile/){print CONFIGOUT "FirstEventNObsFromFile $iStep\n";}
	    elsif (/^ManipulateInput/){print CONFIGOUT "ManipulateInput 0\n";} # to decrease the yield
	    elsif (/^AssumeEffiOverBkgCurve/){print CONFIGOUT "AssumeEffiOverBkgCurve 2\n";}
	    
#	    elsif (/^StraightFitMode/){print CONFIGOUT "StraightFitMode 1\n";}
#	    elsif (/^AssumeBkgOverPotCurve/) {print CONFIGOUT "AssumeBkgOverPotCurve 1\n";} #use bkg/pot curve per scan

	    elsif (/^StraightFitMode/){print CONFIGOUT "StraightFitMode 2\n";}


	    # only assume a P0 on the POT scale
#	    elsif (/^CorrectBkgBias /){print CONFIGOUT "CorrectBkgBias 0\n";}
#	    elsif (/^POTScale /) {print CONFIGOUT "POTScale 1.011\n";} #use scale
#	    elsif (/^POTScaleErr /) {print CONFIGOUT "POTScaleErr 0.0017\n";} #use scale error

	    # assume a Pol1 on the POT scale
	    elsif (/^CorrectBkgBias /){print CONFIGOUT "CorrectBkgBias 1\n";}
	    elsif (/^POTScale /) {print CONFIGOUT "POTScale 1.00\n";} #use scale
	    elsif (/^POTScaleErr /) {print CONFIGOUT "POTScaleErr 0.021\n";} #use scale error

	    elsif (/^BkgBiasObsP0 /){print CONFIGOUT "BkgBiasObsP0 1.01163\n";}
	    elsif (/^BkgBiasObsP1 /){print CONFIGOUT "BkgBiasObsP1 -0.0103\n";}
	    elsif (/^BkgBiasErrP0 /){print CONFIGOUT "BkgBiasErrP0 0.0013\n";}
	    elsif (/^BkgBiasErrP1 /){print CONFIGOUT "BkgBiasErrP1 0.004\n";}
	    elsif (/^BkgBiasErrP0P1Corr /){print CONFIGOUT "BkgBiasErrP0P1Corr -0.06\n";}

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
