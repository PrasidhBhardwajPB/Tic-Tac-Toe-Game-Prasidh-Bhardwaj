#include <iostream>

bool winning(char grid[3][3], bool playerStatus, int row, int colm);

int main(){

    int row, colm;
    int strikes = 0;
    char p1, p2;
    bool P1status = false;
    bool P2status = false;
    char grid[3][3];

    grid[0][0] = '-';
    grid[0][1] = '-';
    grid[0][2] = '-';
    grid[1][0] = '-';
    grid[1][1] = '-';
    grid[1][2] = '-';
    grid[2][0] = '-';
    grid[2][1] = '-';
    grid[2][2] = '-';

    std::cout << "***TIC TAC TOE GAME***" << "\n";
    for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                std::cout << grid[i][j] << " ";
            }
            std::cout << std::endl;
        }

    do{
        do{
            do{
                std::cout << "Player1, where to strike? " << std::endl ;
                std::cin >> row >> colm;
                if(row<0 || row>2 || colm <0 || colm >2){
                    std::cout << "Enter Rows 0 to 2 & Columns 0 to 2." << std::endl;
                }
            }while(row<0 || row>2 || colm <0 || colm >2);
            if(grid [row][colm] != '-'){
                std::cout << "Don't try to cheat by overwriting! Enter something valid." << std::endl;
            }
        }while(grid[row][colm] != '-');

        grid[row][colm] = 'X';    
        strikes++;
        

        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                std::cout << grid[i][j] << " ";
            }
            std::cout << std::endl;
        }

        P1status = winning(grid, P1status, row, colm);
        if(strikes == 9){
            break;
        }

        if(P1status == true){
            break;
        }

        do{
            do{
                std::cout << "Player2, where to strike? " << std::endl ;
                std::cin >> row >> colm;
                if(row<0 || row>2 || colm <0 || colm >2){
                    std::cout << "Enter Rows 0 to 2 & Columns 0 to 2." << std::endl;
                }
            }while(row<0 || row>2 || colm <0 || colm >2);
            if(grid [row][colm] != '-'){
                std::cout << "Don't try to cheat by overwriting! Enter something valid." << std::endl;
            }
        }while(grid[row][colm] != '-');

        grid[row][colm] = 'O';
        strikes++;
        
        
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                std::cout << grid[i][j] << " ";
            }
            std::cout << std::endl;
        }

        P2status = winning(grid, P2status, row, colm);
        if(strikes == 9){
            break;
        }

    }while(P1status == false && P2status == false);

    if(P1status == true){
        std::cout << "Player1 wins!" << std::endl;
    }
    else if (P2status == true){
        std::cout << "Player2 wins!" << std::endl;
    }
    else{
        std::cout << "It's a Draw!"<< std::endl;
    }

    std::cout << "***COME BACK AGAIN***";

    return 0;
}

bool winning(char grid[3][3], bool playerStatus, int row, int colm){

    if (row == 0 && colm == 0){     // Row 0 Checking
        if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
            playerStatus = true;
        }
        else if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]){
            playerStatus = true;
        }
        else if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]){
            playerStatus = true;
        }
    }
    else if (row == 0 && colm == 1){
        if (grid[0][1] == grid[1][1] && grid[1][1]== grid[2][1]){
            playerStatus = true;
        }
        else if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]){
            playerStatus = true;
        }
    }
    else if (row == 0 && colm == 2){
        if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
            playerStatus = true;
        }
        else if (grid[2][2] == grid[1][2] && grid[1][2] == grid[0][2]){
            playerStatus = true;
        }
        else if (grid[0][2] == grid[0][1] && grid[0][1] == grid[0][0]){
            playerStatus = true;
        }
    }

    else if (row == 1 && colm == 0){        // Row 1 Checking
        if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]){
            playerStatus = true;
        }
        else if (grid[1][0] == grid[0][0] && grid[0][0] == grid[2][0]){
            playerStatus = true;
        }
    }
    else if (row == 1 && colm == 1){
        if (grid[1][1] == grid[0][1] && grid[0][1] == grid[2][1]){
            playerStatus = true;
        }
        else if (grid[1][1] == grid[1][0] && grid[1][0] == grid[1][2]){
            playerStatus = true;
        }
        else if (grid[1][1] == grid[0][0] && grid[0][0] == grid[2][2]){
            playerStatus = true;
        }
        else if (grid[1][1] == grid[0][2] && grid[0][2] == grid[2][0]){
            playerStatus = true;
        }
    }
    else if (row == 1 && colm == 2){
        if (grid[1][2] == grid[0][2] && grid[0][2] == grid[2][2]){
            playerStatus = true;
        }
        else if (grid[1][2] == grid[1][1] && grid[1][1] == grid[1][0]){
            playerStatus = true;
        }
    }

    else if (row == 2 && colm == 0){          // Row 2 Checking
        if (grid[2][0] == grid[1][0] && grid[1][0] == grid[0][0]){
            playerStatus = true;
        }
        else if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]){
            playerStatus = true;
        }
        else if (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]){
            playerStatus = true;
        }
    }
    else if (row == 2 && colm == 1){
        if (grid[2][1] == grid[1][1] && grid[1][1] == grid[0][1]){
            playerStatus = true;
        }
        else if (grid[2][1] == grid[2][0] && grid[2][0]== grid[2][2]){
            playerStatus = true;
        }
    }
    else if (row == 2 && colm == 2){
        if (grid[2][2] == grid[1][1] && grid[1][1]== grid[0][0]){
            playerStatus = true;
        }
        else if (grid[2][2] == grid[2][1] && grid[2][1] == grid[2][0]){
            playerStatus = true;
        }
        else if (grid[2][2] == grid[1][2] && grid[1][2] == grid[0][2]){
            playerStatus = true;
        }
    }

    return playerStatus;

}