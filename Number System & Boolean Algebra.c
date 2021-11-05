#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
char in[100], out[100];
int out2[200],d_count=0,out4[100],store[100][20]={0};
void ind(int,int,int);
int ham_calc(int,int,int);
int conversion(long long int,int);
long long int decimal(int base1);
void design();
void Choice_project(int);
FILE *history;                             ///File history saves all searched history
int options()                             ///showing the main menu options from here.
{
    int n;
  FILE *option;
char a[1000];
option=fopen("option.txt","r");
while(!feof(option)){
    fgets(a,3,option);
printf("%s",a);}
fclose(option);
    scanf("%d%*c",&n);
    system("cls");
    design();
 return n;
}
long long int power(unsigned long long a,int b) /// exponential algorithm. finds value of a^b
{
   long long int I=1;
    while(b!=0)
    {
    if(b%2==1)
    {
        I=I*a;
        b--;
    }
    else
    {
        a=a*a;
        b=b/2;
    }
    }
    return I;
}

//NUMBER SYSTEM
void todec(int base)
{
   long long int num=0;
    int i;
    char st[100];
    history=fopen("history.txt","a");
    if(base<=3)                                ///decimal to other conversion.
    {
        if(base==1){
           fprintf(history,"\t\tDECIMAL    To   BINARY\n");
            printf("\t\tDECIMAL    To   BINARY\n");}
        if(base==2){
            fprintf(history,"\t\tDECIMAL    To   OCTAL\n");
            printf("\t\tDECIMAL    To    OCTAL\n");}
        if(base==3){
            fprintf(history,"\t\tDECIMAL To HEXADECIMAL\n");
            printf("\t\tDECIMAL To HEXADECIMAL\n");}
        fprintf(history,"\t\t######################\n\n");
        fprintf(history,"Decimal Number is:");
            printf("\t\t######################\n\n");
          printf("Input a Decimal Number:");
          scanf("%s%*c",&st);
          fprintf(history," %s\n",st);
    for(i=0;i<strlen(st);i++)                            ///decimal string is converting into a decimal number
    {
        if(st[i]<48 || st[i]>57)
        {
            num=-100;
            break;
        }
        num=(num*10)+(st[i]-48);
    }
      if(base==1)
      {
     conversion(num,2);                               /// converting decimal into binary
     if(num!=-100){
   fprintf(history,"Binary value of (%s)D is (%s)B\n",st,out);
   printf("Binary value of (%s)D is (%s)B\n",st,out);}
      }
      if(base==2)                                     /// converting decimal into octal
      {
      conversion(num,8);
            if(num!=-100){
         fprintf(history,"Octal value of (%s)D is (%s)O\n",st,out);
         printf("Octal value of (%s)D is (%s)O\n",st,out);}
      }
        if(base==3)                                    ///converting decimal into hexadecimal
        {
         conversion(num,16);
            if(num!=-100){
            fprintf(history,"Hexadecimal value of (%s)D is (%s)H\n",st,out);
            printf("Hexadecimal value of (%s)D is (%s)H\n",st,out);}
        }
    }
  else if(base<=6)                                 ///Binary to other conversion
   {
       if(base==4){
         fprintf(history,"\t\tBINARY   TO   DECIMAL\n");
         printf("\t\tBINARY   TO   DECIMAL\n");}
       if(base==5){
         fprintf(history,"\t\tBINARY    TO    OCTAL\n");
         printf("\t\tBINARY    TO    OCTAL\n");}
       if(base==6){
         fprintf(history,"\t\tBINARY TO HEXADECIMAL\n");
         printf("\t\tBINARY TO HEXADECIMAL\n");}
         printf("\t\t#####################\n\n");
        fprintf(history,"\t\t#####################\n\n");

    num = decimal(2);                                ///converting Binary into decimal, then decimal to other.
    if(base==4 && num!= -100){
   fprintf(history,"Decimal value of (%s)B is (%lld)D\n",in,num);
   printf("Decimal value of (%s)B is (%lld)D\n",in,num);}
  if(num==-100 && base==4){
    fprintf(history,"Error code!....\n");
    printf("Error code!\nTry again....\n");}
   if(base==5)
   {
    conversion(num,8);
    if(num!=-100){
    fprintf(history,"Octal value of(%s)B is (%s)O\n",in,out);
    printf("Octal value of(%s)B is (%s)O\n",in,out);}
   }
    if(base==6)
   {
    conversion(num,16);
    if(num!=-100){
    fprintf(history,"Hexadecimal value of(%s)B is (%s)H\n",in,out);
    printf("Hexadecimal value of(%s)B is (%s)H\n",in,out);}
   }
   }
 else if(base<=9)                                    ///Octal to other conversion
   {
       if(base==7){
         fprintf(history,"\t\tOCTAL   TO   DECIMAL\n");
         printf("\t\tOCTAL   TO   DECIMAL\n");}
       if(base==8){
         fprintf(history,"\t\tOCTAL    TO   BINARY\n");
         printf("\t\tOCTAL    TO   BINARY\n");}
       if(base==9){
         fprintf(history,"\t\tOCTAL TO HEXADECIMAL\n");
         printf("\t\tOCTAL TO HEXADECIMAL\n");}
         printf("\t\t#####################\n\n");
         fprintf(history,"\t\t#####################\n\n");
       num= decimal(8);                                   ///converting Octal to decimal, then decimal to other.
        if(base==7 && num!= -100){
   fprintf(history,"Decimal value of (%s)O is (%lld)D\n",in,num);
   printf("Decimal value of (%s)O is (%lld)D\n",in,num);}
   else if(num==-100 && base==7){
    fprintf(history,"Error code!....\n");
    printf("Error code!\nTry again....\n");}
     if(base==8)
   {
    conversion(num,2);
    if(num!=-100){
    fprintf(history,"Binary value of(%s)O is (%s)B\n",in,out);
    printf("Binary value of(%s)O is (%s)B\n",in,out);}
   }
    if(base== 9)
   {
    conversion(num,16);
    if(num!=-100){
    fprintf(history,"Hexadecimal value of(%s)O is (%s)H\n",in,out);
    printf("Hexadecimal value of(%s)O is (%s)H\n",in,out);}
   }
   }
else                                                      ///converting hexadecimal to other.
   {
       if(base==10){
         fprintf(history,"\t\tHEXADECIMAL TO DECIMAL\n");
         printf("\t\tHEXADECIMAL TO DECIMAL\n");}
       if(base==11){
        fprintf(history,"\t\tHEXADECIMAL  TO BINARY\n");
         printf("\t\tHEXADECIMAL  TO BINARY\n");}
       if(base>=12){
        fprintf(history,"\t\tHEXADECIMAL  TO  OCTAL\n");
         printf("\t\tHEXADECIMAL  TO  OCTAL\n");}
         printf("\t\t######################\n\n");
         fprintf(history,"\t\t######################\n\n");
       num=decimal(16);                                      ///convert hexadecimal to decimal. then decimal to others.
        if(base==10 && num!= -100){
   fprintf(history,"Decimal value of (%s)H is (%lld)D\n",in,num);
   printf("Decimal value of (%s)H is (%lld)D\n",in,num);}
   else if(num==-100 && base==10){
    fprintf(history,"Error code!n");
    printf("Error code!\nTrt again....\n");}
   if(base==11)
   {
    conversion(num,2);
    if(num!=-100){
    fprintf(history,"Binary value of(%s)H is (%s)B\n",in,out);
    printf("Binary value of(%s)H is (%s)B\n",in,out);}
   }
    if(base>= 12)
   {
    conversion(num,8);
    if(num!=-100){
    fprintf(history,"Octal value of(%s)H is (%s)O\n",in,out);
    printf("Octal value of(%s)H is (%s)O\n",in,out);}
   }
   }
   fprintf(history,"\n\n\n");
   fclose(history);
}
void numbersystem()
{
    int base,n,op;
   FILE *num_system;
char a[1000];
num_system=fopen("choice_numbersystem.txt","r");
while(!feof(num_system)){                          ///reading the number system option from a file name choice_numbersystem.txt.
    fgets(a,40,num_system);
printf("%s",a);}
fclose(num_system);
    scanf("%d%*c",&base);
    number:;
   system("cls");
   design();
    todec(base);
    printf("\n\n1.Try again\n");
    printf("2.Back\n");
    printf("3.Main Menu\n\n");
    printf("Choice Option: ");
    scanf("%d%*c",&n);
        system("cls");
        design();
    if(n==1)
       goto number;
    if(n==2)
    numbersystem();
    if(n==3)
    {
       op=options();
    Choice_project(op);
    }
}
long long int decimal(int base1)
{
 long long int dec=0;
 int j=0,i;
    if(base1==2){
    fprintf(history,"Binary number is: ");
    printf("Input a Binary number: ");}
    if(base1==8){
        fprintf(history,"Octal number is: ");
        printf("Input a Octal number: ");}
    if(base1==16){
       fprintf(history,"Hexadecimal number is: ");
       printf("Input a Hexadecimal number: ");}
  gets(in);                                            ///input binary,octal, hexadecimal number(according to base1). then convert the string into decimal.
  fprintf(history,"%s\n",in);

    int len =strlen(in);
    for(i=len-1;i>=0;i--)                           ///converting string into decimal
    {
        if(in[i]<60)                               /// when string digit are 1to9
            {
                if(in[i]-48>=base1)
                return -100;
     dec=(long long int)((in[i]-48)*(power(base1,j++))) + dec;
            }
     else                                       ///when string digit are A to F. for hexadecimal input.
     {
         if(in[i]-55>=base1)
                return -100;
          dec=(long long int)((in[i]-55)*(power(base1,j++))) + dec;
     }
    }
    return dec;
}
int conversion(long long int x,int base2)
{
   long long int y= x;
    if(x==-100){
        fprintf(history,"Error code!....\n");
        printf("Error code!\nTry again....\n");}
    else
        {
   int i=0;
   while(y!=0)
   {
       if(y%base2<10)                        ///each time number is divided with base and remaider is stored. as a digit of output.
     out[i++]=y%base2+48;
     else
        out[i++]=y%base2+55;
     y=y/base2;
   }
   out[i]='\0';
   strrev(out);                              ///the output is stored as LSB to MSB. so, it is reversed.
   }
}

