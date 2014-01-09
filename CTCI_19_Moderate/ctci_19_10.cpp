// rand5() can generate a random number between 1 and 5
int rand7(){
	int num = 5*rand5()-rand5(); // generate random num from 0 to 24
	if(num < 21)
		return (num%7+1);
}

// in general case, use rand_m() to implement rand_n(), if n > m^2-1, no idea how to do it.