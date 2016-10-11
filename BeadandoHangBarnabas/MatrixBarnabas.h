#include <iostream>
using namespace std;

class MatrixBarnabas{
private:
    int matrix[5][5];
public:
    MatrixBarnabas();
    void printMatrixFull();
    int getMatrixValue(int sor, int oszlop);
    void setMatrixValue(int sor, int oszlop, int value);
    MatrixBarnabas operator++(); //prefix
    MatrixBarnabas operator--(); //prefix
    bool TeleMatrix(); // csak egyesek vannak [Tele van a matrix egyesekkel]
    bool TeleSor(int i);
};