//BCD code
int Formdecimal(char st[])
{
    int i,num=0;
    for(i=3;i>=0;i--)
    {
        if(st[i]!='0')
        num=num+power(2,3-i);
    }
    return num;
}
int BCDtoDecimal(int n)
{
    int len,i=0,p[100]={0},count=0,a=0;
    if(n==3)
        {
    printf("\t\t BCD TO DECIMAL\n");
    printf("\t\t ##############\n\n");
    printf("Enter a BCD code: ");
    fprintf(history,"\t\t BCD TO DECIMAL\n");
    fprintf(history,"\t\t ##############\n\n");
    fprintf(history,"BCD code is: ");
        }
    gets(in);
    fprintf(history,"%s\n",in);
    char st[6];
    len=strlen(in);
    for(i=0;i<len;i++)                           ///error detection
    {
        if(in[i]>'1')
        {
            len=0;
        printf("\nError Code!\nTry again...\n");
        fprintf(history,"\nError Code!...\n");
        }
    }
    i=0;
    while(i<len)
    {
      if((len+a)%4!=0)                  ///adding 0, at the start of BCD code, if size of BCD is not divided by 4. as 10011 into 0001 0011.
       {
          st[a]='0';
          a++;
       }
       else                           /// while reshape of BCD code is complete, main operation is started here.
    {
        st[(i+a)%4]=in[i];            ///st array stored every 4digit binary number from the BCD code.
          if((i+a+1)%4==0)            /// if st array is fulled  with 4digit binary.
          {
              st[4]='\0';
              fprintf(history,"%s\t",st);
              printf("%s\t",st);
             p[count++] =Formdecimal(st);          ///decimal value of st array is stored in p array.
              }
          i++;
    }
    }
    printf("\n\n");
    fprintf(history,"\n\n");
    for(i=0;i<count;i++)
    {
        if(n==3){
        fprintf(history,"%d\t",p[i]);
        printf("%d\t",p[i]);}
        else{
            fprintf(history,"%d\t",p[i]-3);
            printf("%d\t",p[i]-3);}
    }
    printf("\n");
    fprintf(history,"\n");
    for(i=0;i<count;i++)
    {
        if(n==3)
        {
        if(p[i]>9)
            {
            fprintf(history,"Invalid");
            printf("Invalid");
            len=-1;}
        }
        else
            {
               if(p[i]-3>9 || p[i]-3<0)
            {
            fprintf(history,"Invalid");
            printf("Invalid");
            len=-1;}
            }
          printf("\t");
          fprintf(history,"\t");
    }
    if(n==3)                                ///printing decimal output, that comes from a BCD input.
    {
    if(len==-1 || len==0){
        fprintf(history,"\n\nSo, This BCD code is an Invalid code\n");
        printf("\n\nSo, This BCD code is an Invalid code\n");}
    else
    {
    fprintf(history,"\n\nDecimal value of (%s)BCD is (",in);
    printf("\n\nDecimal value of (%s)BCD is (",in);
     for(i=0;i<count;i++)                     ///printing Decimal output.
    {
        printf("%d",p[i]);
        fprintf(history,"%d",p[i]);
    }
    fprintf(history,")D\n");
    printf(")D\n");}
    }
    else{                                  ///printing decimal output, that comes from a excess-3 input.
         if(len==-1 || len==0){
        fprintf(history,"\n\nSo, This EXCESS-3 code is an Invalid code\n");
        printf("\n\nSo, This EXCESS-3 code is an Invalid code\n");}
    else
    {
    fprintf(history,"\n\nDecimal value of (%s)XS3 is (",in);
    printf("\n\nDecimal value of (%s)XS3 is (",in);
     for(i=0;i<count;i++)                          ///printing decimal output
    {
        fprintf(history,"%d",p[i]-3);
        printf("%d",p[i]-3);
    }
    fprintf(history,")D\n");
    printf(")D\n");}
    }
}
int DecimaltoBCD()
{
    int i,len,j,cunt=0,p=0;
    char out1[200];
    printf("\t\t DECIMAL TO BCD\n");
     printf("\t\t ##############\n\n");
    printf("Enter a Decimal Value: ");
    fprintf(history,"\t\t DECIMAL TO BCD\n");
    fprintf(history,"\t\t ##############\n\n");
    fprintf(history,"Decimal Value is: ");
    gets(in);
    printf("\n\n");
    fprintf(history,"%s\n\n",in);
    len=strlen(in);
    for(i=0;i<len;i++)                              ///Error input detection
    {
        if(in[i]>57)
            {
            fprintf(history,"Error Code!...\n");
            printf("Error Code!\nTry again...\n");
            break;
        }
    }
    if(i==len)
    {
        for(i=0;i<len;i++){                          ///printing every digit of decimal
            fprintf(history,"%c\t",in[i]);
            printf("%c\t",in[i]);}
        printf("\n");
        fprintf(history,"\n");
        for(i=0;i<len;i++)                          ///finding every BCD of every digit of that decimal.
        {
            conversion(in[i]-48,2);
         for(j=0;j<4;j++){
             if((strlen(out)+cunt)%4!=0 || strlen(out)==0)   ///out string contains a BCD value. if the number of BCD digit is not divisible by 4.
             {cunt++;                                        ///then, attached 0 before value.
                 fprintf(history,"0");
                 printf("0");
                 if(i!=0)
            out1[p++]='0';
             }
             else
                {
            fprintf(history,"%c",out[j-cunt]);
            printf("%c",out[j-cunt]);
            out1[p++]=out[j-cunt];
                }
         }
         cunt=0;
         fprintf(history,"\t");
         printf("\t");
        }
       out1[p]='\0';
       fprintf(history,"\n\nBCD value of (%s)D is (%s)BCD\n",in,out1);
       printf("\n\nBCD value of (%s)D is (%s)BCD\n",in,out1);
    }
}
void DecimaltoExcess()
{
   int i,len,j,cunt=0,p=0;
   char out1[200];
   printf("\t\t DECIMAL TO EXCESS-3\n");
   printf("\t\t ###################\n\n");
   printf("Enter a Decimal value: ");
   gets(in);
    printf("\n\n");
   fprintf(history,"\t\t DECIMAL TO EXCESS-3\n");
   fprintf(history,"\t\t ###################\n\n");
   fprintf(history,"Decimal value is: %s\n\n",in);
    len=strlen(in);
    for(i=0;i<len;i++)                                   ///Error input detection.
    {
        if(in[i]>57)
            {
            fprintf(history,"Error Code!...\n");
            printf("Error Code!\nTry again...\n");
            break;
        }
    }
    if(i==len)
    {
        for(i=0;i<len;i++){                                ///printing every decimal digit
            fprintf(history,"%c\t",in[i]);
            printf("%c\t",in[i]);}
        printf("\n");
        fprintf(history,"\n");
        for(i=0;i<len;i++)                                ///finding Excess-3 value of every decimal digit
        {
            conversion(in[i]-45,2);
         for(j=0;j<4;j++){
             if((strlen(out)+cunt)%4!=0 || strlen(out)==0)   ///out string contain Excess-3 value of every decimal digit.
             {cunt++;                                        ///if length of out string is not divisible by 4, we have to attached 0 before the value.
                 fprintf(history,"0");
                 printf("0");
         if(i!=0)
            out1[p++]='0';
             }
             else
                {
            fprintf(history,"%c",out[j-cunt]);
            printf("%c",out[j-cunt]);
            out1[p++]=out[j-cunt];
                }
         }
         cunt=0;
         printf("\t");
         fprintf(history,"\t");
        }
       out1[p]='\0';
       printf("\n\nEXCESS-3 Code of (%s)D is (%s)XS3\n",in,out1);                 ///printing Excess-3 value of every individual decimal digit.
       fprintf(history,"\n\nEXCESS-3 Code of (%s)D is (%s)XS3\n",in,out1);
    }
}
void ExcesstoDecimal(int n)
{
   int i;
   printf("\t\t EXCESS-3 TO DECIMAL\n");
   printf("\t\t ###################\n\n");
   printf("Enter a EXCESS-3 code(0 or 1 digit allowed only): ");
   fprintf(history,"\t\t EXCESS-3 TO DECIMAL\n");
   fprintf(history,"\t\t ###################\n\n");
   fprintf(history,"EXCESS-3 code: ");
   BCDtoDecimal(n);                                   ///every individual digit is conver into decimal, then substract 3 from each of the decimal digit.
                                                      /// if decimal digits are valid.
}
int BCD(int n)
{
    history = fopen("history.txt","a");
    if(n==1)
    {
       DecimaltoBCD();
    }
    else if(n==2)
    {
        DecimaltoExcess();
    }
    else if(n==3)
    {
       BCDtoDecimal(n);
    }
    else
    {
       ExcesstoDecimal(n);
    }
    fprintf(history,"\n\n\n");
    fclose(history);
}
void choiceBCD()
{
    int n,n1,op;
    printf("1.Decimal to BCD\n");
    printf("2.Decimal to Excess-3\n");
    printf("3.BCD to Decimal\n");
    printf("4.Excess-3 to Decimal\n\n");
    printf("\nChoice Option: ");
    scanf("%d%*c",&n);
    system("cls");
    design();
    BCD:;
    BCD(n);
    printf("\n\n1.Try again!\n");
    printf("2.Back\n");
    printf("3.Main Menu\n\n");
    printf("Choice Options: ");
    scanf("%d%*c",&n1);
    system("cls");
    design();
    if(n1==1)
        goto BCD;
    if(n1==2)
        choiceBCD();
    if(n1==3)
    {
      op=options();
      Choice_project(op);
    }
}

