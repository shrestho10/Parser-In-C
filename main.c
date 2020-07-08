#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main()
{

char expr[10000],operators[200],paren[200];
char variables[200][200];
char table[200][200];
int pos=0;
int ascii[10000]={0};
char constants[200];
char error[200][200];
int cnt,i,number=0;
int j=-1,k=-1,l=-1,n=0,parenth=-1,s=0,p=0;
int pr[1000]={0},m=0;
char type[100][100];
int identifier=0;
int point=0;
int uu=0;
int codeRunner=0;
int pathStarter=0;
int errorPos=0;
char arr[200][200];
int arrayPos1=0, arrayPos2=0;
int checkBefore=0;
int arrayCheck=0;
int beforeAvailable=0;
int newlinecounter=0;
int variablepos[100];




printf("\nParser \n\n");

printf("Enter the String\n\n");

scanf("%[^\t]s", expr );

cnt = strlen(expr);

for(i = 0; i < cnt; ++i)
{

if(expr[i]=='\n')
{
    newlinecounter++;
}

if(expr[i-1]=='#'&&expr[i]=='i'&& expr[i+1]=='n'&& expr[i+2]=='c'&& expr[i+3]=='l'&&expr[i+4]=='u'&&expr[i+5]=='d'
   && expr[i+6]=='e')
{
  codeRunner=1;
  pathStarter=i+7;
  break;

}
}


if(codeRunner==1)
{





for (i = pathStarter; i < cnt; ++i)
{
ascii[i] = (int)expr[i];
}

for(i=pathStarter;i<cnt;++i)

{
    if(expr[i]=='\n')
{
    newlinecounter++;
}



    if(expr[i]=='/'&& expr[i+1]=='/')
    {
        while(expr[i]!= '\n')
        {
            i++;
        }
        if(expr[i]=='\n')
{
    newlinecounter++;
}
    }
 if(expr[i]=='/'&& expr[i+1]=='*')  /*   */
    { i=i+2;
        while(1)
        {  if(expr[i]=='\n')
{
    newlinecounter++;
}
            if(expr[i]== '*'&& expr[i+1]=='/')
            {
                i=i+2;
                break;
            }
            else
            {

                i++;

            }
        }
    }

    if(expr[i]=='f'&&expr[i+1]=='i'&& expr[i+2]=='(')
    {
        i=i+2;
        printf("\n fi Error ---> if is a keyword\n\n");
    }

if( isdigit(expr[i]) || expr[i]=='.' )
{ identifier=0;
while(expr[i]!=';')
{
if(expr[i]=='\n')
{
    newlinecounter++;
}
if(expr[i]==','|| expr[i]==' ')
{
    break;
}
else
{

if(constants[j]=='.')
{
   point++;
   //printf("\n%d",point);
}

   j++;
    constants[j]=expr[i];
    i++;
}
}
constants[j+1]='\0';
j=1;
while(constants[j]!='\0')
{
    if(((int)constants[j]>=65 && (int)constants[j]<=90 && constants[j]!='E'&&constants[j]!='e' && constants[j]!='.' )
       || ((int)constants[j]>=97 && (int)constants[j]<=122 && constants[j]!='e'&&constants[j]!='E'& constants[j]!='.' )|| point>1)

{

    identifier=1;
    break;
}
j++;
}

if(identifier==1)
{
    printf(" \n %s \t Error\n",constants);
    j=-1;
point=0;


}

else{

printf("\n%s\t\tConstant\n\n",constants);
j=-1;
point=0;
}
}





/*if( isalpha(expr[i]) && ( expr[i-1]!=';' && expr[i-1]!=' ' &&expr[i-1]!='\n' && expr[i-1]!='('  && expr[i-1]!=operators[l]
    && expr[i-1]!= ',' && expr[i-1]!='_' )&& i!=0)
{
    error[p][s]=expr[i-1];
    while(expr[i]!=';'  )
    {


     s++;
     error[p][s]=expr[i];
     i++;
     if(expr[i]==','||expr[i]=='+'||expr[i]=='-'||expr[i]=='/'|| expr[i]=='*'|| expr[i]=='='|| expr[i]=='^'||
     expr[i]=='>'||expr[i]=='<'||expr[i]=='=')
     {
            //error[p][0]=' ';
         break;
     }
    }
    error[p][s+1]='\0';
     printf("%s\t",error);
    printf("\tError\n\n");
        p++;
    s=0;

}

*/
if( isalpha(expr[i]) && (expr[i-1]==' ' || expr[i-1]==';'|| expr[i-1]=='\n' || i==0 || expr[i-1]==paren[parenth]||
expr[i-1]==operators[l]|| expr[i-1]==','||expr[i-1]=='_'))
{
 arrayCheck=0;
 checkBefore=0;


    if(expr[i-1]=='_')
    {  k++;
        variables[m][k]='_';
    }

    if(expr[i-1]=='*'&&(expr[i-2]=='\n'||expr[i-2]==';'|| expr[i-2]==','|| expr[i-2]==' '))
    {  k++;
        variables[m][k]='*';
    }


while( isalpha(expr[i]) || isdigit(expr[i]) || expr[i]=='_' ||expr[i]=='['||expr[i]==']')
{
    if(expr[i]=='['&& !isdigit(expr[i+1]))
    {  arrayCheck=1;
        errorPos=i+1;
        arrayPos1++;
        while((expr[errorPos])!=']')
        {
            arr[arrayPos1][arrayPos2]=expr[errorPos];

            arrayPos2++;
            errorPos++;
        }
  arr[arrayPos1][arrayPos2+1]='\0';
    }



k++;
variables[m][k]=expr[i];
i++;

}



variables[m][k+1]='\0';
variablepos[m]=newlinecounter+1;
if (arrayCheck==1)
{


int y=m;
//printf("\n\n\n %d \n\n\n",y);

for( beforeAvailable=0;beforeAvailable<=y;beforeAvailable++)
{
    if(strcmp(variables[beforeAvailable],arr[arrayPos1])==0)
    {
    checkBefore=1;
   // printf("\n\n%d\n\n",checkBefore);
    break;

    }


}

if(checkBefore==0)
{
    printf("\n\n %s\t error\n\n", variables[m]);
   //printf("\n\n%d\n\n",checkBefore);
    m--;
}
//printf("\n%s\n",arr[arrayPos1]);
arrayPos1++;
}







/*int g=0,h=0;



    for(h=m,g=m;g>=0;g--)
    {
       if(strcmp(variables[h],variables[g-1])==0)
       {
        variables[h][0]='\0';

           break;
       }
    }

*/








if(strcmp(variables[m],"int")==0|| strcmp(variables[m],"main")==0||strcmp(variables[m],"float")==0||strcmp(variables[m],"char")==0||strcmp(variables[m],"if")==0||
       strcmp(variables[m],"else")==0||strcmp(variables[m],"for")==0||strcmp(variables[m],"auto")==0||strcmp(variables[m],"break")==0||strcmp(variables[m],"const")==0||
       strcmp(variables[m],"double")==0||strcmp(variables[m],"case")==0||strcmp(variables[m],"continue")==0||strcmp(variables[m],"default")==0||strcmp(variables[m],"do")==0||
       strcmp(variables[m],"enum")==0||strcmp(variables[m],"extern")==0||strcmp(variables[m],"goto")==0||strcmp(variables[m],"long")==0||strcmp(variables[m],"register")==0||
       strcmp(variables[m],"return")==0||strcmp(variables[m],"short")==0||strcmp(variables[m],"signed")==0||strcmp(variables[m],"sizeof")==0||strcmp(variables[m],"static")==0||
       strcmp(variables[m],"struct")==0||strcmp(variables[m],"switch")==0||strcmp(variables[m],"typedef")==0||strcmp(variables[m],"union")==0||strcmp(variables[m],"unsigned")==0||
       strcmp(variables[m],"void")==0||strcmp(variables[m],"volatile")==0||strcmp(variables[m],"while")==0||strcmp(variables[m],"include")==0)
   {

    printf("%s\t",variables[m]);
    printf("\tKeyword\n\n");




   }

  else if(strcmp(variables[m],"stdio")==0|| strcmp(variables[m],"conio")==0)
  {
       printf("%s\t",variables[m]);
    printf("\tHeaderFile\n\n");
  }




   else if(strcmp(variables[m],"scanf")==0|| strcmp(variables[m],"printf")==0)
   {
       printf("%s",variables[m]);
    printf("\tLibrary Function\n\n");
   }















    else if(variables[m][0]=='\0')
            {
              printf("\n");
            }


   else
   {
    printf("%s\t",variables[m]);
    printf("\tVariable\n\n");





    }




m++;

arrayPos2=0;
k=-1;


}


if(expr[i]=='='&&expr[i+1]=='=')
{
    printf("%c%c\t\t Comparative operator Equal\n",expr[i],expr[i+1]);
    i=i+2;
}

if(expr[i]=='>'&&expr[i+1]=='=')
{
    printf("%c%c\t\t Comparative operator Greater Than\n",expr[i],expr[i+1]);
    i=i+2;
}

if(expr[i]=='<'&&expr[i+1]=='=')
{
    printf("%c%c\t\t Comparative operator Less than\n",expr[i],expr[i+1]);
    i=i+2;
}

if(expr[i]=='!'&&expr[i+1]=='=')
{
    printf("%c%c\t\t Comparative operator\n",expr[i],expr[i+1]);
    i=i+2;
}

if(expr[i]=='+'||expr[i]=='-'||expr[i]=='/'|| expr[i]=='*'||  expr[i]=='^'||expr[i]=='>'||expr[i]=='<')

{

     if(expr[i]=='*'&&(expr[i-1]=='\n'||expr[i-1]==';'|| expr[i-1]==','|| expr[i-1]==' '))
     {
l++;
operators[l]= expr[i];
     }
     else
     {



l++;
operators[l]= expr[i];


/*int s=0;

int p=0;
for(p=l-1;p>=0;p--)
{
    if(operators[l]==operators[p])
    {
         s=1;
         break;
    }
}
if(s==0)
*/
printf("\n%c\t\tOperator\n",operators[l]);
     }

}

if(expr[i]=='=')
{

    printf("%c\t\tAssignment Operator\n",expr[i]);
}




if(expr[i]=='('||expr[i]==')'||expr[i]=='{'|| expr[i]=='}'|| expr[i]=='['|| expr[i]==']')
    {

    parenth++;
    paren[parenth]=expr[i];
    printf("%c\t\tparenthesis\n",paren[parenth]);


    }

if(expr[i]==',')
    {



    if(expr[i-1]==',')
    {
        printf("\n error with comma\n");
    }
    else
    {
         printf("%c\t\tcomma\n",expr[i]);
    }


    }





if(expr[i]==';'||expr[i]=='\n')

 {variables[m][0]=';';
 variables[m][1]='\0';

            printf("%s\t",variables[m]);
    printf("\tSemicolon\n\n");
    m++;
            }









}


printf("\n\n\tSymbol Table\n\n");
printf("\t**********************\n\n\n");
printf("\tId\tName\ttype");
int count=m;
int id=0;
int syn;
int undeclared=m;
//printf("\n\n\n %d",count);
for(m=0;m<count;m++)
{ uu=0;
    if(strcmp(variables[m],"int")==0 &&strcmp(variables[m+1],"main")!=0)
    {
        while(variables[m+1][0]!=';')
        {uu=0;
           int scr=0;
           while(variables[m+1][scr]!='\0')
           {
               table[pos][scr]=variables[m+1][scr];
               scr++;
           }
           pos++;


            int pos1=pos-1;

            for(int y=pos;y>=0;y--)
            {
                if(strcmp(table[pos1],table[y-2])==0)
                {
                    printf("\n%s\t\t Eroor\n",table[pos1]);
                    pos--;
                    //table[pos1][0]='\0';
                    variables[m+1][0]='\0';
                    uu=1;
                    break;

                }
            }




            type[m+1][0]='i';
            type[m+1][1]='n';
            type[m+1][2]='t';
       int cc=0;
       while(variables[m+1][cc]!='\0')
       {
           if(variables[m+1][0]=='*')
           {
            variables[m+1][0]=' ';
            type[m+1][3]=' ';
            type[m+1][4]='p';
            type[m+1][5]='o';
            type[m+1][6]='i';
            type[m+1][7]='n';
            type[m+1][8]='t';
            type[m+1][9]='e';
            type[m+1][10]='r';
            type[m+1][11]='\0';
            break;
           }




            if(variables[m+1][cc]=='[')
           {
            type[m+1][3]=' ';
            type[m+1][4]='a';
            type[m+1][5]='r';
            type[m+1][6]='r';
            type[m+1][7]='a';
            type[m+1][8]='y';
            type[m+1][9]='\0';
            break;

           }





           else{ cc++;}
       }

       if(strcmp(variables[m+1],"main")==0||
               strcmp(variables[m+1],"int")==0|| strcmp(variables[m+1],"main")==0||strcmp(variables[m+1],"float")==0||strcmp(variables[m+1],"char")==0||strcmp(variables[m+1],"if")==0||
       strcmp(variables[m+1],"else")==0||strcmp(variables[m+1],"for")==0||strcmp(variables[m+1],"auto")==0||strcmp(variables[m+1],"break")==0||strcmp(variables[m+1],"const")==0||
       strcmp(variables[m+1],"double")==0||strcmp(variables[m+1],"case")==0||strcmp(variables[m+1],"continue")==0||strcmp(variables[m+1],"default")==0||strcmp(variables[m+1],"do")==0||
       strcmp(variables[m+1],"enum")==0||strcmp(variables[m+1],"extern")==0||strcmp(variables[m+1],"goto")==0||strcmp(variables[m+1],"long")==0||strcmp(variables[m+1],"register")==0||
       strcmp(variables[m+1],"return")==0||strcmp(variables[m+1],"short")==0||strcmp(variables[m+1],"signed")==0||strcmp(variables[m+1],"sizeof")==0||strcmp(variables[m+1],"static")==0||
       strcmp(variables[m+1],"struct")==0||strcmp(variables[m+1],"switch")==0||strcmp(variables[m+1],"typedef")==0||strcmp(variables[m+1],"union")==0||strcmp(variables[m+1],"unsigned")==0||
       strcmp(variables[m+1],"void")==0||strcmp(variables[m+1],"volatile")==0||strcmp(variables[m+1],"while")==0||strcmp(variables[m+1],"include")==0)
           {
         m++;

           }

           else if(uu==1)
           {
               //id--;
               m++;
           }
       else {

            id++;
            printf("\n\tid%d \t%s \t %s",id,variables[m+1],type[m+1]);
            m++;
        }
        }
    }






    else if(strcmp(variables[m],"float")==0 &&strcmp(variables[m+1],"main")!=0)
    {

    while(variables[m+1][0]!=';')
        { uu=0;
           int scr=0;
           while(variables[m+1][scr]!='\0')
           {
               table[pos][scr]=variables[m+1][scr];
               scr++;
           }
               pos++;

 int pos1=pos-1;

            for(int y=pos;y>=0;y--)
            {
                if(strcmp(table[pos1],table[y-2])==0)
                {
                    printf("\n%s\t\t Eroor",table[pos1]);
                    table[pos1][0]='\0';
                    variables[m+1][0]='\0';
                    uu=1;
                    break;

                }
            }










            type[m+1][0]='f';
            type[m+1][1]='l';
            type[m+1][2]='o';
            type[m+1][3]='a';
            type[m+1][4]='t';
       int cc=0;
       while(variables[m+1][cc]!='\0')
       {

           if(variables[m+1][0]=='*')
           {
            variables[m+1][0]=' ';
            type[m+1][5]=' ';
            type[m+1][6]='p';
            type[m+1][7]='o';
            type[m+1][8]='i';
            type[m+1][9]='n';
            type[m+1][10]='t';
            type[m+1][11]='e';
            type[m+1][12]='r';
            type[m+1][13]='\0';
            break;
           }



           if(variables[m+1][cc]=='[')
           {
               type[m+1][5]=' ';
            type[m+1][6]='a';
            type[m+1][7]='r';
            type[m+1][8]='r';
            type[m+1][9]='a';
            type[m+1][10]='y';
            type[m+1][11]='\0';
            break;
           }





           else{ cc++;}
       }


     if(strcmp(variables[m+1],"main")==0||
               strcmp(variables[m+1],"int")==0|| strcmp(variables[m+1],"main")==0||strcmp(variables[m+1],"float")==0||strcmp(variables[m+1],"char")==0||strcmp(variables[m+1],"if")==0||
       strcmp(variables[m+1],"else")==0||strcmp(variables[m+1],"for")==0||strcmp(variables[m+1],"auto")==0||strcmp(variables[m+1],"break")==0||strcmp(variables[m+1],"const")==0||
       strcmp(variables[m+1],"double")==0||strcmp(variables[m+1],"case")==0||strcmp(variables[m+1],"continue")==0||strcmp(variables[m+1],"default")==0||strcmp(variables[m+1],"do")==0||
       strcmp(variables[m+1],"enum")==0||strcmp(variables[m+1],"extern")==0||strcmp(variables[m+1],"goto")==0||strcmp(variables[m+1],"long")==0||strcmp(variables[m+1],"register")==0||
       strcmp(variables[m+1],"return")==0||strcmp(variables[m+1],"short")==0||strcmp(variables[m+1],"signed")==0||strcmp(variables[m+1],"sizeof")==0||strcmp(variables[m+1],"static")==0||
       strcmp(variables[m+1],"struct")==0||strcmp(variables[m+1],"switch")==0||strcmp(variables[m+1],"typedef")==0||strcmp(variables[m+1],"union")==0||strcmp(variables[m+1],"unsigned")==0||
       strcmp(variables[m+1],"void")==0||strcmp(variables[m+1],"volatile")==0||strcmp(variables[m+1],"while")==0||strcmp(variables[m+1],"include")==0)
           {
         m++;

           }
else if(uu==1)
           {
               //id--;
               m++;
           }
           else
           {


            id++;
            printf("\n\tid%d \t%s \t %s",id,variables[m+1],type[m+1]);
            m++;
           }
        }

    }




    else if(strcmp(variables[m],"char")==0 &&strcmp(variables[m+1],"main")!=0)
    {

      while(variables[m+1][0]!=';')
        { uu=0;
           int scr=0;
           while(variables[m+1][scr]!='\0')
           {
               table[pos][scr]=variables[m+1][scr];
               scr++;
           }
           pos++;

 int pos1=pos-1;

            for(int y=pos;y>=0;y--)
            {
                if(strcmp(table[pos1],table[y-2])==0)
                {
                    printf("\n%s\t\t Eroor",table[pos1]);
                    table[pos1][0]='\0';
                    variables[m+1][0]='\0';
                    uu=1;
                    break;

                }
            }







            type[m+1][0]='c';
            type[m+1][1]='h';
            type[m+1][2]='a';
            type[m+1][3]='r';

       int cc=0;
       while(variables[m+1][cc]!='\0')
       {
           if(variables[m+1][0]=='*')
           {
            variables[m+1][0]=' ';
            type[m+1][4]=' ';
            type[m+1][5]='p';
            type[m+1][6]='o';
            type[m+1][7]='i';
            type[m+1][8]='n';
            type[m+1][9]='t';
            type[m+1][10]='e';
            type[m+1][11]='r';
            type[m+1][12]='\0';
            break;
           }





           if(variables[m+1][cc]=='[')
           {
               type[m+1][5]=' ';
            type[m+1][5]='a';
            type[m+1][6]='r';
            type[m+1][7]='r';
            type[m+1][8]='a';
            type[m+1][9]='y';
            type[m+1][10]='\0';
            break;
           }


            if(strcmp(variables[m+1],"main")==0)
           {
            m++;
            break;
           }


           else{ cc++;}
       }

     if(strcmp(variables[m+1],"main")==0||
               strcmp(variables[m+1],"int")==0|| strcmp(variables[m+1],"main")==0||strcmp(variables[m+1],"float")==0||strcmp(variables[m+1],"char")==0||strcmp(variables[m+1],"if")==0||
       strcmp(variables[m+1],"else")==0||strcmp(variables[m+1],"for")==0||strcmp(variables[m+1],"auto")==0||strcmp(variables[m+1],"break")==0||strcmp(variables[m+1],"const")==0||
       strcmp(variables[m+1],"double")==0||strcmp(variables[m+1],"case")==0||strcmp(variables[m+1],"continue")==0||strcmp(variables[m+1],"default")==0||strcmp(variables[m+1],"do")==0||
       strcmp(variables[m+1],"enum")==0||strcmp(variables[m+1],"extern")==0||strcmp(variables[m+1],"goto")==0||strcmp(variables[m+1],"long")==0||strcmp(variables[m+1],"register")==0||
       strcmp(variables[m+1],"return")==0||strcmp(variables[m+1],"short")==0||strcmp(variables[m+1],"signed")==0||strcmp(variables[m+1],"sizeof")==0||strcmp(variables[m+1],"static")==0||
       strcmp(variables[m+1],"struct")==0||strcmp(variables[m+1],"switch")==0||strcmp(variables[m+1],"typedef")==0||strcmp(variables[m+1],"union")==0||strcmp(variables[m+1],"unsigned")==0||
       strcmp(variables[m+1],"void")==0||strcmp(variables[m+1],"volatile")==0||strcmp(variables[m+1],"while")==0||strcmp(variables[m+1],"include")==0)
           {
         m++;

           }
else if(uu==1)
           {
               //id--;
               m++;
           }
           else
           {


            id++;
            printf("\n\tid%d \t%s \t %s",id,variables[m+1],type[m+1]);
            m++;
        }


        }

    }
}









for(int y=0;y<m;y++)
{ int nn1=0;

    if(strcmp(variables[y],"int")!=0&& strcmp(variables[y],"main")!=0&&strcmp(variables[y],"float")!=0&&strcmp(variables[y],"char")!=0&&strcmp(variables[y],"if")!=0&&
       strcmp(variables[y],"else")!=0&&strcmp(variables[y],"for")!=0&&strcmp(variables[y],"auto")!=0&&strcmp(variables[y],"break")!=0&&strcmp(variables[y],"const")!=0&&
       strcmp(variables[y],"double")!=0&&strcmp(variables[y],"case")!=0&&strcmp(variables[y],"continue")!=0&&strcmp(variables[y],"default")!=0&&strcmp(variables[y],"do")!=0&&
       strcmp(variables[y],"enum")!=0&&strcmp(variables[y],"extern")!=0&&strcmp(variables[y],"goto")!=0&&strcmp(variables[y],"long")!=0&&strcmp(variables[y],"register")!=0&&
       strcmp(variables[y],"return")!=0&&strcmp(variables[y],"short")!=0&&strcmp(variables[y],"signed")!=0&&strcmp(variables[y],"sizeof")!=0&&strcmp(variables[y],"static")!=0&&
       strcmp(variables[y],"struct")!=0&&strcmp(variables[y],"switch")!=0&&strcmp(variables[y],"typedef")!=0&&strcmp(variables[y],"union")!=0&&strcmp(variables[y],"unsigned")!=0&&
       strcmp(variables[y],"void")!=0&&strcmp(variables[y],"volatile")!=0&&strcmp(variables[y],"while")!=0&&strcmp(variables[y],"include")!=0&&strcmp(variables[y],"stdio")!=0&&strcmp(variables[y],"conio")!=0&&strcmp(variables[y],";")!=0)
       {
        for(int nn=0;nn<pos;nn++)
        { nn1=0;
            if(strcmp(variables[y],table[nn])==0)
            {
             nn1=1;
             break;
            }
        }
        if(nn1==0)
        {
            printf("\n\n\n %s not declared variable at line %d\n",variables[y],variablepos[y]);
            //printf("\n\n%d",newlinecounter);
        }
       }
}




//


}

else
{
    printf("\n\n\n *****Invalid Start of code!!!!****\n");



}


int lineCounter=0;
int bracketPosition[100];
cnt = strlen(expr);
int pp=0;
int pp1=0;
int bracketCounter=0;
int firstbracketcounter=0;
int firstbracketpos[100];
int semicolCounterunderfor=0;






for(i = 0; i < cnt; ++i)

{
    if(expr[i]=='\n')
    {
        lineCounter++;
    }


    if(expr[i]==',')
    {



    if(expr[i-1]==',')
    {
        printf("\n error with comma at line %d\n",lineCounter+1);
    }
    else
    {
         //printf("%c\t\tcomma\n",expr[i]);

    }


    }


    if(expr[i]=='*'&&expr[i+1]=='*')
    {

        printf("\n Error of expression at line %d",lineCounter+1);
    }

    if(expr[i]=='\n' &&(expr[i-1]!=';'&& expr[i-1]!=')'&&expr[i-1]!='\n'&&expr[i-1]!='{'&&expr[i-1]!='}'&&expr[i-1]!='>'))
    {
     if(expr[i-1]=='e'&&expr[i-2]=='s'&&expr[i-3]=='l'&&expr[i-4]=='e')
     {

     }
     else
        printf("\n no semicolon in  line no %d",lineCounter);
    }

if(expr[i]=='{')
    {
        bracketCounter++;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

    if(expr[i]=='}')
    {
        bracketCounter--;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

    if(expr[i]=='f'&&expr[i+1]=='o'&&expr[i+2]=='r')
    { i=i+3;
     if(expr[i]=='{')
    {
        bracketCounter++;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

    if(expr[i]=='}')
    {
        bracketCounter--;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }
        while(expr[i]!='(')
        {
if(expr[i]=='{')
    {
        bracketCounter++;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

    if(expr[i]=='}')
    {
        bracketCounter--;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

        if(expr[i]=='\n')
        {
            lineCounter++;
        }
        if(expr[i]!=' '&&expr[i]!='(')
        {
            printf("\n Eroor for loop at line %d",lineCounter);
            break;


        }
        i++;
        if(i==cnt)
        {
            break;
        }
        }

        if(expr[i]=='(')
        {
            i++;
            while(expr[i]!=')')
            {
if(expr[i]=='{')
    {
        bracketCounter++;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

    if(expr[i]=='}')
    {
        bracketCounter--;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }
            if(expr[i]=='\n')
          {

              lineCounter++;
              break;
          }
        if(expr[i]==';')
        {
        semicolCounterunderfor++;
        }
        i++;


            }


        }
        if(expr[i]!=')')
        {
            printf("\nerror for bracket for loop");
        }

        if(expr[i]==')')
        {
            if(semicolCounterunderfor!=2)
            {
                printf("\nEror of semicolons in for loop");
            }


        }


    }


    if(expr[i]=='i' && expr[i+1]=='f')
    {
        int ifloc=lineCounter+1;
         i=i+2;
         if(expr[i]=='{')
    {
        bracketCounter++;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

    if(expr[i]=='}')
    {
        bracketCounter--;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

        while(expr[i]!='(')
        {
            if(expr[i]=='\n')
            {
                lineCounter++;
            }
            if(expr[i]!='\n' && expr[i]!=' '&& expr[i]!='(')
            {
                printf("\n bracket missing for if at line %d",ifloc);
                break;
            }
            if(i==cnt)
            {
                break;
            }
            i++;
        }
        if(expr[i]=='(')
        {
            i++;
            while(expr[i]!=')')
            {

            if(expr[i]=='\n')
          {

              lineCounter++;
              break;
          }



        i++;


            }


        }
        if(expr[i]==')'&& expr[i-1]=='(')
        {
            printf("\n\n no expression in if\n\n");
        }
        if(expr[i]!=')')
        {
            printf("\nerror for bracket if condition");
        }

        if(expr[i]==')')
        {
            if(semicolCounterunderfor!=2)
            {
                //printf("\nEror of semicolons in if condition loop");
            }


        }




    }


    if(expr[i]=='w' && expr[i+1]=='h'&& expr[i+2]=='i'&& expr[i+3]=='l'&& expr[i+4]=='e')
    {
        int ifloc=lineCounter+1;
         i=i+5;

         if(expr[i]=='{')
    {
        bracketCounter++;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

    if(expr[i]=='}')
    {
        bracketCounter--;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

        while(expr[i]!='(')
        {
            if(expr[i]=='\n')
            {
                lineCounter++;
            }
            if(expr[i]!='\n' && expr[i]!=' '&& expr[i]!='(')
            {
                printf("\n bracket missing for while at line %d",ifloc);
                break;
            }
            if(i==cnt)
            {
                break;
            }
            i++;
        }
        if(expr[i]=='(')
        {
            i++;
            while(expr[i]!=')')
            {

            if(expr[i]=='\n')
          {

              lineCounter++;
              break;
          }



        i++;


            }


        }
        if(expr[i]==')'&& expr[i-1]=='(')
        {
            printf("\n\n no expression in while\n\n");
        }
        if(expr[i]!=')')
        {
            printf("\nerror for bracket while condition");
        }

        if(expr[i]==')')
        {
            if(semicolCounterunderfor!=2)
            {
                //printf("\nEror of semicolons in if condition loop");
            }


        }




    }

    if(expr[i]=='d'&&expr[i+1]=='o')
    {i=i+2;
     while(expr[i]!='w'&&expr[i+1]!='h'&&expr[i+2]!='i'&&expr[i+3]!='l'&&expr[i+4]!='e')
     {
          if(expr[i]=='i' && expr[i+1]=='f')
    {
        int ifloc=lineCounter+1;
         i=i+2;
         if(expr[i]=='{')
    {
        bracketCounter++;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

    if(expr[i]=='}')
    {
        bracketCounter--;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

        while(expr[i]!='(')
        {
            if(expr[i]=='\n')
            {
                lineCounter++;
            }
            if(expr[i]!='\n' && expr[i]!=' '&& expr[i]!='(')
            {
                printf("\n bracket missing for if at line %d",ifloc);
                break;
            }
            if(i==cnt)
            {
                break;
            }
            i++;
        }
        if(expr[i]=='(')
        {
            i++;
            while(expr[i]!=')')
            {

            if(expr[i]=='\n')
          {

              lineCounter++;
              break;
          }



        i++;


            }


        }
        if(expr[i]==')'&& expr[i-1]=='(')
        {
            printf("\n\n no expression in if\n\n");
        }
        if(expr[i]!=')')
        {
            printf("\nerror for bracket if condition");
        }

        if(expr[i]==')')
        {
            if(semicolCounterunderfor!=2)
            {
                //printf("\nEror of semicolons in if condition loop");
            }


        }




    }
         if(expr[i]=='{')
    {
        bracketCounter++;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

    if(expr[i]=='}')
    {
        bracketCounter--;
        bracketPosition[pp]=lineCounter+1;
        pp++;
    }

         i++;
     }
     if(expr[i]!='w'&&expr[i+1]!='h'&&expr[i+2]!='i'&&expr[i+3]!='l'&&expr[i+4]!='e')
     {
         printf("\n No while for do condition\n\n\n");
     }
    }





}
 if(bracketCounter==1)
    {
        //printf("\n\n\nNo error with bracket");
        printf("\n\n\nBracket Problem at line %d",lineCounter);
    }
    if(bracketCounter>0 && bracketCounter!=1)
    {

        for(i=bracketCounter;i>0;i--)
        {
             printf("\n\n\nBracket Problem at line %d",bracketPosition[pp-i]);

        }
    }
        if(bracketCounter<0)
    {
        for(i=bracketCounter;i<0;i++)
{


             printf("\n\n\nBracket Problem at line %d",bracketPosition[pp+i]);

        }
    }



   printf("\n\n%d\n\n",lineCounter);
   lineCounter=0;


    for(i = 0; i < cnt; ++i)
    {
        firstbracketcounter==0;
        while(expr[i]!='\n')
        {
            if(expr[i]=='(')
            {
                firstbracketcounter++;
            }
            if(expr[i]==')')
            {
                firstbracketcounter--;
            }
            i++;
        }
        i++;
        lineCounter++;
        if(firstbracketcounter<0)
        {
            printf(" bracket ) is more at line %d\n",lineCounter);
            firstbracketcounter=0;
        }
         if(firstbracketcounter>0)
        {
            printf(" bracket ( is more at line %d\n",lineCounter);
            firstbracketcounter=0;
        }
    }







}


















//




