#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Warrior {
    string weapon;
    int power;
    bool tag;
};

//Feel free to modify the parameters if you need other values
bool skirmish(Warrior*** protectors, Warrior*** invaders, int skirmish_row,
		      int rows, int columns, int &reserves, ofstream &output)
{
    //returns true if the invaders breach the walls.

    int j = skirmish_row;


    for(int i = 0; i < rows; i++)
    {
        if((protectors[i][j] != NULL)&&(invaders[j][i] != NULL))
        {
            if(protectors[i][j]->tag == false)
            {
                protectors[i][j]->power = i*10 + (j+1)*10;
            

                if(i%2 == 0)
                {
                    protectors[i][j]->weapon = "axe";
                }
            }

            invaders[j][i]->power = j*10 + (i+1)*10;
            

            if(j%2 != 0)
            {
                invaders[j][i]->weapon = "axe";
            }       
            //solving skirmish
            //when both have the same weapon
        
            if((protectors[i][j]->weapon) == (invaders[j][i]->weapon))
            {
                if((protectors[i][j]->power) > (invaders[j][i]->power))//protector wins
                {
                    invaders[j][i] = NULL;
                    output << "Invader Killed." << endl;
                }   
                    

                else if((invaders[j][i]->power) > (protectors[i][j]->power))//invader wins
                {   
                    bool nullFound = false;

                    for(int p = 0; p < rows; p++)//Protector Defects
                    {
                        for(int q = 0; q < columns; q++)
                        {

                            if(invaders[q][p] == NULL)
                            {
                                //Warrior *temp[i][j] = protector[i][j];
                                nullFound = true;
                                invaders[q][p] = protectors[i][j];
                                output << "Protector defected." << endl;
                                
                                break;
                                //invaders[q][p] = temp;
                                
                                
                            }
                        }
                        if(nullFound == true)
                        {
                            break;
                        }
                    }
                    

                    if(nullFound == false)//Protector Killed
                    {
                        output << "Protector Killed." << endl;
                    }
                        if(reserves == 0)
                        {
                            protectors[i][j] = NULL;
                        }

                        if(reserves > 0)
                        {
                            protectors[i][j]->weapon = "axe";
                            protectors[i][j]->power = 100;
                            protectors[i][j]->tag = true;
                            reserves--;
                        }
                        
                }
            

                else if((protectors[i][j]->power) == (invaders[j][i]->power))//draw
                {
                    output << "Duel ends in a draw." << endl;
                }
                    
            }

                

            else if(((protectors[i][j]->weapon)=="axe")&&((invaders[j][i]->weapon) == "sword"))//invader killed
            {
                invaders[j][i] = NULL;
                output << "Invader Killed." << endl;
            }

            else if(((protectors[i][j]->weapon)=="sword")&&((invaders[j][i]->weapon) == "axe"))//protector killed/defected
            {
                bool nullFound = false;

                    for(int p = 0; p < rows; p++)//Protector Defects
                    {
                        for(int q = 0; q < columns; q++)
                        {

                            if(invaders[q][p] == NULL)
                            {
                                //Warrior *temp[i][j] = protector[i][j];
                                nullFound = true;
                                invaders[q][p] = protectors[i][j];
                                output << "Protector defected." << endl;
                                
                                break;
                                //invaders[q][p] = temp; 
                            }
                        }
                        if(nullFound == true)
                        {
                            break;
                        }
                    }
                    

                    if(nullFound == false)//Protector Killed
                    {
                        output << "Protector Killed." << endl;
                    }
                        if(reserves == 0)
                        {
                            protectors[i][j] = NULL;
                        }

                        if(reserves > 0)
                        {
                            protectors[i][j]->weapon = "axe";
                            protectors[i][j]->power = 100;
                            protectors[i][j]->tag = true;
                            reserves--;
                        }
            }
        }
                     
        else
        {
            if((protectors[i][j] == NULL)&&(invaders[j][i]!=NULL))
            {
                return true;
            }
        
            if((protectors[i][j] != NULL)&&(invaders[j][i] == NULL))
            {
                output << "No assault." << endl;
            }
        }
    }

    return false;
}


    

int main(int argc, char* argv[])
{
    if (argc < 3) {
	   cerr << "Please provide an input and output file" << endl;
	   return -1;
    }

    ifstream input(argv[1]);
    ofstream output(argv[2]);

    if(input.fail())
    {
        cout << "You didn't enter a valid input file." << endl;
        return -1;
    }

    if(output.fail())
    {
        cout << "You didn't enter a valid output file." << endl;
        return -1;
    }

    int rows;
    int cols;
    int reserve;
    int skirmishes;

    string stringrows;
    string stringcols;
    string stringreserve;
    string stringskirmishes;
    //read the input file and initialize the values here.

    input >> stringrows;
    input >> stringcols;
    input >> stringreserve;
    input >> stringskirmishes;

    rows = stoi(stringrows);
    cols = stoi(stringcols);
    reserve = stoi(stringreserve);
    skirmishes = stoi(stringskirmishes);

    Warrior ***protectors = new Warrior** [rows];
    Warrior ***invaders = new Warrior** [cols];

    for(int i = 0; i < rows; i++)
    {  
            protectors[i] = new Warrior*[cols];
    }

    for(int i = 0; i < cols; i++)
    {
        invaders[i] = new Warrior*[rows];
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            protectors[i][j] = new Warrior;            
        }
    }

    for(int i = 0; i < cols; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            invaders[i][j] = new Warrior;            
        }
    }

    //initialize the protectors and invaders here.
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            //protectors[i][j] = NULL;
            //invaders[j][i] = NULL;

            protectors[i][j]->weapon = "sword";
            protectors[i][j]->power = 0;
            
            invaders[j][i]->weapon = "sword";
            invaders[j][i]->power = 0;

            protectors[i][j]-> tag = false;
            invaders[j][i]-> tag = false;

        }
    }
    int flag = 0;
    for (int i=1; i <= skirmishes; i++){
        int skirmish_row;
        
        //read the input file to find the value for skirmish row
        string skirmtemp;
        input >> skirmtemp;

        skirmish_row = stoi(skirmtemp);

        if(skirmish_row > cols)
            continue;
        
        //In general, it is bad style to throw everything into your main function
        bool end = skirmish(protectors, invaders, skirmish_row, rows, cols, reserve, output);

        if(end == true)
        {
            flag = 1;
            break;
        }
    }

    //output the winner and deallocate your memory.
    if(flag == 1)
    {
        output << "Winner: invaders" << endl;
    }
    else
    {
        output << "Winner: protectors" << endl;
    }

    /*for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
           delete protectors[i][j];
        }
       delete[] protectors[i];
   }
    delete[] protectors;

    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
           delete invaders[i][j];
        }
        delete[] invaders[i];
    }
    delete[] invaders;

    return 0;*/
}
