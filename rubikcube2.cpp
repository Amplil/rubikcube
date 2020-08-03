#include<stdio.h>
#include<string.h>

void blocks_conversion(const char *blocks[],const char *conversion[]){
	for(int i= 0;i<8;i++){
		if(!strcmp(blocks[i],"000") && strcmp(conversion[0],""))blocks[i]=conversion[0];
		else if(!strcmp(blocks[i],"001") && strcmp(conversion[1],""))blocks[i]=conversion[1];
		else if(!strcmp(blocks[i],"010") && strcmp(conversion[2],""))blocks[i]=conversion[2];
		else if(!strcmp(blocks[i],"011") && strcmp(conversion[3],""))blocks[i]=conversion[3];
		else if(!strcmp(blocks[i],"100") && strcmp(conversion[4],""))blocks[i]=conversion[4];
		else if(!strcmp(blocks[i],"101") && strcmp(conversion[5],""))blocks[i]=conversion[5];
		else if(!strcmp(blocks[i],"110") && strcmp(conversion[6],""))blocks[i]=conversion[6];
		else if(!strcmp(blocks[i],"111") && strcmp(conversion[7],""))blocks[i]=conversion[7];
	}
}
void direction_conversion(int *direction,int conversion){
	// 0: 何もしない
	// 1: 0なら1に1なら0に
	// 2: 1なら2に2なら1に
	// 3: 0なら2に2なら0に
	if(conversion==1){
		if(*direction==0)*direction=1;
		else if(*direction==1)*direction=0;
	}
	else if(conversion==2){
		if(*direction==1)*direction=2;
		else if(*direction==2)*direction=1;
	}
	else if(conversion==3){
		if(*direction==0)*direction=2;
		else if(*direction==2)*direction=0;
	}
}
void directions_conversion(const char *blocks[],int directions[],int conversion[]){
	for(int i= 0;i<8;i++){
		if(!strcmp(blocks[i],"000"))direction_conversion(directions+i,conversion[0]);
		else if(!strcmp(blocks[i],"001"))direction_conversion(directions+i,conversion[1]);
		else if(!strcmp(blocks[i],"010"))direction_conversion(directions+i,conversion[2]);
		else if(!strcmp(blocks[i],"011"))direction_conversion(directions+i,conversion[3]);
		else if(!strcmp(blocks[i],"100"))direction_conversion(directions+i,conversion[4]);
		else if(!strcmp(blocks[i],"101"))direction_conversion(directions+i,conversion[5]);
		else if(!strcmp(blocks[i],"110"))direction_conversion(directions+i,conversion[6]);
		else if(!strcmp(blocks[i],"111"))direction_conversion(directions+i,conversion[7]);
	}
}
const char *blocks_rotation(const char *blocks[],int directions[],const char rotation[]){
	if(!strcmp(rotation,"x0")){
		const char *converted_blocks[8]={"001","011","000","010","","","",""};
		int converted_directions[8]={2,2,2,2,0,0,0,0};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(blocks,directions,converted_directions);
		return("-x0");
	}
	else if(!strcmp(rotation,"x1")){
		const char *converted_blocks[8]={"","","","","101","111","100","110"};
		int converted_directions[8]={0,0,0,0,2,2,2,2};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(blocks,directions,converted_directions);
		return("-x1");
	}
	else if(!strcmp(rotation,"-x0")){
		const char *converted_blocks[8]={"010","000","011","001","","","",""};
		int converted_directions[8]={2,2,2,2,0,0,0,0};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(blocks,directions,converted_directions);
		return("x0");
	}
	else if(!strcmp(rotation,"-x1")){
		const char *converted_blocks[8]={"","","","","110","100","111","101"};
		int converted_directions[8]={0,0,0,0,2,2,2,2};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(blocks,directions,converted_directions);
		return("x1");
	}
	else if(!strcmp(rotation,"y0")){
		const char *converted_blocks[8]={"001","101","","","000","100","",""};
		int converted_directions[8]={3,3,0,0,3,3,0,0};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(blocks,directions,converted_directions);
		return("-y0");
	}
	else if(!strcmp(rotation,"y1")){
		const char *converted_blocks[8]={"","","011","111","","","010","110"};
		int converted_directions[8]={0,0,3,3,0,0,3,3};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(blocks,directions,converted_directions);
		return("-y1");
	}
	else if(!strcmp(rotation,"-y0")){
		const char *converted_blocks[8]={"100","000","","","101","001","",""};
		int converted_directions[8]={3,3,0,0,3,3,0,0};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(blocks,directions,converted_directions);
		return("y0");
	}
	else if(!strcmp(rotation,"-y1")){
		const char *converted_blocks[8]={"","","110","010","","","111","011"};
		int converted_directions[8]={0,0,3,3,0,0,3,3};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(blocks,directions,converted_directions);
		return("y1");
	}
	else if(!strcmp(rotation,"z0")){
		const char *converted_blocks[8]={"100","","000","","110","","010",""};
		int converted_directions[8]={1,0,1,0,1,0,1,0};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(blocks,directions,converted_directions);
		return("-z0");
	}
	else if(!strcmp(rotation,"-z0")){
		const char *converted_blocks[8]={"010","","110","","000","","100",""};
		int converted_directions[8]={1,0,1,0,1,0,1,0};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(blocks,directions,converted_directions);
		return("z0");
	}
	else return("");
}
bool blockscmp(const char *blocks1[],const char *blocks2[]){ // blocks1,blocks2が一致しているか判定する
	for(int i= 0;i<8;i++){
		if(strcmp(blocks1[i],blocks2[i]))return(false);
	}
	return(true);
}
void blockscpy(const char *blocks1[],const char *blocks2[]){ // blocks2からblocks1へコピー
	for(int i= 0;i<8;i++){
		blocks1[i]=blocks2[i];
	}
}

