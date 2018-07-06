#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count = 0, vowel = 0;
int ModifyFile(FILE* fp)
{
    char ch = fgetc(fp);

    FILE *cp;

    int NumberOfSentence = 0;
    cp = fopen("mod.txt","w");
    while(ch!= EOF)
    {
        while(ch != '.' && ch!= '?' && ch != '!' && ch!= '(' && ch!= '[' && ch!= ',')
        {
            fputc(ch,cp);
            ch = fgetc(fp);
            if(ch == 'M')
            {
                fputc(ch,cp);
                ch = fgetc(fp);
                 if(ch == 'r'){

                    fputc(ch,cp);
                    ch = fgetc(fp);
                    if(ch == 's')
                    {
                        if( ch == '.')
                    {
                       fputc(' ',cp);
                      ch = fgetc(fp);
                    }
                    }
                    else if( ch == '.')
                    {
                       fputc(' ',cp);
                      ch = fgetc(fp);
                    }
                 }


            }

        }
        if( ch == '(' || ch == '[' || ch == ',')
        {
           fputc(' ',cp);
           fputc(ch,cp);
           ch = fgetc(fp);

        }
        if(ch == '.' || ch== '?' || ch == '!' ){

            fputc(ch,cp);
            fputs(" ",cp);
            ch = fgetc(fp);
            NumberOfSentence++;
        }
    }
    //printf("No of Senetnce = %d\n\n\n",NumberOfSentence);
    fclose(cp);
    return NumberOfSentence;
}


 int counter(char rd1[])
    {
           int i = 0;
           count = 0;
           vowel = 0;
         while(rd1[i]!='\0')
         {
             if(rd1[i]=='a'|| rd1[i]=='e'|| rd1[i]=='i'|| rd1[i]=='o'|| rd1[i]=='u' || rd1[i]=='A'|| rd1[i]=='E'|| rd1[i]=='I'|| rd1[i]=='O'|| rd1[i]=='U')
             {
               vowel++;
                if(rd1[i+1]!='a'&& rd1[i+1]!='e'&& rd1[i+1]!='i'&& rd1[i+1]!='o'&& rd1[i+1]!='u' && rd1[i+1]!='\0' && rd1[i+1]!='A'&& rd1[i+1]!='E'&& rd1[i+1]!='I'&& rd1[i+1]!='O'&& rd1[i+1]!='U')
                    count++;
             }
             if(rd1[i]!='\0')
             i++;
         }
         return count;
         //printf(" %d\n",count);
    }
