/* NAME : Ramyaa Parthasarathy
   Monte-Carlo
  Program to estimate the value of Pi using Monte-Carlo method
  Subject: Programming Finance
*/
#include<iostream>
#include<fstream>
#include<time.h>
#include<math.h>
#include<iomanip>
using namespace std;
void main()
{
	srand(unsigned(time(NULL)));  //seed value for generating random numbers
	double xaxis;                  //xaxis random variable
	double yaxis;                  //yaxis random variable
	double d;                      //distance from centre of the circle (0,0)
	double pi;                     //Estimated value of Pi
	double incount=0;                //Number of points within the arc
	int i;                         //for loop iteration variable
	int N;                         //Total number of iterations

								   //Getting the number of iterations from user
	cout << "\nEnter the number of iterations \n";
	cin >> N;

	//Opening the file
	ofstream myfile;
	myfile.open("monte.txt");

	//Starting iterations
	for (i = 0; i<N; i++)
	{

		// generating random numbers for the two coordinates 
		xaxis = (double)rand() / (double)RAND_MAX;
		yaxis = (double)rand() / (double)RAND_MAX;


		//Storing the points in file
		myfile << "X:" << xaxis << "\tY:" << yaxis << "\n";

		//Calculating the distance from centre to the random coordinates
		d = sqrt ((xaxis*xaxis) + (yaxis*yaxis));

		//Radius of the circle is 1 and center is (0,0)
		//Therefore the points that lie within the first quadrant of the circle can be identified using the formula and stored in 'd'

		//Counting the points that lie within the arc/circle
		if (d <= 1)
			incount++;
		
			
	}

	//Closing the file
	myfile.close();


	cout << "\nThe Coordinates are saved to the file.";

	//Calculating the value of pi using the formula given
	pi = 4.0000 * ((double)incount / N);

	//Printing the estimated value of pi
	cout << "\n\nThe estimated value of pi for " << N << " iterations is " <<pi<<endl;

	

}