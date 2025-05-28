#include <stdio.h>

int main(void){
	
	struct Date{
		int year;
		int month;
		int day;
	};
	
	struct Book{
		char title[128];
		char author[40];
		float price;
		struct Date date;
		char publisher[40];
	};

	/* struct Book book1 = {
		"hello world",
		"laijianwei",
		40.2,
		// (2021,1,1),
		{
			2021,
			1,
			1,
		}
		"no name publisher",
	}; */
	
	struct Book book1 = {
		"hello world",
		"laijianwei",
		40.2,
		// (2021,1,1),
		{
			2021,
			1,
			1,
		},
		"no name publisher",
	};
	
	struct Book book2 = {
		"hello world",
		"laijianwei",
		40.2,
		2020,11,22,
		"no name publisher",
	};
	return 0;
}