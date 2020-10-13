#include<stdio.h>
#include<string.h>

int x, i;
float p, pp, n;
float a, b, c, d, e;
float k, t, ku, ut, ua;
char temp;

struct data{
char nama[100];
char nim[100];
float absen;
float tugas;
float kuis;
float uas;
float uts;
float akhir;
char nilai[100];}

wow[500];

int wadaw(){
do{
printf("<<<===PERCENTAGE OF ASSESSMENT===>>>\n");
printf("================================\n");
printf("Enter the attendance percentage (%%) : ");
	scanf("%f", &k);
printf("Enter a percentage for the assignment     (%%) : ");
	scanf("%f", &t);
printf("Enter the quiz percentage      (%%) : ");
	scanf("%f", &ku);
printf("Enter the Half Semester Exam percentage       (%%) : ");
	scanf("%f", &ut);
printf("Enter the percentage of the Final Semester Examination       (%%) : ");
	scanf("%f", &ua);
	
pp=k + t + ku + ut + ua;

if(pp != 100){
printf("Percentage of assessment          (%%) : %.0f\n", pp);
printf("\n(***PERCENTAGE OF THE RATING MUST BE 100%%***)\n");
printf("---------------------------------------------------\n");}
if(pp == 100){
printf("Percentage of assessment          (%%) : %.0f\n", pp);}}
while(pp != 100);

printf("---------------------------------------------------\n");

printf("Enter the meeting total  : ");
	scanf("%f", &p);
printf("Enter the number of students : ");
	scanf("%f", &n);

printf("---------------------------------------------------\n");

for(i = 1; i <= n; i++){
printf("Name 	    : ");
	scanf("%c", &temp);
	scanf("%[^\n]s", &wow[i].nama);
printf("Student ID Number 	    : ");
	scanf("%s", &wow[i].nim);
printf("Presence   : ");
	scanf("%f", &wow[i].absen);
printf("Assignment grades : ");
	scanf("%f", &wow[i].tugas);
printf("Quiz scores  : ");
	scanf("%f", &wow[i].kuis);
printf("Mid-Semester Exam scores   : ");
	scanf("%f", &wow[i].uts);
printf("Final Semester Exam Value   : ");
	scanf("%f", &wow[i].uas);
	
printf("---------------------------------------------------\n");

a = ((wow[i].absen / p) * (k / 100) * 100);
b = ((wow[i].tugas) * (t / 100));
c = ((wow[i].kuis) * (ku / 100));
d = ((wow[i].uts) * (ut / 100));
e = ((wow[i].uas) * (ua / 100));

wow[i].akhir = a + b + c + d + e;

if(wow[i].akhir <= 100 && wow[i].akhir >= 80){
strcpy(wow[i].nilai, "A");}
else if(wow[i].akhir <= 79 && wow[i].akhir >= 60){
strcpy(wow[i].nilai, "B+");}
else if(wow[i].akhir <=59 && wow[i].akhir >= 55){
strcpy(wow[i].nilai, "B");}
else if(wow[i].akhir <= 54 && wow[i].akhir >= 50){
strcpy(wow[i].nilai, "C+");}
else if(wow[i].akhir <= 49 && wow[i].akhir >= 45){
strcpy(wow[i].nilai, "C");}
else if(wow[i].akhir <= 44 && wow[i].akhir >= 40){
strcpy(wow[i].nilai, "D+");}
else if(wow[i].akhir <= 39 && wow[i].akhir >= 35){
strcpy(wow[i].nilai, "D");}
else {strcpy(wow[i].nilai, "E");}}
}

main(){
printf("|***PROGRAM FOR CALCULATING FINAL VALUE***|\n");
printf("|=========================================|\n");
printf("|Choose a course:                         |\n");
printf("|1. Character Building                    |\n");
printf("|2. Physics                               |\n");
printf("|=========================================|\n");
printf("Choose a course: ");
	scanf("%d", &x);
printf("---------------------------------------------------\n");

switch(x){
case 1:
wadaw();

printf("\n===============================================================================================================\n");
printf("|                                                Character Building                                             |\n");
printf("|=================================================================================================================|");
printf("\n|                                                       (2 SKS)                                                   |");
printf("\n|===============================================================================================================|\n");
printf("|No.|            Student Name            |   ID Number   | Presence | Assignment | Quiz | Mid Test Semester | Final Test Semester | Final Score | Grade |\n");
printf("|===|====================================|===============|==========|============|======|===================|=====================|=============|=======|\n");
for(i = 1; i <= n; i++){
printf("|%-3i|", i);
printf("%-38s|", wow[i].nama);
printf("%9s|", wow[i].nim);
printf("%-11.0f|", wow[i].absen);
printf("%-7.0f|", wow[i].tugas);
printf("%-6.0f|", wow[i].kuis);
printf("%-5.0f|", wow[i].uts);
printf("%-5.0f|", wow[i].uas);
printf("%-13f|", wow[i].akhir);
printf("%-7s|", wow[i].nilai);
printf("\n");}
printf("===================================================================================================================\n");
break;

case 2:
wadaw();

printf("\n===================================================================================================================\n");
printf("|                                                       Physics                                                    |\n");
printf("|=================================================================================================================|");
printf("\n|                                                       (3 SKS)                                                   |");
printf("\n|=================================================================================================================|\n");
printf("|No.|            Student Name            |   ID Number   | Presence | Assignment | Quiz | Mid Test Semester | Final Test Semester | Final Score | Grade |\n");
printf("|===|====================================|===============|==========|============|======|===================|=====================|=============|=======|\n");
for(i = 1; i <= n; i++){
printf("|%-3i|", i);
printf("%-38s|", wow[i].nama);
printf("%9s|", wow[i].nim);
printf("%-11.0f|", wow[i].absen);
printf("%-7.0f|", wow[i].tugas);
printf("%-6.0f|", wow[i].kuis);
printf("%-5.0f|", wow[i].uts);
printf("%-5.0f|", wow[i].uas);
printf("%-13f|", wow[i].akhir);
printf("%-7s|", wow[i].nilai);
printf("\n");}
printf("===================================================================================================================\n");
break;

default: printf("(***NO COURSE SELECTED***)");
}
}
