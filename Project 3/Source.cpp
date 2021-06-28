/*
* Vincent Del Vecchio
* 
* File - Source.cpp
* 
*/
#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#undef max
using namespace std;

/*
Description:
   To call this function, simply pass the function name in Python that you wish to call.
Example:
   callProcedure("printsomething");
Output:
   Python will print on the screen: Hello from python!
Return:
   None
*/
void CallProcedure(string pName)
{
   char* procname = new char[pName.length() + 1];
   std::strcpy(procname, pName.c_str());

   Py_Initialize();
   PyObject* my_module = PyImport_ImportModule("CS210_Starter_PY_Code");
   PyErr_Print();
   PyObject* my_function = PyObject_GetAttrString(my_module, procname);
   PyObject* my_result = PyObject_CallObject(my_function, NULL);
   Py_Finalize();

   delete[] procname;
}

/*
Description:
   To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
   int x = callIntFunc("PrintMe","Test");
Output:
   Python will print on the screen:
      You sent me: Test
Return:
   100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
   char* procname = new char[proc.length() + 1];
   std::strcpy(procname, proc.c_str());

   char* paramval = new char[param.length() + 1];
   std::strcpy(paramval, param.c_str());


   PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
   // Initialize the Python Interpreter
   Py_Initialize();
   // Build the name object
   pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code");
   // Load the module object
   pModule = PyImport_Import(pName);
   // pDict is a borrowed reference 
   pDict = PyModule_GetDict(pModule);
   // pFunc is also a borrowed reference 
   pFunc = PyDict_GetItemString(pDict, procname);
   if (PyCallable_Check(pFunc))
   {
      pValue = Py_BuildValue("(z)", paramval);
      PyErr_Print();
      presult = PyObject_CallObject(pFunc, pValue);
      PyErr_Print();
   }
   else
   {
      PyErr_Print();
   }
   //printf("Result is %d\n", _PyLong_AsInt(presult));
   Py_DECREF(pValue);
   // Clean up
   Py_DECREF(pModule);
   Py_DECREF(pName);
   // Finish the Python Interpreter
   Py_Finalize();

   // clean 
   delete[] procname;
   delete[] paramval;


   return _PyLong_AsInt(presult);
}

/*
Description:
   To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
   int x = callIntFunc("doublevalue",5);
Return:
   25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
   char* procname = new char[proc.length() + 1];
   std::strcpy(procname, proc.c_str());

   PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
   // Initialize the Python Interpreter
   Py_Initialize();
   // Build the name object
   pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code");
   // Load the module object
   pModule = PyImport_Import(pName);
   // pDict is a borrowed reference 
   pDict = PyModule_GetDict(pModule);
   // pFunc is also a borrowed reference 
   pFunc = PyDict_GetItemString(pDict, procname);
   if (PyCallable_Check(pFunc))
   {
      pValue = Py_BuildValue("(i)", param);
      PyErr_Print();
      presult = PyObject_CallObject(pFunc, pValue);
      PyErr_Print();
   }
   else
   {
      PyErr_Print();
   }
   //printf("Result is %d\n", _PyLong_AsInt(presult));
   Py_DECREF(pValue);
   // Clean up
   Py_DECREF(pModule);
   Py_DECREF(pName);
   // Finish the Python Interpreter
   Py_Finalize();

   // clean 
   delete[] procname;

   return _PyLong_AsInt(presult);
}

/*
Description:
   Opens a .dat file titled frequency containing a list of each item and it's frequency on a single line (ex Apples 5)
   Then prints a historgram of the frequency data using the information from the file
Example: 
   printFrequencyList();
Output:
   A histogram of the data contained in the frequency.dat file
Return:
   None
*/
void printFrequencyList() {
   ifstream frequencyFile; // Create inputfile stream to open file with

   try {
      frequencyFile.open("frequency.dat"); // Opens file titled frequency.dat
      string str; // string to hold info pulled from file
      frequencyFile >> str; // Grab first string from file
      
      std::cout << "\nFrequency Histogram:" << endl; // Print Histogram header

      while (!frequencyFile.eof()) { // Loop until end of file
         std::cout << str << ": "; // Prints out Item name
         frequencyFile >> str; // Gets items frequency 
         for (int i = 0; i < stoi(str); ++i) { // We must convert the frequency to an interger with stoi() since it is receieved as a str.
            std::cout << "*"; // Prints a visual representation of the frequency as many times as the item occurs on the list
         }
         std::cout << endl; // Print a new line for the next item
         frequencyFile >> str; // Read in next item from file
      }
   }
   catch (exception e) { // Catch and print exception message if one occurs
      std::cout << e.what();
   }

   frequencyFile.close(); // Close file

}

int main()
{
   int userInput = 0;
   string userItem = "";

   // Loop Menu and user input capture until user inputs 4
   do {
      std::cout << "1: Produce a list of all items purchased in a given day along with the number of times each item was purchased." << endl <<
         "2: Produce a number representing how many times a specific item was purchased in a given day." << endl <<
         "3: Produce a text-based histogram listing all items purchased in a given day, along with a representation of the number of times each item was purchased." << endl <<
         "4: Exit" << endl <<
         "Enter your selection as a number 1, 2,  3, or 4." << endl;

      cin >> userInput;
      if (cin.fail()) { // If user input does not match expected type cin.fail is true
         userInput = 0; // Set user input to 0 triggering error message in switch statement below
         cin.clear(); // Clear cin failbit
         cin.ignore(std::numeric_limits<int>::max(), '\n'); // Clear buffer to prepare for next user input
      }
      // Performs the operation requested by the user
      switch (userInput) {
      case 1: // Calls python function that produces a list of all items purchased in a given day along with the number of times each item was purchased
         CallProcedure("PrintAllItems");
         break;
      case 2: // Calls python function that returns the frequency of a word input by the user and then prints it to the screen
         std::cout << "Which Item would you like to obtain the frequency for?" << endl;
         cin >> userItem;
         std::cout << "\nFrequency of " << userItem << ": " << callIntFunc("getItemFrequency", userItem) << endl;
         break;
      case 3: // Calls Python function to create a frequency.dat file containing the list of items and their frequencies, then calls a method to read from that file and print a histogram representation of it
         CallProcedure("createFrequencyFile");
         printFrequencyList();
         break;
      case 4: // Prints Exit message and breaks menu loop to allow program to end  
         std::cout << "\nNow Exiting" << endl;
         break;
      default: // User input is invalid option and prints error message
         std::cout << "Please enter a valid selection." << endl;
         break;
      }

      std::cout << endl;
   } while (userInput != 4);
}
