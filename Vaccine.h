#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Beneficiariy{
	char name[50];
	int age;
	char gender[10];
	char reference_id[20];//aadhaar card,ration card,etc
	char phone_number[10];
	char address[100];
	char vaccinated_date[20];
	int VaccinationStatus;
	char VaccinatedDate[25];
	char location[100];
	char VaccineName[100];
};
struct Beneficiariy b;
int count;
void addBeneficiaries();
void print_beneficiaries();
void searchBeneficiarybyID();
void sortBeneficiariesByName();
void sortBeneficiariesByVaccineName();
void sortBeneficiariesByDate();
void calculateAgeStatistics();
void numBeneficiaries();
void sortBeneficiariesByLocation();
void searchBeneficiaryByage();
void searchBeneficiaryByVaccineName();
void addBeneficiaries()
{
	printf("\n Add Beneficiarie name :");
	scanf("%s",b.name);
	printf("\n age:");
	scanf("%d",&b.age);
	printf("\n Gender:");
	scanf("%s",b.gender);
	printf("\n Address:");
	scanf("%s",b.address);
	printf("\n phonenumber:");
	scanf("%s",b.phone_number);
	printf("\n enter the reference id :");
	scanf("%s",b.reference_id);
	printf("\n enter the Vacccination Date:");
	scanf("%s",b.VaccinatedDate);
	printf("vaccination status:");
	scanf("%d",&b.VaccinationStatus);
	printf("place of Vaccination Hospital/Health centre:");
	scanf(" %s",b.location);
	printf("place of Vaccine Name:");
	scanf(" %s",b.VaccineName);
		FILE *fb;
	fb=fopen("Beneficiariy.dat","a");
	fwrite(&b,sizeof(struct Beneficiariy),1,fb);
	fclose(fb); 
}
void print_beneficiaries()
{
	char opt;
FILE*fb;

	fb=fopen("Beneficiariy.dat","r");
	
	printf("\n<<<Beneficiariy DETAILS>>>\n");
	printf("ID    Name    Gender    Age    VaccineName\n--------------------------------------------------");
	while(fread(&b,sizeof(struct Beneficiariy),1,fb)>0)
	printf("\n%s %-11s  %-6s   %-3d  %s",b.reference_id,b.name,b.gender,b.age,b.VaccineName);


	fclose(fb);
	
}
void certificate();
void certificate()
{
FILE*fb;

	fb=fopen("Beneficiariy.dat","r");

	
    char id[20];
    printf("\nEnter Id: ");
    scanf("%s", id);

    int found = 0;
    while (fread(&b, sizeof(struct Beneficiariy), 1, fb) > 0) {
        if (strcmp(b.reference_id, id) == 0) {
            found = 1;
            printf("\n\tVACCINATION REGISTRATION SYSTEM\t \n");
            printf("\nBeneficiary Name  :%s", b.name);
            printf("\nBeneficiary Age   :%d", b.age);
            printf("\nGender\t\t:%s", b.gender);
            printf("\nVaccination status :%d", b.VaccinationStatus);
            printf("\nDate of Vaccination:%s",b.VaccinatedDate);
            printf("\nVaccine Name :%s",b.VaccineName);
            printf("\nplace of Vaccination:%s",b.location);
            printf("\nReference Idno:\t%s", b.reference_id);
            printf("\nPhone Number\t:%s", b.phone_number);
        }
    }

    fclose(fb);

    if (!found) {
        printf("\nNo beneficiary with the provided ID found.");
    }
}
void searchBeneficiarybyID(){

 FILE *fb;
    char id[20];
    char opt;

    fb = fopen("Beneficiariy.dat", "r");

    printf("\nEnter Id: ");
    scanf("%s", id);

    printf("\n<<<Beneficiariy DETAILS>>>\n");
    printf("ID    Name    Gender    Age\n--------------------------------------------------");

    while (fread(&b, sizeof(struct Beneficiariy), 1, fb) > 0) {
        if (strcmp(b.reference_id, id) == 0) {
            printf("\n%s %-11s  %-6s   %-3d", b.reference_id, b.name, b.gender, b.age);
            printf("Do you Want Certificate? (Y/N): ");
            scanf(" %c", &opt);

            if (opt == 'Y' || opt == 'y') {
                certificate();
            } else {
                exit(0);
            }
        }
    }

    printf("\nThere is no beneficiary with the provided ID.");
    fclose(fb);
}
void sortBeneficiariesByName() {
    struct Beneficiariy beneficiaries[100]; // Assuming a maximum of 100 beneficiaries
    int numBeneficiaries = 0;
	int i,j;
    FILE *fb;
    fb = fopen("Beneficiariy.dat", "r");

    while (fread(&b, sizeof(struct Beneficiariy), 1, fb) > 0) {
        beneficiaries[numBeneficiaries] = b;
        numBeneficiaries++;
    }
    fclose(fb);

    // Sort beneficiaries by name using bubble sort
    for( i = 0; i < numBeneficiaries - 1; i++) {
        for( j = 0; j < numBeneficiaries - i - 1; j++) {
            if (strcmp(beneficiaries[j].name, beneficiaries[j + 1].name) > 0) {
                struct Beneficiariy temp = beneficiaries[j];
                beneficiaries[j] = beneficiaries[j + 1];
                beneficiaries[j + 1] = temp;
            }
        }
    }

    printf("\n<<<Beneficiaries Sorted by Name>>>\n");
    printf("ID    Name    Gender    Age    VaccineName    Address\n--------------------------------------------------");

    for(i = 0; i < numBeneficiaries; i++) {
        struct Beneficiariy beneficiary = beneficiaries[i];
        printf("\n%s %-11s  %-6s   %-3d  %s   %s", beneficiary.reference_id, beneficiary.name, beneficiary.gender, beneficiary.age, beneficiary.VaccineName, beneficiary.address);
    }
}
void sortBeneficiariesByAge() {
    struct Beneficiariy beneficiaries[100]; // Assuming a maximum of 100 beneficiaries
    int numBeneficiaries = 0;
	int i,j;
    FILE *fb;
    fb = fopen("Beneficiariy.dat", "r");

    while (fread(&b, sizeof(struct Beneficiariy), 1, fb) > 0) {
        beneficiaries[numBeneficiaries] = b;
        numBeneficiaries++;
    }
    fclose(fb);

    // Sort beneficiaries by age using bubble sort
    for(i = 0; i < numBeneficiaries - 1; i++) {
        for(j = 0; j < numBeneficiaries - i - 1; j++) {
            if (beneficiaries[j].age > beneficiaries[j + 1].age) {
                struct Beneficiariy temp = beneficiaries[j];
                beneficiaries[j] = beneficiaries[j + 1];
                beneficiaries[j + 1] = temp;
            }
        }
    }

    printf("\n<<<Beneficiaries Sorted by Age>>>\n");
    printf("ID    Name    Gender    Age    VaccineName    Address\n--------------------------------------------------");

    for (i = 0; i < numBeneficiaries; i++) {
        struct Beneficiariy beneficiary = beneficiaries[i];
        printf("\n%s %-11s  %-6s   %-3d  %s   %s", beneficiary.reference_id, beneficiary.name, beneficiary.gender, beneficiary.age, beneficiary.VaccineName, beneficiary.address);
    }
}

