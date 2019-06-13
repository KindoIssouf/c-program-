/*issouf kindo
CSE-110-301
this program sells theater tickets
*/
#include <iostream>
#include <iomanip>
#include <math.h>
#include <windows.h>

#include <cstdlib>

using namespace std;

void Display_seats(int seatingArray[][8],int rows);
void Check_For_Availablility(int seatingArray[][8],int rows,int x,int y);
void get_selected_seat(int& x,int& y,int seatingArray[][8],int rows,bool check1);
bool Check_For_soldOut(int seatingArray[][8],int rows);


int main()
{
     int rows = 9;
     int seatingArray[rows][8] ={
                                { 40, 50, 50, 50, 50, 50, 50, 40 },
                                { 30, 30, 40, 50, 50, 40, 30, 30 },
                                { 20, 30, 30, 40, 40, 30, 30, 20 },
                                { 10, 20, 20, 20, 20, 20, 20, 10 },
                                { 10, 20, 20, 20, 20, 20, 20, 10 },
                                { 10, 20, 20, 20, 20, 20, 20, 10 },
                                { 10, 10, 10, 10, 10, 10, 10, 10 },
                                { 10, 10, 10, 10, 10, 10, 10, 10 },
                                { 10, 10, 10, 10, 10, 10, 10, 10 } };

    Display_seats(seatingArray,rows);

    int x,y;

    bool check1=false;

    get_selected_seat(x, y,seatingArray,rows, check1);

      check1 = Check_For_soldOut(seatingArray,rows);

    while(check1== false)
     {

           Check_For_Availablility( seatingArray,rows, x, y);

                Sleep(3000);
                system("CLS");

                Display_seats(seatingArray,rows);

                check1 = Check_For_soldOut(seatingArray,rows);

                get_selected_seat(x, y,seatingArray,rows, check1);


        }




    return 0;
}


    void Display_seats(int seatingArray[][8],int rows)
    {
        cout <<"\n\n----------------Available Seats in the Theater-------------------\n"<<endl;


        for (int i = 0;i<= rows - 1;i++)
        {
            for (int j= 0; j<= 7 ;j++)

            {
                if(seatingArray[i][j] !=-1)
                {
                    cout<<setw(4)<<" "<<setw(1)<<"$ "<<setw(2)<<seatingArray[i][j];
                }
                else
                {
                    cout<<setw(4)<<" "<<setw(4)<<"X";
                }

            }
            cout <<"\n";
        }
    }

    void get_selected_seat(int& x,int& y,int seatingArray[][8],int rows,bool check1)
    {
        int Temp1;
        int Temp2;
        bool CheckInput = false;

         while ((CheckInput == false)&&( check1== false))

        {

                cout <<"\n\t please select a row of your seat: ";
                cin>>Temp1;

                cout <<"\t please select a column of your seat: ";
                cin>>Temp2;

                if (((Temp1>0)&&(Temp1<= 9))&&((Temp2>0)&&(Temp2<=8)))
                {
                x =Temp1;
                y =Temp2 ;
                CheckInput = true;

                }
                else
                {
                cout <<"\n\t Error: "<<Temp1<<","<<Temp2<<" is an invalid seat entry\n\n";

                }


        }
    }



    void Check_For_Availablility(int seatingArray[][8],int rows,int x,int y)
    {
    int sentinel = -1;

            if (seatingArray[x-1][y-1] != sentinel)
            {

                cout <<"\n\t Thank You for choosing seat: # "<<x<<","<<y<<"\n";

                cout <<"\t Your ticket price is: $" <<seatingArray[x-1][y-1]<<endl;

                seatingArray[x-1][y-1] = sentinel;

            }

            else
                {
                cout <<"\t THIS SEAT HAS BEEN ALREADY SOLD \n\n";
                }

}

bool Check_For_soldOut(int seatingArray[][8],int rows)
{
    bool SoldOut = false;
    int Count = 0;

     for (int i = rows - 1; ((i >= 0)&&(SoldOut == false)) ; i--)
        {
            for (int j = 7; ((j>= 0)&&(SoldOut == false)); j--)

            {
                if(seatingArray[i][j] == -1)
                {
                    Count++;
                }

                if (Count == 72)
                   {
                       cout <<"\n\t ATTENTION: THE THEATER HAS BEEN SOLD OUT! ";
                       SoldOut = true;
                   }
            }
        }

        return SoldOut;

}




