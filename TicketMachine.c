#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct tickets {
	 float price ;
	 char name[15];
	 int count;         // δημιουργία δομής για εισιτήρια  με κοστος ονομα εναν μετρητή και ένα συνολικό ποσό 
	 float need_to_pay;
 }ticket;

void selectionChoice(int choice_of_ticket, int num_tick){    // δημιουργία συνάρτησης  για το menu επιλογών πέρνει σαν παραμέτρους την επιλογή του εισιτηρίου και τον αριθμό τον εισιτηρίων
	switch(choice_of_ticket){
		case 1 :
		ticket.price =1.40;
		strcpy(ticket.name, "Ενίαιο");
		ticket.count+=num_tick; // προσθέτει το πλήθος των εισητρίων που εισαγάγει ο χρήστης
		ticket.need_to_pay = ticket.price*ticket.count; // βγάζει το συνολικό ποσό που πρέπει να πληρώσει
			break;
		case 2 :
		ticket.price =0.60;
		strcpy(ticket.name, "Μειωμένο");
		ticket.count+=num_tick;
		ticket.need_to_pay = ticket.price*ticket.count;
			
			break;
		case 3 :
		ticket.price =4.50;
		strcpy(ticket.name, "Ημερήσιο");
		ticket.count+=num_tick;
		ticket.need_to_pay = ticket.price*ticket.count;
			break;
		case 4 :
		ticket.price =9.00;
		strcpy(ticket.name, "Εβδομαδιαίο");
		ticket.count+=num_tick;
		ticket.need_to_pay = ticket.price*ticket.count;
			break;
		case 5 :
		ticket.price =10.00;
		strcpy(ticket.name, "Αεροδρομίου");
		ticket.count+=num_tick;
		ticket.need_to_pay = ticket.price*ticket.count;
			break;
			
	}
			
}

double kermata(double *money_added){ // επειδη χρησιμοποιώ 2 φορές την όλη διαδιακασία την έκανα συνάρτηση και  με κλήση κατά αναφορά
		printf("Πρέπει να εισαγάγετε: %0.2f Ευρώ συνολικά",ticket.need_to_pay);	// του ζητάει το ποσο που υπολογιστηκε
	
	printf("\n");	
	printf("Πόσα εισάγετε;   ");
	scanf("%lf",&*money_added); 
	while( *money_added != 0.05 && *money_added != 0.1 &&  *money_added != 0.2 &&  *money_added != 0.5 &&  *money_added != 1 &&  *money_added != 2 &&  *money_added != 5 &&  *money_added != 10 &&  *money_added != 20 &&  *money_added != 50 ){
		printf("Εισάγετε μια έγκυρη τιμή : 0.05 / 0.1 / 0.2 / 0.5 / 1 / 2 / 5 / 10 / 20 / 50   :");
		printf("Πρέπει να εισαγάγετε: %0.2f Ευρώ συνολικά ",ticket.need_to_pay);	// του ζητάει συγκεκριμένες τιμές που να αντιστοιχούν σε κερματα η χαρτονομίσματα και επαναλαμβανεται στις λάθος
		printf("\n");	
		printf("Πόσα εισάγετε;  ");
		scanf("%lf",&*money_added);
	}
	
}


double resta(double amount){ // Επέλεξα να υλοποιήσω ανδρομική συνάρτηση  . Καλείται μεχρι να γίνει το ποσό <=0
	
	ticket.need_to_pay-=amount; // πάρε το ποσο που δίνει ο χρηστης και αφαίρεσε το από το συνολικο ποσό που πρέπει να πληρωθει
	if(ticket.need_to_pay<=0){ // αν το ποσο γίνει ίσο με 0 η μικρότερο μπες εδώ
		if(ticket.need_to_pay < amount) // αν το ποσο γίνει αρνητικό 
			printf("Παρακαλώ πάρτε τα ρέστα σας %0.2f ",fabs(ticket.need_to_pay)); // βγάλε στο χρήστη το ποσό που του επιστρέφεται (χρήση της συνάρτηση fabs()  apo th math.h για την εμφάνιση της απόλυτης τιμής)
		else
			printf("Καλη συνέχεια ");	// αν το ποσο μπει ακριβώς και δεν υπάρχουν ρεστα
		return 0;
  	
  	}
  	else {// αν το ποσό όμως είναι μεγαλύτερο απο 0
  		
  	    kermata(&amount);// ρώτα ξανα το χρήστη 

		return resta(amount);// χρησιμποιείται  αναδρομικά η συναρτηση 
  	}
	
}

int main ()
{
    system("chcp 1253>nul");
	int  choice_of_ticket, num_of_tickets ;// μεταβλητές
	double money;
		
	printf("Παρακαλώ επιλέξτε ένα απο τα παρακάτω :\n 1.Ενιαίο 1.40 ευρώ \n 2.Μειωμένο 0.60 ευρώ \n 3.Ημερήσιο 4.50 ευρώ \n 4.Εβδομαδιαίο 9.00 ευρώ \n 5.Αεροδρομίου 10.00 :\n ");
	do{
		printf("Παρακαλώ εισάγετε την επιλογή σας:  ");// ζητάει απο το χρήστη τις 5 επιλογές και επαναλαμβάνεται αν εισάγει κάτι διαφορετικό
		scanf("%d",&choice_of_ticket);
		
	}while(choice_of_ticket >5 || choice_of_ticket <1 );
	
	do{
		printf("Πόσα εισητήρια θέλετε:  "); // ζηταει τον αριθμό εισιτηρίων αρκει να ναι πάνω απο 1
		scanf("%d",&num_of_tickets);
		
	}while(num_of_tickets <1 );	
	
	
	selectionChoice(choice_of_ticket,num_of_tickets);// χρήση της συνάρτησης για το menu 
	
	kermata(&money);// συνάρτηση για τον έλεγχο των κερμάτων

	resta(money); // χρηση της συνάρτησης για τα ρεστα
	
	return 0;
}




