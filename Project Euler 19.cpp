#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int leapcount(int year)
{
    int i=0,j=0;
    for(i=0;i<year;i++)
    {
                       if(i%4==0&&i%100!=0)
                          j++;
                       else if(i%400==0)
                          j++;
    }
    return j;
}
int leapcheck(int y)
{
	   if(y%4==0&&y%100!=0)
          return 1;
       else if(y%400==0)
          return 1;
	   else return 0;

}
int validdatecheck(int d,int m,int y)
{
	int f=0;
	if(y<1) return 0;
	else if(d>31) return 0;
    else if(m=2)
	{
		f=leapcheck(y);
		if(f==0&&d<=28) return 1;
		else if(f==1&&d<=29) return 1;
		else return 0;
	}
	else if((m==4||m==6||m==9||m==11)&&d<=30)
		return 1;
	else if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d<=31)
		return 1;
	else return 0;
}



int main()
{
  float x=0;
  int monthreq,date,month=1,year,count=0,i,j;
  int noy,noly,flag=0;
  unsigned long nod;
  for(i=1901;i<2001;i++)
  {
        year=i;
      for(j=1;j<13;j++)
      {
          date=1;
          monthreq=j;
          noy=year;
          noly=leapcount(year);
          nod=(year-1)*365+noly;
          nod=nod%7;
          flag=leapcheck(year);
              switch(monthreq)
              {
                   case 1:
                      nod+=date;
                      break;
                   case 2:
                      nod+=31+date;
                      break;
                   case 3:
                      nod+=flag+31+28+date;
                      break;
                   case 4:
                      nod+=flag+31*2+28+date;
                      break;
                   case 5:
                      nod+=flag+31*2+28+date+30;
                      break;
                   case 6:
                      nod+=flag+31*3+28+date+30;
                      break;
                   case 7:
                      nod+=flag+31*3+28+date+30*2;
                      break;
                   case 8:
                      nod+=flag+31*4+28+date+30*2;
                      break;
                   case 9:
                      nod+=flag+31*5+28+date+30*2;
                      break;
                   case 10:
                      nod+=flag+31*5+28+date+30*3;
                      break;
                   case 11:
                      nod+=flag+31*6+28+date+30*3;
                      break;
                   case 12:
                      nod+=flag+31*6+28+date+30*4;
                      break;
                   default: exit(0);
              }
              nod=(nod-1)%7;
                      if(nod==0)
                              count++;

      }
    }
cout<<count;
return 0;
}
