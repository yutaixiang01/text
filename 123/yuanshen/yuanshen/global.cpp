#include"global.h"

//��פ13����������
const char weapon_3star[][200] = { "����", "������֮��","ѻ��","������","����Ӣ��̷","ħ������","��ӧǹ",
								"�������","��ԡ��Ѫ�Ľ�","��Ӱ����","��������","������","����" };


//��פ16���ǽ�ɫ
const char char_4star[][200] = { "����", "ɰ��", "�ϰ���", "����", "ŵ����", "������", "��л��", "����",
								"����", "����", "����", "����", "����", "����", "�Ű���", "��ɯ" };


//18����������
const char weapon_4star[][200] = { "����", "����", "����", "�����Թ�", "����", "�������", "��������", "�����ص�", "���糤ǹ",
								"ϻ����", "���", "�����", "�ӽ�", "�����", "ϻ������", "����", "�ѽ�", "���罣" };

//��פ15 ����
const char weapon_char_5star[][200] = { "����" ,"Ī��" ,"����" ,"��¬��" ,"��","��Ī˹֮��", "���֮��", "�ķ�ԭ��", "���֮��", "����",
								"���֮��", "�ǵ�ĩ·", "���֮��", "���֮��", "��ӥ��" };

//���������
int jiuchan_num = 0;

//�������Ʒ�Ǽ�
int xingji = 0;

//��������
int r = 0;

//����ssr-1��û��������Ʒ
int ssr = 0;

//����sr-1��û��������Ʒ
int sr = 1;
//����һ���ַ�����洢���
char results[100];
//��Ȩ��Ϊ10000
int Wceil = 10000;
//������ƷȨ��
static int wr = 9430;

int chizi = 0;
int baodi = 0;

//����һ�����ȷֲ���[1,max]�ϵ������
int RF1(int max) {
	return 1 + (int)max * rand() / (RAND_MAX + 1);
}

//ȡ������֮�����Сֵ
int min(int a, int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}


//���ǽ�ɫȨ��  ����ssr���ӣ�������û�г��е�������ࣩȨ�ر��   
//ssrΪ0��Ȩ��Ϊ 60   ssr���ڵ���74֮��Ȩֵÿ������600  Ȩֵ���ʱ����10000
int wssr(int ssr) {
	if (ssr <= 73) {
		return 60;
	}
	else if (ssr >= 74) {
		return (60 + 600 * (ssr - 73));
	}
}


//���ǽ�ɫ������Ȩ��
//srΪ0ʱȨ��Ϊ510    sr���ڵ���8֮��Ȩ��ÿ������5100   Ȩ������Ǵ���10000
int wsr(int sr) {
	if (sr <= 8) {
		return 510;
	}
	else if (sr >= 9) {
		return 510 + 5100 * (sr - 8);
	}
}

//дһ��ѡ����ӵ��жϺ���
void xuanzechizi() {
	printf_s("\nѡ��(����)\n 1.��פ��\n 2.����类�up \n 3.����up\n");
	scanf_s("%d", &chizi);
}


//����鿨�ĺ���  
void chanzgzhuchouka() {
	//�����޸ľ�������
	printf_s("����һ���鼸��:");
	scanf_s("%d", &jiuchan_num);

	xuanzechizi();


	//ѭ��ȷ��ÿ�ε��Ǽ�  ��  ��   ��
	//�ù��޸�jiuchan_num ���ж�ѭ��
	for (int i = 0; i < jiuchan_num; ) {

		//����ѡ�����ֳ�ȡ��ʽ  ��һ�黹��10��
		int xuanze = 0;

		//ѡ����ӵĺ���

		printf_s("\nѡ��1 or 2��\n 1.��һ����\n 2.��10��\n");
		scanf_s("%d", &xuanze);

		if (xuanze == 1) {

			//��������һ
			jiuchan_num -= 1;

			//�����������  �˳�
			if (jiuchan_num == 0) {
				break;
			}

			//ȷ���鿨�ȼ��ĺ���
			queding_xingji();
		}
		else {

			//����������10 �˳�
			if (jiuchan_num < 10) {
				printf_s("��������");
				break;

			}
			else {
				jiuchan_num -= 10;

				//ѭ��ʮ��   ȷ��ÿ���Ǽ�
				for (int j = 1; j <= 10; j++) {
					queding_xingji();
				}
			}
		}
	}
}

