void sevenseg(int dec)
{
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0;

	switch(dec)
	{
		case 0:
			g=1;
			break;
		case 1:
			a=1,d=1,e=1,f=1,g=1;
			break;			
		case 2:
			c=1,f=1;
			break;			
		case 3:
			e=1,f=1;
			break;			
		case 4:
			a=1,d=1,e=1;
			break;			
		case 5:
			b=1,e=1;
			break;			
		case 6:
			b=1;
			break;			
		case 7:
			d=1,e=1,f=1,g=1;
			break;			
		case 8:
			break;			
		case 9:
			e=1;
			break;			
		default:
			b=1,c=1;
			break;
	}
	digitalWrite(2,a);
	digitalWrite(3,b);
	digitalWrite(4,c);
	digitalWrite(5,d);
	digitalWrite(6,e);
	digitalWrite(7,f);
	digitalWrite(8,g);

}