int CountWord(FILE *n2)
{
    int j,k,l;
    count = 0;
    char n;
    n=fgetc(n2);
 while(n!=EOF)
 {
     j=0;
                                k=0;
                                l=0;
                                while(n!='\n' && n!=' ' && n!='\t' && n!=EOF && n!='.' && n!=':' && n!='(' && n!=')' && n!= '"' && n!= ',' && n!= ';')
                                {
                                    n=fgetc(n2);
                                }
                                j++;
                                while(n=='\n' || n==' ' || n=='\t' || n=='.' || n==':' || n=='(' || n==')' || n== '"' || n== ',' || n== ';')
                                {
                                    n=fgetc(n2);
                                }
                                count=count+j;//counting word in  file
 }
 fclose(n2);
 return count;
}
void StopWord(FILE *fp, FILE *wr)
{
FILE *st,*n2;
int c,i,j,k,l,m,count=0,p,u,flag=0;;
char ch,ch2,stop[100],str[100],n,wr1[100];
ch=fgetc(fp);
    //printf("\n\tbefore remove the stop word:\t\n");
while(ch!=EOF)
{
    flag=0;
    i=0;
    c=0;
    j=0;
    str[i]='\0';
    while(ch!=' ' && ch!='\n' && ch!='\t' && ch!=EOF)
    {
        if(ch == '"' || ch == '.' || ch == ',' || ch == ';' || ch == ':')
        {
          ch=fgetc(fp);
        }
         if (ch!=' ' && ch!='\n' && ch!='\t' && ch!=EOF)
         {
        str[i]=ch;
        i++;
        c++;
        ch=fgetc(fp);
         }
    }
    str[i]='\0';
    j++;
    while(ch==' ' || ch=='\t' || ch=='\n')
    {
        j=1;
        ch=fgetc(fp);
    }
        st = fopen("stopword.txt", "r");
        ch2=fgetc(st);

                                while(ch2!=EOF)
                            {
                                k=0;
                                l=0;
                                while(ch2!='\n' && ch2!=' ' && ch2!='\t' && ch2!=EOF)
                                {
                                    stop[k]=ch2;
                                    k++;
                                    l++;
                                    ch2=fgetc(st);
                                }
                                while(ch2==' ' || ch2=='\t' || ch2=='\n')
                                {
                                    ch2=fgetc(st);
                                }
                                if(strcmp(stop,str)==0)
                                {
                                    flag=1;
                                }
                            for(k=0;k<=l;k++)
                                {
                                    stop[k]='\0';
                                }
                            }
                             fclose(st);
                if(flag==0)
                        {
                            fputs(str,wr);
                            fputs("\n",wr);
                        }
//printf("%s\n",str);
}
 count =0; //used for counting the number of word in file
fclose(wr);
 fclose(fp);
// printf("\n\tafter remove stop words the file is :\t\n");
 n2=fopen("new.txt","r");
 n=fgetc(n2);
 for(i=0;i<100;i++)
 {
     wr1[i]='\0';
 }
 while(n!=EOF)
 {

                                k=0;
                                l=0;
                                while(n!='\n' && n!=' ' && n!='\t' && n!=EOF)
                                {
                                    wr1[k]=n;
                                    k++;
                                    l++;
                                    n=fgetc(n2);
                                }
                                while(n==' ' || n=='\t' || n=='\n')
                                {
                                    n=fgetc(n2);

                                }
                                 //printf("%s",wr1);

                                for(k=0;k<=l;k++)
                                {
                                    wr1[k]='\0';
                                }
                               // printf(" \n");

 }
 fclose(n2);
//count = 0;
 //n2=fopen("new.txt","r");
 //count = count_word(n2);
 //printf("after remove stop word %d word present",count);
fclose(n2);
}
void beuty(FILE *fp,FILE *cp)
{
  FILE *step_2,*step_1,*rd,*wr,*rd_last,*write,*fi,*st,*n2;

    wr = fopen("STOP_WORD_REMOVED.txt","w");
    int c,i,j,k,l,m,count=0,p,u,flag=0;;
    char ch,ch2,stop[100],str[100],n,wr1[100];
    ch=fgetc(fp);
    //printf("\n\tbefore remove the stop word:\t\n");
while(ch!=EOF)
{
    flag=0;
    i=0;
    c=0;
    j=0;
    str[i]='\0';
    // remove bracketed sentence
    if(ch == '(' || ch == '[')
    {
        while(ch != ')' && ch != ']' )
        {
          ch=fgetc(fp);
        }
        ch=fgetc(fp);
    }
    while(ch==' ' || ch=='\t' || ch=='\n')
    {
        j=1;
        ch=fgetc(fp);
    }
    while(ch!=' ' && ch!='\n' && ch!='\t' && ch!=EOF)
    {
        if(ch == '"' || ch == '.' || ch == ',' || ch == ';' || ch == ':')
        {
          ch=fgetc(fp);
        }

        if(ch == '(' || ch == '[')
    {
        while(ch != ')' && ch != ']' )
        {
          ch=fgetc(fp);
        }
        ch=fgetc(fp);
    }

         if (ch!=' ' && ch!='\n' && ch!='\t' && ch!=EOF)
         {
        str[i]=ch;
        i++;
        c++;
        ch=fgetc(fp);
         }

    }
    str[i]='\0';
    j++;
    while(ch==' ' || ch=='\t' || ch=='\n')
    {
        j=1;
        ch=fgetc(fp);
    }
        st = fopen("stopword.txt", "r");
        ch2=fgetc(st);

                                while(ch2!=EOF)
                            {
                                k=0;
                                l=0;

                                while(ch2!='\n' && ch2!=' ' && ch2!='\t' && ch2!=EOF)
                                {
                                    stop[k]=ch2;
                                    k++;
                                    l++;
                                    ch2=fgetc(st);
                                }
                                while(ch2==' ' || ch2=='\t' || ch2=='\n')
                                {
                                    ch2=fgetc(st);
                                }
                                if(strcmp(stop,str)==0)
                                {
                                    flag=1;
                                }
                            for(k=0;k<=l;k++)
                                {
                                    stop[k]='\0';
                                }
                            }
                             fclose(st);
                if(flag==0)
                        {
                            fputs(str,wr);
                            fputs("\n",wr);
                        }
//printf("%s\n",str);
}
 count =0; //used for counting the number of word in file
fclose(wr);
 fclose(fp);
// printf("\n\tafter remove stop words the file is :\t\n");
 n2=fopen("STOP_WORD_REMOVED.txt","r");
 n=fgetc(n2);
 for(i=0;i<100;i++)
 {
     wr1[i]='\0';
 }
 while(n!=EOF)
 {

                                k=0;
                                l=0;
                                while(n!='\n' && n!=' ' && n!='\t' && n!=EOF)
                                {
                                    wr1[k]=n;
                                    k++;
                                    l++;
                                    n=fgetc(n2);
                                }
                                while(n==' ' || n=='\t' || n=='\n')
                                {
                                    n=fgetc(n2);

                                }
                                 //printf("%s",wr1);

                                for(k=0;k<=l;k++)
                                {
                                    wr1[k]='\0';
                                }
                               // printf(" \n");

 }
 fclose(n2);
//count = 0;
 //n2=fopen("new.txt","r");
 //count = count_word(n2);
 //printf("after remove stop word %d word present",count);
fclose(n2);
wr1[0]='\0';
str[0] = '\0';
j = 0, p = 0,flag = 0,i = 0;
int   len = 0, len2= 0, match = 0;
         wr = fopen("After.txt","w");
         rd = fopen("STOP_WORD_REMOVED.txt","r");
         step_1 = fopen("step_1.txt","r");
         char ch_step_1,ch_step_2,srd1[100],rd1[100],str2[20];
         ch_step_1 = fgetc(step_1);
         ch2 = fgetc(rd);
         srd1[0]='\0';
         wr1[0]='\0';
         while(ch2 != EOF)
         {
              i =0;
               rd1[i] ='\0';
             while(ch2!= '\n' && ch2 != EOF)
             {
                 rd1[i] = ch2;
                 i++;
                 ch2 = fgetc(rd);

             }
             rd1[i] ='\0';
             count = counter(rd1);



             /*******************porter stemming #step_1a_1b starting***************************/

                  while( ch_step_1!= EOF && match == 0)
             {
             i = 0;
             while(ch_step_1 != '\n' && ch_step_1 != EOF)
             {
                   srd1[i] = ch_step_1;
                   i++;
                  ch_step_1 = fgetc(step_1);
             }
                  srd1[i] = '\0';
                  i= 0;
                      while(srd1[i] != ':')
                      {
                          str[i] = srd1[i];
                          i++;
                      }
                      str[i] = '\0';
                      i++;
                      j= 0;
                      while(srd1[i]!= '\0')
                      {
                          str2[j]= srd1[i];
                          j++;
                          i++;
                      }
                       str2[j] = '\0';
                       len = strlen(str);
                       len2 = strlen(rd1);
                       flag = 0;
                       if(len2>len){

                       p = i = len2-len;
                       j = 0;
                       char cmp[len+2];
                       while(rd1[i]!='\0' )
                       {
                           cmp[j] = rd1[i];
                           i++;
                           j++;
                       }
                       cmp[j]='\0';
                       j = 0;
                           if(strcmp(cmp,str) == 0)
                           {
                               if (((strcmp(str,"eed")== 0) && count == 1) || ((strcmp(str,"ed")== 0) && vowel == 1) || ((strcmp(str,"ing")== 0) && vowel == 1) || (count == 3 && ((strcmp(str,"ational")==0) || (strcmp(str,"tional")==0))))
                               {
                                 flag = 1;
                                 match = 1;
                               }

                               if(flag == 0)
                                {

                                      while(str2[j]!='\0')
                                      {

                                            rd1[p] = str2[j];

                                            p++;
                                            j++;
                                            match = 1;
                                      }
                                       rd1[p] = '\0';

                                    if(strcmp(str,"ed")==0)
                                    {
                                        len2 = len2 - 2;
                                        if((rd1[len2-2]=='a' && rd1[len2-1]=='t') || (rd1[len2-2]=='b' && rd1[len2-1]=='l') || (rd1[len2-2]=='i' && rd1[len2-1]=='z'))
                                        {
                                          rd1[p]='e';
                                          rd1[p+1] = '\0';
                                        }
                                        if( (rd1[len2-2]=='a' && rd1[len2-1]=='a') || (rd1[len2-2]=='b' && rd1[len2-1]=='b' )|| (rd1[len2-2]=='c' && rd1[len2-1]=='c' )|| (rd1[len2-2]=='d' && rd1[len2-1]=='d' )|| (rd1[len2-2]=='e' && rd1[len2-1]=='e' ) || (rd1[len2-2]=='f' && rd1[len2-1]=='f' ) || (rd1[len2-2]=='g' && rd1[len2-1]=='g' ) || (rd1[len2-2]=='h' && rd1[len2-1]=='h' ) || (rd1[len2-2]=='i' && rd1[len2-1]=='i' ) || (rd1[len2-2]=='j' && rd1[len2-1]=='j' ) || (rd1[len2-2]=='k' && rd1[len2-1]=='k' ) || (rd1[len2-2]=='m' && rd1[len2-1]=='m' ) || (rd1[len2-2]=='n' && rd1[len2-1]=='n' ) || (rd1[len2-2]=='o' && rd1[len2-1]=='o' ) || (rd1[len2-2]=='p' && rd1[len2-1]=='p' ) || (rd1[len2-2]=='q' && rd1[len2-1]=='q' ) || (rd1[len2-2]=='r' && rd1[len2-1]=='r' ) || (rd1[len2-2]=='t' && rd1[len2-1]=='t' ) || (rd1[len2-2]=='u' && rd1[len2-1]=='u' ) || (rd1[len2-2]=='v' && rd1[len2-1]=='v' ) || (rd1[len2-2]=='w' && rd1[len2-1]=='w' ) || (rd1[len2-2]=='x' && rd1[len2-1]=='x' ) || (rd1[len2-2]=='y' && rd1[len2-1]=='y' ) )
                                       {
                                          rd1[len2-1] = '\0';
                                       }
                                    }
                                    else if( strcmp(str,"ing")==0 )
                                    {
                                        len2 = len2 - 3;
                                       if( (rd1[len2-2]=='a' && rd1[len2-1]=='a') || (rd1[len2-2]=='b' && rd1[len2-1]=='b' )|| (rd1[len2-2]=='c' && rd1[len2-1]=='c' )|| (rd1[len2-2]=='d' && rd1[len2-1]=='d' )||(rd1[len2-2]=='e' && rd1[len2-1]=='e' ) || (rd1[len2-2]=='f' && rd1[len2-1]=='f' ) || (rd1[len2-2]=='g' && rd1[len2-1]=='g' ) || (rd1[len2-2]=='h' && rd1[len2-1]=='h' ) || (rd1[len2-2]=='i' && rd1[len2-1]=='i' ) || (rd1[len2-2]=='j' && rd1[len2-1]=='j' ) || (rd1[len2-2]=='k' && rd1[len2-1]=='k' ) || (rd1[len2-2]=='m' && rd1[len2-1]=='m' ) || (rd1[len2-2]=='n' && rd1[len2-1]=='n' ) || (rd1[len2-2]=='o' && rd1[len2-1]=='o' ) || (rd1[len2-2]=='p' && rd1[len2-1]=='p' ) || (rd1[len2-2]=='q' && rd1[len2-1]=='q' ) || (rd1[len2-2]=='r' && rd1[len2-1]=='r' ) || (rd1[len2-2]=='t' && rd1[len2-1]=='t' ) || (rd1[len2-2]=='u' && rd1[len2-1]=='u' ) || (rd1[len2-2]=='v' && rd1[len2-1]=='v' ) || (rd1[len2-2]=='w' && rd1[len2-1]=='w' ) || (rd1[len2-2]=='x' && rd1[len2-1]=='x' ) || (rd1[len2-2]=='y' && rd1[len2-1]=='y' ) )
                                       {
                                          rd1[len2-1] = '\0';
                                       }
                                       if( (rd1[len2-3]!='a'&& rd1[len2-3]!='e'&& rd1[len2-3]!='i'&& rd1[len2-3]!='o'&& rd1[len2-3]!='u') && (rd1[len2-2]=='a'|| rd1[len2-2]=='e'|| rd1[len2-2]=='i'|| rd1[len2-2]=='o'|| rd1[len2-2]=='u') && (rd1[len2-1]!='a'&& rd1[len2-1]!='e'&& rd1[len2-1]!='i'&& rd1[len2-1]!='o'&& rd1[len2-1]!='u') && count == 2)
                                       {
                                         rd1[len2]='e';
                                          rd1[len2+1] = '\0';
                                       }

                                    }
                                    else if(strcasecmp(str,"y") == 0)
                                    {
                                      if(vowel>=1)
                                      {
                                          rd1[len2-1] = 'i';
                                          rd1[len2] = '\0';
                                      }
                                      }


                               }

                           }
                       }

                  ch_step_1 = fgetc(step_1);
             }

            /*******ending of #step_1a_1b********/
                fclose(step_1);
                step_1 = fopen("step_1.txt","r");
                ch_step_1 = fgetc(step_1);
             match = 0;
             count = 0;
             vowel = 0;
             fputs(rd1,wr);
             fputs("\n",wr);
             ch2 = fgetc(rd);
         }
         fclose(step_1);
         fclose(rd);
         fclose(wr);

         rd_last = fopen("After.txt","r");
         step_2 = fopen("step_2.txt","r");
         write = fopen("after2.txt","w");

         ch_step_2 = fgetc(step_2);
         ch = fgetc(rd_last);

           while(ch != EOF)
         {
               i =0;
               rd1[i] ='\0';
             while(ch!= '\n' && ch != EOF)
             {
                 rd1[i] = ch;
                 i++;
                 ch = fgetc(rd_last);
             }
             rd1[i] ='\0';

             count = counter(rd1);

             while( ch_step_2!= EOF && match == 0)
             {
             i = 0;
             while(ch_step_2 != '\n' && ch_step_2 != EOF)
             {
                   srd1[i] = ch_step_2;
                   i++;
                  ch_step_2 = fgetc(step_2);
             }
                  srd1[i] = '\0';
                  i= 0;
                      while(srd1[i] != ':')
                      {
                          str[i] = srd1[i];
                          i++;
                      }
                      str[i] = '\0';
                      i++;
                      j= 0;
                      while(srd1[i]!= '\0')
                      {
                          str2[j]= srd1[i];
                          j++;
                          i++;
                      }
                       str2[j] = '\0';
                       len = strlen(str);
                       len2 = strlen(rd1);
                       flag = 0;
                       if(len2>len){
                       p = i = len2-len;
                       int k = p;
                       j = 0;
                       char cmp[len+2];
                       while(rd1[i]!='\0' )
                       {
                           cmp[j] = rd1[i];
                           i++;
                           j++;
                       }
                       cmp[j]='\0';
                       j = 0;
                       if((strcmp(cmp,str) == 0) && count>2)
                           {

                               while(str2[j]!='\0')
                           {

                                            rd1[p] = str2[j];

                                p++;
                                j++;
                                match = 1;
                           }
                            rd1[p] = '\0';
                           }
                       }
                  ch_step_2 = fgetc(step_2);
             }
                fclose(step_2);
                step_2 = fopen("step_2.txt","r");
                ch_step_2 = fgetc(step_2);
             match = 0;

             fputs(rd1,write);
             fputs("\n",write);
             ch = fgetc(rd_last);
           }
           fclose(wr);
           fclose(write);
           fclose(rd_last);
           fclose(step_2);
           wr = fopen("after2.txt","r");
           ch =fgetc(wr);
           while(ch!= EOF)
            {
            fputc(ch,cp);
            ch =fgetc(wr);
            }
            fclose(wr);
            remove("after2.txt");
            remove("After.txt");
}



