// Verilen bir n saniye boyunca saniye dakika saat bilgisini ekrana yazdiran program
// 5 farkli cozum uygulanabilir
#include <stdio.h>
int main(void)
{
    int saat=0, dakika=0,saniye=0, i=0,n;
    printf("saatin kac saniye boyunca goruntulenmesini istersiniz?");
    scanf("%d",&n);
     
    // asagidaki cozumde saat ve dakika kontrolleri gereksiz oldugu halde her seferinde yapiliyor
	/*
    for (i=0;i<n;i++)
    {
        saniye++;
        if (saniye==60)
        {
           saniye=0;
           dakika++;
    	}
        if (dakika==60)
        {
              dakika=0;
              saat++;
    	}
        if (saat==24)
            saat=0;
        printf("saat-%d dak:%d san:%d\n",saat,dakika,saniye);    
	}
    */
   
   // konroller gerektiginde yapiliyor
    for (i=0;i<n;i++)
    {
        saniye++;
        if (saniye==60)
        {
           saniye=0;
           dakika++;
           if (dakika==60)
           {
              dakika=0;
              saat++;
              if (saat==24)
                 saat=0;
           }
        }
        printf("saat-%d dak:%d san:%d\n",saat,dakika,saniye);
    }
    
    
    //kotrol yerine mod alarak da cozulebilir
    /*
	i=0;
    while(i<n)
    {
    	saat= (i/3600)%24;
    	dakika=((i-(saat*3600))/60)%60;
    	saniye=i%60;
    	printf("saat-%d dak:%d san:%d\n",saat,dakika,saniye);    
    	i++;
	}
    */
  
  /* aþaðýdaki çözümde dönüþ sayýsý deðiþmedi sadece kontrol sayýsýný arttýrmýþ olduk */
  /*
    while(i<n)
    {
    	while ((saat<24) && (i<n))
    	{
    		while ((dakika<60)&& (i<n))
    		{
    			while ((saniye<60) && (i<n))
    			{
    				printf("saat-%d dak:%d san:%d\n",saat,dakika,saniye);    
    				saniye++;
    				i++;
				}
				saniye=0;
				dakika++;
			}
			dakika=0;
			saat++;
		}
		saat=0;
	}
*/

//
/* 0'lamak yerine mod alarak da cozulebilir
 for (i=0;i<n;i++)
    {
        saniye++;
        if (saniye%60==0)
        {
           
           dakika++;
           if (dakika%60==0)
           {
             
              saat++;
              
           }
        }
        printf("saat-%d dak:%d san:%d\n",saat%24,dakika%60,saniye%60);
    }
 */   
	
getch();
return 0;
}