//Hamming Code
void Hammingrecieve()
{
    int len,i,r=0,pos,val,flag=0,p=0;
    printf("* * *Find Error & Correct the Encrypted Data* * *\n\n");
    fprintf(history,"\t\tFind Error & Correct the Encrypted Data\n");
    fprintf(history,"\t\t#######################################\n\n");
   printf("Enter the Recived Data Word: ");
 gets(in);
 fprintf(history,"Recived Data Word is: %s\n",in);
  len=strlen(in);
  for(i=0;i<len;i++)                                     ///checking Error of encryted data word
  {
      out2[i]=in[i]-48;
      if(in[i]-48>1)
      {
        printf("Error digit %c\nOnly 1 or 0 allowed...\ntry again\n",in[i]);
        fprintf(history,"Error digit %c\nOnly 1 or 0 allowed...\ntry again\n",in[i]);
        break;}
  }
  if(i==len)
  {
  printf("\n\n\tLength of Recieved Data word=n=%d\n",len);
  printf("\tLet,Number of Parity bit added here is = r\n");
  printf("\nSo,\n\t   (2^r) %c n+1\n",242);
 printf("\tor,(2^r) %c %d+1\n",242,len);
 fprintf(history,"\n\n\tLength of Recieved Data word=n=%d\n",len);
 fprintf(history,"\tLet,Number of Parity bit added here is = r\n");
 fprintf(history,"\nSo,\n\t   (2^r) %c n+1\n",242);
 fprintf(history,"\tor,(2^r) %c %d+1\n",242,len);
  i =0;
 while(len>power(2,i)-1)                   ///finding the number of parity in encrypted data word.
	{
	    r++;
		i++;
	}
	printf("\n\tr=%d (min value from above eqn)\n",r);
	printf("\nSo, %d parity bit is present in the Data Word\n\n",r);
    printf("Here(using even parity method),\n");
    fprintf(history,"\n\tr=%d (min value from above eqn)\n",r);
	fprintf(history,"\nSo, %d parity bit is present in the Data Word\n\n",r);
    fprintf(history,"Here(using even parity method),\n");
    int st[20];
      for(i=0;i<r;i++)
	{
        pos =power(2,i);                      ///pos stores the value of 2^i.
        printf("p%d\t[%d]   ",pos,pos);
        fprintf(history,"p%d\t[%d]   ",pos,pos);
       ind(pos,len,i);                         ///printing the index that can effect the parity of index [pos-1]
        printf("\n    ");
        fprintf(history,"\n    ");
        val=ham_calc(pos-1,len,i);              ///calculating the value of parity bit of index [pos-1]
        printf("\n\tSo,p%d=%d\n",pos,val);
        printf("\n\n");
        fprintf(history,"\n\tSo,p%d=%d\n\n\n",pos,val);
        if(val==1)                                ///if value of parity bit of index [pos-1] is 1 then, there must be an Error.
            st[flag++]=pos;                        ///As, Encrypted data word was written by even parity method.
	}
	if(flag>0)
    {
        printf("There is an Error in the code\n");
        printf("From the above, We can see...\n(");
        fprintf(history,"There is an Error in the code\n");
        fprintf(history,"From the above, We can see...\n(");
        for(i=0;i<flag;i++)
        {
            p=p+st[i];                                      ///finding the digit that has Error.
             if(i+1==flag){
        fprintf(history,"%d)=%dth digit have to be Correct\n",st[i],p);
        printf("%d)=%dth digit have to be Correct\n",st[i],p);}
        else{
            fprintf(history,"%d+",st[i]);
            printf("%d+",st[i]);}
        }
    if(p<=len)
    {
     out2[p-1]=(out2[p-1]-1)*(out2[p-1]-1);
     printf("\nSO, The Correct Hamming Code is: ");
    fprintf(history,"\nSO, The Correct Hamming Code is: ");                ///printing the correct encryted data word.
     for(i=0;i<len;i++){
        fprintf(history,"%d",out2[i]);
        printf("%d",out2[i]);}
        printf("\n");
       fprintf(history,"\n");
            }
     else                                   ///In case of Multiple bit Error.
     {
        printf("\nBut, %dth position is not in the data...\nSO, There must be multiple bit Error...",p);
     printf("\n\nSorry, as Multiple bit Correction Cant't detect by Hamming Code\n");
     fprintf(history,"\nBut, %dth position is not in the data...\nSO, There must be multiple bit Error...",p);
     fprintf(history,"\n\nSorry, as Multiple bit Correction Cant't detect by Hamming Code\n");}
   }
     else{
        fprintf(history,"Congrats!...\nRecieved Data Word has no Error...\n");
        printf("Congrats!...\nRecieved Data Word has no Error...\n");}
  }
}
void ind(int pos,int total,int shift)
{
 int n,i;
for(i=pos+1;i<=total;i++)
{
 n=i&(1<<(shift)) ;                   ///checking whether  ith index can effect 2^shift index parity.
                                    /// if n=0, then ith index don't effect 2^shift index parity.
                                    /// if n!=0, then ith index can effect the parity of 2^shift index.
 if(n!=0)
 {
     if(i>9){
       printf("[%d]  ",i);
       fprintf(history,"[%d]  ",i);}
     else{
     printf("[%d]   ",i);
     fprintf(history,"[%d]   ",i);}
 }
}
}
int ham_calc(int pos,int total,int shift)
{
	int count=0,i,j,n;
for(i=pos+1;i<=total;i++)
{
 n=i&(1<<(shift)) ;                   ///checking if ith index  can effect 2^shift index parity.
 if(n!=0)
 {
     fprintf(history,"     %d",out2[i-1]);
     printf("     %d",out2[i-1]);
     if(out2[i-1]==1)                 ///counting the number of 1, in the index that can effect 2^shift index parity.
        count++;
 }
}
if(count%2==0)                        ///according to even parity, 2^shift index parity value will be 0
 return 0;
 else                                 ///according to even parity, 2^shift index parity value will be 1
    return 1;
}
void Hamming()
{
    int len,r=0,i,total,k=0,j=0,pos,val,d;
 printf("* * *Find the Correct Hamming Code* * *\n\n");
 fprintf(history,"\t\tFind the Correct Hamming Code\n");
 fprintf(history,"\t\t#############################\n\n");
 printf("Enter the Data Word: ");                                ///Data word that has to be encrypted.
 gets(in);
 fprintf(history,"Data Word is: %s\n",in);
  len=strlen(in);
  for(i=0;i<len;i++)                                           ///Error detection in input.
  {
      if(in[i]-48>1)
      {
        fprintf(history,"Error digit %c\nOnly 1 or 0 allowed...\ntry again\n",in[i]);
        printf("Error digit %c\nOnly 1 or 0 allowed...\ntry again\n",in[i]);
        break;}
  }
  if(i==len)                                             ///if data word has no Error.
  {
  printf("\n\n\tLength of Data word=n=%d\n",len);
  printf("\tLet,Number of Parity bit will add = r\n");
  printf("\nSo,\n\t   (2^r) %c n+r+1\n",242);
  printf("\tor,(2^r) %c %d+r+1\n",242,len);
  fprintf(history,"\n\n\tLength of Data word=n=%d\n",len);
  fprintf(history,"\tLet,Number of Parity bit will add = r\n");
  fprintf(history,"\nSo,\n\t   (2^r) %c n+r+1\n",242);
  fprintf(history,"\tor,(2^r) %c %d+r+1\n",242,len);
  i =0;
 while(len>power(2,i)-(i+1))                            /// find the number of parity bit have to be added. formula 2^r < len+r+1.
	{
	    r++;
		i++;
	}
	total=r+len;                                       ///total data word with parity bit
	printf("\n\tr=%d (min value from above eqn)\n",r);
	printf("\nSo, %d parity bit will added with the Data Word\n",r);
	printf("\nCalculated word will be: ");
	fprintf(history,"\n\tr=%d (min value from above eqn)\n",r);
	fprintf(history,"\nSo, %d parity bit will added with the Data Word\n",r);
	fprintf(history,"\nCalculated word will be: ");
	for(i=0;i<total;i++)                            /// printing the encrypted data word will look like with parity bit.
    {
        d=power(2,k);                               /// d stores the position of 2^0, 2^1, 2^2......
        if(i==(d-1))
        {
		    fprintf(history,"(p%d)",d);
			printf("(p%d)",d);
			k++;
		}
		else
        {
            fprintf(history,"%c",in[j]);
            printf("%c",in[j]);
            out2[i]=in[j]-48;
            j++;
        }
    }
    printf("\n\n");
    printf("Here(using even parity method),\n");
    fprintf(history,"\n\nHere(using even parity method),\n");
    for(i=0;i<r;i++)
	{
        pos = power(2,i);                                          ///pos stores the index of power 2.
        printf("p%d\t[%d]   ",pos,pos);
        fprintf(history,"p%d\t[%d]   ",pos,pos);
       ind(pos,total,i);                                          ///this prints the index no. which can effect the parity bit of [2^i-1] index;
        printf("\n");
        printf("\tp%d",pos);
        fprintf(history,"\n\tp%d",pos);
        val=ham_calc(pos,total,i);                              /// val stored the value of the parity bit of [2^i -1] index.
        printf("\n\tSo,p%d=%d\n",pos,val);
        printf("\n\n");
        fprintf(history,"\n\tSo,p%d=%d\n\n\n",pos,val);
		out2[pos-1]=val;                                        ///out2 string stored the encrypted data word.
	}
        printf("CALCULATED HAMMING CODE: (");
        fprintf(history,"CALCULATED HAMMING CODE: (");
	for(i=0;i<total;i++)                                     ///printing actual encrypted hamming code.
	{
	    printf("%d",out2[i]);
	    fprintf(history,"%d",out2[i]);
	}
	printf(")\n");
	fprintf(history,")\n");}
}
void Choice(int n)
{
    if(n==1)
        Hamming();
 else
        Hammingrecieve();
}
int ChoiceHamming()
{
    history=fopen("history.txt","a");
    int n,n1,op;
    printf("\n1.Find encoded Hamming Code(for given data)\n");
    printf("2.Find Error & Correct the encrypted hamming code\n");
    printf("\nChoice Option: ");
    scanf("%d%*c",&n);
    system("cls");
    design();
    hamming:;
    Choice(n);
    printf("\n\n1.Try again!\n");
    printf("2.Back\n");
    printf("3.Main Menu\n\n");
    printf("Choice Options: ");
    scanf("%d%*c",&n1);
    fprintf(history,"\n\n\n");
    system("cls");
    design();
    if(n1==1)
        goto hamming;
    fclose(history);
    if(n1==2)
        ChoiceHamming();
    if(n1==3)
    {
        op=options();
        Choice_project(op);
    }

}

