#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Vaccine.h"
int main()
{
int choice;
while(1){
printf("\n\n========WELCOME TO VACCINATION CENTRE============");
printf("\n\nPlease select your prefered operation");
printf("\n\n1.to add Beneficiaries name:");
printf("\n2.Show Beneficiaries details");
printf("\n3.SearchByVaccineName");
printf("\n4.SearchingByName");
printf("\n5.SearchingByAge");
printf("\n6.Searching Beneficiaries via ID:");
printf("\n7.statistics Beneficiaries via Age");
printf("\n8.statistics of Vaccination persons: ");
printf("\n9.Sorting ascending order:");
printf("\n10.Count of Vaccination");
printf("\n11.Certificate Beneficiaries via ID: ");
printf("\n12.Exit\n");
printf("\n Your choice:\t");
scanf("%d",&choice);	
switch(choice)
{
	case 1:addBeneficiaries();
	break;
	case 2: print_beneficiaries();
	break;
	case 3:searchBeneficiaryByVaccineName();
	break;
	case 4:searchBeneficiaryByName();
	break;
	case 5:searchBeneficiaryByAge(); 
	break;
	case 6:searchBeneficiarybyID();
	break;
	case 7: calculateAgeStatistics(); 
	break;
	case 8:calculateStatistics();
                break;
    case 9: printf("\nSort Beneficiaries");
            printf("\n1. Sort by Name");
            printf("\n2. Sort by Age");
            printf("\n3. Sort by Date of Vaccination");
            printf("\n4.Sort by Location");
            printf("\n5.Sort by Vaccination Name");
            printf("\nEnter your choice: ");
            int sortChoice;
            scanf("%d", &sortChoice);
            switch (sortChoice) {
                    case 1:
                        sortBeneficiariesByName();
                        break;
                    case 2:
                        sortBeneficiariesByAge();
                        break;
                    case 3:
                        sortBeneficiariesByDate();
                        break;
                    case 4:sortBeneficiariesByLocation();
                    	break;
                    case 5:sortBeneficiariesByVaccineName();
                    	break;
                    }
	case 10:numBeneficiaries();
	break;
	case 11:certificate();
	break;
	case 12:exit(0);
	break;
	default:printf("\n you entered wrong choice");	
		break;
}
}
return 0;
}

