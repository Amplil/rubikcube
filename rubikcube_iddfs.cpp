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

bool iddfs(int depth,char current_invalid_rotation[],const char *current_displacement,const char *current_blocks[],const char *goal_blocks[],int limit){
	const char *blocks_befo[8];
	char displacement_befo[256],invalid_rotation_befo[4];
	if(limit==depth){
		printf("%s\n",current_displacement);
		//printf("���");

		if(blockscmp(current_blocks,goal_blocks))return(true);
	}
	else{
		for (int j=0;j<M;j++){
			blockscpy(blocks,current_blocks); // ���ɖ߂�
			strcpy(displacement,current_displacement); // ���ɖ߂�
			if(strcmp(invalid_rotation,rotation_list[j])){ // �����ȉ�]�i1�O�̉�]��ł�������]�j�łȂ��Ȃ�
				strcat(displacement,rotation_list[j]);
				for(int i= 0;i<8;i++){
					const char *rotation=block_conversion(blocks+i,rotation_list[j]);
					if(strcmp(rotation,"")){ // block_conversion��""��Ԃ��Ȃ����
						strcpy(invalid_rotation,rotation);
					}
					// else block_conversion(blocks+i,rotation_list[j]);
				}
				if(iddfs(depth+1,displacement,blocks,goal_blocks,limit))return(true); // true�Ȃ�true��Ԃ�
				strcpy(invalid_rotation,""); // depth��limit�܂œ��B�������ߌ��ɖ߂�
			}
		}
	}
	return(false);
}
int main(void){
	// int i=0,depth=0,limit=0;
	int limit=0;
	const int N=10; // �ő�̐[��
	const char *start_blocks[8]={"001","011","000","010","111","101","100","110"}, // �|�C���^������̔z��
	*goal_blocks[8]={"011","001","000","010","111","101","100","110"}; // �|�C���^������̔z��

	for (limit = 2; limit<=N; limit++) {
		//strcpy(invalid_rotation,"");
		//strcpy(displacement,"");
		if(iddfs(1,"","",start_blocks,goal_blocks,limit)){
			printf("������܂���");
			return(0);
		}
		//else printf("������܂���ł���");
	}	
	printf("������܂���ł���");
	return(0);
}