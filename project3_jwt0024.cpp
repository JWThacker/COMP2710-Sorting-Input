/*
   Author: Jared Thacker
   AU ID: jwt0024
   Filename: project3_jwt0024.cpp
   Compilation instructions: g++ project3_jwt0024.cpp -o project3_jwt0024.out
   Help: Murach's C++ Programming, class notes, my project2 for unit testing
*/
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <assert.h>
using namespace std;

const int MAX_SIZE = 100;
//Declare function prototypes
int readfile(int inputArray[], ifstream& instream);
int sort(int iArray1[], int iArray1_size, int iArray2[],int iArray2_size, int oArray[]);
void writefile(int outputArray[],int outputArray_size,string outputFileName);
void test_readfile(void);
void test_sort(void);
void test_writefile(void);

int main(){
   //Declare ifstream object, inStream
   ifstream inStream;
   
   //Declare the arrays and other variables that will be needed for the execution of
   //of this project
   int iArray1[MAX_SIZE];
   int iArray1_size;
   int iArray2[MAX_SIZE];
   int iArray2_size;
   int outputArray[MAX_SIZE];
   int outputArray_size;
   int i;
   string filename,outputFileName;

   //Establish the beginning of the interface and receive the input file
   //name from the user 
   cout << "***Welcome to Jared's sorting program**" << endl; 
   cout << "Enter the first input file name:" << endl; 
   cin >> filename;
   
   //Open the first file from the user
   inStream.open((char*)filename.c_str());
   
   //Test if the first file cannot be opened, then alert
   //the user and terminate the program 
   if(inStream.fail()){
      cout << "Input file opening has failed. \n";
      exit(EXIT_FAILURE);
   }

   //Read the first file provided by the user and output
   //the contents to the terminal. Lastly close the 
   //the file
   iArray1_size = readfile(iArray1,inStream);
   cout << "The list of " << iArray1_size << " numbers in file " << filename << " is:"<< endl;
   for(i=0;i<iArray1_size;i++){
      cout << iArray1[i] << endl;
   }
   cout << endl;
   inStream.close();

   //Receive the second file from the user and test to 
   //and open it
   cout << "Enter the second input file name:" << endl; 
   cin >> filename;
   inStream.open((char*)filename.c_str());

   //Test if the second file cannot be opened, then alert
   //the user and terminate the program 
   if(inStream.fail()){
      cout << "Input file opening has failed. \n";
      exit(EXIT_FAILURE);
   }

   //Read the second file provided by the user and output
   //the contents to the terminal. Lastly, close the file.
   iArray2_size = readfile(iArray2,inStream);
   cout << "The list of " << iArray2_size << " numbers in file " << filename << " is:"<< endl;
   for(i=0;i<iArray2_size;i++){
      cout << iArray2[i] << endl;
   }
   cout << endl;
   inStream.close();

   //Call the sort function. This function sorts the contents of both input files
   //and ouputs the order list to a new array, outputArray
   outputArray_size = sort(iArray1,iArray1_size,iArray2,iArray2_size,outputArray);

   //Print the sorted contents to the terminal
   cout << "The sorted list of " << outputArray_size << " numbers is: ";
   for (int i = 0; i < outputArray_size; i++) {
      cout << outputArray[i] << " ";
   }
   cout << endl;

   //Prompt the user to provide the name of the output file
   //that the shallarray should be written to
   cout << "Enter the ouput file name:" << endl;
   cin >> outputFileName;
   writefile(outputArray,outputArray_size,outputFileName);
   cout << "***Please check the new file - " << outputFileName << "***" <<  endl;
   cout << "***Goodbye***" << endl;

   //The remainder of the main() function executes unit tests on the readfile()
   //sort(), and writefile() functions
   test_readfile();
   test_sort(); 
   test_writefile(); 
   return 0;

}

/*
   Function: readfile()
   Purpose: To read the ifstream and store it to an array, inputArrayp[]
   Inputs: inputArray[] - The array that the contents of inStream shall
                          be stored in
           inStream - The ifstream object which shall have its contents
                      extracted and saved to an array
*/
int readfile(int inputArray[], ifstream& inStream){
   int index=0; //The counter that represents the index of inputArray
   
   inStream >> inputArray[index];
   //While the end-of-file has not been reached, extract and store
   //the contents of the ifstream to the array
   while (! inStream.eof()){
      //If the index of the array has reach above 100, then
      //the file is too large and return -1 from the function 
      if(index > 100){
         cout << "File is too large for the I/O"<< endl;
         return -1;
      }
      //If the ifstream fails to open, then return -1 from the function
      if(inStream.fail()){
         return -1;
      }
         //other iterate the index of the array and store it in inputArray
         index++;
         inStream >> inputArray[index];
      }
      return index;
   }


