/**
*	@file : sortdriver.cpp
*	@author: Luke Dercher
*	@date: 2015.04.05
*	@purpose: sortdriver implementation file. Sortdriver checks whether a valid file passed in to sort and creates an array filled with those values in that file.
*/

#include "sortdriver.h"

void SortDriver::run(int argc, char** argv)
{
    std::string sort = argv[2];

    std::string fileName = argv[3];


    if (areParametersValid(sort, fileName))
    {
        std::ifstream fileIn;

        fileIn.open(fileName);

        if (!fileIn)
        {
            std::cout<<"not correct ";
        }

        int size = getFileCount(fileIn);

        int* arr = createArray(fileIn, size);

        double time;

        std::cout<<"Calculating sort timing information.... \n\n";

        std::string outFile = argv[4];

        std::ofstream out;

        out.open(outFile);

        if (sort == "-bubble")
        {
            fileIn.close();

            time = Sorts<int>::sortTimer(Sorts<int>::bubbleSort,arr, size);

            out<<"Bubble Sort sorted "<< size << " numbers in "<< time <<" seconds";

            out.close();

        }
        else if (sort == "-selection")
        {
            fileIn.close();

            time = Sorts<int>::sortTimer(Sorts<int>::selectionSort, arr, size);

            out<<"Selection Sort sorted "<< size << " numbers in "<< time <<" seconds";

            out.close();
        }
        else if(sort == "-insertion")
        {
            fileIn.close();

            time = Sorts<int>::sortTimer(Sorts<int>::insertionSort, arr, size);

            out<<"Insertion Sort sorted "<< size << " numbers in "<< time <<" seconds";

            out.close();
        }
        else if(sort == "-quick")
        {
            fileIn.close();

            time = Sorts<int>::sortTimer(Sorts<int>::quickSort, arr, size);

            out<<"Quick Sort sorted "<< size << " numbers in "<< time <<" seconds";

            out.close();
        }
        else if(sort == "-quick3")
        {
            fileIn.close();

            time = Sorts<int>::sortTimer(Sorts<int>::quickSortMedian, arr, size);

            out<<"Quick Sort (with median) sorted "<< size << " numbers in "<< time <<" seconds";

            out.close();
        }
        else if (sort == "merge")
        {
            fileIn.close();

            time = Sorts<int>::sortTimer(Sorts<int>::mergeSort, arr, size);

            out<<"Merge Sort sorted "<< size << " numbers in "<< time <<" seconds";

            out.close();
        }
        else if (sort == "-all")
        {
            double time1, time2, time3, time4, time5, time6;

            fileIn.close();

            int copy1[size];

            SortDriver::copyArray(arr, copy1, size);

            int copy2[size];

            SortDriver::copyArray(arr, copy2, size);

            int copy3[size];

            SortDriver::copyArray(arr, copy3, size);

            int copy4[size];

            SortDriver::copyArray(arr, copy4, size);

            int copy5[size];

            SortDriver::copyArray(arr, copy5, size);


            time1 = Sorts<int>::sortTimer(Sorts<int>::bubbleSort,arr, size);



            time2 = Sorts<int>::sortTimer(Sorts<int>::selectionSort, copy1, size);



            time3 = Sorts<int>::sortTimer(Sorts<int>::insertionSort, copy2, size);



            time4 = Sorts<int>::sortTimer(Sorts<int>::quickSort, copy3, size);



            time5 = Sorts<int>::sortTimer(Sorts<int>::quickSortMedian, copy4, size);



            time6 = Sorts<int>::sortTimer(Sorts<int>::mergeSort, copy5, size);

            out<<"Bubble Sort sorted "<< size << " numbers in "<< time1 <<" seconds\n\n";

            out<<"Selection Sort sorted "<< size << " numbers in "<< time2 <<" seconds\n\n";

            out<<"Insertion Sort sorted "<< size << " numbers in "<< time3 <<" seconds\n\n";

            out<<"Quick Sort sorted "<< size << " numbers in "<< time4 <<" seconds\n\n";

            out<<"Quick Sort (with median) sorted "<< size << " numbers in "<< time5 <<" seconds\n\n";

            out<<"Merge Sort sorted "<< size << " numbers in "<< time6 <<" seconds";

            out.close();

        }

        std::cout<<"Calculations finished. Results stored in "<< outFile << "\n\n";

        std::cout<<"Exiting...";

        out.close();
	delete[] arr;
    }
    else
    {
           printHelpMenu();
    }

}


void SortDriver::printHelpMenu()
{
    std::cout << "\nSorting is done one of the following ways:\n\n"
            << "./prog -sort -bubble inputFile outputFile\n"
            << "./prog -sort -selection inputFile outputFile\n"
            << "./prog -sort -insertion inputFile outputFile\n"
            << "./prog -sort -quick inputFile outputFile\n"
            << "./prog -sort -quick3 inputFile outputFile\n"
            << "./prog -sort -merge inputFile outputFile\n"
            << "./prog -sort -all inputFile outputFile\n"
            << "Option explainations:\n"
            << "\t-bubble to time bubble sort and store all timing results in outputFile\n"
            << "\t-selection to time selection sort and store all timing results in outputFile\n"
            << "\t-insertion to time insertion sort and store all timing results in outputFile\n"
            << "\t-quick to time quick sort and store all timing results in outputFile\n"
            << "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
            << "\t-merge to time merge sort  and store all timing results in outputFile\n"
            << "\t-all to time all of the sorts and store all timing results in outputFile\n"
            << "\tinputFile must be file created by a NumberFileGenerator\n"
            << "\toutputFile must be to a valid path. It will hold the timing results\n";

}

bool SortDriver::isFileAccessible(std::string fileName)
{
    std::ifstream inputfile (fileName);

    if (inputfile.good())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool SortDriver::isSortValid(std::string sortParameter)
{
    if (sortParameter == "-bubble"  || sortParameter == "-selection" || sortParameter == "-insertion" || sortParameter == "-quick" || sortParameter == "-quick3" || sortParameter == "-merge" || sortParameter == "-all")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName)
{
    if (isFileAccessible(inputFileName) && isSortValid(sortName))
    {
        return true;
    }
    else
    {
        return false;
    }

}

int SortDriver::getFileCount(std::ifstream& inputFile)
{
    std::string FileCount;

    inputFile >> FileCount;

    return stoi(FileCount);
}

int* SortDriver::createArray(std::ifstream& inputFile, int size)
{
    int* arr = new int[size];

    int i = 0;

    for(i = 0; i < size; i++)
    {
        inputFile>> arr[i];
	if(inputFile.eof())
	  i = size;
    }

    return arr;
}

void SortDriver::copyArray(int original[], int copy[], int size)
{
    for (int i=0; i<size; i++)
    {
        copy[i]= original[i];
    }
}
