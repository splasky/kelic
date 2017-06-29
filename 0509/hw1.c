
int main(void){
	int i=0;
	int sum=0;

	for(i=1;i<=100;++i){
	if(i%2 ==0)
		continue;
	if(i==3 || i==59 || i==70)
		continue;
	sum+=i;
	}
	return 0;
}
