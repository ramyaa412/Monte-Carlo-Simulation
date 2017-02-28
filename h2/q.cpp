	//  Homework No.2
	//  main.cpp
	//  Monte-Carlo
	//  NETID: st683
	//  Created by Sanjeevi Thirumurugesan on 9/16/15.
	//  Program to estimate the value of Pi using Monte-Carlo method

#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
	int main()
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
	std::cout << "Enter the number of iterations \n";
	std::cin >> N;

	//Opeining the file
	std::ofstream myfile;
	myfile.open("Coordinates.txt");

	//Starting iterations
	for (i = 0; i<N; i++)
	{

		// generating random numbers for the two coordinates with four decimal spaces
		xaxis = rand() % (100000 - 0) / 100000.0;
		yaxis = rand() % (100000 - 0) / 100000.0;


		//std::cout<<"\nX: "<<xaxis<<"\nY: "<<yaxis;

		//Storing the points in file
		myfile << "X:" << xaxis << "\tY:" << yaxis << "\n";

		//Calculating the distance from centre to the random coordinates
		d = sqrt((double)(xaxis*xaxis) + (yaxis*yaxis));

		//Radius of the circle is 1 and center is (0,0)
		//Therefore the points that lie within the first quadrant of the circle can be identified using the formula and stored in 'd'

		//Counting the points that lie within the arc/circle
		if (d <= 1)
			incount++;
	}

	//Closing the file
	myfile.close();


	std::cout << "\nThe Coordinates are saved to the file.";

	//Calculating the value of pi using the formula given
	pi = 4 * (double)(incount / N);

	//Printing the estimated value of pi
	std::cout << "\nThe estimated value of pi for " << N << " iterations is " << pi;

	return 0;

}
