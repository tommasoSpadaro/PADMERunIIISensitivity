#!/usr/bin/perl -w

$seedStem = $ARGV[0]; #e.g.: statisticalTest_massSteps_71_massRange_16.22_17.62_UseNuis1
$seedStart = $ARGV[1]; #e.g. 8000
$stemdir = ".";#/Users/Tommaso1/PADME/PADME_sensitivity";
opendir (INPUTDIR, "$stemdir/output") or die "cannot open the output dir\n";
$launched = 0;
while ($filein = readdir(INPUTDIR)){
    if ($filein =~ /^${seedStem}_seed(\d+).root$/){
	$seed = $1;
	if ($seed >= $seedStart && $seed < $seedStart+1000) {
	    open (CONFIG, "${stemdir}/input/config_generic.txt") or die "cannot open config file input/config_generic.txt\n";
	    $configOut = "${stemdir}/input/config_generic_seed_${seed}_readonly.txt";
	    open (CONFIGOUT, ">$configOut") or die "cannot open config file $configOut.txt\n";
	    while (<CONFIG>){
		chomp;
		if (/^ReadMode/) {print CONFIGOUT "ReadMode 1\n";}
		elsif (/^Seed/) {print CONFIGOUT "Seed $seed\n";}
		elsif (/^InputFileName /){print CONFIGOUT "InputFileName $stemdir/output/$filein\n";}
		else         {print CONFIGOUT "$_\n";}
	    }
	    close CONFIGOUT;
	    if ($launched > 0 && ($launched % 20 == 0)) {
		system("sleep 5");
	    }
	    $command = "./bin/runStatisticalTreatment $configOut > logs/runEvent_seed${seed}_read.log &";
	    print "execute $command\n";
	    system($command);
	    $launched++;
	}
    }
}
