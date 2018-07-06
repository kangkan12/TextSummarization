    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include"beutiful.h"
    int main()
    {
      FILE *fp,*wr,*cp;
      int n,i;
     char fileName[100],any[100];
     remove("summary.txt");
      printf("\n\tHow many file do you want to enter\t");
      scanf("%d",&n);
       printf("\t ENTER how many Senetnces you need as a summary and HIT ENTER ");
      int no_sentence;
      scanf("%d",&no_sentence);
      for(i = 0; i<n; i++)
      {
      remove("summary.txt");

      //char fileName[100];
      printf("\n\tPLEASE ENTER NAME OF YOUR TEXT FILE with .txt AND HIT ENTER\n\t");
      scanf("%s",&fileName);
      char str[100]= "summary";
     strcat(str,fileName);
     remove(str);


      fp =fopen(fileName,"r");
      if (fp == NULL)
      {
          printf("\n\t%s\" File NOT FOUND!",fileName);
		  getch();
        exit(1);
      }
      else
      {
      int NumberOfSentence = ModifyFile(fp);
      fclose(fp);
      //remove(fileName);
      //rename("mod.txt",fileName);
      printf("\tTotal no of Senetnces in your document is  = %d\n",NumberOfSentence);
      if(NumberOfSentence>1){

      if( no_sentence>= NumberOfSentence)
      {
          //printf("\t wrong input: system automatically generate summary\n");
          no_sentence = NumberOfSentence/2;
          //printf("\t no of summery sentence%d\n",  no_sentence);
      }
      else if(no_sentence <= 0)
      {
          printf("\t wrong input \n");
          //no_sentence = NumberOfSentence;
          exit(1);

      }




      fp =fopen("mod.txt","r");
      int word = CountWord(fp);
      printf("\t total no of word in the file %d \n",word);
      fclose(fp);
      fp =fopen("mod.txt","r");
      wr = fopen("BEUTY_FILE.txt","w");
      beuty(fp,wr);//beuty(reading file,writing file)
      fclose(wr);
      char ch;
      fp = fopen("BEUTY_FILE.txt","r");
      ch =fgetc(fp);
      fclose(fp);
      fp = fopen("BEUTY_FILE.txt","r");
      cp = fopen("unique.txt","w");
      occurance(fp,cp);//occurance(reading file,writing file)
      fclose(cp);
      fclose(fp);
      wr = fopen("unique.txt","r");
     ch =fgetc(wr);
     /*while(ch != EOF){
        printf("%c",ch);
         ch =fgetc(wr);
      }
      fclose(wr);*/
      fp = fopen("mod.txt","r");
      cp = fopen("sentence_pos.txt","w");
      //SentecePose(reading File , writing the position of file i.e write file);
      SentencePos(fp,cp);
      cp = fopen("unique.txt","r");
      fp = fopen("termFrequency.txt","w");
      weight(fp,cp,word);
     fclose(fp);
     fclose(cp);
     fp = fopen("sentence_pos.txt","r");
     cp = fopen("weight.txt","r");
     sen_weight(fp,cp,no_sentence);
     fclose(cp);
     fclose(fp);
     fclose(wr);
    remove("weight.txt");
     remove("sentence_pos.txt");
    remove("BEUTY_FILE.txt");
     remove("termFrequency.txt");
     remove("unique.txt");
     remove("STOP_WORD_REMOVED.txt");
     remove("s_w.txt");
     remove("mod.txt");
    remove("s_weight.txt");
    remove("ANOTHER.txt");
    remove("termFrequency.txt");
    //printf("\n\n\n\t SUMMARY OF YOUR FILE IS STORED IN 'summary.txt' FILE\n\n");
    }
     char str[100]= "summary";
     strcat(str,fileName);
     rename("summary.txt",str);
     printf("\n\n");
 wr = fopen(str,"r");
char     ch =fgetc(wr);
     while(ch != EOF){
        printf("%c",ch);
         ch =fgetc(wr);
      }

      printf("\n\n");
 }

}
}
