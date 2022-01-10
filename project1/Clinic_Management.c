/************************************************************************************/
/************************************ HEADR FILES ***********************************/
/************************************************************************************/

#include<stdio.h>
#include "Std_types.h"
#include "Clinic_Management.h"
#define password  1234 

/*************************************** Global **************************************/
typedef struct client
{
	uint8 Name[30];
	uint8 Age; 
	uint8 Gender[10]; 
    uint32 ID;
	uint8 Appointment;
	
}USER;


uint8 i=0 , Place_1=0,Place_2=0,Place_3=0,Place_4=0,Place_5=0 , flag = 0;
USER ID_Array[5] ;
uint8 Size = sizeof(ID_Array)/sizeof(ID_Array[0]);




/*************************************************************/
/****************** IMPLEMENTATION FUNCTION ******************/
/*************************************************************/



/******************************   Mode_System  *******************************/

void If_User()
{
	uint32 User_ID , flag = 0 ; 
	printf("Enter Your ID = ");
	scanf("%d" , &User_ID ); 
	for(uint8 Counter_2 = 0 ; Counter_2< 5; Counter_2++)
	{
	    if(User_ID==ID_Array[Counter_2].ID)
	    {    flag = 0 ;
			 printf("Your name is        = %s\n",ID_Array[Counter_2].Name   );
			 printf("Your Age is         = %d\n",ID_Array[Counter_2].Age    );
			 printf("Your Gender is      = %s\n",ID_Array[Counter_2].Gender );
			 printf("Your ID is          = %d\n",ID_Array[Counter_2].ID     );
			 
			 if(ID_Array[Counter_2].Appointment==1)
	         {
	         	 printf("Your Appointment is = 2pm    to 2:30pm\n" )    ; 	
	         }
	         if(ID_Array[Counter_2].Appointment==2)
	         {
	         	 printf("Your Appointment is = 2:30pm to 3pm\n"    )    ; 
	         }
	         if(ID_Array[Counter_2].Appointment==3)
	         {
	         	printf("Your Appointment is = 3pm    to 3:30pm\n"  )    ; 	
	         }
	         if(ID_Array[Counter_2].Appointment==4)
	         {
	         	printf("Your Appointment is = 4pm    to 4:30pm\n"  )    ; 	
	         }
	         if(ID_Array[Counter_2].Appointment==5)
	         {
	         	printf("Your Appointment is = 4:30pm to 5pm\n"     )    ; 
	         }
			 main();
			 break; 
	    }
		if(Counter_2==4)
		{
			printf("Incoreect ID\n")    ; 
			main();
		}
	}
}

void If_Admin()
{
	uint8 try = 0;
	while(try!=3)
	{
		uint16 Admin_Pass ;
		printf("Enter Your Password   = ");
		scanf("%d" , &Admin_Pass ); 
		if(Admin_Pass==password)
	    {			   
		   printf("Right Password\n");
		   char operation[6] ;
		   printf("Enter Add OR Cancel OR Edit OR Disply  ? = ");
		   scanf("%s" , &operation ); 
		   for(uint8 i=0 ; i<6 ; i++)
	        {
	         	if(operation[i]<97)
	         	{
	         		operation[i] = operation[i]+32;
	         	}
	         	else
	         	{
	         		operation[i] = operation[i];
	         	}
	        }
			
		   if(operation[0]=='a' && operation[1]=='d' && operation[2]=='d' )
		   {
			   Add_New_Patient_Record();
		   }
		   
		   if(operation[0]=='c' && operation[1]=='a' && operation[2]=='n' && operation[3]=='c' && operation[4]=='e' && operation[5]=='l')
		   {
			   Cancel_Reservation();
		   } 
		   
           if(operation[0]=='e' && operation[1]=='d' && operation[2]=='i' && operation[3]=='t')
		   {
			   Edit_Patient_Record();
		   }  
		   
           if(operation[0]=='d' && operation[1]=='i' && operation[2]=='s' && operation[3]=='p' && operation[4]=='l' && operation[5]=='y')
		   {
			   Disply_Contect_pationt();	
		   }	
           else
		   {
			   main();
		   }		    
		   break;
	    }
		else
		{
			try++;
			printf("Wrong Password Try Again !!!\n");
			
		}
	}
	if(try==3)
	{
		main();
	}
}