/*
   Function: sort
   Inputs: iArray1[] - The first array consisting of the contents from input1.txt
           iArray2[] - The first array consisting of the contents from input2.txt
           iArray1_size - The size of iArray1[]
           iArray2_size - The size of iArray2[]
           oArray - The array to be returned/outputted from the sort() function
   Outputs: sizeOfOutputArray - The size of the output array
*/
int sort(int iArray1[], int iArray1_size, int iArray2[],int iArray2_size, int oArray[]){
	bool sortCompleted = false; 
	int i=0,j=0,sizeOfOutputArray=0; 
   //While loop that executes as long as the sorting process is processing
   while(!sortCompleted){
      //If we are within the bounds of both the input arrays, then compare and place values
      //in the output array
      if(i < iArray1_size && j < iArray2_size){
         //If the element of array1 is smaller than the element of array2 
         //place the element of array1 into the output array
         if(iArray1[i] < iArray2[j]){
	       oArray[sizeOfOutputArray]=iArray1[i];
	       i++;
	    }
            //If the element of array2 is smaller than the element of array2 
            //place the element of array2 into the output array
	    else if(iArray1[i] > iArray2[j]) {
		     oArray[sizeOfOutputArray] = iArray2[j];
	       j++;
	    }
            //If the elements of both arrays are equivalent, place them
            //both into the array
	    else{
		  oArray[sizeOfOutputArray] = iArray1[i];
		  oArray[sizeOfOutputArray+1] = iArray1[i];
                  sizeOfOutputArray++;
	       i++;
	       j++;
	    }
      }
      //if we are still in the range of the array1, print the 
      //the remainder of the elements of array1 into the output
      //array
      else if(i < iArray1_size){
	    oArray[sizeOfOutputArray] = iArray1[i];
	    i++;
      }
      //if we are still in the range of the array2, print the 
      //the remainder of the elements of array2 into the output
      //array
      else if(j < iArray2_size){
	    oArray[sizeOfOutputArray] = iArray2[j];
          j++;
      }
      else{
	 sortCompleted = true;
	 return sizeOfOutputArray;
      }
      sizeOfOutputArray++;
   }
	return -1;
}

/*
   Function: writefile
   Purpose: To the write the sorted contents to a .txt file
   Inputs: outputArray[] - the array whose contents shall be stored
                           in the .txt file
           outputFileName - the name of the output file provided by the
                            user
   Outputs: NONE
*/
void writefile(int outputArray[],int outputArray_size,string outputFileName){
   //Declare the ofstream object
   ofstream outputStream;

   //Declare the index of the outputArray
   int i; 

   //open the ouput .txt file and if it cannot be opened
   //alert the user
   outputStream.open((char*)outputFileName.c_str());
   if(outputStream.fail()){
      cout << "Unable to open/write to the file" << endl;
   }
   else{ //Otherwise write the contents of the output array to the .txt file
      for(i=0;i<outputArray_size;i++){
         outputStream << outputArray[i] << endl;

      }
   }   
   outputStream.close(); //close the .txt file

}

/*
   Function: test_readfile()
   Purpose: to provide unit testing for the readfile() function
   Inputs: NONE
   Outputs: NONE
*/
void test_readfile(void){

   ifstream inStream;
   int inputArray[MAX_SIZE];
   int inputArray_size;

   //Case 1: Nonexistent input file
   inStream.open("notReal.txt");
   inputArray_size = readfile(inputArray,inStream);
   assert(-1 == inputArray_size);
   
   //Case 2: Contents of input file greater than MAX_SIZE
   inStream.open("moreThanMaxSize.txt");
   inStream.close();
   assert(-1 == inputArray_size);

   //Case 3: Read input1.txt
   inStream.open("input1.txt");
   inputArray_size = readfile(inputArray,inStream);
   inStream.close();
   assert(6 == inputArray_size);
   assert(4 == inputArray[0]);
   assert(13 == inputArray[1]);
   assert(14 == inputArray[2]);
   assert(17 == inputArray[3]);
   assert(23 == inputArray[4]);
   assert(89 == inputArray[5]);

   //Case 4: Read input2.txt
   inStream.open("input2.txt");
   inputArray_size = readfile(inputArray,inStream);
   inStream.close();
   assert(5 == inputArray_size);
   assert(3 == inputArray[0]);
   assert(7 == inputArray[1]);
   assert(9 == inputArray[2]);
   assert(14 == inputArray[3]);
   assert(15 == inputArray[4]);
}

