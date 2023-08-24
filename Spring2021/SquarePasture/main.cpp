#include <fstream>
using namespace std;
int main() {
  ifstream fin ("square.in");
  ofstream fout ("square.out");
  int smallestX = 10;
	int largestX = 0;
	int smallestY = 10;
	int largestY = 0;

		// read in two lines, store corners of the pastures
		for(int i = 0; i < 2; i++) {
			int xLow;
			int yLow;
			int xHigh;
			int yHigh;
			fin >> xLow >> yLow >> xHigh >> yHigh; 
			if(xLow < smallestX) {
				smallestX = xLow;
			}
			if(xHigh > largestX) {
				largestX = xHigh;
			}
			if(yLow < smallestY) {
				smallestY = yLow;
			}
			if(yHigh > largestY) {
				largestY = yHigh;
			}
		}
		
		// compute the desired side length of the square
		int desiredSideLength = largestX - smallestX;
		if(largestY - smallestY > largestX - smallestX) {
			desiredSideLength = largestY - smallestY; 
		}
		fout << desiredSideLength * desiredSideLength; 
}