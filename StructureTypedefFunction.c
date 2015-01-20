#include "stdafx.h"
#include <stdio.h>
#include "string.h"


typedef struct 
{
	int day;
	int month;
	int year;
} date;

typedef struct 
{
	int studentID;
	char firstName[21];
	char familyName[21];
	int courseID;	
	date DOB;
	date startDate;
} student;

void display_student(student student1);

student makeStudent(int ID, char fname[], char sname[], int course, date DOB, date start);

void main ()
{
	date DOB1 = {25,12,1900};
	date start1 = {1,1,1920};

	student student2;
	
	student2 = makeStudent(101, "Ebenezer","Scrooge",1001, DOB1,start1);

	display_student (student2);
}

void display_student(student studentx)
{
	printf("Student ID: %d, %s, %s is taking course %d \n", studentx.studentID, studentx.familyName, studentx.firstName, studentx.courseID);
	printf("Date Of Birth: %d/%d/%d \n", studentx.DOB.day,studentx.DOB.month,studentx.DOB.year);
	printf("Start Date: %d/%d/%d \n\n\n", studentx.startDate.day, studentx.startDate.month,studentx.startDate.year);
}

student makeStudent(int ID, char fname[], char sname[], int course, date DOB, date start)
{
	student student1;

	student1.studentID = ID;
	student1.courseID = course;
	student1.DOB = DOB;
	student1.startDate = start;
	strcpy_s(student1.firstName, fname);
	strcpy_s(student1.familyName, sname);

	return student1;
}