uint8 Mode_System()
{
	char Mode[5] ;
	printf("Write User or Admin ? = ");
	scanf("%s" , &Mode );
	for(uint8 i=0 ; i<5 ; i++)
	{
		if(Mode[i]<97)
		{
			Mode[i] = Mode[i]+32;
		}
		else
		{
			Mode[i] = Mode[i];
		}
	}
	if(Mode[0]=='u' && Mode[1]=='s' && Mode[2]=='e' && Mode[3]=='r')
	{
		
		return 1 ; 
	}
	if(Mode[0]=='a' && Mode[1]=='d' && Mode[2]=='m' &&  Mode[3]=='i' && Mode[4]=='n')
	{
		
		return 0 ;
	}
	else
	{
		main();
	}
	
}


/******************************   Add_New_Patient_Record  *******************************/

void Add_New_Patient_Record()
{
	uint8  index = -1 ;
	USER U ;
    printf("Enter Your Name        = ");
	scanf("%s" , &ID_Array[i].Name );
    printf("Enter Your Age         = ");
	scanf("%d" , &ID_Array[i].Age );
    printf("Enter Your Gender      = ");
	scanf("%s" , &ID_Array[i].Gender );
    printf("Enter Your ID          = ");
	scanf("%d" , &ID_Array[i].ID );	
	printf("Enter Your Appointment = ");
	scanf("%d" , &ID_Array[i].Appointment );
	//ID_Array[i].ID = U.ID ;
	
	
	if(ID_Array[i].Appointment==1)
	{
		 Place_1 = 1 ;
	}
	if(ID_Array[i].Appointment==2)
	{
		Place_2 = 1 ; 
	}
	if(ID_Array[i].Appointment==3)
	{
		Place_3 = 1 ;
	}
	if(ID_Array[i].Appointment==4)
	{
		Place_4 = 1;
	}
	if(ID_Array[i].Appointment==5)
	{
		Place_5 = 1;
	}
	
	
	uint32 User_ID =ID_Array[i].ID ; 
	uint8 User_Appointment=ID_Array[i].Appointment ; 
	for(uint8 Counter = 0 ; Counter<5; Counter++)
	{
		if( (User_ID==ID_Array[Counter].ID) && (i != Counter))
		{
			    printf("******************************************************** This ID already USED ***************************************************\n");
			    if(ID_Array[i].Appointment==1)
	            {
	            	 Place_1 = 0 ;
	            }
	            if(ID_Array[i].Appointment==2)
	            {
	            	Place_2 = 0 ; 
	            }
	            if(ID_Array[i].Appointment==3)
	            {
	            	Place_3 = 0 ;
	            }
	            if(ID_Array[i].Appointment==4)
	            {
	            	Place_4 = 0;
	            }
	            if(ID_Array[i].Appointment==5)
	            {
	            	Place_5 = 0;
	            }	
			
			for(uint8 k=0 ; k<10 ; k++)
			{
				ID_Array[i].Name[k]   = ID_Array[i+1].Name[k]  ;
				ID_Array[i].Gender[k] = ID_Array[i+1].Gender[k];
			}
			ID_Array[i].Age    = ID_Array[i+1].Age   ;
			
			ID_Array[i].ID     = ID_Array[i+1].ID    ;
			
			ID_Array[i].Appointment     = ID_Array[i+1].Appointment    ;
					
			   	
			i--;
			    
			
			break;
			
	    }
    }
	
	for(uint8 Counter = 0 ; Counter<5; Counter++)
	{
		if( (User_Appointment==ID_Array[Counter].Appointment) && (i != Counter) || ID_Array[i].Appointment > 5)
		{
			printf("******************************************************** This Appointment EXIST ***************************************************\n");
			if(ID_Array[i].Appointment==1)
	        {
	        	 Place_1 = 1 ;
	        }
	        if(ID_Array[i].Appointment==2)
	        {
	        	Place_2 = 1 ; 
	        }
	        if(ID_Array[i].Appointment==3)
	        {
	        	Place_3 = 1 ;
	        }
	        if(ID_Array[i].Appointment==4)
	        {
	        	Place_4 = 1;
	        }
	        if(ID_Array[i].Appointment==5)
	        {
	        	Place_5 =1;
	        }		
			
			
			for(uint8 k=0 ; k<10 ; k++)
			{
				ID_Array[i].Name[k]   = ID_Array[i+1].Name[k]  ;
				ID_Array[i].Gender[k] = ID_Array[i+1].Gender[k];
			}
			ID_Array[i].Age    = ID_Array[i+1].Age   ;
			ID_Array[i].ID     = ID_Array[i+1].ID    ;
			
			ID_Array[i].Appointment     = ID_Array[i+1].Appointment    ;
			
			i--;
			break;
	    }
    }
		
	i++;
}
	

