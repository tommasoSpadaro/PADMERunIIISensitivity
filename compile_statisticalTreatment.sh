clang++ `root-config --cflags` -fPIC -Wall -O3 -g -c statConfig.C -o build/statConfig.o
clang++ `root-config --cflags` -fPIC -Wall -O3 -g -c statisticalTreatmentTH.C -o build/statisticalTreatmentTH.o
clang++ `root-config --cflags` -fPIC -Wall -O3 -g -c statisticalTreatmentTH_main.cc -o build/statisticalTreatmentTH_main.o
clang++ `root-config --cflags` -fPIC -Wall -O3 -g -c statisticalTreatmentTH_read.cc -o build/statisticalTreatmentTH_read.o
clang++ `root-config --cflags` -fPIC -Wall -O3 -g -c statisticalTreatmentTH_gene.cc -o build/statisticalTreatmentTH_gene.o
clang++ -o bin/runStatisticalTreatment build/statisticalTreatmentTH_main.o  build/statConfig.o build/statisticalTreatmentTH.o `root-config --glibs`
clang++ -o bin/readStatisticalTreatment build/statisticalTreatmentTH_read.o build/statConfig.o build/statisticalTreatmentTH.o `root-config --glibs`
clang++ -o bin/geneStatisticalTreatment build/statisticalTreatmentTH_gene.o build/statConfig.o build/statisticalTreatmentTH.o `root-config --glibs`

