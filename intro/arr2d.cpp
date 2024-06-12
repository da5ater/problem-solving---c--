#include <iostream>



using namespace std;



int main ()
{
    int c = 5;
    int r = 5;
    int grades[r][c] = {
        {14 , 25 ,47, 6   , 23},
        {14 , 35, 16, 3267, 4},
        {1  , 2 , 7 , 8   , 4},
        {10 , 21, 73, 88  , 45},
        {10 , 21, 73, 88  , 45}
    };


    for (int row  = 0; row < r; row++)
    {
        double sum = 0;

        for (int column = 0; column < c ; column++)
        {
            sum += grades[row][column];
        }
        
        double avg = sum / 5;

        cout << "average grades for student  number " << row << "is : " << avg <<endl;
    }
    

    


}