void sortBeneficiariesByDate() {
    struct Beneficiariy beneficiaries[100]; // Assuming a maximum of 100 beneficiaries
    int numBeneficiaries = 0;
	int i,j;
    FILE *fb;
    fb = fopen("Beneficiariy.dat", "r");

    while (fread(&b, sizeof(struct Beneficiariy), 1, fb) > 0) {
        beneficiaries[numBeneficiaries] = b;
        numBeneficiaries++;
    }
    fclose(fb);

    // Sort beneficiaries by date of vaccination using bubble sort
    for(i = 0; i < numBeneficiaries - 1; i++) {
        for(j = 0; j < numBeneficiaries - i - 1; j++) {
            // Assuming the date format is "YYYY-MM-DD"
            int year1, month1, day1;
            int year2, month2, day2;
            scanf(beneficiaries[j].VaccinatedDate, "%d-%d-%d", &year1, &month1, &day1);
            scanf(beneficiaries[j + 1].VaccinatedDate, "%d-%d-%d", &year2, &month2, &day2);

            if (year1 > year2 || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2)) {
                struct Beneficiariy temp = beneficiaries[j];
                beneficiaries[j] = beneficiaries[j + 1];
                beneficiaries[j + 1] = temp;
            }
        }
    }

    printf("\n<<<Beneficiaries Sorted by Date of Vaccination>>>\n");
    printf("ID    Name    Gender    Age    PhoneNumber    Address    Vaccination Date\n------------------------------------------------------------------------");

    for(i = 0; i < numBeneficiaries; i++) {
        struct Beneficiariy beneficiary = beneficiaries[i];
        printf("\n%s %-11s  %-6s   %-3d  %s   %s   %s", beneficiary.reference_id, beneficiary.name, beneficiary.gender, beneficiary.age, beneficiary.phone_number, beneficiary.address, beneficiary.VaccinatedDate);
    }
}

