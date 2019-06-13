/**
*issouf kindo
*this program simulates rain 
*/
#include <iostream>
#include <windows.h>

using namespace std;

void Get_inputs (double&  rainFallRate,double& hourOfRain );
void Simulations(double floodPlain[][18],int arrayRowNumber,double rainFallRate,double hourOfRain,double& RainFall,double drainingRate,double& Drainage,double& hours);
void display(double floodPlain[][18],int arrayRowNumber,double RainFall,double hours);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


int main()
{

int arrayRowNumber=18;

double floodPlain[arrayRowNumber][18] ={
 { 12, 13, 14, 15, 16, 16, 16, 17, 17, 18, 18, 19, 20, 20, 20, 19, 18, 18 },
 { 12, 12, 13, 14, 15, 16, 14, 15, 15, 16, 18, 19, 20, 20, 20, 19, 17, 16 },
 { 11, 11, 12, 13, 14, 15, 14, 13, 13, 14, 16, 19, 20, 20, 20, 19, 17, 16 },
 { 10, 10, 11, 12, 13, 14, 12, 10, 11, 11, 11, 12, 18, 14, 12, 12, 15, 16 },
 { 10, 10, 10, 11, 12, 11, 10, 8, 9, 8, 7, 11, 14, 12, 12, 12, 14, 15 },
 { 9, 10, 10, 11, 11, 12, 8, 6, 6, 5, 5, 8, 12, 12, 11, 12, 14, 15 },
 { 8, 10, 10, 10, 10, 8, 6, 5, 5, 5, 6, 10, 10, 10, 11, 13, 13, 15 },
 { 7, 7, 7, 6, 5, 4, 4, 4, 5, 6, 7, 10, 10, 10, 10, 13, 14, 16 },
 { 6, 6, 5, 5, 4, 3, 3, 4, 5, 6, 8, 10, 10, 10, 10, 11, 12, 12 },
 { 6, 6, 5, 5, 4, 3, 4, 5, 6, 7, 10, 10, 11, 12, 12, 19, 14, 16 },
 { 8, 6, 5, 6, 6, 4, 5, 5, 6, 8, 10, 10, 10, 10, 11, 19, 15, 17 },
 { 10, 7, 6, 7, 7, 5, 6, 5, 7, 9, 10, 10, 10, 10, 12, 19, 16, 18 },
 { 11, 8, 7, 8, 8, 6, 8, 9, 10, 12, 15, 16, 16, 17, 15, 16, 17, 18 },
 { 12, 10, 8, 10, 10, 7, 9, 10, 12, 15, 16, 16, 17, 17, 16, 17, 18, 18 },
 { 13, 12, 10, 10, 10, 8, 9, 10, 12, 15, 16, 16, 17, 17, 18, 19, 18, 18 },
 { 13, 13, 12, 12, 12, 10, 10, 11, 13, 15, 16, 16, 17, 17, 18, 19, 18, 18 },
 { 13, 13, 12, 12, 12, 10, 10, 11, 13, 15, 16, 16, 17, 17, 19, 19, 18, 18 },
 { 14, 13, 13, 12, 12, 12, 12, 13, 14, 15, 16, 16, 17, 17, 20, 19, 18, 18 }};

            double  rainFallRate;
            double hourOfRain;
            double RainFall= 0;
            double drainingRate=4;
            double Drainage;
            double hours=1;



            display(floodPlain, arrayRowNumber,RainFall, hours);

    cout<<"\n\tPress enter to start: \n";
    cin.get();

                 Get_inputs ( rainFallRate,hourOfRain );
                 system("CLS");
                 Simulations(floodPlain,arrayRowNumber, rainFallRate,hourOfRain, RainFall, drainingRate, Drainage, hours);




    return 0;
}


void Get_inputs (double& rainFallRate,double& hourOfRain )
{
cout<<"enter the rain fall rate:\n ";
cin >>rainFallRate;
cout<<"enter the duration  of rain in hours:\n ";
cin>> hourOfRain;
}
    void Simulations(double floodPlain[][18],int arrayRowNumber,double rainFallRate,double  hourOfRain,double& RainFall,double drainingRate,double& Drainage,double& hours)
    {


        while (hours<=hourOfRain)
        {
        RainFall+=rainFallRate;
           for  ( int i=0; i<arrayRowNumber; i++)
           {

               for (int j=0; j<18;j++)
               {
                   if (floodPlain[i][j]<=RainFall)
                   {

                      SetConsoleTextAttribute(hConsole,9);

                       cout <<" * ";
                   }

                    else
                        {

                     SetConsoleTextAttribute(hConsole,10);
                       cout <<" + ";
                        }
                     SetConsoleTextAttribute(hConsole, 15);


                }
                cout <<"\n";


           }


cout <<"total rain fall is : "<<RainFall<<" inches    ,"
<< " Time elapsed is: "<<hours<<" hours ";


        Sleep(3000);
        system("CLS");
           hours++;

        }

        cout <<"\t\t<<<<<<Rain ends after " << hours-1<<" hour >>>>>>>\n";
         Sleep(3000);
        system("CLS");




         while (Drainage>=0)
         {

             Drainage = (RainFall-drainingRate);


            Drainage = (RainFall-drainingRate);

             for  ( int i=0; i<arrayRowNumber; i++)
            {

               for (int j=0; j<18;j++)
               {
                   if (floodPlain[i][j]<=Drainage)
                   {

                     SetConsoleTextAttribute(hConsole,9);

                       cout <<" * ";

                    }
                    else
                        {

                     SetConsoleTextAttribute(hConsole,10);
                       cout <<" + ";
                        }

                     SetConsoleTextAttribute(hConsole, 15);

               }
               cout <<"\n";

         }


if (Drainage>=0)
 {

cout <<"\n\t total rain fall is : "<<RainFall<<" inches    ,\n";
cout <<"\twater level  : "<< Drainage<<" inches    ,\n";
cout << " \t Time elapsed is: "<<hours<<" hours ";
 }
 else
 {
cout <<"\n\t total rain fall is : "<<RainFall<<" inches    ,\n";
cout <<"\t water level  : 0.00 inches    ,\n";
cout << " \t Time elapsed is: "<<hours<<" hours ";

 }

        Sleep(3000);
        system("CLS");
           hours++;

           drainingRate=drainingRate+4;
    }

    }




    void display(double floodPlain[][18],int arrayRowNumber,double RainFall,double hours)
    {


for  ( int i=0; i<arrayRowNumber; i++)
            {

               for (int j=0; j<18;j++)
               {
                   SetConsoleTextAttribute(hConsole,10);
                   cout <<" + ";
               }
               cout <<"\n";

            }

SetConsoleTextAttribute(hConsole, 15);

    }