//ASCII
void choiceASCII()
{
    int op;
    history=fopen("history.txt","a");
    char main[3];
    printf("1.ASCII TABLE\n");
    printf("2.Search ASCII value of a character\n");
    printf("3.Search ASCII code of a number\n\n");
    printf("choice option: ");
    scanf("%d%*c",&op);
    system("cls");
    design();
    if(op==1)
        ASCII();
   else if(op==2){
       char asci;
        printf("* * *ASCII value of a Character* * *\n\n");
        fprintf(history,"\t\tASCII value of a Character\n");
        fprintf(history,"\t\t##########################\n\n");
        printf("Enter a Character: ");
        scanf("%c%*c",&asci);
        fprintf(history,"ASCII Character: %c\n",asci);
        printf("ASCII value of %c is %d\n",asci,asci);
        fprintf(history,"ASCII value of %c is %d\n",asci,asci);
    }
    else{
        int asci;
        printf("* * *ASCII code of a Number* * *\n\n");
        fprintf(history,"\t\tASCII code of a Number\n");
        fprintf(history,"\t\t######################\n\n");
        printf("Enter a Number: ");
        scanf("%d%*c",&asci);
        printf("ASCII code of %d is %c\n",asci,asci);
        fprintf(history,"ASCII code of %d is %c\n",asci,asci);
    }
    fprintf(history,"\n\n\n");
    fclose(history);
     printf("Press Enter to go Main Menu  ");
    gets(main);
    system("cls");
    design();
    op=options();
    Choice_project(op);
}
void ASCII()                                                     ///Prints Ascii Table.
{
printf("\n\n\t\t\t\t\tASCII Table\n\n");
fprintf(history,"\t\t\tASCII Table\n");
fprintf(history,"\t\t\t###########\n\n");
printf("Decimal|   ASCII|\tDecimal|   ASCII|\tDecimal|   ASCII|\tDecimal|   ASCII|\n");
fprintf(history,"Decimal|   ASCII|\tDecimal|   ASCII|\tDecimal|   ASCII|\tDecimal|   ASCII|\n");
int i,op;
for(i=32;i<88;i++)                        ///difference =56. it means 56 rows with 4 colomns. every rows print i,i+56,i+112,i+168 Ascii value.
{
    if(i<100)
    {
        if(i==32){                           ///special line for space.
 fprintf(history,"     %d|%c(space)|\t",i,i);
 printf("     %d|%c(space)|\t",i,i);}
 else{
     fprintf(history,"     %d|   %c    |\t",i,i);
     printf("     %d|   %c    |\t",i,i);}
    }
 else{                                      ///extra space print for 3digit number
 fprintf(history,"    %d|   %c    |\t",i,i);
 printf("    %d|   %c    |\t",i,i);}
 if(i+56<100){
 fprintf(history,"     %d|   %c    |\t",i+56,i+56);
 printf("     %d|   %c    |\t",i+56,i+56);}
 else{
 fprintf(history,"    %d|   %c    |\t",i+56,i+56);
 printf("    %d|   %c    |\t",i+56,i+56);}
 printf("    %d|   %c    |\t",i+112,i+112);
 fprintf(history,"    %d|   %c    |\t",i+112,i+112);
 if(i+168!=255){
 fprintf(history,"    %d|   %c    |\n",i+168,i+168);
 printf("    %d|   %c    |\n",i+168,i+168);}
}
printf("\n\n");
fprintf(history,"\n\n");
}

