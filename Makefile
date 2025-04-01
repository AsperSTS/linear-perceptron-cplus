all:
	g++ -std=c++2b main.cpp Vector.cpp Matrix.cpp  -o linearPerceptron	
run:
	./linearPerceptron