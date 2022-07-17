#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;

void tailNLineFromAFile(string str, int nlines)
{
    int count = 0;
    long int pos;
    char s[nlines*10];
    cout<<"\n\n--------------- About to read "<<nlines<<" from \""<<str<<"\" -----------------------\n"<<endl;
    FILE* input = fopen(str.c_str(),"r");
    if(input == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fseek(input,0,SEEK_END);
    pos = ftell(input);
    while(pos)
    {
        fseek(input, --pos, SEEK_SET);
        if(fgetc(input) == '\n')
        {    
            if(count++ == nlines) break;
        }
    }
    while(fgets(s,nlines*10,input) != NULL)
    {
        fprintf(stdout,"%s",s);
    }
    fclose(input);
    return ;
}

int main(int argc, char**argv)
{
    string _filename;
    int n_lines;
    char sub_cmd_after,sub_cmd_before;
    if(argc < 2)
    {
        cout<<"Less Number Of Argument\n";
        return 0;
    }
    _filename = argv[2];
    sscanf(argv[1],"%c%d%c",&sub_cmd_before,&n_lines,&sub_cmd_after);    
    tailNLineFromAFile(_filename,n_lines);
    return 0;
}