void calculateStatistics() {
    struct Beneficiariy beneficiaries[100]; // Assuming a maximum of 100 beneficiaries
    int numBeneficiaries = 0;
	int i,j;
    FILE *fb;
    fb = fopen("Beneficiariy.dat", "r");

    while (fread(&b, sizeof(struct Beneficiariy), 1, fb) > 0) {
        beneficiaries[numBeneficiaries] = b;
        numBeneficiaries++;
    }
    fclose(fb);

    int totalAge = 0;
    int minAge = beneficiaries[0].age;
    int maxAge = beneficiaries[0].age;

    for(i = 0; i < numBeneficiaries; i++) {
        totalAge += beneficiaries[i].age;
        if (beneficiaries[i].age < minAge)
            minAge = beneficiaries[i].age;
        if (beneficiaries[i].age > maxAge)
            maxAge = beneficiaries[i].age;
    }

    float averageAge = (float)totalAge / numBeneficiaries;

    printf("\n<<<Age Statistics>>>");
    printf("\nTotal Beneficiaries: %d", numBeneficiaries);
    printf("\nMinimum Age: %d", minAge);
    printf("\nMaximum Age: %d", maxAge);
    printf("\nAverage Age: %.2f", averageAge);
    
}
void numBeneficiaries()
{
 int numBeneficiaries = 0;

    FILE *fb;
    fb = fopen("Beneficiariy.dat", "r");

    while (fread(&b, sizeof(struct Beneficiariy), 1, fb) > 0) {
       
        numBeneficiaries++;
    }
    printf("\n No.of beneficiaries %d till now",numBeneficiaries);
    fclose(fb);	
}
//void searchBeneficiaryByage();
void calculateAgeStatistics();
void calculateAgeStatistics() {
    struct Beneficiariy beneficiaries[100]; // Assuming a maximum of 100 beneficiaries
    int numBeneficiaries = 0;
	int i,j;
    FILE *fb;
    fb = fopen("Beneficiariy.dat", "r");

    while (fread(&b, sizeof(struct Beneficiariy), 1, fb) > 0) {
        beneficiaries[numBeneficiaries] = b;
        numBeneficiaries++;
    }
    fclose(fb);

    int ageCounts[6] = {0}; // Array to store the counts for different age groups
    int totalBeneficiaries = 0;

    for(i = 0; i < numBeneficiaries; i++) {
        int age = beneficiaries[i].age;
        if (age >= 18 && age <= 25) {
            ageCounts[0]++;
        } else if (age >= 26 && age <= 35) {
            ageCounts[1]++;
        } else if (age >= 36 && age <= 45) {
            ageCounts[2]++;
        } else if (age >= 46 && age <= 55) {
            ageCounts[3]++;
        } else if (age >= 56 && age <= 65) {
            ageCounts[4]++;
        } else if (age > 65) {
            ageCounts[5]++;
        }
        totalBeneficiaries++;
    }

    printf("\n<<<Vaccination Statistics by Age Group>>>\n");
    printf("Age Group\t\tCount\t\tPercentage\n");
    printf("-----------------------------------------\n");

    char ageGroups[6][15] = {"18-25", "26-35", "36-45", "46-55", "56-65", "65+"};

    for(i = 0; i < 6; i++) {
        float percentage = (float)ageCounts[i] / totalBeneficiaries * 100;
        printf("%s\t\t\t%d\t\t%.2f%%\n", ageGroups[i], ageCounts[i], percentage);

        // Print bar graph
        printf("|");
        int barLength = (int)(percentage / 2); // Adjust the scaling factor as needed
        for(j = 0; j < barLength; j++) {
            printf("=");
        }
        printf("\n");
    }
}
void sortBeneficiariesByLocation() {
    struct Beneficiariy beneficiaries[100]; // Assuming a maximum of 100 beneficiaries
    int numBeneficiaries = 0;
    int i, j;

    FILE* fb;
    fb = fopen("Beneficiariy.dat", "r");
    while (fread(&b, sizeof(struct Beneficiariy), 1, fb) > 0) {
        beneficiaries[numBeneficiaries] = b;
        numBeneficiaries++;
    }
    fclose(fb);

    // Sort beneficiaries by location using bubble sort
    for (i = 0; i < numBeneficiaries - 1; i++) {
        for (j = 0; j < numBeneficiaries - i - 1; j++) {
            if (strcmp(beneficiaries[j].location, beneficiaries[j + 1].location) > 0) {
                struct Beneficiariy temp = beneficiaries[j];
                beneficiaries[j] = beneficiaries[j + 1];
                beneficiaries[j + 1] = temp;
            }
        }
    }

    printf("\n<<<Beneficiaries Sorted by Location>>>\n");
    printf("ID    Name    Gender    Age    VaccineName    Location\n------------------------------------------------------");

    for (i = 0; i < numBeneficiaries; i++) {
        struct Beneficiariy beneficiary = beneficiaries[i];
        printf("\n%s %-11s  %-6s   %-3d  %s   %s", beneficiary.reference_id, beneficiary.name, beneficiary.gender, beneficiary.age, beneficiary.VaccineName, beneficiary.location);
    }
}

