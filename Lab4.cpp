#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main() {
   int numBeds;        // count the number of beds
   string strCustInOut;// input string of customer-in and -out
   bool tanning[26];   // An array that notes who is currently in a bed
   bool known[26];     // keep track of whether you have seen a particular alphabet symbol
   int numTanning;     // count of how many people are currently tanning
   int numMisses;      // count how many times of customers left
   
   while (true) {
       // get the number of beds
       numMisses = 0;
       numTanning = 0;
       cin >> numBeds; 
       // if the input is 0 or more than 20, then exit
       if (numBeds == 0 || numBeds > 20) {break;}
       // get the list of customer-in and -out
       cin >> strCustInOut;
       
       for (unsigned int j=0; j<sizeof(known); j++)
       {
          tanning[j] = 0;
          known[j] = 0;
       }
       // Your code
       for (unsigned int i=0; i<strCustInOut.length(); i++) // string to chars
       {
           //int x = (static_cast<int>(strCustInOut[i]) - 'A'); 
           int x = (static_cast<int>(strCustInOut[i]) - 'A');

           if (known[x] != true && numTanning < numBeds) {
              tanning[x] = true;
              known[x] = true;
              numTanning++;
           }
           
           else if (known[x] != true && numTanning == numBeds) {
              known[x] = true;
              tanning[x] = false;
           }
           
           else if (known[x] == true && tanning[x] == true) {
              numTanning--;
              tanning[x] = false;
           }
           
           else if (known[x] == true && tanning[x] == false) {
             numMisses++;
           }
       }
        // print the output
       if (numMisses == 0)
           cout << "All customers tanned successfully." << endl;
       else
           cout << numMisses << " customer(s) walked away." << endl;
   }
   return 0;
}

