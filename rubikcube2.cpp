#include<stdio.h>
#include<string.h>

void blocks_conversion(const char *blocks[],const char *conversion[]){
	for(int i= 0;i<8;i++){
		if(!strcmp(blocks[i],"000"))blocks[i]=conversion[0];
		else if(!strcmp(blocks[i],"001"))blocks[i]=conversion[1];
		else if(!strcmp(blocks[i],"010"))blocks[i]=conversion[2];
		else if(!strcmp(blocks[i],"011"))blocks[i]=conversion[3];
		else if(!strcmp(blocks[i],"100"))blocks[i]=conversion[4];
		else if(!strcmp(blocks[i],"101"))blocks[i]=conversion[5];
		else if(!strcmp(blocks[i],"110"))blocks[i]=conversion[6];
		else if(!strcmp(blocks[i],"111"))blocks[i]=conversion[7];
	}
}
void directions_conversion(int directions[],int conversion[]){ // 
	// 0: �������Ȃ�
	// 1: 0�Ȃ�1��1�Ȃ�0��
	// 2: 1�Ȃ�2��2�Ȃ�1��
	// 3: 0�Ȃ�2��2�Ȃ�0��
	for(int i= 0;i<8;i++){
		if(conversion[i]==1){
			if(directions[i]==0)directions[i]=1;
			else if(directions[i]==1)directions[i]=0;
		}
		else if(conversion[i]==2){
			if(directions[i]==1)directions[i]=2;
			else if(directions[i]==2)directions[i]=1;
		}
		else if(conversion[i]==3){
			if(directions[i]==0)directions[i]=2;
			else if(directions[i]==2)directions[i]=0;
		}
		//else if(directions[i]==conversion[1])directions[i]=conversion[0];
	}
}
const char *blocks_rotation(const char *blocks[],int directions[],const char rotation[]){
	if(!strcmp(rotation,"x0")){
		const char *converted_blocks[8]={"001","011","000","010","","","",""};
		int converted_directions[8]={2,2,2,2,0,0,0,0};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(directions,converted_directions);
		return("-x0");
	}
	else if(!strcmp(rotation,"x1")){
		const char *converted_blocks[8]={"","","","","101","111","100","110"};
		int converted_directions[8]={0,0,0,0,2,2,2,2};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(directions,converted_directions);
		return("-x1");
	}
	else if(!strcmp(rotation,"-x0")){
		const char *converted_blocks[8]={"010","000","011","001","","","",""};
		int converted_directions[8]={2,2,2,2,0,0,0,0};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(directions,converted_directions);
		return("x0");
	}
	else if(!strcmp(rotation,"-x1")){
		const char *converted_blocks[8]={"","","","","110","100","111","101"};
		int converted_directions[8]={0,0,0,0,2,2,2,2};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(directions,converted_directions);
		return("x1");
	}
	else if(!strcmp(rotation,"y0")){
		const char *converted_blocks[8]={"001","101","","","000","100","",""};
		int converted_directions[8]={3,3,0,0,3,3,0,0};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(directions,converted_directions);
		return("-y0");
	}
	else if(!strcmp(rotation,"y1")){
		const char *converted_blocks[8]={"","","011","111","","","010","110"};
		int converted_directions[8]={0,0,3,3,0,0,3,3};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(directions,converted_directions);
		return("-y1");
	}
	else if(!strcmp(rotation,"-y0")){
		const char *converted_blocks[8]={"100","000","","","101","001","",""};
		int converted_directions[8]={3,3,0,0,3,3,0,0};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(directions,converted_directions);
		return("y0");
	}
	else if(!strcmp(rotation,"-y1")){
		const char *converted_blocks[8]={"","","110","010","","","111","011"};
		int converted_directions[8]={0,0,3,3,0,0,3,3};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(directions,converted_directions);
		return("y1");
	}
	else if(!strcmp(rotation,"z0")){
		const char *converted_blocks[8]={"100","","000","","110","","010",""};
		int converted_directions[8]={1,0,1,0,1,0,1,0};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(directions,converted_directions);
		return("-z0");
	}
	else if(!strcmp(rotation,"-z0")){
		const char *converted_blocks[8]={"010","","110","","000","","100",""};
		int converted_directions[8]={1,0,1,0,1,0,1,0};
		blocks_conversion(blocks,converted_blocks);
		directions_conversion(directions,converted_directions);
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
//const char *start_blocks[8]={"001","011","000","010","111","101","100","110"}, // �|�C���^������̔z��
//*goal_blocks[8]={"011","001","000","010","111","101","100","110"}; // �|�C���^������̔z��

const char *start_blocks[8]={"011","001","000","010","100","110","101","111"}, // �|�C���^������̔z��
*goal_blocks[8]={"111","100","101","011","000","001","110","010"}; // �|�C���^������̔z��
//int start_directions[8]={0,0,0,0,0,0,0,0},goal_directions[8]={0,0,0,0,0,0,0,0};
int start_directions[8]={0,0,0,0,0,2,0,0},goal_directions[8]={2,0,0,2,0,1,2,2};
int main(void){
	const char *blocks[8];
	int directions[8];
	char displacement[256],invalid_rotation[4],rotation[10]="0";

	blockscpy(blocks,start_blocks); // ���ɖ߂�
	strcpy(displacement,""); // ���ɖ߂�
	strcpy(invalid_rotation,""); // ���ɖ߂�
	memcpy(directions,start_directions,sizeof(start_directions)); // ���ɖ߂�

	printf("�uend�v�ŏI��\n�ureset�v�Ō��̏�Ԃɖ߂�\n");
	for(int i=0;i<8;i++){
		printf("%s %d\n",blocks[i],directions[i]);
	}
	printf("%s\n��",displacement);
	scanf("%s",rotation);
	if(!strcmp(rotation,"end"))return(0);
	do{
		if(!strcmp(rotation,"reset")){
			memcpy(blocks,start_blocks,sizeof(start_blocks));
		}
		else{
			strcat(displacement,rotation);
			strcpy(invalid_rotation,blocks_rotation(blocks,directions,rotation));
		}

		for(int i=0;i<8;i++){
			printf("%s %d\n",blocks[i],directions[i]);
		}
		if(blockscmp(blocks,goal_blocks) && memcmp(directions,goal_directions,sizeof(start_directions))){
			printf("�S�[���ƍ��v���܂���");
		}
		printf("%s\n��",displacement);
		scanf("%s",rotation);
	}while(strcmp(rotation,"end"));
	return(0);
}