//Truth Table generator
void bitcheck(int num,int n)           ///prints different variable values to make Truth table.
{
int i,p;
for(i=0;i<n;i++)
{
   p=num&(1<<i);
   if(p==0)
    out2[n-i-1]=0;                     ///out2 string stores binary digit of int num.
   else
    out2[n-i-1]=1;
}
for(i=0;i<n;i++){                     ///then print those binary digits(with tab) to make truth table
    fprintf(history," %d\t",out2[i]);
    printf(" %d\t",out2[i]);}
}
int bracket(int start)
{
    int j=start+1,stock=1,total=0,p,i;
while(in[j]!=')')
 {
if(in[j]=='(')
{
    stock=stock&bracket(j);
    j=j+d_count;
    d_count=0;
}
if(in[j]=='+')
{
    total=total|stock;
    stock=1;
}
if((in[j]>64 && in[j]<91)||(in[j]>96 && in[j]<123))
{
    if(in[j+1]=='\'')
        {
      p=(out2[out4[in[j]]]-1)*(out2[out4[in[j]]]-1);
  stock= stock&p;
  j++;
  }
  else
    stock= stock&out2[out4[in[j]]];
}
j++;
 }
 total=total|stock;
 i=start;
 while(in[i]!=')')
 {
 d_count++;
 i++;
 }
 if(in[j+1]=='\'')
    {
    total=(total-1)*(total-1);
     d_count++;
      }
return total;
}
void  Truth_table()
{
    history= fopen("history.txt","a");
    int i,n=0,len,out1[200]={0},out3[200]={0},j,stock=1,total=0,p,n1,op;
    printf("* * *TRUTH TABLE GENERATING(for a Boolean Eqn)* * *\n\n");
    printf("Enter a Boolen Equation: ");
    gets(in);
    fprintf(history,"\t\tTRUTH TABLE GENERATING(for a Boolean Eqn)\n");
    fprintf(history,"\t\t#########################################\n\n\n");
    fprintf(history,"Boolean Equation: %s",in);
    len=strlen(in);
    for(i=0;i<len;i++)                 /// storing the variable of Boolean Equation in out1 string. if it appear multiple time, store once only.
    {
      if((in[i]>64 && in[i]<91)||(in[i]>96 && in[i]<123))
      {
       out1[in[i]]=1;
      }
    }
    for(i=65;i<123;i++)
    {
        if(out1[i]==1)                ///this means, ascii value of i is present in Boolean Equation.
        {
            out4[i]=n;                ///out4 uses to numbering the variable use in the Boolean Equation.
            out3[n]=i;                /// out3 string stores those variable by number.
            n++;
        }
        if(i==90)
            i=96;
    }
    printf("\n\t\t\tTRUTH TABLE\n\n");
    fprintf(history,"\n\t\t\tTRUTH TABLE\n\n");
    for(i=0;i<n;i++){                      ///printing varible of Truth Table
        fprintf(history," %c\t",out3[i]);
        printf(" %c\t",out3[i]);}
    printf(" Output\n");
    fprintf(history," Output\n");
for(i=0;i<(int)power(2,n);i++)             /// calculates the Truth table.
{
 bitcheck(i,n);                             ///prints variable values in truth table. 2^n line variable values have to print for n variable.
 for(j=0;j<len;j++)
 {
if(in[j]=='(')
{
    stock=stock&bracket(j);              ///bracket(j) calculate the equation between bracket.
    j=j+d_count;                         ///stock stores the value of every minterm.
    d_count=0;
}
if(in[j]=='+')                           /// + operator means we have to add or operation between stock and total.
{
    total=total|stock;                   ///total calculate the value of total SOP calculated till now.
    stock=1;                             ///beginning of any minterm operation stock=1. because, minterm is a product of many variable.
}
if((in[j]>64 && in[j]<91)||(in[j]>96 && in[j]<123))
{
    if(in[j+1]=='\'')
        {
      p=(out2[out4[in[j]]]-1)*(out2[out4[in[j]]]-1);          ///if [j+1] index have a prime. then this value will reversed.
  stock= stock&p;
  j++;
  }
  else
    stock= stock&out2[out4[in[j]]];           ///stock stroing the minterm
}
 }
total=total|stock;                           ///at the end total stores SOP values for a set of variable values.
 printf(" %d",total);
 printf("\n");
fprintf(history," %d\n",total);
 total=0;
 stock=1;
}
fprintf(history,"\n\n\n");
fclose(history);
 printf("\n\n1.Try again!\n");
    printf("2.Main Menu\n\n");
    printf("Choice Options: ");
    scanf("%d%*c",&n1);
    system("cls");
    design();
    if(n1==1)
        Truth_table();
    if(n1==2)
    {
        op=options();
        Choice_project(op);
    }
}

