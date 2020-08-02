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
	// 0: �������Ȃ�
	// 1: 0�Ȃ�1��1�Ȃ�0��
	// 2: 1�Ȃ�2��2�Ȃ�1��
	// 3: 0�Ȃ�2��2�Ȃ�0��
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
bool blockscmp(const char *blocks1[],const char *blocks2[]){ // blocks1,blocks2����v���Ă��邩���肷��
	for(int i= 0;i<8;i++){
		if(strcmp(blocks1[i],blocks2[i]))return(false);
	}
	return(true);
}
void blockscpy(const char *blocks1[],const char *blocks2[]){ // blocks2����blocks1�փR�s�[
	for(int i= 0;i<8;i++){
		blocks1[i]=blocks2[i];
	}
}

const int M=10; // ��]�̎�ނ̐�
char rotation_list[10][4]={"x0","-x0","x1","-x1","y0","-y0","y1","-y1","z0","-z0"};
const char *start_blocks[8]={"001","011","000","010","111","101","100","110"}, // �|�C���^������̔z��
*goal_blocks[8]={"011","001","000","010","111","101","100","110"}; // �|�C���^������̔z��

//const char *start_blocks[8]={"011","001","000","010","100","110","101","111"}, // �|�C���^������̔z��
//*goal_blocks[8]={"111","100","101","011","000","001","110","010"}; // �|�C���^������̔z��

int start_directions[8]={0,0,0,0,0,0,0,0},goal_directions[8]={0,0,0,0,0,0,0,0};
//int start_directions[8]={0,0,0,0,0,2,0,0},goal_directions[8]={2,0,0,2,0,1,2,2};

bool iddfs(int depth,const char invalid_rotation_befo[],const char *displacement_befo,const char *blocks_befo[],int directions_befo[],int limit){
	const char *blocks[8];
	int directions[8];
	char displacement[256],invalid_rotation[4];
	if(limit==depth){
		printf("%s\n",displacement_befo);
		if(blockscmp(blocks_befo,goal_blocks) && !memcmp(directions_befo,goal_directions,sizeof(start_directions))){
			return(true);
		}
	}
	else{
		for (int j=0;j<M;j++){
			blockscpy(blocks,blocks_befo); // ���ɖ߂�
			strcpy(displacement,displacement_befo); // ���ɖ߂�
			strcpy(invalid_rotation,invalid_rotation_befo); // ���ɖ߂�
			memcpy(directions,directions_befo,sizeof(start_directions)); // ���ɖ߂�
			if(strcmp(invalid_rotation,rotation_list[j])){ // �����ȉ�]�i1�O�̉�]��ł�������]�j�łȂ��Ȃ�
				strcat(displacement,rotation_list[j]);
				strcpy(invalid_rotation,blocks_rotation(blocks,directions,rotation_list[j]));
				/*
				for(int i= 0;i<8;i++){
					const char *rotation=block_conversion(blocks+i,rotation_list[j]);
					if(strcmp(rotation,"")){ // block_conversion��""��Ԃ��Ȃ����
						strcpy(invalid_rotation,rotation);
					}
					// else block_conversion(blocks+i,rotation_list[j]);
				}
				*/
				if(iddfs(depth+1,invalid_rotation,displacement,blocks,directions,limit))return(true); // true�Ȃ�true��Ԃ�
				// strcpy(invalid_rotation,""); // depth��limit�܂œ��B�������ߌ��ɖ߂�
			}
		}
	}
	return(false);
}
int main(void){
	// int i=0,depth=0,limit=0;
	int limit=0;
	const int N=15; // �ő�̐[��
	for (limit = 2; limit<=N; limit++) {
		//strcpy(invalid_rotation,"");
		//strcpy(displacement,"");
		if(iddfs(1,"","",start_blocks,start_directions,limit)){
			printf("������܂���");
			return(0);
		}
		//else printf("������܂���ł���");
	}	
	printf("������܂���ł���");
	return(0);
}