void occurance(FILE *fp, FILE *wr)
    {
        FILE *cp,*cp2;
        char ch,ch2,arr[20],arr2[20];
        int i,j,count = 0;
        cp = fopen("cp.txt","w");
        ch = fgetc(fp);
        while(ch != EOF)
        {
            fputc(ch,cp);
            ch = fgetc(fp);
        }
        fclose(fp);
        fclose(cp);
        cp2 = fopen("ren.txt","w");
        cp = fopen("cp.txt","r");
        fp = fopen("BEUTY_FILE.txt","r");

        ch2 = fgetc(cp);
        ch = fgetc(fp);
        while(ch != EOF)
        {
            i = 0;
            count = 0;
            arr[i] = '\0';
            while(ch != '\n' && ch != EOF)
            {
                arr[i]=tolower(ch);
                i++;
                ch = fgetc(fp);
            }
            arr[i] = '\0';
            while(ch2 != EOF)
            {
            i = 0;
            arr2[i] = '\0';
              while(ch2 != '\n' && ch2 != EOF){

                arr2[i]=tolower(ch2);
                i++;
                ch2 = fgetc(cp);
            }
            arr2[i] = '\0';

              if(strcmp(arr,arr2)==0)
              {
                  count ++;

              }
              else
              {
                fputs(arr2,cp2);
                fputs("\n",cp2);
              }
               ch2 = fgetc(cp);
            }


            if(count>0) {

                fputs(arr,wr);
                fputs(":",wr);
                fprintf(wr, "%d", count);
                fputs("\n",wr);
            }
            fclose(cp);
            fclose(cp2);
           // remove("cp.txt");
            //rename("ren.txt","cp.txt");
            cp2 = fopen("ren.txt","w");
            cp = fopen("cp.txt","r");
            ch2 = fgetc(cp);
            ch = fgetc(fp);
        }
          fclose(cp);
            fclose(cp2);
        remove("ren.txt");
        remove("cp.txt");
        fclose(fp);
    }
   int SentencePos( FILE *fp,FILE *cp)
    {
        char ch;
        int pos = 0;
        ch = fgetc(fp);
        while(ch != EOF)
        {
            while(ch != '.' && ch != EOF && ch != '?' && ch != '!')
            {
                if(ch =='(' || ch == '[')
                {
                    while(ch !=')' && ch != ']')
                    {
                      fputc(ch,cp);
                      ch = fgetc(fp);
                    }
                }
                fputc(ch,cp);
                ch = fgetc(fp);
            }
           pos++;
           fputc('.',cp);
           //fprintf(cp, "%d", pos);
           fputc('\n',cp);
           ch = fgetc(fp);
           while(ch == ' ' || ch == '\n')
           ch = fgetc(fp);
        }
        fclose(fp);
        fclose(cp);
    }


    int TermFrequency(FILE *fp, FILE *cp,int word )
{
 char ch;
 float count = 0;
 ch = fgetc(cp);
 while(ch != EOF)
 {
  while( ch!= ':')
  {
     fputc(ch,fp);
     ch = fgetc(cp);
  }
  fputc(':',fp);
  count = 0;
  while(ch != '\n' && ch != EOF)
  {
   count = count*10 + (ch - '0');
   ch = fgetc(cp);
  }
  count = count / word;
  fprintf( fp, "%f", count);
  fputc('\n',fp);
  ch = fgetc(cp);
 }
}
int weight(FILE *fp, FILE *cp, int word)
{
    FILE *wr,*rd;
    char ch;
 float count = 0;
 cp = fopen("unique.txt","r");
 fp = fopen("termFrequency.txt","w");
 ch = fgetc(cp);
 while(ch != EOF)
 {
  while( ch!= ':')
  {
     fputc(ch,fp);
     ch = fgetc(cp);
  }
  fputc(':',fp);
  count = 0;
  while(ch != '\n' && ch != EOF)
  {
   count = count*10 + (ch - '0');
   ch = fgetc(cp);
  }
  count = count / word;
  fprintf( fp, "%f", count);
  fputc('\n',fp);
  ch = fgetc(cp);
 }

 fclose(cp);
 fclose(fp);

 float fl;
char ch2;
int c = 0,n = 153;
rd = fopen("weight.txt","w");
fp = fopen("termFrequency.txt","r");
wr = fopen("STOP_WORD_REMOVED.txt","r");
ch =fgetc(fp);
while(ch !=EOF){
        if(ch == '\n')
        {
           ch2  = fgetc(wr);
           while(ch2 != EOF && ch2 != '\n')
           {
               fputc(ch2,rd);
               ch2  = fgetc(wr);
           }
           fputc(':',rd);
        //  printf("%f",fl);
          fprintf(rd,"%f",fl);
          fputs("\n",rd);
          //printf("\n");

        }
fscanf(fp,"%f",&fl);
ch =fgetc(fp);

}
fclose(rd);
fclose(wr);
fclose(fp);
}