void queding_xingji() {


	//���������
	r = RF1(min(Wceil, wssr(ssr) + wsr(sr) + wr));


	//�������     ������ڡ�1��wssr(ssr)����
	if (r >= 1 && r <= wssr(ssr)) {
		xingji = 5;
		printf_s("\n%d\n", xingji);   //��ӡ�Ǽ�
		ssr = 0;
		sr += 1;
		result(xingji);       //������
	}
	//�������      ������ڡ�wssr(ssr+1),wssr(ssr)+wsr(sr)����
	else if (r >= wssr(ssr + 1) && r <= wssr(ssr) + wsr(sr)) {
		xingji = 4;
		printf_s("\n%d\n", xingji);
		ssr += 1;
		sr = 1;
		result(xingji);
	}
	//�������   ������ڡ�wssr(ssr)+wsr(sr),max����
	else {
		xingji = 3;
		printf_s("\n%d\n", xingji);
		ssr += 1;
		sr += 1;
		result(xingji);

	}
}

char* result(int xingji)
{

	//����һ�����������
	//srand((unsigned)time(NULL));

	if (xingji == 3) {

		//����һ��  ���ֵ��ͬ���������������� ����� Ȼ���������ȡֵ   ֻ������  		//  ����[1,13]
		int n1 = rand() % 13;

		//�洢 �鵽�� ��������
		//printf_s("%s", weapon_3star[n1]);
		//���Ƶ����������
		strcpy_s(results, weapon_3star[n1]);
		printf_s("%s\n", results);
		//���ؽ��
		return results;

	}
	else if (xingji == 4) {

		//����һ��    �������0  1  ��   �ж����������ǽ�ɫ   ����0�������أ���1�ǽ�ɫ��
		int boolen = rand() % 2;   //[0,1]

		if (boolen == 0) {
			//������
			//����һ��  ���ֵ��ͬ���������������� ����� Ȼ���������ȡֵ
			int n2 = rand() % 18;
			//printf_s("%s", weapon_4star[n2]);
			strcpy_s(results, weapon_4star[n2]);
			printf_s("%s\n", results);
			return results;
		}
		else {
			//��ɫ��
			//����һ��  ���ֵ��ͬ�����ǽ�ɫ������ ����� Ȼ���������ȡֵ
			int n3 = rand() % 16;
			//printf_s("%s", char_4star[n3]);
			strcpy_s(results, weapon_4star[n3]);
			printf_s("%s\n", results);
			return results;
		}

	}
	else {
		//�����ж�   �Ƿ����ˣ���/  up��  
		//����   ���������ǽ�ɫ����//  ����������ж�   ��  ��ɫ  ���� ��Ϊһ��(֮��ͬ��)
		//����һ��    �������0  1  ��   �ж��Ƿ�����

		int boolen = rand() % 2;   //[0,1]


		//����ǳ�פ��   ֻ�ܴӵ�һ�������  //������up������   ����   �󱣵�    ���������  ��������+1   ���ݲ���ֵ�ж���һ�αز���
		if (chizi == 1) {
			boolen = 0;
		}

		if (chizi != 1 && baodi == 0 && boolen == 0) {
			boolen = 0;
		}
		else if (chizi != 1 && baodi == 1) {
			boolen = 1;
			baodi = 0;
		}



		if (boolen == 0) {   //����   ����   ����  
			// �����µ� һ�� ����  �����ж� ��һ�� �ض����up  ����  ����������һ�� bool  ��һ�� ֱ��������Ŀ���
			//���������     ���һ��������Ʒ

			if (chizi != 1) {
				baodi += 1;
			}


			int n4 = rand() % 15;   //[0,14]

			printf_s("\n-----------------------------\n");
			//printf_s("%s\n", weapon_char_5star[n4]);
			strcpy_s(results, weapon_char_5star[n4]);
			printf_s("%s\n", results);
			return results;

		}
		else {   //û��    ���ݳ����ж�    ����Ǻ��ҳ���   Ϊ  ����    �����   类�����   类�   ����  ���β���
			if (chizi == 2) {
				strcpy_s(results, "����类�");
				printf_s("\n-----------------------------\n");
				printf_s("%s\n", results);

				return results;
			}
			else {
				strcpy_s(results, "����");
				printf_s("\n-----------------------------\n");
				printf_s("%s\n", results);
				return results;
			}
		}

	}

}

