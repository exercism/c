/* The Conversion Does Not Use the Inbuit 
 * function printf , using only for stdout
 * if you think printf must not be used 
 * then i will use inline assembly code
 */

char Decimal[20];

int printf(const char *format, ...);

int convert_to_ascii(int FromInteger){
		int EquAscii = 0;
		if(FromInteger == 0){ EquAscii = 48; }
		if(FromInteger == 1){ EquAscii = 49; }
		if(FromInteger == 2){ EquAscii = 50; }
		if(FromInteger == 3){ EquAscii = 51; }
		if(FromInteger == 4){ EquAscii = 52; }
		if(FromInteger == 5){ EquAscii = 53; }
		if(FromInteger == 6){ EquAscii = 54; }
		if(FromInteger == 7){ EquAscii = 55; }
		if(FromInteger == 8){ EquAscii = 56; }
		if(FromInteger == 9){ EquAscii = 57; }
		return EquAscii;
}

int Power( int base , int power){
	int sum = 0;
	if(power == 0) { return 1;}
	if(power == 1) { return base;}
	for(base = base; power != 0;power--){
		if(power == 1){
			return sum;
		}else{
		sum = sum + (base*base);
		}
	}
	return sum;
}


int Convert_to_Decimal(long int FromBinary){
	long int dec = 0;
	int i = 0;
	long int tempBit = FromBinary;
	while(tempBit != 0){
		dec = dec + (tempBit % 10) * Power(2,i);
		i++;
		tempBit = tempBit/10;
	}
	long int TempNo = dec;
    int ii=0;
        while(TempNo != 0){
                Decimal[ii] = convert_to_ascii(TempNo % 10);
                ii++;
                TempNo = TempNo/10;
                if(TempNo == 0){ ii++;Decimal[ii] = '\0';}
    }	
	return dec;
}