/*
   Function: test_sort()
   Purpose: to test the sort() function
   Inputs: NONE
   Outputs: NONE
*/
void test_sort(void){
   int array1[MAX_SIZE] = {4,13,14,17,23,89};
   int array2[MAX_SIZE] = {3,7,9,14,15};

   int array1_size = 6;
   int array2_size = 5;
   int outputArray[MAX_SIZE];
   int outputArray_size;

   //Case 1: Test input1.txt and input2.txt
   outputArray_size = sort(array1,array1_size,array2,array2_size,outputArray);
   assert(11 == outputArray_size);
   assert(3 == outputArray[0]);
   assert(4 == outputArray[1]);
   assert(7 == outputArray[2]);
   assert(9 == outputArray[3]);
   assert(13 == outputArray[4]);
   assert(14 == outputArray[5]);
   assert(14 == outputArray[6]);
   assert(15 == outputArray[7]);
   assert(17 == outputArray[8]);
   assert(23 == outputArray[9]);
   assert(89 == outputArray[10]);
   
   
   //Case 2: Identical input arrays
   int array3[MAX_SIZE] = {4,13,14,17,23,89};
   int array4[MAX_SIZE] = {4,13,14,17,23,89};
   int array3_size = 6;
   int array4_size = 6;
   outputArray_size = sort(array3,array3_size,array4,array4_size,outputArray);
   assert(12 == outputArray_size); 
   assert(4 == outputArray[0]);
   assert(4 == outputArray[1]);
   assert(13 == outputArray[2]);
   assert(13 == outputArray[3]);
   assert(14 == outputArray[4]);
   assert(14 == outputArray[5]);
   assert(17 == outputArray[6]);
   assert(17 == outputArray[7]);
   assert(23 == outputArray[8]);
   assert(23 == outputArray[9]);
   assert(89 == outputArray[10]);
   assert(89 == outputArray[11]);

   //Case 3: Negative numbers introduced
   int array5[MAX_SIZE] = {-4,-3,-1,5,6,10};
   int array6[MAX_SIZE] = {0,1,6,9};
   int array5_size = 6;
   int array6_size = 4;
   outputArray_size = sort(array5,array5_size,array6,array6_size,outputArray);
   assert(10 == outputArray_size);
   assert(-4 == outputArray[0]);
   assert(-3 == outputArray[1]);
   assert(-1 == outputArray[2]);
   assert(0 == outputArray[3]);
   assert(1 == outputArray[4]);
   assert(5 == outputArray[5]);
   assert(6 == outputArray[6]);
   assert(6 == outputArray[7]);
   assert(9 == outputArray[8]);
   assert(10 == outputArray[9]);
}

/*
   Function: test_writefile()
   Purpose: to test the writefile() function
   Inputs: NONE
   Outputs: NONE
*/
void test_writefile(void){
   int outputArray[MAX_SIZE] = {3,4,7,9,13,14,14,15,17,23,89},testArray[MAX_SIZE]; 
   int outputArray_size = 11,i=0;
   //string testFileName  = "test_writefile.txt";
   ifstream inStream;

   //Write the contents of outputArray to test_writefile.txt
   //and verify that contents of test_writefile.txt are correct
   writefile(outputArray,outputArray_size,"test_writefile.txt");
   inStream.open("test_writefile.txt");
   inStream >> testArray[i];
   while(!inStream.eof()){
      i++;
      inStream >> testArray[i];
   }
   inStream.close();
   //User assert() to verify the contents of the array
   assert(3 == testArray[0]);
   assert(4 == testArray[1]);
   assert(7 == testArray[2]);
   assert(9 == testArray[3]);
   assert(13 == testArray[4]);
   assert(14 == testArray[5]);
   assert(14 == testArray[6]);
   assert(15 == testArray[7]);
   assert(17 == testArray[8]);
   assert(23 == testArray[9]);
   assert(89 == testArray[10]);

}