void sen_weight(FILE *fp,FILE *cp, int no_sentence)
    {
      FILE *wr;
      char str[50],str1[50];
      int i = 0,flag = 0;
      float fl = 0.0, sw = 0.0,d = 0.0,no_word = 0;
      wr = fopen("s_weight.txt","w");
      char ch,ch2;
      float *arr;
      int index = 1;
      arr = (float *)malloc(index * sizeof(float));
      ch = fgetc(cp);
      ch2 = fgetc(fp);
      while(ch != EOF)
      {
          i = 0;
          str[i] = '\0';
          while(ch != ':')
          {
               str[i] = ch;
               ch = fgetc(cp);
               i++;
               //fscanf(cp,"%f",&fl);
          }
           str[i] = '\0';
           while(ch != '\n' && ch != EOF)
           {
                  fscanf(cp,"%f",&fl);
                  ch = fgetc(cp);
           }

           if(ch == '\n')
           {
               d = fl;
               //printf("%f  = ",d);
               fl = 0;
               flag = 0;
               //printf("%s\n",str);
           }
           while(ch2 != EOF && flag == 0)
           {
               while(ch2 != '.' && ch2 != EOF && flag == 0)
               {
                   i = 0;
                   str1[i] = '\0';
                   while(ch2 != ' ' && ch2 != ':' && ch2 != ',' && ch2 != '?' && ch2!= '\n' && ch2 != EOF && ch2!= '.' && ch2 != '"' && ch2 != ';')
                   {
                       if(ch2 == '(' || ch == '[')
                       {
                           while(ch2 != ')' && ch != ']')
                           {
                             fputc(ch2,wr);
                             ch2 = fgetc(fp);

                           }

                           while(ch2 == ' ' || ch2 == '\n' || ch2 == '\t' || ch2 ==')' || ch ==']')
                           {
                             fputc(ch2,wr);
                              ch2 = fgetc(fp);
                           }

                       }
                       if(ch2 != ' ' && ch2 != ':' && ch2 != ',' && ch2 != '?' && ch2!= '\n' && ch2 != EOF && ch2!= '.' && ch2 != '"' && ch2 != ';')
                      {
                       fputc(ch2,wr);
                       str1[i] = ch2;
                       ch2 = fgetc(fp);
                       i++;
                      }
                   }
                    if(ch2 == ' ' || ch2 == ':' || ch2 == ',' || ch2 == '?' || ch2 == '\n' || ch2 == EOF || ch2== '.' || ch2 == '"' || ch2 == ';')
                    {
                       fputc(ch2,wr);
                    }
                   str1[i] = '\0';
                    no_word++;
                   if(strcmp(str,str1) == 0)
                   {

                       sw = sw + d;
                       flag = 1;

                   }
                   if(ch2 == '.' || ch2 == '?')
                   {
                       //sw = sw/no_word;
                       if(no_word>30)
                       {
                           sw = 0;
                       }
                       fputc(':',wr);
                       fprintf( wr, "%f", sw);

                       if(sw != 0)
                       {
                       arr = realloc(arr,index * sizeof(float));
                       arr[index-1] = sw;
                       index++;

                       }
                       sw = 0;
                       no_word = 0;
                   }
                   else if(flag != 1)
                     ch2 = fgetc(fp);
               }
               ch2 = fgetc(fp);
           }
           ch = fgetc(cp);
      }
     // printf("\tthe array is here\n");
      /*for( i = 0; i<index-1; i++)
      {
        printf("\t%d = %f\n",i,arr[i]);
      }*/
    fclose(cp);
    fclose(fp);
    fclose(wr);
    cp = fopen("s_weight.txt","r");
    ArrangeSummary(cp,no_sentence);
    }



