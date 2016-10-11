#include <iostream>
#include "MatrixBarnabas.h"
#include <time.h>
#include <windows.h>
#include <string>

using namespace std;

MatrixBarnabas::MatrixBarnabas()
{
    srand (time(NULL));
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            matrix[i][j] = rand()%2;
        }
    }
    cout<<"kesz a matrix"<<endl;
}


void MatrixBarnabas::printMatrixFull()
{
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            cout << matrix[i][j];
        }
        cout <<endl;
    }
}

int MatrixBarnabas::getMatrixValue(int sor, int oszlop)
{
    return matrix[sor][oszlop];
}

void MatrixBarnabas::setMatrixValue(int sor, int oszlop, int value)
{
    matrix[sor][oszlop]=value;
}

MatrixBarnabas MatrixBarnabas::operator++()
{
    if (!TeleMatrix())
    {
        bool vanNemNullaSor=false;
        int elsoNemNullaSor;
        int db=0;
        for (int i=0; i <5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (matrix[i][j] != 0 && db==0)
                {
                    elsoNemNullaSor=i;
                    db++;
                    vanNemNullaSor=true;
                    break;
                }
            }
        }
        if (vanNemNullaSor && elsoNemNullaSor<5)
        {

            if (!TeleSor(elsoNemNullaSor) && elsoNemNullaSor<5)
            {
                for (int j=0; j<5; j++)
                {
                    matrix[elsoNemNullaSor][j] = 1;
                }
            }
            else if (TeleSor(elsoNemNullaSor) && elsoNemNullaSor<4)
            {
                elsoNemNullaSor++;
                while (TeleSor(elsoNemNullaSor)) elsoNemNullaSor++;

                for (int j=0; j<5; j++)
                {
                    matrix[elsoNemNullaSor][j] = 1;
                }
            }
            else
            {
                    cout<<"hiba a matrix megtelt!"<<endl;
            }

        }
        else
        {
                cout<<"Hiba, a matrixnak minden sora csupa 0!"<<endl;
            }
    }
    else
    {
            cout<<"hiba a matrixban csak 1esek vannak!"<<endl;
    }
}

    MatrixBarnabas MatrixBarnabas::operator--()
    {
            bool vanNemNullaSor=false;
            int elsoNemNullaSor;
            int db=0;
            for (int i=4; i >=0 ; i--)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (matrix[i][j] != 0 && db==0)
                    {
                        elsoNemNullaSor=i;
                        db++;
                        vanNemNullaSor=true;
                        break;
                    }
                }
            }
            if (vanNemNullaSor)
            {

                for (int j=0; j<5; j++)
                {
                    matrix[elsoNemNullaSor][j] = 0;
                }
                cout<<"-- operator lefutott!"<<endl;

            }
            else
            {
                cout << "Sajnos a matrixban csak 0-k vannak!"<<endl;
            }
        }

    bool MatrixBarnabas::TeleMatrix()
    {
        for (int i=0; i <5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (matrix[i][j] ==0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool MatrixBarnabas::TeleSor(int i)
    {
        for (int j=0;j<5;j++) {
            if (matrix[i][j]==0) return false;
        }
        return true;
    }
