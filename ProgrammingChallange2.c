#include<stdio.h>
#include<stdint.h>

typedef struct my_date_t
{
	uint8_t date;
	uint8_t month;
	uint16_t year;
}my_date_t;

typedef enum status_t
{
	SUCCESS=1,
	NULL_PTR=-1,
	INCORRECT=0
}status_t;

status_t string_to_date_converter(char* input_string, my_date_t* result_date);

int main()
{
	char input_string[11];
	printf("Enter the date in format DD/MM/YYYY:");
	fgets(input_string,11,stdin);
	my_date_t result_date[1];
	status_t status_output=string_to_date_converter(input_string,result_date);
	switch(status_output)
	{
		case SUCCESS:  printf("Successfully converted\n");
		                break;  
		case NULL_PTR:  printf("NULL pointer to work with\n");
		                break;
		case INCORRECT:  printf("Invalid inputs\n");
		                  break;
	}
	printf("Date:%d",result_date->date);
	printf("\nMonth:%d",result_date->month);
	printf("\nYear:%d",result_date->year);
	return 0;
}

status_t string_to_date_converter(char* input_string, my_date_t* result_date)
{
	if(result_date == NULL)
	  return -1;
	  
   else	
	 {
		int l_date=0,l_month=0,l_year=0;
		for(int i=0;i<=1;i++)
		{
			if(input_string[i]>=48 && input_string[i]<=57)
			      l_date= l_date*10 + ( (int) (input_string[i]) - 48);
			
			else 
			     return 0;
		}
		result_date->date=l_date;
		for(int i=3;i<=4;i++)
		{
			if(input_string[i]>=48 && input_string[i]<=57)
			      l_month= l_month*10 + ( (int) (input_string[i]) - 48);
			
			else 
			     return 0;
		}
		result_date->month=l_month;
		for(int i=6;i<=9;i++)
		{
			if(input_string[i]>=48 && input_string[i]<=57)
			      l_year= l_year*10 + ( (int) (input_string[i]) - 48);
			
			else 
			     return 0;
		}
		result_date->year=l_year;
  }
	return 1;
}
