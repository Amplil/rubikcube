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
bool blockscmp(const char *blocks1[],const char *blocks2[]){ // blocks1,blocks2が一致しているか判定する
	int i=0;
	for(i= 0;i<8;i++){
		if(strcmp(blocks1[i],blocks2[i]))return(false);
	}
	return(true);

}

const int M=10; // 回転の種類の数
char displacement[256]="",rotation[10]="0",buffer[256],
rotation_list[10][4]={"x0","-x0","x1","-x1","y0","-y0","y1","-y1","z0","-z0"};
char invalid_rotation[4];

bool iddfs(int depth,const char *blocks[],const char *goal_blocks[],int limit){
	//int i=0,j=0;
	if(limit==depth){
		if(blockscmp(blocks,goal_blocks))return(true);
	}
	else{
		for (int j=0;j<M;j++){
			strcat(displacement,rotation_list[j]);
			for(int i= 0;i<8;i++){
				if(!strcmp(invalid_rotation,"")){
					strcpy(invalid_rotation,block_conversion(blocks+i,rotation));
				}
				else block_conversion(blocks+i,rotation_list[j]);
			}
			iddfs(depth+1,blocks,goal_blocks,limit);
			printf("%s\n",displacement);
		}
	}
}
int main(void){
	int i=0,depth=0,limit=0;
	const char *blocks[8]={"001","011","000","010","111","101","100","110"}, // ポインタ文字列の配列
	*goal_blocks[8]={"011","001","000","010","111","101","100","110"}; // ポインタ文字列の配列

	for (limit = 2; limit <= 20; limit++) {
		strcpy(invalid_rotation,"");
		strcpy(displacement,"");
		if(iddfs(1,blocks,goal_blocks,limit)){
			printf("見つかりました");
		}
	}	
	return(0);
}