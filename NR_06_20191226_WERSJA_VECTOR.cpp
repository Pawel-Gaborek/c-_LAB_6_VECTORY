
//
//////////////////////////////////////////////////////////////
//  Pawel Gaborek                                           //
//  Programowanie C++                                       //
//  Semestr 3, rok 2, album nr: 45093                       //
//  Prowadzacy, Pan dr inż. Piotr Błaszyński                //
//  LABOLATORIUM_NR-6.cpp                                   //
//  LABOLATORIUM_NR-6------wersja VECTOR                    //
//                                                          //
//  Created by Paweł Gaborek on 15/04/2019.                 //
//  Copyright © 2019 Paweł Gaborek. All rights reserved.    //
//////////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

class matrix
{
    vector<vector<double>>matrix_;
public:
    
    /////////////////////////////////////////////////////////////////////////
    ////----------------konstruktory dla klasy matrix--------------------////
    
    matrix(){};
    
    ////-------------------konstruktor dla alokacji pamieci dla macierzy wypelnionej zerami
    matrix(int lines_number, int columns_number);
    
    ////-------------------konstruktor dla tworzenia macierzy wczytanej z pliku
    matrix(string matrix_name);
    
    
    
    
    /////////////////////////////////////////////////////////////////////////
    ////-------------------metody dla klasy matrix-----------------------////
    
    
    void return_matrix_(int line, int colum);
    
    void return_matrix_number(int line, int column);
    
    void return_matrix_line(int line, int column);
    
    void return_matrix_columne(int line, int column);
    
    void write_matrix_to_file(string matrix_name, int lines_number, int columns_number);
    
    void change_matrix_number_value(int line, int column, double new_value);
    
    void matrix_transpose();
    
    string get_time();
    
private:
protected:
};

///////////////////////////////////////////////////////////
/////////------------konstruktory---------------///////////
///////////////////////////////////////////////////////////

matrix::matrix(int line, int column)
{
    matrix_.resize(line);
    for(int i=0; i<line; i++)
    {
        matrix_[i].resize(column);
    }
    for(int j=0; j<line; j++)
    {
        for(int k=0; k<column; k++)
        {
            matrix_[j][k]=0;
        }
    }
}

matrix::matrix(string matrix_name)
{
    ////-------------------otwieram plik konwertuje linie pliku do tablicy stringow
    string file_name;
    string templine;
    string templine_2;
    fstream name_file;
    fstream name_file_2;
    int lines_number=0;
    int columns_number=0;
    int j=0;
    file_name = "matrix";
    name_file.open(file_name+=".txt", ios::in);
    if(name_file.good()==false)
    {
        cout << "Przykro mi! Jednak program nie mogl odnalezc pliku o takiej nazwie.";
        cout << "Program teraz utworzy nowy plik o nazwie ''matrix.txt''";
        name_file.open("matrix.txt", ios::out | ios::app);
    }
    
    vector<string>temp_string_from_file;
    while(getline(name_file, templine))
    {
        temp_string_from_file.push_back(templine);
        lines_number++;
    }
    
    templine_2=temp_string_from_file[0];
    int length= temp_string_from_file[0].length();
    for (int j=0 ; j<length ; j++)
    {
        if (templine_2[j]==';')
        {
            columns_number++;
        }
    }
    
    matrix_.resize(lines_number);
    for(int i=0; i<lines_number; i++)
    {
        matrix_[i].resize(columns_number);
    }
    
    for (int im=0 ; im<lines_number ; im++)
    {
        string tempstring;
        string temp_value;
        tempstring = temp_string_from_file[im];
        for (int jl=0 ; jl<columns_number ; jl++)
        {
            
            temp_value=tempstring;
            tempstring.erase(tempstring.find(';'), tempstring.length());
            double temp_double = atof(tempstring.c_str());
            matrix_[im][jl]=temp_double;
            if (j<columns_number)
            {
                temp_value.replace(0,temp_value.find(';')+1, "");
                tempstring=temp_value;
            }
        }
    }
    ////-------------------kasuje pamiec i zamykam plik
    name_file.close();
    
}



///////////////////////////////////////////////////////////
/////////---------------metody------------------///////////
///////////////////////////////////////////////////////////


void matrix::return_matrix_(int line, int column)
{
    for(int i=0 ; i<line ; i++)
    {
        for (int j=0 ; j<column ; j++)
        {
            cout << matrix_[i][j] << "\t\t\t";
        }
        cout << "\n";
    }
}

void matrix::return_matrix_line(int line, int column)
{
    for(int i=0 ; i<column ; i++)
    {
        cout << matrix_[line][i];
    }
}

void matrix::return_matrix_columne(int line, int column)
{
    for(int i=0 ; i<column ; i++)
    {
        cout << matrix_[i][column];
    }
}

void matrix::return_matrix_number(int line, int column)
{
    cout << matrix_[line][column];
}

void matrix::write_matrix_to_file(string matrix_name, int lines_number, int columns_number)
{
    string time_from_return;
    time_from_return = get_time();
    fstream file_export;
    string file_name=matrix_name;
    string temp_number;
    file_export.open(file_name+"_"+time_from_return+=".txt", ios::out | ios::app);
    for (int i=0 ; i<lines_number ; i++)
    {
        for (int j=0 ; j<columns_number ; j++)
        {
            temp_number=to_string(matrix_[i][j]);
            file_export << temp_number<< ";";
        }
        file_export << "\n";
    }
    file_export.close();
}