//Gray code
void GraytoBinary()
{
    int i,len,j=0;
    printf("\t\tGREY TO BINARY\n");
    printf("\t\t##############\n\n");
    printf("Enter Your Gray Code: ");
    gets(in);
    fprintf(history,"\t\tGREY TO BINARY\n");
    fprintf(history,"\t\t##############\n\n");
    fprintf(history,"Gray Code is: %s\n",in);
    len=strlen(in);
    for(i=0;i<len;i++)
    {
        if(in[i]-48>1)
            {
        printf("\n\nError Code!\nTry again...\n");
        printf("Gray Code Allows 0 and 1 Digits Only...\n");
        fprintf(history,"\n\nError Code!...\n");
        fprintf(history,"Gray Code Allows 0 and 1 Digits Only...\n\n\n");
        break;}
    }
    if(i==len)
    {
       while(j!=len)
      {
          if(j==0)
            out[j]=in[j];
          else
            out[j]=((out[j-1]-48)^(in[j]-48))+48;       ///jth index value of binary string is xor operation between
                                                       ///jth index of gray string and [j-1] index of binary string.
            j++;
      }
      out[len]='\0';
      fprintf(history,"\n\nBinary vlaue of Gray Code(%s)G is = (%s)B\n\n\n",in,out);
      printf("\n\nBinary vlaue of Gray Code(%s)G is = (%s)B\n",in,out);
    }
}
void BinarytoGray()
{
    int i,len,j=0;
    fprintf(history,"\t\tBINARY TO GRAY\n");
    printf("\t\tBINARY TO GRAY\n");
    printf("\t\t##############\n\n");
    fprintf(history,"\t\t##############\n\n");
    printf("Enter your Binary Code: ");
    gets(in);                                                  ///input Binary string
    fprintf(history,"Binary Code is: %s\n\n",in);
    len=strlen(in);
    for(i=0;i<len;i++)                                         ///Error detection in input
    {
        if(in[i]-48>1)
            {
        printf("\n\nError Code!\nTry again...\n");
        fprintf(history,"\n\nError Code!...\n\n\n");
        break;}
    }
    if(i==len)
    {
      while(j!=len)
      {
          if(j==0)
            out[j]=in[j];
          else
            out[j]=((in[j-1]-48)^(in[j]-48))+48;     ///jth index value of gray string is the xor oparetion between jth and (j-1)th index of binary string
            j++;
      }
      out[len]='\0';
      fprintf(history,"\n\nGray Code for (%s)B is = (%s)G\n\n\n",in,out);
      printf("\n\nGray Code for (%s)B is = (%s)G\n",in,out);
    }
}
void Choicegray()
{
 int n,n1,op;
 history=fopen("history.txt","a");
 printf("1.Binary to Gray Code\n");
 printf("2.Gray Code to Binary\n\n");
 printf("Choice option: ");
 scanf("%d%*c",&n);
 system("cls");
 design();
 Grey:;
 if(n==1)
    BinarytoGray();
 else
   GraytoBinary();
    printf("\n\n1.Try again!\n");
    printf("2.Back\n");
    printf("3.Main Menu\n\n");
    printf("Choice Options: ");
    scanf("%d%*c",&n1);
    system("cls");
    design();
    if(n1==1)
        goto Grey;
        fprintf(history,"\n\n");
        fclose(history);
    if(n1==2)
        Choicegray();
    if(n1==3)
    {
        op=options();
        Choice_project(op);
    }
}

