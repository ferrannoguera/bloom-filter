#./bin/bash

echo "make"
make
echo "g++ -std=c++11 -o gen_proves100 gen_proves100.cpp"
g++ -std=c++11 -o gen_proves100 gen_proves100.cpp
echo "./gen_proves100 < claus/inp_100pw.txt"
./gen_proves100 < claus/inp_100pw.txt

echo "g++ -std=c++11 -o gen_proves500 gen_proves500.cpp"
g++ -std=c++11 -o gen_proves500 gen_proves500.cpp
echo "./gen_proves500 < claus/inp_500pw.txt"
./gen_proves500 < claus/inp_500pw.txt

echo "g++ -std=c++11 -o gen_proves1000 gen_proves1000.cpp"
g++ -std=c++11 -o gen_proves1000 gen_proves1000.cpp
echo "./gen_proves1000 < claus/inp_1000pw.txt"
./gen_proves1000 < claus/inp_1000pw.txt

echo "g++ -std=c++11 -o gen_proves10000 gen_proves10000.cpp"
g++ -std=c++11 -o gen_proves10000 gen_proves10000.cpp
echo "./gen_proves10000 < claus/inp_10000pw.txt"
./gen_proves10000 < claus/inp_10000pw.txt


echo "./main100 < tests/cent/test0.txt > comparacions/cent/restest0.txt"
./main100 < tests/cent/test0.txt > comparacions/cent/restest0.txt
echo "./main100 < tests/cent/test1.txt > comparacions/cent/restest1.txt"
./main100 < tests/cent/test1.txt > comparacions/cent/restest1.txt
echo "./main100 < tests/cent/test2.txt > comparacions/cent/restest2.txt"
./main100 < tests/cent/test2.txt > comparacions/cent/restest2.txt
echo "./main100 < tests/cent/test3.txt > comparacions/cent/restest3.txt"
./main100 < tests/cent/test3.txt > comparacions/cent/restest3.txt
echo "./main100 < tests/cent/test4.txt > comparacions/cent/restest4.txt"
./main100 < tests/cent/test4.txt > comparacions/cent/restest4.txt
echo "./main100 < tests/cent/test5.txt > comparacions/cent/restest5.txt"
./main100 < tests/cent/test5.txt > comparacions/cent/restest5.txt

echo "./main500 < tests/cinccents/test0.txt > comparacions/cinccents/restest0.txt"
./main500 < tests/cinccents/test0.txt > comparacions/cinccents/restest0.txt
echo "./main500 < tests/cinccents/test1.txt > comparacions/cinccents/restest1.txt"
./main500 < tests/cinccents/test1.txt > comparacions/cinccents/restest1.txt
echo "./main500 < tests/cinccents/test2.txt > comparacions/cinccents/restest2.txt"
./main500 < tests/cinccents/test2.txt > comparacions/cinccents/restest2.txt
echo "./main500 < tests/cinccents/test3.txt > comparacions/cinccents/restest3.txt"
./main500 < tests/cinccents/test3.txt > comparacions/cinccents/restest3.txt
echo "./main500 < tests/cinccents/test4.txt > comparacions/cinccents/restest4.txt"
./main500 < tests/cinccents/test4.txt > comparacions/cinccents/restest4.txt
echo "./main500 < tests/cinccents/test5.txt > comparacions/cinccents/restest5.txt"
./main500 < tests/cinccents/test5.txt > comparacions/cinccents/restest5.txt

echo "./main1000 < tests/mil/test0.txt > comparacions/mil/restest0.txt"
./main1000 < tests/mil/test0.txt > comparacions/mil/restest0.txt
echo "./main1000 < tests/mil/test1.txt > comparacions/mil/restest1.txt"
./main1000 < tests/mil/test1.txt > comparacions/mil/restest1.txt
echo "./main1000 < tests/mil/test2.txt > comparacions/mil/restest2.txt"
./main1000 < tests/mil/test2.txt > comparacions/mil/restest2.txt
echo "./main1000 < tests/mil/test3.txt > comparacions/mil/restest3.txt"
./main1000 < tests/mil/test3.txt > comparacions/mil/restest3.txt
echo "./main1000 < tests/mil/test4.txt > comparacions/mil/restest4.txt"
./main1000 < tests/mil/test4.txt > comparacions/mil/restest4.txt
echo "./main1000 < tests/mil/test5.txt > comparacions/mil/restest5.txt"
./main1000 < tests/mil/test5.txt > comparacions/mil/restest5.txt

echo "./main10000 < tests/deumil/test0.txt > comparacions/deumil/restest0.txt"
./main10000 < tests/deumil/test0.txt > comparacions/deumil/restest0.txt
echo "./main10000 < tests/deumil/test1.txt > comparacions/deumil/restest1.txt"
./main10000 < tests/deumil/test1.txt > comparacions/deumil/restest1.txt
echo "./main10000 < tests/deumil/test2.txt > comparacions/deumil/restest2.txt"
./main10000 < tests/deumil/test2.txt > comparacions/deumil/restest2.txt
echo "./main10000 < tests/deumil/test3.txt > comparacions/deumil/restest3.txt"
./main10000 < tests/deumil/test3.txt > comparacions/deumil/restest3.txt
echo "./main10000 < tests/deumil/test4.txt > comparacions/deumil/restest4.txt"
./main10000 < tests/deumil/test4.txt > comparacions/deumil/restest4.txt
echo "./main10000 < tests/deumil/test5.txt > comparacions/deumil/restest5.txt"
./main10000 < tests/deumil/test5.txt > comparacions/deumil/restest5.txt