string matrix::get_time()
{
    time_t rawtime;
    string time_to_return;
    struct tm * timeinfo;
    char time_table [100];
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    
    strftime (time_table,100,"%F",timeinfo);
    time_to_return=time_table;
    return time_to_return;
}


string get_time()
{
    time_t rawtime;
    string time_to_return;
    struct tm * timeinfo;
    char time_table [100];
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    
    strftime (time_table,100,"%X",timeinfo);
    time_to_return=time_table;
    return time_to_return;
}

string get_date()
{
    time_t rawtime;
    string time_to_return;
    struct tm * timeinfo;
    char time_table [100];
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    
    strftime (time_table,100,"%F",timeinfo);
    time_to_return=time_table;
    return time_to_return;
}

void matrix::change_matrix_number_value(int line, int column, double new_value)
{
    //int line;
    //int column;
    //double new_value;
    //cout << "Podaj kolumne i wiersz dla wartosci ktora ma byc zmodyfikowana.\n";
    //cout << "Kolumna:\t";
    //cin >> column;
    //cout << "\nWiersz:\t";
    //cin >> line;
    //cout << "\nPodaj nowa wartosc dla elementu macierzy:\t";
    //cin >> new_value;
    matrix_[line][column]=new_value;
}

void matrix::matrix_transpose()
{
    ////-------------------otwieram plik konwertuje linie pliku do tablicy stringow
    string file_name;
    string templine;
    string templine_2;
    fstream name_file;
    fstream name_file_2;
    int lines_number;
    int columns_number;
    vector<vector<double>>temp_vector;
    
    
    vector<string>temp_string_from_file;
    while(getline(name_file, templine))
    {
        temp_string_from_file.push_back(templine);
        lines_number++;
    }
    
    lines_number=matrix_.size();
    columns_number=matrix_[0].size();
    
    temp_vector.resize(lines_number);
    for(int i=0; i<lines_number; i++)
    {
        temp_vector[i].resize(columns_number);
    }
    for(int j=0; j<lines_number; j++)
    {
        for(int k=0; k<columns_number; k++)
        {
            temp_vector[j][k]=matrix_[j][k];
        }
    }
    
    matrix_.resize(columns_number);
    for(int i=0; i<columns_number; i++)
    {
        temp_vector[i].resize(lines_number);
    }
    
    for(int j=0; j<columns_number; j++)
    {
        for(int k=0; k<lines_number; k++)
        {
            matrix_[j][k]=temp_vector[k][j];
        }
    }
}





int main()
{
    int exit = 0;
    char continuation;
    string teamTeam;
    string name;
    string program_begin;
    string program_end;
    string temp_date;
    
    while(exit==0)
    {
        program_begin=get_time();
        cout << "\nCzas rozpoczecia dzialania programu to: " << program_begin << "\n";
        cout << "\nSuper ! Wlasnie uruchomiles program do labolatorium nr 6 - wersja z VECTOREM - na kierunku Informatyka\n";
        cout << "Program umozliwi Ci tworzenie macierzy.\n";
        
        
        ////----------------
        ////----macierz nr 1
        
        cout << "\nMacierz nr 1: \n";
        matrix matrix_1(4, 3);
        matrix_1.return_matrix_(4, 3);
        matrix_1.write_matrix_to_file("Macierz_1", 4, 3);
        
        ////----------------
        ////----macierz nr 2
        
        cout << "\nMacierz nr 2 utworzona z pliku: \n";
        matrix matrix_2("matrix");
        matrix_2.return_matrix_(4, 3);
        matrix_2.write_matrix_to_file("Macierz_2", 4, 3);
        
        ////----------------
        ////----macierz nr 3
        
        cout << "Macierz po modyfikacji:\n";
        matrix matrix_3("matrix");
        matrix_3.change_matrix_number_value(0, 0, 5.87);
        matrix_3.change_matrix_number_value(1, 2, 2.45);
        matrix_3.change_matrix_number_value(2, 0, 10.43);
        matrix_3.change_matrix_number_value(3, 2, 4.23);
        matrix_3.change_matrix_number_value(0, 2, 5);
        matrix_3.return_matrix_(4, 3);
        matrix_3.write_matrix_to_file("Macierz_3", 4, 3);
        
        ////----------------
        ////----macierz nr 4
        cout << "Wyswietlam macierz do transponowaniu:\n";
        matrix matrix_4("Matrix_3_"+temp_date);
        matrix_4.return_matrix_(4, 3);
        matrix_4.matrix_transpose();
        cout << "Wyswietlam macierz po transponowaniu:\n";
        matrix_4.return_matrix_(3, 4);
        matrix_3.write_matrix_to_file("Macierz_4", 3, 4);
        
        
        program_end=get_time();
        cout << "\nCzas zakonczenia dzialania programu to: " << program_end << "\n";
        while(1)
        {
            cout << "\nProgram wlasnie zakonczyl swoje dzialanie";
            cout << "Czy chcesz uruchomic program ponownie ??";
            cout << "W przypadku ponownego uruchomienia wpisz litere ''t'', w przerciwnym razie wpisz litere ''n''.";
            cout << "Pamietaj ze wielkosc liter ma zmaczenie.\n\n\n";
            cin >> continuation;
            if(continuation=='t')
            {
                break;
            }
            else
            {
                cout << "Niestety podales bledna litere";
                cout << "Sproboj jeszcze raz";
            }
        }
        cout << "Szkoda ze nie chcesz ponownie uruchomic programu";
        cout << "Moze nastepnycm razem. Powodzenia !!!";
    }
    return 0;
};


