all:
	g++ -std=c++2b src/main.cpp src/Utils.cpp -o build/linearPerceptron
	./linearPerceptron 	
run:
	./build/linearPerceptron

eigen:
	g++ -std=c++2b -I eigen-3.4.0 main.cpp Utils.cpp -o linearPerceptron
	./linearPerceptron 	
buildTest:
	g++ -std=c++2b -I eigen-3.4.0 test.cpp -o test
	./test