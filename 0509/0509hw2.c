
int main(void){
	int Table[]={34,65,12,34,67,89,7,6,83,89};
	int i=0;
	int length=sizeof(Table)/sizeof(Table[0]);
	
	for(i=0;i<length;++i){
	if(Table[i]<20)
		Table[i]=0;
	else if(Table[i]>=40)
		Table[i]=Table[i]%40;
	}

	return 0;
}