void Edit_Patient_Record()
{   
    uint32 User_ID ; 
	printf("Enter The pationt ID = ");
    scanf("%d" , &User_ID );
	
	
	
	for(uint8 Counter_2 = 0 ; Counter_2< Size; Counter_2++)
    {
		  if(User_ID==ID_Array[Counter_2].ID )
		    {
				    if(ID_Array[Counter_2].Appointment==1)
	                {
	                	Place_1 = 0 ;
	                }
	                if(ID_Array[Counter_2].Appointment==2)
	                {
	                	Place_2 = 0 ;
	                }
	                if(ID_Array[Counter_2].Appointment==3)
	                {
	                	Place_3 = 0 ;
	                }
	                if(ID_Array[Counter_2].Appointment==4)
	                {
	                	Place_4 = 0 ;
	                }
	                if(ID_Array[Counter_2].Appointment==5)
	                {
	                	Place_5 = 0 ;
	                }  
					
				  printf("Enter Your Name        = ");
	              scanf("%s" , &ID_Array[Counter_2].Name );
                  printf("Enter Your Age         = ");
	              scanf("%d" , &ID_Array[Counter_2].Age );
                  printf("Enter Your Gender      = ");
	              scanf("%s" , &ID_Array[Counter_2].Gender );
                  printf("Enter Your ID          = ");
	              scanf("%d" , &ID_Array[Counter_2].ID );	
				  printf("Enter Your Appointment = ");
	              scanf("%d" , &ID_Array[Counter_2].Appointment );	
				 

				    if(ID_Array[Counter_2].Appointment==1)
	                {
	                	Place_1 = 1 ;
	                }
	                if(ID_Array[Counter_2].Appointment==2)
	                {
	                	Place_2 = 1 ;
	                }
	                if(ID_Array[Counter_2].Appointment==3)
	                {
	                	Place_3 = 1 ;
	                }
	                if(ID_Array[Counter_2].Appointment==4)
	                {
	                	Place_4 = 1 ;
	                }
	                if(ID_Array[Counter_2].Appointment==5)
	                {
	                	Place_5 = 1 ;
	                }  
					
				 break; 
		    }
		if(Counter_2==4)
		{
			printf("Incoreect ID\n")    ; 
			main();
		}
	}
	
}


/******************************   Cancel_Reservation  *******************************/

void Cancel_Reservation()
{
	uint32 User_ID , index = -1 ;
	printf("Enter The pationt ID = ");
    scanf("%d" , &User_ID ); 
	
	for(uint8 Counter_2 = 0 ; Counter_2< Size; Counter_2++)
    {
					
		  if(User_ID==ID_Array[Counter_2].ID)
		    {
				    if(ID_Array[Counter_2].Appointment==1)
	                {
	                	Place_1 = 0 ;
	                }
	                if(ID_Array[Counter_2].Appointment==2)
	                {
	                	Place_2 = 0 ;
	                }
	                if(ID_Array[Counter_2].Appointment==3)
	                {
	                	Place_3 = 0 ;
	                }
	                if(ID_Array[Counter_2].Appointment==4)
	                {
	                	Place_4 = 0 ;
	                }
	                if(ID_Array[Counter_2].Appointment==5)
	                {
	                	Place_5 = 0 ;
	                }  
				
				 for(uint8 i = 0 ; i<Size ; i++)
					{
						if(ID_Array[i].ID==User_ID)
						{
							index = i ;
							break;
						}
					}
					
				 if(index != -1)
					{
						for(uint8 i = index; i < 10 - 1; i++)
						  {
							
							for(uint8 k=0 ; k<10 ; k++)
							{
								ID_Array[i].Name[k]   = ID_Array[i+1].Name[k]  ;
								ID_Array[i].Gender[k] = ID_Array[i+1].Gender[k];
							}
							ID_Array[i].Age    = ID_Array[i+1].Age   ;
							
							ID_Array[i].ID     = ID_Array[i+1].ID    ;
							
							ID_Array[i].Appointment     = ID_Array[i+1].Appointment    ;
						  }
						
					}
					if(ID_Array[i].Appointment==1)
	                {
	                	 Place_1 = 0 ;
	                }
	              
					i--;
					break;
		    }
	   if(Counter_2==4)
		{
			printf("Incoreect ID\n")    ; 
			main();
		}
	}
}

