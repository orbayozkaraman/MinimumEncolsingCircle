
#include <stdio.h> 
  #include <stdlib.h> 
  #include <graphics.h> 
  #include <math.h> 
  
  
  

  
  // dosyaya deðer girerken son deðerden sonra boþluk býrakýn lütfen
   
  int main() 
  { 
     
    
	
    
  	int r,t;
  	int n=0;
  	int q=0;
  	
  	
  	int dizi[100];

    int sayilar;
    FILE *hedef_dosya;
    hedef_dosya=fopen("dosya.txt","r");
    int tutucu=0;
    if(hedef_dosya==NULL){
    	printf("dosya boþ");
	}

  while(!feof(hedef_dosya))
    {
        fscanf(hedef_dosya,"%d",&sayilar);
        dizi[n]=sayilar;
        n++;  
        tutucu++;
    } 
    
    
    
	int x[100];
	int y[100];
	for(int k=0;k<=n-2;k++){

       if(k%2==0){

           x[k]=dizi[k];

           }

       else

       y[k]=dizi[k];
   }
   
   if(n==1)
    {
        printf("Lütfen koordinat giriniz.");
    }
    
    if(n==2)
    {
        printf("Lutfen birden fazla koordinat giriniz.");
    }
    
    
    
   
   while(q<=n-2){
   	
   
    x[q]=x[q]*16+320;
    y[q+1]=240-(y[q+1]*16);
    q+=2;

}


  	int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, ""); 
    int a=16;
    int b=16;
  	 
  	 
	   
  	 
  	int sayac=0; 
  	int sayac2=0;
  	 
  	for(int i=0;i<n-1;i+=2){
  		sayac+=x[i];
	  } 
	  
	for(int i=1;i<n-1;i+=2){
		sayac2+=y[i];
	}  
	sayac=sayac/((n-1)/2);
	sayac2=sayac2/((n-1)/2);
	
	double temp=0.0;
	for(int i=0;i<n-1;i+=2){
		t = pow(sayac-x[i],2) + pow(sayac2-y[i+1],2);
		r=sqrt(t);
		if(r>temp){
			temp=r;
			r=0;
		}
		else{
			r=0;
		}
		
	}
	printf("yaricap:%f\n",temp);
	printf("merkez X:%d Y:%d\n",sayac,sayac2);
	printf("nokta sayisi:%d",n-1);
	
  	fclose(hedef_dosya);
  	
  	
  	
    for(int j=0;j<n-1;j+=2){
  	circle(x[j],y[j+1],4);
  }
  
  
  	
  	circle(sayac, sayac2,temp); 
  	line (0,240,640,240);
    line(320,0,320,480);
    
    
    double xu = 0.0 , yu = 0.0 , u = 0.0 ; 
    int i = 0 ; 
    for(u = 0.0 ; u <= 1.0 ; u += 0.0001) 
    { 
    if(n==5){
        xu = (1-u)*x[0]+u*x[2];
        yu = (1-u)*y[1]+u*y[3];
        putpixel(xu,yu,1);
    }
    else if(n==7){
        xu = pow(1-u,2)*x[0]+2*u*(1-u)*x[2]+pow(u,2)*x[4];
        yu = pow(1-u,2)*y[1]+2*u*(1-u)*y[3]+pow(u,2)*y[5];
        putpixel(xu,yu,1);
    }
    else if(n==9){
        xu = pow(1-u,3)*x[0]+3*u*pow(1-u,2)*x[2]+3*pow(u,2)*(1-u)*x[4] +pow(u,3)*x[6]; 
        yu = pow(1-u,3)*y[1]+3*u*pow(1-u,2)*y[3]+3*pow(u,2)*(1-u)*y[5] +pow(u,3)*y[7]; 
        putpixel(xu,yu,1);
    } 
}
 
    
    
    
    
    for(int i=0;i<=40;i++){
    	line(a,235,a,245);
    	a=a+16;
	}
	
	for(int i=0;i<=40;i++){
		line(315,b,325,b);
		b=b+16;
	}  
   
     
  	getch();

      return 0; 
   
  } 
  

  
  

  
  
  
  
  
  
  
  
  
  
