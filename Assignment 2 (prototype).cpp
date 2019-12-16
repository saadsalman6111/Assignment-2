#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
//int IS[3][3] = {8,0,6,5,4,7,2,3,1};
//int FS[3][3] = {0,1,2,3,4,5,6,7,8};
int IS[3][3] = {1,2,3,5,6,0,7,8,4};
int FS[3][3] = {1,2,3,5,8,6,0,7,4};
int current_cost;
void check_currentcost()
{
    int cost = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (IS[i][j] != FS[i][j])
                cost++;
        }
    }
    current_cost = cost;
}
int checkcost(int x, int y, int i, int j)
{
    int cost = 0;
    int temp = IS[x][y];
    IS[x][y] = IS[i][j];
    IS[i][j] = temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (IS[i][j] != FS[i][j])
                cost++;
        }
    }
    temp = IS[x][y];
    IS[x][y] = IS[i][j];
    IS[i][j] = temp;
    return cost;
}
void perform_move()
{
    int minimum;
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (IS[i][j] == 0)  //Move.
            {
                if (j+1 < 3 && IS[i][j+1]!= FS[i][j+1])
                {
                    //cout<<"Right Possible\n";
                    right  = true;
                }
                if (j-1 >= 0  && IS[i][j-1]!= FS[i][j-1])
                {
                    //cout<<"Left Possible\n";
                    left = true;
                }
                if (i-1 >= 0  && IS[i-1][j]!= FS[i-1][j])
                {
                   // cout<<"up Possible\n";
                    up = true;
                }
                if (i+1 < 3  && IS[i+1][j]!= FS[i+1][j])
                {
                   // cout<<"down Possible\n";
                    down = true;
                }
                int cost_left = 100000;             //initialized to a very big number
                int cost_right = 100000;
                int cost_up = 100000;
                int cost_down = 100000;
                if (left == true)
                    cost_left = checkcost(i, j-1, i, j);
                if (right == true)
                    cost_right = checkcost(i, j+1, i, j);
                if (up == true)
                    cost_up = checkcost(i-1, j, i, j);
                if (down == true)
                    cost_down = checkcost(i+1, j, i, j);
                minimum = min(cost_left, cost_right);
                minimum = min(minimum, cost_up);
                minimum = min(minimum, cost_down);
                if (minimum== cost_left)
                {
                    cout<<"going left\n";
                    int temp = IS[i][j];
                    IS[i][j] = IS[i][j-1];
                    IS[i][j-1] = temp;
                }
                else if(minimum == cost_right)
                {
                     cout<<"going right\n";
                    int temp = IS[i][j];
                    IS[i][j] = IS[i][j+1];
                    IS[i][j+1] = temp;
                }
                else if (minimum == cost_down)
                {
                     cout<<"going down\n";
                    int temp = IS[i][j];
                    IS[i][j] = IS[i+1][j];
                    IS[i+1][j] = temp;
                }
                else if (minimum == cost_up)
                {
                     cout<<"going up\n";
                    int temp = IS[i][j];
                    IS[i][j] = IS[i-1][j];
                    IS[i-1][j] = temp;
                }
            }
        }
    }
    current_cost = minimum;
}
int main()
{
    do
    {
        check_currentcost();
        if (current_cost == 0){}
            //break;
        perform_move();          //Print the next formed sequence.
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            cout<<IS[i][j]<<" ";
            cout<<endl;
        }
        system("pause");
    }while(current_cost != 0);
    cout<<"\n\n\nFINAL OUTPUT\n\n";
    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            cout<<IS[i][j]<<" ";
            cout<<endl;
        }
    cout<<"\n\nProgram ends\n";
    return 0;
}
