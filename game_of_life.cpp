#include <iostream>
#include <vector>

using namespace std;

using Grid = vector<vector<char>>;

int nocrash(int i) {
    return max(i, 0);
}

void display(const Grid& grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}


void maxxing(Grid& grid) {
    Grid temp = grid;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) { 
            char base = grid[i][j];
                char before = grid[i][j-1];
                    int beforefulll = 0;
                    int noupper = nocrash(i-1);
                    int nolower = 0;
                    //cout << nolower << endl;
                    for(int k = noupper; k <= i+1; k++) {
                        if(k<grid[i].size()) {
                            char beforefull = grid[k][j-1];
                            if(beforefull == 'X') {
                                beforefulll++;
                            }
                        }
                    }
                char current = grid[i][j];
                    int currentfulll = 0;
                    for(int k = noupper; k <=i+1; k++) {
                        if(k<grid[i].size()) {
                            char currentfull = grid[k][j];
                            if (currentfull == 'X') {
                                currentfulll++;
                        }
                    }
                }
                char after = grid[i][j+1];
                    int afterfulll = 0;
                    for(int k = noupper; k <=i+1; k++) {
                        if(k<grid[i].size()) {
                            char afterfull = grid[k][j+1];
                            if (afterfull == 'X') {
                                afterfulll++;
                            }
                    }
                }

                    if (grid[i][j] == 'X' && currentfulll > 0) {
                        currentfulll--;
                    }

                    int final = beforefulll+currentfulll+afterfulll;
                    if (grid[i][j] == 'X') {
                        if (final < 2 || final > 3)
                            temp[i][j] = '-';   
                    } else {
                        if (final == 3){
                            temp[i][j] = 'X'; 
                        }
                    }
        }
    }
        grid = temp;
}

int main() {
    Grid grid = {
        {'-', '-', 'X', '-', '-'},
        {'-', '-', 'X', '-', '-'},
        {'-', '-', 'X', '-', '-'},
        {'-', '-', 'X', '-', '-'},
        {'-', '-', 'X', '-', '-'}
    };

    cout << "Initial Grid:\n";
    display(grid);

    char input = 'y';

    while (input == 'y' || input == 'Y') {
        maxxing(grid);
        cout << "Next Generation:\n";
        display(grid);

        cout << "Lagi? (y/n): " << flush;
        cin >> input;
    }

    return 0;
}
