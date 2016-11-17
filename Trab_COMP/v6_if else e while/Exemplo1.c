{
	int a, b, c;
	String s;
	print("Valor de A:");
	read(a);
	print("Valor de B:");
	read(b);
	while (a != b)
	{
		if (a > b || a == b)
		{
			a = a - b;
		}
		if (b > a)
		{
			b = b - a;
		} else{
			b = b + a;		
		}
	}
	b = 20 + a;
	print("\nRes=");
	print(a);
}
	
