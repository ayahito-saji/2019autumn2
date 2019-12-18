/********fileio.cpp  **************/

#include <stdio.h>
#include <stdlib.h>

/******** �摜�̓ǂݍ��݁C�ۑ� *****************/

typedef struct _image{
	int w;
	int h;
	int ch;
	unsigned char *data;
} Image;

//Image�̊m��
Image *new_image(int w, int h, int ch){
	Image *img = (Image *)malloc(sizeof(Image));
	img->w = w;
	img->h = h;
	img->ch = ch;
	int size = w*h*ch;
	img->data = (unsigned char *)malloc(sizeof(unsigned char)*size);
	//�[���N���A
	for(int i=0; i<size; i++)
		img->data[i] = 0;
	return img;
}

//Image�̊J��
void delete_image(Image *img){
	delete img->data;
	delete img;
}

#define BUFF_LEN 256
//PGM�摜�����[�h����
Image *load_image(const char *fname){
	FILE *fp = fopen(fname, "rb");
	if(fp == NULL){
		fprintf(stderr, "ERROR : failed to open file.\n");
		return NULL;
	}
	char buff[BUFF_LEN];
	int count = 0;
	int type = 0;
	int w, h;
	int max;
	while(count < 3){
		if(fgets(buff, BUFF_LEN, fp) == NULL)
			return NULL;
		if(buff[0] == '#')//�R�����g�̓X�L�b�v
			continue;
		switch(count){
		case 0://type
			if(buff[0] != 'P'){
				fprintf(stderr, "ERROR : unknown format\n");
				return NULL;
			}
			type = buff[1] - '0';
			break;
		case 1://w h
			sscanf(buff, "%d %d", &w, &h);
			break;
		case 2://max
			sscanf(buff, "%d", &max);
			break;
		}
		count++;
	}

	if(type == 5){//pgm
		Image *img = new_image(w, h, 1);
		int size = w*h;
		for(int i=0; i<size; i++){
			int c = getc(fp);
			if(c < 0){//�f�[�^�������Ȃ��D
				delete_image(img);
				fprintf(stderr, "ERROR : too short data\n");
				fclose(fp);
				return NULL;
			}
			img->data[i] = (unsigned char)c;
		}
		fclose(fp);
		return img;
	}else{
		//���Ή�
		fprintf(stderr, "ERROR : unknown format number : %d\n", type);
		fclose(fp);
		return NULL;
	}
}

void save_image(const char *fname, Image *img){
	FILE *fp = fopen(fname, "wb");

	if(img->ch == 3){//PPM
		fprintf(fp, "P6\n");
	}else if(img->ch == 1){//PGM
		fprintf(fp, "P5\n");
	}
	fprintf(fp, "%d %d\n", img->w, img->h);
	fprintf(fp, "255\n");
	int size = img->w*img->h*img->ch;
	for(int i=0; i<size; i++)
		putc(img->data[i], fp);
	fclose(fp);
}

void bayer_normal(Image *input, Image *output){
	
}

/********** �摜�̓ǂݍ��݁C�ۑ��@�����܂�*******************************/

int main(int argc, char *argv[]){
	char *fname = "input.pgm";
	if(argc == 2)
		fname = argv[1];
	//�t�@�C���̓ǂݍ���
	Image *img = load_image(fname);
	if(img == NULL){
		fprintf(stderr, "Failed to load image : %s\n", fname);
		return 1;
	}

	//���ʕۑ��p�摜
	Image *result = new_image(img->w, img->h, 3);

	//�x�C���[����
	bayer_normal(img, result);

	//���ʂ̕ۑ�
	save_image("output.ppm", result);

	//���n��
	delete_image(img);
	delete_image(result);

	return 0;
}
