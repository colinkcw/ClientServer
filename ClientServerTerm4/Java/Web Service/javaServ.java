package org.tempuri;

import java.util.*;
import java.net.URL;

class javaServ{
	public static void main(String[] args){
		int value = 0;
		int num1 , num2;
		
		Scanner scan = new Scanner(System.in);
		num1 = scan.nextInt();
		num2 = scan.nextInt();
		Service1 service = new Service1();
		Service1Soap simple = service.getService1Soap12();
		value = simple.simpleMethod(num1,num2);
		System.out.print(value);
		
	}
}