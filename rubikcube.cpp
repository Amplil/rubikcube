#include<stdio.h>
#include<string.h>
const char *block_conversion(const char **block,char const rotation[]){
	if(!strcmp(rotation,"x0")){
		if(!strcmp(*block,"000"))*block="001";
		else if(!strcmp(*block,"001"))*block="011";
		else if(!strcmp(*block,"011"))*block="010";
		else if(!strcmp(*block,"010"))*block="000";
		else return("");
		return("-x0");
	}
	else if(!strcmp(rotation,"x1")){
		if(!strcmp(*block,"100"))*block="101";
		else if(!strcmp(*block,"101"))*block="111";
		else if(!strcmp(*block,"111"))*block="110";
		else if(!strcmp(*block,"110"))*block="100";
		else return("");
		return("-x1");
	}
	else if(!strcmp(rotation,"-x0")){
		if(!strcmp(*block,"000"))*block="010";
		else if(!strcmp(*block,"010"))*block="011";
		else if(!strcmp(*block,"011"))*block="001";
		else if(!strcmp(*block,"001"))*block="000";
		else return("");
		return("x0");
	}
	else if(!strcmp(rotation,"-x1")){
		if(!strcmp(*block,"100"))*block="110";
		else if(!strcmp(*block,"110"))*block="111";
		else if(!strcmp(*block,"111"))*block="101";
		else if(!strcmp(*block,"101"))*block="100";
		else return("");
		return("x1");
	}
	else if(!strcmp(rotation,"y0")){
		if(!strcmp(*block,"000"))*block="001";
		else if(!strcmp(*block,"001"))*block="101";
		else if(!strcmp(*block,"101"))*block="100";
		else if(!strcmp(*block,"100"))*block="000";
		else return("");
		return("-y0");
	}
	else if(!strcmp(rotation,"y1")){
		if(!strcmp(*block,"010"))*block="011";
		else if(!strcmp(*block,"011"))*block="111";
		else if(!strcmp(*block,"111"))*block="110";
		else if(!strcmp(*block,"110"))*block="010";
		else return("");
		return("-y1");
	}
	else if(!strcmp(rotation,"-y0")){
		if(!strcmp(*block,"000"))*block="100";
		else if(!strcmp(*block,"100"))*block="101";
		else if(!strcmp(*block,"101"))*block="001";
		else if(!strcmp(*block,"001"))*block="000";
		else return("");
		return("y0");
	}
	else if(!strcmp(rotation,"-y1")){
		if(!strcmp(*block,"010"))*block="110";
		else if(!strcmp(*block,"110"))*block="111";
		else if(!strcmp(*block,"111"))*block="011";
		else if(!strcmp(*block,"011"))*block="010";
		else return("");
		return("y1");
	}
	else if(!strcmp(rotation,"z0")){
		if(!strcmp(*block,"000"))*block="100";
		else if(!strcmp(*block,"100"))*block="110";
		else if(!strcmp(*block,"110"))*block="010";
		else if(!strcmp(*block,"010"))*block="000";
		else return("");
		return("-z0");
	}
	else if(!strcmp(rotation,"-z0")){
		if(!strcmp(*block,"000"))*block="010";
		else if(!strcmp(*block,"010"))*block="110";
		else if(!strcmp(*block,"110"))*block="100";
		else if(!strcmp(*block,"100"))*block="000";
		else return("");
		return("z0");
	}
	else if(!strcmp(rotation,"2x0")){
		if(!strcmp(*block,"000"))*block="011";
		else if(!strcmp(*block,"001"))*block="010";
		else if(!strcmp(*block,"010"))*block="001";
		else if(!strcmp(*block,"011"))*block="000";
		else return("");
		return("2x0");
	}
	else if(!strcmp(rotation,"2x1")){
		if(!strcmp(*block,"100"))*block="111";
		else if(!strcmp(*block,"101"))*block="110";
		else if(!strcmp(*block,"110"))*block="101";
		else if(!strcmp(*block,"111"))*block="100";
		else return("");
		return("2x1");
	}
	else if(!strcmp(rotation,"2y0")){
		if(!strcmp(*block,"000"))*block="101";
		else if(!strcmp(*block,"001"))*block="100";
		else if(!strcmp(*block,"100"))*block="001";
		else if(!strcmp(*block,"101"))*block="000";
		else return("");
		return("2y0");
	}
	else if(!strcmp(rotation,"2y1")){
		if(!strcmp(*block,"010"))*block="111";
		else if(!strcmp(*block,"011"))*block="110";
		else if(!strcmp(*block,"110"))*block="011";
		else if(!strcmp(*block,"111"))*block="010";
		else return("");
		return("2y1");
	}
	else if(!strcmp(rotation,"2z0")){
		if(!strcmp(*block,"000"))*block="110";
		else if(!strcmp(*block,"010"))*block="100";
		else if(!strcmp(*block,"100"))*block="010";
		else if(!strcmp(*block,"110"))*block="000";
		else return("");
		return("2z0");
	}
	else return("");
}
int main(void){
	int i=0;
	/*
	char *block[8]={"011","001","000","010","100","110","101","111"},
		displacement[8][256]={"","","","","","-y1x1","","y1-x1"},rotation[10]="0",buffer[256];
		*/
	/*
	char *block[8]={"000","001","010","011","100","101","110","111"},
		displacement[8][256]={"","x0","","","","","",""},rotation[10]="0",buffer[256];
		*/
	const char *block[8]={"001","011","000","010","111","101","100","110"};
	char displacement[8][256]={"x0","-x0","","","","","",""},rotation[10]="0",buffer[256];

	printf("「end」で終了\n「reset」で元の状態に戻る\n");
	for(i=0;i<8;i++)printf("%s %s\n",block[i],displacement[i]);
	printf("\n→");
	scanf("%s",rotation);
	if(!strcmp(rotation,"end"))return(0);
	do{
		if(!strcmp(rotation,"reset")){
			block[0]="011";block[1]="001";block[2]="000";block[3]="010";block[4]="100";block[5]="110";block[6]="101";block[7]="111";
			strcpy(displacement[0],"");strcpy(displacement[1],"");strcpy(displacement[2],"");strcpy(displacement[3],"");strcpy(displacement[4],"");strcpy(displacement[5],"-y1x1");strcpy(displacement[6],"");strcpy(displacement[7],"y1-x1");
		}
		else if(!strcmp(rotation,"reset")){
		}
		for(i=0;i<8;i++){
			strcpy(buffer,block_conversion(block+i,rotation));
			strcat(buffer,displacement[i]);
			strcpy(displacement[i],buffer);
			printf("%s %s\n",block[i],displacement[i]);
		}
		printf("\n→");
		scanf("%s",rotation);
	}while(strcmp(rotation,"end"));
	return(0);
}