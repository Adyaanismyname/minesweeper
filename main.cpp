#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


#define max_side 10


int side = 10;
int mine = 16;
int minecounter = 0;

void displayboard(string myboard[][max_side]) {
    cout << endl;

    for (int i = 0; i < side; i++) {
        cout << i << " ";
    }
    cout << endl;
    

    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            cout << myboard[i][j] << " ";
        }

        cout << "  " << i;
        cout << endl;
    }
}

void placemines(string realboard[][max_side]) {
    int counter = 0;

    while (counter < mine) {
        int x = rand() % side;
        int y = rand() % side;

        if (realboard[x][y] != "*") {
            realboard[x][y] = "*";
            counter++;
        }
    }
}

int mine_counter(int x, int y, string realboard[][max_side]) {
    int counter = 0;
    if(x-1 >= 0) {
        if(realboard[x-1][y] == "*") {
            counter++;
        }
        if(y+1 <= side-1 && realboard[x-1][y+1] == "*") {
            counter++;
        }
        if(y-1 >= 0 && realboard[x-1][y-1] == "*") {
            counter++;
        }
        
    }
    
    if(x+1 <= side-1) {
        if(realboard[x+1][y] == "*") {
            counter++;
        }
        if(y+1 <= side-1 && realboard[x+1][y+1] == "*") {
            counter++;
        }
        if(y-1 >= 0 && realboard[x+1][y-1] == "*") {
            counter++;
        }
        
    }

    if(y+1 <= side-1 && realboard[x][y+1] == "*") {
        counter++;
    }
    if(y-1 >= 0 && realboard[x][y-1] == "*" ) {
        counter++;
    }

    return counter;

    
}

void input(int& x, int& y, string myboard[][max_side], string realboard[][max_side]) {
    bool upper_row = true;
    bool lower_row = true;
    bool right_col = true;
    bool left_col = true;
    cout << "Enter the row: ";
    cin >> x;
    cout << "Enter the column: ";
    cin >> y;

    if (x < side && y < side) {
        mine_counter(x, y, realboard);

        if (realboard[x][y] != "*") {
            if(mine_counter(x,y,realboard) == 0) {
                int randomarea = rand() %(10-2);
                for(int i = 0; i < 5; i++ ) {
                    if(upper_row == true) {
                        if(x-i >= 0) {
                            if(realboard[x-i][y] != "*") {
                                myboard[x-i][y] = to_string(mine_counter(x-i,y,realboard));
                            }
                            else {
                                upper_row = false;
                            }
                            
                            if(y+i <= side-1 && realboard[x-i][y+i] != "*") {
                                myboard[x-i][y+i] = to_string(mine_counter(x-i,y+i,realboard));
                            }
                            else {
                                upper_row = false;
                            }
                            
                            if(y-i >= 0 && realboard[x-i][y-i] != "*") {
                                myboard[x-i][y-i] = to_string(mine_counter(x-i,y-i,realboard));
                                
                            }
                            else {
                                upper_row = false;
                            }

        
                        }
                    }


                    if(lower_row== true) {
                        if(x+i <= side-1) {
                            if(realboard[x+i][y] != "*") {
                                myboard[x+i][y] = to_string(mine_counter(x+i,y,realboard));
                            }
                            else {
                                lower_row = false;
                            }
                            if(y+i <= side-i && realboard[x+i][y+i] != "*") {
                                myboard[x+i][y+i] = to_string(mine_counter(x+i,y+i,realboard));
                                
                            }
                            else { 
                                lower_row = false;
                            }
                            if(y-i >= 0 && realboard[x+i][y-i] != "*") {
                                myboard[x+i][y-i] = to_string(mine_counter(x+i,y-i,realboard));
                            }
                            else {
                                lower_row = false;
                            }

                            
                        }
                    }

                    if(right_col == true) {
                        if(y+i <= side-1 && realboard[x][y+i] != "*") {
                            myboard[x][y+i] = to_string(mine_counter(x,y+i,realboard));
                        }
                        else {
                            right_col = false;
                        }
                    }
                    if(left_col == true) {
                        if(y-i >= 0 && realboard[x][y-i] != "*" ) {
                            myboard[x][y-i] = to_string(mine_counter(x,y-i,realboard));
                        }
                        else {
                            left_col = false;
                        }
                    }

                }
            }
            else {
                myboard[x][y] = to_string(mine_counter(x,y,realboard));
                minecounter = 0;
            }
            
        }
        else {
            cout << "Game over" << endl;
            exit(EXIT_SUCCESS);
        }
    }
}

int main() {
    string realboard[max_side][max_side];
    string myboard[max_side][max_side];

    // initializing the boards
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            realboard[i][j] = "-";
            myboard[i][j] = "-";
        }
    }

    srand(time(0)); // Seed the random number generator

    int input_x;
    int input_y;

    placemines(realboard);
    
    while (true) {
        cout << "=================Minesweeper=================";
        cout << endl;
        cout << endl;
        system("clear");
        displayboard(myboard);
        //displayboard(realboard);
        input(input_x, input_y, myboard, realboard);
    }

    return 0;
}