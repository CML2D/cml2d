#include <iostream>
#include <cstring>
#include "getopt.h"
#define HELP "HELP: use options -f for showing formula, -p for showing oxidation number, -v for visualizing 2-d model."

using namespace std;

int main(int argc, char *argv[]){
    int rez = 0, f_flag = 0, p_flag = 0, v_flag = 0, err_flag = 0, help_flag = 0;
    char *outfile = NULL, *infile = NULL;
    switch(argc){
        case 1:
            cout << "Empty input" << endl; 
			err_flag = 1;
			break;
        case 2:
            if (!strcmp(argv[1], "help"))
			{
                cout << HELP << endl;
				help_flag = 1;
			}
            else
			{
                cout << "Wrong input" << endl;
			    err_flag = 1;
			}
            break;
        default:
            infile = argv[1];
            outfile = argv[argc-1];
            while ((rez = getopt (argc-1, &(argv[1]), "f:p:v:")) != -1)
                switch (rez)
                {
                  case 'f':
                    f_flag = 1;
                    break;
                  case 'p':
                    p_flag = 1;
                    break;
                  case 'v':
                    v_flag = 1;
                    break;
                  case '?':
                    err_flag = 1;
                }
    }
    if(err_flag == 0 && help_flag == 0)
    {
        cout << infile << endl;
        cout << f_flag << p_flag << v_flag << endl;
        cout << outfile << endl;
    }
    else if(err_flag)
        cout << "Error" << endl;
    return 0;
}