//Boolean Eqn of a Given Truth Table
struct kmap{
int binary[100];
int out;
int flag;
}num[100];
int bit_print(int m,int n)
{
    int i,j,k,count=0;
    for(i=0;i<m;i++)
    {
      for(j=n-1;j>=0;j--)
      {
        k=  i&(1<<j);
        if(k==0){
        printf("0\t");
        fprintf(history,"0\t");
         num[i].binary[n-j-1]=0;}
        else{
             printf("1\t");
             fprintf(history,"1\t");
        num[i].binary[n-j-1]=1;}
      }
      scanf("%d",&num[i].out);
      fprintf(history,"%d\n\n",num[i].out);
      if(num[i].out==1)
        count++;
      printf("\n");
      num[i].flag=0;
    }
      return count;
}
int kmap2var(int p)
{
    if(num[0].out==1 && num[2].out==1 &&(num[0].flag==0 || num[2].flag==0) )
    {
      num[0].flag=1;
      num[2].flag=1;
      store[p][0]=-1;
      store[p][1]=0;
      p++;
    }
    if(num[0].out==1 && num[1].out==1 &&(num[0].flag==0 || num[1].flag==0) )
    {
      num[0].flag=1;
      num[1].flag=1;
      store[p][0]=0;
      store[p][1]=-1;
      p++;
    }
    if(num[2].out==1 && num[3].out==1 &&(num[2].flag==0 || num[3].flag==0) )
    {
      num[2].flag=1;
      num[3].flag=1;
      store[p][0]=1;
      store[p][1]=-1;
      p++;
    }
    if(num[1].out==1 && num[3].out==1 &&(num[1].flag==0 || num[3].flag==0) )
    {
      num[1].flag=1;
      num[3].flag=1;
      store[p][0]=-1;
      store[p][1]=1;
      p++;
    }
    return p;
}
int kmap3var(int p)
{
if(num[0].out==1 && num[2].out==1 && num[4].out==1 && num[6].out==1 && (num[0].flag==0 || num[2].flag==0|| num[4].flag==0 || num[6].flag==0) )
    {
      num[0].flag=1;
      num[2].flag=1;
      num[4].flag=1;
      num[6].flag=1;
      store[p][0]=-1;
      store[p][1]=-1;
      store[p][2]=0;
      p++;
    }
if(num[1].out==1 && num[3].out==1 && num[5].out==1 && num[7].out==1 && (num[1].flag==0 || num[3].flag==0|| num[5].flag==0 || num[7].flag==0) )
    {
      num[1].flag=1;
      num[3].flag=1;
      num[5].flag=1;
      num[7].flag=1;
      store[p][0]=-1;
      store[p][1]=-1;
      store[p][2]=1;
      p++;
    }
    if(num[0].out==1 && num[1].out==1 && num[2].out==1 && num[3].out==1 && (num[0].flag==0 || num[1].flag==0|| num[2].flag==0 || num[3].flag==0) )
    {
      num[0].flag=1;
      num[1].flag=1;
      num[2].flag=1;
      num[3].flag=1;
      store[p][0]=0;
      store[p][1]=-1;
      store[p][2]=-1;
      p++;
    }
    if(num[4].out==1 && num[5].out==1 && num[6].out==1 && num[7].out==1 && (num[4].flag==0 || num[5].flag==0|| num[6].flag==0 || num[7].flag==0) )
    {
      num[4].flag=1;
      num[5].flag=1;
      num[6].flag=1;
      num[7].flag=1;
      store[p][0]=1;
      store[p][1]=-1;
      store[p][2]=-1;
      p++;
    }
if(num[2].out==1 && num[3].out==1 && num[6].out==1 && num[7].out==1 && (num[2].flag==0 || num[3].flag==0|| num[6].flag==0 || num[7].flag==0) )
    {
      num[2].flag=1;
      num[3].flag=1;
      num[6].flag=1;
      num[7].flag=1;
      store[p][0]=-1;
      store[p][1]=1;
      store[p][2]=-1;
      p++;
    }
if(num[0].out==1 && num[1].out==1 && num[4].out==1 && num[5].out==1 && (num[0].flag==0 || num[1].flag==0|| num[4].flag==0 || num[5].flag==0) )
    {
      num[0].flag=1;
      num[1].flag=1;
      num[4].flag=1;
      num[5].flag=1;
      store[p][0]=-1;
      store[p][1]=0;
      store[p][2]=-1;
      p++;
    }
      if(num[0].out==1 && num[1].out==1 &&(num[0].flag==0 || num[1].flag==0) )
    {
      num[0].flag=1;
      num[1].flag=1;
      store[p][0]=0;
      store[p][1]=0;
      store[p][2]=-1;
      p++;
    }
      if(num[0].out==1 && num[2].out==1 &&(num[0].flag==0 || num[2].flag==0) )
    {
      num[0].flag=1;
      num[2].flag=1;
      store[p][0]=0;
      store[p][1]=-1;
      store[p][2]=0;
      p++;
    }
      if(num[4].out==1 && num[6].out==1 &&(num[4].flag==0 || num[6].flag==0) )
    {
      num[4].flag=1;
      num[6].flag=1;
      store[p][0]=1;
      store[p][1]=-1;
      store[p][2]=0;
      p++;
    }
      if(num[2].out==1 && num[6].out==1 &&(num[2].flag==0 || num[6].flag==0) )
    {
      num[2].flag=1;
      num[6].flag=1;
      store[p][0]=-1;
      store[p][1]=1;
      store[p][2]=0;
      p++;
    }
      if(num[0].out==1 && num[4].out==1 &&(num[0].flag==0 || num[4].flag==0) )
    {
      num[0].flag=1;
      num[4].flag=1;
      store[p][0]=-1;
      store[p][1]=0;
      store[p][2]=0;
      p++;
    }
      if(num[1].out==1 && num[3].out==1 &&(num[1].flag==0 || num[3].flag==0) )
    {
      num[1].flag=1;
      num[3].flag=1;
      store[p][0]=0;
      store[p][1]=-1;
      store[p][2]=1;
      p++;
    }
      if(num[5].out==1 && num[7].out==1 &&(num[5].flag==0 || num[7].flag==0) )
    {
      num[5].flag=1;
      num[7].flag=1;
      store[p][0]=1;
      store[p][1]=-1;
      store[p][2]=1;
      p++;
    }
      if(num[3].out==1 && num[7].out==1 &&(num[3].flag==0 || num[7].flag==0) )
    {
      num[3].flag=1;
      num[7].flag=1;
      store[p][0]=-1;
      store[p][1]=1;
      store[p][2]=1;
      p++;
    }
      if(num[1].out==1 && num[5].out==1 &&(num[1].flag==0 || num[5].flag==0) )
    {
      num[1].flag=1;
      num[5].flag=1;
      store[p][0]=-1;
      store[p][1]=0;
      store[p][2]=1;
      p++;
    }
      if(num[2].out==1 && num[3].out==1 &&(num[2].flag==0 || num[3].flag==0) )
    {
      num[2].flag=1;
      num[3].flag=1;
      store[p][0]=0;
      store[p][1]=1;
      store[p][2]=-1;
      p++;
    }
      if(num[6].out==1 && num[7].out==1 &&(num[6].flag==0 || num[7].flag==0) )
    {
      num[6].flag=1;
      num[7].flag=1;
      store[p][0]=1;
      store[p][1]=1;
      store[p][2]=-1;
      p++;
    }
      if(num[4].out==1 && num[5].out==1 &&(num[4].flag==0 || num[5].flag==0) )
    {
      num[4].flag=1;
      num[5].flag=1;
      store[p][0]=1;
      store[p][1]=0;
      store[p][2]=-1;
      p++;
    }
    return p;
}
void Boolean_Eqn()
{
 int i,n,j,p=0,count,num_of1;
   printf("Enter the Number of Input:");
   scanf("%d",&n);
   printf("\n\nEnter OUTPUT for each line of Input: \n\n");
   printf("\t\t\tTruth Table\n\n");
   fprintf(history,"\t\t\tTruth Table\n\n");
   for(i=0;i<n;i++){
   fprintf(history,"%c\t",65+i);
   printf("%c\t",65+i);}
   printf("OUTPUT\n");
   fprintf(history,"OUTPUT\n");
num_of1= bit_print(pow(2,n),n);                                 ///print variable input for Truth table output
if(num_of1==pow(2,n))
{
     printf("\n\nBoolean Equation for abobe Truth Table is: 1");
    fprintf(history,"\n\nBoolean Equation for abobe Truth Table is: 1");
}
else
    {
   if(n==2)
   p= kmap2var(p);
   if(n==3)
    p=kmap3var(p);
       for(i=0;i<pow(2,n);i++)
       {
          if(num[i].out!=0 && num[i].flag==0)
          {
          for(j=0;j<n;j++)
          {
              if(num[i].binary[j]==0)
               store[p][j]=0;
              else
               store[p][j]=1;
          }
          num[i].flag=1;
          p++;
          }
          }
          printf("\n\nBoolean Equation for abobe Truth Table is:\n\n\t\t\t\t");
          fprintf(history,"\n\nBoolean Equation for abobe Truth Table is:\n\n\t\t\t\t");
          for(i=0;i<p;i++)
          {
              for(j=0;j<n;j++)
              {
                  if(store[i][j]==0){
                    fprintf(history,"%c'",65+j);
                    printf("%c'",65+j);}
                  if(store[i][j]==1)
                    {
                    printf("%c",65+j);
                    fprintf(history,"%c",65+j);
                    }
              }
              if(i!=p-1)
              printf("+");
              fprintf(history,"+");
          }
    }
    memset(store,0,sizeof(store));
}
void Choice_Boolean()
{
int i,n1,op;
history= fopen("history.txt","a");
printf("* * *Forming Boolean Eqn(for a given Truth Table)* * *\n\n");
fprintf(history,"\t\tForming Boolean Eqn(for a given Truth Table)\n");
fprintf(history,"\t\t############################################\n\n\n");
  Boolean_Eqn();
  printf("\n\n1.Try again!\n");
    printf("2.Main Menu\n\n");
    printf("Choice Options: ");
    scanf("%d%*c",&n1);
    system("cls");
    design();
    fprintf(history,"\n\n\n");
    fclose(history);
    if(n1==1)
       Choice_Boolean();
    if(n1==2)
    {
        op=options();
        Choice_project(op);
    }
}
///History
void HISTORY(){
    char a[1000];
history = fopen("history.txt","r");
fseek(history,0,SEEK_END);
int filesize = ftell(history);
if(filesize==0)
    printf("Nothing in the history\n");
    fseek(history,0,SEEK_SET);
while(!feof(history)){
    fgets(a,3,history);
printf("%s",a);}

fclose(history);
int option;
printf("\n1.clear history\n");
printf("2.Main menu\n");
printf("\nChoice Option: ");
scanf("%d",&option);
system("cls");
design();
if(option==1){
    history=fopen("history.txt","w");
    fclose(history);
}
       int op=options();
        Choice_project(op);
}
void Choice_project(int op) ///selecting which menu you want to go
{
    if(op==1)
        {
numbersystem();
        }
    if(op==2)
        {
       choiceBCD();}
   if(op==3)
    {
 ChoiceHamming();
    }
   if(op==4)
   {
       choiceASCII();}
    if(op==5)
    {
        Choicegray();}
    if(op==6)
    {
    Truth_table();}
    if(op==7)
        {
       Choice_Boolean();}
    else
        HISTORY();
}
void design()  ///prints logo
{
FILE *dsgn;
char a[1000];
dsgn=fopen("design.txt","r");
while(!feof(dsgn)){
    fgets(a,3,dsgn);
printf("%s",a);}
fclose(dsgn);
printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c",178,178,178,178,178,178,178,178,178,178,178,178,178,178,178);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178);
}
int main()
{
    int op;
    design();
   op= options();
   Choice_project(op);
getch();
}
