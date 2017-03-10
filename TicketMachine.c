#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct tickets {
	 float price ;
	 char name[15];
	 int count;         // ���������� ����� ��� ���������  �� ������ ����� ���� ������� ��� ��� �������� ���� 
	 float need_to_pay;
 }ticket;

void selectionChoice(int choice_of_ticket, int num_tick){    // ���������� ����������  ��� �� menu �������� ������ ��� ����������� ��� ������� ��� ���������� ��� ��� ������ ��� ����������
	switch(choice_of_ticket){
		case 1 :
		ticket.price =1.40;
		strcpy(ticket.name, "������");
		ticket.count+=num_tick; // ��������� �� ������ ��� ��������� ��� ��������� � �������
		ticket.need_to_pay = ticket.price*ticket.count; // ������ �� �������� ���� ��� ������ �� ��������
			break;
		case 2 :
		ticket.price =0.60;
		strcpy(ticket.name, "��������");
		ticket.count+=num_tick;
		ticket.need_to_pay = ticket.price*ticket.count;
			
			break;
		case 3 :
		ticket.price =4.50;
		strcpy(ticket.name, "��������");
		ticket.count+=num_tick;
		ticket.need_to_pay = ticket.price*ticket.count;
			break;
		case 4 :
		ticket.price =9.00;
		strcpy(ticket.name, "�����������");
		ticket.count+=num_tick;
		ticket.need_to_pay = ticket.price*ticket.count;
			break;
		case 5 :
		ticket.price =10.00;
		strcpy(ticket.name, "�����������");
		ticket.count+=num_tick;
		ticket.need_to_pay = ticket.price*ticket.count;
			break;
			
	}
			
}

double kermata(double *money_added){ // ������ ����������� 2 ����� ��� ��� ����������� ��� ����� ��������� ���  �� ����� ���� �������
		printf("������ �� ����������: %0.2f ���� ��������",ticket.need_to_pay);	// ��� ������ �� ���� ��� ������������
	
	printf("\n");	
	printf("���� ��������;   ");
	scanf("%lf",&*money_added); 
	while( *money_added != 0.05 && *money_added != 0.1 &&  *money_added != 0.2 &&  *money_added != 0.5 &&  *money_added != 1 &&  *money_added != 2 &&  *money_added != 5 &&  *money_added != 10 &&  *money_added != 20 &&  *money_added != 50 ){
		printf("�������� ��� ������ ���� : 0.05 / 0.1 / 0.2 / 0.5 / 1 / 2 / 5 / 10 / 20 / 50   :");
		printf("������ �� ����������: %0.2f ���� �������� ",ticket.need_to_pay);	// ��� ������ ������������� ����� ��� �� ������������ �� ������� � �������������� ��� ��������������� ���� �����
		printf("\n");	
		printf("���� ��������;  ");
		scanf("%lf",&*money_added);
	}
	
}


double resta(double amount){ // ������� �� ��������� ��������� ���������  . �������� ����� �� ����� �� ���� <=0
	
	ticket.need_to_pay-=amount; // ���� �� ���� ��� ����� � ������� ��� �������� �� ��� �� �������� ���� ��� ������ �� ��������
	if(ticket.need_to_pay<=0){ // �� �� ���� ����� ��� �� 0 � ��������� ���� ���
		if(ticket.need_to_pay < amount) // �� �� ���� ����� �������� 
			printf("�������� ����� �� ����� ��� %0.2f ",fabs(ticket.need_to_pay)); // ����� ��� ������ �� ���� ��� ��� ������������ (����� ��� ��������� fabs()  apo th math.h ��� ��� �������� ��� �������� �����)
		else
			printf("���� �������� ");	// �� �� ���� ���� ������� ��� ��� �������� �����
		return 0;
  	
  	}
  	else {// �� �� ���� ���� ����� ���������� ��� 0
  		
  	    kermata(&amount);// ���� ���� �� ������ 

		return resta(amount);// ��������������  ���������� � ��������� 
  	}
	
}

int main ()
{
    system("chcp 1253>nul");
	int  choice_of_ticket, num_of_tickets ;// ����������
	double money;
		
	printf("�������� �������� ��� ��� �� �������� :\n 1.������ 1.40 ���� \n 2.�������� 0.60 ���� \n 3.�������� 4.50 ���� \n 4.����������� 9.00 ���� \n 5.����������� 10.00 :\n ");
	do{
		printf("�������� �������� ��� ������� ���:  ");// ������ ��� �� ������ ��� 5 �������� ��� ��������������� �� ������� ���� �����������
		scanf("%d",&choice_of_ticket);
		
	}while(choice_of_ticket >5 || choice_of_ticket <1 );
	
	do{
		printf("���� ��������� ������:  "); // ������ ��� ������ ���������� ����� �� ��� ���� ��� 1
		scanf("%d",&num_of_tickets);
		
	}while(num_of_tickets <1 );	
	
	
	selectionChoice(choice_of_ticket,num_of_tickets);// ����� ��� ���������� ��� �� menu 
	
	kermata(&money);// ��������� ��� ��� ������ ��� ��������

	resta(money); // ����� ��� ���������� ��� �� �����
	
	return 0;
}