void swap(float* a, float* b)
{
    float t = *a;
    *a = *b;
    *b = t;
}
float partition (float arr[], int low, int high)
{
    float pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    int j;
    for (j = low; j <= high-1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] >= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(float arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(float arr[], int size)
{
    int i;
    //for (i=0; i < size; i++)
    //printf("%f ",arr[i]);
    //printf("\n");
}

void ArrangeSummary(FILE *cp, int no_sentence)
{
   char ch,ch2;
   FILE *wr,*fp;
   float fl = -1, *arr2;
   int index = 1;
   arr2 = (float *)malloc(index * sizeof(float));
   fp = fopen("sentence_pos.txt","r");
   wr = fopen("new.txt","w");
   ch = fgetc(cp);
   ch2 = fgetc(fp);
   while(ch2 != EOF)
    {
        while(ch != '\n' && ch != EOF)
        {
            ch = fgetc(cp);
            fscanf(cp,"%f",&fl);
        }
        if( fl != -1 ){
          fputc('#',wr);
          fprintf(wr,"%f", fl);

                                 if(fl != 0)
                       {
                       arr2 = realloc(arr2,index * sizeof(float));
                       arr2[index-1] = fl;
                       index++;

                       }



          fputc(' ',wr);
          fl = -1;
        while(ch2 != '\n' && ch2 != EOF)
        {
          fputc(ch2,wr);
          ch2 = fgetc(fp);
        }
        }
        while(ch == ' ' || ch == '\n')
        {
            ch = fgetc(fp);
        }
                while(ch2 == ' ' || ch2 == '\n')
        {

            fputc(ch2,wr);
            ch2 = fgetc(cp);
        }

    }
    fclose(wr);
    fclose(fp);
    fclose(cp);


    //remove("s_weight.txt");
    rename("new.txt","s_w.txt");
    //remove("new.txt");
    //remove("sentence_pos.txt");

    fp = fopen("s_w.txt","r");
    cp = fopen("ANOTHER.txt","w");
        ch = fgetc(fp);
        while(ch != EOF)
        {
            fputc(ch,cp);
            ch = fgetc(fp);
        }

    fclose(fp);
    fclose(cp);

    //printf("%d",index-1);
    quickSort(arr2, 0, index-1);
    //printf("\tSorted array: %d\n",index-1);
    printArray(arr2, index-1);
   wr = fopen("summary.txt","w");
   int i,flag;
   for(i = 0; i<no_sentence; i++)
   {
       fp = fopen("s_w.txt","r");
       cp = fopen("copy.txt","w");
       ch = fgetc(fp);
       flag = 0;
       while(ch !=EOF){
           fscanf(fp,"%f",&fl);

           if( fl == arr2[i] && flag != 1) {
            flag = 1;
            if(ch == '#')
                ch = fgetc(fp);
             while(ch != '\n')
            {
            fputc(ch,wr);
            ch = fgetc(fp);
            }
           fputc('\n',wr);
           }
           else
            {
               // printf("%f ",fl);
                fputc(ch,cp);
                fprintf(cp,"%f",fl);
           while( ch != '\n' && ch != EOF)
           {
               ch = fgetc(fp);
               fputc(ch,cp);
           }
        }
         ch = fgetc(fp);
   }
   fclose(cp);
   fclose(fp);
   remove("s_w.txt");
   rename("copy.txt","s_w.txt");
   remove("copy.txt");
  }
}
