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
	int i=0,depth=0;
	const char *block[8]={"001","011","000","010","111","101","100","110"}; // ポインタ文字列（変数）
	const char goal_block[8][4]={"011","001","000","010","111","101","100","110"}; // 配列文字列（定数）
	char displacement[8][256]={"x0","-x0","","","","","",""},rotation[10]="0",buffer[256];

	for (depth= 0;block==goal_block;depth++){
		block_conversion(block+i,rotation);
		strcat(buffer,displacement[i]);
		printf("%s\n",displacement[i]);
	}
		
	return(0);
}