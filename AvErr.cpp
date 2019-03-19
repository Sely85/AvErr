//Written by Lara Querciagrossa (2013)

#include <stdio.h>
#include <cstdlib>
#include <memory>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <strstream>
#include <cmath>
#define THIRD 0.333333333333333
#define ROOTTHREE 1.73205080756888       
#define PI 3.141592653589793238462643383279502884197
 
using namespace std;

int main(int argc, char *argv[])
{

  if (argc != 2) 
    {
      std::cout << " " << std::endl;
      std::cout << " Welcome to the AvErr code!" << std::endl;
      std::cout << " AvErr will compute average and standard " << std::endl;
      std::cout << " deviation and error of a single column of data " << std::endl;
      std::cout << " " << std::endl;
      std::cout << " Usage: AvErr <filename> " << std::endl;
      std::cout << " " << std::endl;

      return 0;
    }

  /***************************************  
             Read input file
  ***************************************/
  int num = 0;
  double *val;

  if (string(argv[1]) == "--help")
    {
      std::cout << " " << std::endl;
      std::cout << " Welcome to the AvErr code!" << std::endl;
      std::cout << " AvErr will compute average and standard " << std::endl;
      std::cout << " deviation and error of a single column of data " << std::endl;
      std::cout << " " << std::endl;
      std::cout << " Usage: AvErr <filename> " << std::endl;
      std::cout << " " << std::endl;

      return 0;
    }
  else
    {
      string line;

      ifstream infile ( argv[1]) ;

      if ( !infile.is_open() ){
	cout<<"ERROR: Could not open file\n";
	return 0;
      }

      //find number of lines in file to know how much memory to allocate
      while(!infile.eof()){
	getline(infile,line);
	num++;
      }

      std::cout << "In your file (" << argv[1] << ") there are "<< num-1 << " lines " << std::endl;

      val = new double[num];

      //back to start
      infile.close();    
      infile.open(argv[1]);    

      double min = 1000000.0;
      double max = -1000000.0;

      for (int i=0; i<num; i++)
	{
	  infile >> val[i];
	  //	std::cout << val[i] << std::endl;

	  if (val[i] < min)
	    min = val[i];

	  if (val[i] > max)
	    max = val[i];

	}

      std::cout << "Your minimum value is: " << min << std::endl;
      std::cout << "Your maximum value is: " << max << std::endl;

    }    



  /***************************************  
             Compute average
  ***************************************/

  double sum=0;
  double ave;

  for (int j=0; j<num; j++)
    {
      sum=sum+val[j];
    }

  ave = sum/(num);

  std::cout << " " << std::endl;

  /***************************************  
     Compute std var, std dev, std err
  ***************************************/

  double sumsq=0;
  double stdvar, stddev, stderr;

  for (int k=0; k<num; k++)
    {
      sumsq=sumsq+(val[k]-ave)*(val[k]-ave);
    }

  stdvar = sumsq/(num-1);
  stddev = sqrt(stdvar);
  stderr = stddev/sqrt(num);

  std::cout << "Data average........................ " << ave << std::endl;
  std::cout << "Standard deviation.................. " << stddev << std::endl; 
  std::cout << "Standard variation.................. " << stdvar << std::endl; 
  std::cout << "Standard error...................... " << stderr << std::endl; 

  std::cout << " " << std::endl;

}