const int M=10; // 回転の種類の数
char rotation_list[10][4]={"x0","-x0","x1","-x1","y0","-y0","y1","-y1","z0","-z0"};
const char *start_blocks[8]={"001","011","000","010","111","101","100","110"}, // ポインタ文字列の配列
*goal_blocks[8]={"011","001","000","010","111","101","100","110"}; // ポインタ文字列の配列
int start_directions[8]={0,0,0,0,0,0,0,0},goal_directions[8]={0,0,0,0,0,0,0,0};

//const char *start_blocks[8]={"011","001","000","010","100","110","101","111"}, // ポインタ文字列の配列
//*goal_blocks[8]={"111","100","101","011","000","001","110","010"}; // ポインタ文字列の配列
//int start_directions[8]={0,0,0,0,0,2,0,0},goal_directions[8]={2,0,0,2,0,1,2,2};
int main(void){
	const char *blocks[8];
	int directions[8];
	char displacement[256],invalid_rotation[4],rotation[10]="0";

	blockscpy(blocks,start_blocks); // 元に戻す
	strcpy(displacement,""); // 元に戻す
	strcpy(invalid_rotation,""); // 元に戻す
	memcpy(directions,start_directions,sizeof(start_directions)); // 元に戻す

	printf("「end」で終了\n「reset」で元の状態に戻る\n");
	for(int i=0;i<8;i++){
		printf("%s %d\n",blocks[i],directions[i]);
	}
	printf("displacement=%s invalid_rotation=%s \n→",displacement,invalid_rotation);
	scanf("%s",rotation);
	if(!strcmp(rotation,"end"))return(0);
	do{
		if(!strcmp(rotation,"reset")){
			blockscpy(blocks,start_blocks); // 元に戻す
			strcpy(displacement,""); // 元に戻す
			strcpy(invalid_rotation,""); // 元に戻す
			memcpy(directions,start_directions,sizeof(start_directions)); // 元に戻す
		}
		else{
			strcat(displacement,rotation);
			strcpy(invalid_rotation,blocks_rotation(blocks,directions,rotation));
		}

		for(int i=0;i<8;i++){
			printf("%s %d\n",blocks[i],directions[i]);
		}
		if(blockscmp(blocks,goal_blocks) && !memcmp(directions,goal_directions,sizeof(start_directions))){
			printf("ゴールと合致しました\n");
		}
		printf("displacement=%s invalid_rotation=%s \n→",displacement,invalid_rotation);
		scanf("%s",rotation);
	}while(strcmp(rotation,"end"));
	return(0);
}