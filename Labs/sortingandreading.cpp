#include<fstream>
#include<iostream>
using namespace std;
class SortingStringFilesIgnoringCase {

public: 
    static string toUpperCase(string& str){

        string temp = ""; 
        for (int i = 0; i < str.length(); i++) 
        {
            char c = str.at(i); 

            if (c > 96 && c < 123)
            {
                c -= 32; 
            }
            temp += c; 
        } 
        return temp; 
   }

    static void selectionSort(string* array, int arrayLen) 
    {
        for (int i = 0; i < arrayLen - 1; i++) 
        {
            int minIndex = i; 
            for (int j = i + 1; j < arrayLen; j++) 
            {
                if (toUpperCase(array[j]) < toUpperCase(array[minIndex]))                 
                    minIndex = j;
            }

            if (minIndex != i)
            { 
                string temp = array[i];
                array[i] = array[minIndex];
                array[minIndex] = temp;
            }
        }
    }

    static void readSortWrite()
    {
        ifstream reader("inputStrings.txt", ios::in); 

        int len; 

        reader >> len; 

        string* str = new string[len]; 

        for (int i = 0; i < len; i++)
        {
             reader >> str[i]; 
        }

        reader.close(); 

        selectionSort(str, len);
        ofstream writer("outputStrings.txt", ios::out); 
        writer << len << endl; 

        for (int i = 0; i < len; i++)
        {
           
            writer << str[i] << endl;
        }

        writer.close();       
        delete[] str; 

    }
};

    


int main() {
    string str = "aBb_A_#bZAxcz#%!Cce";

    cout << "Upper-case version of " << str << " is " <<
        SortingStringFilesIgnoringCase::toUpperCase(str);
    SortingStringFilesIgnoringCase::readSortWrite();
}