void sortBeneficiariesByVaccineName() {
    struct Beneficiariy beneficiaries[100]; // Assuming a maximum of 100 beneficiaries
    int numBeneficiaries = 0;
    int i, j;

    FILE* fb;
    fb = fopen("Beneficiariy.dat", "r");

    while (fread(&b, sizeof(struct Beneficiariy), 1, fb) > 0) {
        beneficiaries[numBeneficiaries] = b;
        numBeneficiaries++;
    }
    fclose(fb);

    // Sort beneficiaries by vaccine name using bubble sort
    for(i = 0; i < numBeneficiaries - 1;i++){
        for(j = 0; j < numBeneficiaries - i - 1; j++) {
            if(strcmp(beneficiaries[j].VaccineName, beneficiaries[j + 1].VaccineName) > 0) {
                struct Beneficiariy temp = beneficiaries[j];
                beneficiaries[j] = beneficiaries[j + 1];
                beneficiaries[j + 1] = temp;
            }
        }
    }

    printf("\n<<<Beneficiaries Sorted by Vaccine Name>>>\n");
    printf("ID    Name    Gender    Age    VaccineName    Location\n------------------------------------------------------");

    for (i = 0; i < numBeneficiaries; i++) {
        struct Beneficiariy beneficiary = beneficiaries[i];
        printf("\n%s %-11s  %-6s   %-3d  %s   %s", beneficiary.reference_id, beneficiary.name, beneficiary.gender, beneficiary.age, beneficiary.VaccineName, beneficiary.location);
    }
}
 void searchBeneficiaryByVaccineName() {
     FILE *fb;
    char searchName[100];
    int found = 0;

    fb = fopen("Beneficiariy.dat", "r");

    printf("Enter the Vaccine Name to search: ");
    scanf("%s", searchName);

    printf("\n<<<Beneficiary Details with Vaccine Name: %s>>>\n", searchName);
    printf("ID    Name    Gender    Age    Vaccination Status    Vaccination Date\n---------------------------------------------------------------------");

    while (fread(&b, sizeof(struct Beneficiariy), 1, fb) > 0) {
        if (strcmp(b.VaccineName, searchName) == 0) {
            found = 1;
            printf("\n%s %-11s  %-6s   %-3d  %d   %s", b.reference_id, b.name, b.gender, b.age, b.VaccinationStatus, b.VaccinatedDate);
        }
    }

    fclose(fb);

    if (!found) {
        printf("\nNo beneficiaries found with the provided Vaccine Name: %s", searchName);
    }
}
void searchBeneficiaryByName() {
    FILE* fb;
    char name[50];
    int found = 0;

    fb = fopen("Beneficiariy.dat", "r");
    printf("\nEnter the name to search: ");
    scanf("%s", name);

    printf("\n<<<Beneficiaries Matching the Name: %s>>>\n", name);
    printf("ID    Name    Gender    Age    VaccineName\n--------------------------------------------------");

    while (fread(&b, sizeof(struct Beneficiariy), 1, fb) > 0) {
        if (strcmp(b.name, name) == 0) {
            printf("\n%s %-11s  %-6s   %-3d  %s", b.reference_id, b.name, b.gender, b.age, b.VaccineName);
            found = 1;
        }
    }

    fclose(fb);

    if (!found) {
        printf("\nNo beneficiaries found with the provided name: %s", name);
    }
}
void searchBeneficiaryByAge() {
    int age;
    int found = 0;

    printf("Enter age to search beneficiaries: ");
    scanf("%d", &age);

    FILE* fb;
    fb = fopen("Beneficiariy.dat", "r");

    printf("\n<<<Beneficiary Details>>>\n");
    printf("ID    Name    Gender    Age    VaccineName\n--------------------------------------------------");

    while (fread(&b, sizeof(struct Beneficiariy), 1, fb) > 0) {
        if (b.age == age) {
            printf("\n%s %-11s  %-6s   %-3d  %s", b.reference_id, b.name, b.gender, b.age, b.VaccineName);
            found = 1;
        }
    }

    fclose(fb);

    if (!found) {
        printf("\nNo beneficiaries found with the provided age.\n");
    }
}

