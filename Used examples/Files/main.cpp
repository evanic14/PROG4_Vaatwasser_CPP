#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
   string filename;
   cout << "enter filname" << endl;
   getline(cin,filename);
   cout << "filename: " << filename <<endl;

   ofstream FileOut;
   ifstream FileIn;

   FileOut.open(filename);


   if (FileOut.good())
   {
      int i;
      for(i =0 ;i<9;i++)
         FileOut << "een string " << i << endl;
      FileOut << "een string " << i;
      FileOut.close();
   }
   else
      cout << "Error opening file for writing" << endl;

   string word_een, word_string, getal;
   int a;
   FileIn.open(filename);
   if (FileIn.good())
   {
      while (!FileIn.eof())
      {
         FileIn >> word_een; FileIn >> word_string;
         FileIn >> getal;
         a=stoi(getal);
         cout << a << endl;
      }

      cout << "end of file bereikt" <<endl;
      FileIn.close();
   }
   else
   {
      cout << "error opening file for reading" <<endl;
   }
}