/******************************   Disply_Contect_pationt  *******************************/

void Disply_Contect_pationt()
{
	
	
	for(uint8 Counter_2 = 0 ; Counter_2< i; Counter_2++)
    {	       
		printf("Pationt %d NAME        = %s \n" , Counter_2+1 , ID_Array[Counter_2].Name)  ;  
		printf("Pationt %d AGE         = %d \n" , Counter_2+1 , ID_Array[Counter_2].Age)   ;  
		printf("Pationt %d GENDERR     = %s \n" , Counter_2+1 , ID_Array[Counter_2].Gender);  
		printf("Pationt %d ID          = %d \n" , Counter_2+1 , ID_Array[Counter_2].ID)    ;  
                
		     if(ID_Array[Counter_2].Appointment==1)
	         {
	         	 printf("Pationt %d Appointment = 2pm    to 2:30pm\n" ,Counter_2+1)    ; 	
	         }
	         if(ID_Array[Counter_2].Appointment==2)
	         {
	         	 printf("Pationt %d Appointment = 2:30pm to 3pm\n" ,Counter_2+1)    ; 
	         }
	         if(ID_Array[Counter_2].Appointment==3)
	         {
	         	printf("Pationt %d Appointment = 3pm    to 3:30pm\n" ,Counter_2+1)    ; 	
	         }
	         if(ID_Array[Counter_2].Appointment==4)
	         {
	         	printf("Pationt %d Appointment = 4pm    to 4:30pm\n",Counter_2+1)    ; 	
	         }
	         if(ID_Array[Counter_2].Appointment==5)
	         {
	         	printf("Pationt %d Appointment = 4:30pm to 5pm\n" ,Counter_2+1)    ; 
	         }
		printf("\n");
	}
	main();
}



void Reserve__Slot()
{   
     printf("/************************************************************************************************************/\n");
     printf("/********************************************* Clinic_Management ********************************************/\n");
     printf("/************************************************************************************************************/\n \n");
   

     printf("/********************************************** Available Place **********************************************/\n");
	 
	 
	 if(Place_1==1)
	 {
	    printf("                                1-  2pm    to 2:30pm   Not Available \n" )    ; 	
	 }
	 else
	 {
		printf("                                1-  2pm    to 2:30pm    Available \n" )    ; 
	 }
	 
	 if(Place_2==1)
	 {	 
		printf("                                2-  2:30pm to 3pm      Not Available\n" )    ; 	
	 }
	 else
	 {
		printf("                                2-  2:30pm to 3pm       Available\n" )    ; 	

	 }
	 
	 if(Place_3==1)
	 {   
		printf("                                3-  3pm    to 3:30pm   Not Available\n" )    ; 	
	 }
	 else
	 {
		printf("                                3-  3pm    to 3:30pm    Available\n" )    ; 	
	 }
	 
	 if(Place_4==1)
	 {
		printf("                                4-  4pm    to 4:30pm   Not Available \n" )    ; 	
	 }
	 else
	 {
		printf("                                4-  4pm    to 4:30pm    Available \n" )    ; 	 
	 }
	 
	 if(Place_5==1)
	 {
		printf("                                5-  4:30pm to 5pm      Not Available\n" )    ; 
	 }
	 else
	 {
		printf("                                5-  4:30pm to 5pm       Available\n" )    ; 
	 }
}









