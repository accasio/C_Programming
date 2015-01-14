#include "stdafx.h"
#include <stdio.h>
#define PI 3.14159
void main()
{
float height, length, depth, radius;
float volume;
int choice;
printf("Volume Calculator \n ---------------------\n Enter Choice: Cuboid:1 or Sphere: 2\n\n");
scanf("%d",&choice);
if(choice == 1)
{
printf ("Enter height: ");
scanf ("%f", &height );
if (height <= 0.0)
{
printf("height must be >= 0 \n Program exiting \n");
return;
}
printf ("Enter length: ");
scanf ("%f", &length );
if (length <= 0.0)
{
printf("length must be >= 0 \n Program exiting \n");
return;
}
printf ("Enter depth: ");
scanf ("%f", &depth );
if (depth <= 0.0)
{
printf("depth must be >= 0 \n Program exiting \n");
return;
}
volume = height*length*depth;
printf ("Volume is %.2f \n", volume);
}
else if (choice == 2)
{
printf ("Enter radius: ");
scanf ("%f", &radius );
if (radius <= 0.0)
{
printf("radius must be >= 0 \n Program exiting \n");
return;
}
volume = (4.0/3.0)*PI*radius*radius*radius;
printf ("Volume is %.2f \n", volume);
}
else
{
printf("illegal choice entered - exiting \n");
return;
}
return;
}