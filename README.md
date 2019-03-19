AvErr
=====

Welcome to the AvErr code!

AvErr will compute average and standard deviation and error of a single column of data. 
 
Usage: AvErr <filename> 


BUILD (Linux)
-------------
g++ -lm AvErr.cpp -o AvErr


USAGE
-----
./AvErr <inputfile> 
 
This code will compute:
- minimum and maximum values contained in your <inputfile>
- the average value of data contained in your <inputfile>
- standard deviation of data  
- standard variation of data --> (std dev)^2
- standard error of data --> (std dev)/sqrt(N)



EXAMPLE
-------
Execute:
	./AvErr data.txt

Output:
In your file (data.txt) there are 2609 lines 
Your minimum value is: -39.7367
Your maximum value is: 44.8657
 
Data average........................ 4.07556
Standard deviation.................. 20.7332
Standard variation.................. 429.868
Standard error...................... 0.405833
